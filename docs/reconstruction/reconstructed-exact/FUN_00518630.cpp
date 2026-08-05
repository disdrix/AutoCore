// =============================================================================
// FUN_00518630
// -----------------------------------------------------------------------------
// Stable ID: aa_00518630
// Address:   0x00518630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00518630 @ 0x00518630
// Stable ID: aa_00518630
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×13, for×3, while×2, return×2, do×1.
//  - Notable callees: FUN_007a4480×4, FUN_004c3f10×2, FUN_004073a0, FUN_004d0e90, FUN_00518630, Object_ResolveFromTFID.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
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

void __thiscall FUN_00518630(int param_1,int param_2,char param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  byte *pTfid;

  uint uVar5;

  int *piVar6;

  int *piVar7;

  int *piVar8;

  uint uVar9;

  uint uStack_3c;

  int iStack_38;

  int iStack_34;

  int iStack_30;

  void *apvStack_20 [2];

  int *piStack_18;

  int *piStack_14;

  int iStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a35b4;

  local_c = ExceptionList;

  piVar8 = (int *)0x0;

  if ((*(int **)(param_1 + 0xac) != (int *)0x0) &&

     (ExceptionList = &local_c, iVar2 = (**(code **)(**(int **)(param_1 + 0xac) + 0x214))(),

     iVar2 != 0)) {

    iVar1 = *(int *)(param_1 + 0x70);

    piVar6 = (int *)0x0;

    uStack_3c = 0;

    iStack_38 = 0;

    iStack_30 = 0;

    piStack_18 = (int *)0x0;

    piStack_14 = (int *)0x0;

    iStack_10 = 0;

    uStack_4 = 0;

    if (*(char *)(iVar1 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar1 + 0x1d) = 1;

    while( true ) {

      if (*(char *)(iVar1 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iStack_38 == 0) {

        iStack_38 = *(int *)(iVar1 + 0x14);

      }

      else {

        iStack_38 = *(int *)(iStack_38 + 0x14);

      }

      if (iStack_38 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(iStack_38 + 8);

      }

      if (iVar3 == 0) break;

      uStack_3c = (uint)*(byte *)(iVar3 + 0xda);

      if (uStack_3c != 0) {

        iVar3 = *(int *)(iVar3 + 0x14c);

        uVar9 = 0;

        iVar4 = FUN_004c3f10(1);

        if (iVar4 != 0) {

          iStack_34 = 0;

          do {

            iVar4 = *(int *)(iVar2 + 0x1bc);

            if ((iVar4 == 0) || ((uint)(*(int *)(iVar2 + 0x1c0) - iVar4 >> 4) <= uVar9)) {

              pTfid = g_abTfidInvalid_9CDF88;

            }

            else {

              pTfid = (byte *)(iVar4 + iStack_34);

            }

            apvStack_20[0] = Object_ResolveFromTFID((TFID_16 *)pTfid);

            if ((apvStack_20[0] != (void *)0x0) &&

               (*(int *)(*(int *)((int)apvStack_20[0] + 0xa8) + 0x34) == iVar3)) {

              if ((piVar6 == (int *)0x0) ||

                 ((uint)(iStack_10 - (int)piVar6 >> 2) <= (uint)((int)piVar8 - (int)piVar6 >> 2))) {

                FUN_004073a0(piVar8,1,apvStack_20);

                piVar6 = piStack_18;

                piVar8 = piStack_14;

              }

              else {

                *piVar8 = (int)apvStack_20[0];

                piStack_14 = piVar8 + 1;

                piVar8 = piStack_14;

              }

            }

            iStack_34 = iStack_34 + 0x10;

            uVar9 = uVar9 + 1;

            uVar5 = FUN_004c3f10(1);

          } while (uVar9 < uVar5);

        }

      }

    }

    *(uint8_t *)(iVar1 + 0x1d) = 0;

    if (piVar6 != (int *)0x0) {

      uVar9 = (int)piVar8 - (int)piVar6 >> 2;

      piVar7 = piVar6;

      if ((uVar9 != 0) && ((param_3 == '\0' || (uStack_3c <= uVar9)))) {

        for (; (piVar6 != piVar8 && (piVar7 = piStack_18, iStack_30 < param_2));

            iStack_30 = iStack_30 + 1) {

          iVar2 = *piVar6;

          *(uint32_t /* width from decompiler */ *)(iVar2 + 0xcc) = param_4;

          FUN_004d0e90(iVar2);

          piVar6 = piVar6 + 1;

          piVar7 = piStack_18;

        }

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar7);

    }

  }

  ExceptionList = local_c;

  return;

}
