// =============================================================================
// FUN_008b2db0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b2db0
// Address:   0x008b2db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b2db0 @ 0x008b2db0
// Stable ID: aa_008b2db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: FUN_008b2db0.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_008b2db0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (param_1[0x1ad] != 0) {

    cVar1 = (**(code **)(*(int *)param_1[0x1ad] + 0xd8))();

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(*(int *)param_1[0x1ad] + 0xd0))();

      if (cVar1 != '\0') {

        if (0 < (short)((uint)param_2 >> 0x10)) {

          (**(code **)(*(int *)param_1[0x1ad] + 0x45c))(0xbf800000);

          return 1;

        }

        (**(code **)(*(int *)param_1[0x1ad] + 0x45c))(0x3f800000);

        return 1;

      }

    }

  }

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (param_1[0x12e] != 0)) {

                    /* WARNING: Could not recover jumptable at 0x008b2e38. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))();

    return uVar2;

  }

  return 0;

}
