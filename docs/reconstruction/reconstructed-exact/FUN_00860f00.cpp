// =============================================================================
// FUN_00860f00
// -----------------------------------------------------------------------------
// Stable ID: aa_00860f00
// Address:   0x00860f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00860f00 @ 0x00860f00
// Stable ID: aa_00860f00
// Embedded strings (evidence for future rename):
//   - "SHOW_GRID_LINES"
//   - "true"
//   - "POINT_GRID_640"
//   - "POINT_GRID_800"
//   - "POINT_GRID_1024"
//   - "POINT_GRID_1280"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×12, goto×5, return×2.
//  - Notable callees: _wcsicmp×12, FUN_007a8b00×5, SysFreeString×3, FUN_007933a0, FUN_00860f00.
//  - Strings: "SHOW_GRID_LINES"; "true"; "POINT_GRID_640"; "POINT_GRID_800".
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

void __thiscall FUN_00860f00(int param_1,int *param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  void *unaff_ESI;

  BSTR unaff_EDI;

  float fVar3;

  float fVar4;

  float fVar5;

  uint32_t /* width from decompiler */ unaff_retaddr;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b8760;

  local_c = ExceptionList;

  local_10 = 0;

  local_4 = 0;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    local_4 = 0xffffffff;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  (**(code **)(*param_2 + 0x1c))(param_2,&local_10);

  iVar1 = _wcsicmp(L"SHOW_GRID_LINES",unaff_EDI);

  if (iVar1 == 0) {

    SysFreeString(unaff_EDI);

    unaff_EDI = (BSTR)0x0;

    (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe8);

    iVar1 = _wcsicmp(L"true",(wchar_t *)0x0);

    *(bool *)(param_1 + 0x4fc) = iVar1 == 0;

    goto LAB_008611b1;

  }

  iVar1 = _wcsicmp(L"POINT_GRID_640",unaff_EDI);

  if (iVar1 == 0) {

    piVar2 = (int *)(param_1 + 0x514);

    param_1 = param_1 + 0x518;

LAB_00860fc2:

    FUN_007a8b00(param_2,piVar2,param_1,0);

    fVar3 = (float)*piVar2;

    fVar5 = (float)DAT_00d1e818;

  }

  else {

    iVar1 = _wcsicmp(L"POINT_GRID_800",unaff_EDI);

    if (iVar1 == 0) {

      piVar2 = (int *)(param_1 + 0x51c);

      FUN_007a8b00(param_2,piVar2,param_1 + 0x520,0);

      fVar3 = (float)DAT_00d1e818;

      fVar5 = (float)*piVar2;

    }

    else {

      iVar1 = _wcsicmp(L"POINT_GRID_1024",unaff_EDI);

      if (iVar1 == 0) {

        piVar2 = (int *)(param_1 + 0x524);

        param_1 = param_1 + 0x528;

        goto LAB_00860fc2;

      }

      iVar1 = _wcsicmp(L"POINT_GRID_1280",unaff_EDI);

      if (iVar1 == 0) {

        piVar2 = (int *)(param_1 + 0x52c);

        FUN_007a8b00(param_2,piVar2,param_1 + 0x530,0);

        fVar3 = (float)DAT_00d1e818;

        fVar5 = (float)*piVar2;

      }

      else {

        iVar1 = _wcsicmp(L"POINT_GRID_1600",unaff_EDI);

        if (iVar1 == 0) {

          piVar2 = (int *)(param_1 + 0x534);

          param_1 = param_1 + 0x538;

          goto LAB_00860fc2;

        }

        iVar1 = _wcsicmp(L"SIZE_GRID_640",unaff_EDI);

        if (iVar1 == 0) {

          piVar2 = (int *)(param_1 + 0x53c);

          FUN_007a8b00(param_2,piVar2,param_1 + 0x540,0);

          fVar3 = (float)DAT_00d1e818;

          fVar5 = (float)*piVar2;

        }

        else {

          iVar1 = _wcsicmp(L"SIZE_GRID_800",unaff_EDI);

          if (iVar1 != 0) {

            iVar1 = _wcsicmp(L"SIZE_GRID_1024",unaff_EDI);

            if (iVar1 == 0) {

              piVar2 = (int *)(param_1 + 0x54c);

              param_1 = param_1 + 0x550;

            }

            else {

              iVar1 = _wcsicmp(L"SIZE_GRID_1280",unaff_EDI);

              if (iVar1 == 0) {

                piVar2 = (int *)(param_1 + 0x554);

                param_1 = param_1 + 0x558;

              }

              else {

                iVar1 = _wcsicmp(L"SIZE_GRID_1600",unaff_EDI);

                if (iVar1 != 0) {

                  FUN_007933a0(param_2,unaff_retaddr);

                  goto LAB_008611b1;

                }

                piVar2 = (int *)(param_1 + 0x55c);

                param_1 = param_1 + 0x560;

              }

            }

            goto LAB_00860fc2;

          }

          piVar2 = (int *)(param_1 + 0x544);

          FUN_007a8b00(param_2,piVar2,param_1 + 0x548,0);

          fVar3 = (float)DAT_00d1e818;

          fVar5 = (float)*piVar2;

        }

      }

    }

  }

  fVar4 = (float)piVar2[1] * (float)DAT_00d1e81c * DAT_00aaa678;

  *piVar2 = (int)(fVar3 * fVar5 * DAT_00aaa67c);

  piVar2[1] = (int)fVar4;

LAB_008611b1:

  local_c = (void *)0xffffffff;

  SysFreeString(unaff_EDI);

  ExceptionList = unaff_ESI;

  return;

}
