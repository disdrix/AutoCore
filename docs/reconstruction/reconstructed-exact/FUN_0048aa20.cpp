// =============================================================================
// FUN_0048aa20
// -----------------------------------------------------------------------------
// Stable ID: aa_0048aa20
// Address:   0x0048aa20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048aa20 @ 0x0048aa20
// Stable ID: aa_0048aa20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0048a890, FUN_0048aa20, memmove.
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

int * __thiscall FUN_0048aa20(int *param_1,void *param_2,size_t param_3)



{

  uint uVar1;

  uint uVar2;

  

  uVar1 = ((int *)*param_1)[1];

  uVar2 = *(int *)*param_1 + param_3;

  if (uVar1 < uVar2) {

    FUN_0048a890(uVar1 + uVar2);

  }

  memmove((void *)(*(int *)*param_1 + 8 + *param_1),param_2,param_3);

  *(uint *)*param_1 = uVar2;

  *(uint8_t *)(*param_1 + 8 + uVar2) = 0;

  return param_1;

}
