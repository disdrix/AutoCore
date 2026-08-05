// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_008e9690
// -----------------------------------------------------------------------------
// Stable ID: aa_008e9690
// Callee of Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x008e9690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_008e9290, FUN_008e9690.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_PollBoundActions
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

void Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_008e9690(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int unaff_EDI;

  

  if (unaff_EDI != 0) {

    iVar3 = 0;

    piVar4 = (int *)(param_1 + 0x5d8);

    do {

      iVar1 = *piVar4;

      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x500) != 0)) {

        if (((*(int *)(unaff_EDI + 0x160) == *(int *)(iVar1 + 0x508)) &&

            (*(int *)(unaff_EDI + 0x164) == *(int *)(iVar1 + 0x50c))) ||

           (((iVar2 = *(int *)(unaff_EDI + 0xac), iVar2 != 0 &&

             (*(int *)(iVar2 + 0x160) == *(int *)(iVar1 + 0x508))) &&

            (*(int *)(iVar2 + 0x164) == *(int *)(iVar1 + 0x50c))))) break;

      }

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 1;

    } while (iVar3 < 4);

  }

  FUN_008e9290();

  return;

}
