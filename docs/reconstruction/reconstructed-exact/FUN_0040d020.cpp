// =============================================================================
// FUN_0040d020  (named: Math_Vec3Length_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d020
// Address:   0x0040d020  (autoassault.exe, image base 0x400000)
// System:    interaction-activation (partition) / shared pure math leaf
// Generated: 2026-08-05 MEGA-137 dual A/B seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
// Euclidean 3-float length leaf: return sqrt(x*x + y*y + z*z) in ST0.
// Twin clean: Math_Vec3Length_Inferred.cpp

// ABI (sealed): __cdecl; three float stack args; ST0 return; plain RET.
// BODY: 0x0040d020–0x0040d03e (31 B). CALLEES: none.
// CALLERS: Client_InteractClickPickTarget (×2), FUN_005ba440 (×1).

typedef long double float10;

float10 FUN_0040d020(float param_1, float param_2, float param_3)
{
  return SQRT((float10)param_3 * (float10)param_3 +
              (float10)param_2 * (float10)param_2 +
              (float10)param_1 * (float10)param_1);
}
