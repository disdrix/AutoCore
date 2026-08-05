// =============================================================================
// FUN_0043efb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043efb0
// Address:   0x0043efb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043efb0 @ 0x0043efb0
// Stable ID: aa_0043efb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0043efb0.
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

void __thiscall FUN_0043efb0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  *param_1 = &PTR_FUN_009caec8;

  param_1[1] = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  param_1[2] = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  param_1[3] = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  param_1[4] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  param_1[5] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

  param_1[6] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x18);

  param_1[7] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

  param_1[8] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20);

  param_1[9] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x24);

  param_1[10] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x28);

  return;

}
