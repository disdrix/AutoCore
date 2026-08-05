// =============================================================================
// FUN_0069ead0
// -----------------------------------------------------------------------------
// Stable ID: aa_0069ead0
// Address:   0x0069ead0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069ead0 @ 0x0069ead0
// Stable ID: aa_0069ead0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_00697d80×4, CONCAT31×2, FUN_0069e940×2, FUN_00686050, FUN_00697280, FUN_00697390, FUN_00698950, FUN_0069e970.
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

void __thiscall FUN_0069ead0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint8_t local_70 [20];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_5c [64];

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009aaf18;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff84;

  ExceptionList = &local_10;

  local_18 = param_1;

  FUN_00697390(param_4);

  iVar2 = *(int *)(param_1 + 4);

  uVar5 = 0;

  local_8 = 0;

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x54;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x54;

    }

    if (0x30c30c3U - iVar1 < param_3) {

      FUN_00697280();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x54;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0x30c30c3 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0x54;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_00686050();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x54);

      local_8 = CONCAT31(local_8._1_3_,1);

      local_1c = pvVar3;

      iVar2 = FUN_00697d80(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      FUN_0069e9b0(iVar2,param_3,local_70,param_1,param_2);

      FUN_00697d80(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x54,param_1,param_2);

      local_8 = 0;

      iVar2 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x54;

      }

      if (*(int *)(param_1 + 4) != 0) {

        FUN_00698950(*(int *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x54 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar2) * 0x54 + (int)pvVar3);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = *(int *)(param_1 + 8);

      if ((uint)((iVar2 - param_2) / 0x54) < param_3) {

        FUN_00697d80(param_2,iVar2,param_3 * 0x54 + param_2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_0069eaa0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x54,

                     local_70);

        iVar2 = *(int *)(param_1 + 8) + param_3 * 0x54;

        *(int *)(param_1 + 8) = iVar2;

        local_8 = 0;

        FUN_0069e940(param_2,iVar2 + param_3 * -0x54,local_70);

      }

      else {

        iVar1 = iVar2 + param_3 * -0x54;

        uVar4 = FUN_00697d80(iVar1,iVar2,iVar2,param_1,iVar1);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_0069e970(param_2,iVar1,iVar2,iVar1);

        FUN_0069e940(param_2,param_3 * 0x54 + param_2,local_70);

      }

    }

  }

  local_8 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_5c);

  ExceptionList = local_10;

  return;

}
