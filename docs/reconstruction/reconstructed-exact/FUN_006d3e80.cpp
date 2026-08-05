// =============================================================================
// FUN_006d3e80
// -----------------------------------------------------------------------------
// Stable ID: aa_006d3e80
// Address:   0x006d3e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d3e80 @ 0x006d3e80
// Stable ID: aa_006d3e80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006d3c20, FUN_006d3e80.
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

int __thiscall FUN_006d3e80(int param_1,int param_2)



{

  FUN_006d3c20(param_2);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x50);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x54);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x58);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x5c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x60);

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = *(uint32_t /* width from decompiler */ *)(param_2 + 100);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x68);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x6c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x70);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x74);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x78);

  *(uint8_t *)(param_1 + 0x7c) = *(uint8_t *)(param_2 + 0x7c);

  *(uint8_t *)(param_1 + 0x7d) = *(uint8_t *)(param_2 + 0x7d);

  return param_1;

}
