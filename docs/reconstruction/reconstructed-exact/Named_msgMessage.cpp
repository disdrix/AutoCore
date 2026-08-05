// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, goto×2, while×1.
//  - Notable callees: CONCAT22, FUN_00435df0, FUN_00718fd0, FUN_00719420, FUN_00768ee0, FUN_0076cec0, vog_LogMessage, wcsncpy.
//  - Strings: "Error unserializing unicode string".
//  - Return sites: 2.

// =============================================================================
// Named_msgMessage
// -----------------------------------------------------------------------------
// Stable ID: aa_00718fd0
// Address:   0x00718fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "msgMessage"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_msgMessage(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint16_t uVar1;

  uint16_t *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  wchar_t *_Dest;

  wchar_t *_Source;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20 [2];

  wchar_t *local_18;

  uint16_t *local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ab4d3;

  local_c = ExceptionList;

  _Source = (wchar_t *)0x0;

  local_18 = (wchar_t *)0x0;

  local_14 = (uint16_t *)0x0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  while( true ) {

    puVar2 = local_14;

    if (*(int *)(param_1 + 0x4044) == 0) {

      if ((*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x18) + 2) &&

         ((iVar3 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18)), iVar3 < 0 ||

          (*(int *)(param_1 + 0x20) < 2)))) {

        iVar3 = -1;

      }

      else {

        uVar1 = *(uint16_t *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c);

        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 2;

        local_24 = CONCAT22(local_24._2_2_,uVar1);

        iVar3 = 0;

      }

    }

    else {

      iVar3 = FUN_00768ee0(&local_24);

    }

    local_20[0] = local_24;

    if ((_Source == (wchar_t *)0x0) ||

       ((uint)(local_10 - (int)_Source >> 1) <= (uint)((int)puVar2 - (int)_Source >> 1))) {

      FUN_00719420(puVar2,1,local_20);

      _Source = local_18;

    }

    else {

      *puVar2 = (short)local_24;

      local_14 = puVar2 + 1;

    }

    if ((short)local_24 == 0) break;

    if (iVar3 < 0) {

LAB_007190b5:

      *param_2 = 0;

      uVar4 = FUN_0076cec0(local_20,"Error unserializing unicode string");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\msg\\msgMessage.cpp"

                     ,0x91,2,uVar4);

LAB_007190ff:

      if (_Source == (wchar_t *)0x0) {

        ExceptionList = local_c;

        return;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(_Source);

    }

  }

  if (-1 < iVar3) {

    _Dest = operator_new__(2);

    *param_2 = _Dest;

    wcsncpy(_Dest,_Source,1);

    goto LAB_007190ff;

  }

  goto LAB_007190b5;

}
