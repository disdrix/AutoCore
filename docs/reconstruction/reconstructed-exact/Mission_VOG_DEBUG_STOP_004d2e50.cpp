// READABILITY (auto CF):
//  - Body size: ~173 non-empty decompiler lines.
//  - Control keywords: if×27, goto×9, while×6, do×4, return×4, for×3.
//  - Notable callees: FUN_007a4480×6, FUN_0053fff0×5, CVOGCharacter_CheckMissionRequirements×3, CVOGCharacter_HasCompletedMission, FUN_00402c40, FUN_004d2e50, FUN_00547920.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 4.

// =============================================================================
// Mission_VOG_DEBUG_STOP_004d2e50
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "VOG_DEBUG_STOP"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004d2e50 clean capture (not modernized).
//
// Address:  0x004d2e50  (autoassault.exe, image base 0x400000)
// Stable:   aa_004d2e50
// Stable ID: aa_004d2e50
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004d2e50_*.md
//           Original Ghidra symbol: FUN_004d2e50
//
// Exactness: Body mirrors reconstructed-exact/FUN_004d2e50*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_VOG_DEBUG_STOP_004d2e50
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2e50
// Address:   0x004d2e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

char Mission_VOG_DEBUG_STOP_004d2e50(int param_1,int *param_2)



