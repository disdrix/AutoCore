// =============================================================================
// entry
// -----------------------------------------------------------------------------
// Stable ID: aa_00489a56
// Address:   0x00489a56  (autoassault.exe, image base 0x400000)
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

/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int entry(void)

{
  byte bVar1;
  HMODULE pHVar2;
  uint32_t /* width from decompiler */ *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  uint32_t /* width from decompiler */ uVar8;
  _STARTUPINFOA local_88;
  int local_44;
  int local_40;
  int local_3c;
  char **local_38;
  char **local_34 [2];
  _startupinfo local_2c;
  byte *local_28;
  uint local_24;
  uint local_20;
  uint32_t /* width from decompiler */ uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_009c6a08;
  uStack_c = 0x489a62;
  local_24 = 0;
  pHVar2 = GetModuleHandleA((LPCSTR)0x0);
  if (((short)pHVar2->unused == 0x5a4d) &&
     (piVar6 = (int *)((int)&pHVar2->unused + pHVar2[0xf].unused), *piVar6 == 0x4550)) {
    if ((short)piVar6[6] == 0x10b) {
      if (0xe < (uint)piVar6[0x1d]) {
        iVar5 = piVar6[0x3a];
        goto LAB_00489abc;
      }
    }
    else if (((short)piVar6[6] == 0x20b) && (0xe < (uint)piVar6[0x21])) {
      iVar5 = piVar6[0x3e];
LAB_00489abc:
      local_20 = (uint)(iVar5 != 0);
      goto LAB_00489ac2;
    }
  }
  local_20 = 0;
LAB_00489ac2:
  local_8 = (undefined *)0x0;
  __set_app_type(2);
  _DAT_00d21a04 = 0xffffffff;
  DAT_00d21a08 = 0xffffffff;
  puVar3 = (uint32_t /* width from decompiler */ *)__p__fmode();
  *puVar3 = DAT_00b0329c;
  puVar3 = (uint32_t /* width from decompiler */ *)__p__commode();
  *puVar3 = DAT_00b03298;
  _DAT_00d21a00 = *(uint32_t /* width from decompiler */ *)_adjust_fdiv_exref;
  __RTC_Initialize();
  FUN_00489d6e();
  if (DAT_00aef868 == 0) {
    __setusermatherr(FUN_00489d6e);
  }
  __setdefaultprecision();
  initterm(&DAT_00aef838,&DAT_00aef83c);
  _atexit((_func_4879 *)&LAB_00489d12);
  local_2c.newmode = DAT_00b03294;
  local_40 = __getmainargs(&local_3c,&local_38,local_34,DAT_00b03290,&local_2c);
  if (local_40 < 0) {
    _amsg_exit(8);
  }
  initterm(&DAT_00aef000,&DAT_00aef834);
  pbVar7 = *(byte **)_acmdln_exref;
  while( true ) {
    bVar1 = *pbVar7;
    local_28 = pbVar7;
    if ((bVar1 < 0x21) && ((bVar1 == 0 || (local_24 == 0)))) break;
    if (bVar1 == 0x22) {
      local_24 = (uint)(local_24 == 0);
    }
    iVar5 = _ismbblead((uint)bVar1);
    if (iVar5 != 0) {
      pbVar7 = pbVar7 + 1;
    }
    pbVar7 = pbVar7 + 1;
  }
  for (; (pbVar7 = local_28, *local_28 != 0 && (*local_28 < 0x21)); local_28 = local_28 + 1) {
  }
  local_88.dwFlags = 0;
  GetStartupInfoA(&local_88);
  if ((local_88.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = (uint)local_88.wShowWindow;
  }
  uVar8 = 0;
  pHVar2 = GetModuleHandleA((LPCSTR)0x0);
  iVar5 = FUN_0094ba40(pHVar2,uVar8,pbVar7,uVar4);
  local_44 = iVar5;
  if (local_20 == 0) {
                    /* WARNING: Subroutine does not return */
    exit(iVar5);
  }
  _cexit();
  return iVar5;
}
