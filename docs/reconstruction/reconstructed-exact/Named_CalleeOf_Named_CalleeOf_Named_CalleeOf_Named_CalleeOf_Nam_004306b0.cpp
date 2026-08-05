// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004306b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004306b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x004306b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: CONCAT31×2, FUN_00430390×2, FUN_00431430×2, FUN_00431450×2, FUN_0046a2c0×2, FUN_004306b0, FUN_00431480, FUN_00431aa0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004306b0(int param_1,int param_2,uint param_3,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_4)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint extraout_ECX;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_38 [28];

  int local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bccf9;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffbc;

  ExceptionList = &local_10;

  local_18 = param_1;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_38,param_4);

  uVar4 = 0;

  local_8 = 0;

  iVar1 = *(int *)(param_1 + 4);

  if (iVar1 != 0) {

    uVar4 = (*(int *)(param_1 + 0xc) - iVar1) / 0x1c;

  }

  if (param_3 != 0) {

    if (iVar1 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (0x9249249U - iVar1 < param_3) {

      FUN_004540b0();

      uVar4 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (uVar4 < iVar1 + param_3) {

      if (0x9249249 - (uVar4 >> 1) < uVar4) {

        uVar4 = 0;

      }

      else {

        uVar4 = uVar4 + (uVar4 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (uVar4 < iVar1 + param_3) {

        iVar1 = FUN_00469c50();

        uVar4 = iVar1 + param_3;

      }

      pvVar2 = operator_new(uVar4 * 0x1c);

      local_8 = CONCAT31(local_8._1_3_,1);

      uVar3 = FUN_0046a2c0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar2,param_1,param_2);

      uVar3 = FUN_00430390(uVar3,param_3,local_38);

      FUN_0046a2c0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar3,param_1,param_2);

      local_8 = 0;

      iVar1 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (*(int *)(param_1 + 4) != 0) {

        FUN_00431aa0(*(int *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar4 * 0x1c + (int)pvVar2);

      *(void **)(param_1 + 8) = (void *)((int)pvVar2 + (param_3 + iVar1) * 0x1c);

      *(void **)(param_1 + 4) = pvVar2;

    }

    else {

      local_1c = *(int *)(param_1 + 8);

      if ((uint)((local_1c - param_2) / 0x1c) < param_3) {

        FUN_00431430(param_2,local_1c,param_3 * 0x1c + param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00430390(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x1c

                     ,local_38);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x1c;

        FUN_00431450(param_2,*(int *)(param_1 + 8) + param_3 * -0x1c,local_38);

      }

      else {

        iVar1 = local_1c + param_3 * -0x1c;

        uVar3 = FUN_00431430(iVar1,local_1c,local_1c);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

        FUN_00431480(param_2,iVar1,local_1c);

        FUN_00431450(param_2,param_3 * 0x1c + param_2,local_38);

      }

    }

  }

  local_8 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_38);

  ExceptionList = local_10;

  return;

}
