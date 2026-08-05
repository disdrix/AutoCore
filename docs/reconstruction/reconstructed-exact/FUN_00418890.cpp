// =============================================================================
// FUN_00418890
// -----------------------------------------------------------------------------
// Stable ID: aa_00418890
// Address:   0x00418890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00418890 @ 0x00418890
// Stable ID: aa_00418890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00418890, FUN_00418c70.
//  - Return sites: 2.

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

void __thiscall FUN_00418890(int param_1,int *param_2,int *param_3)



{

  int iVar1;

  

  iVar1 = FUN_00418c70(param_3);

  if ((iVar1 != *(int *)(param_1 + 4)) && (*(int *)(iVar1 + 0xc) <= *param_3)) {

    *param_2 = iVar1;

    return;

  }

  *param_2 = *(int *)(param_1 + 4);

  return;

}
