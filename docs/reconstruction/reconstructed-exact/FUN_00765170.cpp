// =============================================================================
// FUN_00765170
// -----------------------------------------------------------------------------
// Stable ID: aa_00765170
// Address:   0x00765170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00765170 @ 0x00765170
// Stable ID: aa_00765170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~176 non-empty decompiler lines.
//  - Control keywords: if×17, do×2, while×2, for×1, return×1.
//  - Notable callees: FUN_00412d40×2, FUN_004376e0×2, FUN_00989e00×2, FUN_00416160, FUN_00456960, FUN_007647c0, FUN_00765170, FUN_0076f970.
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

uint32_t /* width from decompiler */ __thiscall FUN_00765170(int *param_1,int *param_2,char param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int *piVar6;

  int iVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int iStack_cc;

  int local_c8;

  int *local_c4;

  void *local_c0;

  int *piStack_bc;

  int *piStack_b8;

  int iStack_b4;

  uint32_t /* width from decompiler */ uStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  uint32_t /* width from decompiler */ uStack_a8;

  float fStack_a4;

  uint32_t /* width from decompiler */ auStack_a0 [16];

  uint8_t auStack_60 [68];

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009b27a6;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  local_c4 = param_1;

  FUN_00989e00(&local_c8,PTR_s_palStaticGeometry_00afa2e8);

  iVar2 = FUN_0096aa20(local_c8);

  if (iVar2 == -1) {

    if (param_1[0x29] == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = param_1[0x2a] - param_1[0x29] >> 2;

    }

    FUN_0096b150(param_1 + 0x26,iVar2 + 1);

    iVar2 = *(int *)(param_1[0x29] + iVar2 * 4);

    iVar7 = *(int *)(iVar2 + 0xf4);

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00989e00(&local_c0,PTR_s_palStaticGeometry_00afa2e8);

    *(uint32_t /* width from decompiler */ *)(iVar7 + 8) = *puVar3;

    uVar4 = (**(code **)(*param_1 + 0xc))();

    FUN_00416160(uVar4);

  }

  else {

    iVar2 = *(int *)(param_1[0x29] + iVar2 * 4);

  }

  (**(code **)(*param_2 + 0x34))();

  iStack_b4 = iVar2 + 0x30;

  if ((*(uint *)(iVar2 + 0xec) >> 1 & 1) == 0) {

    puVar3 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x70);

  }

  else {

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_009730e0();

  }

  piVar6 = local_c4;

  puVar9 = auStack_a0;

  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar9 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar9 = puVar9 + 1;

  }

  if ((local_c4[0x25] == 0) && ((int *)param_2[0x25] != (int *)0x0)) {

    piVar5 = (int *)(**(code **)(*(int *)param_2[0x25] + 0x48))(local_c4);

    piVar6[0x25] = (int)piVar5;

    (**(code **)(*piVar5 + 0x40))(&fStack_a4,iVar2,iStack_cc);

  }

  piVar6 = (int *)piVar6[0x25];

  if ((piVar6 == (int *)0x0) ||

     (cVar1 = (**(code **)(*piVar6 + 0x38))(param_2,auStack_a0,iVar2,local_c8), cVar1 == '\0')) {

    piStack_bc = (int *)param_2[0x31];

    piVar6 = (int *)param_2[0x30];

    if (piVar6 != piStack_bc) {

      do {

        piVar5 = (int *)*piVar6;

        iVar2 = (**(code **)(*piVar5 + 4))();

        if (iVar2 == 0x47504345) {

          local_c0 = operator_new(0xc4);

          piVar8 = (int *)0x0;

          uStack_14 = 0;

          if (local_c0 != (void *)0x0) {

            piVar8 = (int *)FUN_004376e0(local_c0,piVar5);

          }

          uStack_14 = 0xffffffff;

          if (((piVar5[0x16] != 0) && (piVar5[0x17] != 0)) &&

             (*(int *)(piVar5[0x17] + 0x1c) != piVar5[0x18])) {

            (**(code **)(*piVar5 + 0x80))();

          }

          iVar2 = piVar5[0x19];

          if ((*(byte *)(iVar2 + 0xbc) & 1) != 0) {

            iVar2 = FUN_00972e50();

          }

          iVar7 = *piVar8;

          uVar4 = FUN_00412d40(auStack_60,iVar2,auStack_a0);

          (**(code **)(iVar7 + 0x4c))(uVar4);

          piVar8[0x16] = iStack_cc;

          FUN_007647c0(piVar8);

          piVar8[0x19] = (int)piStack_b8;

          if (param_3 == '\0') {

            (**(code **)(*piVar8 + 0x68))();

          }

          else {

            (**(code **)(*piVar8 + 100))();

          }

        }

        piVar6 = piVar6 + 1;

      } while (piVar6 != piStack_bc);

    }

    piVar6 = (int *)param_2[0x34];

    piVar5 = (int *)param_2[0x35];

    piStack_bc = piVar5;

    piStack_b8 = piVar6;

    if (piVar6 != piVar5) {

      do {

        piVar8 = (int *)*piVar6;

        piStack_b8 = piVar6;

        iVar2 = (**(code **)(*piVar8 + 4))();

        if (iVar2 == 0x47504345) {

          local_c0 = operator_new(0xc4);

          uStack_14 = 1;

          if (local_c0 == (void *)0x0) {

            piVar6 = (int *)0x0;

          }

          else {

            piVar6 = (int *)FUN_004376e0(local_c0,piVar8);

          }

          uStack_14 = 0xffffffff;

          if (((piVar8[0x16] != 0) && (piVar8[0x17] != 0)) &&

             (*(int *)(piVar8[0x17] + 0x1c) != piVar8[0x18])) {

            (**(code **)(*piVar8 + 0x80))();

          }

          iVar2 = piVar8[0x19];

          if ((*(byte *)(iVar2 + 0xbc) & 1) != 0) {

            uStack_b0 = 0;

            uStack_ac = 0;

            uStack_a8 = 0;

            fStack_a4 = g_flOne;

            FUN_0076f970(iVar2,&uStack_b0,iVar2 + 0x9c,iVar2 + 0x80,iVar2 + 0x90);

            *(uint *)(iVar2 + 0xbc) = *(uint *)(iVar2 + 0xbc) & 0xfffffffe;

          }

          iVar7 = *piVar6;

          uVar4 = FUN_00412d40(auStack_60,iVar2,auStack_a0);

          (**(code **)(iVar7 + 0x4c))(uVar4);

          iVar7 = local_c8;

          piVar6[0x16] = iStack_cc;

          iVar2 = *(int *)(local_c8 + 0xd0);

          local_c4 = piVar6;

          if ((iVar2 == 0) ||

             ((uint)(*(int *)(local_c8 + 0xd8) - iVar2 >> 2) <=

              (uint)(*(int *)(local_c8 + 0xd4) - iVar2 >> 2))) {

            FUN_00456960(*(uint32_t /* width from decompiler */ *)(local_c8 + 0xd4));

          }

          else {

            puVar3 = *(uint32_t /* width from decompiler */ **)(local_c8 + 0xd4);

            *puVar3 = piVar6;

            *(uint32_t /* width from decompiler */ **)(local_c8 + 0xd4) = puVar3 + 1;

          }

          (**(code **)(*piVar6 + 0x20))(iVar7);

          piVar6[0x19] = iStack_b4;

          piVar5 = piStack_bc;

          piVar6 = piStack_b8;

        }

        piVar6 = piVar6 + 1;

        piStack_b8 = piVar6;

      } while (piVar6 != piVar5);

    }

  }

  (**(code **)(*local_c4 + 0x50))();

  ExceptionList = pvStack_1c;

  return 0;

}
