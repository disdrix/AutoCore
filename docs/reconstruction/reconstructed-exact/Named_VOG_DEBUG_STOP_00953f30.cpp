// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×10, goto×3, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_00541a80×3, wcsstr×2, FUN_00404b30, FUN_008f8200, FUN_00953f30, _snprintf, atoi.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal"; "ID:%d Name:%S Map:%S".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00953f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00953f30
// Address:   0x00953f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x00953fc1) */



uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_00953f30(uint32_t /* width from decompiler */ param_1,char *param_2)



{

  char *_Str;

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  wchar_t *pwVar4;

  int *piVar5;

  int iVar6;

  wchar_t local_714 [128];

  wchar_t awStack_614 [260];

  char acStack_40c [1024];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b7eee;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  _Str = strtok((char *)0x0,param_2);

  if (_Str != (char *)0x0) {

    uVar1 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00404b30(_Str,uVar1);

    uStack_4 = 0;

    wcscpy(awStack_614,local_714);

    uStack_4 = 0xffffffff;

    iVar2 = atoi(_Str);

    iVar6 = 0;

    iVar3 = FUN_00541a80();

    if (*(char *)(iVar3 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar3 + 0x1d) = 1;

LAB_00954020:

    while( true ) {

      iVar3 = FUN_00541a80();

      if (*(char *)(iVar3 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar6 == 0) {

        iVar6 = *(int *)(iVar3 + 0x14);

      }

      else {

        iVar6 = *(int *)(iVar6 + 0x14);

      }

      if (iVar6 == 0) {

        piVar5 = (int *)0x0;

      }

      else {

        piVar5 = *(int **)(iVar6 + 8);

      }

      if (piVar5 == (int *)0x0) break;

      if (iVar2 == 0) goto LAB_0095407f;

      if (iVar2 == *piVar5) goto LAB_009540b8;

    }

    iVar6 = FUN_00541a80();

    *(uint8_t *)(iVar6 + 0x1d) = 0;

  }

  ExceptionList = local_c;

  return 1;

LAB_0095407f:

  pwVar4 = wcsstr((wchar_t *)(piVar5 + 0x2d),awStack_614);

  if ((pwVar4 != (wchar_t *)0x0) ||

     (pwVar4 = wcsstr((wchar_t *)(piVar5 + 7),awStack_614), pwVar4 != (wchar_t *)0x0)) {

LAB_009540b8:

    _snprintf(acStack_40c,0x400,"ID:%d Name:%S Map:%S",*piVar5,piVar5 + 0x2d,piVar5 + 7);

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200(DAT_00d1b8dc,6,"System",acStack_40c,0);

    }

  }

  goto LAB_00954020;

}
