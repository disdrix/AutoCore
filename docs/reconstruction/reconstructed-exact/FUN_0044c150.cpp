// =============================================================================
// FUN_0044c150
// -----------------------------------------------------------------------------
// Stable ID: aa_0044c150
// Address:   0x0044c150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044c150 @ 0x0044c150
// Stable ID: aa_0044c150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_0044c150, _aligned_malloc.
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

void __fastcall FUN_0044c150(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int *local_4;

  

  if (((int *)*param_1 == (int *)0x0) || (*(int *)*param_1 == 0)) {

    local_4 = param_1;

    piVar1 = _aligned_malloc(24000,0x10);

    local_4 = piVar1;

    CVOGReaction_FailMissionNotify(&local_4);

    *param_1 = (int)piVar1;

    iVar3 = 499;

    piVar2 = piVar1;

    do {

      iVar3 = iVar3 + -1;

      *piVar2 = (int)(piVar2 + 0xc);

      piVar2 = piVar2 + 0xc;

    } while (iVar3 != 0);

    piVar1[0x1764] = 0;

  }

  *param_1 = *(int *)*param_1;

  return;

}
