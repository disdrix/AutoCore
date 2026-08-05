// =============================================================================
// Named_TEXTURE_OFFSET_MIDDLE_008aa080
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa080
// Address:   0x008aa080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_TEXTURE_OFFSET_MIDDLE_008aa080 @ 0x008aa080
// Stable ID: aa_008aa080
// Embedded strings (evidence for future rename):
//   - "TEXTURE_OFFSET_LEFT"
//   - "%f;%f"
//   - "TEXTURE_OFFSET_MIDDLE"
//   - "TEXTURE_OFFSET_RIGHT"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: SysFreeString×4, _wcsicmp×3, swscanf×3, FUN_0040d230, FUN_007933a0, FUN_008aa080.
//  - Strings: "TEXTURE_OFFSET_LEFT"; "%f;%f"; "TEXTURE_OFFSET_MIDDLE"; "TEXTURE_OFFSET_RIGHT".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * String-driven rename evidence: "TEXTURE_OFFSET_MIDDLE"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_TEXTURE_OFFSET_MIDDLE_008aa080(int *param_1,int param_2)



{

  int iVar1;

  float unaff_EBX;

  BSTR unaff_ESI;

  uint32_t /* width from decompiler */ unaff_retaddr;

  int local_18;

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b9993;

  local_c = ExceptionList;

  local_18 = 0;

  local_4 = 0;

  if ((param_1 != (int *)0x0) && (param_2 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_1 + 0x1c))(param_1,&local_18);

    iVar1 = _wcsicmp(L"TEXTURE_OFFSET_LEFT",unaff_ESI);

    if (iVar1 == 0) {

      SysFreeString(unaff_ESI);

      unaff_ESI = (BSTR)0x0;

      (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

      iVar1 = swscanf((wchar_t *)0x0,L"%f;%f",&stack0xffffffe4,0);

      if (iVar1 == 2) {

        _DAT_00000000 = _DAT_00000000 - unaff_EBX;

      }

      *(float *)(local_18 + 0x52c) = unaff_EBX;

    }

    else {

      iVar1 = _wcsicmp(L"TEXTURE_OFFSET_MIDDLE",unaff_ESI);

      if (iVar1 == 0) {

        SysFreeString(unaff_ESI);

        unaff_ESI = (BSTR)0x0;

        (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

        iVar1 = swscanf((wchar_t *)0x0,L"%f;%f",&stack0xffffffe4,0);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - unaff_EBX;

        }

        *(float *)(local_18 + 0x530) = unaff_EBX;

      }

      else {

        iVar1 = _wcsicmp(L"TEXTURE_OFFSET_RIGHT",unaff_ESI);

        if (iVar1 == 0) {

          FUN_0040d230();

          (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

          iVar1 = swscanf(unaff_ESI,L"%f;%f",&stack0xffffffe4,0);

          if (iVar1 == 2) {

            _DAT_00000000 = _DAT_00000000 - unaff_EBX;

          }

          *(float *)(local_18 + 0x534) = unaff_EBX;

        }

        else {

          FUN_007933a0(param_1,unaff_retaddr);

        }

      }

    }

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_ESI);

    ExceptionList = pvStack_14;

    return;

  }

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
