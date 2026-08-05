// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e5ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e5ce0
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
// Address:   0x008e5ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, while×1.
//  - Notable callees: FUN_00571010×2, FUN_008e5990×2, CVOGReaction_ResolveObjectTarget, FUN_00522000, FUN_008e5ce0.
//  - Return sites: 4.

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

void Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e5ce0(uint32_t /* width from decompiler */ param_1,uint param_2,uint param_3)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  

  if ((param_2 & param_3) == 0xffffffff) {

    FUN_008e5990(0);

    return;

  }

  if (DAT_00d1b6d8 != 0) {

    iVar3 = 0;

    if (((((*(int *)(DAT_00d1b6d8 + 0x250) == 0) ||

          (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) == 0)) ||

         (iVar3 = FUN_00571010(param_2,param_3), iVar3 == 0)) ||

        ((*(uint *)(iVar3 + 0x17c) >> 0x13 & 1) == 0)) &&

       ((*(int *)(DAT_00d1b6d8 + 0xcbc) != 0 && (*(char *)(DAT_00d1b644 + 0xf5) != '\0')))) {

      iVar3 = FUN_00571010(param_2,param_3);

    }

    if ((iVar3 == 0) || ((*(uint *)(iVar3 + 0x17c) >> 0x13 & 1) == 0)) {

      iVar3 = FUN_00522000();

      uVar4 = 0;

      if (iVar3 < 1) {

        return;

      }

      while( true ) {

        uVar1 = *(uint *)(DAT_00d1b6d8 + 0x5a0 + (uVar4 & 0xff) * 8);

        uVar2 = *(uint *)(DAT_00d1b6d8 + 0x5a4 + (uVar4 & 0xff) * 8);

        if ((((uVar1 & uVar2) != 0xffffffff) && (uVar1 == param_2)) && (uVar2 == param_3)) break;

        uVar4 = uVar4 + 1;

        if (iVar3 <= (int)uVar4) {

          return;

        }

      }

      iVar3 = CVOGReaction_ResolveObjectTarget(1,uVar1,uVar2);

    }

    if (iVar3 != 0) {

      FUN_008e5990(iVar3);

    }

  }

  return;

}
