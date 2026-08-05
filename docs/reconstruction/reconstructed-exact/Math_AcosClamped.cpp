// =============================================================================
// Math_AcosClamped  (Ghidra: FUN_0040d0a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d0a0
// Address:   0x0040d0a0  (autoassault.exe, image base 0x400000)
// System:    physics / shared math
// Generated: 2026-07-29 dual A/B seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
// Domain-safe inverse cosine in radians.
//   |x| <  1  → CRT _CIacos(x)
//   |x| >= 1  → 0.0 if x > 0, else π (DAT_00a27c3c)
// Avoids feeding _CIacos arguments outside [-1, 1].

// ABI (sealed):
//   __cdecl
//   arg0: float x @ [esp+4]
//   return: angle radians in ST0 (x87 float10)

// CONSTANTS (read_memory 2026-07-29):
//   g_flOne      @ 0x00a0f2a0 = 1.0f   (00 00 80 3f)
//   DAT_00a27c3c @ 0x00a27c3c = π      (db 0f 49 40)

// CALLEES: _CIacos @ 0x006a3e26
// CALLERS: turret aim, orientation helpers, UI tooltip, camera residual, … (17 sites)

extern float g_flOne;           // 0x00a0f2a0
extern float DAT_00a27c3c;      // 0x00a27c3c == π
extern long double _CIacos(void); // CRT; arg already in ST0 on entry convention

// Retail body does not expose a C prototype for _CIacos; decompiler shows
// float10 return from the helper. Clean form matches CF only.

typedef long double float10;

float10 Math_AcosClamped(float x)
{
  float10 fVar1;
  float fVar2;

  if (g_flOne <= (float)((x < 0.0f) ? -x : x) /* ABS(x) */) {
    /* |x| >= 1: saturated endpoints of acos on [-1,1] (and exterior map) */
    fVar2 = 0.0f;
    if (x <= 0.0f) {
      fVar2 = DAT_00a27c3c; /* π */
    }
    return (float10)fVar2;
  }
  /* |x| < 1: load x into ST0 and call CRT acos */
  fVar1 = (float10)_CIacos();
  return fVar1;
}

/*
 * Behavioral notes:
 * - CF matches raw aa_0040d0a0 and live Ghidra decompile (2026-07-29).
 * - Assembly uses FABS + FCOMIP vs g_flOne; JC when |x| < 1.
 * - Saturated path: XORPS zero; COMISS x,0; JA keeps 0; else MOVSS π.
 * - Name Math_AcosClamped is inferred (product symbol unknown).
 */
