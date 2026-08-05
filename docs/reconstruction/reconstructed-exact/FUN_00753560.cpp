// =============================================================================
// FUN_00753560
// -----------------------------------------------------------------------------
// Stable ID: aa_00753560
// Address:   0x00753560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753560 @ 0x00753560
// Stable ID: aa_00753560
// Embedded strings (evidence for future rename):
//   - "NormalizingCubeMap"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, switch×1, goto×1.
//  - Notable callees: FUN_0096f3e0×3, FUN_0043ef70×2, FUN_0096efd0×2, CONCAT31, FUN_007528f0, FUN_00753560, strstr.
//  - Strings: "NormalizingCubeMap".
//  - Return sites: 4.

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

int __thiscall FUN_00753560(uint32_t /* width from decompiler */ param_1,int param_2,int param_3)



{

  int iVar1;

  char *pcVar2;

  undefined **appuStack_64 [4];

  uint32_t /* width from decompiler */ uStack_54;

  uint8_t local_38 [4];

  char *pcStack_34;

  uint32_t /* width from decompiler */ local_2c;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1b9a;

  local_c = ExceptionList;

  if (param_3 < 0) {

    return -1;

  }

  iVar1 = *(int *)(param_2 + 8);

  if (*(int *)(iVar1 + 0xc) == 0) {

    iVar1 = -0x7789f794;

    ExceptionList = &local_c;

  }

  else {

    ExceptionList = &local_c;

    iVar1 = (**(code **)(**(int **)(iVar1 + 0xc) + 0x10))

                      (*(int **)(iVar1 + 0xc),*(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x10) + param_3 * 8),

                       local_38);

  }

  iVar1 = (-1 < iVar1) - 1;

  if (iVar1 < 0) {

    ExceptionList = local_c;

    return iVar1;

  }

  local_4 = 0;

  switch(local_2c) {

  case 5:

  case 7:

    iVar1 = FUN_0096f3e0(param_1,0);

    break;

  default:

    local_4 = 0xffffffff;

    FUN_0096efd0();

    ExceptionList = local_c;

    return -1;

  case 8:

    FUN_0043ef70();

    local_4._0_1_ = 2;

    uStack_54 = 0x104;

    iVar1 = FUN_0096f3e0(param_1,appuStack_64);

    local_4 = (uint)local_4._1_3_ << 8;

    appuStack_64[0] = &PTR_LAB_009caeb8;

    break;

  case 9:

    FUN_0043ef70();

    local_4 = CONCAT31(local_4._1_3_,1);

    if (pcStack_34 == (char *)0x0) {

LAB_00753628:

      uStack_54 = 0x102;

    }

    else {

      pcVar2 = strstr(pcStack_34,"NormalizingCubeMap");

      uStack_54 = 2;

      if (pcVar2 == (char *)0x0) goto LAB_00753628;

    }

    iVar1 = FUN_0096f3e0(param_1,appuStack_64);

    local_4 = local_4 & 0xffffff00;

  }

  if (-1 < iVar1) {

    iVar1 = FUN_007528f0(param_3,0);

  }

  local_4 = 0xffffffff;

  FUN_0096efd0();

  ExceptionList = local_c;

  return iVar1;

}
