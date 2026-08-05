// =============================================================================
// FUN_00655da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00655da0
// Address:   0x00655da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00655da0 @ 0x00655da0
// Stable ID: aa_00655da0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~163 non-empty decompiler lines.
//  - Control keywords: if×17, do×6, while×6, return×1.
//  - Notable callees: FUN_005b3300×2, FUN_00658800×2, FUN_00652e80, FUN_00655da0, FUN_00657d10.
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



void __thiscall FUN_00655da0(int param_1,int param_2)



{

  uint uVar1;

  uint8_t *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t *puVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  int iStack_8054;

  uint8_t *puStack_804c;

  int iStack_8048;

  uint8_t *puStack_8044;

  uint32_t /* width from decompiler */ uStack_8040;

  int iStack_803c;

  int iStack_8038;

  int iStack_8034;

  uint32_t /* width from decompiler */ *puStack_8030;

  int iStack_8028;

  int iStack_8024;

  uint8_t *local_8020;

  uint32_t /* width from decompiler */ local_801c;

  uint32_t /* width from decompiler */ local_8018;

  uint8_t local_8010 [32764];

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0x655db0;

  local_8020 = local_8010;

  local_801c = 0;

  local_8018 = 0x80000400;

  (**(code **)(**(int **)(param_2 + 0xc4) + 0x1c))(&local_8020);

  puVar6 = local_8020;

  puVar2 = local_8020;

  if (*(int *)(param_1 + 8) < (int)local_8020) {

    iVar3 = *(int *)(param_1 + 8);

    piVar7 = (int *)(param_1 + 4);

    puStack_804c = local_8020;

    iStack_8034 = iVar3;

    if ((int)local_8020 < iVar3) {

      iVar4 = (int)local_8020 << 7;

      iVar3 = iVar3 - (int)local_8020;

      do {

        (*(code *)**(uint32_t /* width from decompiler */ **)(*piVar7 + iVar4))(0);

        iVar4 = iVar4 + 0x80;

        iVar3 = iVar3 + -1;

        puVar2 = local_8020;

      } while (iVar3 != 0);

    }

    else {

      uVar1 = *(uint *)(param_1 + 0xc);

      if ((int)(uVar1 & 0x7fffffff) < (int)local_8020) {

        puVar2 = (uint8_t *)((uVar1 & 0x7fffffff) * 2);

        if ((int)puVar2 <= (int)local_8020) {

          puVar2 = local_8020;

        }

        puStack_8030 = (uint32_t /* width from decompiler */ *)*piVar7;

        *piVar7 = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0x80000000;

        if (0 < (int)puVar2) {

          FUN_005b3300(piVar7,((int)puVar2 < 0) - 1 & (uint)puVar2,0x80);

        }

        puVar2 = local_8020;

        if (0 < iVar3) {

          puVar8 = puStack_8030 + 0x1b;

          iStack_8038 = (int)puStack_8030 - *piVar7;

          puVar5 = (uint32_t /* width from decompiler */ *)(*piVar7 + 100);

          iStack_803c = iVar3;

          do {

            if (puVar5 != (uint32_t /* width from decompiler */ *)0x64) {

              FUN_00652e80(puVar8 + -0x1b);

              puVar5[-0x19] = &PTR_FUN_009e5c6c;

              puVar5[-1] = puVar8[-3];

              *puVar5 = *(uint32_t /* width from decompiler */ *)(iStack_8038 + (int)puVar5);

              puVar5[1] = puVar8[-1];

              puVar5[2] = *puVar8;

              puVar5[3] = puVar8[1];

              puVar5[4] = puVar8[2];

              puVar5[5] = puVar8[3];

              puVar5[6] = puVar8[4];

              puVar2 = local_8020;

              iVar3 = iStack_8034;

            }

            puVar5 = puVar5 + 0x20;

            puVar8 = puVar8 + 0x20;

            iStack_803c = iStack_803c + -1;

          } while (iStack_803c != 0);

          iStack_803c = 0;

          puVar5 = puStack_8030;

          iVar4 = iVar3;

          if (0 < iVar3) {

            do {

              (**(code **)*puVar5)(0);

              iVar4 = iVar4 + -1;

              puVar2 = local_8020;

              puVar5 = puVar5 + 0x20;

            } while (iVar4 != 0);

          }

        }

        if (-1 < (int)uVar1) {

          (**(code **)(*DAT_00b05060 + 0x14))(puStack_8030,uVar1 << 7,0x12);

          puVar2 = local_8020;

        }

      }

      else if (iVar3 < (int)local_8020) {

        iVar4 = iVar3 * 0x80 + *piVar7;

        iVar9 = (int)local_8020 - iVar3;

        do {

          if (iVar4 != 0) {

            FUN_00658800();

            puVar2 = local_8020;

          }

          iVar4 = iVar4 + 0x80;

          iVar9 = iVar9 + -1;

        } while (iVar9 != 0);

      }

      if (iVar3 < (int)puVar6) {

        iVar4 = iVar3 * 0x80 + *(int *)(iStack_8054 + 4);

        iVar3 = (int)puVar6 - iVar3;

        do {

          if (iVar4 != 0) {

            FUN_00658800();

            puVar2 = local_8020;

          }

          iVar4 = iVar4 + 0x80;

          iVar3 = iVar3 + -1;

        } while (iVar3 != 0);

      }

    }

    *(uint8_t **)(iStack_8054 + 8) = puVar6;

  }

  iStack_8048 = 0;

  puStack_8044 = (uint8_t *)0x0;

  uStack_8040 = 0x80000000;

  puVar6 = puVar2;

  if (0 < (int)puVar2) {

    FUN_005b3300(&iStack_8048,(uint)puVar2 & ((int)puVar2 < 0) - 1,4);

    puVar6 = local_8020;

  }

  puVar6 = puVar6 + -1;

  puStack_8044 = puVar2;

  if (-1 < (int)puVar6) {

    iVar4 = (int)puVar6 * 0x80;

    iVar3 = (int)puVar6 * 0x20;

    do {

      FUN_00657d10(iStack_8024 + iVar3,iStack_8024 + iVar3 + 0x10);

      *(int *)(iStack_8048 + (int)puVar6 * 4) = *(int *)(iStack_8054 + 4) + iVar4;

      puVar6 = puVar6 + -1;

      iVar3 = iVar3 + -0x20;

      iVar4 = iVar4 + -0x80;

    } while (-1 < (int)puVar6);

  }

  (**(code **)(**(int **)(iStack_8054 + -4) + 0x24))(&iStack_8048,0xffff0000,DAT_00d03528);

  if (-1 < (int)puStack_804c) {

    (**(code **)(*DAT_00b05060 + 0x14))(iStack_8054,(int)puStack_804c * 4,0x12);

  }

  if (-1 < iStack_8028) {

    (**(code **)(*DAT_00b05060 + 0x14))(puStack_8030,iStack_8028 << 5,0x12);

  }

  return;

}
