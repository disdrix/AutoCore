// =============================================================================
// FUN_005b04b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b04b0
// Address:   0x005b04b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b04b0 @ 0x005b04b0
// Stable ID: aa_005b04b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, goto×2, do×1, while×1, for×1.
//  - Notable callees: FUN_00418e60, FUN_005b04b0.
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

void __thiscall FUN_005b04b0(int param_1,uint param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4) + 4);

  if (iVar2 == 0) {

LAB_005b04d8:

    iVar2 = 0;

  }

  else {

    do {

      if (param_2 == *(uint *)(iVar2 + 0x10)) {

        if (iVar2 == 0) goto LAB_005b04d8;

        iVar2 = *(int *)(iVar2 + 8);

        goto LAB_005b04df;

      }

      iVar2 = *(int *)(iVar2 + 0xc);

    } while (iVar2 != 0);

    iVar2 = 0;

  }

LAB_005b04df:

  if (iVar2 != 0) {

    for (piVar3 = *(int **)(iVar2 + 0x58); piVar3 != *(int **)(iVar2 + 0x5c); piVar3 = piVar3 + 2) {

      if ((*piVar3 == param_3) && (piVar3[1] == param_4)) {

        return;

      }

    }

    iVar1 = *(int *)(iVar2 + 0x58);

    if ((iVar1 != 0) &&

       ((uint)(*(int *)(iVar2 + 0x5c) - iVar1 >> 3) < (uint)(*(int *)(iVar2 + 0x60) - iVar1 >> 3)))

    {

      piVar3 = *(int **)(iVar2 + 0x5c);

      piVar3[1] = param_4;

      *piVar3 = param_3;

      *(int **)(iVar2 + 0x5c) = piVar3 + 2;

      return;

    }

    FUN_00418e60(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x5c),1,&param_3);

  }

  return;

}
