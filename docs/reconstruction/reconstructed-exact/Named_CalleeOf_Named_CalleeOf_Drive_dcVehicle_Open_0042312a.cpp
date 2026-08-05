// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Open_0042312a
// -----------------------------------------------------------------------------
// Stable ID: aa_0042312a
// Callee of Named_CalleeOf_Drive_dcVehicle_Open
// Address:   0x0042312a  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_dcVehicle_Open: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0042312a.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_dcVehicle_Open
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Open_0042312a(void)



{

  int iVar1;

  int unaff_EBP;

  int unaff_ESI;

  

  iVar1 = *(int *)(*(int *)(unaff_EBP + 8) + 0xc);

  if (iVar1 == unaff_ESI) {

    ExceptionList = *(void **)(unaff_EBP + -0xc);

    return 0x8007000e;

  }

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10) = *(uint32_t /* width from decompiler */ *)(unaff_EBP + 0xc);

  ExceptionList = *(void **)(unaff_EBP + -0xc);

  return 0;

}
