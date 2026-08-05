// =============================================================================
// FUN_005ec620
// -----------------------------------------------------------------------------
// Stable ID: aa_005ec620
// Address:   0x005ec620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ec620 @ 0x005ec620
// Stable ID: aa_005ec620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_005ec620, FUN_005ee030.
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

void __thiscall FUN_005ec620(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint *param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  *param_4 = 0;

  if (*(int *)(param_2 + 0xc) != 0) {

    do {

      piVar1 = *(int **)(param_1 + 0x14);

      iVar3 = *(int *)(param_2 + 0x10 + *param_4 * 4) * 0xc;

      iVar2 = **(int **)(param_1 + 0x10);

      FUN_005ee030(iVar2 + *(int *)(iVar3 + *piVar1) * 0xc,

                   iVar2 + *(int *)(*piVar1 + iVar3 + 4) * 0xc,

                   iVar2 + *(int *)(*piVar1 + iVar3 + 8) * 0xc);

      *param_4 = *param_4 + 1;

    } while (*param_4 < *(uint *)(param_2 + 0xc));

  }

  return;

}
