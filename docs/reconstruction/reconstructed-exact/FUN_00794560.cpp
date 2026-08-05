// =============================================================================
// FUN_00794560
// -----------------------------------------------------------------------------
// Stable ID: aa_00794560
// Address:   0x00794560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00794560 @ 0x00794560
// Stable ID: aa_00794560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×13, return×2, do×1, while×1.
//  - Notable callees: wcslen×2, FUN_007944a0, FUN_00794560, FUN_007a8230.
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

uint __thiscall FUN_00794560(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  char cVar2;

  uint uVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  size_t sVar7;

  wchar_t *pwVar8;

  wchar_t *_Str;

  int *piVar9;

  int iStack_10;

  int iStack_c;

  int iStack_4;

  

  uVar3 = (**(code **)(*param_1 + 0xd8))();

  if (((char)uVar3 == '\0') || (param_1[0xa4] == 0)) {

    return uVar3 & 0xffffff00;

  }

  if (*(char *)((int)param_1 + 0x489) == '\0') {

    iStack_10 = (int)(short)param_3;

    iStack_4 = (int)(short)((uint)param_3 >> 0x10);

    piVar4 = (int *)(**(code **)(*param_1 + 0x120))(&iStack_10,1,1);

    iStack_10 = *piVar4 + param_1[0x5c] / 2;

    iStack_c = piVar4[1] + param_1[0x5d] / 2;

    if ((param_1[0xa3] == 0) && (param_1[0x83] != 0)) {

      iVar5 = (**(code **)(*param_1 + 0x210))();

      param_1[0xa3] = iVar5;

    }

    iVar5 = param_1[0xa3];

    if (((iVar5 != 0) && (*(int *)(iVar5 + 0x84) != 0)) &&

       (*(int *)(iVar5 + 0x88) - *(int *)(iVar5 + 0x84) >> 7 != 0)) {

      piVar4 = param_1 + 0x124;

      *piVar4 = 0;

      iVar6 = FUN_007944a0();

      iVar5 = param_1[0xa3];

      piVar9 = *(int **)(iVar5 + 0x84);

      if (piVar9 != *(int **)(iVar5 + 0x88)) {

        _Str = (wchar_t *)(piVar9 + 4);

        do {

          if (*(int **)(_Str + 0xc) != (int *)0x0) {

            if (*(int *)(**(int **)(_Str + 0xc) + 0x7c) + *(int *)(_Str + -6) + iStack_c < iStack_4)

            {

              if (*(uint *)(_Str + 10) < 8) {

                sVar7 = wcslen(_Str);

                *piVar4 = *piVar4 + sVar7;

              }

              else {

                sVar7 = wcslen(*(wchar_t **)_Str);

                *piVar4 = *piVar4 + sVar7;

              }

            }

            else {

              iVar1 = *piVar4;

              pwVar8 = _Str;

              if (7 < *(uint *)(_Str + 10)) {

                pwVar8 = *(wchar_t **)_Str;

              }

              cVar2 = (**(code **)(*param_1 + 0x284))

                                (*piVar9 + iStack_10,*(int *)(_Str + -6) + iStack_c,pwVar8,

                                 (int)(short)param_3,iStack_4,piVar4,iVar1);

              if (cVar2 != '\0') {

                if ((char)piVar9[0x18] != '\0') {

                  (**(code **)(*param_1 + 800))

                            ((char)piVar9[0x18],piVar9[0x1a],piVar9[0x1b],piVar9[0x1c],piVar9[0x1d],

                             piVar9[0x1e]);

                  *piVar4 = iVar1 + 1;

                }

                break;

              }

              if ((char)_Str[0x28] != '\0') {

                *piVar4 = iVar1 + 1;

              }

            }

          }

          piVar9 = piVar9 + 0x20;

          _Str = _Str + 0x40;

        } while (piVar9 != *(int **)(iVar5 + 0x88));

      }

      if (piVar9 == *(int **)(iVar5 + 0x88)) {

        *piVar4 = iVar6;

      }

    }

  }

  uVar3 = FUN_007a8230(param_2,param_3);

  return uVar3;

}
