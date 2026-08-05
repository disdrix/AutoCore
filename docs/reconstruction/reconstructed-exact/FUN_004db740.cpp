// =============================================================================
// FUN_004db740
// -----------------------------------------------------------------------------
// Stable ID: aa_004db740
// Address:   0x004db740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004db740 @ 0x004db740
// Stable ID: aa_004db740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004db740, FUN_004e7a30, __RTDynamicCast.
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

void __thiscall FUN_004db740(int param_1,int param_2,uint8_t param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  

  piVar3 = operator_new(0x40);

  if (piVar3 == (int *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3[6] = 0;

    piVar3[5] = 0;

    piVar3[4] = 0;

  }

  piVar3[2] = *(int *)(param_2 + 0x160);

  piVar3[3] = *(int *)(param_2 + 0x164);

  piVar3[8] = param_4;

  piVar3[9] = param_5;

  *(uint8_t *)(piVar3 + 1) = param_3;

  iVar5 = *(int *)(param_1 + 0xe8f0);

  *(int *)(param_1 + 0xe8f0) = iVar5 + 1;

  *piVar3 = iVar5;

  iVar4 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                          &CVOGGraphicsBase::RTTI_Type_Descriptor,0);

  iVar2 = *(int *)(*(int *)(iVar4 + 4) + 4);

  iVar5 = *(int *)(iVar2 + 0x88 + iVar4);

  iVar1 = *(int *)(iVar2 + 0x8c + iVar4);

  piVar3[4] = *(int *)(iVar2 + 0x84 + iVar4);

  piVar3[5] = iVar5;

  piVar3[6] = iVar1;

  iVar5 = FUN_004e7a30(*piVar3,piVar3,0);

  if (iVar5 != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar3);

  }

  return;

}
