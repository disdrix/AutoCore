// =============================================================================
// FUN_0067c030
// -----------------------------------------------------------------------------
// Stable ID: aa_0067c030
// Address:   0x0067c030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067c030 @ 0x0067c030
// Stable ID: aa_0067c030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0067c030.
//  - Return sites: 2.

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

void __thiscall FUN_0067c030(int param_1,uint param_2)



{

  uint uVar1;

  

  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + param_2;

  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;

  uVar1 = *(uint *)(param_1 + 0x3c);

  if (param_2 < *(uint *)(param_1 + 0x3c)) {

    uVar1 = param_2;

  }

  *(uint *)(param_1 + 0x3c) = uVar1;

  if (*(uint *)(param_1 + 0x34) < param_2) {

    *(uint *)(param_1 + 0x34) = param_2;

    return;

  }

  *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34);

  return;

}
