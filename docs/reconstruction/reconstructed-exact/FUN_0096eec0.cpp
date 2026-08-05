// Twin of Host34_NestedHash0xC_Singleton_Ctor_Inferred.cpp (Ghidra name FUN_0096eec0).
// Stable ID: aa_0096eec0  VA: 0x0096eec0  Wave: W35-S
// See: docs/reconstruction/reconstructed-exact/Host34_NestedHash0xC_Singleton_Ctor_Inferred.cpp

#include <cstdint>

extern "C" void* NestedHash_Ctor_Sentinel0xC_Inferred(void* self);
extern "C" uint32_t* FUN_0043bd40();
extern "C" int _atexit(void (*fn)());
extern "C" void LAB_009c3370();
extern "C" void LAB_0096ed30();

extern "C" void* DAT_00d1f04c;
extern "C" void* DAT_00d1f050;
extern "C" uint32_t DAT_00d1f7e8;
extern "C" void* DAT_00d1f7e4;
extern "C" void* PTR_FUN_00a9ef54;

// stack(self*); RET 4; returns self
extern "C" void* FUN_0096eec0(void* self)
{
  DAT_00d1f04c = self;
  NestedHash_Ctor_Sentinel0xC_Inferred(self);
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x28) = 1;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x2c) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x30) = 0;

  if ((DAT_00d1f7e8 & 1u) == 0) {
    DAT_00d1f7e8 |= 1u;
    DAT_00d1f7e4 = &PTR_FUN_00a9ef54;
    _atexit(&LAB_009c3370);
  }

  // Map insert at *DAT_00d1f050 + 0x58; key 0x00d1f7e4; value {LAB_0096ed30, 0}
  // (tree/key setup incomplete in decompiler — sealed from body bytes)
  (void)DAT_00d1f050;
  uint32_t* slot = FUN_0043bd40();
  slot[0] = reinterpret_cast<uint32_t>(&LAB_0096ed30);
  slot[1] = 0;
  return self;
}
