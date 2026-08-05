// =============================================================================
// FUN_0056b6b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056b6b0
// Address:   0x0056b6b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056b6b0 @ 0x0056b6b0
// Stable ID: aa_0056b6b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0056b6b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __fastcall FUN_0056b6b0(int param_1)



{

  return ((float10)((int)*(short *)(param_1 + 0x13a) + (int)*(short *)(param_1 + 0x12e)) *

          (float10)_DAT_00b04650 * (float10)DAT_00a0f298 +

         (float10)((int)*(short *)(param_1 + 0x138) + (int)*(short *)(param_1 + 300)) *

         (float10)_DAT_00b0464c * (float10)DAT_00a0f298 +

         (float10)((int)*(short *)(param_1 + 0x136) + (int)*(short *)(param_1 + 0x12a)) *

         (float10)_DAT_00b04648 * (float10)DAT_00a0f298 +

         (float10)((int)*(short *)(param_1 + 0x134) + (int)*(short *)(param_1 + 0x128)) *

         (float10)_DAT_00b04644 * (float10)DAT_00a0f298 +

         (float10)((int)*(short *)(param_1 + 0x132) + (int)*(short *)(param_1 + 0x126)) *

         (float10)_DAT_00b04640 * (float10)DAT_00a0f298 +

         (float10)((int)*(short *)(param_1 + 0x130) + (int)*(short *)(param_1 + 0x124)) *

         (float10)_DAT_00b0463c * (float10)DAT_00a0f298) /

         ((float10)*(int *)(param_1 + 0xd0) * (float10)g_flMsToSeconds_Inferred);

}
