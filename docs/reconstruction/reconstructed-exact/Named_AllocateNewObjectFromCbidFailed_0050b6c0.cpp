// =============================================================================
// Named_AllocateNewObjectFromCbidFailed_0050b6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0050b6c0
// Address:   0x0050b6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_AllocateNewObjectFromCbidFailed_0050b6c0 @ 0x0050b6c0
// Stable ID: aa_0050b6c0
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, return×5.
//  - Notable callees: CVOGReaction_GiveItemByCbid, CVOGReaction_RandomUnitScalar, FUN_00509c70, Named_AllocateNewObjectFromCbidFailed_0050b6c0, FUN_007a4480.
//  - Strings: "allocatenewobjectfromcbid failed %d".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "allocatenewobjectfromcbid failed %d"
 * Domain alias of FUN_0050b6c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_AllocateNewObjectFromCbidFailed_0050b6c0(uint32_t /* width from decompiler */ param_1,int param_2,float param_3)



{

  ushort uVar1;

  int iVar2;

  int *piVar3;

  

  iVar2 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar2 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

  if (param_3 < (float)uVar1 * DAT_00aaa638) {

    return (int *)0x0;

  }

  if (param_2 == -1) {

    return (int *)0x0;

  }

  piVar3 = (int *)CVOGReaction_GiveItemByCbid(param_2);

  if (piVar3 == (int *)0x0) {

    FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",param_2);

    return (int *)0x0;

  }

  iVar2 = (**(code **)(*piVar3 + 8))(param_2,param_1,1);

  if ((-1 < iVar2) && (*(int *)(piVar3[0x2a] + 0x3c) != 0)) {

    FUN_00509c70(piVar3,(int)*(short *)(*(int *)(piVar3[0x2a] + 0x3c) + 0x3f0),0x80000000,1,0);

    return piVar3;

  }

  (**(code **)*piVar3)(1);

  return (int *)0x0;

}
