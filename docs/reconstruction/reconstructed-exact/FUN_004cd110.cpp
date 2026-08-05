// =============================================================================
// FUN_004cd110
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd110
// Address:   0x004cd110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cd110 @ 0x004cd110
// Stable ID: aa_004cd110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004cd110, FUN_005d8400, FUN_005d85c0, FUN_005d8fc0.
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

void __fastcall FUN_004cd110(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  

  uVar1 = FUN_005d8fc0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe4a4),0,0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4a8) = uVar1;

  FUN_005d85c0(0x61a9);

  FUN_005d8400(0x200000);

  return;

}
