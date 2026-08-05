// =============================================================================
// FUN_0066cb40
// -----------------------------------------------------------------------------
// Stable ID: aa_0066cb40
// Address:   0x0066cb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066cb40 @ 0x0066cb40
// Stable ID: aa_0066cb40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0066cb40, FUN_0066e660.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0066cb40(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  FUN_0066e660(param_2);

  *param_1 = &PTR_FUN_009e7ab8;

  param_1[2] = &PTR_LAB_009e7aa8;

  param_1[0xc] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20);

  param_1[0xd] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x24);

  param_1[8] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  param_1[9] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

  param_1[10] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x18);

  param_1[0xb] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

  return param_1;

}
