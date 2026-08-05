// =============================================================================
// FUN_00867990
// -----------------------------------------------------------------------------
// Stable ID: aa_00867990
// Address:   0x00867990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00867990 @ 0x00867990
// Stable ID: aa_00867990
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00867990.
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

void __fastcall FUN_00867990(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4fc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x500) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x514) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x518) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x51c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x520) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x524) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x528) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x530) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x534) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x538) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x53c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x554) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x558) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x55c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x540) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x560) = 0;

  return;

}
