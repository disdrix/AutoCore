// =============================================================================
// FUN_0083b920
// -----------------------------------------------------------------------------
// Stable ID: aa_0083b920
// Address:   0x0083b920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083b920 @ 0x0083b920
// Stable ID: aa_0083b920
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
//   - "%.0f s"
//   - "%.0f m"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×19, for×2, goto×2, return×1.
//  - Notable callees: FUN_007a4480×4, sprintf×3, FUN_00578270×2, ceil×2, CVOGHBBase_GetRemainingSeconds, FUN_0083b920, ROUND, fsin.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal"; "%.0f s".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0083b920(int param_1,float param_2)



{

  CVOGHBBase *this;

  char cVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  bool bVar6;

  float10 fVar7;

  float fVar8;

  float fVar9;

  double dVar10;

  uint32_t /* width from decompiler */ uStack_6c;

  uint8_t uStack_64;

  uint8_t uStack_63;

  uint8_t uStack_62;

  uint8_t uStack_61;

  int iStack_58;

  uint8_t auStack_54 [4];

  int local_50;

  float local_4c;

  char acStack_48 [68];

  

  iVar2 = *(int *)(param_1 + 0x538);

  if (iVar2 != 0) {

    local_50 = 0;

    if (*(char *)(iVar2 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar2 + 0x1d) = 1;

LAB_0083b970:

    iVar2 = *(int *)(param_1 + 0x538);

    if (*(char *)(iVar2 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (local_50 == 0) {

      local_50 = *(int *)(iVar2 + 0x14);

      if (local_50 == 0) goto LAB_0083b9bf;

      piVar5 = *(int **)(local_50 + 8);

    }

    else {

      local_50 = *(int *)(local_50 + 0x14);

      if (local_50 == 0) {

LAB_0083b9bf:

        piVar5 = (int *)0x0;

      }

      else {

        piVar5 = *(int **)(local_50 + 8);

      }

    }

    if (piVar5 != (int *)0x0) {

      if ((piVar5[0x182] != 0) && ((int *)piVar5[0x18c] != (int *)0x0)) {

        if (*(int *)(piVar5[0x182] + 0x10) == -1000) {

          iVar2 = (**(code **)(*(int *)piVar5[0x18c] + 0x1dc))();

          if (iVar2 != 0) {

            (**(code **)(*(int *)piVar5[0x18c] + 0x1d8))(0);

            (**(code **)(*(int *)piVar5[0x18c] + 0x34c))();

          }

        }

        else {

          iVar2 = FUN_00578270();

          if (iVar2 == 0) {

            bVar6 = false;

          }

          else {

            piVar3 = (int *)FUN_00578270();

            iVar2 = (**(code **)(*piVar3 + 0x210))();

            bVar6 = iVar2 == DAT_00d1b6d8;

          }

          this = (CVOGHBBase *)piVar5[0x182];

          local_4c = (float)this->nPeriodMs;

          if (this->nPeriodMs < 0) {

            local_4c = local_4c + _DAT_00aaa5dc;

          }

          local_4c = local_4c * g_flMsToSeconds_Inferred;

          piVar5[0x140] = (int)((float)piVar5[0x140] + param_2);

          fVar9 = CVOGHBBase_GetRemainingSeconds(this);

          if (fVar9 <= DAT_00aaa9f0) {

            fVar8 = local_4c * DAT_00a0f704;

            if (DAT_00a0f694 < local_4c * DAT_00a0f704) {

              fVar8 = DAT_00a0f694;

            }

            if ((fVar8 < fVar9) || ((bVar6 && (local_4c <= DAT_00a0f694)))) {

              ceil((double)fVar9);

              sprintf(acStack_48,"%.0f s");

              cVar1 = (**(code **)(*piVar5 + 0xf8))();

              if (cVar1 == '\0') {

                iVar2 = (**(code **)(*(int *)piVar5[0x18c] + 0x164))(1);

                uStack_61 = *(uint8_t *)(iVar2 + 3);

                uStack_62 = 0xff;

                uStack_63 = 0xff;

                uStack_64 = 0xff;

                (**(code **)(*(int *)piVar5[0x18c] + 0x15c))(1,&uStack_64);

              }

            }

            else {

              dVar10 = ceil((double)fVar9);

              sprintf(acStack_48,"%.0f s",dVar10);

              iVar2 = (**(code **)(*(int *)piVar5[0x18c] + 0x164))();

              uStack_61 = *(uint8_t *)(iVar2 + 3);

              uStack_62 = 0xff;

              uStack_63 = 0xff;

              uStack_64 = 0xff;

              (**(code **)(*(int *)piVar5[0x18c] + 0x15c))(1);

              cVar1 = (**(code **)(*piVar5 + 0xf8))();

              if (cVar1 == '\0') {

                fVar7 = (float10)fsin((float10)(float)piVar5[0x140] * (float10)_DAT_00aaa9e8);

                iStack_58 = (int)ROUND((fVar7 + (float10)g_flVehicleHpTechCoeff) *

                                       (float10)DAT_00a0f704 * (float10)DAT_00aaa6f8);

                if ((int *)piVar5[0x18b] != (int *)0x0) {

                  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)piVar5[0x18b] + 0x164))(0);

                  *puVar4 = uStack_6c;

                  (**(code **)(*(int *)piVar5[0x18b] + 0x34c))();

                }

                if ((int *)piVar5[0x18a] != (int *)0x0) {

                  (**(code **)(*(int *)piVar5[0x18a] + 0x164))(2);

                  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)piVar5[0x18a] + 0x164))(0);

                  *puVar4 = uStack_6c;

                  (**(code **)(*(int *)piVar5[0x18a] + 0x34c))();

                }

              }

            }

          }

          else {

            sprintf(acStack_48,"%.0f m",(double)(fVar9 * DAT_00aaa9ec));

            (**(code **)(*(int *)piVar5[0x18c] + 0x164))();

            (**(code **)(*(int *)piVar5[0x18c] + 0x15c))(1);

          }

          (**(code **)(*(int *)piVar5[0x18c] + 0x1d8))(auStack_54,1,1);

          (**(code **)(*(int *)piVar5[0x18c] + 0x34c))();

        }

      }

      goto LAB_0083b970;

    }

    *(uint8_t *)(*(int *)(param_1 + 0x538) + 0x1d) = 0;

  }

  return;

}
