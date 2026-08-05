// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00721250
// -----------------------------------------------------------------------------
// Stable ID: aa_00721250
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x00721250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0071aef0, FUN_00720630, FUN_00721250.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

void Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00721250(void)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EDI;

  

  *(uint8_t *)(unaff_EDI + 0x10) = 0;

  if (*(int *)(unaff_EDI + 0x188) == 0) {

    puVar2 = operator_new(0x10);

    if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar2[1] = 0;

      puVar2[2] = 0;

      *puVar2 = &PTR_FUN_00aa93cc;

      *(uint8_t *)(puVar2 + 3) = 0;

    }

    *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x188) = puVar2;

    cVar1 = FUN_0071aef0();

    if (cVar1 != '\0') {

      FUN_00720630();

      return;

    }

  }

  return;

}
