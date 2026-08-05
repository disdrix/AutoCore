// =============================================================================
// FUN_0064ee50
// -----------------------------------------------------------------------------
// Stable ID: aa_0064ee50
// Address:   0x0064ee50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064ee50 @ 0x0064ee50
// Stable ID: aa_0064ee50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0064ecd0, FUN_0064ee50.
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

void __fastcall FUN_0064ee50(int param_1)



{

  if (-1 < (int)*(uint *)(param_1 + 0x48)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),*(uint *)(param_1 + 0x48) & 0x7fffffff,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x3c)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),*(int *)(param_1 + 0x3c) * 4,0x12);

  }

  if (-1 < *(int *)(param_1 + 0x30)) {

    (**(code **)(*DAT_00b05060 + 0x14))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x28),*(int *)(param_1 + 0x30) * 4,0x12);

  }

  FUN_0064ecd0();

  return;

}
