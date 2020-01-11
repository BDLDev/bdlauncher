#pragma once

#include "macros.h"
#include "time.h"
#include "types.h"

/// Sizeof an UDP header in byte
#define UDP_HEADER_SIZE 28

#define CC_TIME_TYPE_BYTES 8
typedef RakNet::TimeUS CCTimeType;

typedef RakNet::uint24_t DatagramSequenceNumberType;
typedef double BytesPerMicrosecond;
typedef double BytesPerSecond;
typedef double MicrosecondsPerByte;

namespace RakNet {

class CCRakNetSlidingWindow {
public:
  CCRakNetSlidingWindow();
  ~CCRakNetSlidingWindow();

  /// Reset all variables to their initial states, for a new connection
  void Init(CCTimeType curTime, uint32_t maxDatagramPayload);

  /// Update over time
  void Update(CCTimeType curTime, bool hasDataToSendOrResend);

  int GetRetransmissionBandwidth(CCTimeType curTime, CCTimeType timeSinceLastTick, uint32_t unacknowledgedBytes, bool isContinuousSend);
  int GetTransmissionBandwidth(CCTimeType curTime, CCTimeType timeSinceLastTick, uint32_t unacknowledgedBytes, bool isContinuousSend);

  /// Acks do not have to be sent immediately. Instead, they can be buffered up such that groups of acks are sent at a time
  /// This reduces overall bandwidth usage
  /// How long they can be buffered depends on the retransmit time of the sender
  /// Should call once per update tick, and send if needed
  bool ShouldSendACKs(CCTimeType curTime, CCTimeType estimatedTimeToNextTick);

  /// Every data packet sent must contain a sequence number
  /// Call this function to get it. The sequence number is passed into OnGotPacketPair()
  DatagramSequenceNumberType GetAndIncrementNextDatagramSequenceNumber(void);
  DatagramSequenceNumberType GetNextDatagramSequenceNumber(void);

  /// Call this when you send packets
  /// Every 15th and 16th packets should be sent as a packet pair if possible
  /// When packets marked as a packet pair arrive, pass to OnGotPacketPair()
  /// When any packets arrive, (additionally) pass to OnGotPacket
  /// Packets should contain our system time, so we can pass rtt to OnNonDuplicateAck()
  void OnSendBytes(CCTimeType curTime, uint32_t numBytes);

  /// Call this when you get a packet pair
  void OnGotPacketPair(DatagramSequenceNumberType datagramSequenceNumber, uint32_t sizeInBytes, CCTimeType curTime);

  /// Call this when you get a packet (including packet pairs)
  /// If the DatagramSequenceNumberType is out of order, skippedMessageCount will be non-zero
  /// In that case, send a NAK for every sequence number up to that count
  bool OnGotPacket(DatagramSequenceNumberType datagramSequenceNumber, bool isContinuousSend, CCTimeType curTime, uint32_t sizeInBytes, uint32_t *skippedMessageCount);

  /// Call when you get a NAK, with the sequence number of the lost message
  /// Affects the congestion control
  void OnResend(CCTimeType curTime, TimeUS nextActionTime);
  void OnNAK(CCTimeType curTime, DatagramSequenceNumberType nakSequenceNumber);

  /// Call this when an ACK arrives.
  /// hasBAndAS are possibly written with the ack, see OnSendAck()
  /// B and AS are used in the calculations in UpdateWindowSizeAndAckOnAckPerSyn
  /// B and AS are updated at most once per SYN
  void OnAck(CCTimeType curTime, CCTimeType rtt, bool hasBAndAS, BytesPerMicrosecond _B, BytesPerMicrosecond _AS, double totalUserDataBytesAcked, bool isContinuousSend,
             DatagramSequenceNumberType sequenceNumber);
  void OnDuplicateAck(CCTimeType curTime, DatagramSequenceNumberType sequenceNumber);

