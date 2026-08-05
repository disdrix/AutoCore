// =============================================================================
// FUN_00780c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00780c30
// Address:   0x00780c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00780c30 @ 0x00780c30
// Stable ID: aa_00780c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00780c30.
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

void __fastcall FUN_00780c30(int param_1)



{

  int iVar1;

  int iVar2;

  

  if ((*(int *)(param_1 + 0x208) != 0) || (*(char *)(param_1 + 0x214) != '\0')) {

    iVar2 = 0;

    if (0 < *(int *)(param_1 + 0x210)) {

      do {

        iVar1 = *(int *)(*(int *)(param_1 + 0x208) + iVar2 * 4);

        *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + 1;

        if ((*(uint *)(iVar1 + 0x28) & 2) == 0) {

          *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xfffffffe;

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < *(int *)(param_1 + 0x210));

    }

    if (*(int **)(param_1 + 0x228) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x228) + 0x24))(param_1);

    }

  }

  return;

}
