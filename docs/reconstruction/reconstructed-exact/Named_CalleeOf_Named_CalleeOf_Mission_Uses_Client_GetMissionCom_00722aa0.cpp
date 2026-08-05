// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_00722aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00722aa0
// Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00722aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×9, goto×3, do×2, while×2, return×1.
//  - Notable callees: FUN_007227e0, FUN_00722aa0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_00722aa0(int param_1,uint param_2,uint param_3,char param_4,byte *param_5)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  int iVar4;

  int extraout_ECX;

  int *piVar5;

  byte *pbVar6;

  bool bVar7;

  float10 fVar8;

  int local_4;

  

  if ((*(char *)(param_1 + 600) != '\0') && (local_4 = 0, 0 < *(int *)(param_1 + 0x210))) {

    piVar5 = (int *)(param_1 + 0x31c);

    do {

      iVar2 = *piVar5;

      if (iVar2 != 0) {

        if (((param_2 == *(uint *)(iVar2 + 0x40)) && (param_3 == *(uint *)(iVar2 + 0x44))) &&

           (param_4 == *(char *)(iVar2 + 0x35))) {

LAB_00722b2d:

          if ((*(char *)(iVar2 + 0x1c5) != '\0') && (*(char *)(iVar2 + 0x36) != '\0')) {

            fVar8 = (float10)FUN_007227e0(0);

            *(float *)(iVar2 + 0x1b0) = (float)fVar8;

            *(uint8_t *)(*piVar5 + 0x38) = 1;

            param_1 = extraout_ECX;

          }

        }

        else if ((param_2 & param_3) == 0xffffffff) {

          pbVar3 = (byte *)(iVar2 + 0x48);

          pbVar6 = param_5;

          do {

            bVar1 = *pbVar3;

            bVar7 = bVar1 < *pbVar6;

            if (bVar1 != *pbVar6) {

LAB_00722b24:

              iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);

              goto LAB_00722b29;

            }

            if (bVar1 == 0) break;

            bVar1 = pbVar3[1];

            bVar7 = bVar1 < pbVar6[1];

            if (bVar1 != pbVar6[1]) goto LAB_00722b24;

            pbVar3 = pbVar3 + 2;

            pbVar6 = pbVar6 + 2;

          } while (bVar1 != 0);

          iVar4 = 0;

LAB_00722b29:

          if (iVar4 == 0) goto LAB_00722b2d;

        }

      }

      local_4 = local_4 + 1;

      piVar5 = piVar5 + 1;

    } while (local_4 < *(int *)(param_1 + 0x210));

  }

  return 0;

}
