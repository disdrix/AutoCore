// =============================================================================
// FUN_00522060
// -----------------------------------------------------------------------------
// Stable ID: aa_00522060
// Address:   0x00522060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522060 @ 0x00522060
// Stable ID: aa_00522060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, do×1, while×1.
//  - Notable callees: FUN_005711c0×6, FUN_00599dd0×3, FUN_00522060.
//  - Return sites: 4.

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

bool __thiscall FUN_00522060(int param_1,int param_2,int *param_3,char param_4,char param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  *param_3 = 0;

  if ((((*(int *)(param_1 + 0x250) == 0) || (*(int *)(*(int *)(param_1 + 0x250) + 0x2b0) == 0)) ||

      (*(int *)(param_1 + 0xcbc) == 0)) || (*(int *)(param_2 + 0x38) != 0x1a)) {

    return false;

  }

  iVar2 = *(int *)(param_2 + 0x3c);

  if (iVar2 == 0) {

    return false;

  }

  if (param_5 != '\0') {

    iVar1 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x4c0),0);

    *param_3 = iVar1;

    iVar2 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x4c0),0);

    *param_3 = *param_3 + iVar2;

    return *param_3 != 0;

  }

  if ((param_4 != '\x01') && ('\0' < *(char *)(iVar2 + 0x4d4))) {

    iVar1 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x4d0),0);

    iVar3 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x4d0),0);

    if ((int)*(char *)(iVar2 + 0x4d4) <= iVar1 + iVar3) {

      *param_3 = *param_3 + (iVar1 + iVar3) / (int)*(char *)(iVar2 + 0x4d4);

    }

  }

  if (param_4 != '\x02') {

    iVar1 = FUN_00599dd0();

    if (0 < iVar1) {

      _param_4 = -1;

      param_2 = 0;

      iVar1 = FUN_00599dd0();

      if (0 < iVar1) {

        _param_5 = (int *)(iVar2 + 0x498);

        do {

          iVar2 = *_param_5;

          if (iVar2 != -1) {

            iVar1 = FUN_005711c0(iVar2,0);

            iVar2 = FUN_005711c0(iVar2,0);

            iVar1 = iVar1 + iVar2;

            if ((_param_4 == -1) || (iVar1 <= _param_4)) {

              _param_4 = iVar1;

            }

            if (iVar1 < 1) break;

          }

          _param_5 = _param_5 + 1;

          param_2 = param_2 + 1;

          iVar2 = FUN_00599dd0();

        } while (param_2 < iVar2);

        if (0 < _param_4) {

          *param_3 = *param_3 + _param_4;

        }

      }

    }

  }

  return 0 < *param_3;

}
