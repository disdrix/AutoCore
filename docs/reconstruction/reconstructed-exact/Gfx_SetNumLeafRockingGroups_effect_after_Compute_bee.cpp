// =============================================================================
// Gfx_SetNumLeafRockingGroups_effect_after_Compute_bee
// -----------------------------------------------------------------------------
// Stable ID: aa_006868b0
// Address:   0x006868b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_SetNumLeafRockingGroups_effect_after_Compute_bee @ 0x006868b0
// Stable ID: aa_006868b0
// Embedded strings (evidence for future rename):
//   - "SetNumLeafRockingGroups() has no effect after Compute() has been called"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: Compute, Gfx_SetNumLeafRockingGroups_effect_after_Compute_bee, SetNumLeafRockingGroups.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "SetNumLeafRockingGroups() has no effect after Compute() has been called"
 * Domain alias of FUN_006868b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Gfx_SetNumLeafRockingGroups_effect_after_Compute_bee(int *param_1,int param_2)



{

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a9dc2;

  local_10 = ExceptionList;

  local_8 = 0;

  if (*(char *)((int)param_1 + 0x45) == '\0') {

    if (param_2 == 0) {

      param_2 = 1;

    }

    *(int *)(*param_1 + 0xb0) = param_2;

    return;

  }

  ExceptionList = &local_10;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             &DAT_00d08e78,"SetNumLeafRockingGroups() has no effect after Compute() has been called"

            );

  ExceptionList = local_10;

  return;

}
