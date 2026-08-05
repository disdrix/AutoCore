// =============================================================================
// FUN_006a2360
// -----------------------------------------------------------------------------
// Stable ID: aa_006a2360
// Address:   0x006a2360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a2360 @ 0x006a2360
// Stable ID: aa_006a2360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0069a020, FUN_006a2360.
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

int __thiscall FUN_006a2360(int param_1,int param_2)



{

  if (param_2 != param_1) {

    FUN_0069a020(param_2);

    *(uint8_t *)(param_1 + 0x10) = *(uint8_t *)(param_2 + 0x10);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

    *(uint8_t *)(param_1 + 0x18) = *(uint8_t *)(param_2 + 0x18);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x24);

    *(uint8_t *)(param_1 + 0x40) = *(uint8_t *)(param_2 + 0x40);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x44);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x48);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x30);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x34);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x38);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c);

  }

  return param_1;

}
