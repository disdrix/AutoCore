// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00449ff0, FUN_0046c1b0, FUN_0074dba0, RemoveAnimation, vog_LogMessage.
//  - Strings: ",

                   0xfa,1,".
//  - Return sites: 2.

// =============================================================================
// Named_anmPriorityBlendController_0074dba0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074dba0
// Address:   0x0074dba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "anmPriorityBlendController"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_anmPriorityBlendController_0074dba0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int *local_4;

  

  local_4 = param_1;

  FUN_0046c1b0();

  piVar1 = local_4;

  if (local_4 == (int *)param_1[5]) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmPriorityBlendController.cpp",

                   0xfa,1,"RemoveAnimation() called with animation that is not added to controller!"

                  );

    return 0;

  }

  (**(code **)(*param_1 + 0x3c))(param_2,local_4 + 3);

  FUN_00449ff0(&local_4,piVar1);

  return param_2;

}
