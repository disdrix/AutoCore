// =============================================================================
// FUN_0040d950
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d950
// Address:   0x0040d950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040d950 @ 0x0040d950
// Stable ID: aa_0040d950
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0040d950.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040d950; evidence only — no invented semantics):
//  - Entry: `int __fastcall FUN_0040d950(undefined4 param_1,int param_2)`.
//  - Branches: if (*(param_2 + 8) <= uVar2).
//  - Returns (1 site(s)): `*(*(param_2 + 4) + uVar2 * 4) + (*(pa...`.




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

int __fastcall FUN_0040d950(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  

  uVar2 = *(uint *)(param_2 + 0xc) >> 2;

  iVar1 = uVar2 * -4;

  if (*(uint *)(param_2 + 8) <= uVar2) {

    uVar2 = uVar2 - *(uint *)(param_2 + 8);

  }

  return *(int *)(*(int *)(param_2 + 4) + uVar2 * 4) + (*(uint *)(param_2 + 0xc) + iVar1) * 4;

}
