// =============================================================================
// FUN_00413b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00413b30
// Address:   0x00413b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00413b30 @ 0x00413b30
// Stable ID: aa_00413b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00413b30, FUN_00419b40.
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

uint32_t /* width from decompiler */ FUN_00413b30(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)

{
  int iVar1;
  
  iVar1 = FUN_00419b40(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  return *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);
}
