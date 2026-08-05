// =============================================================================
// Named_CalleeOf_Drive_NDRiver_fx_0048ed00
// -----------------------------------------------------------------------------
// Stable ID: aa_0048ed00
// Callee of Drive_NDRiver_fx
// Address:   0x0048ed00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0096f0e0×2, FUN_0048ed00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_NDRiver_fx
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

void __fastcall Named_CalleeOf_Drive_NDRiver_fx_0048ed00(int param_1)



{

  int local_8;

  int local_4;

  

  FUN_0096f0e0(0x15,*(int *)(DAT_00d1f058 + 0x2c) + 0x80,1,0x4011,0,param_1 + 0xd4);

  local_4 = *(int *)(*(int *)(DAT_00d1f058 + 0x2c) + 0x84) / 2;

  local_8 = *(int *)(*(int *)(DAT_00d1f058 + 0x2c) + 0x80) / 2;

  FUN_0096f0e0(0x15,&local_8,1,0x4011,0,0);

  return;

}
