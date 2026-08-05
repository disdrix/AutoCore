// =============================================================================
// FUN_00432b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00432b60
// Address:   0x00432b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00432b60 @ 0x00432b60
// Stable ID: aa_00432b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT31×2, FUN_00432b60.
//  - Return sites: 3.

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

uint FUN_00432b60(int param_1)



{

  uint in_EAX;

  

  if (param_1 == 0) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x44) = s_null_file_handler_00a9bd10._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x48) = s_null_file_handler_00a9bd10._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x4c) = s_null_file_handler_00a9bd10._8_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x50) = s_null_file_handler_00a9bd10._12_4_;

    *(uint16_t *)(in_EAX + 0x54) = s_null_file_handler_00a9bd10._16_2_;

    return CONCAT31((int3)((uint)(in_EAX + 0x44) >> 8),1);

  }

  if (*(int *)(in_EAX + 4) == 0) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x44) = s_null_image____00a9bd00._0_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x48) = s_null_image____00a9bd00._4_4_;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x4c) = s_null_image____00a9bd00._8_4_;

    *(uint16_t *)(in_EAX + 0x50) = s_null_image____00a9bd00._12_2_;

    return CONCAT31((int3)((uint)(in_EAX + 0x44) >> 8),1);

  }

  return in_EAX & 0xffffff00;

}
