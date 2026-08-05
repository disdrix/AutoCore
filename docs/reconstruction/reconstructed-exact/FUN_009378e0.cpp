// =============================================================================
// FUN_009378e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009378e0
// Address:   0x009378e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009378e0 @ 0x009378e0
// Stable ID: aa_009378e0
// Embedded strings (evidence for future rename):
//   - "%s: %.5f, %.1f%% \t^%.5f, v%.5f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: ROUND×2, CONCAT11, CONCAT13, CONCAT21, CONCAT31, CONCAT44, FUN_0040aef0, FUN_00759730.
//  - Strings: "%s: %.5f, %.1f%% \t^%.5f, v%.5f".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_009378e0(char *param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ extraout_ECX;

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int unaff_EDI;

  uint64_t local_48;

  double local_40;

  double local_38;

  double local_30;

  uint32_t /* width from decompiler */ local_1c;

  float local_18;

  uint8_t *local_14;

  uint8_t *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2c9d;

  local_c = ExceptionList;

  iVar2 = 0x18;

  if (DAT_00d1e7ec != 0) {

    iVar2 = *(int *)(DAT_00d1e7ec + 0x7c) + 2;

  }

  local_1c = g_flOne;

  if (*(float *)(DAT_00d09874 + 0x30) != g_flZero) {

    local_1c = *(float *)(DAT_00d09874 + 0x30 + param_2 * 4) / *(float *)(DAT_00d09874 + 0x30);

  }

  local_18 = *(float *)(DAT_00d09874 + 0x30 + param_2 * 4);

  local_30 = (double)*(float *)(DAT_00d09874 + 0x110 + param_2 * 4);

  local_38 = (double)*(float *)(DAT_00d09874 + 0xd8 + param_2 * 4);

  local_40 = (double)(local_1c * DAT_00aaa7ac);

  local_48 = (double)local_18;

  ExceptionList = &local_c;

  sprintf(param_1,"%s: %.5f, %.1f%% \t^%.5f, v%.5f",param_3);

  uVar1 = extraout_ECX;

  if (DAT_00a10e78 < local_1c) {

    local_18 = local_1c * _DAT_00aaaa30;

    local_14._0_1_ = (char)(int)ROUND(local_18);

    uVar1 = CONCAT31((int3)((uint)extraout_ECX >> 8),-0x40 - (char)local_14);

    local_10._0_1_ = (char)(int)ROUND(local_1c * _DAT_00a14018);

    local_1c = (float)CONCAT13(0xff,CONCAT21(CONCAT11(0xff,-0x40 - (char)local_14),

                                             -0x80 - (char)local_10));

    param_4 = &local_1c;

  }

  local_30 = 1.0210135990277448e-304;

  local_38 = 2.12199579096527e-314;

  local_40 = 2.12199579047121e-314;

  local_10 = (uint8_t *)&local_48;

  local_14 = (uint8_t *)&local_48;

  local_48 = (double)CONCAT44(param_1,uVar1);

  FUN_0040aef0(&local_48);

  local_4 = 0xffffffff;

  FUN_00759730(*(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x2c),unaff_EDI,param_4);

  *(int *)(unaff_EDI + 4) = *(int *)(unaff_EDI + 4) + iVar2;

  ExceptionList = local_c;

  return;

}
