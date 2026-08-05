// =============================================================================
// FUN_00562c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00562c70
// Address:   0x00562c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00562c70 @ 0x00562c70
// Stable ID: aa_00562c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×2.
//  - Notable callees: fwrite×19, FUN_00562c70.
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

uint32_t /* width from decompiler */ __thiscall FUN_00562c70(int param_1,FILE *param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *_Str;

  int iVar4;

  int iStack_18;

  int iStack_14;

  int iStack_10;

  RACE_ID_INFERRED aRStack_8 [2];

  

  if (param_2 != (FILE *)0x0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x1dc + param_1) + 0xac))

              (param_2);

    fwrite((void *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x15c + param_1),0x10,1,param_2);

    fwrite((void *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x14c + param_1),0x10,1,param_2);

    fwrite((void *)(param_1 + -0x144),4,1,param_2);

    fwrite((void *)(param_1 + -0x15c),4,1,param_2);

    fwrite((void *)(param_1 + -0x160),4,1,param_2);

    fwrite((void *)(param_1 + -0x138),1,1,param_2);

    fwrite((void *)(param_1 + -0x137),1,1,param_2);

    fwrite((void *)(param_1 + -0x12f),1,1,param_2);

    fwrite((void *)(param_1 + -0x12e),1,1,param_2);

    fwrite(&stack0x00000000,1,1,param_2);

    fwrite((void *)(param_1 + -0x37),1,1,param_2);

    iVar3 = 0;

    piVar2 = (int *)(param_1 + -0xf0);

    iStack_18 = 0;

    iStack_14 = 0;

    iVar4 = 0;

    do {

      if (*piVar2 == -1) {

        if (iStack_14 < iVar3) {

          iVar4 = (0xf0 - param_1) + (int)piVar2;

          iVar3 = iStack_14;

          iStack_18 = iStack_14;

        }

      }

      else {

        if (iStack_14 != iVar3) {

          piVar1 = (int *)(iVar4 + -0xf4 + param_1);

          *piVar1 = piVar2[-1];

          piVar1[1] = *piVar2;

          piVar1[2] = piVar2[1];

          piVar2[-1] = 0;

          *piVar2 = 0;

          piVar2[1] = 0;

          *piVar2 = -1;

          iVar3 = iStack_18;

        }

        iVar3 = iVar3 + 1;

        iVar4 = iVar4 + 0xc;

        iStack_18 = iVar3;

      }

      iStack_14 = iStack_14 + 1;

      piVar2 = piVar2 + 3;

    } while (iStack_14 < 0xc);

    _Str = (uint32_t /* width from decompiler */ *)(param_1 + -0xf4);

    iStack_10 = 0xc;

    do {

      if (_Str[1] == -1) {

        *_Str = 0;

        _Str[1] = 0;

        _Str[2] = 0;

        _Str[1] = 0xffffffff;

      }

      fwrite(_Str,0xc,1,param_2);

      _Str = _Str + 3;

      iStack_10 = iStack_10 + -1;

    } while (iStack_10 != 0);

    fwrite((void *)(param_1 + -0x40),4,1,param_2);

    fwrite((void *)(param_1 + -0x3c),4,1,param_2);

    fwrite((void *)(param_1 + -0x140),8,1,param_2);

    fwrite((void *)(param_1 + -0x164),4,1,param_2);

    fwrite((void *)(param_1 + -0x38),1,1,param_2);

    aRStack_8[0] = Object_GetRootRaceId

                             ((void *)(*(int *)(*(int *)(param_1 + -0x1dc) + 4) + -0x1dc + param_1))

    ;

    fwrite(aRStack_8,4,1,param_2);

    fwrite((void *)(param_1 + -0x28),4,1,param_2);

    return 1;

  }

  return 0;

}
