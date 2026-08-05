// =============================================================================
// FUN_00634350
// -----------------------------------------------------------------------------
// Stable ID: aa_00634350
// Address:   0x00634350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00634350 @ 0x00634350
// Stable ID: aa_00634350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, goto×1, return×1.
//  - Notable callees: FUN_00634350.
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

void __thiscall FUN_00634350(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 0x40)) {

    piVar4 = *(int **)(param_1 + 0x3c);

    do {

      if (*piVar4 == param_2) goto LAB_00634373;

      iVar3 = iVar3 + 1;

      piVar4 = piVar4 + 1;

    } while (iVar3 < *(int *)(param_1 + 0x40));

  }

  iVar3 = -1;

LAB_00634373:

  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + -1;

  if (iVar3 < *(int *)(param_1 + 0x40)) {

    do {

      iVar2 = iVar3 * 4;

      iVar1 = iVar3 * 4;

      iVar3 = iVar3 + 1;

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + iVar1) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + 4 + iVar2);

    } while (iVar3 < *(int *)(param_1 + 0x40));

  }

  return;

}
