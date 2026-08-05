// =============================================================================
// FUN_0090c920
// -----------------------------------------------------------------------------
// Stable ID: aa_0090c920
// Address:   0x0090c920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090c920 @ 0x0090c920
// Stable ID: aa_0090c920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007916e0, FUN_0090c810, FUN_0090c920.
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

void __thiscall FUN_0090c920(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  FUN_007916e0(param_2);

  if ((char)param_2 != '\0') {

    iVar1 = FUN_0090c810();

    if (((*(int *)(param_1 + 0x5a0) != 0) && (DAT_00d1b6d8 != 0)) && (iVar1 < 0x19)) {

                    /* WARNING: Could not recover jumptable at 0x0090c966. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(param_1 + 0x5a0) + 0xcc))();

      return;

    }

  }

  return;

}
