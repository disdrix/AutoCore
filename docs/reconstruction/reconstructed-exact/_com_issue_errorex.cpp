// =============================================================================
// _com_issue_errorex
// -----------------------------------------------------------------------------
// Stable ID: aa_00717f20
// Address:   0x00717f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* Library Function - Single Match
    void __stdcall _com_issue_errorex(long,struct IUnknown *,struct _GUID const &)
   
   Library: Visual Studio 2003 Debug */

void _com_issue_errorex(long param_1,IUnknown *param_2,_GUID *param_3)

{
  HRESULT HVar1;
  int iVar2;
  IErrorInfo *local_c;
  int *local_8;
  
  local_c = (IErrorInfo *)0x0;
  if ((param_2 != (IUnknown *)0x0) &&
     (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_00a14020,&local_8), -1 < HVar1)
     ) {
    iVar2 = (**(code **)(*local_8 + 0xc))(local_8,param_3);
    (**(code **)(*local_8 + 8))(local_8);
    if ((iVar2 == 0) && (HVar1 = GetErrorInfo(0,&local_c), HVar1 != 0)) {
      local_c = (IErrorInfo *)0x0;
    }
  }
  (*(code *)PTR_FUN_00af8b20)(param_1,local_c);
  return;
}
