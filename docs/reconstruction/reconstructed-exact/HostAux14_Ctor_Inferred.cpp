// =============================================================================
// HostAux14_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00442c80
// Address:   0x00442c80  (autoassault.exe, image base 0x400000)
// System:    client / host-base aux (+8 slot of HostBase_EnsureAuxPtrs)
// Generated: 2026-07-29 W33-S dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Construct 0x14-byte host aux object placed at host+8:
//   +0 = PTR_FUN_00a9f49c (vtbl)
//   +4 = untouched
//   +8/+0xc/+0x10 = 0
// ABI: self* on stack (not ECX); RET 4; returns self in EAX (MSVC ctor).
// Sole caller: HostBase_EnsureAuxPtrs_Inferred after operator_new(0x14).

#include <cstdint>

// Vtable image symbol (Ghidra: PTR_FUN_00a9f49c)
extern "C" void *PTR_FUN_00a9f49c;

extern "C" void *HostAux14_Ctor_Inferred(void *self)
{
  auto *obj = static_cast<uint32_t *>(self);
  obj[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a9f49c);
  // obj[1] (+0x04) intentionally not written
  obj[2] = 0;
  obj[3] = 0;
  obj[4] = 0;
  return self; // EAX at RET
}

// Twin export for FUN_* symbol stability
extern "C" void *FUN_00442c80(void *self)
{
  return HostAux14_Ctor_Inferred(self);
}
