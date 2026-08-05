// =============================================================================
// FUN_006511b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006511b0
// Address:   0x006511b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006511b0 @ 0x006511b0
// Stable ID: aa_006511b0
// Embedded strings (evidence for future rename):
//   - "MiNumJacobians"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~187 non-empty decompiler lines.
//  - Control keywords: if×13, while×3, for×3, do×2, return×2.
//  - Notable callees: FUN_006511b0, FUN_006c1120.
//  - Strings: "MiNumJacobians".
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

void FUN_006511b0(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,

                 uint8_t *param_5,int *param_6,int param_7,int *param_8,int param_9)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int iVar4;

  uint8_t *puVar5;

  int iVar6;

  uint8_t *puVar7;

  int iVar8;

  uint8_t *puVar9;

  uint uVar10;

  uint8_t *puVar11;

  int *piVar12;

  uint8_t *local_24;

  uint8_t *puStack_20;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ *puStack_14;

  uint8_t *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ *puStack_8;

  uint8_t *puStack_4;

  

  iVar4 = (int)param_5;

  iVar8 = *(int *)((int)param_5 + 0x18) * 4 + 8;

  local_24 = (uint8_t *)0x0;

  local_10 = (uint8_t *)0x0;

  puVar5 = (uint8_t *)(**(code **)(*DAT_00d039dc + 4))();

  puStack_4 = puVar5;

  iVar6 = (**(code **)(*DAT_00d039dc + 0xc))();

  puVar9 = puVar5 + iVar6;

  do {

    puStack_18 = puVar5 + *(int *)((int)param_5 + 0x14) + 0x90;

    puStack_c = puStack_18 + *(int *)((int)param_5 + 0xc);

    puStack_20 = puStack_c;

    while( true ) {

      piVar1 = DAT_00b05060;

      iVar6 = *(int *)((int)param_5 + 0x10);

      puStack_8 = (uint32_t /* width from decompiler */ *)(puStack_c + iVar8);

      puVar7 = (uint8_t *)((int)puStack_8 + iVar6 + 4);

      if (puVar7 <= puVar9) {

        *puVar5 = 2;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x3c) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x38) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x34) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x30) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x1c) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x18) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x14) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x10) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x2c) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x28) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x24) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x20) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x4c) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x48) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x44) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x40) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x5c) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x58) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x54) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x50) = 0;

        piVar1 = param_6 + param_7;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x6c) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x68) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 100) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x60) = 0;

        puVar7 = puVar5 + 0x80;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x7c) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x78) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x74) = 0;

        *(uint32_t /* width from decompiler */ *)(puVar5 + 0x70) = 0;

        puStack_4 = puVar7;

        for (piVar12 = param_6; piVar12 < piVar1; piVar12 = piVar12 + 1) {

          piVar3 = *(int **)(*piVar12 + 0x3c);

          if (piVar3[2] != (int)puVar7 - (int)puVar5) {

            piVar3[2] = (int)puVar7 - (int)puVar5;

          }

          puVar7 = (uint8_t *)(**(code **)(*piVar3 + 0xc))(param_1,param_4,puVar7);

        }

        *puVar7 = 3;

        piVar12 = param_8 + param_9;

        param_5 = puStack_20;

        puStack_14 = puStack_8;

        for (; param_8 < piVar12; param_8 = param_8 + 1) {

          iVar8 = *(int *)(*(int *)(*param_8 + 0x10) + 0x3c);

          *param_3 = puVar5 + *(int *)(*(int *)(*(int *)(*param_8 + 0xc) + 0x3c) + 8);

          param_3[1] = puVar5 + *(int *)(iVar8 + 8);

          if (param_5 <= puStack_18) {

            param_5 = (uint8_t *)0xffffffff;

            puStack_18 = local_10;

          }

          (**(code **)(*(int *)*param_8 + 0x24))(param_3,&puStack_18);

        }

        iVar8 = 0;

        *puStack_14 = 0x400;

        if (0 < *(int *)(iVar4 + 0x18)) {

          do {

            *(uint32_t /* width from decompiler */ *)(puStack_c + iVar8 * 4) = 0;

            iVar8 = iVar8 + 1;

          } while (iVar8 < *(int *)(iVar4 + 0x18));

        }

        iVar8 = FUN_006c1120(param_2,puStack_8,puVar5,puStack_c);

        if (DAT_00bc5644 < DAT_00bc5648) {

          *DAT_00bc5644 = "MiNumJacobians";

          DAT_00bc5644[1] = (float)*(int *)(iVar4 + 0x18);

          DAT_00bc5644 = DAT_00bc5644 + 2;

        }

        if (iVar8 == 1) {

          uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20);

          puVar5 = puStack_4;

          for (; param_6 < piVar1; param_6 = param_6 + 1) {

            puVar5 = (uint8_t *)

                     (**(code **)(**(int **)(*param_6 + 0x3c) + 0x10))(param_1,uVar2,puVar5);

          }

        }

        (**(code **)(*DAT_00d039dc + 8))();

        piVar1 = DAT_00b05060;

        if (local_24 != (uint8_t *)0x0) {

          uVar10 = (uint)(puVar9 + (0xf - (int)local_24)) & 0xfffffff0;

          if ((uVar10 != 0) &&

             ((local_24 == (uint8_t *)DAT_00b05060[5] ||

              ((uint8_t *)DAT_00b05060[5] == (uint8_t *)0x0)))) {

            (**(code **)(*DAT_00b05060 + 0x28))(local_24,uVar10);

            return;

          }

          DAT_00b05060[2] = DAT_00b05060[2] - uVar10;

          piVar1[3] = piVar1[3] + uVar10;

        }

        return;

      }

      if (puVar9 <= puStack_18) break;

      if (puStack_20 < puVar9) {

        iVar6 = iVar6 + 4 + iVar8;

        piVar12 = DAT_00b05060 + 3;

        uVar10 = iVar6 + 0xfU & 0xfffffff0;

        if (*piVar12 < (int)uVar10) {

          puStack_c = (uint8_t *)(**(code **)(*DAT_00b05060 + 0x24))(uVar10);

          puVar9 = puStack_c + iVar6;

          local_24 = puStack_c;

        }

        else {

          puStack_c = (uint8_t *)DAT_00b05060[2];

          DAT_00b05060[2] = (int)(puStack_c + uVar10);

          piVar1[3] = *piVar12 - uVar10;

          puVar9 = puStack_c + iVar6;

          local_24 = puStack_c;

        }

      }

      else {

        puVar11 = puStack_18 +

                  (*(int *)((int)param_5 + 8) * 2 - (int)puVar9) + *(int *)((int)param_5 + 0xc);

        puVar7 = puVar11 + iVar8 + iVar6 + 4;

        piVar12 = DAT_00b05060 + 3;

        uVar10 = (uint)(puVar7 + 0xf) & 0xfffffff0;

        if (*piVar12 < (int)uVar10) {

          puStack_c = puVar7;

          local_10 = (uint8_t *)(**(code **)(*DAT_00b05060 + 0x24))(uVar10);

        }

        else {

          local_10 = (uint8_t *)DAT_00b05060[2];

          DAT_00b05060[2] = (int)(local_10 + uVar10);

          piVar1[3] = *piVar12 - uVar10;

        }

        puStack_20 = puVar9 + -*(int *)((int)param_5 + 8);

        puVar9 = local_10 + (int)puVar7;

        puStack_c = local_10 + (int)puVar11;

        local_24 = local_10;

      }

    }

    iVar6 = (int)puVar7 - (int)puStack_4;

    piVar12 = DAT_00b05060 + 3;

    uVar10 = iVar6 + 0xfU & 0xfffffff0;

    if (*piVar12 < (int)uVar10) {

      puVar5 = (uint8_t *)(**(code **)(*DAT_00b05060 + 0x24))(uVar10);

      puVar9 = puVar5 + iVar6;

      local_24 = puVar5;

    }

    else {

      puVar5 = (uint8_t *)DAT_00b05060[2];

      DAT_00b05060[2] = (int)(puVar5 + uVar10);

      piVar1[3] = *piVar12 - uVar10;

      puVar9 = puVar5 + iVar6;

      local_24 = puVar5;

    }

  } while( true );

}
