// =============================================================================
// FUN_00496110
// -----------------------------------------------------------------------------
// Stable ID: aa_00496110
// Address:   0x00496110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00496110 @ 0x00496110
// Stable ID: aa_00496110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_004507a0, FUN_00496110.
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

void __thiscall FUN_00496110(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  

  piVar3 = (int *)**(int **)(param_2 + 4);

  if (piVar3 != *(int **)(param_2 + 4)) {

    do {

      if (piVar3[2] != 0) {

        piVar1 = (int *)(piVar3[2] + 0x140);

        *piVar1 = *piVar1 + 1;

        iVar2 = *(int *)(param_1 + 0xac);

        if ((iVar2 == 0) ||

           ((uint)(*(int *)(param_1 + 0xb4) - iVar2 >> 2) <=

            (uint)(*(int *)(param_1 + 0xb0) - iVar2 >> 2))) {

          FUN_004507a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb0),1,piVar3 + 2);

        }

        else {

          piVar1 = *(int **)(param_1 + 0xb0);

          *piVar1 = piVar3[2];

          *(int **)(param_1 + 0xb0) = piVar1 + 1;

        }

      }

      piVar3 = (int *)*piVar3;

    } while (piVar3 != (int *)*(int *)(param_2 + 4));

  }

  return;

}
