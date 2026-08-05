// =============================================================================
// FUN_00449680
// -----------------------------------------------------------------------------
// Stable ID: aa_00449680
// Address:   0x00449680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00449680 @ 0x00449680
// Stable ID: aa_00449680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, while×1.
//  - Notable callees: FUN_00415e90, FUN_0043fd70, FUN_00449680, FUN_00449a90.
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

void FUN_00449680(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3)



{

  int *piVar1;

  int in_EAX;

  

  if ((param_2 == (int *)**(int **)(in_EAX + 8)) && (param_3 == *(int **)(in_EAX + 8))) {

    FUN_00415e90();

    FUN_00449a90(9);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20) = 1;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x24) = 1;

    *param_1 = **(uint32_t /* width from decompiler */ **)(in_EAX + 8);

    return;

  }

  while (param_2 != param_3) {

    piVar1 = (int *)*param_2;

    FUN_0043fd70(param_2);

    param_2 = piVar1;

  }

  *param_1 = param_2;

  return;

}
