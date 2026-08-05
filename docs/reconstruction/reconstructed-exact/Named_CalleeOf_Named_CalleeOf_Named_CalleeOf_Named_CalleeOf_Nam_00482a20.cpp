// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00482a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00482a20
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x00482a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_00482a20.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00482a20(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int unaff_ESI;

  int unaff_EDI;

  

  iVar1 = 0;

  iVar3 = 0x100;

  do {

    iVar2 = iVar3 + iVar1 >> 1;

    if (*(int *)(unaff_ESI + iVar2 * 4) <= unaff_EDI) {

      iVar1 = iVar2;

      iVar2 = iVar3;

    }

    iVar3 = iVar2;

  } while (iVar2 - iVar1 != 1);

  return;

}
