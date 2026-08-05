// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_0052eb90
// -----------------------------------------------------------------------------
// Stable ID: aa_0052eb90
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
// Address:   0x0052eb90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×12, return×6, do×1, goto×1, while×1.
//  - Notable callees: FUN_004e5810×2, FUN_0052b040, FUN_0052eb90, FUN_0053e510.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_0052eb90(int param_1,int param_2)



{

  short sVar1;

  char cVar2;

  int iVar3;

  uint uVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  bool bVar8;

  float10 fVar9;

  byte local_21d;

  uint8_t local_21c [4];

  void *local_218;

  uint32_t /* width from decompiler */ local_214;

  uint32_t /* width from decompiler */ local_210;

  uint8_t local_20c [4];

  void *local_208;

  uint32_t /* width from decompiler */ local_204;

  uint32_t /* width from decompiler */ local_200;

  uint8_t local_1fc [496];

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  if ((*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) == 0) || (param_2 == 0)) {

    return 0;

  }

  if ((0 < *(int *)(param_1 + 0x6b4)) ||

     (cVar2 = FUN_0052b040(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_2 + 0xa8) + 0x3c) + 0x4ac),

                           local_1fc), cVar2 == '\0')) {

    return 1;

  }

  local_21d = 0;

  do {

    iVar3 = FUN_004e5810(local_21c);

    if (*(int *)(iVar3 + 4) == 0) {

      uVar4 = 0;

    }

    else {

      uVar4 = *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 3;

    }

    uVar7 = (uint)local_21d;

    if (local_218 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_218);

    }

    local_218 = (void *)0x0;

    local_214 = 0;

    local_210 = 0;

    if (uVar4 <= uVar7) {

      return 0;

    }

    iVar3 = FUN_004e5810(local_20c);

    piVar5 = (int *)CVOGReaction_ResolveObjectTarget

                              (0,*(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 4) + uVar7 * 8),

                               *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 4) + 4 + uVar7 * 8));

    if (local_208 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_208);

    }

    local_208 = (void *)0x0;

    local_204 = 0;

    local_200 = 0;

    if ((piVar5 != (int *)0x0) && (iVar3 = (**(code **)(*piVar5 + 0x1c8))(), iVar3 != 0)) {

      iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);

      uVar6 = (**(code **)(*piVar5 + 0x1c8))();

      (**(code **)(*(int *)(iVar3 + 4 + param_1) + 0x19c))(uVar6);

      fVar9 = (float10)FUN_0053e510(uVar6);

      if (fVar9 <= (float10)DAT_00a0f524) {

        sVar1 = *(short *)(*(int *)(piVar5[0x2a] + 0x3c) + 0x3f4);

        if (sVar1 == 0xd) {

          bVar8 = iStack_c == 0;

        }

        else if (sVar1 == 0xe) {

          bVar8 = iStack_8 == 0;

        }

        else {

          if (sVar1 != 0xf) goto LAB_0052ed3e;

          bVar8 = iStack_4 == 0;

        }

        if (!bVar8) {

          return 1;

        }

      }

    }

LAB_0052ed3e:

    local_21d = local_21d + 1;

  } while( true );

}
