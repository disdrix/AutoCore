// =============================================================================
// Named_CalleeOf_Named_gfxDevice_009686e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009686e0
// Callee of Named_gfxDevice
// Address:   0x009686e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_009686e0, FUN_0096c8e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice
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

void Named_CalleeOf_Named_gfxDevice_009686e0(void)



{

  int *piVar1;

  int *piVar2;

  

  piVar2 = (int *)*DAT_00d1ee30;

  piVar1 = DAT_00d1ee30;

  if (piVar2 != DAT_00d1ee30) {

    do {

      if ((piVar2[2] != 0) && (*(int *)(*(int *)(piVar2[2] + 0x44) + 0x30) == 0)) {

        FUN_0096c8e0();

        piVar1 = DAT_00d1ee30;

      }

      piVar2 = (int *)*piVar2;

    } while (piVar2 != piVar1);

  }

  return;

}
