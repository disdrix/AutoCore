// =============================================================================
// FUN_00972db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00972db0
// Address:   0x00972db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00972db0 @ 0x00972db0
// Stable ID: aa_00972db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076df50, FUN_0076e3c0, FUN_00972db0.
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

void FUN_00972db0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int unaff_ESI;

  uint8_t local_10 [16];

  

  FUN_0076e3c0(local_10,param_1,param_2,param_3);

  FUN_0076df50(unaff_ESI + 0x80,local_10,unaff_ESI + 0x80);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xbc) = 0xffffffff;

  *(int *)(unaff_ESI + 0xb4) = *(int *)(unaff_ESI + 0xb4) + 1;

  return;

}
