// =============================================================================
// FUN_0064f7a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0064f7a0
// Address:   0x0064f7a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064f7a0 @ 0x0064f7a0
// Stable ID: aa_0064f7a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0064f7a0, FUN_0065e650.
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

void FUN_0064f7a0(int param_1)



{

  if (param_1 != 0) {

    FUN_0065e650();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0x80000000;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0x80000000;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  }

  return;

}
