// =============================================================================
// FUN_005db090
// -----------------------------------------------------------------------------
// Stable ID: aa_005db090
// Address:   0x005db090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005db090 @ 0x005db090
// Stable ID: aa_005db090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005db090.
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

void __thiscall FUN_005db090(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  

  if (((*(char *)(param_1 + -0xe2) == '\0') && (*(char *)(param_1 + -0xe0) == '\0')) &&

     (cVar1 = (**(code **)(*(int *)(param_1 + -0x1c0) + 100))(param_2), cVar1 != '\0')) {

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x1bc + param_1) + 0x114))

              (param_2);

  }

  return;

}
