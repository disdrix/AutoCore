// =============================================================================
// FUN_005d8450
// -----------------------------------------------------------------------------
// Stable ID: aa_005d8450
// Address:   0x005d8450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d8450 @ 0x005d8450
// Stable ID: aa_005d8450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005d8450.
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

uint32_t /* width from decompiler */ * __fastcall FUN_005d8450(uint32_t /* width from decompiler */ *param_1)



{

  byte unaff_retaddr;

  

  *param_1 = &PTR_FUN_009db1c4;

  (**(code **)(*DAT_00b05060 + 4))(DAT_00bc5640);

  DAT_00bc5640 = 0;

  DAT_00bc564c = 0;

  DAT_00bc5644 = 0;

  DAT_00bc5648 = 0;

  *param_1 = &PTR_LAB_009cc290;

  if ((unaff_retaddr & 1) != 0) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(uint16_t *)(param_1 + 1),0x16);

  }

  return param_1;

}
