// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0044ba80, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_gfxDeviceIB_0044ba80
// -----------------------------------------------------------------------------
// Stable ID: aa_0044ba80
// Address:   0x0044ba80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxDeviceIB"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_gfxDeviceIB_0044ba80(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  piVar2 = *(int **)(*(int *)(param_1 + 4) + 0x10);

  if ((piVar2 != (int *)0x0) && (piVar3 = (int *)*piVar2, piVar3 != (int *)0x0)) {

    piVar1 = piVar2 + 3;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca,1,

                     "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");

      piVar2[3] = 0;

      return;

    }

    (**(code **)(*piVar3 + 0x30))(piVar3);

  }

  return;

}
