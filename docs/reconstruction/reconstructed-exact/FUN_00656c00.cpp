// =============================================================================
// FUN_00656c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00656c00
// Address:   0x00656c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00656c00 @ 0x00656c00
// Stable ID: aa_00656c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00656c00.
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

void __thiscall

FUN_00656c00(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4,

            uint32_t /* width from decompiler */ param_5)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = *param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = param_2[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = param_2[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = param_2[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = *param_4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = param_4[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = param_4[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = param_4[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = *param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = param_3[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = param_3[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = param_3[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = param_5;

  return;

}
