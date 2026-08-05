// =============================================================================
// FUN_00687320
// -----------------------------------------------------------------------------
// Stable ID: aa_00687320
// Address:   0x00687320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00687320 @ 0x00687320
// Stable ID: aa_00687320
// Embedded strings (evidence for future rename):
//   - "GetBoundingBox() expects a non-NULL parameter"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00687320, GetBoundingBox.
//  - Strings: "GetBoundingBox() expects a non-NULL parameter".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_00687320(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x40);

    *param_2 = *puVar1;

    param_2[1] = puVar1[1];

    param_2[2] = puVar1[2];

    param_2[3] = puVar1[3];

    param_2[4] = puVar1[4];

    param_2[5] = puVar1[5];

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x0068735d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             &DAT_00d08e78,"GetBoundingBox() expects a non-NULL parameter");

  return;

}
