// =============================================================================
// FUN_0096ab50
// -----------------------------------------------------------------------------
// Stable ID: aa_0096ab50
// Address:   0x0096ab50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096ab50 @ 0x0096ab50
// Stable ID: aa_0096ab50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, for×1, return×1, goto×1, while×1.
//  - Notable callees: FUN_0096a9d0, FUN_0096ab50, memmove.
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

int FUN_0096ab50(int param_1)



{

  int *piVar1;

  size_t _Size;

  int iVar2;

  int iVar3;

  int iVar4;

  void *pvVar5;

  int iVar6;

  int *piVar7;

  int *_Dst;

  int unaff_EBX;

  int iVar8;

  

  iVar4 = FUN_0096a9d0(param_1);

  iVar8 = *(int *)(unaff_EBX + 0xc);

  _Dst = (int *)(iVar8 + param_1 * 4);

  piVar7 = (int *)(iVar8 + (iVar4 + param_1) * 4);

  iVar2 = *(int *)(*_Dst + 0x14c);

  iVar3 = *(int *)(*_Dst + 0x148);

  if (iVar3 != -1) {

    piVar1 = (int *)(*(int *)(iVar8 + iVar3 * 4) + 0x150);

    *piVar1 = *piVar1 + -1;

  }

  if (_Dst != piVar7) {

    _Size = (*(int *)(unaff_EBX + 0x10) - (int)piVar7 >> 2) * 4;

    pvVar5 = memmove(_Dst,piVar7,_Size);

    *(void **)(unaff_EBX + 0x10) = (void *)((int)pvVar5 + _Size);

  }

  piVar7 = *(int **)(unaff_EBX + 0xc);

  iVar8 = 0;

  do {

    if (piVar7 == _Dst) {

      piVar7 = *(int **)(unaff_EBX + 0x10);

      for (; _Dst != piVar7; _Dst = _Dst + 1) {

        iVar2 = *_Dst;

        iVar3 = *(int *)(iVar2 + 0x148);

        if ((iVar3 != -1) && (param_1 < iVar3)) {

          *(int *)(iVar2 + 0x148) = iVar3 - iVar4;

        }

        if (*(int *)(iVar2 + 0x14c) != -1) {

          *(int *)(iVar2 + 0x14c) = *(int *)(iVar2 + 0x14c) - iVar4;

        }

        *(int *)(iVar2 + 0x144) = iVar8;

        iVar8 = iVar8 + 1;

      }

      *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + 1;

      *(uint *)(unaff_EBX + 4) = *(uint *)(unaff_EBX + 4) | 3;

      return iVar4;

    }

    iVar3 = *piVar7;

    iVar6 = *(int *)(iVar3 + 0x14c);

    if (iVar6 == param_1) {

      iVar6 = -1;

      if (iVar2 == -1) {

LAB_0096abe2:

        *(int *)(iVar3 + 0x14c) = iVar6;

      }

    }

    else if (param_1 < iVar6) {

      iVar6 = iVar6 - iVar4;

      goto LAB_0096abe2;

    }

    *(int *)(iVar3 + 0x144) = iVar8;

    piVar7 = piVar7 + 1;

    iVar8 = iVar8 + 1;

  } while( true );

}
