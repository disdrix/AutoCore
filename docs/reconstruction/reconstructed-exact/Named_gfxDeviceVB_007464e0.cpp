// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007464e0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_gfxDeviceVB_007464e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007464e0
// Address:   0x007464e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxDeviceVB"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_gfxDeviceVB_007464e0(int *param_1)



{

  int *piVar1;

  int *piVar2;

  

  piVar2 = (int *)*param_1;

  if (piVar2 != (int *)0x0) {

    piVar1 = param_1 + 4;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                     "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

      param_1[4] = 0;

      return;

    }

    (**(code **)(*piVar2 + 0x30))(piVar2);

  }

  return;

}
