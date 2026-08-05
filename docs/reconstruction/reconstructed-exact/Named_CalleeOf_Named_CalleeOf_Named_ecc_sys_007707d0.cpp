// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_007707d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007707d0
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x007707d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_007707d0, free.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ecc_sys
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

void Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_007707d0(void)



{

  int iVar1;

  int *unaff_ESI;

  

  if (unaff_ESI[3] != 0) {

    iVar1 = 0;

    if (0 < *unaff_ESI) {

      do {

        *(uint32_t /* width from decompiler */ *)(unaff_ESI[3] + iVar1 * 4) = 0;

        iVar1 = iVar1 + 1;

      } while (iVar1 < *unaff_ESI);

    }

    free((void *)unaff_ESI[3]);

    unaff_ESI[3] = 0;

    *unaff_ESI = 0;

    unaff_ESI[1] = 0;

    unaff_ESI[2] = 0;

  }

  return;

}
