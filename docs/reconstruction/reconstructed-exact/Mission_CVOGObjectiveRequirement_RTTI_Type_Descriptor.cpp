// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×15, while×3, for×2, goto×2, do×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_004dbef0×3, FUN_004de760, __RTDynamicCast.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Mission_CVOGObjectiveRequirement_RTTI_Type_Descriptor
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "CVOGObjectiveRequirement_RTTI_Type_Descriptor"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004de760 clean capture (not modernized).
//
// Address:  0x004de760  (autoassault.exe, image base 0x400000)
// Stable:   aa_004de760
// Stable ID: aa_004de760
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004de760_*.md
//           Original Ghidra symbol: FUN_004de760
//
// Exactness: Body mirrors reconstructed-exact/FUN_004de760*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_CVOGObjectiveRequirement_RTTI_Type_Descriptor
// -----------------------------------------------------------------------------
// Stable ID: aa_004de760
// Address:   0x004de760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "CVOGObjectiveRequirement_RTTI_Type_Descriptor"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Mission_CVOGObjectiveRequirement_RTTI_Type_Descriptor(int param_1,uint param_2,int param_3)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  int local_8;

  

  iVar1 = param_2;

  iVar7 = *(int *)(param_2 + 0x55c);

  local_8 = 0;

  if (*(char *)(iVar7 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar7 + 0x1d) = 1;

  iVar7 = param_3;

  do {

    iVar5 = *(int *)(iVar1 + 0x55c);

    if (*(char *)(iVar5 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (local_8 == 0) {

      local_8 = *(int *)(iVar5 + 0x14);

      if (local_8 == 0) goto LAB_004de7eb;

      piVar3 = *(int **)(local_8 + 8);

    }

    else {

      local_8 = *(int *)(local_8 + 0x14);

      if (local_8 == 0) {

LAB_004de7eb:

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(local_8 + 8);

      }

    }

    if (piVar3 == (int *)0x0) {

      *(uint8_t *)(*(int *)(iVar1 + 0x55c) + 0x1d) = 0;

      return;

    }

    param_3 = 0;

    while( true ) {

      iVar5 = *piVar3;

      if (*(int *)(iVar5 + 0x158) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(iVar5 + 0x15c) - *(int *)(iVar5 + 0x158) >> 2;

      }

      if (iVar4 <= param_3) break;

      piVar6 = *(int **)(*(int *)(iVar5 + 0x158) + param_3 * 4);

      iVar5 = (**(code **)(*piVar6 + 0x50))();

      if ((iVar5 == 3) &&

         (piVar6 = (int *)__RTDynamicCast(piVar6,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,

                                          &CVOGObjectiveRequirement_Deliver::RTTI_Type_Descriptor,0)

         , piVar6[7] == *(int *)(param_1 + 0xfc))) {

        if (iVar7 == 0) {

          param_2 = 0;

          while( true ) {

            iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1) + 0xe4e8);

            if ((*(int *)(iVar5 + 0x2c) == 0) ||

               ((uint)(*(int *)(iVar5 + 0x30) - *(int *)(iVar5 + 0x2c) >> 2) <= param_2)) break;

            iVar7 = (**(code **)(**(int **)(*(int *)(iVar5 + 0x2c) + param_2 * 4) + 0x1d8))();

            if ((iVar7 == 0) ||

               (*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x34) !=

                piVar6[6])) {

LAB_004de94d:

              param_2 = param_2 + 1;

            }

            else {

              cVar2 = (**(code **)(*piVar6 + 0xc))(iVar1,piVar3);

              if (cVar2 == '\0') {

                FUN_004dbef0(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7,5,0xffffffff,0xffffffff,

                             *(uint32_t /* width from decompiler */ *)(*piVar3 + 0x10));

                goto LAB_004de94d;

              }

              FUN_004dbef0(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7,8,0xffffffff,0xffffffff,

                           *(uint32_t /* width from decompiler */ *)(*piVar3 + 0x10));

              param_2 = param_2 + 1;

            }

          }

        }

        else if (*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x34) ==

                 piVar6[6]) {

          cVar2 = (**(code **)(*piVar6 + 0xc))(iVar1,piVar3);

          if (cVar2 == '\0') {

            iVar5 = *(int *)(*(int *)(iVar7 + 4) + 4);

            uVar9 = *(uint32_t /* width from decompiler */ *)(*piVar3 + 0x10);

            uVar8 = 5;

          }

          else {

            iVar5 = *(int *)(*(int *)(iVar7 + 4) + 4);

            uVar9 = *(uint32_t /* width from decompiler */ *)(*piVar3 + 0x10);

            uVar8 = 8;

          }

          FUN_004dbef0(iVar5 + 4 + iVar7,uVar8,0xffffffff,0xffffffff,uVar9);

        }

      }

      param_3 = param_3 + 1;

    }

  } while( true );

}
