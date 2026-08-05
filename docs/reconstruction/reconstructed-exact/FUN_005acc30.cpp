// =============================================================================
// FUN_005acc30
// -----------------------------------------------------------------------------
// Stable ID: aa_005acc30
// Address:   0x005acc30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005acc30 @ 0x005acc30
// Stable ID: aa_005acc30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_005acc30, FUN_005adff0, FUN_005ae140.
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

int __thiscall FUN_005acc30(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (*(char *)(param_1 + 0x6c) != '\0') {

    local_4 = param_3;

    local_8 = param_2;

    piVar2 = (int *)FUN_005ae140(&local_8);

    piVar1 = *(int **)(param_1 + 0x74);

    if (piVar2 != (int *)*piVar1) {

      FUN_005adff0();

    }

    if (piVar2 != piVar1) {

      return piVar2[6];

    }

  }

  return 0;

}
