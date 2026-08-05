// =============================================================================
// FUN_008a5dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a5dd0
// Address:   0x008a5dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a5dd0 @ 0x008a5dd0
// Stable ID: aa_008a5dd0
// Embedded strings (evidence for future rename):
//   - "MISSION_WINDOW"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: block×9, SysFreeString×2, FUN_007933a0, FUN_008a5dd0, _wcsicmp.
//  - Strings: "MISSION_WINDOW".
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

/* WARNING: Removing unreachable block (ram,0x008a5e73) */

/* WARNING: Removing unreachable block (ram,0x008a5e8a) */

/* WARNING: Removing unreachable block (ram,0x008a5e90) */

/* WARNING: Removing unreachable block (ram,0x008a5efc) */

/* WARNING: Removing unreachable block (ram,0x008a5f0f) */

/* WARNING: Removing unreachable block (ram,0x008a5ed5) */

/* WARNING: Removing unreachable block (ram,0x008a5f34) */

/* WARNING: Removing unreachable block (ram,0x008a5f66) */

/* WARNING: Removing unreachable block (ram,0x008a5f7d) */



void FUN_008a5dd0(int *param_1,int param_2)



{

  int iVar1;

  wchar_t *unaff_ESI;

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b98d2;

  local_c = ExceptionList;

  local_4 = 0;

  if ((param_1 != (int *)0x0) && (param_2 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_1 + 0x1c))();

    iVar1 = _wcsicmp(L"MISSION_WINDOW",unaff_ESI);

    if (iVar1 == 0) {

      (**(code **)(*param_1 + 0x30))(param_1);

    }

    else {

      FUN_007933a0(param_1);

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
