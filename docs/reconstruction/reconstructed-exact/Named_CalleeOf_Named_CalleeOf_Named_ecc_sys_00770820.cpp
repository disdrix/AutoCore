// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770820
// -----------------------------------------------------------------------------
// Stable ID: aa_00770820
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00770820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00770820.
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

void Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770820(void)



{

  int *in_EAX;

  int iVar1;

  

  iVar1 = *in_EAX;

  if (0 < iVar1) {

    do {

      if (*(int *)(in_EAX[3] + -4 + *in_EAX * 4) != 0) break;

      iVar1 = *in_EAX + -1;

      *in_EAX = iVar1;

    } while (0 < iVar1);

    iVar1 = *in_EAX;

  }

  if (iVar1 == 0) {

    in_EAX[2] = 0;

  }

  return;

}
