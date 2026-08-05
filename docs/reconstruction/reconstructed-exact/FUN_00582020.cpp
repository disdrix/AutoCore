// =============================================================================
// FUN_00582020
// -----------------------------------------------------------------------------
// Stable ID: aa_00582020
// Address:   0x00582020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00582020 @ 0x00582020
// Stable ID: aa_00582020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00582020.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall FUN_00582020(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

  iVar2 = iVar1 + param_1;

  if (((*(char *)(*(int *)(*(int *)(iVar1 + 0x1c + param_1) + 0x3c) + 0x408) != '\x03') &&

      ((*(byte *)(iVar2 + 0xf2) & 4) == 0)) && (*(int *)(iVar2 + 0x88) < 1)) {

    if ((*(int **)(param_1 + -0x88) != (int *)0x0) &&

       (iVar2 = (**(code **)(**(int **)(param_1 + -0x88) + 0x48))(),

       _DAT_009d45d8 <

       *(float *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0x2c + param_1) *

       *(float *)(iVar2 + 0xc))) {

      return 0;

    }

    return 1;

  }

  return 0;

}
