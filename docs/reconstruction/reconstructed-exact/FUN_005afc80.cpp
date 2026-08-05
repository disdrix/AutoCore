// =============================================================================
// FUN_005afc80
// -----------------------------------------------------------------------------
// Stable ID: aa_005afc80
// Address:   0x005afc80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005afc80 @ 0x005afc80
// Stable ID: aa_005afc80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×7, goto×2, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_005afc80, FUN_005b08d0, memmove.
//  - Return sites: 1.

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

void __thiscall FUN_005afc80(int param_1,int *param_2,int param_3,int param_4)



{

  int *piVar1;

  int *_Dst;

  void *pvVar2;

  int iVar3;

  

  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & (uint)param_2) * 4)

                  + 4);

  if (iVar3 == 0) {

LAB_005afcab:

    iVar3 = 0;

  }

  else {

    do {

      if (param_2 == *(int **)(iVar3 + 0x10)) {

        if (iVar3 == 0) goto LAB_005afcab;

        iVar3 = *(int *)(iVar3 + 8);

        goto LAB_005afcb2;

      }

      iVar3 = *(int *)(iVar3 + 0xc);

    } while (iVar3 != 0);

    iVar3 = 0;

  }

LAB_005afcb2:

  if (iVar3 != 0) {

    piVar1 = *(int **)(iVar3 + 0x5c);

    for (_Dst = *(int **)(iVar3 + 0x58); _Dst != piVar1; _Dst = _Dst + 2) {

      if ((*_Dst == param_3) && (_Dst[1] == param_4)) {

        if (_Dst != piVar1) {

          FUN_005b08d0(&param_2,_Dst + 2,piVar1,_Dst,&param_3);

          _Dst = param_2;

        }

        break;

      }

    }

    if (_Dst != *(int **)(iVar3 + 0x5c)) {

      pvVar2 = memmove(_Dst,*(int **)(iVar3 + 0x5c),0);

      *(void **)(iVar3 + 0x5c) = pvVar2;

    }

  }

  return;

}
