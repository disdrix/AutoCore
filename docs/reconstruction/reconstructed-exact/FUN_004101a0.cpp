// =============================================================================
// FUN_004101a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004101a0
// Address:   0x004101a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004101a0 @ 0x004101a0
// Stable ID: aa_004101a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004101a0, FUN_0096c450.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x004101a0; evidence only — no invented semantics):
//  - Entry: `uint __fastcall FUN_004101a0(undefined4 param_1)`.
//  - Branches: if (*in_EAX != 0).
//  - Calls: FUN_0096c450(param_1).
//  - Returns (2 site(s)): `uVar1`; `in_EAX & 0xffffff00`.




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

uint __fastcall FUN_004101a0(uint32_t /* width from decompiler */ param_1)



{

  int *in_EAX;

  uint uVar1;

  

  if (*in_EAX != 0) {

    uVar1 = FUN_0096c450(param_1);

    return uVar1;

  }

  return (uint)in_EAX & 0xffffff00;

}
