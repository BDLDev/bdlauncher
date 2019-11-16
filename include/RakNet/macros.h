#pragma once

#define _FILE_AND_LINE_ __FILE__, __LINE__

#define BITSTREAM_STACK_ALLOCATION_SIZE 256
#define RESEND_BUFFER_ARRAY_LENGTH 512
#define RESEND_BUFFER_ARRAY_MASK 511
#define MAXIMUM_NUMBER_OF_INTERNAL_IDS 10

#define STATIC_FACTORY_DECLARATIONS(x)                                                                                                                                                                 \
  static x *GetInstance(void);                                                                                                                                                                         \
  static void DestroyInstance(x *i);

#define STATIC_FACTORY_DEFINITIONS(x, y)                                                                                                                                                               \
  x *x::GetInstance(void) { return SLNet::OP_NEW<y>(_FILE_AND_LINE_); }                                                                                                                                \
  void x::DestroyInstance(x *i) { SLNet::OP_DELETE((y *)i, _FILE_AND_LINE_); }
