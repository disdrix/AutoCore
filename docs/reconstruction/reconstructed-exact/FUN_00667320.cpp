// =============================================================================
// FUN_00667320
// -----------------------------------------------------------------------------
// Stable ID: aa_00667320
// Address:   0x00667320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00667320 @ 0x00667320
// Stable ID: aa_00667320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00665bf0, FUN_00667320.
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

void __thiscall FUN_00667320(int param_1,int param_2)



{

  FUN_00665bf0(param_2);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x90) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x94) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x98) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xa0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xa4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xa8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xac) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xb0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x100);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xb4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x104);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xb8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x108);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xbc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xc0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x110);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xc4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x114);

  *(uint32_t /* width from decompiler */ *)(param_2 + 200) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x118);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xcc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x11c);

  return;

}
