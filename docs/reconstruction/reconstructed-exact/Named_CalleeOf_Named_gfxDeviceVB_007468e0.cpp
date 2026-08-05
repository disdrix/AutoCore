// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_007468e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007468e0
// Callee of Named_gfxDeviceVB (+1 other named callers)
// Address:   0x007468e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxDeviceVB (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_007468e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB (+1 other named callers)
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

int __thiscall Named_CalleeOf_Named_gfxDeviceVB_007468e0(int param_1,char param_2,char param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  while( true ) {

    if (iVar1 == *(int *)(param_1 + 8)) {

      return 0;

    }

    if ((*(char *)(iVar1 + 6) == param_2) && (*(char *)(iVar1 + 7) == param_3)) break;

    iVar1 = iVar1 + 8;

  }

  return iVar1;

}
