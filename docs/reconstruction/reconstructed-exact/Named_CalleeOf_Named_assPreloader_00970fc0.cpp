// =============================================================================
// Named_CalleeOf_Named_assPreloader_00970fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00970fc0
// Callee of Named_assPreloader
// Address:   0x00970fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPreloader: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_0043e850×2, FUN_0043d6f0, FUN_0043d700, FUN_0043d770, FUN_00970fc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assPreloader
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

void Named_CalleeOf_Named_assPreloader_00970fc0(void)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char local_c;

  

  FUN_0043d6f0();

  cVar1 = FUN_0043e850();

  while (cVar1 != '\0') {

    if (local_c == '\0') {

      FUN_0043d770();

    }

    else {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_0043d700();

      *puVar2 = 1;

    }

    cVar1 = FUN_0043e850();

  }

  return;

}
