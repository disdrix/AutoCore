// =============================================================================
// FUN_005b36f0  (scaffold twin of Env_ApplyFogShaderAndReflect_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b36f0
// Address:   0x005b36f0  (autoassault.exe, image base 0x400000)
// Body:      0x005b36f0–0x005b3992 (674 B / 0x2A2)
// Wave:      W29-I OWN-ONLY dual (2026-07-29)
// Canonical: Env_ApplyFogShaderAndReflect_Inferred
// Exactness: Behavior-preserving rewrite of decompiler CF; vtbl+ret4 sealed.
// Bit-for-bit / runtime / differential: OPEN.
// =============================================================================

// See Env_ApplyFogShaderAndReflect_Inferred.cpp for the dual-sealed port surface.
// This twin keeps the Ghidra symbol for scaffold continuity.

#include <stdint.h>

uint32_t __thiscall Env_ApplyFogShaderAndReflect_Inferred(void *self, uint32_t arg0);

uint32_t __thiscall FUN_005b36f0(void *param_1, uint32_t param_2)
{
  return Env_ApplyFogShaderAndReflect_Inferred(param_1, param_2);
}
