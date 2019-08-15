#pragma once

#include "assert.h"
#include "macros.h"
#include "memoryoverride.h"
#include "string.h"
#include "types.h"
#include <cmath>
#include <float.h>

namespace RakNet {

/// This class allows you to write and read native types as a string of bits.  BitStream is used extensively throughout RakNet and is designed to be used by users as well.
/// \sa BitStreamSample.txt
class BitStream {

public:
  // GetInstance() and DestroyInstance(instance*)
  STATIC_FACTORY_DECLARATIONS(BitStream)

  /// Default Constructor
  BitStream();

  /// \brief Create the bitstream, with some number of bytes to immediately allocate.
  /// \details There is no benefit to calling this, unless you know exactly how many bytes you need and it is greater than BITSTREAM_STACK_ALLOCATION_SIZE.
  /// In that case all it does is save you one or more realloc calls.
  /// \param[in] initialBytesToAllocate the number of bytes to pre-allocate.
  BitStream(const unsigned int initialBytesToAllocate);

  /// \brief Initialize the BitStream, immediately setting the data it contains to a predefined pointer.
  /// \details Set \a _copyData to true if you want to make an internal copy of the data you are passing. Set it to false to just save a pointer to the data.
  /// You shouldn't call Write functions with \a _copyData as false, as this will write to unallocated memory
  /// 99% of the time you will use this function to cast Packet::data to a bitstream for reading, in which case you should write something as follows:
  /// \code
  /// SLNet::BitStream bs(packet->data, packet->length, false);
  /// \endcode
  /// \param[in] _data An array of bytes.
  /// \param[in] lengthInBytes Size of the \a _data.
  /// \param[in] _copyData true or false to make a copy of \a _data or not.
  BitStream(unsigned char *_data, const unsigned int lengthInBytes, bool _copyData);

  // Destructor
  ~BitStream();

  /// Resets the bitstream for reuse.
  void Reset(void);

  /// \brief Bidirectional serialize/deserialize any integral type to/from a bitstream.
  /// \details Undefine __BITSTREAM_NATIVE_END if you need endian swapping.
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] inOutTemplateVar The value to write
  /// \return true if \a writeToBitstream is true.  true if \a writeToBitstream is false and the read was successful.  false if \a writeToBitstream is false and the read was not successful.
  template <class templateType> bool Serialize(bool writeToBitstream, templateType &inOutTemplateVar);

