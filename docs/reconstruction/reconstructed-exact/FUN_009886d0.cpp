// =============================================================================
// FUN_009886d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009886d0
// Address:   0x009886d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009886d0 @ 0x009886d0
// Stable ID: aa_009886d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0044e060, FUN_009886d0.
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

int __fastcall FUN_009886d0(int param_1)



{

  int iVar1;

  

  iVar1 = FUN_0044e060();

  *(int *)(param_1 + 4) = iVar1;

  *(uint8_t *)(iVar1 + 0x25) = 1;

  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint8_t *)(param_1 + 0x10) = 0;

  *(uint8_t *)(param_1 + 0x11) = 0;

  *(uint8_t *)(param_1 + 0x12) = 0;

  *(uint8_t *)(param_1 + 0x15) = 1;

  *(uint8_t *)(param_1 + 0x14) = 1;

  return param_1;

}
