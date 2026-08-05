// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×9, for×3, while×2, do×1, goto×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_0053fff0×3, CVOGCharacter_CheckMissionPrerequisites, FUN_00403430, FUN_00404840, FUN_0040fb90, FUN_00418700, FUN_00536740.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00536740
// -----------------------------------------------------------------------------
// Stable ID: aa_00536740
// Address:   0x00536740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_VOG_DEBUG_STOP_00536740(void *param_1,uint param_2,uint param_3)



{

  uint *puVar1;

  uint uMissionID;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int local_1c [2];

  int *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3d0c;

  pvStack_c = ExceptionList;

  iVar5 = 0;

  ExceptionList = &pvStack_c;

  piVar2 = (int *)FUN_0040fb90();

  local_10 = 0;

  local_4 = 0;

  local_14 = piVar2;

  piVar3 = (int *)FUN_0053fff0();

  iVar4 = *piVar3;

  if (*(char *)(iVar4 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar4 + 0x1d) = 1;

  while( true ) {

    piVar3 = (int *)FUN_0053fff0();

    iVar4 = *piVar3;

    if (*(char *)(iVar4 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar5 == 0) {

      iVar5 = *(int *)(iVar4 + 0x14);

    }

    else {

      iVar5 = *(int *)(iVar5 + 0x14);

    }

    if (iVar5 == 0) {

      local_1c[0] = 0;

    }

    else {

      local_1c[0] = *(int *)(iVar5 + 8);

    }

    if (local_1c[0] == 0) break;

    iVar4 = FUN_00418700(local_14,piVar2[1],local_1c);

    FUN_00404840(1);

    piVar2[1] = iVar4;

    **(int **)(iVar4 + 4) = iVar4;

    piVar2 = local_14;

  }

  piVar3 = (int *)FUN_0053fff0();

  *(uint8_t *)(*piVar3 + 0x1d) = 0;

  piVar3 = (int *)*piVar2;

  if (piVar3 != piVar2) {

    do {

      puVar1 = (uint *)piVar3[2];

      if ((puVar1[0x4a] == param_2) &&

         ((((param_3 == 0xffffffff || (puVar1[0x4b] == param_3)) &&

           (iVar4 = *(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac + (int)param_1

                                     ) + 0x3c),

           (ushort)puVar1[0x24] == (ushort)*(byte *)(iVar4 + 0x532))) &&

          ((*(ushort *)((int)puVar1 + 0x92) == 0xffff ||

           (*(ushort *)((int)puVar1 + 0x92) == (ushort)*(byte *)(iVar4 + 0x531))))))) {

        uMissionID = *puVar1;

        for (iVar4 = *(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 0x538) + 0x10) +

                                      (*(uint *)(*(int *)((int)param_1 + 0x538) + 8) & uMissionID) *

                                      4) + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {

          if (uMissionID == *(uint *)(iVar4 + 0x10)) {

            if ((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) goto LAB_005368f4;

            break;

          }

        }

        CVOGCharacter_CheckMissionPrerequisites(param_1,uMissionID,'\x01','\x01');

      }

LAB_005368f4:

      piVar3 = (int *)*piVar3;

    } while (piVar3 != local_14);

  }

  FUN_00403430();

  ExceptionList = pvStack_c;

  return 1;

}
