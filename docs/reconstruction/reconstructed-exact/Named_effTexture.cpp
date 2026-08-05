// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0096e9f0, FUN_0096f0e0, vog_LogMessage.
//  - Strings: ",0x57,3,

                   ".
//  - Return sites: 2.

// =============================================================================
// Named_effTexture
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f0e0
// Address:   0x0096f0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effTexture"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall

Named_effTexture(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = FUN_0096e9f0(param_2,param_4,param_5,param_6,param_7);

  if (iVar3 == 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTexture.cpp",0x57,3,

                   "Failed to create instance of texture.");

    return 0xffffffff;

  }

  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;

  if (*(int *)(iVar3 + 8) == 1) {

    (**(code **)(*(int *)(iVar3 + 4) + 4))();

  }

  iVar2 = *param_1;

  if (iVar2 != 0) {

    piVar1 = (int *)(iVar2 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(iVar2 + 4) + 8))();

    }

  }

  *param_1 = iVar3;

  return 0;

}
