#pragma once

#include "macros.h"
#include "DataStructures.h"
#include "memoryoverride.h"
#include <cstdint>

namespace RakNet {
/// Forward declaration
class BitStream;
class RakString;
class HuffmanEncodingTree;

/// \brief Writes and reads strings to and from bitstreams.
///
/// Only works with ASCII strings.  The default compression is for English.
/// You can call GenerateTreeFromStrings to compress and decompress other languages efficiently as well.
class StringCompressor {
public:
  // Destructor
  ~StringCompressor();

  /// static function because only static functions can access static members
  /// The RakPeer constructor adds a reference to this class, so don't call this until an instance of RakPeer exists, or unless you call AddReference yourself.
  /// \return the unique instance of the StringCompressor
  static StringCompressor *Instance(void);

  /// Given an array of strings, such as a chat log, generate the optimal encoding tree for it.
  /// This function is optional and if it is not called a default tree will be used instead.
  /// \param[in] input An array of bytes which should point to text.
  /// \param[in] inputLength Length of \a input
  /// \param[in] languageID An identifier for the language / string table to generate the tree for.  English is automatically created with ID 0 in the constructor.
  void GenerateTreeFromStrings(unsigned char *input, unsigned inputLength, uint8_t languageId);

  /// Writes input to output, compressed.  Takes care of the null terminator for you.
  /// \param[in] input Pointer to an ASCII string
  /// \param[in] maxCharsToWrite The max number of bytes to write of \a input.  Use 0 to mean no limit.
  /// \param[out] output The bitstream to write the compressed string to
  /// \param[in] languageID Which language to use
  void EncodeString(const char *input, int maxCharsToWrite, BitStream *output, uint8_t languageId = 0);

  /// Writes input to output, uncompressed.  Takes care of the null terminator for you.
  /// \param[out] output A block of bytes to receive the output
  /// \param[in] maxCharsToWrite Size, in bytes, of \a output .  A NULL terminator will always be appended to the output string.  If the maxCharsToWrite is not large enough, the string will be
  /// truncated. \param[in] input The bitstream containing the compressed string \param[in] languageID Which language to use
  bool DecodeString(char *output, int maxCharsToWrite, BitStream *input, uint8_t languageId = 0);

  void EncodeString(const RakString *input, int maxCharsToWrite, BitStream *output, uint8_t languageId = 0);
  bool DecodeString(RakString *output, int maxCharsToWrite, BitStream *input, uint8_t languageId = 0);

  /// Used so I can allocate and deallocate this singleton at runtime
  static void AddReference(void);

  /// Used so I can allocate and deallocate this singleton at runtime
  static void RemoveReference(void);

  StringCompressor();

private:
  /// Singleton instance
  static StringCompressor *instance;

  /// Pointer to the huffman encoding trees.
  DataStructures::Map<int, HuffmanEncodingTree *> huffmanEncodingTrees;

  static int referenceCount;
};
} // namespace RakNet