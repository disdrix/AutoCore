// =============================================================================
// FUN_004747e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004747e0
// Address:   0x004747e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004747e0 @ 0x004747e0
// Stable ID: aa_004747e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~273 non-empty decompiler lines.
//  - Control keywords: if×39, do×13, while×13, return×7, goto×4.
//  - Notable callees: malloc×9, _CIpow×7, FUN_006a3db0×6, FUN_00476cc0×5, FUN_004747e0, FUN_004776d0, ROUND.
//  - Return sites: 7.

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



void FUN_004747e0(void)



{

  double dVar1;

  byte bVar2;

  uint8_t uVar3;

  uint16_t uVar4;

  int in_EAX;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  uint uVar8;

  byte bVar9;

  int iVar10;

  uint uVar11;

  int iVar12;

  uint uVar13;

  float10 fVar14;

  uint local_38;

  uint local_34;

  ushort uStack_24;

  uint local_20;

  

  if ((float)_DAT_00aaa608 != *(float *)(in_EAX + 0x15c)) {

    if (*(byte *)(in_EAX + 0x127) < 9) {

      if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

        pvVar5 = malloc(0x100);

      }

      else {

        pvVar5 = (void *)(**(code **)(in_EAX + 0x248))();

      }

      if ((pvVar5 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0();

      }

      iVar12 = 0;

      *(void **)(in_EAX + 0x164) = pvVar5;

      do {

        _CIpow();

        uVar3 = FUN_006a3db0();

        *(uint8_t *)(iVar12 + *(int *)(in_EAX + 0x164)) = uVar3;

        iVar12 = iVar12 + 1;

      } while (iVar12 < 0x100);

      if ((*(uint *)(in_EAX + 0x70) & 0x600080) != 0) {

        if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

          pvVar5 = malloc(0x100);

        }

        else {

          pvVar5 = (void *)(**(code **)(in_EAX + 0x248))();

        }

        if ((pvVar5 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

          FUN_00476cc0();

        }

        iVar12 = 0;

        *(void **)(in_EAX + 0x16c) = pvVar5;

        do {

          _CIpow();

          uVar3 = FUN_006a3db0();

          *(uint8_t *)(iVar12 + *(int *)(in_EAX + 0x16c)) = uVar3;

          iVar12 = iVar12 + 1;

        } while (iVar12 < 0x100);

        if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

          pvVar5 = malloc(0x100);

        }

        else {

          pvVar5 = (void *)(**(code **)(in_EAX + 0x248))();

        }

        if ((pvVar5 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

          FUN_00476cc0();

        }

        *(void **)(in_EAX + 0x168) = pvVar5;

        iVar12 = 0;

        do {

          _CIpow();

          uVar3 = FUN_006a3db0();

          *(uint8_t *)(iVar12 + *(int *)(in_EAX + 0x168)) = uVar3;

          iVar12 = iVar12 + 1;

        } while (iVar12 < 0x100);

        return;

      }

    }

    else {

      if ((*(byte *)(in_EAX + 0x126) & 2) == 0) {

        local_34 = (uint)*(byte *)(in_EAX + 0x17f);

      }

      else {

        local_34 = (uint)*(byte *)(in_EAX + 0x17c);

        if ((uint)*(byte *)(in_EAX + 0x17c) < (uint)*(byte *)(in_EAX + 0x17d)) {

          local_34 = (uint)*(byte *)(in_EAX + 0x17d);

        }

        if (local_34 < *(byte *)(in_EAX + 0x17e)) {

          local_34 = (uint)*(byte *)(in_EAX + 0x17e);

        }

      }

      if (local_34 == 0) {

        local_34 = 0;

      }

      else {

        local_34 = 0x10 - local_34;

      }

      if (((*(byte *)(in_EAX + 0x71) & 4) == 0) || (4 < (int)local_34)) {

        if ((int)local_34 < 9) {

          if ((int)local_34 < 0) {

            local_34 = 0;

          }

        }

        else {

          local_34 = 8;

        }

      }

      else {

        local_34 = 5;

      }

      bVar2 = (byte)local_34;

      bVar9 = 8 - bVar2;

      iVar12 = 1 << (bVar9 & 0x1f);

      *(uint *)(in_EAX + 0x158) = local_34 & 0xff;

      uVar6 = FUN_004776d0();

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x170) = uVar6;

      if ((*(uint *)(in_EAX + 0x70) & 0x480) == 0) {

        local_38 = 0;

        if (0 < iVar12) {

          do {

            if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

              pvVar5 = malloc(0x200);

            }

            else {

              pvVar5 = (void *)(**(code **)(in_EAX + 0x248))();

            }

            if ((pvVar5 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0))

            goto LAB_00474ec6;

            *(void **)(*(int *)(in_EAX + 0x170) + local_38 * 4) = pvVar5;

            iVar10 = 0;

            do {

              _CIpow();

              uVar4 = FUN_006a3db0();

              *(uint16_t *)(iVar10 + *(int *)(*(int *)(in_EAX + 0x170) + local_38 * 4)) = uVar4;

              iVar10 = iVar10 + 2;

            } while (iVar10 < 0x200);

            local_38 = local_38 + 1;

          } while ((int)local_38 < iVar12);

        }

      }

      else {

        iVar10 = 0;

        if (0 < iVar12) {

          do {

            if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

              pvVar5 = malloc(0x200);

            }

            else {

              pvVar5 = (void *)(**(code **)(in_EAX + 0x248))();

            }

            if ((pvVar5 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0))

            goto LAB_00474ec6;

            *(void **)(*(int *)(in_EAX + 0x170) + iVar10 * 4) = pvVar5;

            iVar10 = iVar10 + 1;

          } while (iVar10 < iVar12);

        }

        uVar7 = iVar12 << 8;

        uVar13 = 0;

        local_38 = 0;

        dVar1 = (double)(int)uVar7;

        if ((int)uVar7 < 0) {

          dVar1 = dVar1 + _DAT_00aaa728;

        }

        do {

          fVar14 = (float10)_CIpow();

          local_20 = (uint)(longlong)ROUND(fVar14 * (float10)dVar1);

          if (uVar13 <= local_20) {

            uStack_24 = (ushort)((local_38 & 0xff) << 8) | (ushort)local_38;

            do {

              uVar11 = uVar13 >> (bVar9 & 0x1f);

              uVar8 = 0xff >> (bVar2 & 0x1f) & uVar13;

              uVar13 = uVar13 + 1;

              *(ushort *)(*(int *)(*(int *)(in_EAX + 0x170) + uVar8 * 4) + uVar11 * 2) = uStack_24;

            } while (uVar13 <= local_20);

          }

          local_38 = local_38 + 1;

        } while ((int)local_38 < 0x100);

        if (uVar13 < uVar7) {

          do {

            uVar8 = 0xff >> (bVar2 & 0x1f) & uVar13;

            uVar11 = uVar13 >> (bVar9 & 0x1f);

            uVar13 = uVar13 + 1;

            *(uint16_t *)(*(int *)(*(int *)(in_EAX + 0x170) + uVar8 * 4) + uVar11 * 2) = 0xffff;

          } while (uVar13 < uVar7);

        }

      }

      if ((*(uint *)(in_EAX + 0x70) & 0x600080) != 0) {

        if (iVar12 * 4 == 0) {

          pvVar5 = (void *)0x0;

        }

        else {

          if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

            pvVar5 = malloc(iVar12 * 4);

          }

          else {

            pvVar5 = (void *)(**(code **)(in_EAX + 0x248))();

          }

          if ((pvVar5 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

            FUN_00476cc0();

          }

        }

        *(void **)(in_EAX + 0x178) = pvVar5;

        local_38 = 0;

        if (0 < iVar12) {

          do {

            if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

              pvVar5 = malloc(0x200);

            }

            else {

              pvVar5 = (void *)(**(code **)(in_EAX + 0x248))();

            }

            if ((pvVar5 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0))

            goto LAB_00474ec6;

            *(void **)(*(int *)(in_EAX + 0x178) + local_38 * 4) = pvVar5;

            iVar10 = 0;

            do {

              _CIpow();

              uVar4 = FUN_006a3db0();

              *(uint16_t *)(iVar10 + *(int *)(*(int *)(in_EAX + 0x178) + local_38 * 4)) = uVar4;

              iVar10 = iVar10 + 2;

            } while (iVar10 < 0x200);

            local_38 = local_38 + 1;

          } while ((int)local_38 < iVar12);

        }

        if (iVar12 * 4 == 0) {

          pvVar5 = (void *)0x0;

        }

        else {

          if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

            pvVar5 = malloc(iVar12 * 4);

          }

          else {

            pvVar5 = (void *)(**(code **)(in_EAX + 0x248))();

          }

          if ((pvVar5 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0)) {

LAB_00474ec6:

                    /* WARNING: Subroutine does not return */

            FUN_00476cc0();

          }

        }

        *(void **)(in_EAX + 0x174) = pvVar5;

        local_38 = 0;

        if (0 < iVar12) {

          do {

            if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

              pvVar5 = malloc(0x200);

            }

            else {

              pvVar5 = (void *)(**(code **)(in_EAX + 0x248))();

            }

            if ((pvVar5 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0))

            goto LAB_00474ec6;

            *(void **)(*(int *)(in_EAX + 0x174) + local_38 * 4) = pvVar5;

            iVar10 = 0;

            do {

              _CIpow();

              uVar4 = FUN_006a3db0();

              *(uint16_t *)(iVar10 + *(int *)(*(int *)(in_EAX + 0x174) + local_38 * 4)) = uVar4;

              iVar10 = iVar10 + 2;

            } while (iVar10 < 0x200);

            local_38 = local_38 + 1;

          } while ((int)local_38 < iVar12);

        }

      }

    }

  }

  return;

}
