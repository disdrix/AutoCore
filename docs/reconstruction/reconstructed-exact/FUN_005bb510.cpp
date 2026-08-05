// =============================================================================
// FUN_005bb510
// -----------------------------------------------------------------------------
// Stable ID: aa_005bb510
// Address:   0x005bb510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005bb510 @ 0x005bb510
// Stable ID: aa_005bb510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×9, return×6.
//  - Notable callees: FUN_005bb510.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ __thiscall FUN_005bb510(int *param_1,int param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  

  if (*param_1 != 0) {

    return 1;

  }

  if (param_1[0x28a] != 0) {

    if (param_2 != 0) {

      if (((param_1[1] != 0) && (piVar1 = *(int **)(param_1[1] + 0x10), piVar1 != (int *)0x0)) &&

         (*(int *)(param_2 + 0xe8a0) != 0)) {

        if (param_1[0x234] == 2) {

          iVar3 = (**(code **)(*piVar1 + 0x210))(0);

          if (iVar3 != 0) {

            iVar3 = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

          }

          if (iVar3 != *(int *)(param_2 + 0xe8a0)) {

            return 0;

          }

        }

        else if ((param_1[0x234] == 4) &&

                (cVar2 = (**(code **)(*piVar1 + 0x298))(*(int *)(param_2 + 0xe8a0)), cVar2 != '\0'))

        {

          return 0;

        }

      }

      if ((((short)param_1[0x236] != 0) && (*(char *)(param_2 + 0x7d) == '\0')) &&

         ((*(int *)(param_2 + 0x78) != 0 &&

          (((int)(short)param_1[0x236] &

           1 << ((byte)*(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x78) + 0x150) & 0x1f)) == 0)))) {

        return 0;

      }

    }

    return 1;

  }

  return 0;

}
