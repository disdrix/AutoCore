// =============================================================================
// FUN_00574a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00574a30
// Address:   0x00574a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00574a30 @ 0x00574a30
// Stable ID: aa_00574a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, while×1, if×1.
//  - Notable callees: FUN_00520330, FUN_00574a30.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_00574a30(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);

  iVar2 = 0;

  piVar3 = (int *)(param_1 + 0x198);

  while ((*piVar3 != *(int *)(iVar1 + 0x164 + param_2) ||

         (piVar3[1] != *(int *)(iVar1 + 0x168 + param_2)))) {

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 4;

    if (3 < iVar2) {

      return 0;

    }

  }

  *(int *)((iVar2 + 0x1a) * 0x10 + param_1) = param_2;

  FUN_00520330(param_1);

  return 1;

}
