// =============================================================================
// Named_CalleeOf_Skill_ResolveTargetList_0054ff00
// -----------------------------------------------------------------------------
// Stable ID: aa_0054ff00
// Callee of Skill_ResolveTargetList
// Address:   0x0054ff00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_ResolveTargetList: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~149 non-empty decompiler lines.
//  - Control keywords: if×33, return×18, goto×5.
//  - Notable callees: FUN_0040aff0×3, FUN_005749d0×2, FUN_004bb0d0, FUN_005130e0, FUN_0054ff00, TFID_EqualsObjectId, TFID_NotEquals.
//  - Return sites: 18.

/*
 * Behavioral notes:
 * Callee of Skill_ResolveTargetList
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * __thiscall Named_CalleeOf_Skill_ResolveTargetList_0054ff00(int param_1,int *param_2,int *param_3,uint *param_4)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  void *pA;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint8_t *puVar7;

  uint32_t /* width from decompiler */ *pB;

  uint8_t auStack_10 [16];

  

  if (param_2 == (int *)0x0) {

    if (((*(byte *)(param_1 + 0x614) & 1) != 0) &&

       (((iVar6 = *(int *)(param_1 + 0x60c), iVar6 == 0 || (iVar6 == 1)) || (iVar6 == 0xb)))) {

      iVar6 = *param_3;

LAB_0055029f:

      iVar6 = (**(code **)(iVar6 + 0x19c))();

      if (iVar6 == 0) {

        return (int *)0x0;

      }

      return (int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6);

    }

    goto LAB_005502bd;

  }

  iVar6 = 0;

  iVar2 = (**(code **)(*param_3 + 0x214))();

  if (iVar2 != 0) {

    iVar6 = (**(code **)(*param_3 + 0x214))();

    iVar6 = *(int *)(iVar6 + 0x250);

  }

  iVar2 = *(int *)(param_2[0x2a] + 0x38);

  if ((*(byte *)(param_1 + 0x614) & 1) != 0) {

    if ((*(int *)(param_1 + 0x60c) == 0) || (*(int *)(param_1 + 0x60c) == 1)) {

      iVar6 = (**(code **)(*param_3 + 0x19c))();

      if (iVar6 == 0) {

        return param_3;

      }

      iVar6 = *param_3;

      goto LAB_0055029f;

    }

    goto LAB_005502bd;

  }

  cVar1 = (**(code **)(*param_2 + 0x198))();

  if ((cVar1 != '\0') && ((*(byte *)(param_1 + 0x615) & 4) == 0)) {

    *param_4 = *param_4 | 8;

    return (int *)0x0;

  }

  cVar1 = (**(code **)(*param_2 + 0x198))();

  if ((((cVar1 != '\0') && ((*(byte *)(param_1 + 0x615) & 4) != 0)) &&

      (iVar3 = (**(code **)(*param_2 + 0x1d4))(), iVar3 == 0)) &&

     ((*(byte *)(param_1 + 0x614) & 4) != 0)) goto LAB_005502bd;

  if ((*(byte *)(param_1 + 0x614) & 2) != 0) {

    if ((iVar6 != 0) && ((int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) == param_2)) {

      return param_2;

    }

    if (param_3 == param_2) {

      return param_2;

    }

    iVar3 = (**(code **)(*param_3 + 0x210))(0);

    if ((iVar3 != 0) && (iVar3 = (**(code **)(*param_2 + 0x210))(0), iVar3 != 0)) {

      iVar3 = (**(code **)(*param_2 + 0x210))(0);

      iVar4 = (**(code **)(*param_3 + 0x210))(0);

      if (iVar4 == iVar3) {

        return param_2;

      }

    }

  }

  if ((*(byte *)(param_1 + 0x614) & 0x80) != 0) {

    if (*(int *)(param_1 + 0x618) == -1) {

      cVar1 = FUN_005130e0(0);

      if ((cVar1 != '\0') && (((uint)param_2[0x5f] >> 10 & 1) == 0)) {

        return param_2;

      }

    }

    else if (*(int *)(param_1 + 0x618) == iVar2) {

      return param_2;

    }

  }

  if (((iVar2 != 0xe) && (iVar2 != 0x12)) && (iVar2 != 0x14)) {

    *param_4 = *param_4 | 0x10;

    return (int *)0x0;

  }

  if (((*(byte *)(param_1 + 0x614) & 4) != 0) &&

     (cVar1 = (**(code **)(*param_3 + 0x298))(param_2), cVar1 == '\0')) {

    if (iVar6 == 0) {

      if (param_3 != param_2) {

        return param_2;

      }

    }

    else if (((int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) != param_2) &&

            (param_3 != param_2)) {

      return param_2;

    }

  }

  if ((((*(byte *)(param_1 + 0x615) & 0x20) != 0) &&

      (iVar6 = (**(code **)(*param_3 + 0x1dc))(), iVar6 != 0)) &&

     (iVar6 = (**(code **)(*param_3 + 0x1dc))(), *(int *)(iVar6 + 0xcb0) != 0)) {

    iVar6 = (**(code **)(*param_2 + 0x214))();

    if (iVar6 != 0) {

      pB = &DAT_009d1ca8;

      puVar7 = auStack_10;

      (**(code **)(*param_2 + 0x214))(puVar7);

      pA = (void *)FUN_0040aff0(puVar7);

      iVar6 = TFID_NotEquals(pA,pB);

      if ((char)iVar6 != '\0') {

        puVar7 = auStack_10;

        (**(code **)(*param_2 + 0x214))(puVar7);

        uVar5 = FUN_0040aff0(puVar7);

        iVar6 = FUN_004bb0d0(uVar5);

        if (iVar6 != 0) {

          (**(code **)(*param_3 + 0x1dc))();

          cVar1 = FUN_005749d0(iVar6);

          if (cVar1 != '\0') {

            return param_2;

          }

        }

        goto LAB_005501c1;

      }

    }

    (**(code **)(*param_3 + 0x1dc))();

    uVar5 = (**(code **)(*param_2 + 0x210))(0);

    cVar1 = FUN_005749d0(uVar5);

    if (cVar1 != '\0') {

      return param_2;

    }

  }

LAB_005501c1:

  if (((*(byte *)(param_1 + 0x614) & 8) != 0) &&

     (cVar1 = (**(code **)(*param_3 + 0x298))(param_2), cVar1 != '\0')) {

    return param_2;

  }

  if (((*(byte *)(param_1 + 0x614) & 0x10) != 0) &&

     (iVar6 = (**(code **)(*param_2 + 0x214))(), iVar6 != 0)) {

    FUN_0040aff0(auStack_10);

    iVar6 = TFID_EqualsObjectId(auStack_10,param_3 + 0x58);

    if ((char)iVar6 != '\0') {

      return param_2;

    }

  }

  if ((((*(byte *)(param_1 + 0x615) & 4) != 0) &&

      (cVar1 = (**(code **)(*param_2 + 0x198))(), cVar1 != '\0')) &&

     (((uint)param_2[0x5f] >> 10 & 1) == 0)) {

    return param_2;

  }

LAB_005502bd:

  *param_4 = *param_4 | 4;

  return (int *)0x0;

}
