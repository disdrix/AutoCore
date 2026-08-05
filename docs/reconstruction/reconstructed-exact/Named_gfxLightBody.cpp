// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0073c0a0, FUN_0096e430, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightBody.cpp"; "Failed to Initialize Light Implementation".
//  - Return sites: 2.

// =============================================================================
// Named_gfxLightBody
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e430
// Address:   0x0096e430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxLightBody"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_gfxLightBody(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  (**(code **)(*param_1 + 0x5c))();

  piVar3 = (int *)FUN_0073c0a0();

  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = (int *)param_1[0x23];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  param_1[0x23] = (int)piVar3;

  if (piVar3 == (int *)0x0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightBody.cpp",0x32,3,

                   "Failed to Initialize Light Implementation");

    return 0xffffffff;

  }

  return 0;

}
