// =============================================================================
// FUN_0088a990
// -----------------------------------------------------------------------------
// Stable ID: aa_0088a990
// Address:   0x0088a990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088a990 @ 0x0088a990
// Stable ID: aa_0088a990
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004124c0, FUN_0088a990.
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

void __fastcall FUN_0088a990(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x540) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x548) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x550) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x554) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x53c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = DAT_00a1e3d8;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x514) = DAT_00a1e3dc;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x518) = DAT_00a1e3e0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x51c) = DAT_00a1e3e4;

  FUN_004124c0(0,0,0,0,0,0);

  return;

}
