// =============================================================================
// FUN_00902590
// -----------------------------------------------------------------------------
// Stable ID: aa_00902590
// Address:   0x00902590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00902590 @ 0x00902590
// Stable ID: aa_00902590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_00902590.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall FUN_00902590(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (param_1[0x14a] != 0) {

    cVar1 = (**(code **)(*(int *)param_1[0x14a] + 0xd8))();

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(*(int *)param_1[0x14a] + 0xd0))();

      if (cVar1 != '\0') {

        if ((short)((uint)param_2 >> 0x10) < 1) {

          (**(code **)(*(int *)param_1[0x14a] + 0x45c))(0x3f800000);

        }

        else {

          (**(code **)(*(int *)param_1[0x14a] + 0x45c))(0xbf800000);

        }

        if (*(int *)(param_1[0x143] + 0x670) != 0) {

          (**(code **)(**(int **)(param_1[0x143] + 0x670) + 0xd4))(0);

          (**(code **)(**(int **)(param_1[0x143] + 0x670) + 0x34c))();

        }

        return 1;

      }

    }

  }

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (param_1[0x12e] != 0)) {

                    /* WARNING: Could not recover jumptable at 0x0090264d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))();

    return uVar2;

  }

  return 0;

}
