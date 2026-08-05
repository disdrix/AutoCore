// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0096f510×2, FUN_0096f530×2, FUN_00988610×2, CONCAT31, FUN_0055d670, FUN_007b6a20, FUN_007b70b0, FUN_009701d0.
//  - Strings: "UISideChannelAdd.fx"; "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBurnFilter.cpp"; "failed to load filter effect.".
//  - Return sites: 1.

// =============================================================================
// Named_VOGBurnFilter_0055d670
// -----------------------------------------------------------------------------
// Stable ID: aa_0055d670
// Address:   0x0055d670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOGBurnFilter"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_VOGBurnFilter_0055d670(void)



{

  int iVar1;

  char *pcVar2;

  uint8_t local_20 [4];

  uint8_t local_1c [8];

  uint8_t local_14 [8];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4a30;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0096f530();

  local_4 = 0;

  FUN_00988610(local_14);

  pcVar2 = "UISideChannelAdd.fx";

  FUN_007b6a20("UISideChannelAdd.fx");

  FUN_007b70b0(pcVar2);

  FUN_0096f530();

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_00989e00(local_20,"UISideChannelAdd.fx");

  FUN_009701d0(local_20);

  iVar1 = FUN_00988610(local_1c);

  if (iVar1 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBurnFilter.cpp",0xbf,3,

                   "failed to load filter effect.");

  }

  local_4 = local_4 & 0xffffff00;

  FUN_0096f510();

  local_4 = 0xffffffff;

  FUN_0096f510();

  ExceptionList = local_c;

  return;

}
