// Twin of Host54_NestedHash0xC_At28_Ctor_Inferred.cpp (Ghidra name FUN_00996bc0).
// Stable ID: aa_00996bc0  VA: 0x00996bc0  Wave: W35-S
// See: docs/reconstruction/reconstructed-exact/Host54_NestedHash0xC_At28_Ctor_Inferred.cpp

#include <cstdint>

extern "C" void* NestedHash_Ctor_Sentinel0xC_Inferred(void* self);

// stack(self*); RET 4; returns self
extern "C" void* FUN_00996bc0(void* self)
{
  auto* p = reinterpret_cast<uint8_t*>(self);
  *reinterpret_cast<uint32_t*>(p + 0x00) = 0;
  *reinterpret_cast<uint32_t*>(p + 0x04) = 0;
  *reinterpret_cast<uint32_t*>(p + 0x08) = 0;
  *(p + 0x0c) = 0;
  *reinterpret_cast<uint32_t*>(p + 0x10) = 8;
  *reinterpret_cast<uint32_t*>(p + 0x14) = 0;
  // +0x18 intentionally unwritten
  *reinterpret_cast<uint32_t*>(p + 0x1c) = 0;
  *reinterpret_cast<uint32_t*>(p + 0x20) = 0;
  *reinterpret_cast<uint32_t*>(p + 0x24) = 0;
  NestedHash_Ctor_Sentinel0xC_Inferred(p + 0x28);
  *(p + 0x50) = 1;
  return self;
}
