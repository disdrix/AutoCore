// =============================================================================
// FUN_00913500
// -----------------------------------------------------------------------------
// Stable ID: aa_00913500
// Address:   0x00913500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00913500 @ 0x00913500
// Stable ID: aa_00913500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_007900e0, FUN_00913500.
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

uint32_t /* width from decompiler */ __thiscall FUN_00913500(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (param_2 == 0xd)) {

    if (DAT_00d1b958 != (int *)0x0) {

      cVar1 = (**(code **)(*DAT_00d1b958 + 0x3d8))();

      if (cVar1 != '\0') {

        uVar2 = (**(code **)(*param_1 + 0x338))(8,param_1[0x126]);

        return uVar2;

      }

    }

    if (param_1[0x12f] != 0) {

      cVar1 = (**(code **)(*(int *)param_1[0x12f] + 0x354))(0xd,param_3);

      if (cVar1 != '\0') {

        return 1;

      }

    }

    if (param_1[0x2a1] != 0) {

                    /* WARNING: Could not recover jumptable at 0x009135a1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar2 = (**(code **)(*(int *)param_1[0x2a1] + 0x338))();

      return uVar2;

    }

  }

  uVar2 = FUN_007900e0(param_2,param_3);

  return uVar2;

}
