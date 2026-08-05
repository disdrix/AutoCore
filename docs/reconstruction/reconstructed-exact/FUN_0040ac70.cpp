// =============================================================================
// FUN_0040ac70
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ac70
// Address:   0x0040ac70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040ac70 @ 0x0040ac70
// Stable ID: aa_0040ac70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0040ac70.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x0040ac70; evidence only — no invented semantics):
//  - Entry: `undefined4 * __fastcall FUN_0040ac70(int param_1)`.
//  - Branches: if (*(param_1 + 8) != 0x0).
//  - Returns (2 site(s)): `(iVar1 + 0x80)`; `&DAT_00afdfec`.




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

uint32_t /* width from decompiler */ * __fastcall FUN_0040ac70(int param_1)



{

  int iVar1;

  

  if (*(int **)(param_1 + 8) != (int *)0x0) {

    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xc))();

    return (uint32_t /* width from decompiler */ *)(iVar1 + 0x80);

  }

  return &DAT_00afdfec;

}
