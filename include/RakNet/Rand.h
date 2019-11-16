#pragma once

/// Initialise seed for Random Generator
/// \note not threadSafe, use an instance of RakNetRandom if necessary per thread
/// \param[in] seed The seed value for the random number generator.
extern void seedMT(unsigned int seed);

/// \internal
/// \note not threadSafe, use an instance of RakNetRandom if necessary per thread
extern unsigned int reloadMT(void);

/// Gets a random unsigned int
/// \note not threadSafe, use an instance of RakNetRandom if necessary per thread
/// \return an integer random value.
extern unsigned int randomMT(void);

/// Gets a random float
/// \note not threadSafe, use an instance of RakNetRandom if necessary per thread
/// \return 0 to 1.0f, inclusive
extern float frandomMT(void);

/// Randomizes a buffer
/// \note not threadSafe, use an instance of RakNetRandom if necessary per thread
extern void fillBufferMT(void *buffer, unsigned int bytes);

namespace RakNet {

// Same thing as above functions, but not global
class RakNetRandom {
public:
  RakNetRandom();
  ~RakNetRandom();
  void SeedMT(unsigned int seed);
  unsigned int ReloadMT(void);
  unsigned int RandomMT(void);
  float FrandomMT(void);
  void FillBufferMT(void *buffer, unsigned int bytes);

protected:
  unsigned int state[624 + 1];
  unsigned int *next;
  int left;
};

} // namespace SLNet