// =============================================================================
// FUN_00553d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00553d20
// Address:   0x00553d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00553d20 @ 0x00553d20
// Stable ID: aa_00553d20
// Embedded strings (evidence for future rename):
//   - "Failed to load weather FX: %s"
//   - "env_time_midday"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: NDSpecialFX_LoadFromScriptName×2, FUN_004b8dc0, FUN_004b9270, FUN_004b99c0, FUN_00553d20, FUN_007a4480.
//  - Strings: "Failed to load weather FX: %s"; "env_time_midday".
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

uint32_t /* width from decompiler */ __thiscall FUN_00553d20(char *param_1,char param_2)



{

  void *pvVar1;

  

  if (param_2 != '\0') {

    pvVar1 = *(void **)(param_1 + 0x104);

    if (pvVar1 != (void *)0x0) {

      FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    param_1[0x104] = '\0';

    param_1[0x105] = '\0';

    param_1[0x106] = '\0';

    param_1[0x107] = '\0';

  }

  if ((*(int *)(param_1 + 0x104) == 0) && (*param_1 != '\0')) {

    pvVar1 = NDSpecialFX_LoadFromScriptName(param_1,0,0);

    *(void **)(param_1 + 0x104) = pvVar1;

    if (pvVar1 == (void *)0x0) {

      FUN_007a4480(1,"Failed to load weather FX: %s",param_1);

      pvVar1 = NDSpecialFX_LoadFromScriptName("env_time_midday",0,0);

      *(void **)(param_1 + 0x104) = pvVar1;

    }

    if (*(int *)(param_1 + 0x104) != 0) {

      *(uint8_t *)(*(int *)(param_1 + 0x104) + 9) = 1;

      FUN_004b8dc0(0,0);

      FUN_004b9270(*(uint32_t /* width from decompiler */ *)(param_1 + 0x104));

    }

  }

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0x104);

}
