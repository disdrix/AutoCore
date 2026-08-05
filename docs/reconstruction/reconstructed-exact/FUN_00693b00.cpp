// =============================================================================
// FUN_00693b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00693b00
// Address:   0x00693b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00693b00 @ 0x00693b00
// Stable ID: aa_00693b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00691d80, FUN_00693b00.
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

void FUN_00693b00(int param_1,int param_2,int param_3)



{

  for (; param_1 != param_2; param_1 = param_1 + 0x30) {

    FUN_00691d80(param_3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x10);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x14);

    *(uint8_t *)(param_1 + 0x18) = *(uint8_t *)(param_3 + 0x18);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x1c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c);

  }

  return;

}
