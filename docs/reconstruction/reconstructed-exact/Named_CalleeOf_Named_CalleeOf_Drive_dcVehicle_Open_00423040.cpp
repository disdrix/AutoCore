// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Open_00423040
// -----------------------------------------------------------------------------
// Stable ID: aa_00423040
// Callee of Named_CalleeOf_Drive_dcVehicle_Open
// Address:   0x00423040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_dcVehicle_Open: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00423040, FUN_004230a0, realloc.
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Open_00423040(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  int iVar2;

  

  if (unaff_ESI[1] == unaff_ESI[2]) {

    iVar2 = 1;

    if (unaff_ESI[2] != 0) {

      iVar2 = unaff_ESI[1] * 2;

    }

    pvVar1 = realloc((void *)*unaff_ESI,iVar2 * 0x34);

    if (pvVar1 == (void *)0x0) {

      return 0;

    }

    unaff_ESI[2] = iVar2;

    *unaff_ESI = pvVar1;

  }

  FUN_004230a0(param_1);

  unaff_ESI[1] = unaff_ESI[1] + 1;

  return 1;

}
