// =============================================================================
// FUN_00607f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00607f90
// Address:   0x00607f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00607f90 @ 0x00607f90
// Stable ID: aa_00607f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_0041b0b0×2, FUN_007c3650×2, CONCAT31, FUN_00518940, FUN_005c7f30, FUN_00607f90, FUN_007b7df0, FUN_007e1d80.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00607f90(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  float fVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a81d3;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009debf8;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_005c7f30(0);

  *param_1 = &PTR_FUN_009debb4;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009de8ec;

  local_4 = 1;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x25c;

  _eh_vector_constructor_iterator_(param_1 + 0x2c,0x48,4,FUN_006089c0,FUN_00608a10);

  param_1[0x8a] = 0;

  param_1[0x8b] = 0;

  param_1[0x8c] = 0;

  fVar2 = g_flOne;

  param_1[0x75] = s_Unnamed_009debf0._0_4_;

  uVar1 = s_Unnamed_009debf0._4_4_;

  param_1[0x87] = fVar2;

  param_1[0x86] = DAT_00a1109c;

  param_1[0x76] = uVar1;

  local_4 = CONCAT31(local_4._1_3_,3);

  param_1[0x8d] = 0xffffffff;

  param_1[0x8e] = 0;

  param_1[0x8f] = 0;

  param_1[0x90] = 0;

  param_1[0x91] = 0;

  param_1[0x92] = 0;

  param_1[0x74] = 0xffffffff;

  param_1[0x93] = 0;

  *(uint8_t *)(param_1 + 0x88) = 1;

  puVar3 = param_1 + 0x3d;

  iVar4 = 4;

  do {

    puVar3[-1] = 0xffffffff;

    *(uint8_t *)puVar3 = 0;

    puVar3 = puVar3 + 0x12;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  if ((DAT_00d029e4 == 0) || (DAT_00d029e8 - DAT_00d029e4 >> 4 == 0)) {

    FUN_007e1d80();

    FUN_007c3650(&DAT_00d029e0,1);

    FUN_007c3650(&DAT_00d029f0,0);

    FUN_007b7df0();

    if ((DAT_00d029e4 == 0) || (DAT_00d029e8 - DAT_00d029e4 >> 4 == 0)) {

      local_1c = 0;

      local_18 = 0;

      local_14 = 0;

      local_10 = 0;

      FUN_0041b0b0(&local_1c);

    }

    if ((DAT_00d029f4 == 0) || (DAT_00d029f8 - DAT_00d029f4 >> 4 == 0)) {

      local_1c = 0;

      local_18 = 0;

      local_14 = 0;

      local_10 = 0;

      FUN_0041b0b0(&local_1c);

    }

  }

  ExceptionList = local_c;

  return param_1;

}
