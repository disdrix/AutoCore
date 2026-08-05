// =============================================================================
// FUN_0067cd80
// -----------------------------------------------------------------------------
// Stable ID: aa_0067cd80
// Address:   0x0067cd80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067cd80 @ 0x0067cd80
// Stable ID: aa_0067cd80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0067cd80, FUN_0067ffb0, thunk_FUN_0076c4d0.
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

void __thiscall FUN_0067cd80(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  if (*(char *)(param_1 + 5) == '\0') {

    puVar1 = operator_new(8);

    if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar1 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      *puVar1 = param_3;

      *(uint8_t *)(puVar1 + 1) = param_2._0_1_;

    }

    param_2 = puVar1;

    FUN_0067ffb0(&param_2);

    thunk_FUN_0076c4d0();

    return;

  }

  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*param_3)(1);

  }

  return;

}
