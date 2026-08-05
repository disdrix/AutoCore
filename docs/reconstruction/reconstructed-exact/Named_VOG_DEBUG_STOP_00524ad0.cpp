// READABILITY (auto CF):
//  - Body size: ~364 non-empty decompiler lines.
//  - Control keywords: if×61, for×12, do×6, while×6, goto×5, return×1.
//  - Notable callees: FUN_007a4480×24, CVOGReaction_RandomUnitScalar×8, FUN_00523430×5, FUN_00524ad0, FUN_007a4080.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00524ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00524ad0
// Address:   0x00524ad0  (autoassault.exe, image base 0x400000)
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

void __fastcall Named_VOG_DEBUG_STOP_00524ad0(int param_1)



{

  ushort uVar1;

  int iVar2;

  bool bVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *local_18;

  uint32_t /* width from decompiler */ *local_14;

  uint32_t /* width from decompiler */ *local_10;

  uint32_t /* width from decompiler */ *local_c;

  uint32_t /* width from decompiler */ *local_8;

  int local_4;

  

  local_14 = (uint32_t /* width from decompiler */ *)0x0;

  local_10 = (uint32_t /* width from decompiler */ *)0x0;

  local_c = (uint32_t /* width from decompiler */ *)0x0;

  local_18 = (uint32_t /* width from decompiler */ *)0x0;

  local_8 = (uint32_t /* width from decompiler */ *)0x0;

  CVOGReaction_RandomUnitScalar();

  FUN_007a4080();

  iVar4 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar4 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

  *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

  bVar3 = DAT_00a0f710 < (float)uVar1 * DAT_00aaa638;

  iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

                  0x544);

  iVar6 = 0;

  if (0 < *(int *)(iVar4 + 0xc)) {

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    local_4 = (int)((longlong)(ulonglong)uVar1 %

                   (longlong)

                   (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac +

                                                       param_1) + 0x3c) + 0x544) + 0xc) + 1));

    if (0 < local_4) {

      do {

        iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                 0x3c) + 0x544);

        if (*(char *)(iVar4 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar6 == 0) {

          iVar6 = *(int *)(iVar4 + 0x14);

          if (iVar6 == 0) goto LAB_00524c21;

          local_14 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

        }

        else {

          iVar6 = *(int *)(iVar6 + 0x14);

          if (iVar6 == 0) {

LAB_00524c21:

            local_14 = (uint32_t /* width from decompiler */ *)0x0;

          }

          else {

            local_14 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

          }

        }

        local_4 = local_4 + -1;

      } while (local_4 != 0);

      if (local_14 != (uint32_t /* width from decompiler */ *)0x0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x700) = *local_14;

      }

    }

    *(uint8_t *)

     (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

              0x544) + 0x1d) = 0;

  }

  iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

                  0x53c);

  iVar6 = 0;

  if (0 < *(int *)(iVar4 + 0xc)) {

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    iVar4 = (int)((longlong)(ulonglong)uVar1 %

                 (longlong)

                 (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac +

                                                     param_1) + 0x3c) + 0x53c) + 0xc) + 1));

    if (0 < iVar4) {

      do {

        iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                 0x3c) + 0x53c);

        if (*(char *)(iVar2 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar6 == 0) {

          iVar6 = *(int *)(iVar2 + 0x14);

          if (iVar6 == 0) goto LAB_00524d34;

          local_10 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

        }

        else {

          iVar6 = *(int *)(iVar6 + 0x14);

          if (iVar6 == 0) {

LAB_00524d34:

            local_10 = (uint32_t /* width from decompiler */ *)0x0;

          }

          else {

            local_10 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

          }

        }

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      if (local_10 != (uint32_t /* width from decompiler */ *)0x0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x708) = *local_10;

      }

    }

    *(uint8_t *)

     (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

              0x53c) + 0x1d) = 0;

  }

  iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

                  0x540);

  iVar6 = 0;

  if (0 < *(int *)(iVar4 + 0xc)) {

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    iVar4 = (int)((longlong)(ulonglong)uVar1 %

                 (longlong)

                 (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac +

                                                     param_1) + 0x3c) + 0x540) + 0xc) + 1));

    if (0 < iVar4) {

      do {

        iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                 0x3c) + 0x540);

        if (*(char *)(iVar2 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar6 == 0) {

          iVar6 = *(int *)(iVar2 + 0x14);

          if (iVar6 == 0) goto LAB_00524e53;

          local_c = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

        }

        else {

          iVar6 = *(int *)(iVar6 + 0x14);

          if (iVar6 == 0) {

LAB_00524e53:

            local_c = (uint32_t /* width from decompiler */ *)0x0;

          }

          else {

            local_c = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

          }

        }

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      if (local_c != (uint32_t /* width from decompiler */ *)0x0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x70c) = *local_c;

      }

    }

    *(uint8_t *)

     (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

              0x540) + 0x1d) = 0;

  }

  iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

                  0x548);

  iVar6 = 0;

  if (0 < *(int *)(iVar4 + 0xc)) {

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    iVar4 = (int)((longlong)(ulonglong)uVar1 %

                 (longlong)

                 (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac +

                                                     param_1) + 0x3c) + 0x548) + 0xc) + 1));

    if (0 < iVar4) {

      do {

        iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                 0x3c) + 0x548);

        if (*(char *)(iVar2 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar6 == 0) {

          iVar6 = *(int *)(iVar2 + 0x14);

        }

        else {

          iVar6 = *(int *)(iVar6 + 0x14);

        }

        if (iVar6 == 0) {

          puVar5 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          puVar5 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

        }

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x710) = *puVar5;

      }

    }

    *(uint8_t *)

     (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

              0x548) + 0x1d) = 0;

  }

  iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

                  0x54c);

  iVar6 = 0;

  if (0 < *(int *)(iVar4 + 0xc)) {

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    iVar4 = (int)((longlong)(ulonglong)uVar1 %

                 (longlong)

                 (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac +

                                                     param_1) + 0x3c) + 0x54c) + 0xc) + 1));

    if (0 < iVar4) {

      do {

        iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                 0x3c) + 0x54c);

        if (*(char *)(iVar2 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar6 == 0) {

          iVar6 = *(int *)(iVar2 + 0x14);

          if (iVar6 == 0) goto LAB_00525073;

          local_18 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

        }

        else {

          iVar6 = *(int *)(iVar6 + 0x14);

          if (iVar6 == 0) {

LAB_00525073:

            local_18 = (uint32_t /* width from decompiler */ *)0x0;

          }

          else {

            local_18 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

          }

        }

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      if (local_18 != (uint32_t /* width from decompiler */ *)0x0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x704) = *local_18;

      }

    }

    *(uint8_t *)

     (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

              0x54c) + 0x1d) = 0;

    if ((local_18 != (uint32_t /* width from decompiler */ *)0x0) && (local_18[0x25] != 0)) {

      if (bVar3) {

        local_14 = (uint32_t /* width from decompiler */ *)0x0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x700) = 0xffffffff;

      }

      else {

        local_18 = (uint32_t /* width from decompiler */ *)0x0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x704) = 0xffffffff;

      }

    }

  }

  iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

                  0x550);

  iVar6 = 0;

  if (0 < *(int *)(iVar4 + 0xc)) {

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    iVar4 = (int)((longlong)(ulonglong)uVar1 %

                 (longlong)

                 (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac +

                                                     param_1) + 0x3c) + 0x550) + 0xc) + 1));

    if (0 < iVar4) {

      do {

        iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                 0x3c) + 0x550);

        if (*(char *)(iVar2 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar6 == 0) {

          iVar6 = *(int *)(iVar2 + 0x14);

          if (iVar6 == 0) goto LAB_005251c3;

          local_8 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

        }

        else {

          iVar6 = *(int *)(iVar6 + 0x14);

          if (iVar6 == 0) {

LAB_005251c3:

            local_8 = (uint32_t /* width from decompiler */ *)0x0;

          }

          else {

            local_8 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

          }

        }

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      if (local_8 != (uint32_t /* width from decompiler */ *)0x0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x714) = *local_8;

      }

    }

    *(uint8_t *)

     (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

              0x550) + 0x1d) = 0;

  }

  if (local_14 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00523430(1,local_14,0);

  }

  if (local_10 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00523430(3,local_10,0);

  }

  if (local_c != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00523430(4,local_c,0);

  }

  if (local_18 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00523430(7,local_18,0);

  }

  if (local_8 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00523430(8,local_8,0);

  }

  return;

}
