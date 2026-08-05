// =============================================================================
// FUN_0088f000
// -----------------------------------------------------------------------------
// Stable ID: aa_0088f000
// Address:   0x0088f000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088f000 @ 0x0088f000
// Stable ID: aa_0088f000
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_0088f000.
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

void __fastcall FUN_0088f000(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int *)(unaff_ESI + 0x5a0) != 0) {

    iVar1 = **(int **)(unaff_ESI + 0x5a0);

    uVar2 = 0xffffffff;

    FUN_007a69d0(param_1,0xffffffff,1,1);

    uVar2 = FUN_007a6de0(param_1,uVar2);

    (**(code **)(iVar1 + 0x1d8))(uVar2);

                    /* WARNING: Could not recover jumptable at 0x0088f03b. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x5a0) + 0x34c))();

    return;

  }

  return;

}
