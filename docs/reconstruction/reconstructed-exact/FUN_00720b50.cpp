// =============================================================================
// FUN_00720b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00720b50
// Address:   0x00720b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00720b50 @ 0x00720b50
// Stable ID: aa_00720b50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_00720670×2, FUN_00720b50.
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

void FUN_00720b50(void)



{

  int iVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ auStack_260 [50];

  char local_190 [4];

  char local_18c [4];

  char local_188;

  uint32_t /* width from decompiler */ local_110;

  uint32_t /* width from decompiler */ local_10c;

  uint32_t /* width from decompiler */ local_108;

  uint32_t /* width from decompiler */ local_104;

  uint32_t /* width from decompiler */ local_100;

  uint32_t /* width from decompiler */ local_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint32_t /* width from decompiler */ local_f0;

  uint8_t local_ec;

  uint8_t local_eb;

  uint8_t local_ea;

  uint32_t /* width from decompiler */ local_e8;

  uint32_t /* width from decompiler */ local_e4;

  uint32_t /* width from decompiler */ local_e0;

  uint32_t /* width from decompiler */ local_dc;

  uint32_t /* width from decompiler */ local_d8;

  char local_c8 [4];

  char local_c4 [4];

  char local_c0 [120];

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint8_t local_24;

  uint8_t local_23;

  uint8_t local_22;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  

  local_190 = (char  [4])s_ominous1_00aa93d4._0_4_;

  local_d8 = 1;

  local_10 = 1;

  local_24 = 1;

  local_18c = (char  [4])s_ominous1_00aa93d4._4_4_;

  local_c4 = (char  [4])s_char_create_00a2dc28._4_4_;

  local_104 = DAT_00a110d8;

  local_100 = DAT_00a110d8;

  local_110 = DAT_00aaa8a8;

  local_108 = DAT_00aaa8a8;

  local_dc = 100;

  local_3c = DAT_00a110d8;

  local_38 = DAT_00a110d8;

  local_14 = 100;

  local_eb = 0;

  local_ea = 0;

  local_e0 = 0;

  local_e8 = 0;

  local_e4 = 0;

  local_ec = 0;

  local_188 = s_ominous1_00aa93d4[8];

  local_f8 = DAT_00aaa688;

  local_10c = 0;

  local_f4 = DAT_00aaa870;

  local_f0 = DAT_00aaa7a4;

  local_23 = 0;

  local_22 = 0;

  local_18 = 0;

  local_20 = 0;

  local_1c = 0;

  local_48 = DAT_00aaa964;

  local_40 = DAT_00aaa964;

  pcVar2 = local_190;

  puVar3 = auStack_260;

  for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *(uint32_t /* width from decompiler */ *)pcVar2;

    pcVar2 = pcVar2 + 4;

    puVar3 = puVar3 + 1;

  }

  local_30 = DAT_00aaa688;

  local_44 = 0;

  local_2c = DAT_00aaa870;

  local_28 = DAT_00a0f694;

  local_c8 = (char  [4])s_char_create_00a2dc28._0_4_;

  local_c0._0_4_ = s_char_create_00a2dc28._8_4_;

  FUN_00720670();

  pcVar2 = local_c8;

  puVar3 = auStack_260;

  for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *(uint32_t /* width from decompiler */ *)pcVar2;

    pcVar2 = pcVar2 + 4;

    puVar3 = puVar3 + 1;

  }

  FUN_00720670();

  return;

}
