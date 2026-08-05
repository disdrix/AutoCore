// =============================================================================
// FUN_00634540
// -----------------------------------------------------------------------------
// Stable ID: aa_00634540
// Address:   0x00634540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00634540 @ 0x00634540
// Stable ID: aa_00634540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004a16d0, FUN_00634540.
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

void __thiscall FUN_00634540(int param_1,int param_2)



{

  int iVar1;

  

  if ((*(int *)(param_1 + 0xc) != 0) && (g_flMultiKillCountBlend < *(float *)(param_2 + 0x10))) {

    iVar1 = FUN_004a16d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),1,0xffffffff);

    if (iVar1 != 0) {

                    /* WARNING: Could not recover jumptable at 0x00634587. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(param_1 + 8) + 0xf8))();

      return;

    }

  }

  return;

}
