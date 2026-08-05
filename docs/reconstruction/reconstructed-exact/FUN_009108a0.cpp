// =============================================================================
// FUN_009108a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009108a0
// Address:   0x009108a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009108a0 @ 0x009108a0
// Stable ID: aa_009108a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_009108a0, NDUIWindow_ReloadInterface.
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

void __thiscall FUN_009108a0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  NDUIWindow_ReloadInterface(param_2);

  if (DAT_00d1b9a8 != (int *)0x0) {

    (**(code **)(*DAT_00d1b9a8 + 0x28))(0);

    (**(code **)(*DAT_00d1b9a8 + 0x118))(&stack0xfffffff4);

  }

  (**(code **)(*param_1 + 0x46c))(param_1[0xab]);

  return;

}
