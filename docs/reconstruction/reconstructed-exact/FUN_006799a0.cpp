// =============================================================================
// FUN_006799a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006799a0
// Address:   0x006799a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006799a0 @ 0x006799a0
// Stable ID: aa_006799a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006799a0.
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

uint32_t /* width from decompiler */ __thiscall

FUN_006799a0(int param_1,uint32_t /* width from decompiler */ param_2,uint8_t param_3,char param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  *(uint8_t *)(param_1 + 0x14) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = param_5;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = param_6;

  *(char *)(param_1 + 0x16) = param_4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = param_7;

  *(bool *)(param_1 + 0x15) = param_4 == '\0';

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = param_8;

  return 0;

}
