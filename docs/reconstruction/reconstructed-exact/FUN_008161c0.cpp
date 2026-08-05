// =============================================================================
// FUN_008161c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008161c0
// Address:   0x008161c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008161c0 @ 0x008161c0
// Stable ID: aa_008161c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007f5120, FUN_008161c0.
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

void __fastcall FUN_008161c0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int *)(param_1 + 0x80c) != 0) {

    iVar1 = **(int **)(param_1 + 0x80c);

    uVar2 = FUN_007f5120(1,1);

    (**(code **)(iVar1 + 0x1d8))(uVar2);

                    /* WARNING: Could not recover jumptable at 0x008161fc. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(param_1 + 0x80c) + 0x34c))();

    return;

  }

  return;

}
