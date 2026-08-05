// =============================================================================
// Named_CalleeOf_Drive_Invalid_Vehicle_Name_004f5930
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5930
// Callee of Drive_Invalid_Vehicle_Name
// Address:   0x004f5930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Invalid_Vehicle_Name: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004f5930.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Drive_Invalid_Vehicle_Name
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

longlong __thiscall Named_CalleeOf_Drive_Invalid_Vehicle_Name_004f5930(int param_1,char param_2)



{

  int iVar1;

  

  if (*(char *)(param_1 + 0x288) != param_2) {

    iVar1 = (int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1)

                                    + 0x3c) + 0x3f0);

    return (longlong)(iVar1 * iVar1);

  }

  return 0;

}
