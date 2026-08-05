// =============================================================================
// FUN_007a0870
// -----------------------------------------------------------------------------
// Stable ID: aa_007a0870
// Address:   0x007a0870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a0870 @ 0x007a0870
// Stable ID: aa_007a0870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0079f640, FUN_007a0870.
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

uint32_t /* width from decompiler */ __fastcall FUN_007a0870(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(char *)(in_EAX + 0x1dc) == '\0') {

    return 1;

  }

  uVar1 = FUN_0079f640(param_2,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x1d0));

  return uVar1;

}
