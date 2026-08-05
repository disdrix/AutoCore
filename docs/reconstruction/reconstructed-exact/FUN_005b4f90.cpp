// =============================================================================
// FUN_005b4f90
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4f90
// Address:   0x005b4f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b4f90 @ 0x005b4f90
// Stable ID: aa_005b4f90
// Embedded strings (evidence for future rename):
//   - "RenderLeaves"
//   - "RenderLeaves::GetGeometry"
//   - "RenderLeaves::GetLeafBillboardTable"
//   - "RenderLeaves::SetParamArrayByName"
//   - "RenderLeaves::AlphaRefValue"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×10, do×3, while×3, return×1.
//  - Notable callees: FUN_0076cef0×5, FUN_0076cf00×5, FUN_00687220×4, FUN_0068a4d0×2, FUN_00752a00×2, FUN_0096f5d0×2, FUN_0096fdf0×2, CONCAT31.
//  - Strings: "RenderLeaves"; "RenderLeaves::GetGeometry"; "RenderLeaves::GetLeafBillboardTable"; "RenderLeaves::SetParamArrayByName".
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

uint32_t /* width from decompiler */ __fastcall FUN_005b4f90(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  short sVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  char *pcVar8;

  int local_1c;

  uint local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a68f1;

  local_c = ExceptionList;

  local_10 = DAT_00d1f040;

  ExceptionList = &local_c;

  FUN_0076cf00("RenderLeaves");

  uVar6 = 0;

  local_4 = 0;

  local_14 = DAT_00d1f040;

  FUN_0076cf00("RenderLeaves::GetGeometry");

  local_4._0_1_ = 1;

  FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),4,0xffffffff,0xffffffff,0);

  FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),4,0xffffffff,0xffffffff,0xffffffff);

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0076cef0();

  uVar7 = 0;

  sVar3 = FUN_00687220();

  if (sVar3 != 0) {

    do {

      iVar5 = *(int *)(*(int *)(param_1 + 0x14) + uVar7 * 4);

      if (iVar5 != 0) {

        *(uint8_t *)(iVar5 + 0xcc) = 0;

      }

      uVar7 = uVar7 + 1;

      uVar4 = FUN_00687220();

    } while (uVar7 < (uVar4 & 0xffff));

  }

  iVar5 = *(int *)(param_1 + 0x50);

  if ((((-1 < *(int *)(iVar5 + 0x80)) && (*(char *)(iVar5 + 0x78) != '\0')) &&

      (*(short *)(iVar5 + 0x84) != 0)) &&

     (iVar5 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar5 + 0x80) * 4), iVar5 != 0)) {

    *(uint8_t *)(iVar5 + 0xcc) = 1;

  }

  iVar5 = *(int *)(param_1 + 0x50);

  if (((-1 < *(int *)(iVar5 + 0xbc)) && (*(char *)(iVar5 + 0xb4) != '\0')) &&

     ((*(short *)(iVar5 + 0xc0) != 0 &&

      (iVar5 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(iVar5 + 0xbc) * 4), iVar5 != 0)))) {

    *(uint8_t *)(iVar5 + 0xcc) = 1;

  }

  local_1c = 0;

  local_14 = DAT_00d1f040;

  FUN_0076cf00("RenderLeaves::GetLeafBillboardTable");

  local_4._0_1_ = 2;

  FUN_006868a0(1);

  FUN_00686d30(0x3e800000,0xbf800000,0xbf800000);

  local_18 = FUN_00687230(&local_1c);

  local_4._0_1_ = 0;

  FUN_0076cef0();

  local_14 = DAT_00d1f040;

  FUN_0076cf00("RenderLeaves::SetParamArrayByName");

  local_4 = CONCAT31(local_4._1_3_,3);

  sVar3 = FUN_00687220();

  if (sVar3 != 0) {

    do {

      iVar5 = *(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4);

      if (((iVar5 != 0) && (*(char *)(iVar5 + 0xcc) != '\0')) && (*(int *)(iVar5 + 0x20) != 0)) {

        FUN_0096fe40(*(uint32_t /* width from decompiler */ *)(iVar5 + 0xd4),local_18,local_1c * 4);

        uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4) + 0xd0);

        cVar2 = FUN_0096fdf0();

        iVar5 = FUN_00752a00(uVar1,&DAT_00b05240);

        if ((iVar5 == -1) && (cVar2 != '\0')) {

          FUN_0096f5d0();

        }

      }

      uVar6 = uVar6 + 1;

      uVar7 = FUN_00687220();

    } while (uVar6 < (uVar7 & 0xffff));

  }

  local_4 = local_4 & 0xffffff00;

  FUN_0076cef0();

  local_18 = 0;

  do {

    uVar6 = local_18;

    local_14 = DAT_00d1f040;

    FUN_0076cf00("RenderLeaves::AlphaRefValue");

    local_4._0_1_ = 4;

    if (uVar6 == 0) {

      pcVar8 = (char *)(*(int *)(param_1 + 0x50) + 0x78);

    }

    else {

      pcVar8 = (char *)(*(int *)(param_1 + 0x50) + 0xb4);

    }

    if ((((-1 < *(int *)(pcVar8 + 8)) && (*pcVar8 != '\0')) && (*(short *)(pcVar8 + 0xc) != 0)) &&

       ((iVar5 = *(int *)(*(int *)(param_1 + 0x14) + *(int *)(pcVar8 + 8) * 4), iVar5 != 0 &&

        (*(int *)(iVar5 + 0x20) != 0)))) {

      uVar1 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xd8);

      cVar2 = FUN_0096fdf0();

      iVar5 = FUN_00752a00(uVar1,pcVar8 + 4);

      if ((iVar5 == -1) && (cVar2 != '\0')) {

        FUN_0096f5d0();

      }

    }

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_0076cef0();

    local_18 = local_18 + 1;

  } while (local_18 < 2);

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 1;

}
