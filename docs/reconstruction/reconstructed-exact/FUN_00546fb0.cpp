// =============================================================================
// FUN_00546fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00546fb0
// Address:   0x00546fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00546fb0 @ 0x00546fb0
// Stable ID: aa_00546fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_00546fb0, FUN_005483f0.
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

void __thiscall FUN_00546fb0(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x16c) = 2;

  if (*(int *)(param_1 + 0x13c) == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x13c) >> 2;

  }

  iVar1 = 0;

  if (0 < iVar3) {

    piVar2 = *(int **)(param_1 + 0x13c);

    do {

      if (*piVar2 == param_2) break;

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar1 < iVar3);

  }

  for (; iVar1 < iVar3 + -1; iVar1 = iVar1 + 1) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x13c) + iVar1 * 4) =

         *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x13c) + 4 + iVar1 * 4);

    *(char *)(*(int *)(*(int *)(param_1 + 0x13c) + iVar1 * 4) + 0x14) = (char)iVar1;

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x13c) + iVar1 * 4) + 0x150) = 2;

  }

  FUN_005483f0(iVar3 + -1,0);

  *(char *)(param_1 + 0x130) = *(char *)(param_1 + 0x130) + -1;

  return;

}
