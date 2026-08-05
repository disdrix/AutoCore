// =============================================================================
// FUN_0058e0f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e0f0
// Address:   0x0058e0f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058e0f0 @ 0x0058e0f0
// Stable ID: aa_0058e0f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0058e0f0, FUN_00632390.
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

void FUN_0058e0f0(int param_1)



{

  if (param_1 != 0) {

    FUN_00632390();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  }

  return;

}
