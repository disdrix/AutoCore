// =============================================================================
// FUN_0063a800
// -----------------------------------------------------------------------------
// Stable ID: aa_0063a800
// Address:   0x0063a800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063a800 @ 0x0063a800
// Stable ID: aa_0063a800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d68f0, FUN_005eadb0, FUN_0063a800.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_0063a800(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  *(float *)(param_1 + 0x6c) = *(float *)(param_1 + 0x6c) + _DAT_00aaab98;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = param_2[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = param_2[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = param_2[3];

  FUN_005eadb0((uint32_t /* width from decompiler */ *)(param_1 + 0x30));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc);

  FUN_005d68f0(param_1 + 0x80,param_1 + 0x20);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

  return;

}
