// =============================================================================
// FUN_006482d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006482d0
// Address:   0x006482d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006482d0 @ 0x006482d0
// Stable ID: aa_006482d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00638140, FUN_006482d0, FUN_0065ae80, _strlwr.
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

uint32_t /* width from decompiler */ FUN_006482d0(uint param_1,uint *param_2)



{

  char *_String;

  uint32_t /* width from decompiler */ uVar1;

  

  _String = (char *)FUN_00638140(param_1);

  _strlwr(_String);

  param_1 = 0;

  uVar1 = FUN_0065ae80(_String,&param_1);

  *param_2 = param_1 & 0xfffffffe;

  (**(code **)(*DAT_00b05060 + 4))(_String);

  return uVar1;

}
