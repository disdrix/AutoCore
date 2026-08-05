// =============================================================================
// FUN_00578b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00578b30
// Address:   0x00578b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00578b30 @ 0x00578b30
// Stable ID: aa_00578b30
// Embedded strings (evidence for future rename):
//   - "Skill %d has invalid frequency %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×10, return×2.
//  - Notable callees: CVOGHBBase_StampLastFireTime×2, CONCAT31, CVOGReaction_FailMissionNotify, FUN_004b7e50, FUN_005081d0, FUN_00518ca0, FUN_0051f880, FUN_005408f0.
//  - Strings: "Skill %d has invalid frequency %d".
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

void __fastcall FUN_00578b30(CVOGHBBase *param_1)



{

  char *pcVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  

  (*(code *)PTR_FUN_00af31e4)(param_1,0);

  piVar2 = (int *)CVOGReaction_ResolveObjectTarget

                            (CONCAT31((int3)((uint)param_1[0x28].nUnusedOrFlags >> 8),

                                      param_1[0x28].cStopped),param_1[0x28].pOwnerObject,

                             param_1[0x28].nUnusedOrFlags);

  if (param_1->pOwnerObject != (void *)0x0) {

    if ((param_1[0x27].fDormant & 0x10U) != 0) {

      pcVar1 = (char *)((int)param_1->pOwnerObject + 0x26);

      *pcVar1 = *pcVar1 + '\x01';

    }

    iVar3 = FUN_005408f0(param_1[0x27].nPeriodMs,0x16,1);

    if (iVar3 != 0) {

      iVar4 = (**(code **)(*(int *)param_1->pOwnerObject + 0x19c))();

      if (iVar4 == 0) {

        (**(code **)(*(int *)param_1->pOwnerObject + 0xf8))(iVar3,0,&param_1[0x2a].nUnusedOrFlags);

      }

      else {

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0xf8))();

      }

      CVOGReaction_FailMissionNotify(&stack0xfffffff4);

      FUN_004b7e50(0,0,0,0,0,0);

    }

  }

  if (piVar2 != (int *)0x0) {

    iVar3 = (**(code **)(*piVar2 + 0x214))();

    if ((iVar3 != 0) && ((param_1[0x27].fDormant & 2U) != 0)) {

      FUN_00518ca0(param_1[0x27].nPeriodMs,param_1[0x29].nPeriodCounter,

                   param_1[0x29].dwLastFireTickMs,param_1[0x29].pOwnerObject,

                   param_1[0x29].nUnusedOrFlags);

    }

    if (*(char *)&param_1[8].pVTable != '\0') {

      iVar3 = (**(code **)(*piVar2 + 0x210))(0);

      if (iVar3 != 0) {

        FUN_0051f880(1);

      }

    }

  }

  if ((param_1->nPeriodSentinel == -1000) && (param_1->nPeriodMs == 0)) {

    FUN_005081d0();

    CVOGHBBase_StampLastFireTime(param_1);

    return;

  }

  if ((param_1->nPeriodSentinel != 1) && ((uint)param_1->nPeriodMs < 300)) {

    FUN_007a4480(1,"Skill %d has invalid frequency %d",param_1[0x27].nPeriodMs,param_1->nPeriodMs);

    param_1->nPeriodMs = 300;

  }

  CVOGHBBase_StampLastFireTime(param_1);

  return;

}
