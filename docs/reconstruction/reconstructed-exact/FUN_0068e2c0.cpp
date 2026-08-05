// =============================================================================
// FUN_0068e2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068e2c0
// Address:   0x0068e2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068e2c0 @ 0x0068e2c0
// Stable ID: aa_0068e2c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~212 non-empty decompiler lines.
//  - Control keywords: if×18, return×6, while×3, for×2, do×1, goto×1.
//  - Notable callees: FUN_0068cfe0×2, CONCAT31, FUN_0040f5b0, FUN_00443b40, FUN_0068bae0, FUN_0068bee0, FUN_0068daa0, FUN_0068dba0.
//  - Return sites: 6.

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

int __fastcall FUN_0068e2c0(int param_1)



{

  int iVar1;

  int iVar2;

  uint16_t *puVar3;

  void *pvVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  ushort uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  short sVar11;

  uint32_t /* width from decompiler */ *puVar12;

  int iVar13;

  uint32_t /* width from decompiler */ *puVar14;

  uint uVar15;

  uint16_t local_50;

  uint32_t /* width from decompiler */ *local_4c;

  uint local_48;

  int local_44;

  int local_40;

  uint8_t local_3c [4];

  void *local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t local_2c [4];

  void *local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t local_1c [4];

  void *local_18;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aa558;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 100) == 0) {

    uVar8 = 0;

  }

  else {

    uVar8 = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2;

  }

  iVar13 = uVar8 * -0x55555555;

  if ((short)(uVar8 / 3) != 0) {

    ExceptionList = &local_c;

    local_44 = param_1;

    FUN_0068dba0(*(uint16_t *)(param_1 + 0x18));

    local_4 = 0;

    FUN_0068dd60(*(uint16_t *)(param_1 + 0x18));

    local_4._0_1_ = 1;

    local_48 = 0;

    FUN_0068bee0(*(uint16_t *)(param_1 + 0x18),&local_48);

    local_4 = CONCAT31(local_4._1_3_,2);

    local_48 = 0;

    if (*(short *)(param_1 + 0x18) != 0) {

      do {

        uVar8 = local_48;

        iVar13 = 0;

        uVar9 = 0;

        while (sVar11 = (short)local_48, -1 < sVar11) {

          iVar5 = sVar11 * 0x10 + *(int *)(param_1 + 0x44);

          iVar1 = *(int *)(iVar5 + 4);

          if ((iVar1 == 0) || ((ushort)(*(int *)(iVar5 + 8) - iVar1 >> 2) <= uVar9)) {

            if (-1 < sVar11) {

              iVar1 = *(int *)(sVar11 * 0x10 + 4 + *(int *)(param_1 + 0x44));

              if (iVar1 != 0) {

                uVar6 = *(int *)(sVar11 * 0x10 + *(int *)(param_1 + 0x44) + 8) - iVar1 >> 2;

                goto LAB_0068e3c3;

              }

            }

            break;

          }

          iVar13 = iVar13 + (uint)*(ushort *)

                                   (*(int *)((local_48 & 0xffff) * 0x10 + 4 +

                                            *(int *)(param_1 + 0x34)) + (uint)uVar9 * 2);

          uVar9 = uVar9 + 1;

        }

        uVar6 = 0;

LAB_0068e3c3:

        uVar6 = uVar6 & 0xffff;

        if (uVar6 != 0) {

          uVar6 = uVar6 - 1;

        }

        iVar13 = iVar13 + uVar6 * 4;

        if (iVar13 < 1) {

          iVar13 = (local_48 & 0xffff) * 0x10;

          pvVar4 = *(void **)(iVar13 + 4 + (int)local_28);

          if (pvVar4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar4);

          }

          *(uint32_t /* width from decompiler */ *)(iVar13 + 4 + (int)local_28) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar13 + 8 + (int)local_28) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc + (int)local_28) = 0;

          pvVar4 = *(void **)(iVar13 + 4 + (int)local_38);

          if (pvVar4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar4);

          }

          *(uint32_t /* width from decompiler */ *)(iVar13 + 4 + (int)local_38) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar13 + 8 + (int)local_38) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc + (int)local_38) = 0;

          *(uint32_t /* width from decompiler */ *)((int)local_18 + (local_48 & 0xffff) * 4) = 0;

        }

        else {

          local_4c = operator_new__(iVar13 * 2);

          uVar9 = 0;

          puVar10 = local_4c;

          while (-1 < (short)uVar8) {

            iVar1 = *(int *)(param_1 + 0x44);

            iVar7 = (short)uVar8 * 0x10;

            iVar5 = *(int *)(iVar7 + 4 + iVar1);

            if ((iVar5 == 0) || ((ushort)(*(int *)(iVar7 + 8 + iVar1) - iVar5 >> 2) <= uVar9))

            break;

            iVar5 = (uVar8 & 0xffff) * 0x10;

            uVar6 = (uint)*(ushort *)

                           (*(int *)(*(int *)(param_1 + 0x34) + 4 + iVar5) + (uint)uVar9 * 2) * 2;

            puVar12 = *(uint32_t /* width from decompiler */ **)(*(int *)(iVar5 + 4 + iVar1) + (uint)uVar9 * 4);

            puVar14 = puVar10;

            for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

              *puVar14 = *puVar12;

              puVar12 = puVar12 + 1;

              puVar14 = puVar14 + 1;

            }

            for (uVar8 = uVar6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

              *(uint8_t *)puVar14 = *(uint8_t *)puVar12;

              puVar12 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

              puVar14 = (uint32_t /* width from decompiler */ *)((int)puVar14 + 1);

            }

            iVar1 = *(int *)(local_44 + 0x44);

            iVar2 = *(int *)(iVar1 + 4 + iVar7);

            puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + uVar6);

            if (iVar2 == 0) {

              uVar8 = 0;

            }

            else {

              uVar8 = *(int *)(iVar1 + 8 + iVar7) - iVar2 >> 2;

            }

            uVar15 = (uint)uVar9;

            if ((int)uVar15 < (int)((uVar8 & 0xffff) - 1)) {

              *(uint16_t *)puVar10 =

                   *(uint16_t *)(*(int *)(*(int *)(iVar5 + 4 + iVar1) + uVar15 * 4) + -2 + uVar6);

              *(uint16_t *)((int)puVar10 + 2) =

                   **(uint16_t **)

                     (*(int *)(*(int *)(local_44 + 0x44) + 4 + iVar5) + 4 + uVar15 * 4);

              *(uint16_t *)(puVar10 + 1) =

                   **(uint16_t **)

                     (*(int *)(*(int *)(local_44 + 0x44) + 4 + iVar5) + 4 + uVar15 * 4);

              *(uint16_t *)((int)puVar10 + 6) =

                   *(uint16_t *)

                    (*(int *)(*(int *)(*(int *)(local_44 + 0x44) + 4 + iVar5) + 4 + uVar15 * 4) + 2)

              ;

              puVar10 = puVar10 + 2;

            }

            uVar9 = uVar9 + 1;

            uVar8 = local_48;

            param_1 = local_44;

          }

          iVar5 = (uVar8 & 0xffff) * 0x10;

          iVar1 = *(int *)((int)local_28 + iVar5 + 4);

          local_40 = iVar13;

          if ((iVar1 == 0) ||

             ((uint)(*(int *)((int)local_28 + iVar5 + 0xc) - iVar1 >> 1) <=

              (uint)(*(int *)((int)local_28 + iVar5 + 8) - iVar1 >> 1))) {

            FUN_00443b40(*(uint32_t /* width from decompiler */ *)((int)local_28 + iVar5 + 8),1,&local_40);

          }

          else {

            puVar3 = *(uint16_t **)((int)local_28 + iVar5 + 8);

            local_50 = (uint16_t)iVar13;

            *puVar3 = local_50;

            *(uint16_t **)((int)local_28 + iVar5 + 8) = puVar3 + 1;

          }

          iVar1 = *(int *)((int)local_38 + iVar5 + 4);

          if ((iVar1 == 0) ||

             ((uint)(*(int *)((int)local_38 + iVar5 + 0xc) - iVar1 >> 2) <=

              (uint)(*(int *)((int)local_38 + iVar5 + 8) - iVar1 >> 2))) {

            FUN_0068bae0(*(uint32_t /* width from decompiler */ *)((int)local_38 + iVar5 + 8),1,&local_4c);

          }

          else {

            puVar10 = *(uint32_t /* width from decompiler */ **)((int)local_38 + iVar5 + 8);

            *puVar10 = local_4c;

            *(uint32_t /* width from decompiler */ **)((int)local_38 + iVar5 + 8) = puVar10 + 1;

          }

          *(int *)((int)local_18 + (uVar8 & 0xffff) * 4) = iVar13 + -2;

          local_48 = uVar8;

        }

        local_48 = local_48 + 1;

      } while ((ushort)local_48 < *(ushort *)(param_1 + 0x18));

    }

    FUN_0068daa0();

    FUN_0068dc00(local_2c);

    FUN_0068ddc0(local_3c);

    FUN_0040f5b0(local_1c);

    if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_18);

    }

    if (local_38 != (void *)0x0) {

      FUN_0068cfe0(local_38,local_34,local_3c,local_40);

                    /* WARNING: Subroutine does not return */

      operator_delete(local_38);

    }

    iVar13 = 0;

    if (local_28 != (void *)0x0) {

      FUN_0068cfe0(local_28,local_24,local_2c,local_40);

                    /* WARNING: Subroutine does not return */

      operator_delete(local_28);

    }

  }

  ExceptionList = local_c;

  return iVar13;

}
