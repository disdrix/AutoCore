// =============================================================================
// FUN_00774e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00774e60
// Address:   0x00774e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00774e60 @ 0x00774e60
// Stable ID: aa_00774e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×7, return×4.
//  - Notable callees: FUN_00770d10, FUN_00771300, FUN_00772ff0, FUN_00774210, FUN_00774e60.
//  - Return sites: 4.

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

void FUN_00774e60(int *param_1,int *param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  

  iVar1 = *param_2;

  iVar2 = *param_1;

  uVar3 = (uint)(param_1[2] != param_2[2]);

  iVar4 = iVar2;

  if (iVar1 <= iVar2) {

    iVar4 = iVar1;

  }

  if (DAT_00afa2b4 <= iVar4) {

    FUN_00774210(param_2,param_3);

    param_3[2] = (*param_3 < 1) - 1 & uVar3;

    return;

  }

  iVar4 = iVar2;

  if (iVar1 <= iVar2) {

    iVar4 = iVar1;

  }

  if (DAT_00afa2ac <= iVar4) {

    FUN_00772ff0(param_2,param_3);

    param_3[2] = (*param_3 < 1) - 1 & uVar3;

    return;

  }

  iVar4 = iVar1 + 1 + iVar2;

  if (iVar4 < 0x200) {

    if (iVar1 <= iVar2) {

      iVar2 = iVar1;

    }

    if (iVar2 < 0x101) {

      FUN_00770d10(param_1,param_3,iVar4);

      param_3[2] = (*param_3 < 1) - 1 & uVar3;

      return;

    }

  }

  FUN_00771300(param_1,param_2,param_3,iVar4);

  param_3[2] = (*param_3 < 1) - 1 & uVar3;

  return;

}
