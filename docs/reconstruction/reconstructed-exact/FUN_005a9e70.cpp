// =============================================================================
// FUN_005a9e70
// -----------------------------------------------------------------------------
// Stable ID: aa_005a9e70
// Address:   0x005a9e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a9e70 @ 0x005a9e70
// Stable ID: aa_005a9e70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005a9e70.
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

void __fastcall FUN_005a9e70(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = s_Unset_Map_name_009d87b8._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = s_Unset_Map_name_009d87b8._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = s_Unset_Map_name_009d87b8._8_4_;

  *(uint16_t *)(param_1 + 0x18) = s_Unset_Map_name_009d87b8._12_2_;

  *(char *)(param_1 + 0x1a) = s_Unset_Map_name_009d87b8[0xe];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = s_Unset_description_009d87a4._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = s_Unset_description_009d87a4._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = s_Unset_description_009d87a4._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = s_Unset_description_009d87a4._12_4_;

  *(uint16_t *)(param_1 + 0x11c) = s_Unset_description_009d87a4._16_2_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8dc) = s_Unset_Layer_name_009d8790._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8e0) = s_Unset_Layer_name_009d8790._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8e4) = s_Unset_Layer_name_009d8790._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8e8) = s_Unset_Layer_name_009d8790._12_4_;

  *(char *)(param_1 + 0x8ec) = s_Unset_Layer_name_009d8790[0x10];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9dc) = s_Unset_Layer_description_009d8778._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9e0) = s_Unset_Layer_description_009d8778._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9e4) = s_Unset_Layer_description_009d8778._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9e8) = s_Unset_Layer_description_009d8778._12_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9ec) = s_Unset_Layer_description_009d8778._16_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9f0) = s_Unset_Layer_description_009d8778._20_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x11ac) = s_Unset_Layer_name_009d8790._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x11b0) = s_Unset_Layer_name_009d8790._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x11b4) = s_Unset_Layer_name_009d8790._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x11b8) = s_Unset_Layer_name_009d8790._12_4_;

  *(char *)(param_1 + 0x11bc) = s_Unset_Layer_name_009d8790[0x10];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x12ac) = s_Unset_Layer_description_009d8778._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x12b0) = s_Unset_Layer_description_009d8778._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x12b4) = s_Unset_Layer_description_009d8778._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x12b8) = s_Unset_Layer_description_009d8778._12_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x12bc) = s_Unset_Layer_description_009d8778._16_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x12c0) = s_Unset_Layer_description_009d8778._20_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a7c) = s_Unset_Layer_name_009d8790._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a80) = s_Unset_Layer_name_009d8790._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a84) = s_Unset_Layer_name_009d8790._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a88) = s_Unset_Layer_name_009d8790._12_4_;

  *(char *)(param_1 + 0x1a8c) = s_Unset_Layer_name_009d8790[0x10];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b7c) = s_Unset_Layer_description_009d8778._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b80) = s_Unset_Layer_description_009d8778._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b84) = s_Unset_Layer_description_009d8778._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b88) = s_Unset_Layer_description_009d8778._12_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b8c) = s_Unset_Layer_description_009d8778._16_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b90) = s_Unset_Layer_description_009d8778._20_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x234c) = s_Unset_Layer_name_009d8790._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2350) = s_Unset_Layer_name_009d8790._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2354) = s_Unset_Layer_name_009d8790._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2358) = s_Unset_Layer_name_009d8790._12_4_;

  *(char *)(param_1 + 0x235c) = s_Unset_Layer_name_009d8790[0x10];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x244c) = s_Unset_Layer_description_009d8778._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2450) = s_Unset_Layer_description_009d8778._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2454) = s_Unset_Layer_description_009d8778._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2458) = s_Unset_Layer_description_009d8778._12_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x245c) = s_Unset_Layer_description_009d8778._16_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2460) = s_Unset_Layer_description_009d8778._20_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c1c) = s_Unset_Layer_name_009d8790._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c20) = s_Unset_Layer_name_009d8790._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c24) = s_Unset_Layer_name_009d8790._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c28) = s_Unset_Layer_name_009d8790._12_4_;

  *(char *)(param_1 + 0x2c2c) = s_Unset_Layer_name_009d8790[0x10];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2d1c) = s_Unset_Layer_description_009d8778._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2d20) = s_Unset_Layer_description_009d8778._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2d24) = s_Unset_Layer_description_009d8778._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2d28) = s_Unset_Layer_description_009d8778._12_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2d2c) = s_Unset_Layer_description_009d8778._16_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2d30) = s_Unset_Layer_description_009d8778._20_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34ec) = s_Unset_Layer_name_009d8790._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34f0) = s_Unset_Layer_name_009d8790._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34f4) = s_Unset_Layer_name_009d8790._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34f8) = s_Unset_Layer_name_009d8790._12_4_;

  *(char *)(param_1 + 0x34fc) = s_Unset_Layer_name_009d8790[0x10];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x35ec) = s_Unset_Layer_description_009d8778._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x35f0) = s_Unset_Layer_description_009d8778._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x35f4) = s_Unset_Layer_description_009d8778._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x35f8) = s_Unset_Layer_description_009d8778._12_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x35fc) = s_Unset_Layer_description_009d8778._16_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3600) = s_Unset_Layer_description_009d8778._20_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3dbc) = s_Unset_Layer_name_009d8790._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3dc0) = s_Unset_Layer_name_009d8790._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3dc4) = s_Unset_Layer_name_009d8790._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3dc8) = s_Unset_Layer_name_009d8790._12_4_;

  *(char *)(param_1 + 0x3dcc) = s_Unset_Layer_name_009d8790[0x10];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ebc) = s_Unset_Layer_description_009d8778._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ec0) = s_Unset_Layer_description_009d8778._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ec4) = s_Unset_Layer_description_009d8778._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ec8) = s_Unset_Layer_description_009d8778._12_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ecc) = s_Unset_Layer_description_009d8778._16_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ed0) = s_Unset_Layer_description_009d8778._20_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x468c) = s_Unset_Layer_name_009d8790._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4690) = s_Unset_Layer_name_009d8790._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4694) = s_Unset_Layer_name_009d8790._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4698) = s_Unset_Layer_name_009d8790._12_4_;

  *(char *)(param_1 + 0x469c) = s_Unset_Layer_name_009d8790[0x10];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x478c) = s_Unset_Layer_description_009d8778._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4790) = s_Unset_Layer_description_009d8778._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4794) = s_Unset_Layer_description_009d8778._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4798) = s_Unset_Layer_description_009d8778._12_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x479c) = s_Unset_Layer_description_009d8778._16_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x47a0) = s_Unset_Layer_description_009d8778._20_4_;

  return;

}
