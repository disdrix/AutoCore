// =============================================================================
// FUN_007d8fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_007d8fe0
// Address:   0x007d8fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007d8fe0 @ 0x007d8fe0
// Stable ID: aa_007d8fe0
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "LoadOneVehicleTemplate::dcFetch::Open"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×1.
//  - Notable callees: FUN_004231d0×16, FUN_00423170×2, wcscpy×2, FUN_0041a3e0, FUN_0041a810, FUN_0041bf70, FUN_0041c000, FUN_00422de0.
//  - Strings: "DBReader: %u against %s"; "LoadOneVehicleTemplate::dcFetch::Open".
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

uint32_t /* width from decompiler */ __thiscall FUN_007d8fe0(char *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int iVar1;

  int iVar2;

  byte bStack_1b7;

  uint8_t uStack_1b6;

  uint8_t uStack_1b5;

  uint32_t /* width from decompiler */ local_1b4;

  uint32_t /* width from decompiler */ local_1b0;

  uint32_t /* width from decompiler */ *local_1ac;

  uint32_t /* width from decompiler */ local_1a8;

  int local_1a4;

  uint32_t /* width from decompiler */ local_1a0;

  uint32_t /* width from decompiler */ *local_19c;

  uint32_t /* width from decompiler */ local_198;

  uint32_t /* width from decompiler */ local_194;

  uint32_t /* width from decompiler */ local_190;

  uint32_t /* width from decompiler */ local_18c;

  uint16_t uStack_188;

  uint32_t /* width from decompiler */ uStack_184;

  uint32_t /* width from decompiler */ uStack_180;

  uint32_t /* width from decompiler */ uStack_17c;

  uint32_t /* width from decompiler */ uStack_178;

  uint32_t /* width from decompiler */ uStack_174;

  uint32_t /* width from decompiler */ uStack_170;

  uint32_t /* width from decompiler */ uStack_16c;

  uint32_t /* width from decompiler */ uStack_168;

  uint32_t /* width from decompiler */ uStack_164;

  uint32_t /* width from decompiler */ uStack_160;

  wchar_t awStack_15c [66];

  wchar_t awStack_d8 [102];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aeaff;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  if (DAT_00d1793c != '\0') {

    return 0;

  }

  local_19c = &local_1b4;

  local_1b4 = 0;

  local_1b0 = 0;

  local_1ac = (uint32_t /* width from decompiler */ *)0x0;

  local_1a8 = 0;

  local_1a4 = 0;

  local_1a0 = 0;

  local_194 = 0;

  local_198 = 0;

  local_190 = 0;

  local_18c = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_004230d0(local_19c,&param_2);

  iVar1 = FUN_00422fb0(1,1,4);

  if (-1 < iVar1) {

    iVar1 = FUN_0041a810(&local_1b4,param_1 + 0x28,0,0,&DAT_00a140c8,0,0);

  }

  local_1ac = &uStack_184;

  if (((((((-1 < iVar1) && (iVar1 = FUN_004231d0(&local_1b4,1,4), -1 < iVar1)) &&

         (iVar1 = FUN_004231d0(&local_1b4,2,4), -1 < iVar1)) &&

        ((iVar1 = FUN_004231d0(&local_1b4,3,4), -1 < iVar1 &&

         (iVar1 = FUN_004231d0(&local_1b4,4,4), -1 < iVar1)))) &&

       ((iVar1 = FUN_004231d0(&local_1b4,5,4), -1 < iVar1 &&

        ((iVar1 = FUN_004231d0(&local_1b4,6,2), -1 < iVar1 &&

         (iVar1 = FUN_004231d0(&local_1b4,7,1), -1 < iVar1)))))) &&

      (iVar1 = FUN_004231d0(&local_1b4,8,1), -1 < iVar1)) &&

     ((((iVar1 = FUN_004231d0(&local_1b4,9,4), -1 < iVar1 &&

        (iVar1 = FUN_004231d0(&local_1b4,10,1), -1 < iVar1)) &&

       (iVar1 = FUN_004231d0(&local_1b4,0xb,0xca), -1 < iVar1)) &&

      (((iVar1 = FUN_004231d0(&local_1b4,0xc,0x82), -1 < iVar1 &&

        (iVar1 = FUN_004231d0(&local_1b4,0xd,4), -1 < iVar1)) &&

       ((iVar1 = FUN_004231d0(&local_1b4,0xe,4), -1 < iVar1 &&

        ((iVar1 = FUN_004231d0(&local_1b4,0xf,4), -1 < iVar1 &&

         (iVar1 = FUN_004231d0(&local_1b4,0x10,4), -1 < iVar1)))))))))) {

    if (local_1a4 != 0) {

      iVar2 = FUN_0041c000(0,1);

      iVar1 = param_3;

      if (iVar2 == 0) {

        *(uint32_t /* width from decompiler */ *)(param_3 + 4) = uStack_184;

        *(uint32_t /* width from decompiler */ *)(param_3 + 8) = uStack_174;

        *(uint32_t /* width from decompiler */ *)(param_3 + 0xc) = uStack_168;

        *(uint32_t /* width from decompiler */ *)(param_3 + 0x10) = uStack_160;

        *(uint32_t /* width from decompiler */ *)(param_3 + 0x1c) = uStack_180;

        *(uint16_t *)(param_3 + 0x28) = uStack_188;

        *(uint32_t /* width from decompiler */ *)(param_3 + 0x20) = uStack_164;

        *(uint8_t *)(param_3 + 0x2a) = uStack_1b5;

        *(uint8_t *)(param_3 + 0x2b) = uStack_1b6;

        *(float *)(param_3 + 0x24) = (float)bStack_1b7 * DAT_00a0f718;

        wcscpy((wchar_t *)(param_3 + 0x2c),awStack_d8);

        wcscpy((wchar_t *)(iVar1 + 0xf6),awStack_15c);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x178) = uStack_16c;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x17c) = uStack_17c;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14) = uStack_178;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18) = uStack_170;

      }

      if (local_1a4 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      goto LAB_007d940f;

    }

    iVar1 = -0x7fffbffb;

  }

  FUN_00423170();

  FUN_007a4480(1,"DBReader: %u against %s",iVar1,"LoadOneVehicleTemplate::dcFetch::Open");

LAB_007d940f:

  local_4 = 0xffffffff;

  FUN_0041a3e0(&local_1b4);

  ExceptionList = local_c;

  return 0;

}
