// =============================================================================
// FUN_00805f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00805f80
// Address:   0x00805f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00805f80 @ 0x00805f80
// Stable ID: aa_00805f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00805f80, GetTickCount.
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

uint32_t /* width from decompiler */ __fastcall FUN_00805f80(int param_1)



{

  DWORD DVar1;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0xfa;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  DVar1 = GetTickCount();

  *(DWORD *)(param_1 + 0x44) = DVar1;

  return 0;

}
