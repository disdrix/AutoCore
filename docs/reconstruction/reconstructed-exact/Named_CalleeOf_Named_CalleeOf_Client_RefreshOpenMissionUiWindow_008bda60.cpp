// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008bda60
// -----------------------------------------------------------------------------
// Stable ID: aa_008bda60
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
// Address:   0x008bda60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_008bd580, FUN_008bda60.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008bda60(void)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  int unaff_EDI;

  

  piVar4 = (int *)(unaff_EDI + 0x56c);

  iVar3 = 0;

  do {

    if (*(int *)(unaff_EDI + 0x550) == 0) {

      uVar1 = 0;

    }

    else {

      uVar1 = *(int *)(unaff_EDI + 0x554) - *(int *)(unaff_EDI + 0x550) >> 2;

    }

    uVar2 = *(int *)(unaff_EDI + 0x548) + iVar3;

    if (uVar2 < uVar1) {

      FUN_008bd580(iVar3,*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x550) + uVar2 * 4));

    }

    else {

      if (piVar4[-4] != 0) {

        (**(code **)(*(int *)piVar4[-4] + 4))(0);

      }

      if (*piVar4 != 0) {

        (**(code **)(*(int *)*piVar4 + 4))(0);

      }

      if (piVar4[4] != 0) {

        (**(code **)(*(int *)piVar4[4] + 4))(0);

      }

      if (piVar4[8] != 0) {

        (**(code **)(*(int *)piVar4[8] + 4))(0);

      }

      if (piVar4[0xc] != 0) {

        (**(code **)(*(int *)piVar4[0xc] + 4))(0);

      }

    }

    iVar3 = iVar3 + 1;

    piVar4 = piVar4 + 1;

  } while (iVar3 < 4);

  return;

}
