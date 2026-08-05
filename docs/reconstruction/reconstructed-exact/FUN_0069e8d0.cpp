// =============================================================================
// FUN_0069e8d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0069e8d0
// Address:   0x0069e8d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069e8d0 @ 0x0069e8d0
// Stable ID: aa_0069e8d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0069e8d0.
//  - Return sites: 1.

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

uint8_t * __fastcall FUN_0069e8d0(uint8_t *param_1)



{

  *param_1 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0x3f4ccccd;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0x3f4ccccd;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0x3f4ccccd;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0x3e4ccccd;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_1 + 0x14));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0x3f000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0x3df5c28f;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0x3df5c28f;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0x41200000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0x41200000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  return param_1;

}
