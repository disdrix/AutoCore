// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00787a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00787a30
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00787a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00787a30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_00787a30(void)



{

  int unaff_ESI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1004) = 0;

  if (*(void **)(unaff_ESI + 0x1008) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0x1008));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1008) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x100c) = 0;

  if ((*(char *)(unaff_ESI + 0x1010) != '\0') && (*(void **)(unaff_ESI + 0x1014) != (void *)0x0)) {

    operator_delete__(*(void **)(unaff_ESI + 0x1014));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1014) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1018) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x101c) = 0;

  *(uint8_t *)(unaff_ESI + 0x1010) = 0;

  *(uint8_t *)(unaff_ESI + 0x1030) = 1;

  return;

}
