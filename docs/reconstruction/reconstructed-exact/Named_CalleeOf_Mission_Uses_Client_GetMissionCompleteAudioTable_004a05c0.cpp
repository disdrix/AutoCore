// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_004a05c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a05c0
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x004a05c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004a05c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
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

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_004a05c0(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,

            short param_2)



{

  uint uVar1;

  

  uVar1 = 0;

  if (DAT_00b0360c != 0) {

    uVar1 = (DAT_00b03610 - DAT_00b0360c) / 0x1c;

  }

  if (uVar1 <= (uint)(int)param_2) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_1,"");

    return param_1;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

                     )(DAT_00b0360c + param_2 * 0x1c));

  return param_1;

}
