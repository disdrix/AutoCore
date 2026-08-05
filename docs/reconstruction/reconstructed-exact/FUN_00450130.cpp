// =============================================================================
// FUN_00450130
// -----------------------------------------------------------------------------
// Stable ID: aa_00450130
// Address:   0x00450130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00450130 @ 0x00450130
// Stable ID: aa_00450130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_0044ffa0, FUN_00450130, FUN_00987560.
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

void FUN_00450130(int param_1,int *param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (param_3 != param_4) {

    iVar1 = *(int *)(param_1 + 8);

    iVar2 = param_3;

    for (; param_4 != iVar1; param_4 = param_4 + 0x1c) {

      FUN_0044ffa0(iVar2,param_4);

      iVar2 = iVar2 + 0x1c;

    }

    iVar1 = *(int *)(param_1 + 8);

    for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x1c) {

      FUN_00987560();

    }

    *(int *)(param_1 + 8) = iVar2;

  }

  *param_2 = param_3;

  return;

}
