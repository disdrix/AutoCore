// =============================================================================
// FUN_00519d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00519d80
// Address:   0x00519d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00519d80 @ 0x00519d80
// Stable ID: aa_00519d80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×16, return×2, goto×1.
//  - Notable callees: Object_ResolveFromTFID×2, CONCAT13, CVOGHBBase_Start, CVOGHBList_Enqueue, CVOGReaction_RandomUnitScalar, FUN_004bcda0, FUN_004cdc80, FUN_004d2700.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __fastcall FUN_00519d80(int *param_1)



{

  ushort uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char cVar4;

  int *piVar5;

  int iVar6;

  void *pvVar7;

  CVOGHBBase *pAction;

  int iVar8;

  uint3 unaff_EBX;

  uint unaff_ESI;

  int unaff_retaddr;

  void *pvVar9;

  void *pvStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  void *pvStack_4;

  

  pvStack_4 = (void *)0xffffffff;

  puStack_8 = &LAB_009a36ba;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  piVar5 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x10));

  iVar6 = (**(code **)(*param_1 + 0x210))(0);

  if ((iVar6 != 0) && ((int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) != piVar5)) {

    FUN_004cdc80(piVar5,param_1);

  }

  pvVar9 = (void *)CONCAT13(1,unaff_EBX);

  if (((param_1[10] & param_1[0xb]) != 0xffffffff) && (unaff_retaddr != 0)) {

    FUN_004d2700(piVar5,0,param_1[10],param_1[0xb]);

    pvVar7 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x58));

    if (pvVar7 == (void *)0x0) {

      pvVar9 = (void *)(uint)unaff_EBX;

    }

  }

  param_1[7] = DAT_00b0421c;

  if ((void *)param_1[5] != (void *)0x0) {

    NetObject_SetMaskBits((void *)param_1[5],8,0);

  }

  if (piVar5 != (int *)0x0) {

    cVar4 = (**(code **)(*piVar5 + 0x228))();

    if (cVar4 != '\0') {

      piVar5 = (int *)(**(code **)(*piVar5 + 0x224))();

      if (piVar5 != (int *)0x0) {

        (**(code **)(*piVar5 + 0x54))(param_1);

      }

    }

  }

  if (*(char *)((int)param_1 + 0x23) != '\0') {

    FUN_004e2600();

    (**(code **)(_DAT_00000000 + 0x54))(param_1);

  }

  (**(code **)(*param_1 + 0x40))(1);

  if (param_1[0x19] != 0) {

    FUN_005b2ba0();

  }

  cVar4 = (**(code **)(*param_1 + 0x198))();

  if (((cVar4 == '\0') || ((char)param_1[0x5a] == '\0')) &&

     ((*(int *)(param_1[0x2a] + 0x38) == 3 || (*(int *)(param_1[0x2a] + 0x38) == 1)))) {

    if (((uint)param_1[0x5f] >> 0xc & 1) == 0) {

      if ((char)param_1[0x5a] != '\0') goto LAB_0051a013;

      (**(code **)(*param_1 + 0x2a8))(*(uint32_t /* width from decompiler */ *)(param_1[0x29] + 0xe4e8));

      uVar3 = 1;

    }

    else {

      if (*(char *)(param_1[0x29] + 0x7e) != '\0') {

        iVar6 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar6 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

        }

        uVar1 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

        pvStack_4 = (void *)((float)uVar1 * _DAT_009cec58);

        pvVar9 = (void *)(int)ROUND((float)pvStack_4);

        pvStack_4 = operator_new(0x24);

        pvStack_c = (void *)0x0;

        if (pvStack_4 == (void *)0x0) {

          pAction = (CVOGHBBase *)0x0;

        }

        else {

          pAction = (CVOGHBBase *)FUN_005dabc0();

        }

        pvStack_c = (void *)0xffffffff;

        CVOGHBList_Enqueue(*(void **)(param_1[0x29] + 0xe4ec),pAction);

        CVOGHBBase_Start(pAction);

      }

      (**(code **)(*param_1 + 0x2a8))(*(uint32_t /* width from decompiler */ *)(param_1[0x29] + 0xe4e8));

      uVar3 = 0;

    }

    FUN_004e77d0(param_1[0x58],param_1[0x59],param_1,uVar3);

    *(byte *)((int)param_1 + 0x17d) = *(byte *)((int)param_1 + 0x17d) | 1;

    ExceptionList = pvVar9;

    return 0;

  }

LAB_0051a013:

  *(byte *)((int)param_1 + 0x17d) = *(byte *)((int)param_1 + 0x17d) | 1;

  iVar6 = param_1[0x58];

  iVar2 = param_1[0x59];

  iVar8 = FUN_004e23d0();

  if ((iVar8 != 0) && (*(int *)(iVar8 + 0xc) != 0)) {

    FUN_007a4480(1,

                 "##$$##$$##$$##$$##ONDeath Object CBID:%i, Geo:%s, COID:%I64d, Global?:%i, Position: %.02f, %.02f, %.02f being added to delete cue, but still in InactiveObjectsHas.\n"

                 ,*(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x34),*(int *)(param_1[0x2a] + 0x3c) + 0x10,iVar6,

                 iVar2,(char)param_1[0x5a],(double)(float)param_1[0x20],(double)(float)param_1[0x21]

                 ,(double)(float)param_1[0x22]);

    FUN_004bcda0();

  }

  ExceptionList = pvStack_14;

  return unaff_ESI >> 0x18;

}
