#pragma once

#include "../../util.h"
#include "Packet.h"

class TextPacket : public Packet {
  char filler[200 - sizeof(Packet)];

public:
  TextPacket();

  MakeAccessor(type, char, 32);
  MakeAccessor(sender, std::string, 40);

  virtual ~TextPacket();
  virtual int getId() const override;
  virtual std::string getName() const override;
  virtual void write(BinaryStream &) const override;
  virtual void read(ReadOnlyBinaryStream &) override;
  virtual bool disallowBatching(void) const override;

  static TextPacket createTranslatedAnnouncement(std::string const &sender, std::string const &content, std::string const &uuid, std::string const &xuid);
  static TextPacket createRaw(std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>> const&);
  static TextPacket createTranslatedChat(std::string const& txt);
  static TextPacket createJukeboxPopup(std::string const& txt);
};
