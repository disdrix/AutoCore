// READABILITY (auto CF):
//  - Body size: ~290 non-empty decompiler lines.
//  - Control keywords: if×35, return×7, goto×7, while×4, do×2, for×1.
//  - Notable callees: FUN_007a4480×8, FUN_00411e10×2, FUN_00411e40×2, FUN_004158c0×2, FUN_00415ac0×2, FUN_00416ff0×2, FUN_00429310×2, FUN_00823790×2.
//  - Strings: "VOG_DEBUG_STOP"; "Duplicate hash insert %u, failing out".
//  - Return sites: 7.

// =============================================================================
// Named_VOG_DEBUG_STOP_0083c110
// -----------------------------------------------------------------------------
// Stable ID: aa_0083c110
// Address:   0x0083c110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_0083c110(int *param_1,uint param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  uint uVar7;

  int *piVar8;

  int iVar9;

  char *pcStack_48;

  int *piStack_44;

  char local_18;

  int iStack_8;

  int local_4;

  

  uVar7 = param_2;

  if (((param_1[0x130] == 0) || (param_2 == 0)) || (*(char *)(param_2 + 0xfe) != '\0')) {

    return 0;

  }

  if (param_1[0x14e] == 0) {

LAB_0083c475:

    if (param_1[0x14f] != 0) {

      piStack_44 = (int *)0x83c490;

      FUN_00411e10();

      piStack_44 = (int *)0x83c49f;

      piVar6 = (int *)FUN_00411e40();

      while (piVar6 != (int *)0x0) {

        if (piVar6[0x185] == *(int *)(uVar7 + 0x620)) {

          piVar8 = (int *)(uVar7 + 0x658);

          piVar1 = (int *)(uVar7 + 0x65c);

          puVar4 = (uint32_t /* width from decompiler */ *)(uVar7 + 0x660);

          local_4 = piVar6[0x189];

          uVar7 = param_2;

          if (((piVar6[0x186] == *piVar8) && (piVar6[0x187] == *piVar1)) &&

             (local_18 = (char)*puVar4, (char)piVar6[0x188] == local_18)) {

            *(uint8_t *)(param_1[0x14f] + 0x1d) = 0;

            piStack_44 = (int *)0x83c558;

            FUN_004158c0();

            iVar9 = param_1[0x14e];

            if (iVar9 == 0) goto LAB_0083c641;

            if (piVar6 == (int *)0x0) goto LAB_0083c764;

            if (*(char *)(iVar9 + 0x1d) != '\0') {

              piStack_44 = (int *)0xa64c18;

              pcStack_48 = (char *)0x0;

              FUN_007a4480();

              FUN_007a4480(0,"VOG_DEBUG_STOP");

            }

            uVar7 = param_2;

            piStack_44 = (int *)0x83c5a0;

            iVar3 = FUN_00415ac0();

            if (iVar3 != 0) goto LAB_0083c641;

            iVar3 = *(int *)(*(int *)(*(int *)(iVar9 + 0x10) + (*(uint *)(iVar9 + 8) & uVar7) * 4) +

                            4);

            if (iVar3 == 0) goto LAB_0083c5cc;

            goto LAB_0083c5c0;

          }

        }

        piStack_44 = (int *)0x83c513;

        piVar6 = (int *)FUN_00411e40();

      }

      *(uint8_t *)(param_1[0x14f] + 0x1d) = 0;

    }

    return 0;

  }

  iVar9 = 0;

  piStack_44 = (int *)0x83c156;

  FUN_00411e10();

  do {

    do {

      iVar3 = param_1[0x14e];

      if (*(char *)(iVar3 + 0x1d) == '\0') {

        piStack_44 = (int *)0xa27c9c;

        pcStack_48 = (char *)0x0;

        FUN_007a4480();

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar9 == 0) {

        iVar9 = *(int *)(iVar3 + 0x14);

      }

      else {

        iVar9 = *(int *)(iVar9 + 0x14);

      }

      if (iVar9 == 0) {

        piVar6 = (int *)0x0;

      }

      else {

        piVar6 = *(int **)(iVar9 + 8);

      }

      if (piVar6 == (int *)0x0) {

        *(uint8_t *)(param_1[0x14e] + 0x1d) = 0;

        goto LAB_0083c475;

      }

    } while (piVar6[0x185] != *(int *)(uVar7 + 0x620));

    piVar8 = (int *)(uVar7 + 0x658);

    piVar1 = (int *)(uVar7 + 0x65c);

    puVar4 = (uint32_t /* width from decompiler */ *)(uVar7 + 0x660);

    local_4 = piVar6[0x189];

    uVar7 = param_2;

  } while (((piVar6[0x186] != *piVar8) || (piVar6[0x187] != *piVar1)) ||

          (local_18 = (char)*puVar4, (char)piVar6[0x188] != local_18));

  *(uint8_t *)(param_1[0x14e] + 0x1d) = 0;

  piStack_44 = (int *)0x83c233;

  FUN_004158c0();

  iVar9 = param_1[0x14e];

  if (piVar6 != (int *)0x0) {

    if (*(char *)(iVar9 + 0x1d) != '\0') {

      piStack_44 = (int *)0xa64c18;

      pcStack_48 = (char *)0x0;

      FUN_007a4480();

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    uVar7 = param_2;

    piStack_44 = (int *)0x83c273;

    iVar3 = FUN_00415ac0();

    if (iVar3 == 0) {

      for (iVar3 = *(int *)(*(int *)(*(int *)(iVar9 + 0x10) + (*(uint *)(iVar9 + 8) & uVar7) * 4) +

                           4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {

        if (uVar7 == *(uint *)(iVar3 + 0x10)) {

          if ((iVar3 != 0) && (*(int *)(iVar3 + 8) != 0)) {

            piStack_44 = (int *)uVar7;

            pcStack_48 = "Duplicate hash insert %u, failing out";

            FUN_007a4480(0);

            return 1;

          }

          break;

        }

      }

      piStack_44 = (int *)0x83c2a4;

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00416ff0();

      puVar4[3] = 0;

      puVar4[5] = 0;

      puVar4[6] = 0;

      *(uint8_t *)(puVar4 + 1) = 0;

      *puVar4 = &PTR_LAB_00a6d5fc;

      puVar4[2] = piVar6;

      puVar4[4] = param_2;

      iVar3 = *(int *)(*(int *)(iVar9 + 0x10) + (*(uint *)(iVar9 + 8) & param_2) * 4);

      puVar4[3] = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

      *(uint32_t /* width from decompiler */ **)(iVar3 + 4) = puVar4;

      piStack_44 = (int *)0x83c2dd;

      FUN_00429310();

      uVar7 = param_2;

      if (*(int *)(iVar9 + 0x18) == 0) {

        *(uint32_t /* width from decompiler */ **)(iVar9 + 0x18) = puVar4;

        *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14) = puVar4;

        puVar4[6] = 0;

        puVar4[5] = 0;

      }

      else {

        *(uint32_t /* width from decompiler */ **)(*(int *)(iVar9 + 0x18) + 0x14) = puVar4;

        puVar4[5] = 0;

        puVar4[6] = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18);

        *(uint32_t /* width from decompiler */ **)(iVar9 + 0x18) = puVar4;

      }

      *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + 1;

      piStack_44 = (int *)0x83c33a;

      FUN_00823790();

      piStack_44 = (int *)(uVar7 + 50000);

      pcStack_48 = (char *)0x83c348;

      (**(code **)(*piVar6 + 0x74))();

      pcStack_48 = (char *)0x1;

      (**(code **)(*piVar6 + 0xd4))();

      (**(code **)(*piVar6 + 0xcc))(1);

      (**(code **)(*piVar6 + 0x34c))();

      if (piVar6[0x18b] != 0) {

        local_4 = -1;

        (**(code **)(*(int *)piVar6[0x18b] + 0x15c))(0,&local_4);

      }

      if (piVar6[0x18a] != 0) {

        iVar9 = *(int *)piVar6[0x18a];

        uVar5 = (**(code **)(*(int *)piVar6[0x18a] + 0x164))(2);

        (**(code **)(iVar9 + 0x154))(0,uVar5);

      }

      if (piVar6[0x18c] != 0) {

        iVar9 = (**(code **)(*(int *)piVar6[0x18c] + 0x164))(1);

        *(uint8_t *)(iVar9 + 3) = 0xff;

      }

      if (piVar6[0x18a] != 0) {

        iVar9 = (**(code **)(*(int *)piVar6[0x18a] + 0x164))(0);

        *(uint8_t *)(iVar9 + 3) = 0xff;

      }

      if ((DAT_00d1d8e0 != 0) && (*(int *)(DAT_00d1d8e0 + 0x514) == iStack_8)) {

        (**(code **)(*piVar6 + 0x120))(&stack0xffffffcc,1,1);

        puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar6 + 0x140))(&pcStack_48,1);

        FUN_007fd3d0(pcStack_48,piStack_44,*puVar4,puVar4[1]);

        return 1;

      }

    }

  }

  return 1;

  while (iVar3 = *(int *)(iVar3 + 0xc), iVar3 != 0) {

LAB_0083c5c0:

    if (uVar7 == *(uint *)(iVar3 + 0x10)) {

      if ((iVar3 != 0) && (*(int *)(iVar3 + 8) != 0)) {

        piStack_44 = (int *)uVar7;

        pcStack_48 = "Duplicate hash insert %u, failing out";

        FUN_007a4480(0);

LAB_0083c641:

        if (piVar6 != (int *)0x0) {

          piStack_44 = (int *)0x83c653;

          cVar2 = (**(code **)(*piVar6 + 0x3d8))();

          if (cVar2 != '\0') {

            piStack_44 = (int *)0x83c661;

            (**(code **)(*piVar6 + 0x440))();

          }

          pcStack_48 = (char *)0x83c670;

          piStack_44 = piVar6;

          (**(code **)(*param_1 + 0xbc))();

        }

        goto LAB_0083c764;

      }

      break;

    }

  }

