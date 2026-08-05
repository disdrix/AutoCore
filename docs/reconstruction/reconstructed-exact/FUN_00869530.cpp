// =============================================================================
// FUN_00869530
// -----------------------------------------------------------------------------
// Stable ID: aa_00869530
// Address:   0x00869530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00869530 @ 0x00869530
// Stable ID: aa_00869530
// Embedded strings (evidence for future rename):
//   - "RESIST_ICONS"
//   - "START"
//   - "TEX_SIZE"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: SysFreeString×3, _wcsicmp×3, FUN_007a8b00×2, FUN_007933a0, FUN_00869530.
//  - Strings: "RESIST_ICONS"; "START"; "TEX_SIZE".
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

void __thiscall FUN_00869530(int param_1,int *param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *unaff_EBX;

  wchar_t *unaff_ESI;

  int *unaff_EDI;

  float fVar4;

  int *unaff_retaddr;

  void **_Str2;

  BSTR bstrString;

  void *local_c;

  int *piStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  piStack_8 = (int *)&LAB_009b887a;

  local_c = ExceptionList;

  local_4 = 0;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))();

    iVar2 = _wcsicmp(L"RESIST_ICONS",unaff_ESI);

    if (iVar2 == 0) {

      (**(code **)(*param_2 + 0x30))(param_2);

      if (unaff_retaddr != (int *)0x0) {

        bstrString = (BSTR)&stack0xffffffe8;

        (**(code **)(*unaff_retaddr + 0x20))(unaff_retaddr);

        iVar2 = 0;

        if (0 < (int)unaff_EDI) {

          do {

            _Str2 = &local_c;

            (**(code **)(*piStack_8 + 0x1c))(piStack_8,iVar2);

            SysFreeString(bstrString);

            bstrString = (BSTR)0x0;

            (**(code **)(*unaff_EBX + 0x1c))(unaff_EBX,&stack0xffffffd0);

            iVar3 = _wcsicmp(L"START",(wchar_t *)_Str2);

            if (iVar3 == 0) {

              piVar1 = (int *)(param_1 + 0x544);

              FUN_007a8b00(unaff_EDI,piVar1,param_1 + 0x548,0);

              fVar4 = (float)*(int *)(param_1 + 0x548) * (float)DAT_00d1e81c * DAT_00aaa678;

              *piVar1 = (int)((float)*piVar1 * (float)DAT_00d1e818 * DAT_00aaa67c);

              *(int *)(param_1 + 0x548) = (int)fVar4;

            }

            else {

              iVar3 = _wcsicmp(L"TEX_SIZE",(wchar_t *)_Str2);

              if (iVar3 == 0) {

                FUN_007a8b00(unaff_EDI,param_1 + 0x54c,param_1 + 0x550,0);

              }

            }

            (**(code **)(*unaff_EDI + 8))(unaff_EDI);

            iVar2 = iVar2 + 1;

          } while (iVar2 < (int)unaff_EDI);

        }

        (**(code **)(*piStack_8 + 8))(piStack_8);

      }

    }

    else {

      FUN_007933a0(param_2);

    }

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_ESI);

    ExceptionList = (void *)0x0;

    return;

  }

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
