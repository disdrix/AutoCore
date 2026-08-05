// =============================================================================
// FUN_00481330
// -----------------------------------------------------------------------------
// Stable ID: aa_00481330
// Address:   0x00481330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00481330 @ 0x00481330
// Stable ID: aa_00481330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, goto×1.
//  - Notable callees: CONCAT31, FUN_004396a0, FUN_00481330, FUN_00481430, FUN_004818d0, _stricmp.
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

int __thiscall FUN_00481330(int *param_1,int param_2)



{

  int iVar1;

  char *_Str2;

  int iVar2;

  int *piVar3;

  char *_Str1;

  uint8_t local_1c [4];

  void *local_18;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bd270;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_004818d0();

  if (iVar1 != *(int *)(param_2 + 4)) {

    _Str2 = *(char **)(iVar1 + 0xc);

    if (*(char **)(iVar1 + 0xc) == (char *)0x0) {

      _Str2 = PTR_DAT_00afa2bc;

    }

    _Str1 = (char *)*param_1;

    if ((char *)*param_1 == (char *)0x0) {

      _Str1 = PTR_DAT_00afa2bc;

    }

    iVar2 = _stricmp(_Str1,_Str2);

    if (-1 < iVar2) goto LAB_004813de;

  }

  local_4 = 0;

  FUN_004396a0(local_1c);

  local_4 = CONCAT31(local_4._1_3_,1);

  piVar3 = (int *)FUN_00481430(iVar1);

  iVar1 = *piVar3;

  if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_18);

  }

LAB_004813de:

  ExceptionList = local_c;

  return iVar1 + 0x10;

}
