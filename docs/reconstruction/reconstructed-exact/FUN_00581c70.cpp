// =============================================================================
// FUN_00581c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00581c70
// Address:   0x00581c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581c70 @ 0x00581c70
// Stable ID: aa_00581c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00581c70.
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

void __thiscall FUN_00581c70(int param_1,uint32_t /* width from decompiler */ param_2)



{

  *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0x2c + param_1) = param_2;

  if (*(int **)(param_1 + -0x88) != (int *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x00581ca6. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(param_1 + -0x88) + 0x1c))();

    return;

  }

  return;

}
