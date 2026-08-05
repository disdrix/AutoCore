// =============================================================================
// FUN_004f2930
// -----------------------------------------------------------------------------
// Stable ID: aa_004f2930
// Address:   0x004f2930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f2930 @ 0x004f2930
// Stable ID: aa_004f2930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~137 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_0040d2a0, FUN_004f1180, FUN_004f2930, FUN_004f2d70, FUN_005d3ef0, FUN_005d4240, FUN_005d4440, FUN_005de8f0.
//  - Return sites: 2.

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

int __thiscall FUN_004f2930(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,int param_4)



{

  int iVar1;

  bool bVar2;

  char *pcVar3;

  int iVar4;

  uint8_t local_151;

  uint32_t /* width from decompiler */ local_150;

  uint32_t /* width from decompiler */ local_14c;

  uint32_t /* width from decompiler */ local_140;

  uint32_t /* width from decompiler */ local_13c;

  uint32_t /* width from decompiler */ local_138;

  uint32_t /* width from decompiler */ local_134;

  uint32_t /* width from decompiler */ local_130;

  uint32_t /* width from decompiler */ local_12c;

  uint32_t /* width from decompiler */ local_128;

  uint32_t /* width from decompiler */ local_124;

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  uint32_t /* width from decompiler */ local_110;

  uint32_t /* width from decompiler */ local_10c;

  uint32_t /* width from decompiler */ local_108;

  uint32_t /* width from decompiler */ local_104;

  uint32_t /* width from decompiler */ uStack_100;

  uint32_t /* width from decompiler */ uStack_fc;

  int iStack_ec;

  uint8_t auStack_e8 [8];

  int local_e0;

  uint32_t /* width from decompiler */ local_dc;

  int iStack_d4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  uint32_t /* width from decompiler */ local_b8;

  uint32_t /* width from decompiler */ local_b4;

  uint32_t /* width from decompiler */ local_b0;

  uint32_t /* width from decompiler */ local_ac;

  uint32_t /* width from decompiler */ local_a8;

  uint32_t /* width from decompiler */ local_a4;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  char local_2c;

  void *pvStack_24;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a2bf3;

  local_1c = ExceptionList;

  ExceptionList = &local_1c;

  if (*(int *)(param_1 + 0x98) == 0) {

    iVar4 = *(int *)(param_1 + 0x3c);

    ExceptionList = &local_1c;

    if (((iVar4 != 0) && (ExceptionList = &local_1c, *(short *)(iVar4 + 0x40a) != 0)) &&

       (ExceptionList = &local_1c, *(short *)(iVar4 + 0x40c) != 0)) {

      ExceptionList = &local_1c;

      pcVar3 = (char *)FUN_005de8f0(&local_151);

      if (*pcVar3 != '\0') {

        FUN_004f1180();

      }

    }

    if (*(int *)(param_1 + 0x98) == 0) {

      ExceptionList = local_1c;

      return 0;

    }

  }

  FUN_005e1c80();

  local_14 = 0;

  FUN_005d3ef0(&local_e0);

  local_c0 = *param_2;

  local_bc = param_2[1];

  local_b8 = param_2[2];

  local_b4 = param_2[3];

  local_b0 = *param_3;

  local_ac = param_3[1];

  local_a8 = param_3[2];

  local_a4 = param_3[3];

  if (0 < param_4) {

    local_e0 = param_4;

  }

  bVar2 = false;

  if ((DAT_00b03e64 != '\0') && (local_2c == '\a')) {

    local_40 = DAT_00aaa880;

    bVar2 = true;

    local_150 = 0;

    local_14c = 0;

    local_134 = 0;

    local_138 = 0;

    local_13c = 0;

    local_140 = 0;

    local_124 = 0;

    local_128 = 0;

    local_12c = 0;

    local_130 = 0;

    local_114 = 0;

    local_118 = 0;

    local_11c = 0;

    local_120 = 0;

    local_104 = 0;

    local_108 = 0;

    local_10c = 0;

    local_110 = 0;

    FUN_005f2b60(local_dc,0x461c4000,&local_150);

    FUN_004f2d70(&local_130);

    local_50 = local_140;

    local_4c = local_13c;

    local_48 = local_138;

    local_44 = local_134;

    local_40 = local_14c;

    FUN_005f2900(local_dc,local_14c,&local_e0);

    local_2c = '\x04';

  }

  iStack_ec = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

  *(uint16_t *)(iStack_ec + 4) = 0xa0;

  local_1c._0_1_ = 1;

  iVar4 = FUN_005d4240(auStack_e8);

  local_1c = (void *)((uint)local_1c._1_3_ << 8);

  if (bVar2) {

    iVar1 = *(int *)(iVar4 + 0x3c);

    local_108 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb0);

    local_104 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb4);

    uStack_100 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb8);

    uStack_fc = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc);

    FUN_005d4440(6);

    FUN_0040d2a0(&local_108);

  }

  local_1c = (void *)0xffffffff;

  if (-1 < iStack_d4) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_dc,iStack_d4 * 8,0x12);

  }

  ExceptionList = pvStack_24;

  return iVar4;

}
