// =============================================================================
// FUN_008539e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008539e0
// Address:   0x008539e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008539e0 @ 0x008539e0
// Stable ID: aa_008539e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, switch×1.
//  - Notable callees: FUN_007fd420, FUN_008539e0.
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

uint32_t /* width from decompiler */ __thiscall FUN_008539e0(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint8_t auStack_10 [16];

  

  if (((39999 < param_3) && (param_3 < 0x9c44)) && (iVar2 = param_3 + -40000, iVar2 < 4)) {

    if ((param_1[iVar2 * 2 + 0x15c] & param_1[iVar2 * 2 + 0x15d]) != 0xffffffff) {

      switch(param_2) {

      case 5:

        if ((param_1[param_3 + -0x9af9] != 0) &&

           (iVar2 = CVOGReaction_ResolveObjectTarget

                              (1,param_1[iVar2 * 2 + 0x15c],param_1[iVar2 * 2 + 0x15d]), iVar2 != 0)

           ) {

          puVar3 = (uint32_t /* width from decompiler */ *)

                   (**(code **)(*(int *)param_1[param_3 + -0x9af9] + 0x140))(auStack_10,1);

          puVar4 = (uint32_t /* width from decompiler */ *)

                   (**(code **)(*(int *)param_1[param_3 + -0x9af9] + 0x120))(auStack_10,1,1);

          FUN_007fd420(*puVar4,puVar4[1],*puVar3,puVar3[1]);

        }

        return 1;

      case 6:

        DAT_00d1d8f4 = 1;

        DAT_00d1d8f5 = 0;

        if (DAT_00d1d8dc != (int *)0x0) {

          (**(code **)(*DAT_00d1d8dc + 4))(0);

        }

      case 7:

      case 8:

      case 10:

      case 0xb:

      case 0xd:

      case 0xe:

        return 1;

      }

    }

  }

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar1 != '\0') && (param_1[0xac] != 0)) {

    uVar5 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar5;

  }

  return 0;

}
