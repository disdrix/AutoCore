// =============================================================================
// FUN_0096da40
// -----------------------------------------------------------------------------
// Stable ID: aa_0096da40
// Address:   0x0096da40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096da40 @ 0x0096da40
// Stable ID: aa_0096da40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0043f5e0, FUN_0096da40, FUN_00972fa0.
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

void __fastcall FUN_0096da40(int *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint8_t auStack_c [12];

  

  uVar1 = (**(code **)(*param_1 + 0x48))();

  (**(code **)(*param_1 + 0xc))(uVar1);

  FUN_00972fa0(uVar1);

  (**(code **)(*param_1 + 0x48))();

  (**(code **)(*param_1 + 0xc))();

  FUN_0043f5e0(auStack_c);

  return;

}
