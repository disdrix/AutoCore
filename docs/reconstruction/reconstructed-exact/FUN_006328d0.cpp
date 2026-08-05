// =============================================================================
// FUN_006328d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006328d0
// Address:   0x006328d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006328d0 @ 0x006328d0
// Stable ID: aa_006328d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006328d0.
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

void __fastcall FUN_006328d0(int param_1)



{

  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x2c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x18) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x18))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  return;

}
