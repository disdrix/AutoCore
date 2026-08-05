// =============================================================================
// FUN_0056b400
// -----------------------------------------------------------------------------
// Stable ID: aa_0056b400
// Address:   0x0056b400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056b400 @ 0x0056b400
// Stable ID: aa_0056b400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CVOGTacArc_UpdateMesh, FUN_0056b400.
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

void __thiscall FUN_0056b400(int param_1,char param_2)



{

  *(char *)(param_1 + 0xcb) = param_2;

  if (param_2 == '\0') {

    if (*(int *)(param_1 + 0xc0) != 0) {

      CVOGTacArc_UpdateMesh();

      return;

    }

  }

  else {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8) = 0;

  }

  return;

}
