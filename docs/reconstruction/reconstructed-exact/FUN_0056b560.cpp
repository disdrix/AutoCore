// =============================================================================
// FUN_0056b560
// -----------------------------------------------------------------------------
// Stable ID: aa_0056b560
// Address:   0x0056b560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056b560 @ 0x0056b560
// Stable ID: aa_0056b560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0056b560.
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

float10 __fastcall FUN_0056b560(int param_1)



{

  return ((float10)((int)*(short *)(param_1 + 0x13a) + (int)*(short *)(param_1 + 0x138) +

                    (int)*(short *)(param_1 + 0x136) + (int)*(short *)(param_1 + 0x134) +

                    (int)*(short *)(param_1 + 0x132) + (int)*(short *)(param_1 + 0x130) +

                   (int)*(short *)(param_1 + 0x12e) + (int)*(short *)(param_1 + 300) +

                   (int)*(short *)(param_1 + 0x12a) + (int)*(short *)(param_1 + 0x128) +

                   (int)*(short *)(param_1 + 0x126) + (int)*(short *)(param_1 + 0x124)) *

         (float10)DAT_00a0f298) /

         ((float10)*(int *)(param_1 + 0xd0) * (float10)g_flMsToSeconds_Inferred);

}
