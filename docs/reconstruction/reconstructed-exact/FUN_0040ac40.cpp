// =============================================================================
// FUN_0040ac40
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ac40
// Address:   0x0040ac40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040ac40 @ 0x0040ac40
// Stable ID: aa_0040ac40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0040ac40.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x0040ac40; evidence only — no invented semantics):
//  - Entry: `uint __fastcall FUN_0040ac40(int param_1)`.
//  - Branches: if (*(*(param_1 + 0xa8) + 0x38) == 4) → return 999999; if (uVar1 == 0).
//  - Returns (2 site(s)): `999999`; `uVar2`.




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

uint __fastcall FUN_0040ac40(int param_1)



{

  ushort uVar1;

  uint uVar2;

  

  if (*(int *)(*(int *)(param_1 + 0xa8) + 0x38) == 4) {

    return 999999;

  }

  uVar1 = *(ushort *)(*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x4ba);

  uVar2 = (uint)uVar1;

  if (uVar1 == 0) {

    uVar2 = 200;

  }

  return uVar2;

}
