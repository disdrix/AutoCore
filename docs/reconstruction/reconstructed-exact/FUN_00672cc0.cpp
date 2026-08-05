// =============================================================================
// FUN_00672cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00672cc0
// Address:   0x00672cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00672cc0 @ 0x00672cc0
// Stable ID: aa_00672cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00672440, FUN_00672cc0, FUN_006802d0.
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

uint32_t /* width from decompiler */ __fastcall FUN_00672cc0(int param_1)



{

  int *piVar1;

  uint8_t *puVar2;

  uint8_t local_8 [4];

  uint8_t local_4 [4];

  

  if ((*(char *)(param_1 + 0x96c) != '\0') &&

     (piVar1 = *(int **)(param_1 + 0x98), piVar1 != (int *)0x0)) {

    puVar2 = local_4;

    (**(code **)(*piVar1 + 0x10))(piVar1,puVar2,local_8);

    if (puVar2 != (uint8_t *)0x0) {

      FUN_00672440();

    }

    FUN_006802d0(3,0);

    *(uint8_t *)(param_1 + 0x96c) = 0;

  }

  return 0;

}
