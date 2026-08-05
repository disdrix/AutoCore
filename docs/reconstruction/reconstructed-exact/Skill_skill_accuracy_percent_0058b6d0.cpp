// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×15, return×2.
//  - Notable callees: FUN_005781b0×13, FUN_0058b6d0.
//  - Strings: "max_hp] (additive)\n"; "max_hp] (percent)\n"; "power_cost] (percent)\n"; "max_power] (additive)\n".
//  - Return sites: 2.

// =============================================================================
// Skill_skill_accuracy_percent_0058b6d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058b6d0
// Address:   0x0058b6d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "skill_accuracy] (percent)
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Skill_skill_accuracy_percent_0058b6d0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char *pcVar1;

  

  if (*(float *)(param_1 + 0x4c) != g_flZero) {

    if (g_flOne < *(float *)(param_1 + 0x4c)) {

      pcVar1 = "max_hp] (additive)\n";

    }

    else {

      pcVar1 = "max_hp] (percent)\n";

    }

    FUN_005781b0(param_3,param_2,pcVar1,1);

  }

  if (*(float *)(param_1 + 0x44) != g_flZero) {

    FUN_005781b0(param_3,param_2,"power_cost] (percent)\n",1);

  }

  if (*(float *)(param_1 + 0x48) != g_flZero) {

    if (g_flOne < *(float *)(param_1 + 0x48)) {

      pcVar1 = "max_power] (additive)\n";

    }

    else {

      pcVar1 = "max_power] (percent)\n";

    }

    FUN_005781b0(param_3,param_2,pcVar1,1);

  }

  if (*(float *)(param_1 + 0xc0) != g_flZero) {

    FUN_005781b0(param_3,param_2,"criticals_vs_vehicles] (percent)\n",1);

  }

  if (*(float *)(param_1 + 0xc4) != g_flZero) {

    FUN_005781b0(param_3,param_2,"criticals_vs_creatures] (percent)\n",1);

  }

  if (*(float *)(param_1 + 200) != g_flZero) {

    FUN_005781b0(param_3,param_2,"criticals_def_vehicles] (percent)\n",1);

  }

  if (*(float *)(param_1 + 0xcc) != g_flZero) {

    FUN_005781b0(param_3,param_2,"criticals_def_creatures] (percent)\n",1);

  }

  if (*(float *)(param_1 + 0xf8) != g_flZero) {

    FUN_005781b0(param_3,param_2,"accuracy_bonus] (additive)\n",1);

  }

  if (*(float *)(param_1 + 0xfc) != g_flZero) {

    FUN_005781b0(param_3,param_2,"defense_bonus] (additive)\n",1);

  }

  if (*(float *)(param_1 + 0x100) != g_flZero) {

    FUN_005781b0(param_3,param_2,"penetration_bonus] (additive)\n",1);

  }

  if (*(float *)(param_1 + 0x104) != g_flZero) {

    FUN_005781b0(param_3,param_2,"deflection_bonus] (additive)\n",1);

  }

  if (*(float *)(param_1 + 0x24) != g_flZero) {

    if (*(float *)(param_1 + 0x24) == DAT_00aaa668) {

      FUN_005781b0(param_3,param_2,"always_hits)\n",0);

      return 0;

    }

    FUN_005781b0(param_3,param_2,"skill_accuracy] (percent)\n",1);

  }

  return 0;

}
