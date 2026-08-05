// =============================================================================
// FUN_0088d910
// -----------------------------------------------------------------------------
// Stable ID: aa_0088d910
// Address:   0x0088d910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088d910 @ 0x0088d910
// Stable ID: aa_0088d910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0083ac90, FUN_0088d910.
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

void __fastcall FUN_0088d910(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  iVar1 = param_1[0x157];

  if ((0 < iVar1) && (param_1[0x156] = param_1[0x156] + 1, iVar1 <= param_1[0x156])) {

    param_1[0x156] = iVar1 + -1;

  }

  iVar1 = *param_1;

  uVar2 = (**(code **)(iVar1 + 0x450))(param_1[0x156]);

  (**(code **)(iVar1 + 0x454))(uVar2);

  if (param_1[0x17c] != 0) {

    FUN_0083ac90(param_1[0x17c]);

  }

                    /* WARNING: Could not recover jumptable at 0x0088d96c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x460))();

  return;

}
