// =============================================================================
// FUN_00710a80
// -----------------------------------------------------------------------------
// Stable ID: aa_00710a80
// Address:   0x00710a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00710a80 @ 0x00710a80
// Stable ID: aa_00710a80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_00710a80, FUN_00711680.
//  - Return sites: 4.

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



uint32_t /* width from decompiler */ FUN_00710a80(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (param_1 == (int *)0x0) {

    return 0x181a;

  }

  piVar1 = (int *)*param_1;

  if ((piVar1 != (int *)0x0) && (*piVar1 == 0xface)) {

    if ((char)piVar1[3] != '\n') {

      return 0x17e3;

    }

    _DAT_00d09848 = _DAT_00d09848 + -1;

    puVar2 = (uint32_t /* width from decompiler */ *)*param_1;

    *puVar2 = 0;

    FUN_00711680(puVar2 + 4);

    if (puVar2[9] != 0) {

      (*(code *)PTR_free_00af8a4c)(puVar2[9]);

      puVar2[9] = 0;

    }

    if (puVar2[10] != 0) {

      (*(code *)PTR_free_00af8a4c)(puVar2[10]);

      puVar2[10] = 0;

    }

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)PTR_free_00af8a4c)(puVar2);

    }

    *param_1 = 0;

    return 0;

  }

  return 0x17d4;

}