{

  uint uVar1;

  uint *puVar2;

  bool bVar3;

  bool bVar4;

  int *piVar5;

  uint *this;

  void *this_00;

  int iVar6;

  uint *puVar7;

  uint uVar8;

  int iVar9;

  int iVar10;

  int *unaff_EDI;

  

  bVar4 = false;

  if ((*(int *)(param_1 + 0x244) != 0) &&

     (*(int *)(param_1 + 0x248) - *(int *)(param_1 + 0x244) >> 2 != 0)) {

    uVar8 = 0;

    while ((iVar6 = *(int *)(param_1 + 0x244), iVar6 != 0 &&

           (uVar8 < (uint)(*(int *)(param_1 + 0x248) - iVar6 >> 2)))) {

      iVar10 = uVar8 * 4;

      uVar1 = *(uint *)(iVar6 + iVar10);

      piVar5 = (int *)FUN_0053fff0();

      iVar6 = *piVar5;

      if (iVar6 == 0) {

        this = (uint *)0x0;

LAB_004d2f13:

        bVar3 = CVOGCharacter_HasCompletedMission

                          (param_2,*(uint *)(*(int *)(param_1 + 0x244) + iVar10));

        if (!bVar3) goto LAB_004d2f98;

        uVar1 = *(uint *)(*(int *)(param_1 + 0x244) + iVar10);

        iVar6 = *(int *)(*(int *)(*(int *)(param_2[0x14e] + 0x10) +

                                 (*(uint *)(param_2[0x14e] + 8) & uVar1) * 4) + 4);

        if (iVar6 == 0) {

LAB_004d2f6a:

          this_00 = (void *)0x0;

        }

        else {

          do {

            if (uVar1 == *(uint *)(iVar6 + 0x10)) {

              if (iVar6 == 0) goto LAB_004d2f6a;

              this_00 = *(void **)(iVar6 + 8);

              goto LAB_004d2f71;

            }

            iVar6 = *(int *)(iVar6 + 0xc);

          } while (iVar6 != 0);

          this_00 = (void *)0x0;

        }

LAB_004d2f71:

        if ((*(short *)((int)this_00 + 0xac) == 0) ||

           (iVar6 = CVOGCharacter_CheckMissionRequirements(this_00,param_2,unaff_EDI), iVar6 != 0))

        goto LAB_004d2fac;

        bVar4 = true;

        uVar8 = uVar8 + 1;

      }

      else {

        iVar6 = *(int *)(*(int *)(*(int *)(iVar6 + 0x10) + (*(uint *)(iVar6 + 8) & uVar1) * 4) + 4);

        if (iVar6 == 0) {

LAB_004d2ef8:

          this = (uint *)0x0;

        }

        else {

          do {

            if (uVar1 == *(uint *)(iVar6 + 0x10)) {

              if (iVar6 == 0) goto LAB_004d2ef8;

              this = *(uint **)(iVar6 + 8);

              goto LAB_004d2eff;

            }

            iVar6 = *(int *)(iVar6 + 0xc);

          } while (iVar6 != 0);

          this = (uint *)0x0;

        }

LAB_004d2eff:

        if ((this == (uint *)0x0) || ((short)this[0x2b] != -1)) goto LAB_004d2f13;

LAB_004d2f98:

        if ((this != (uint *)0x0) &&

           (iVar6 = CVOGCharacter_CheckMissionRequirements(this,param_2,unaff_EDI), iVar6 == 0))

        goto LAB_004d3158;

LAB_004d2fac:

        uVar8 = uVar8 + 1;

      }

    }

LAB_004d3188:

    if (!bVar4) {

      return '\0';

    }

    return '\x03';

  }

  if ((*(int *)(param_1 + 0x234) != 0) &&

     (*(int *)(param_1 + 0x238) - *(int *)(param_1 + 0x234) >> 2 != 0)) {

    iVar6 = param_2[0x150];

    iVar9 = 0;

    iVar10 = 0;

    if (*(char *)(iVar6 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar6 + 0x1d) = 1;

    do {

      iVar6 = param_2[0x150];

      if (*(char *)(iVar6 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar10 == 0) {

        iVar10 = *(int *)(iVar6 + 0x14);

      }

      else {

        iVar10 = *(int *)(iVar10 + 0x14);

      }

      if (iVar10 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(iVar10 + 8);

      }

      if (iVar6 == 0) {

        *(uint8_t *)(param_2[0x150] + 0x1d) = 0;

        iVar6 = 0;

        FUN_0053fff0();

        FUN_00402c40();

        while( true ) {

          piVar5 = (int *)FUN_0053fff0();

          iVar10 = *piVar5;

          if (*(char *)(iVar10 + 0x1d) == '\0') {

            FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

            FUN_007a4480(0,"VOG_DEBUG_STOP");

          }

          if (iVar6 == 0) {

            iVar6 = *(int *)(iVar10 + 0x14);

          }

          else {

            iVar6 = *(int *)(iVar6 + 0x14);

          }

          if (iVar6 == 0) {

            this = (uint *)0x0;

          }

          else {

            this = *(uint **)(iVar6 + 8);

          }

          if (this == (uint *)0x0) break;

          puVar2 = *(uint **)(param_1 + 0x238);

          puVar7 = *(uint **)(param_1 + 0x234);

          if (puVar7 != puVar2) {

            do {

              if (*puVar7 == (uint)*(byte *)((int)this + 0x86)) break;

              puVar7 = puVar7 + 1;

            } while (puVar7 != puVar2);

            if ((puVar7 != puVar2) &&

               (iVar10 = CVOGCharacter_CheckMissionRequirements(this,param_2,unaff_EDI), iVar10 == 0

               )) {

              bVar4 = CVOGCharacter_HasCompletedMission(param_2,*this);

              if (!bVar4) {

                piVar5 = (int *)FUN_0053fff0();

                *(uint8_t *)(*piVar5 + 0x1d) = 0;

LAB_004d3158:

                FUN_00547920(0);

                return (*(char *)((int)this + 0x169) != '\0') + '\x06';

              }

              bVar4 = true;

            }

          }

        }

        piVar5 = (int *)FUN_0053fff0();

        *(uint8_t *)(*piVar5 + 0x1d) = 0;

        goto LAB_004d3188;

      }

    } while ((*(short *)(iVar6 + 0xac) == 0) || (iVar9 = iVar9 + 1, iVar9 < 8));

    *(uint8_t *)(param_2[0x150] + 0x1d) = 0;

  }

  return '\0';

}
