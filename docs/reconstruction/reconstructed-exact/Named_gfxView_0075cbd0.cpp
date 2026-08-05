// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×18, return×2.
//  - Notable callees: FUN_0075b720×3, FUN_0076c3c0×2, FUN_0043f1d0, FUN_0043f3b0, FUN_0073f610, FUN_0075bcd0, FUN_0075c680, FUN_0075cbd0.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp"; "Failed to Render Object Display List".
//  - Return sites: 2.

// =============================================================================
// Named_gfxView_0075cbd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075cbd0
// Address:   0x0075cbd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxView"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_gfxView_0075cbd0(int param_1,uint32_t /* width from decompiler */ *param_2,byte param_3)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  void *unaff_EBX;

  uint32_t /* width from decompiler */ unaff_EBP;

  uint uVar7;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar5 = DAT_00d1f614;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b255c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(char *)(DAT_00d1f614 + 200) == '\0') {

    ExceptionList = &pvStack_c;

    iVar6 = FUN_0076c3c0();

    piVar1 = (int *)(iVar5 + 0x34 + *(int *)(iVar5 + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar6 - *(int *)(iVar5 + 0x30));

    *(int *)(iVar5 + 0x30) = iVar6;

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc4) = 0;

  }

  local_4 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = *param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = param_2[1];

  if ((param_3 & 4) == 0) {

    if (*(int *)(param_1 + 0x44) == 0) {

      FUN_0075e7e0(0);

    }

    else if (*(int *)(param_1 + 0x44) != 0) {

      FUN_0043f3b0(0);

    }

  }

  FUN_0075c680();

  if ((*(char *)(param_1 + 0x14c) == '\0') || (iVar6 = *(int *)(param_1 + 0x44), iVar6 == 0)) {

    FUN_0075b720(0,0x3f800000);

  }

  else {

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc);

    uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0);

    uVar4 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x1c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = uVar4;

    FUN_0075b720(0,0x3f800000);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = uVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = uVar3;

  }

  piVar1 = (int *)*DAT_00d1f044;

  if (*(int *)(param_1 + 0x44) == 0) {

    if (DAT_00d1f044[0x1e1] != 0) {

      (**(code **)(*DAT_00d1f610 + 0x1c))(DAT_00d1f610,0xa1,*(uint8_t *)(DAT_00d1f048 + 0x2c));

    }

  }

  else {

    uVar7 = 0;

    if (((param_3 & 1) != 0) && ((*(byte *)(*(int *)(param_1 + 0x44) + 0x2c) & 0x20) != 0)) {

      uVar7 = 5;

    }

    if (((param_3 & 2) != 0) ||

       ((*(char *)(param_1 + 0x129) != '\0' && (*(int *)(param_1 + 0x13c) == 0)))) {

      uVar7 = uVar7 | 2;

    }

    if (uVar7 != 0) {

      FUN_0075ebd0(DAT_00d1f044,uVar7,param_1 + 0x148,0x3f800000,0);

    }

  }

  if ((*(char *)(param_1 + 0x14c) != '\0') && (*(int *)(param_1 + 0x44) != 0)) {

    FUN_0075b720(0,0x3f800000);

    *(uint8_t *)(param_1 + 0x14c) = 0;

  }

  if ((*(char *)(param_1 + 0x129) != '\0') &&

     ((*(int *)(param_1 + 0x13c) != 0 || (*(int *)(param_1 + 0x44) == 0)))) {

    FUN_0075bcd0();

  }

  if (*(char *)(DAT_00d1f048 + 0xd) != '\0') {

    (**(code **)(*DAT_00d1f610 + 0x1c))(DAT_00d1f610,8,2);

  }

  if (*(char *)((int)DAT_00d1f044 + 0x777) != '\0') {

    (**(code **)(*piVar1 + 0x13c))(piVar1,*(uint32_t /* width from decompiler */ *)(DAT_00d1f048 + 0x28));

  }

  iVar6 = FUN_0073f610();

  if (iVar6 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",0x275,3,

                   "Failed to Render Object Display List");

    FUN_0043f1d0();

    ExceptionList = pvStack_c;

    return 0xffffffff;

  }

  if (*(char *)((int)DAT_00d1f044 + 0x777) != '\0') {

    (**(code **)(*piVar1 + 0x13c))(piVar1,0);

  }

  if (*(char *)(DAT_00d1f048 + 0xd) != '\0') {

    (**(code **)(*DAT_00d1f610 + 0x1c))(DAT_00d1f610,8,3);

  }

  (**(code **)(*DAT_00d1f610 + 0x1c))(DAT_00d1f610,0xa1,0);

  if (*(char *)(iVar5 + 200) == '\0') {

    iVar6 = FUN_0076c3c0();

    piVar1 = (int *)(iVar5 + 0x34 + *(int *)(iVar5 + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar6 - *(int *)(iVar5 + 0x30));

    *(int *)(iVar5 + 0x30) = iVar6;

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc4) = unaff_EBP;

  }

  ExceptionList = unaff_EBX;

  return 0;

}
