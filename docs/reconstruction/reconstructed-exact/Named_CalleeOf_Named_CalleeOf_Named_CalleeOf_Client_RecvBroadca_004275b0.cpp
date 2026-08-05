// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca_004275b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004275b0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast
// Address:   0x004275b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×13, return×2.
//  - Notable callees: FUN_00427b70×4, CONCAT31×2, FUN_00427a40×2, FUN_00427590, FUN_004275b0, FUN_00427840, FUN_00427960, FUN_00427b10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca_004275b0(int param_1,int param_2,uint param_3)



{

  uint uVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int extraout_ECX;

  int iVar5;

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

  local_88 [116];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be26b;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff60;

  ExceptionList = &local_10;

  FUN_00427840();

  iVar5 = 0;

  local_8 = 0;

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 0xc) - iVar2 >> 7;

  }

  if (param_3 != 0) {

    if (iVar2 != 0) {

      iVar5 = *(int *)(param_1 + 8) - iVar2 >> 7;

    }

    if (0x1ffffffU - iVar5 < param_3) {

      uVar1 = FUN_004540b0();

      iVar2 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_1 + 8) - iVar2 >> 7;

    }

    if (uVar1 < iVar5 + param_3) {

      if (0x1ffffff - (uVar1 >> 1) < uVar1) {

        uVar1 = 0;

      }

      else {

        uVar1 = uVar1 + (uVar1 >> 1);

      }

      if (iVar2 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - iVar2 >> 7;

      }

      if (uVar1 < iVar5 + param_3) {

        if (iVar2 == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(param_1 + 8) - iVar2 >> 7;

        }

        uVar1 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar1 * 0x80);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_00427b70(pvVar3,param_2);

      FUN_00427a40(iVar2,param_2);

      FUN_00427b70(iVar2 + param_3 * 0x80,param_2);

      local_8 = 0;

      iVar2 = *(int *)(param_1 + 4);

      if (iVar2 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - iVar2 >> 7;

      }

      if (iVar2 != 0) {

        FUN_00427590();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar1 * 0x80 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar5) * 0x80 + (int)pvVar3);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      if ((uint)(*(int *)(param_1 + 8) - param_2 >> 7) < param_3) {

        FUN_00427b70(param_3 * 0x80 + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00427a40(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x80;

      }

      else {

        uVar4 = FUN_00427b70(*(int *)(param_1 + 8),param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_00427b10(param_2);

      }

      FUN_00427960();

    }

  }

  local_8 = 0xffffffff;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>(local_88);

  ExceptionList = local_10;

  return;

}
