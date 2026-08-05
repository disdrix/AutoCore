// =============================================================================
// Named_CalleeOf_Named_Starting_ShutDown_on_Client_00754090
// -----------------------------------------------------------------------------
// Stable ID: aa_00754090
// Callee of Named_Starting_ShutDown_on_Client
// Address:   0x00754090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Starting_ShutDown_on_Client: callee helper. Evidence string: "Palantir::SetClientSize() - Client size changed from (%i,%i) to (%i,%i); reset required\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Palantir::SetClientSize() - Client size changed from (%i,%i) to (%i,%i); reset required\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00754090, FUN_0076c130, Palantir::SetClientSize, from, to.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Starting_ShutDown_on_Client
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_Starting_ShutDown_on_Client_00754090(void)



{

  int unaff_ESI;

  int *unaff_EDI;

  

  if (*(char *)(unaff_ESI + 4) == '\0') {

    return 0xffffffff;

  }

  if ((*unaff_EDI != *(int *)(unaff_ESI + 8)) || (unaff_EDI[1] != *(int *)(unaff_ESI + 0xc))) {

    FUN_0076c130("Palantir::SetClientSize() - Client size changed from (%i,%i) to (%i,%i); reset required\n"

                 ,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc),*unaff_EDI,

                 unaff_EDI[1]);

    *(int *)(unaff_ESI + 8) = *unaff_EDI;

    *(int *)(unaff_ESI + 0xc) = unaff_EDI[1];

    (**(code **)(**(int **)(unaff_ESI + 0x2c) + 8))();

    *(uint8_t *)(unaff_ESI + 6) = 1;

  }

  return 0;

}
