// =============================================================================
// FUN_00516c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00516c40
// Address:   0x00516c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00516c40 @ 0x00516c40
// Stable ID: aa_00516c40
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×13, return×4, for×2, while×2, do×1, goto×1.
//  - Notable callees: FUN_007a4480×4, __RTDynamicCast×2, FUN_00516c40.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_00516c40(int param_1,int param_2)



{

  int iVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  uint uVar5;

  int *piVar6;

  

  iVar1 = param_2;

  if (param_2 == 0) {

    return 0;

  }

  iVar3 = *(int *)(param_2 + 0x55c);

  param_2 = 0;

  if (*(char *)(iVar3 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar3 + 0x1d) = 1;

  do {

    iVar3 = *(int *)(iVar1 + 0x55c);

    if (*(char *)(iVar3 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (param_2 == 0) {

      param_2 = *(int *)(iVar3 + 0x14);

      if (param_2 == 0) goto LAB_00516cdf;

      piVar6 = *(int **)(param_2 + 8);

    }

    else {

      param_2 = *(int *)(param_2 + 0x14);

      if (param_2 == 0) {

LAB_00516cdf:

        piVar6 = (int *)0x0;

      }

      else {

        piVar6 = *(int **)(param_2 + 8);

      }

    }

    if (piVar6 == (int *)0x0) {

      *(uint8_t *)(*(int *)(iVar1 + 0x55c) + 0x1d) = 0;

      return 0;

    }

    if (*piVar6 != 0) {

      uVar5 = 0;

      while( true ) {

        iVar3 = *(int *)(*piVar6 + 0x158);

        if ((iVar3 == 0) || ((uint)(*(int *)(*piVar6 + 0x15c) - iVar3 >> 2) <= uVar5)) break;

        piVar4 = *(int **)(iVar3 + uVar5 * 4);

        iVar3 = (**(code **)(*piVar4 + 0x50))();

        if (iVar3 == 2) {

          piVar4 = (int *)__RTDynamicCast(piVar4,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,

                                          &CVOGObjectiveRequirement_Collect::RTTI_Type_Descriptor,0)

          ;

          cVar2 = (**(code **)(*piVar4 + 0xc))(iVar1,piVar6);

          if ((cVar2 == '\0') && (*(int *)(*(int *)(param_1 + 0xa8) + 0x34) == piVar4[4])) {

            *(uint8_t *)(*(int *)(iVar1 + 0x55c) + 0x1d) = 0;

            return 1;

          }

        }

        else if (iVar3 == 3) {

          piVar4 = (int *)__RTDynamicCast(piVar4,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,

                                          &CVOGObjectiveRequirement_Deliver::RTTI_Type_Descriptor,0)

          ;

          cVar2 = (**(code **)(*piVar4 + 0xc))(iVar1,piVar6);

          if ((cVar2 == '\0') && (*(int *)(*(int *)(param_1 + 0xa8) + 0x34) == piVar4[4])) {

            *(uint8_t *)(*(int *)(iVar1 + 0x55c) + 0x1d) = 0;

            return 1;

          }

        }

        uVar5 = uVar5 + 1;

      }

    }

  } while( true );

}
