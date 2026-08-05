// =============================================================================
// FUN_00411aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00411aa0
// Address:   0x00411aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00411aa0 @ 0x00411aa0
// Stable ID: aa_00411aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00411aa0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00411aa0; evidence only — no invented semantics):
//  - Entry: `float10 __fastcall FUN_00411aa0(int param_1)`.
//  - Branches: if (iVar1 < 0).
//  - Returns (1 site(s)): `fVar2 * (float10)g_flMsToSeconds_Infe...`.




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



float10 __fastcall FUN_00411aa0(int param_1)



{

  int iVar1;

  float10 fVar2;

  

  iVar1 = g_dwClientTickMs - *(int *)(param_1 + 0x178);

  fVar2 = (float10)iVar1;

  if (iVar1 < 0) {

    fVar2 = fVar2 + (float10)_DAT_00aaa5dc;

  }

  return fVar2 * (float10)g_flMsToSeconds_Inferred;

}
