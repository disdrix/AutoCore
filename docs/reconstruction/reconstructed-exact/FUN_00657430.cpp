// PURPOSE (auto): Scaffold unit for FUN_00657430 @ 0x00657430
// Stable ID: aa_00657430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00657430.
//  - Return sites: 1.

exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00657430 @ 0x00657430
// Stable ID: aa_00657430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

void __thiscall

FUN_00657430(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ *param_5,uint32_t /* width from decompiler */ *param_6)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = *param_6;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = param_6[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = param_6[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = param_6[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = *param_5;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = param_5[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = param_5[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = param_5[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = param_4;

  return;

}
