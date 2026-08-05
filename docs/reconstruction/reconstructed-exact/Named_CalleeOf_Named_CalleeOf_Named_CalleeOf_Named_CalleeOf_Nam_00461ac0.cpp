// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00461ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00461ac0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice
// Address:   0x00461ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00461ac0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00461ac0(void)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  *unaff_EDI = *unaff_ESI;

  unaff_EDI[1] = unaff_ESI[1];

  unaff_EDI[2] = unaff_ESI[2];

  unaff_EDI[3] = unaff_ESI[3];

  piVar1 = (int *)unaff_ESI[4];

  if ((piVar1 != (int *)0x0) && (piVar1[1] = piVar1[1] + 1, piVar1[1] == 1)) {

    (**(code **)(*piVar1 + 4))();

  }

  unaff_EDI[4] = unaff_ESI[4];

  *(uint8_t *)(unaff_EDI + 5) = *(uint8_t *)(unaff_ESI + 5);

  *(uint8_t *)((int)unaff_EDI + 0x15) = *(uint8_t *)((int)unaff_ESI + 0x15);

  *(uint8_t *)((int)unaff_EDI + 0x16) = *(uint8_t *)((int)unaff_ESI + 0x16);

  unaff_EDI[6] = unaff_ESI[6];

  return;

}
