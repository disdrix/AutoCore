// =============================================================================
// FUN_00739420
// -----------------------------------------------------------------------------
// Stable ID: aa_00739420
// Address:   0x00739420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00739420 @ 0x00739420
// Stable ID: aa_00739420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_00414b60×2, FUN_00414c20, FUN_004451c0, FUN_0044bbc0, FUN_00738bc0, FUN_00739420, FUN_00746b00.
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

uint32_t /* width from decompiler */ __thiscall FUN_00739420(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  undefined **local_2c;

  int *local_28;

  uint8_t local_24 [24];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2e44;

  local_c = ExceptionList;

  if (*(int *)(param_2 + 0x14) == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(*(int *)(param_2 + 0x14) + 0x18);

  }

  if (*(int *)(param_1 + 0x14) == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(*(int *)(param_1 + 0x14) + 0x18);

  }

  if (iVar1 != iVar3) {

    return 0xffffffff;

  }

  ExceptionList = &local_c;

  FUN_004451c0(local_24,*(int *)(param_2 + 0x14) + 0x24);

  local_4 = 0;

  FUN_00746b00();

  local_28 = (int *)0x0;

  local_2c = &PTR_FUN_00a9db18;

  local_4._0_1_ = 1;

  if (*(int *)(param_1 + 0x14) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + 0x18);

  }

  iVar1 = FUN_00414c20(uVar2,local_24,1,0);

  if (-1 < iVar1) {

    FUN_00738bc0();

    *(uint *)(param_2 + 0xbc) = *(uint *)(param_2 + 0xbc) | 1;

    uVar2 = FUN_0044bbc0(&local_2c,0,0);

    local_4 = (uint)local_4._1_3_ << 8;

    local_2c = &PTR_FUN_00a9db18;

    if ((local_28 != (int *)0x0) && (local_28[1] = local_28[1] + -1, local_28[1] == 0)) {

      (**(code **)(*local_28 + 8))();

    }

    FUN_00414b60();

    ExceptionList = local_c;

    return uVar2;

  }

  local_4 = (uint)local_4._1_3_ << 8;

  local_2c = &PTR_FUN_00a9db18;

  if ((local_28 != (int *)0x0) && (local_28[1] = local_28[1] + -1, local_28[1] == 0)) {

    (**(code **)(*local_28 + 8))();

  }

  FUN_00414b60();

  ExceptionList = local_c;

  return 0xffffffff;

}
