// =============================================================================
// FUN_00580e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00580e20
// Address:   0x00580e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00580e20 @ 0x00580e20
// Stable ID: aa_00580e20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, goto×1, while×1, return×1.
//  - Notable callees: CONCAT31, FUN_00580b60, FUN_00580e20.
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

void __thiscall FUN_00580e20(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  iVar1 = *(int *)(param_1 + 0x84);

  iVar2 = 0;

  if (0 < iVar1) {

    piVar3 = *(int **)(param_1 + 0x80);

    do {

      if (*piVar3 == param_2) goto LAB_00580e51;

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 1;

    } while (iVar2 < iVar1);

  }

  iVar2 = -1;

LAB_00580e51:

  FUN_00580b60(param_2,CONCAT31((int3)((uint)iVar1 >> 8),-1 < iVar2));

  if (-1 < iVar2) {

    *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x80) + iVar2 * 4) =

         *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x80) + *(int *)(param_1 + 0x84) * 4);

  }

  return;

}
