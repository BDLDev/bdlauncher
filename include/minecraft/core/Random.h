#pragma once

#include "minecraft/core/types.h"

class Random{
public:
unsigned int getSeed() const;
double nextDouble();
bool nextBoolean();
void* nextGaussian();
//00000000069a01c0 W Random::getThreadLocal()
void* nextGaussianInt(int);
unsigned int nextUnsignedInt(unsigned int);
void* nextGaussianVec3();
int nextIntInclusive(int, int);
unsigned char nextUnsignedChar();
void* nextGaussianFloat();
//000000000af9a450 B Random::mThreadLocalRandom
//0000000006381d40 W Random::max()
//0000000006381d50 W Random::min()
int nextInt(int);
int nextInt(int, int);
unsigned int nextInt();
void setSeed(unsigned int);
Vec3 nextVec3();
float nextFloat(float);
float nextFloat(float, float);
float nextFloat();

Random(unsigned int);
Random(Random const&);
Random();
//0000000007966d70 W Random::operator()(int)
//0000000006382320 W Random::operator()()
};
