// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_0047a370
// -----------------------------------------------------------------------------
// Stable ID: aa_0047a370
// Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
// Address:   0x0047a370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0047a370.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_0047a370(void)



{

  int iVar1;

  int unaff_ESI;

  

  if (((unaff_ESI != 0) && (*(int *)(unaff_ESI + 0x1c) != 0)) &&

     (*(code **)(unaff_ESI + 0x24) != (code *)0x0)) {

    iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1c) + 0x2c);

    if (iVar1 != 0) {

      (**(code **)(unaff_ESI + 0x24))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28),iVar1);

    }

    (**(code **)(unaff_ESI + 0x24))

              (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c));

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

    return 0;

  }

  return 0xfffffffe;

}
