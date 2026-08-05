// =============================================================================
// Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d4690
// -----------------------------------------------------------------------------
// Stable ID: aa_008d4690
// Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
// Address:   0x008d4690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0075de80, FUN_008cedd0, FUN_008cf120, FUN_008d1370, FUN_008d1600, FUN_008d2840, FUN_008d4690, FUN_008d8a10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
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

void __fastcall Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d4690(int param_1)



{

  FUN_008cf120();

  FUN_008cedd0();

  *(uint8_t *)(*(int *)(param_1 + 0x568) + 0x5c0 + param_1) = 1;

  FUN_008d1600();

  FUN_008d1370();

  FUN_008d8a10(param_1);

  FUN_008d2840(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5a8),*(uint32_t /* width from decompiler */ *)(param_1 + 0x5ac),

               *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a4));

  FUN_0075de80(0,0x41200000);

  return;

}
