// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali_00521b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00521b40
// Callee of Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose
// Address:   0x00521b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_009733d0×3, FUN_00521b40, FUN_005858b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali_00521b40(int param_1)



{

  uint32_t /* width from decompiler */ local_34;

  uint8_t local_30 [16];

  uint8_t local_20 [16];

  uint8_t local_10 [16];

  

  if (*(int *)(param_1 + 0x48) != 0) {

    local_34 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x664);

    FUN_009733d0(&local_34);

    local_34 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x668);

    FUN_009733d0(&local_34);

    local_34 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x66c);

    FUN_009733d0(&local_34);

    FUN_005858b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x48),local_10,local_20,0,local_30,1);

  }

  return;

}
