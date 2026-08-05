// =============================================================================
// FUN_0068d240
// -----------------------------------------------------------------------------
// Stable ID: aa_0068d240
// Address:   0x0068d240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068d240 @ 0x0068d240
// Stable ID: aa_0068d240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0068c330, FUN_0068cfe0, FUN_0068d240.
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

void __thiscall FUN_0068d240(int param_1,int *param_2,int param_3,int param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (param_3 != param_4) {

    uVar1 = FUN_0068c330(param_4,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3,param_2);

    FUN_0068cfe0(uVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1,param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar1;

  }

  *param_2 = param_3;

  return;

}
