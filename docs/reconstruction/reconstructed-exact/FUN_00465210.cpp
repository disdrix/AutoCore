// =============================================================================
// FUN_00465210
// -----------------------------------------------------------------------------
// Stable ID: aa_00465210
// Address:   0x00465210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00465210 @ 0x00465210
// Stable ID: aa_00465210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00465210, FUN_004653e0.
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

float10 __fastcall FUN_00465210(int param_1)



{

  uint32_t /* width from decompiler */ in_XMM0_Da;

  

  if ((*(char *)(param_1 + 0x1c8) != '\0') && (*(char *)(param_1 + 0x1d0) == '\0')) {

    FUN_004653e0();

    *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x200) = in_XMM0_Da;

    *(uint8_t *)(param_1 + 0x1d0) = 1;

  }

  return (float10)*(float *)(param_1 + 0x200);

}
