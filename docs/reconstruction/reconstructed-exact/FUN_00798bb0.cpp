// =============================================================================
// FUN_00798bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00798bb0
// Address:   0x00798bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00798bb0 @ 0x00798bb0
// Stable ID: aa_00798bb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: SysFreeString×4, CONCAT31, FUN_004048e0, FUN_00798bb0, SysAllocString, wcscpy.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00798bb0(int *param_1,OLECHAR *param_2)



{

  BSTR bstrString;

  int iVar1;

  void *unaff_ESI;

  int *unaff_EDI;

  wchar_t *unaff_retaddr;

  BSTR pOVar2;

  uint8_t local_14 [4];

  BSTR local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  BSTR local_4;

  

  local_4 = (BSTR)0xffffffff;

  puStack_8 = &LAB_009ac344;

  pvStack_c = ExceptionList;

  if (param_2 == (OLECHAR *)0x0) {

    local_10 = (BSTR)0x0;

    ExceptionList = &pvStack_c;

  }

  else {

    ExceptionList = &pvStack_c;

    local_10 = SysAllocString(param_2);

    if (local_10 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0(0x8007000e);

    }

  }

  bstrString = local_10;

  local_4 = (BSTR)0x0;

  pOVar2 = local_10;

  iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,local_10,local_14);

  if ((-1 < iVar1) && (unaff_EDI != (int *)0x0)) {

    local_4 = (BSTR)0x0;

    local_10 = (BSTR)CONCAT31(local_10._1_3_,1);

    iVar1 = (**(code **)(*unaff_EDI + 0x68))(unaff_EDI,&local_4);

    (**(code **)(*(int *)pOVar2 + 8))(pOVar2);

    if (-1 < iVar1) {

      wcscpy(unaff_retaddr,local_4);

      SysFreeString(local_4);

      SysFreeString(bstrString);

      ExceptionList = unaff_ESI;

      return 1;

    }

    SysFreeString(local_4);

  }

  SysFreeString(bstrString);

  ExceptionList = unaff_ESI;

  return 0;

}
