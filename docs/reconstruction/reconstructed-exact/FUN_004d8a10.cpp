// =============================================================================
// FUN_004d8a10  (alias → CVOGSectorMap_Constructor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004d8a10
// Address:   0x004d8a10–0x004d938f  (autoassault.exe, image base 0x400000)
// System:    client / CVOGSectorMap
// Generated: 2026-07-29 W24-F (twin of named clean)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: reconstructed-exact/CVOGSectorMap_Constructor.cpp
// =============================================================================
//
// Ghidra-faithful surface lives below as a thin include of the named unit's
// control-flow listing. Prefer CVOGSectorMap_Constructor.cpp for phased reads.
// Full store-by-store decompiler text: raw/aa_004d8a10_FUN_004d8a10.md
//

#include <cstdint>
#include <windows.h>

// Forward to named reconstruction (thiscall as __fastcall single-reg this).
struct CVOGSectorMap;
extern CVOGSectorMap* __fastcall CVOGSectorMap_Constructor(CVOGSectorMap* self);

extern "C" uint32_t* __fastcall FUN_004d8a10(uint32_t* param_1)
{
  return (uint32_t*)CVOGSectorMap_Constructor((CVOGSectorMap*)param_1);
}

// NOTE: Prior auto-scaffold expanded the full decompiler listing with uint32_t
// casts. That expansion is superseded by CVOGSectorMap_Constructor.cpp (W24-F)
// which preserves the same stores/calls in phased form. Authoritative raw
// pseudocode remains in docs/reconstruction/raw/aa_004d8a10_FUN_004d8a10.md.