  /// Call when you send an ack, to see if the ack should have the B and AS parameters transmitted
  /// Call before calling OnSendAck()
  void OnSendAckGetBAndAS(CCTimeType curTime, bool *hasBAndAS, BytesPerMicrosecond *_B, BytesPerMicrosecond *_AS);

  /// Call when we send an ack, to write B and AS if needed
  /// B and AS are only written once per SYN, to prevent slow calculations
  /// Also updates SND, the period between sends, since data is written out
  /// Be sure to call OnSendAckGetBAndAS() before calling OnSendAck(), since whether you write it or not affects \a numBytes
  void OnSendAck(CCTimeType curTime, uint32_t numBytes);

  /// Call when we send a NACK
  /// Also updates SND, the period between sends, since data is written out
  void OnSendNACK(CCTimeType curTime, uint32_t numBytes);

  /// Retransmission time out for the sender
  /// If the time difference between when a message was last transmitted, and the current time is greater than RTO then packet is eligible for retransmission, pending congestion control
  /// RTO = (RTT + 4 * RTTVar) + SYN
  /// If we have been continuously sending for the last RTO, and no ACK or NAK at all, SND*=2;
  /// This is per message, which is different from UDT, but RakNet supports packetloss with continuing data where UDT is only RELIABLE_ORDERED
  /// Minimum value is 100 milliseconds
  CCTimeType GetRTOForRetransmission(unsigned char timesSent) const;

  /// Set the maximum amount of data that can be sent in one datagram
  /// Default to MAXIMUM_MTU_SIZE-UDP_HEADER_SIZE
  void SetMTU(uint32_t bytes);

  /// Return what was set by SetMTU()
  uint32_t GetMTU(void) const;

  /// Query for statistics
  BytesPerMicrosecond GetLocalSendRate(void) const { return 0; }
  BytesPerMicrosecond GetLocalReceiveRate(CCTimeType currentTime) const;
  BytesPerMicrosecond GetRemoveReceiveRate(void) const { return 0; }
  // BytesPerMicrosecond GetEstimatedBandwidth(void) const {return B;}
  BytesPerMicrosecond GetEstimatedBandwidth(void) const { return GetLinkCapacityBytesPerSecond() * 1000000.0; }
  double GetLinkCapacityBytesPerSecond(void) const { return 0; }

  /// Query for statistics
  double GetRTT(void) const;

  bool GetIsInSlowStart(void) const { return IsInSlowStart(); }
  uint32_t GetCWNDLimit(void) const { return (uint32_t)0; }

  /// Is a > b, accounting for variable overflow?
  static bool GreaterThan(DatagramSequenceNumberType a, DatagramSequenceNumberType b);
  /// Is a < b, accounting for variable overflow?
  static bool LessThan(DatagramSequenceNumberType a, DatagramSequenceNumberType b);
  //	void SetTimeBetweenSendsLimit(unsigned int bitsPerSecond);
  uint64_t GetBytesPerSecondLimitByCongestionControl(void) const;

protected:
  // Maximum amount of bytes that the user can send, e.g. the size of one full datagram
  uint32_t MAXIMUM_MTU_INCLUDING_UDP_HEADER;

  double cwnd;     // max bytes on wire
  double ssThresh; // Threshhold between slow start and congestion avoidance

  /// When we get an ack, if oldestUnsentAck==0, set it to the current time
  /// When we send out acks, set oldestUnsentAck to 0
  CCTimeType oldestUnsentAck;

  CCTimeType GetSenderRTOForACK(void) const;

  /// Every outgoing datagram is assigned a sequence number, which increments by 1 every assignment
  DatagramSequenceNumberType nextDatagramSequenceNumber;
  DatagramSequenceNumberType nextCongestionControlBlock;
  bool backoffThisBlock, speedUpThisBlock;
  /// Track which datagram sequence numbers have arrived.
  /// If a sequence number is skipped, send a NAK for all skipped messages
  DatagramSequenceNumberType expectedNextSequenceNumber;

  bool _isContinuousSend;

  bool IsInSlowStart(void) const;

  double lastRtt, estimatedRTT, deviationRtt;
};
} // namespace RakNet