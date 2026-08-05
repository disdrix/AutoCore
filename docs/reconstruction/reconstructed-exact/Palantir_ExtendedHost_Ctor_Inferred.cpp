// =============================================================================
// Palantir_ExtendedHost_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007a26c0
// Address:   0x007a26c0  (autoassault.exe, image base 0x400000)
// System:    Palantir / client host shell
// Generated: 2026-08-04 W37-R
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Placement ctor for the **derived Palantir host**:
//     1) Palantir_BaseCtor (FUN_007543b0) — stack self, RET 4
//     2) install derived vtbl PTR_FUN_00a97170
//     3) FUN_00424bf0 with EAX = self+0xD8
//     4) stamp display defaults (800×600, flags), blend floats, list node
//     5) publish DAT_00d17958 = self; return self
//
// ABI (bytes): stack arg0 = self*; RET 4; EAX = self. Not ECX-thiscall.
// Reject: Named_CalleeOf_Named_Client_InitInstance_007a26c0
//
// See also: reconstructed-exact/FUN_007a26c0.cpp (decompiler-faithful twin)

#include <cstdint>

// Named entry is an alias documentation surface; implementation twin is FUN_007a26c0.
extern "C" std::uint32_t* FUN_007a26c0(std::uint32_t* self);

std::uint32_t* Palantir_ExtendedHost_Ctor_Inferred(std::uint32_t* self)
{
  return FUN_007a26c0(self);
}
