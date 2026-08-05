// =============================================================================
// FUN_008974f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008974f0
// Address:   0x008974f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008974f0 @ 0x008974f0
// Stable ID: aa_008974f0
// Embedded strings (evidence for future rename):
//   - "SKILL_WINDOW"
//   - "NUM_SKILL_ROWS"
//   - "%d;%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: block×11, SysFreeString×3, FUN_007933a0, FUN_008974f0, _wcsicmp, swscanf, wcscmp.
//  - Strings: "SKILL_WINDOW"; "NUM_SKILL_ROWS"; "%d;%d".
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

/* WARNING: Removing unreachable block (ram,0x00897571) */

/* WARNING: Removing unreachable block (ram,0x00897588) */

/* WARNING: Removing unreachable block (ram,0x00897590) */

/* WARNING: Removing unreachable block (ram,0x008975e7) */

/* WARNING: Removing unreachable block (ram,0x008975fa) */

/* WARNING: Removing unreachable block (ram,0x00897610) */

/* WARNING: Removing unreachable block (ram,0x00897623) */

/* WARNING: Removing unreachable block (ram,0x008975d1) */

/* WARNING: Removing unreachable block (ram,0x00897637) */

/* WARNING: Removing unreachable block (ram,0x0089763c) */

/* WARNING: Removing unreachable block (ram,0x00897653) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_008974f0(int param_1,int *param_2,int param_3)



{

  int iVar1;

  BSTR unaff_EBP;

  int iStack_18;

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b9613;

  local_c = ExceptionList;

  local_4 = 0;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))();

    iVar1 = _wcsicmp(L"SKILL_WINDOW",unaff_EBP);

    if (iVar1 == 0) {

      (**(code **)(*param_2 + 0x30))(param_2);

    }

    else {

      iVar1 = wcscmp(L"NUM_SKILL_ROWS",unaff_EBP);

      if (iVar1 == 0) {

        SysFreeString(unaff_EBP);

        unaff_EBP = (BSTR)0x0;

        (**(code **)(*param_2 + 0x68))(param_2);

        iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&iStack_18);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - iStack_18;

        }

        *(int *)(param_1 + 0x514) = iStack_18;

      }

      else {

        FUN_007933a0(param_2);

      }

    }

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_EBP);

    ExceptionList = pvStack_14;

    return;

  }

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
