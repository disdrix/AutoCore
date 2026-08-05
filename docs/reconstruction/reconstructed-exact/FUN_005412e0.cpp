// =============================================================================
// FUN_005412e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005412e0
// Address:   0x005412e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005412e0 @ 0x005412e0
// Stable ID: aa_005412e0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×1, for×1, while×1.
//  - Notable callees: FUN_0049bfb0, FUN_004e53a0, FUN_005412e0, FUN_00544020, FUN_005453b0, FUN_007a4480, FUN_007bca30, memmove.
//  - Strings: "VOG_DEBUG_STOP".
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

void __thiscall FUN_005412e0(int param_1,void *param_2)



{

  size_t _Size;

  int *_Src;

  int *piVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  int *local_c;

  int local_8;

  int local_4;

  

  local_8 = param_1;

  param_2 = (void *)FUN_004e53a0(param_2);

  if (param_2 == (void *)0x0) {

    return;

  }

  FUN_005453b0(*(uint32_t /* width from decompiler */ *)((int)param_2 + 0x1c),&param_2);

  iVar3 = 7;

  local_4 = 0x21;

  do {

    pvVar2 = param_2;

    param_1 = (*(int *)((int)param_2 + 0x18) + iVar3) * 0x10 + param_1;

    _Src = *(int **)(param_1 + 0x18);

    for (piVar1 = *(int **)(param_1 + 0x14); piVar1 != _Src; piVar1 = piVar1 + 1) {

      if ((void *)*piVar1 == param_2) {

        if (piVar1 != _Src) {

          FUN_0049bfb0(&local_c,piVar1 + 1,_Src,piVar1,&param_2);

          piVar1 = local_c;

        }

        break;

      }

    }

    local_c = piVar1;

    iVar4 = (*(int *)((int)pvVar2 + 0x18) + 1 + iVar3) * 0x10 + local_8;

    if (local_c != _Src) {

      _Size = (*(int *)(iVar4 + 8) - (int)_Src >> 2) * 4;

      pvVar2 = memmove(local_c,_Src,_Size);

      *(void **)(iVar4 + 8) = (void *)((int)pvVar2 + _Size);

      pvVar2 = param_2;

    }

    iVar3 = iVar3 + 7;

    local_4 = local_4 + -1;

    param_1 = local_8;

    if (local_4 == 0) {

      iVar3 = FUN_007bca30(*(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x1c));

      if (iVar3 < 0) {

        FUN_007a4480(0,"VOG_DEBUG_STOP");

        return;

      }

      FUN_00544020();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

  } while( true );

}
