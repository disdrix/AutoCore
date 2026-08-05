// =============================================================================
// FUN_006745a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006745a0
// Address:   0x006745a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006745a0 @ 0x006745a0
// Stable ID: aa_006745a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~146 non-empty decompiler lines.
//  - Control keywords: if×13, goto×5, return×4, while×2, do×1, switch×1.
//  - Notable callees: FUN_006745a0, FUN_00675700, FUN_00675930, FUN_006759b0, FUN_006762a0, FUN_006775d0, FUN_00677d40, FUN_00678020.
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

uint32_t /* width from decompiler */ __thiscall

FUN_006745a0(int param_1,uint32_t /* width from decompiler */ param_2,short param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,int *param_7)



{

  uint32_t /* width from decompiler */ *puVar1;

  ushort uVar2;

  int *piVar3;

  int iVar4;

  void *pvVar5;

  int iVar6;

  int local_14;

  void *local_10;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009a93f2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  while ((*(int *)(param_1 + 0x128) != 0 &&

         (local_10 = (void *)(*(int *)(param_1 + 300) - *(int *)(param_1 + 0x128) >> 2),

         local_10 != (void *)0x0))) {

    pvVar5 = *(void **)(*(int *)(param_1 + 300) + -4);

    if (*(int *)(param_1 + 0x128) != 0) {

      local_10 = (void *)(*(int *)(param_1 + 300) - *(int *)(param_1 + 0x128) >> 2);

      if (local_10 != (void *)0x0) {

        *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + -4;

      }

    }

    if (pvVar5 != (void *)0x0) {

      FUN_006793f0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar5);

    }

  }

  FUN_00675930(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x144) + 4));

  *(int *)(*(int *)(param_1 + 0x144) + 4) = *(int *)(param_1 + 0x144);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x148) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x144) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x144);

  *(int *)(*(int *)(param_1 + 0x144) + 8) = *(int *)(param_1 + 0x144);

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x138);

  pvVar5 = (void *)*puVar1;

  *puVar1 = puVar1;

  *(int *)(*(int *)(param_1 + 0x138) + 4) = *(int *)(param_1 + 0x138);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x13c) = 0;

  if (pvVar5 != *(void **)(param_1 + 0x138)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar5);

  }

  local_14 = 0;

  if (*(int *)(param_1 + 0xa8) != 0) {

    do {

      pvVar5 = (void *)0x0;

      switch(param_6) {

      case 0:

        local_10 = operator_new(0x30);

        local_4 = 0;

        if (local_10 == (void *)0x0) {

LAB_00674790:

          piVar3 = (int *)0x0;

        }

        else {

          piVar3 = (int *)FUN_00678b90(1);

        }

        break;

      case 1:

        local_10 = operator_new(0x98);

        local_4 = 1;

        if (local_10 == (void *)0x0) goto LAB_00674790;

        piVar3 = (int *)FUN_006775d0(1);

        break;

      case 2:

        local_10 = operator_new(0x98);

        local_4 = 2;

        if (local_10 == (void *)0x0) goto LAB_00674790;

        piVar3 = (int *)FUN_00678520(1);

        break;

      case 3:

        local_10 = operator_new(0xdc);

        local_4 = 3;

        if (local_10 == (void *)0x0) goto LAB_00674790;

        piVar3 = (int *)FUN_00678020(1);

        break;

      case 4:

        local_10 = operator_new(0x88);

        local_4 = 4;

        if (local_10 == (void *)0x0) goto LAB_00674790;

        piVar3 = (int *)FUN_00677d40(1);

        break;

      default:

        goto switchD_006746bd_default;

      }

      local_4 = 0xffffffff;

      iVar4 = (**(code **)(*piVar3 + 4))(param_4,param_5,1);

      if (iVar4 < 0) {

switchD_006746bd_default:

        ExceptionList = local_c;

        return 0xffffffff;

      }

      puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x94);

      *puVar1 = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0) = 0;

      *(uint16_t *)(param_1 + 0xa4) = 0;

      *(uint16_t *)(param_1 + 0xa4) = 0x12;

      *(uint16_t *)puVar1 = 1;

      iVar4 = piVar3[7];

      *(int *)(param_1 + 0x98) = iVar4;

      iVar6 = piVar3[8];

      *(ushort *)(param_1 + 0xa2) = (ushort)iVar6;

      *(short *)(param_1 + 0x96) = param_3;

      uVar2 = ((ushort)iVar6 >> 3) * param_3;

      *(ushort *)(param_1 + 0xa0) = uVar2;

      *(uint *)(param_1 + 0x9c) = (uint)uVar2 * iVar4;

      *param_7 = piVar3[8];

      local_10 = operator_new(0x98);

      local_4 = 5;

      if (local_10 != (void *)0x0) {

        pvVar5 = (void *)FUN_00678d20(local_14);

      }

      local_4 = 0xffffffff;

      local_10 = pvVar5;

      FUN_00678dc0(puVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0xb0),piVar3,*(uint32_t /* width from decompiler */ *)(param_1 + 0x158));

      iVar4 = *(int *)(param_1 + 0x128);

      if ((iVar4 == 0) ||

         ((uint)(*(int *)(param_1 + 0x130) - iVar4 >> 2) <=

          (uint)(*(int *)(param_1 + 300) - iVar4 >> 2))) {

        FUN_006762a0(*(uint32_t /* width from decompiler */ *)(param_1 + 300),1,&local_10);

      }

      else {

        piVar3 = *(int **)(param_1 + 300);

        *piVar3 = (int)pvVar5;

        *(int **)(param_1 + 300) = piVar3 + 1;

      }

      iVar4 = *(int *)(param_1 + 0x138);

      iVar6 = FUN_006759b0(iVar4,*(uint32_t /* width from decompiler */ *)(iVar4 + 4),&local_10);

      FUN_00675700(1);

      *(int *)(iVar4 + 4) = iVar6;

      local_14 = local_14 + 1;

      **(int **)(iVar6 + 4) = iVar6;

    } while (local_14 != *(int *)(param_1 + 0xa8));

  }

  ExceptionList = local_c;

  return 0;

}
