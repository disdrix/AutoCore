// =============================================================================
// FUN_004cd600
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd600
// Address:   0x004cd600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cd600 @ 0x004cd600
// Stable ID: aa_004cd600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004b4ac0, FUN_004cd600.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004cd600(void)



{

  void *pvVar1;

  

  pvVar1 = DAT_00b037f0;

  if (DAT_00b037f0 != (void *)0x0) {

    FUN_004b4ac0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  DAT_00b037f0 = (void *)0x0;

                    /* WARNING: Could not recover jumptable at 0x004cd626. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (*_DAT_00af43c4)();

  return;

}
