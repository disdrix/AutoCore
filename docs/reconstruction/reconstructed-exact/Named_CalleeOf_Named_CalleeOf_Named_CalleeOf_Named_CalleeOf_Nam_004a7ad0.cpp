// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004a7ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a7ad0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_attachmentRe
// Address:   0x004a7ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_attachmentRe: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_004a6b50×4, CONCAT31×2, FUN_004a68a0×2, FUN_00469c50, FUN_004a6820, FUN_004a68d0, FUN_004a74f0, FUN_004a7a70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_attachmentRe
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

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004a7ad0(int param_1,int param_2,uint param_3,

            basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

            *param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  int iVar6;

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

  local_34 [28];

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a11e9;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffc0;

  ExceptionList = &local_10;

  local_18 = param_1;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

            (local_34,param_4);

  iVar2 = *(int *)(param_1 + 4);

  uVar5 = 0;

  local_8 = 0;

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x1c;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (0x9249249U - iVar2 < param_3) {

      FUN_004a6820();

      uVar5 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (uVar5 < iVar2 + param_3) {

      if (0x9249249 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_00469c50();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x1c);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_004a6b50(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      FUN_004a74f0(iVar2,param_3,local_34,param_1,param_2);

      FUN_004a6b50(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x1c,param_1,param_2);

      local_8 = 0;

      iVar2 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (*(int *)(param_1 + 4) != 0) {

        FUN_004a7aa0(*(int *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x1c + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar2) * 0x1c);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = *(int *)(param_1 + 8);

      iVar1 = param_3 * 0x1c;

      if ((uint)((iVar2 - param_2) / 0x1c) < param_3) {

        FUN_004a6b50(param_2,iVar2,iVar1 + param_2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_004a7a70(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x1c

                     ,local_34);

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;

        local_8 = 0;

        FUN_004a68a0(param_2,*(int *)(param_1 + 8) + param_3 * -0x1c,local_34);

      }

      else {

        iVar6 = iVar2 + param_3 * -0x1c;

        uVar4 = FUN_004a6b50(iVar6,iVar2,iVar2,param_1,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_004a68d0(param_2,iVar6,iVar2,param_2);

        FUN_004a68a0(param_2,iVar1 + param_2,local_34);

      }

    }

  }

  local_8 = 0xffffffff;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>(local_34);

  ExceptionList = local_10;

  return;

}
