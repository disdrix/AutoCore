// =============================================================================
// FUN_00910560
// -----------------------------------------------------------------------------
// Stable ID: aa_00910560
// Address:   0x00910560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00910560 @ 0x00910560
// Stable ID: aa_00910560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007562d0×2, FUN_00792490, FUN_0090fb20, FUN_0090fe50, FUN_00910560.
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

void __fastcall FUN_00910560(int *param_1)



{

  char cVar1;

  

  FUN_0090fe50();

  (**(code **)(*param_1 + 0x474))();

  if (param_1[0x288] != 0) {

    (**(code **)(*param_1 + 0x1a8))();

    FUN_007562d0();

    (**(code **)(*param_1 + 0x1a8))();

    FUN_007562d0();

    param_1[0x288] = 0;

    param_1[0x289] = 0;

  }

  if (((*(char *)((int)param_1 + 0x509) != '\0') && (DAT_00d1b8dc != (int *)0x0)) &&

     (DAT_00d1b978 != (int *)0x0)) {

    (**(code **)(*DAT_00d1b8dc + 0x440))();

    (**(code **)(*param_1 + 0xb0))(DAT_00d1b8dc);

    cVar1 = (**(code **)(*DAT_00d1b978 + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(*DAT_00d1b978 + 0x440))();

    }

    (**(code **)(*param_1 + 0xb0))(DAT_00d1b978);

  }

  FUN_0090fb20(param_1);

  FUN_00792490();

                    /* WARNING: Could not recover jumptable at 0x00910635. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x3ac))();

  return;

}
