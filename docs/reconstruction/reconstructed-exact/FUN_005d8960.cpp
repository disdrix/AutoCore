// =============================================================================
// FUN_005d8960
// -----------------------------------------------------------------------------
// Stable ID: aa_005d8960
// Address:   0x005d8960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d8960 @ 0x005d8960
// Stable ID: aa_005d8960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005b3370, FUN_005d8960, FUN_00638060, FUN_006380a0, FUN_006381a0.
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

void __fastcall FUN_005d8960(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int unaff_EBP;

  

  piVar1 = (int *)(**(code **)(*DAT_00b05060 + 0x10))(4,0x11);

  if (piVar1 == (int *)0x0) {

    piVar1 = (int *)0x0;

  }

  else if (unaff_EBP == 0) {

    DAT_00d02c6c = DAT_00d02c6c + 1;

    *piVar1 = (int)&DAT_00d02c70;

  }

  else {

    iVar2 = FUN_00638060(unaff_EBP);

    iVar3 = FUN_006381a0(iVar2);

    *piVar1 = iVar3 + 0xc;

    FUN_006380a0(iVar3 + 0xc,unaff_EBP,iVar2 + 1);

  }

  if (*(uint *)(param_1 + 0x24) == (*(uint *)(param_1 + 0x28) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x20),4);

  }

  *(int **)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x24) * 4) = piVar1;

  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;

  return;

}
