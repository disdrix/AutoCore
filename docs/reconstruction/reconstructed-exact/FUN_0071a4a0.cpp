// =============================================================================
// FUN_0071a4a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071a4a0
// Address:   0x0071a4a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071a4a0 @ 0x0071a4a0
// Stable ID: aa_0071a4a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~180 non-empty decompiler lines.
//  - Control keywords: if×19, for×2, return×1.
//  - Notable callees: FUN_00768760×8, FUN_00435df0×6, FUN_00437050×3, CONCAT31, FUN_0043d4a0, FUN_0044e8c0, FUN_00469910, FUN_00469c80.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Type propagation algorithm not settling */



uint32_t /* width from decompiler */ __thiscall FUN_0071a4a0(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint unaff_EBP;

  void *unaff_EDI;

  uint32_t /* width from decompiler */ *puVar6;

  void *pvVar7;

  uint32_t /* width from decompiler */ auStack_40f0 [4];

  uint32_t /* width from decompiler */ uStack_40e0;

  uint16_t auStack_40dc [2];

  undefined **ppuStack_40d8;

  int aiStack_40d4 [3];

  uint8_t auStack_40c8 [8];

  undefined **local_40c0;

  int *local_40bc;

  int local_40b8;

  int local_40b4;

  uint8_t local_40b0 [4];

  int local_40ac;

  uint32_t /* width from decompiler */ local_40a8;

  uint32_t /* width from decompiler */ local_40a4;

  uint32_t /* width from decompiler */ auStack_40a0 [13];

  int iStack_406c;

  int iStack_4068;

  int iStack_4064;

  uint32_t /* width from decompiler */ auStack_4058 [4102];

  int iStack_40;

  int iStack_38;

  void *pvStack_24;

  uint8_t uStack_1c;

  uint32_t /* width from decompiler */ uStack_10;

  int *piStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b10a2;

  piStack_c = ExceptionList;

  uStack_10 = 0x71a4bf;

  local_40b8 = (param_4 - param_1) + -4;

  local_40c0 = &PTR_FUN_00aa6034;

  local_40bc = param_2;

  local_40b0[0] = 1;

  local_40a8 = 0;

  local_40a4 = 0;

  local_4 = 0;

  ExceptionList = &piStack_c;

  local_40b4 = param_1;

  local_40ac = param_1;

  (**(code **)(*param_2 + 4))(param_1);

  FUN_0076a150(auStack_40c8);

  piStack_c = (int *)CONCAT31(piStack_c._1_3_,1);

  piVar1 = param_2 + 0xb;

  if (iStack_38 == 0) {

    FUN_00437050(piVar1);

  }

  else {

    FUN_00768760(piVar1);

  }

  if (iStack_38 == 0) {

    FUN_00437050(&stack0xffffbf08);

  }

  else {

    FUN_00768760(&stack0xffffbf08);

  }

  if (iStack_38 == 0) {

    FUN_00437050(auStack_40f0);

  }

  else {

    FUN_00768760(auStack_40f0);

  }

  pvVar3 = operator_new__(unaff_EBP);

  iVar4 = (**(code **)(*param_2 + 4))(*piVar1,0);

  if (((iVar4 == 0) && (iVar4 = (**(code **)(*param_2 + 0x14))(unaff_EDI,unaff_EBP), iVar4 == 0)) &&

     (iVar4 = (**(code **)(*param_2 + 0x30))(), iVar4 == *piVar1 + unaff_EBP)) {

    uStack_40e0 = 0;

    ppuStack_40d8 = (undefined **)param_2;

    pvVar7 = pvVar3;

    for (; pvVar3 != (void *)0x0; pvVar3 = (void *)((int)pvVar3 + -1)) {

      if (iStack_40 == 0) {

        if ((iStack_406c + 4 <= iStack_4064) ||

           ((iVar4 = FUN_00435df0(iStack_4068 + iStack_406c), -1 < iVar4 && (3 < iStack_4064)))) {

          auStack_40f0[0] = *(uint32_t /* width from decompiler */ *)((int)auStack_4058 + iStack_406c);

          iStack_406c = iStack_406c + 4;

        }

      }

      else {

        FUN_00768760(auStack_40f0);

      }

      if (iStack_40 == 0) {

        if ((iStack_406c + 4 <= iStack_4064) ||

           ((iVar4 = FUN_00435df0(iStack_4068 + iStack_406c), -1 < iVar4 && (3 < iStack_4064)))) {

          auStack_40f0[1] = *(uint32_t /* width from decompiler */ *)((int)auStack_4058 + iStack_406c);

          iStack_406c = iStack_406c + 4;

        }

      }

      else {

        FUN_00768760(auStack_40f0 + 1);

      }

      if (iStack_40 == 0) {

        if ((iStack_406c + 4 <= iStack_4064) ||

           ((iVar4 = FUN_00435df0(iStack_4068 + iStack_406c), -1 < iVar4 && (3 < iStack_4064)))) {

          auStack_40f0[2] = *(uint32_t /* width from decompiler */ *)((int)auStack_4058 + iStack_406c);

          iStack_406c = iStack_406c + 4;

        }

      }

      else {

        FUN_00768760(auStack_40f0 + 2);

      }

      if (iStack_40 == 0) {

        if ((iStack_406c + 4 <= iStack_4064) ||

           ((iVar4 = FUN_00435df0(iStack_4068 + iStack_406c), -1 < iVar4 && (3 < iStack_4064)))) {

          pvVar7 = *(void **)((int)auStack_4058 + iStack_406c);

          iStack_406c = iStack_406c + 4;

        }

      }

      else {

        FUN_00768760(&stack0xffffbf08);

      }

      if (iStack_40 == 0) {

        if ((iStack_406c + 2 <= iStack_4064) ||

           ((iVar4 = FUN_00435df0(iStack_4068 + iStack_406c), -1 < iVar4 && (1 < iStack_4064)))) {

          auStack_40dc[0] = *(uint16_t *)((int)auStack_4058 + iStack_406c);

          iStack_406c = iStack_406c + 2;

        }

      }

      else {

        FUN_00768c60(auStack_40dc);

      }

      if (iStack_40 == 0) {

        if ((iStack_406c + 4 <= iStack_4064) ||

           ((iVar4 = FUN_00435df0(iStack_4068 + iStack_406c), -1 < iVar4 && (3 < iStack_4064)))) {

          auStack_40f0[3] = *(uint32_t /* width from decompiler */ *)((int)auStack_4058 + iStack_406c);

          iStack_406c = iStack_406c + 4;

        }

      }

      else {

        FUN_00768760(auStack_40f0 + 3);

      }

      if (pvVar7 == (void *)0xffffffff) {

        uStack_40e0 = DAT_00d1f03c;

        FUN_00469c80();

      }

      else {

        puVar5 = (uint32_t /* width from decompiler */ *)FUN_00989e00(local_40b0,(int)pvVar7 + (int)unaff_EDI);

        uVar2 = *puVar5;

        iVar4 = *(int *)(puStack_8 + 8);

        uStack_40e0 = uVar2;

        FUN_0044e8c0(aiStack_40d4);

        param_2 = piStack_c;

        if (aiStack_40d4[0] == iVar4) {

          local_40a4 = uVar2;

          puVar5 = auStack_40f0;

          puVar6 = auStack_40a0;

          for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {

            *puVar6 = *puVar5;

            puVar5 = puVar5 + 1;

            puVar6 = puVar6 + 1;

          }

          FUN_00469910(&local_40ac,&local_40a4);

          param_2 = piStack_c;

        }

      }

    }

  }

  operator_delete__(unaff_EDI);

  (**(code **)(*param_2 + 4))(0,0);

  uStack_1c = 0;

  FUN_0043d4a0();

  ppuStack_40d8 = &PTR_FUN_00aa6034;

  if (local_40c0 != (undefined **)0x0) {

    operator_delete__(local_40c0);

  }

  ExceptionList = pvStack_24;

  return 0;

}
