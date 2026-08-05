// =============================================================================
// FUN_006a41ac
// -----------------------------------------------------------------------------
// Stable ID: aa_006a41ac
// Address:   0x006a41ac  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a41ac @ 0x006a41ac
// Stable ID: aa_006a41ac
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006a41ac.
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

void __thiscall FUN_006a41ac(int param_1,int param_2,int param_3)



{

  int *piVar1;

  uint uVar2;

  

  uVar2 = param_2 + 8U & 0xfffffff8;

  piVar1 = (int *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 4))(uVar2 * param_3 + 0x10);

  if (piVar1 != (int *)0x0) {

    piVar1[1] = 0;

    *piVar1 = param_1;

    piVar1[3] = 1;

    piVar1[2] = uVar2 - 1;

  }

  return;

}
