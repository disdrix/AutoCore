// =============================================================================
// Named_CalleeOf_Mission_Received_Arranged_Connect_Request_0042c540
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c540
// Callee of Mission_Received_Arranged_Connect_Request
// Address:   0x0042c540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Received_Arranged_Connect_Request: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, return×2, do×1.
//  - Notable callees: FUN_0042c540.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_Received_Arranged_Connect_Request
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

void __fastcall Named_CalleeOf_Mission_Received_Arranged_Connect_Request_0042c540(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint uVar3;

  int unaff_EDI;

  

  uVar3 = 0;

  if (0 < *(int *)(unaff_EDI + 0x24)) {

    piVar2 = *(int **)(unaff_EDI + 0x2c);

    while ((int *)*piVar2 != param_1) {

      uVar3 = uVar3 + 1;

      piVar2 = piVar2 + 1;

      if (*(int *)(unaff_EDI + 0x24) <= (int)uVar3) {

        return;

      }

    }

    piVar2 = param_1 + 2;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*param_1 + 8))();

    }

    if (uVar3 < *(int *)(unaff_EDI + 0x24) - 1U) {

      do {

        puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x2c) + uVar3 * 4);

        *puVar1 = puVar1[1];

        uVar3 = uVar3 + 1;

      } while (uVar3 < *(int *)(unaff_EDI + 0x24) - 1U);

    }

    *(int *)(unaff_EDI + 0x24) = *(int *)(unaff_EDI + 0x24) + -1;

  }

  return;

}
