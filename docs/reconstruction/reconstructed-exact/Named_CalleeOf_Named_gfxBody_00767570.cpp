// =============================================================================
// Named_CalleeOf_Named_gfxBody_00767570
// -----------------------------------------------------------------------------
// Stable ID: aa_00767570
// Callee of Named_gfxBody
// Address:   0x00767570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004362c0, FUN_00767570.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxBody
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

bool Named_CalleeOf_Named_gfxBody_00767570(void)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint *unaff_EDI;

  

  uVar1 = *unaff_EDI;

  if (uVar1 == 0) {

    return false;

  }

  uVar3 = unaff_EDI[2];

  uVar2 = 0;

  if (uVar1 != 0) {

    uVar3 = uVar3 + (uVar1 >> 5) * 4;

    uVar2 = uVar1 & 0x1f;

  }

  uVar1 = *(uint *)(uVar3 + (uVar2 - 1 >> 5) * 4);

  FUN_004362c0(0);

  return (uVar1 & 1 << ((byte)(uVar2 - 1) & 0x1f)) != 0;

}
