// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: vog_LogMessage×2, FUN_0048ed00, FUN_0048f370, FUN_0048fc90, FUN_004982d0, FUN_004c0640, FUN_004c2080, FUN_0055c8c0.
//  - Strings: ",0xad,3,

                     "; ",0xbb,3,

                     "; "NDRiver.fx".
//  - Return sites: 1.

// =============================================================================
// Drive_NDRiver_fx
// -----------------------------------------------------------------------------
// Stable ID: aa_0048fc90
// Address:   0x0048fc90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "NDRiver.fx"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Drive_NDRiver_fx(int param_1,void *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a08ac;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00756320(param_2);

  FUN_0048f370();

  FUN_0048ed00();

  if (DAT_00b04808 == (int *)0x0) {

    param_2 = operator_new(0x20);

    local_4 = 0;

    if (param_2 == (void *)0x0) {

      DAT_00b04808 = (int *)0x0;

    }

    else {

      DAT_00b04808 = (int *)FUN_005769c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc0));

    }

    local_4 = 0xffffffff;

    DAT_00b0480c = param_1;

    (**(code **)(*DAT_00b04808 + 0x20))();

    iVar1 = FUN_00576860();

    if (iVar1 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentSector.cpp",0xad,3,

                     "Water phase initialization failed");

    }

  }

  if (DAT_00b04818 == (int *)0x0) {

    param_2 = operator_new(0x18);

    local_4 = 1;

    if (param_2 == (void *)0x0) {

      DAT_00b04818 = (int *)0x0;

    }

    else {

      DAT_00b04818 = (int *)FUN_00576ed0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc0));

    }

    local_4 = 0xffffffff;

    DAT_00b0481c = param_1;

    (**(code **)(*DAT_00b04818 + 0x20))();

    iVar1 = FUN_00576d70();

    if (iVar1 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentSector.cpp",0xbb,3,

                     "Distort phase initialization failed");

    }

  }

  param_2 = operator_new(0x170);

  local_4 = 2;

  if (param_2 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_005b35a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8));

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = uVar2;

  FUN_005b39a0(1);

  param_2 = operator_new(0xa0);

  local_4 = 3;

  if (param_2 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0055c8c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8));

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 200) = uVar2;

  FUN_0055cc50(1);

  param_2 = operator_new(200);

  local_4 = 4;

  if (param_2 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_004c0640(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8));

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc) = uVar2;

  FUN_004c2080(1);

  FUN_004982d0();

  FUN_0096f530();

  local_4 = 5;

  FUN_00989e00(&param_2,"NDRiver.fx");

  FUN_009701d0(&param_2);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = 0;

  local_4 = 0xffffffff;

  FUN_0096f510();

  ExceptionList = pvStack_c;

  return 0;

}
