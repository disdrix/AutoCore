// =============================================================================
// FUN_0083ed70
// -----------------------------------------------------------------------------
// Stable ID: aa_0083ed70
// Address:   0x0083ed70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083ed70 @ 0x0083ed70
// Stable ID: aa_0083ed70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0083ed70.
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

void __fastcall FUN_0083ed70(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb50) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb64) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb70) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb74) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x514) = 0;

  return;

}
