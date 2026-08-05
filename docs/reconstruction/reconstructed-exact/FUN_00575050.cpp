// =============================================================================
// FUN_00575050
// -----------------------------------------------------------------------------
// Stable ID: aa_00575050
// Address:   0x00575050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00575050 @ 0x00575050
// Stable ID: aa_00575050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_00575050.
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

uint __thiscall FUN_00575050(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  

  piVar1 = *(int **)(param_1 + 0x1e0);

  piVar3 = (int *)*piVar1;

  if (piVar3 != piVar1) {

    iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);

    do {

      if ((piVar3[2] == *(int *)(iVar2 + 0x164 + param_2)) &&

         (piVar3[3] == *(int *)(iVar2 + 0x168 + param_2))) {

        if (piVar3 != *(int **)(param_1 + 0x1e0)) {

          *(int *)piVar3[1] = *piVar3;

          *(int *)(*piVar3 + 4) = piVar3[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar3);

        }

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xcb4) = 0;

        return CONCAT31((int3)((uint)piVar3 >> 8),1);

      }

      piVar3 = (int *)*piVar3;

    } while (piVar3 != piVar1);

  }

  return (uint)piVar3 & 0xffffff00;

}