  /// \brief Bidirectional serialize/deserialize any integral type to/from a bitstream.
  /// \details If the current value is different from the last value
  /// the current value will be written.  Otherwise, a single bit will be written
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] inOutCurrentValue The current value to write
  /// \param[in] lastValue The last value to compare against.  Only used if \a writeToBitstream is true.
  /// \return true if \a writeToBitstream is true.  true if \a writeToBitstream is false and the read was successful.  false if \a writeToBitstream is false and the read was not successful.
  template <class templateType> bool SerializeDelta(bool writeToBitstream, templateType &inOutCurrentValue, const templateType &lastValue);

  /// \brief Bidirectional version of SerializeDelta when you don't know what the last value is, or there is no last value.
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] inOutCurrentValue The current value to write
  /// \return true if \a writeToBitstream is true.  true if \a writeToBitstream is false and the read was successful.  false if \a writeToBitstream is false and the read was not successful.
  template <class templateType> bool SerializeDelta(bool writeToBitstream, templateType &inOutCurrentValue);

  /// \brief Bidirectional serialize/deserialize any integral type to/from a bitstream.
  /// \details Undefine __BITSTREAM_NATIVE_END if you need endian swapping.
  /// If you are not using __BITSTREAM_NATIVE_END the opposite is true for types larger than 1 byte
  /// For floating point, this is lossy, using 2 bytes for a float and 4 for a double.  The range must be between -1 and +1.
  /// For non-floating point, this is lossless, but only has benefit if you use less than half the bits of the type
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] inOutTemplateVar The value to write
  /// \return true if \a writeToBitstream is true.  true if \a writeToBitstream is false and the read was successful.  false if \a writeToBitstream is false and the read was not successful.
  template <class templateType> bool SerializeCompressed(bool writeToBitstream, templateType &inOutTemplateVar);

  /// \brief Bidirectional serialize/deserialize any integral type to/from a bitstream.
  /// \details If the current value is different from the last value
  /// the current value will be written.  Otherwise, a single bit will be written
  /// For floating point, this is lossy, using 2 bytes for a float and 4 for a double.  The range must be between -1 and +1.
  /// For non-floating point, this is lossless, but only has benefit if you use less than half the bits of the type
  /// If you are not using __BITSTREAM_NATIVE_END the opposite is true for types larger than 1 byte
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] inOutCurrentValue The current value to write
  /// \param[in] lastValue The last value to compare against.  Only used if \a writeToBitstream is true.
  /// \return true if \a writeToBitstream is true.  true if \a writeToBitstream is false and the read was successful.  false if \a writeToBitstream is false and the read was not successful.
  template <class templateType> bool SerializeCompressedDelta(bool writeToBitstream, templateType &inOutCurrentValue, const templateType &lastValue);

  /// \brief Save as SerializeCompressedDelta(templateType &currentValue, const templateType &lastValue) when we have an unknown second parameter
  /// \return true on data read. False on insufficient data in bitstream
  template <class templateType> bool SerializeCompressedDelta(bool writeToBitstream, templateType &inOutTemplateVar);

  /// \brief Bidirectional serialize/deserialize an array or casted stream or raw data.  This does NOT do endian swapping.
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] inOutByteArray a byte buffer
  /// \param[in] numberOfBytes the size of \a input in bytes
  /// \return true if \a writeToBitstream is true.  true if \a writeToBitstream is false and the read was successful.  false if \a writeToBitstream is false and the read was not successful.
  bool Serialize(bool writeToBitstream, char *inOutByteArray, const unsigned int numberOfBytes);

  /// \brief Serialize a float into 2 bytes, spanning the range between \a floatMin and \a floatMax
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] inOutFloat The float to write
  /// \param[in] floatMin Predetermined minimum value of f
  /// \param[in] floatMax Predetermined maximum value of f
  bool SerializeFloat16(bool writeToBitstream, float &inOutFloat, float floatMin, float floatMax);

  /// Serialize one type casted to another (smaller) type, to save bandwidth
  /// serializationType should be uint8_t, uint16_t, uint24_t, or uint32_t
  /// Example: int num=53; SerializeCasted<uint8_t>(true, num); would use 1 byte to write what would otherwise be an integer (4 or 8 bytes)
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] value The value to serialize
  template <class serializationType, class sourceType> bool SerializeCasted(bool writeToBitstream, sourceType &value);

  /// Given the minimum and maximum values for an integer type, figure out the minimum number of bits to represent the range
  /// Then serialize only those bits
  /// \note A static is used so that the required number of bits for (maximum-minimum) is only calculated once. This does require that \a minimum and \maximum are fixed values for a given line of code
  /// for the life of the program \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data \param[in] value Integer value
  /// to write, which should be between \a minimum and \a maximum \param[in] minimum Minimum value of \a value \param[in] maximum Maximum value of \a value \param[in] allowOutsideRange If true, all
  /// sends will take an extra bit, however value can deviate from outside \a minimum and \a maximum. If false, will assert if the value deviates
  template <class templateType> bool SerializeBitsFromIntegerRange(bool writeToBitstream, templateType &value, const templateType minimum, const templateType maximum, bool allowOutsideRange = false);
  /// \param[in] requiredBits Primarily for internal use, called from above function() after calculating number of bits needed to represent maximum-minimum
  template <class templateType>
  bool SerializeBitsFromIntegerRange(bool writeToBitstream, templateType &value, const templateType minimum, const templateType maximum, const int requiredBits, bool allowOutsideRange = false);

  /// \brief Bidirectional serialize/deserialize a normalized 3D vector, using (at most) 4 bytes + 3 bits instead of 12-24 bytes.
  /// \details Will further compress y or z axis aligned vectors.
  /// Accurate to 1/32767.5.
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] x x
  /// \param[in] y y
  /// \param[in] z z
  /// \return true if \a writeToBitstream is true.  true if \a writeToBitstream is false and the read was successful.  false if \a writeToBitstream is false and the read was not successful.
  template <class templateType> // templateType for this function must be a float or double
  bool SerializeNormVector(bool writeToBitstream, templateType &x, templateType &y, templateType &z);

  /// \brief Bidirectional serialize/deserialize a vector, using 10 bytes instead of 12.
  /// \details Loses accuracy to about 3/10ths and only saves 2 bytes, so only use if accuracy is not important.
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] x x
  /// \param[in] y y
  /// \param[in] z z
  /// \return true if \a writeToBitstream is true.  true if \a writeToBitstream is false and the read was successful.  false if \a writeToBitstream is false and the read was not successful.
  template <class templateType> // templateType for this function must be a float or double
  bool SerializeVector(bool writeToBitstream, templateType &x, templateType &y, templateType &z);

  /// \brief Bidirectional serialize/deserialize a normalized quaternion in 6 bytes + 4 bits instead of 16 bytes. Slightly lossy.
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] w w
  /// \param[in] x x
  /// \param[in] y y
  /// \param[in] z z
  /// \return true if \a writeToBitstream is true.  true if \a writeToBitstream is false and the read was successful.  false if \a writeToBitstream is false and the read was not successful.
  template <class templateType> // templateType for this function must be a float or double
  bool SerializeNormQuat(bool writeToBitstream, templateType &w, templateType &x, templateType &y, templateType &z);

  /// \brief Bidirectional serialize/deserialize an orthogonal matrix by creating a quaternion, and writing 3 components of the quaternion in 2 bytes each.
  /// \details Use 6 bytes instead of 36
  /// Lossy, although the result is renormalized
  /// \return true on success, false on failure.
  template <class templateType> // templateType for this function must be a float or double
  bool SerializeOrthMatrix(bool writeToBitstream, templateType &m00, templateType &m01, templateType &m02, templateType &m10, templateType &m11, templateType &m12, templateType &m20,
                           templateType &m21, templateType &m22);

  /// \brief Bidirectional serialize/deserialize numberToSerialize bits to/from the input.
  /// \details Right aligned data means in the case of a partial byte, the bits are aligned
  /// from the right (bit 0) rather than the left (as in the normal
  /// internal representation) You would set this to true when
  /// writing user data, and false when copying bitstream data, such
  /// as writing one bitstream to another
  /// \param[in] writeToBitstream true to write from your data to this bitstream.  False to read from this bitstream and write to your data
  /// \param[in] inOutByteArray The data
  /// \param[in] numberOfBitsToSerialize The number of bits to write
  /// \param[in] rightAlignedBits if true data will be right aligned
  /// \return true if \a writeToBitstream is true.  true if \a writeToBitstream is false and the read was successful.  false if \a writeToBitstream is false and the read was not successful.
  bool SerializeBits(bool writeToBitstream, unsigned char *inOutByteArray, const BitSize_t numberOfBitsToSerialize, const bool rightAlignedBits = true);

  /// \brief Write any integral type to a bitstream.
  /// \details Undefine __BITSTREAM_NATIVE_END if you need endian swapping.
  /// \param[in] inTemplateVar The value to write
  template <class templateType> void Write(const templateType &inTemplateVar);

  /// \brief Write the dereferenced pointer to any integral type to a bitstream.
  /// \details Undefine __BITSTREAM_NATIVE_END if you need endian swapping.
  /// \param[in] inTemplateVar The value to write
  template <class templateType> void WritePtr(templateType *inTemplateVar);

  /// \brief Write any integral type to a bitstream.
  /// \details If the current value is different from the last value
  /// the current value will be written.  Otherwise, a single bit will be written
  /// \param[in] currentValue The current value to write
  /// \param[in] lastValue The last value to compare against
  template <class templateType> void WriteDelta(const templateType &currentValue, const templateType &lastValue);

  /// \brief WriteDelta when you don't know what the last value is, or there is no last value.
  /// \param[in] currentValue The current value to write
  template <class templateType> void WriteDelta(const templateType &currentValue);

  /// \brief Write any integral type to a bitstream.
  /// \details Undefine __BITSTREAM_NATIVE_END if you need endian swapping.
  /// If you are not using __BITSTREAM_NATIVE_END the opposite is true for types larger than 1 byte
  /// For floating point, this is lossy, using 2 bytes for a float and 4 for a double.  The range must be between -1 and +1.
  /// For non-floating point, this is lossless, but only has benefit if you use less than half the bits of the type
  /// \param[in] inTemplateVar The value to write
  template <class templateType> void WriteCompressed(const templateType &inTemplateVar);

  /// \brief Write any integral type to a bitstream.
  /// \details If the current value is different from the last value
  /// the current value will be written.  Otherwise, a single bit will be written
  /// For floating point, this is lossy, using 2 bytes for a float and 4 for a double.  The range must be between -1 and +1.
  /// For non-floating point, this is lossless, but only has benefit if you use less than half the bits of the type
  /// If you are not using __BITSTREAM_NATIVE_END the opposite is true for types larger than 1 byte
  /// \param[in] currentValue The current value to write
  /// \param[in] lastValue The last value to compare against
  template <class templateType> void WriteCompressedDelta(const templateType &currentValue, const templateType &lastValue);

  /// \brief Save as WriteCompressedDelta(const templateType &currentValue, const templateType &lastValue) when we have an unknown second parameter
  template <class templateType> void WriteCompressedDelta(const templateType &currentValue);

  /// \brief Read any integral type from a bitstream.
  /// \details Define __BITSTREAM_NATIVE_END if you need endian swapping.
  /// \param[in] outTemplateVar The value to read
  /// \return true on success, false on failure.
  template <class templateType> bool Read(templateType &outTemplateVar);

  /// \brief Read a wchar from a bitstream.
  /// \details Define __BITSTREAM_NATIVE_END if you need endian swapping.
  /// \param[in] varString The value to read
  /// \param[in] varStringLength The length of the given varString array (in wchar_t)
  /// \return true on success, false on failure.
  bool Read(wchar_t *&varString);
  bool Read(wchar_t *&varString, size_t varStringLength);

  /// \brief Read any integral type from a bitstream.
  /// \details If the written value differed from the value compared against in the write function,
  /// var will be updated.  Otherwise it will retain the current value.
  /// ReadDelta is only valid from a previous call to WriteDelta
  /// \param[in] outTemplateVar The value to read
  /// \return true on success, false on failure.
  template <class templateType> bool ReadDelta(templateType &outTemplateVar);

  /// \brief Read any integral type from a bitstream.
  /// \details Undefine __BITSTREAM_NATIVE_END if you need endian swapping.
  /// For floating point, this is lossy, using 2 bytes for a float and 4 for a double.  The range must be between -1 and +1.
  /// For non-floating point, this is lossless, but only has benefit if you use less than half the bits of the type
  /// If you are not using __BITSTREAM_NATIVE_END the opposite is true for types larger than 1 byte
  /// \param[in] outTemplateVar The value to read
  /// \return true on success, false on failure.
  template <class templateType> bool ReadCompressed(templateType &outTemplateVar);

  /// \brief Read a wchar from a bitstream.
  /// \details Define __BITSTREAM_NATIVE_END if you need endian swapping.
  /// This is lossless, but only has benefit if you use less than half the bits of the type
  /// If you are not using __BITSTREAM_NATIVE_END the opposite is true
  /// \param[in] varString The value to read
  /// \param[in] varStringLength The length of the given varString array (in wchar_t)
  /// \return true on success, false on failure.
  bool ReadCompressed(wchar_t *&varString);
  bool ReadCompressed(wchar_t *&varString, size_t varStringLength);

  /// \brief Read any integral type from a bitstream.
  /// \details If the written value differed from the value compared against in the write function,
  /// var will be updated.  Otherwise it will retain the current value.
  /// the current value will be updated.
  /// For floating point, this is lossy, using 2 bytes for a float and 4 for a double.  The range must be between -1 and +1.
  /// For non-floating point, this is lossless, but only has benefit if you use less than half the bits of the type
  /// If you are not using __BITSTREAM_NATIVE_END the opposite is true for types larger than 1 byte
  /// ReadCompressedDelta is only valid from a previous call to WriteDelta
  /// \param[in] outTemplateVar The value to read
  /// \return true on success, false on failure.
  template <class templateType> bool ReadCompressedDelta(templateType &outTemplateVar);

  /// \brief Read one bitstream to another.
  /// \param[in] numberOfBits bits to read
  /// \param bitStream the bitstream to read into from
  /// \return true on success, false on failure.
  bool Read(BitStream *bitStream, BitSize_t numberOfBits);
  bool Read(BitStream *bitStream);
  bool Read(BitStream &bitStream, BitSize_t numberOfBits);
  bool Read(BitStream &bitStream);

  /// \brief Write an array or casted stream or raw data.  This does NOT do endian swapping.
  /// \param[in] inputByteArray a byte buffer
  /// \param[in] numberOfBytes the size of \a input in bytes
  void Write(const char *inputByteArray, const unsigned int numberOfBytes);

  /// \brief Write one bitstream to another.
  /// \param[in] numberOfBits bits to write
  /// \param bitStream the bitstream to copy from
  void Write(BitStream *bitStream, BitSize_t numberOfBits);
  void Write(BitStream *bitStream);
  void Write(BitStream &bitStream, BitSize_t numberOfBits);
  void Write(BitStream &bitStream);

  /// \brief Write a float into 2 bytes, spanning the range between \a floatMin and \a floatMax
  /// \param[in] x The float to write
  /// \param[in] floatMin Predetermined minimum value of f
  /// \param[in] floatMax Predetermined maximum value of f
  void WriteFloat16(float x, float floatMin, float floatMax);

  /// Write one type serialized as another (smaller) type, to save bandwidth
  /// serializationType should be uint8_t, uint16_t, uint24_t, or uint32_t
  /// Example: int num=53; WriteCasted<uint8_t>(num); would use 1 byte to write what would otherwise be an integer (4 or 8 bytes)
  /// \param[in] value The value to write
  template <class serializationType, class sourceType> void WriteCasted(const sourceType &value);

  /// Given the minimum and maximum values for an integer type, figure out the minimum number of bits to represent the range
  /// Then write only those bits
  /// \note A static is used so that the required number of bits for (maximum-minimum) is only calculated once. This does require that \a minimum and \maximum are fixed values for a given line of code
  /// for the life of the program \param[in] value Integer value to write, which should be between \a minimum and \a maximum \param[in] minimum Minimum value of \a value \param[in] maximum Maximum
  /// value of \a value \param[in] allowOutsideRange If true, all sends will take an extra bit, however value can deviate from outside \a minimum and \a maximum. If false, will assert if the value
  /// deviates. This should match the corresponding value passed to Read().
  template <class templateType> void WriteBitsFromIntegerRange(const templateType value, const templateType minimum, const templateType maximum, bool allowOutsideRange = false);
  /// \param[in] requiredBits Primarily for internal use, called from above function() after calculating number of bits needed to represent maximum-minimum
  template <class templateType>
  void WriteBitsFromIntegerRange(const templateType value, const templateType minimum, const templateType maximum, const int requiredBits, bool allowOutsideRange = false);

  /// \brief Write a normalized 3D vector, using (at most) 4 bytes + 3 bits instead of 12-24 bytes.
  /// \details Will further compress y or z axis aligned vectors.
  /// Accurate to 1/32767.5.
  /// \param[in] x x
  /// \param[in] y y
  /// \param[in] z z
  template <class templateType> // templateType for this function must be a float or double
  void WriteNormVector(templateType x, templateType y, templateType z);

  /// \brief Write a vector, using 10 bytes instead of 12.
  /// \details Loses accuracy to about 3/10ths and only saves 2 bytes,
  /// so only use if accuracy is not important.
  /// \param[in] x x
  /// \param[in] y y
  /// \param[in] z z
  template <class templateType> // templateType for this function must be a float or double
  void WriteVector(templateType x, templateType y, templateType z);

  /// \brief Write a normalized quaternion in 6 bytes + 4 bits instead of 16 bytes.  Slightly lossy.
  /// \param[in] w w
  /// \param[in] x x
  /// \param[in] y y
  /// \param[in] z z
  template <class templateType> // templateType for this function must be a float or double
  void WriteNormQuat(templateType w, templateType x, templateType y, templateType z);

  /// \brief Write an orthogonal matrix by creating a quaternion, and writing 3 components of the quaternion in 2 bytes each.
  /// \details Use 6 bytes instead of 36
  /// Lossy, although the result is renormalized
  template <class templateType> // templateType for this function must be a float or double
  void WriteOrthMatrix(templateType m00, templateType m01, templateType m02, templateType m10, templateType m11, templateType m12, templateType m20, templateType m21, templateType m22);

  /// \brief Read an array or casted stream of byte.
  /// \details The array is raw data. There is no automatic endian conversion with this function
  /// \param[in] output The result byte array. It should be larger than @em numberOfBytes.
  /// \param[in] numberOfBytes The number of byte to read
  /// \return true on success false if there is some missing bytes.
  bool Read(char *output, const unsigned int numberOfBytes);

  /// \brief Read a float into 2 bytes, spanning the range between \a floatMin and \a floatMax
  /// \param[in] outFloat The float to read
  /// \param[in] floatMin Predetermined minimum value of f
  /// \param[in] floatMax Predetermined maximum value of f
  bool ReadFloat16(float &outFloat, float floatMin, float floatMax);

  /// Read one type serialized to another (smaller) type, to save bandwidth
  /// serializationType should be uint8_t, uint16_t, uint24_t, or uint32_t
  /// Example: int num; ReadCasted<uint8_t>(num); would read 1 bytefrom the stream, and put the value in an integer
  /// \param[in] value The value to write
  template <class serializationType, class sourceType> bool ReadCasted(sourceType &value);

  /// Given the minimum and maximum values for an integer type, figure out the minimum number of bits to represent the range
  /// Then read only those bits
  /// \note A static is used so that the required number of bits for (maximum-minimum) is only calculated once. This does require that \a minimum and \maximum are fixed values for a given line of code
  /// for the life of the program \param[in] value Integer value to read, which should be between \a minimum and \a maximum \param[in] minimum Minimum value of \a value \param[in] maximum Maximum
  /// value of \a value \param[in] allowOutsideRange If true, all sends will take an extra bit, however value can deviate from outside \a minimum and \a maximum. If false, will assert if the value
  /// deviates. This should match the corresponding value passed to Write().
  template <class templateType> bool ReadBitsFromIntegerRange(templateType &value, const templateType minimum, const templateType maximum, bool allowOutsideRange = false);
  /// \param[in] requiredBits Primarily for internal use, called from above function() after calculating number of bits needed to represent maximum-minimum
  template <class templateType> bool ReadBitsFromIntegerRange(templateType &value, const templateType minimum, const templateType maximum, const int requiredBits, bool allowOutsideRange = false);

  /// \brief Read a normalized 3D vector, using (at most) 4 bytes + 3 bits instead of 12-24 bytes.
  /// \details Will further compress y or z axis aligned vectors.
  /// Accurate to 1/32767.5.
  /// \param[in] x x
  /// \param[in] y y
  /// \param[in] z z
  /// \return true on success, false on failure.
  template <class templateType> // templateType for this function must be a float or double
  bool ReadNormVector(templateType &x, templateType &y, templateType &z);

  /// \brief Read 3 floats or doubles, using 10 bytes, where those float or doubles comprise a vector.
  /// \details Loses accuracy to about 3/10ths and only saves 2 bytes,
  /// so only use if accuracy is not important.
  /// \param[in] x x
  /// \param[in] y y
  /// \param[in] z z
  /// \return true on success, false on failure.
  template <class templateType> // templateType for this function must be a float or double
  bool ReadVector(templateType &x, templateType &y, templateType &z);

  /// \brief Read a normalized quaternion in 6 bytes + 4 bits instead of 16 bytes.
  /// \param[in] w w
  /// \param[in] x x
  /// \param[in] y y
  /// \param[in] z z
  /// \return true on success, false on failure.
  template <class templateType> // templateType for this function must be a float or double
  bool ReadNormQuat(templateType &w, templateType &x, templateType &y, templateType &z);

  /// \brief Read an orthogonal matrix from a quaternion, reading 3 components of the quaternion in 2 bytes each and extrapolatig the 4th.
  /// \details Use 6 bytes instead of 36
  /// Lossy, although the result is renormalized
  /// \return true on success, false on failure.
  template <class templateType> // templateType for this function must be a float or double
  bool ReadOrthMatrix(templateType &m00, templateType &m01, templateType &m02, templateType &m10, templateType &m11, templateType &m12, templateType &m20, templateType &m21, templateType &m22);

  /// \brief Sets the read pointer back to the beginning of your data.
  void ResetReadPointer(void);

  /// \brief Sets the write pointer back to the beginning of your data.
  void ResetWritePointer(void);

  /// \brief This is good to call when you are done with the stream to make
  /// sure you didn't leave any data left over void
  void AssertStreamEmpty(void);

  /// \brief RAKNET_DEBUG_PRINTF the bits in the stream.  Great for debugging.
  void PrintBits(char *out) const;
  void PrintBits(char *out, size_t outLength) const;
  void PrintBits(void) const;
  void PrintHex(char *out) const;
  void PrintHex(char *out, size_t outLength) const;
  void PrintHex(void) const;

  /// \brief Ignore data we don't intend to read
  /// \param[in] numberOfBits The number of bits to ignore
  void IgnoreBits(const BitSize_t numberOfBits);

  /// \brief Ignore data we don't intend to read
  /// \param[in] numberOfBits The number of bytes to ignore
  void IgnoreBytes(const unsigned int numberOfBytes);

  /// \brief Move the write pointer to a position on the array.
  /// \param[in] offset the offset from the start of the array.
  /// \attention
  /// \details Dangerous if you don't know what you are doing!
  /// For efficiency reasons you can only write mid-stream if your data is byte aligned.
  void SetWriteOffset(const BitSize_t offset);

  /// \brief Returns the length in bits of the stream
  inline BitSize_t GetNumberOfBitsUsed(void) const { return GetWriteOffset(); }
  inline BitSize_t GetWriteOffset(void) const { return numberOfBitsUsed; }

  /// \brief Returns the length in bytes of the stream
  inline BitSize_t GetNumberOfBytesUsed(void) const { return BITS_TO_BYTES(numberOfBitsUsed); }

  /// \brief Returns the number of bits into the stream that we have read
  inline BitSize_t GetReadOffset(void) const { return readOffset; }

  /// \brief Sets the read bit index
  void SetReadOffset(const BitSize_t newReadOffset) { readOffset = newReadOffset; }

  /// \brief Returns the number of bits left in the stream that haven't been read
  inline BitSize_t GetNumberOfUnreadBits(void) const { return numberOfBitsUsed - readOffset; }

  /// \brief Makes a copy of the internal data for you \a _data will point to
  /// the stream. Partial bytes are left aligned.
  /// \param[out] _data The allocated copy of GetData()
  /// \return The length in bits of the stream.
  BitSize_t CopyData(unsigned char **_data) const;

  /// \internal
  /// Set the stream to some initial data.
  void SetData(unsigned char *inByteArray);

  /// Gets the data that BitStream is writing to / reading from.
  /// Partial bytes are left aligned.
  /// \return A pointer to the internal state
  inline unsigned char *GetData(void) const { return data; }

  /// \brief Write numberToWrite bits from the input source.
  /// \details Right aligned data means in the case of a partial byte, the bits are aligned
  /// from the right (bit 0) rather than the left (as in the normal
  /// internal representation) You would set this to true when
  /// writing user data, and false when copying bitstream data, such
  /// as writing one bitstream to another.
  /// \param[in] inByteArray The data
  /// \param[in] numberOfBitsToWrite The number of bits to write
  /// \param[in] rightAlignedBits if true data will be right aligned
  void WriteBits(const unsigned char *inByteArray, BitSize_t numberOfBitsToWrite, const bool rightAlignedBits = true);

  /// \brief Align the bitstream to the byte boundary and then write the
  /// specified number of bits.
  /// \details This is faster than WriteBits but
  /// wastes the bits to do the alignment and requires you to call
  /// ReadAlignedBits at the corresponding read position.
  /// \param[in] inByteArray The data
  /// \param[in] numberOfBytesToWrite The size of input.
  void WriteAlignedBytes(const unsigned char *inByteArray, const unsigned int numberOfBytesToWrite);

  // Endian swap bytes already in the bitstream
  void EndianSwapBytes(int byteOffset, int length);

  /// \brief Aligns the bitstream, writes inputLength, and writes input. Won't write beyond maxBytesToWrite
  /// \param[in] inByteArray The data
  /// \param[in] inputLength The size of input.
  /// \param[in] maxBytesToWrite Max bytes to write
  void WriteAlignedBytesSafe(const char *inByteArray, const unsigned int inputLength, const unsigned int maxBytesToWrite);

  /// \brief Read bits, starting at the next aligned bits.
  /// \details Note that the modulus 8 starting offset of the sequence must be the same as
  /// was used with WriteBits. This will be a problem with packet
  /// coalescence unless you byte align the coalesced packets.
  /// \param[in] inOutByteArray The byte array larger than @em numberOfBytesToRead
  /// \param[in] numberOfBytesToRead The number of byte to read from the internal state
  /// \return true if there is enough byte.
  bool ReadAlignedBytes(unsigned char *inOutByteArray, const unsigned int numberOfBytesToRead);

  /// \brief Reads what was written by WriteAlignedBytesSafe.
  /// \param[in] inOutByteArray The data
  /// \param[in] maxBytesToRead Maximum number of bytes to read
  /// \return true on success, false on failure.
  bool ReadAlignedBytesSafe(char *inOutByteArray, int &inputLength, const int maxBytesToRead);
  bool ReadAlignedBytesSafe(char *inOutByteArray, unsigned int &inputLength, const unsigned int maxBytesToRead);

  /// \brief Same as ReadAlignedBytesSafe() but allocates the memory for you using new, rather than assuming it is safe to write to
  /// \param[in] outByteArray outByteArray will be deleted if it is not a pointer to 0
  /// \return true on success, false on failure.
  bool ReadAlignedBytesSafeAlloc(char **outByteArray, int &inputLength, const unsigned int maxBytesToRead);
  bool ReadAlignedBytesSafeAlloc(char **outByteArray, unsigned int &inputLength, const unsigned int maxBytesToRead);

  /// \brief Align the next write and/or read to a byte boundary.
  /// \details This can be used to 'waste' bits to byte align for efficiency reasons It
  /// can also be used to force coalesced bitstreams to start on byte
  /// boundaries so so WriteAlignedBits and ReadAlignedBits both
  /// calculate the same offset when aligning.
  inline void AlignWriteToByteBoundary(void) { numberOfBitsUsed += 8 - (((numberOfBitsUsed - 1) & 7) + 1); }

  /// \brief Align the next write and/or read to a byte boundary.
  /// \details This can be used to 'waste' bits to byte align for efficiency reasons It
  /// can also be used to force coalesced bitstreams to start on byte
  /// boundaries so so WriteAlignedBits and ReadAlignedBits both
  /// calculate the same offset when aligning.
  inline void AlignReadToByteBoundary(void) { readOffset += 8 - (((readOffset - 1) & 7) + 1); }

  /// \brief Read \a numberOfBitsToRead bits to the output source.
  /// \details alignBitsToRight should be set to true to convert internal
  /// bitstream data to userdata. It should be false if you used
  /// WriteBits with rightAlignedBits false
  /// \param[in] inOutByteArray The resulting bits array
  /// \param[in] numberOfBitsToRead The number of bits to read
  /// \param[in] alignBitsToRight if true bits will be right aligned.
  /// \return true if there is enough bits to read
  bool ReadBits(unsigned char *inOutByteArray, BitSize_t numberOfBitsToRead, const bool alignBitsToRight = true);

  /// \brief Write a 0
  void Write0(void);

  /// \brief Write a 1
  void Write1(void);

  /// \brief Reads 1 bit and returns true if that bit is 1 and false if it is 0.
  bool ReadBit(void);

  /// \brief If we used the constructor version with copy data off, this
  /// *makes sure it is set to on and the data pointed to is copied.
  void AssertCopyData(void);

  /// \brief Use this if you pass a pointer copy to the constructor
  /// *(_copyData==false) and want to overallocate to prevent
  /// reallocation.
  void SetNumberOfBitsAllocated(const BitSize_t lengthInBits);

  /// \brief Reallocates (if necessary) in preparation of writing numberOfBitsToWrite
  void AddBitsAndReallocate(const BitSize_t numberOfBitsToWrite);

  /// \internal
  /// \return How many bits have been allocated internally
  BitSize_t GetNumberOfBitsAllocated(void) const;

  /// \brief Read strings, non reference.
  bool Read(char *varString);
  bool Read(unsigned char *varString);

  /// Write zeros until the bitstream is filled up to \a bytes
  void PadWithZeroToByteLength(unsigned int bytes);

  /// Get the number of leading zeros for a number
  /// \param[in] x Number to test
  static int NumberOfLeadingZeroes(uint8_t x);
  static int NumberOfLeadingZeroes(uint16_t x);
  static int NumberOfLeadingZeroes(uint32_t x);
  static int NumberOfLeadingZeroes(uint64_t x);
  static int NumberOfLeadingZeroes(int8_t x);
  static int NumberOfLeadingZeroes(int16_t x);
  static int NumberOfLeadingZeroes(int32_t x);
  static int NumberOfLeadingZeroes(int64_t x);

  /// \internal Unrolled inner loop, for when performance is critical
  void WriteAlignedVar8(const char *inByteArray);
  /// \internal Unrolled inner loop, for when performance is critical
  bool ReadAlignedVar8(char *inOutByteArray);
  /// \internal Unrolled inner loop, for when performance is critical
  void WriteAlignedVar16(const char *inByteArray);
  /// \internal Unrolled inner loop, for when performance is critical
  bool ReadAlignedVar16(char *inOutByteArray);
  /// \internal Unrolled inner loop, for when performance is critical
  void WriteAlignedVar32(const char *inByteArray);
  /// \internal Unrolled inner loop, for when performance is critical
  bool ReadAlignedVar32(char *inOutByteArray);

  inline void Write(const char *const inStringVar) { RakString::Serialize(inStringVar, this); }
  inline void Write(const unsigned char *const inTemplateVar) { Write((const char *)inTemplateVar); }
  inline void Write(char *const inTemplateVar) { Write((const char *)inTemplateVar); }
  inline void Write(unsigned char *const inTemplateVar) { Write((const char *)inTemplateVar); }
  inline void WriteCompressed(const char *const inStringVar) { RakString::SerializeCompressed(inStringVar, this, 0, false); }
  inline void WriteCompressed(const unsigned char *const inTemplateVar) { WriteCompressed((const char *)inTemplateVar); }
  inline void WriteCompressed(char *const inTemplateVar) { WriteCompressed((const char *)inTemplateVar); }
  inline void WriteCompressed(unsigned char *const inTemplateVar) { WriteCompressed((const char *)inTemplateVar); }

  /// ---- Member function template specialization declarations ----
  inline static bool DoEndianSwap(void) { return IsNetworkOrder() == false; }
  inline static bool IsBigEndian(void) { return IsNetworkOrder(); }
  inline static bool IsNetworkOrder(void) {
    bool r = IsNetworkOrderInternal();
    return r;
  }
  // Not inline, won't compile on PC due to winsock include errors
  static bool IsNetworkOrderInternal(void);
  static void ReverseBytes(unsigned char *inByteArray, unsigned char *inOutByteArray, const unsigned int length);
  static void ReverseBytesInPlace(unsigned char *inOutData, const unsigned int length);

private:
  BitStream(const BitStream &invalid) { (void)invalid; }

  BitStream &operator=(const BitStream &invalid) {
    (void)invalid;
    static BitStream i;
    return i;
  }

  /// \brief Assume the input source points to a native type, compress and write it.
  void WriteCompressed(const unsigned char *inByteArray, const unsigned int size, const bool unsignedData);

  /// \brief Assume the input source points to a compressed native type. Decompress and read it.
  bool ReadCompressed(unsigned char *inOutByteArray, const unsigned int size, const bool unsignedData);

  BitSize_t numberOfBitsUsed;

  BitSize_t numberOfBitsAllocated;

  BitSize_t readOffset;

  unsigned char *data;

  /// true if the internal buffer is copy of the data passed to the constructor
  bool copyData;

  /// BitStreams that use less than BITSTREAM_STACK_ALLOCATION_SIZE use the stack, rather than the heap to store data.  It switches over if BITSTREAM_STACK_ALLOCATION_SIZE is exceeded
  unsigned char stackData[BITSTREAM_STACK_ALLOCATION_SIZE];
};

} // namespace RakNet