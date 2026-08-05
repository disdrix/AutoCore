// =============================================================================
// FUN_00622ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_00622ae0
// Address:   0x00622ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00622ae0 @ 0x00622ae0
// Stable ID: aa_00622ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0058a5d0, FUN_006224f0, FUN_00622ae0.
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

void __fastcall FUN_00622ae0(int param_1)



{

  if (((*(int *)(param_1 + 0x18) != 0) && (*(float *)(param_1 + 0x6c4) != g_flZero)) &&

     ((*(byte *)(param_1 + 0x648) & 0x40) != 0)) {

    FUN_0058a5d0(*(int *)(param_1 + 0x18),param_1 + 0x24,*(float *)(param_1 + 0x6c4) * DAT_00aaa668,

                 0x3f800000);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4) = 0;

  FUN_006224f0();

  return;

}
