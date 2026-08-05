// =============================================================================
// FUN_0077bd20
// -----------------------------------------------------------------------------
// Stable ID: aa_0077bd20
// Address:   0x0077bd20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077bd20 @ 0x0077bd20
// Stable ID: aa_0077bd20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0077ba80, FUN_0077bc40, FUN_0077bd20.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



int FUN_0077bd20(void)



{

  int iVar1;

  int local_32e8;

  int iStack_32e4;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x77bd2a;

  iVar1 = FUN_0077bc40(&local_32e8);

  if (iVar1 == 0) {

    iVar1 = (**(code **)(&DAT_00d17a54 + local_32e8 * 0x4c))();

    if (iVar1 == 0) {

      iVar1 = (**(code **)(&DAT_00d18410 + iStack_32e4 * 100))();

      if (iVar1 == 0) {

        FUN_0077ba80(&local_32e8);

        iVar1 = 0;

      }

    }

  }

  return iVar1;

}
