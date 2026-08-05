// =============================================================================
// FUN_00761a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00761a70
// Address:   0x00761a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00761a70 @ 0x00761a70
// Stable ID: aa_00761a70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004406e0, FUN_00760830, FUN_00761a70, FUN_007647c0.
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

void FUN_00761a70(int param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  uint in_EAX;

  

  if ((*(int *)(param_1 + 0xc) == 0) ||

     ((uint)((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28) <= in_EAX)) {

    FUN_00760830(in_EAX + 1);

  }

  FUN_004406e0();

  if (param_3 != '\0') {

    FUN_007647c0(param_2);

  }

  return;

}
