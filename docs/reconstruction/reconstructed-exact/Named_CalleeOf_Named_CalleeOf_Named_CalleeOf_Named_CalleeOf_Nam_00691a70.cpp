// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00691a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00691a70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00691a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_00690bc0×4, CONCAT31×2, FUN_006909a0×2, FUN_0045c210, FUN_00690330, FUN_00690400, FUN_006914a0, FUN_006919c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00691a70(int param_1,int param_2,uint param_3,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_48 [28];

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009aa708;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffac;

  ExceptionList = &local_10;

  local_18 = param_1;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_48,param_4);

  local_2c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1c);

  local_28 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x20);

  local_24 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x24);

  local_20 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x28);

  iVar2 = *(int *)(param_1 + 4);

  uVar5 = 0;

  local_8 = 0;

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x2c;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x2c;

    }

    if (0x5d1745dU - iVar1 < param_3) {

      FUN_00690330();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x2c;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0x5d1745d - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0x2c;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_0045c210();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x2c);

      local_8 = CONCAT31(local_8._1_3_,1);

      local_1c = pvVar3;

      iVar2 = FUN_00690bc0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      FUN_006914a0(iVar2,param_3,local_48,param_1,param_2);

      FUN_00690bc0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x2c,param_1,param_2);

      local_8 = 0;

      iVar2 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x2c;

      }

      if (*(int *)(param_1 + 4) != 0) {

        FUN_006919c0(*(int *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x2c + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar2) * 0x2c + (int)pvVar3);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = *(int *)(param_1 + 8);

      if ((uint)((iVar2 - param_2) / 0x2c) < param_3) {

        FUN_00690bc0(param_2,iVar2,param_3 * 0x2c + param_2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00691a40(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x2c,

                     local_48);

        iVar2 = *(int *)(param_1 + 8) + param_3 * 0x2c;

        *(int *)(param_1 + 8) = iVar2;

        local_8 = 0;

        FUN_006909a0(param_2,iVar2 + param_3 * -0x2c,local_48);

      }

      else {

        iVar1 = iVar2 + param_3 * -0x2c;

        uVar4 = FUN_00690bc0(iVar1,iVar2,iVar2,param_1,iVar1);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_00690400(param_2,iVar1,iVar2,iVar1);

        FUN_006909a0(param_2,param_3 * 0x2c + param_2,local_48);

      }

    }

  }

  local_8 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_48);

  ExceptionList = local_10;

  return;

}
