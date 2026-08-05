// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770440
// -----------------------------------------------------------------------------
// Stable ID: aa_00770440
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00770440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: FUN_00770440, malloc.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00770440(void)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  pvVar1 = malloc(0x100);

  unaff_ESI[3] = pvVar1;

  if (pvVar1 == (void *)0x0) {

    return 0xfffffffe;

  }

  iVar2 = 0;

  do {

    *(uint32_t /* width from decompiler */ *)(iVar2 + unaff_ESI[3]) = 0;

    iVar2 = iVar2 + 4;

  } while (iVar2 < 0x100);

  *unaff_ESI = 0;

  unaff_ESI[1] = 0x40;

  unaff_ESI[2] = 0;

  return 0;

}
