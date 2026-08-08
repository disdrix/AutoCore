// =============================================================================
// Math_Vec3Length_Inferred  (Ghidra: FUN_0040d020)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d020
// Address:   0x0040d020  (autoassault.exe, image base 0x400000)
// System:    interaction-activation (partition) / shared pure math leaf
// Generated: 2026-08-05 MEGA-137 dual A/B seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
// Euclidean length of a 3-float vector: sqrt(x*x + y*y + z*z).
// Pure math leaf (no callees, no globals). Used by pick-target distance and
// residual path/segment distance callers; those callers may scale the result
// (e.g. * 0.015f via DAT_00aaacbc) — scale is NOT part of this function.

// ABI (sealed):
//   __cdecl
//   arg0: float x @ [esp+4]
//   arg1: float y @ [esp+8]
//   arg2: float z @ [esp+0xc]
//   return: length in ST0 (x87 float10)
//   RET (not RET n)

// BODY: 0x0040d020–0x0040d03e inclusive (31 B)
// HEX:  d9442404 d84c2404 d9442408 d84c2408 dec1 d944240c d84c240c dec1 d9fa c3

// CALLEES: none (FSQRT is an instruction)
// CALLERS (3 sites / 2 funcs):
//   Client_InteractClickPickTarget @ 0x009249c0, 0x00924c76
//   FUN_005ba440                   @ 0x005bad63

// RETIRED SCAFFOLD:
//   Named_CalleeOf_Client_InteractClickPickTarget_0040d020 — parent is not exclusive.

typedef long double float10;

float10 Math_Vec3Length_Inferred(float x, float y, float z)
{
  return SQRT((float10)z * (float10)z +
              (float10)y * (float10)y +
              (float10)x * (float10)x);
}

/*
 * Behavioral notes:
 * - CF matches raw aa_0040d020 and live Ghidra decompile (2026-08-05 MEGA-137).
 * - Assembly: FLD/FMUL each component, FADDP twice, FSQRT, RET.
 * - Not squared-length (no missing FSQRT); not 2D; not normalize.
 * - Product/PDB name open → _Inferred suffix.
 */
