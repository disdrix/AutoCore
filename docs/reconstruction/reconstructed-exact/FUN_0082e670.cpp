// =============================================================================
// FUN_0082e670
// -----------------------------------------------------------------------------
// Stable ID: aa_0082e670
// Address:   0x0082e670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082e670 @ 0x0082e670
// Stable ID: aa_0082e670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0082e670.
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

void __fastcall FUN_0082e670(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x528) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x538) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x540) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x548) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x550) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x554) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x558) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x55c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x560) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x564) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x568) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x56c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x570) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x574) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x578) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x57c) = 0;

  return;

}