LAB_0083c5cc:

  piStack_44 = (int *)0x83c5d4;

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_00416ff0();

  puVar4[3] = 0;

  puVar4[5] = 0;

  puVar4[6] = 0;

  *(uint8_t *)(puVar4 + 1) = 0;

  *puVar4 = &PTR_LAB_00a6d5fc;

  puVar4[2] = piVar6;

  puVar4[4] = param_2;

  iVar3 = *(int *)(*(int *)(iVar9 + 0x10) + (*(uint *)(iVar9 + 8) & param_2) * 4);

  puVar4[3] = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

  *(uint32_t /* width from decompiler */ **)(iVar3 + 4) = puVar4;

  piStack_44 = (int *)0x83c60d;

  FUN_00429310();

  uVar7 = param_2;

  if (*(int *)(iVar9 + 0x18) == 0) {

    *(uint32_t /* width from decompiler */ **)(iVar9 + 0x18) = puVar4;

    *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14) = puVar4;

    puVar4[6] = 0;

    puVar4[5] = 0;

  }

  else {

    *(uint32_t /* width from decompiler */ **)(*(int *)(iVar9 + 0x18) + 0x14) = puVar4;

    puVar4[5] = 0;

    puVar4[6] = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18);

    *(uint32_t /* width from decompiler */ **)(iVar9 + 0x18) = puVar4;

  }

  *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + 1;

  piStack_44 = (int *)0x83c692;

  FUN_00823790();

  piStack_44 = (int *)(uVar7 + 50000);

  pcStack_48 = (char *)0x83c6a0;

  (**(code **)(*piVar6 + 0x74))();

  pcStack_48 = (char *)0x1;

  (**(code **)(*piVar6 + 0xd4))();

  (**(code **)(*piVar6 + 0x104))();

  (**(code **)(*piVar6 + 0xcc))(1);

  (**(code **)(*piVar6 + 0x34c))();

  if (piVar6[0x18b] != 0) {

    param_2 = 0xffffffff;

    piStack_44 = (int *)&param_2;

    pcStack_48 = (char *)0x0;

    (**(code **)(*(int *)piVar6[0x18b] + 0x15c))();

  }

  if (piVar6[0x18a] != 0) {

    iVar9 = *(int *)piVar6[0x18a];

    piStack_44 = (int *)0x2;

    pcStack_48 = (char *)0x83c718;

    pcStack_48 = (char *)(**(code **)(*(int *)piVar6[0x18a] + 0x164))();

    (**(code **)(iVar9 + 0x154))(0);

  }

  if (piVar6[0x18c] != 0) {

    piStack_44 = (int *)0x1;

    pcStack_48 = (char *)0x83c73e;

    iVar9 = (**(code **)(*(int *)piVar6[0x18c] + 0x164))();

    *(uint8_t *)(iVar9 + 3) = 0xff;

  }

  if (piVar6[0x18a] != 0) {

    piStack_44 = (int *)0x0;

    pcStack_48 = (char *)0x83c75c;

    iVar9 = (**(code **)(*(int *)piVar6[0x18a] + 0x164))();

    *(uint8_t *)(iVar9 + 3) = 0xff;

  }

LAB_0083c764:

  if (param_1[0x12e] == 0) {

    return 1;

  }

  piStack_44 = (int *)0x83c77b;

  FUN_0092cc60();

  piStack_44 = (int *)0xc350;

  pcStack_48 = (char *)0x5;

  (**(code **)(*param_1 + 0x338))();

  return 1;

}
