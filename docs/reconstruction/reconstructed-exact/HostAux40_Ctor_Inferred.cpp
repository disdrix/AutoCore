// =============================================================================
// HostAux40_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e380
// Address:   0x0074e380  (autoassault.exe, image base 0x400000)
// System:    client / host-base aux (+4 slot via PoolHost 0x40)
// Generated: 2026-07-29 W35-R dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Construct 0x40-byte host aux object placed at host+4 by
//   HostBase_EnsureAuxPtrs → PoolHost_Acquire0x40 (freelist miss: new(0x40)+this):
//   +0x00 = 1.0f (g_flOne)
//   +0x04 = untouched
//   +0x08/+0x0c/+0x10 = 0
//   +0x14 = NestedHash_Ctor_Sentinel0xC (span 0x28)
//   +0x3c = 0
// ABI: self* on stack (not ECX); RET 4; returns self in EAX (MSVC placement ctor).
// Sole direct caller: PoolHost_Acquire0x40_Inferred (0x00986070).

#include <cstdint>

// Nested hash placement ctor (W34-F): aa_0043fdf0
extern "C" void *NestedHash_Ctor_Sentinel0xC_Inferred(void *self);

// Image float constant g_flOne @ 0x00a0f2a0 (= 1.0f)
extern "C" float g_flOne;

extern "C" void *HostAux40_Ctor_Inferred(void *self)
{
  auto *obj = static_cast<uint32_t *>(self);
  auto *as_float = static_cast<float *>(self);

  as_float[0] = g_flOne; // +0x00
  // obj[1] (+0x04) intentionally not written
  obj[2] = 0; // +0x08
  obj[3] = 0; // +0x0c
  obj[4] = 0; // +0x10

  NestedHash_Ctor_Sentinel0xC_Inferred(reinterpret_cast<uint8_t *>(self) + 0x14);

  obj[0xf] = 0; // +0x3c
  return self;  // EAX at RET 4
}

// Twin export for FUN_* symbol stability
extern "C" void *FUN_0074e380(void *self)
{
  return HostAux40_Ctor_Inferred(self);
}
