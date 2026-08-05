// =============================================================================
// FUN_008433d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008433d0
// Address:   0x008433d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008433d0 @ 0x008433d0
// Stable ID: aa_008433d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_007916e0, FUN_008433d0.
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

void __thiscall FUN_008433d0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint8_t uVar2;

  uint8_t uVar3;

  

  cVar1 = (**(code **)(*param_1 + 0xd0))();

  if (cVar1 != (char)param_2) {

    uVar2 = 0;

    uVar3 = 0;

    if (param_1[0x148] != 0) {

      uVar2 = (**(code **)(*(int *)param_1[0x148] + 0xd0))();

    }

    if (param_1[0x149] != 0) {

      uVar3 = (**(code **)(*(int *)param_1[0x149] + 0xd0))();

    }

    if (param_1[0x14c] != 0) {

      (**(code **)(*(int *)param_1[0x14c] + 0xd0))();

    }

    FUN_007916e0(param_2);

    if ((char)param_2 != '\0') {

      if (param_1[0x148] != 0) {

        (**(code **)(*(int *)param_1[0x148] + 0xcc))(uVar2);

      }

      if (param_1[0x149] != 0) {

        (**(code **)(*(int *)param_1[0x149] + 0xcc))(uVar3);

      }

      if (param_1[0x14c] != 0) {

                    /* WARNING: Could not recover jumptable at 0x008434ad. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(*(int *)param_1[0x14c] + 0xcc))();

        return;

      }

    }

  }

  return;

}
