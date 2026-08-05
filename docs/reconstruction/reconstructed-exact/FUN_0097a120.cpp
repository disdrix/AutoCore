// =============================================================================
// FUN_0097a120
// -----------------------------------------------------------------------------
// Stable ID: aa_0097a120
// Address:   0x0097a120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097a120 @ 0x0097a120
// Stable ID: aa_0097a120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, goto×1.
//  - Notable callees: FUN_007a7500, FUN_007fd1c0, FUN_0097a120.
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

uint32_t /* width from decompiler */ __thiscall FUN_0097a120(int *param_1,int param_2,int param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *extraout_EDX;

  uint8_t local_10 [16];

  

  if (param_3 == 0x9c41) {

    if (param_2 == 5) {

      if (((*(char *)((int)param_1 + 0xce) != '\0') && (param_1[0xa2] != 0)) &&

         (param_1[0x140] != 0)) {

        puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x140] + 0x140))(local_10,1);

        (**(code **)(*(int *)param_1[0x140] + 0x120))(local_10,1,1);

        FUN_007a7500();

        FUN_007fd1c0(*extraout_EDX,extraout_EDX[1],*puVar3,puVar3[1]);

      }

    }

    else {

      if (param_2 != 6) goto LAB_0097a144;

      DAT_00d1d8fe = 1;

      DAT_00d1d8ff = 0;

      if (DAT_00d1d8f0 != (int *)0x0) {

        (**(code **)(*DAT_00d1d8f0 + 4))(0);

        return 1;

      }

    }

    return 1;

  }

LAB_0097a144:

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar1 != '\0') && (param_1[0xac] != 0)) {

    uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar2;

  }

  return 0;

}
