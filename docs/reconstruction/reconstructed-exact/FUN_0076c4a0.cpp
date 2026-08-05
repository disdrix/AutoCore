// =============================================================================
// FUN_0076c4a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c4a0
// Address:   0x0076c4a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076c4a0 @ 0x0076c4a0
// Stable ID: aa_0076c4a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076c4a0, rdtsc.
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

void __fastcall FUN_0076c4a0(int param_1)



{

  uint64_t uVar1;

  

  uVar1 = rdtsc();

  *(int *)(param_1 + 0x10) = (int)uVar1;

  *(int *)(param_1 + 0x14) = (int)((ulonglong)uVar1 >> 0x20);

  *(uint8_t *)(param_1 + 0x18) = 0;

  return;

}
