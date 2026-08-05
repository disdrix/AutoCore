// =============================================================================
// FUN_0040ae10
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ae10
// Address:   0x0040ae10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040ae10 @ 0x0040ae10
// Stable ID: aa_0040ae10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0040ae10.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040ae10; evidence only — no invented semantics):
//  - Entry: `void FUN_0040ae10(int *param_1)`.
//  - Branches: if (param_1 != 0x0); if (*piVar1 == 0).
//  - Returns (1 site(s)): `void`.
//  - Assign `local_c = ExceptionList`.
//  - Assign `local_4 = 0xffffffff`.
//  - Assign `param_1 = *param_1`.




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

void FUN_0040ae10(int *param_1)



{

  int *piVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bc5d2;

  local_c = ExceptionList;

  local_4 = 0xffffffff;

  param_1 = (int *)*param_1;

  if (param_1 != (int *)0x0) {

    piVar1 = param_1 + 1;

    ExceptionList = &local_c;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*param_1 + 8))();

    }

  }

  ExceptionList = local_c;

  return;

}
