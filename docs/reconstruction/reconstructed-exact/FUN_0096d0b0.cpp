// =============================================================================
// FUN_0096d0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d0b0
// Address:   0x0096d0b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096d0b0 @ 0x0096d0b0
// Stable ID: aa_0096d0b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0096cad0, FUN_0096d0b0.
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

uint32_t /* width from decompiler */ __fastcall FUN_0096d0b0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if ((*(uint *)(param_1 + 0x2c) & 0x3000) == 0) {

    uVar1 = FUN_0096cad0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c),

                         *(uint32_t /* width from decompiler */ *)(param_1 + 0x20),*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),

                         *(uint32_t /* width from decompiler */ *)(param_1 + 0x30),*(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

    return uVar1;

  }

  (**(code **)(**(int **)(param_1 + 0x4c) + 8))();

  return 0;

}
