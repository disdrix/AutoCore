// =============================================================================
// Named_CalleeOf_Named_attachmentResponseCoefficient_004a1d80
// -----------------------------------------------------------------------------
// Stable ID: aa_004a1d80
// Callee of Named_attachmentResponseCoefficient
// Address:   0x004a1d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_attachmentResponseCoefficient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×7, while×5, return×5, for×1.
//  - Notable callees: iswspace×3, FUN_004a1d80, FUN_004a8100.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_attachmentResponseCoefficient
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

int __fastcall Named_CalleeOf_Named_attachmentResponseCoefficient_004a1d80(wchar_t *param_1)



{

  wchar_t *pwVar1;

  void **ppvVar2;

  wchar_t wVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  wchar_t *pwVar6;

  int local_838;

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

  local_834 [28];

  wchar_t local_818;

  uint32_t /* width from decompiler */ local_816 [512];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a107d;

  local_14 = ExceptionList;

  local_838 = 0;

  if (param_1 != (wchar_t *)0x0) {

    wVar3 = *param_1;

    ppvVar2 = &local_14;

    while (ExceptionList = ppvVar2, wVar3 != L'\0') {

      local_818 = L'\0';

      puVar5 = local_816;

      for (iVar4 = 0x1ff; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar5 = 0;

        puVar5 = puVar5 + 1;

      }

      *(uint16_t *)puVar5 = 0;

      wVar3 = *param_1;

      pwVar6 = &local_818;

      if (wVar3 == L'\"') {

        pwVar1 = param_1 + 1;

        param_1 = param_1 + 1;

        wVar3 = *pwVar1;

        while ((wVar3 != L'\0' && (wVar3 != L'\"'))) {

          param_1 = param_1 + 1;

          *pwVar6 = wVar3;

          pwVar6 = pwVar6 + 1;

          wVar3 = *param_1;

        }

      }

      else {

        while ((wVar3 != L'\0' && (iVar4 = iswspace(wVar3), iVar4 == 0))) {

          wVar3 = *param_1;

          param_1 = param_1 + 1;

          *pwVar6 = wVar3;

          wVar3 = *param_1;

          pwVar6 = pwVar6 + 1;

        }

      }

      if (local_818 != L'\0') {

        std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

        basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                  (local_834,&local_818);

        local_c = 0;

        FUN_004a8100(local_834);

        local_c = 0xffffffff;

        std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

        ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                  (local_834);

        local_838 = local_838 + 1;

      }

      wVar3 = *param_1;

      if (wVar3 == L'\0') {

        ExceptionList = local_14;

        return local_838;

      }

      while (iVar4 = iswspace(wVar3), iVar4 == 0) {

        wVar3 = param_1[1];

        param_1 = param_1 + 1;

        if (wVar3 == L'\0') {

          ExceptionList = local_14;

          return local_838;

        }

      }

      wVar3 = *param_1;

      if (wVar3 == L'\0') {

        ExceptionList = local_14;

        return local_838;

      }

      while (iVar4 = iswspace(wVar3), iVar4 != 0) {

        wVar3 = param_1[1];

        param_1 = param_1 + 1;

        if (wVar3 == L'\0') {

          ExceptionList = local_14;

          return local_838;

        }

      }

      ppvVar2 = ExceptionList;

      wVar3 = *param_1;

    }

  }

  ExceptionList = local_14;

  return local_838;

}
