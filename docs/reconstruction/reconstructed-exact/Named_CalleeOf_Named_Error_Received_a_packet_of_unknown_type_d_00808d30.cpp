// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00808d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00808d30
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x00808d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_005201b0, FUN_00574760, FUN_00808d30, Vehicle_SetCurrentShield.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00808d30(int param_1,int param_2)



{

  int *piVar1;

  VehicleCombatPools_Inferred *pVehicle;

  int iVar2;

  int iVar3;

  byte *pbVar4;

  int *piVar5;

  int local_8;

  

  if ((*(int *)(param_2 + 0xe98) != 0) && (*(int *)(*(int *)(param_2 + 0xe98) + 0xcb0) != 0)) {

    pbVar4 = (byte *)(param_1 + 8);

    local_8 = 4;

    do {

      piVar1 = (int *)FUN_00574760(pbVar4 + (-8 - param_1));

      if (piVar1 != (int *)0x0) {

        iVar3 = piVar1[0x94];

        if ((iVar3 == 0) ||

           (piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3), piVar5 == (int *)0x0))

        {

          piVar5 = (int *)(*(int *)(piVar1[1] + 4) + 4 + (int)piVar1);

        }

        else {

          pVehicle = (VehicleCombatPools_Inferred *)(**(code **)(*piVar5 + 0x1d4))();

          if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 0xe98) + 4) + 4) +

                                          0xac + *(int *)(param_2 + 0xe98)) + 0x3c) + 0x532) == '\0'

             ) {

            iVar3 = (uint)pbVar4[4] * pVehicle->nMaxShield;

            Vehicle_SetCurrentShield(pVehicle,iVar3 / 100 + (iVar3 >> 0x1f));

          }

        }

        iVar3 = *piVar5;

        iVar2 = (**(code **)(iVar3 + 0x244))();

        (**(code **)(iVar3 + 0x240))((int)(iVar2 * (uint)*pbVar4) / 100);

        (**(code **)(*piVar1 + 0xac))

                  ((int)((uint)pbVar4[-4] * (int)*(short *)((int)piVar1 + 0x12e)) / 100);

        if (*(byte *)((int)piVar1 + 0x4f3) != pbVar4[8]) {

          FUN_005201b0(pbVar4[8]);

        }

      }

      pbVar4 = pbVar4 + 1;

      local_8 = local_8 + -1;

    } while (local_8 != 0);

    return 1;

  }

  return 0;

}
