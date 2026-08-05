// =============================================================================
// FUN_00442c80 / HostAux14_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00442c80
// Address:   0x00442c80  (autoassault.exe, image base 0x400000)
// System:    client / host-base aux (+8 slot of HostBase_EnsureAuxPtrs)
// Generated: 2026-07-29 W33-S dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: 0x14-byte aux ctor — vtbl PTR_FUN_00a9f49c; zero +8/+0xc/+0x10;
// leave +4 untouched. Stack self*; RET 4; returns self in EAX.

#include <cstdint>

extern "C" void *PTR_FUN_00a9f49c;

extern "C" void *FUN_00442c80(void *self)
{
  auto *obj = static_cast<uint32_t *>(self);
  obj[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a9f49c);
  obj[2] = 0;
  obj[3] = 0;
  obj[4] = 0;
  return self;
}
