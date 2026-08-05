// =============================================================================
// Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_008532d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008532d0
// Callee of Mission_Client_BuildMissionDetailPanel
// Address:   0x008532d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Client_BuildMissionDetailPanel: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~187 non-empty decompiler lines.
//  - Control keywords: if×14, do×1, while×1, return×1.
//  - Notable callees: FUN_00853210×11, FUN_008532d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Client_BuildMissionDetailPanel
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

void Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_008532d0(uint8_t *param_1)



{

  int *piVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  uint8_t *unaff_EBX;

  int unaff_EDI;

  uint8_t *puVar7;

  uint8_t *puVar8;

  uint8_t *puStack_b0;

  uint8_t *local_ac;

  int iStack_a8;

  uint8_t auStack_a4 [4];

  uint32_t /* width from decompiler */ local_a0;

  float fStack_9c;

  float fStack_98;

  uint8_t *puStack_94;

  uint8_t *puStack_90;

  uint8_t auStack_8c [8];

  int iStack_84;

  uint8_t *puStack_80;

  uint8_t *puStack_7c;

  uint8_t auStack_6c [12];

  uint8_t auStack_60 [8];

  uint8_t auStack_58 [12];

  uint8_t auStack_4c [4];

  uint8_t auStack_48 [20];

  uint8_t auStack_34 [16];

  uint8_t auStack_24 [4];

  uint8_t auStack_20 [4];

  uint8_t auStack_1c [24];

  

  *(uint8_t **)(unaff_EDI + 0x4fc) = param_1;

  local_ac = (uint8_t *)0x0;

  if (*(int **)(unaff_EDI + 0x504) != (int *)0x0) {

    piVar3 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x504) + 0x120))(&local_a0,1,0);

    unaff_EBX = (uint8_t *)*piVar3;

    puStack_b0 = param_1;

    (**(code **)(**(int **)(unaff_EDI + 0x504) + 0x110))(&stack0xffffff4c);

    FUN_00853210();

    iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x504) + 0x140))(&puStack_b0,1);

    local_ac = *(uint8_t **)(iVar4 + 4);

  }

  if (*(int **)(unaff_EDI + 0x500) != (int *)0x0) {

    iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x500) + 0x124))(&local_a0);

    piVar3 = *(int **)(unaff_EDI + 0x504);

    iVar4 = (int)((float)DAT_00d1e81c * *(float *)(iVar4 + 4) * DAT_00aaa678);

    if (piVar3 != (int *)0x0) {

      iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x500) + 0x140))(auStack_a4,1);

      iVar5 = (**(code **)(*piVar3 + 0x140))(auStack_8c,1);

      iVar4 = (*(int *)(iVar5 + 4) - *(int *)(iVar4 + 4)) / 2;

    }

    (**(code **)(**(int **)(unaff_EDI + 0x500) + 0x120))(auStack_a4,1,0);

    unaff_EBX = param_1 + iVar4;

    (**(code **)(**(int **)(unaff_EDI + 0x500) + 0x110))(&stack0xffffff48);

    FUN_00853210();

    iVar5 = (**(code **)(**(int **)(unaff_EDI + 0x500) + 0x140))(&stack0xffffff4c,1);

    if ((int)local_ac < *(int *)(iVar5 + 4) + iVar4) {

      iVar5 = (**(code **)(**(int **)(unaff_EDI + 0x500) + 0x140))(&local_a0,1);

      local_ac = (uint8_t *)(*(int *)(iVar5 + 4) + iVar4);

    }

  }

  param_1 = param_1 + (int)local_ac;

  if (*(int **)(unaff_EDI + 0x510) != (int *)0x0) {

    local_ac = param_1;

    piVar3 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x510) + 0x120))(&local_a0,1,0);

    unaff_EBX = (uint8_t *)*piVar3;

    puStack_b0 = param_1;

    (**(code **)(**(int **)(unaff_EDI + 0x510) + 0x110))(&stack0xffffff4c);

    FUN_00853210();

    iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x510) + 0x140))(&puStack_b0,1);

    param_1 = param_1 + *(int *)(iVar4 + 4);

  }

  local_ac = param_1;

  if (*(int **)(unaff_EDI + 0x508) != (int *)0x0) {

    piVar3 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x508) + 0x120))(&local_a0,1,0);

    unaff_EBX = (uint8_t *)*piVar3;

    puStack_b0 = param_1;

    (**(code **)(**(int **)(unaff_EDI + 0x508) + 0x110))(&stack0xffffff4c);

    FUN_00853210();

    iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x508) + 0x140))(&puStack_b0,1);

    local_ac = param_1 + *(int *)(iVar4 + 4);

  }

  puVar8 = local_ac;

  if (*(int **)(unaff_EDI + 0x50c) != (int *)0x0) {

    piVar3 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x50c) + 0x120))(&local_a0,1,0);

    unaff_EBX = (uint8_t *)*piVar3;

    puStack_b0 = puVar8;

    (**(code **)(**(int **)(unaff_EDI + 0x50c) + 0x110))(&stack0xffffff4c);

    FUN_00853210();

    iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x50c) + 0x140))(&puStack_b0,1);

    local_ac = puVar8 + *(int *)(iVar4 + 4);

  }

  puVar8 = local_ac;

  if (*(int **)(unaff_EDI + 0x514) != (int *)0x0) {

    piVar3 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x514) + 0x120))(&local_a0,1,0);

    unaff_EBX = (uint8_t *)*piVar3;

    puStack_b0 = puVar8;

    (**(code **)(**(int **)(unaff_EDI + 0x514) + 0x110))(&stack0xffffff4c);

    FUN_00853210();

    iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x514) + 0x140))(&puStack_b0,1);

    local_ac = puVar8 + *(int *)(iVar4 + 4);

  }

  puVar8 = local_ac;

  if (*(int **)(unaff_EDI + 0x518) != (int *)0x0) {

    piVar3 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x518) + 0x120))(&local_a0,1,0);

    unaff_EBX = (uint8_t *)*piVar3;

    puStack_b0 = puVar8;

    (**(code **)(**(int **)(unaff_EDI + 0x518) + 0x110))(&stack0xffffff4c);

    FUN_00853210();

    iVar4 = (**(code **)(**(int **)(unaff_EDI + 0x518) + 0x140))(&puStack_b0,1);

    local_ac = puVar8 + *(int *)(iVar4 + 4);

  }

  puStack_90 = (uint8_t *)0x0;

  piVar3 = (int *)(unaff_EDI + 0x53c);

  puStack_94 = local_ac;

  do {

    fStack_98 = (float)((int)puStack_90 / *(int *)(unaff_EDI + 0x568));

    iVar4 = (int)puStack_90 - (int)fStack_98 * *(int *)(unaff_EDI + 0x568);

    if ((piVar3[-8] != 0) && (cVar2 = (**(code **)(*(int *)piVar3[-8] + 0xd0))(), cVar2 != '\0')) {

      puVar8 = auStack_58;

      iVar5 = (**(code **)(*(int *)piVar3[-8] + 0x124))(puVar8);

      puVar7 = auStack_6c;

      puStack_90 = (uint8_t *)

                   ((float)DAT_00d1e81c *

                    ((float)(*(int *)(unaff_EDI + 0x564) * (int)fStack_9c) + *(float *)(iVar5 + 4))

                   * DAT_00aaa678);

      pfVar6 = (float *)(**(code **)(*(int *)piVar3[-8] + 0x124))();

      puStack_7c = unaff_EBX + (int)(float)puStack_94;

      puStack_80 = (uint8_t *)

                   (int)((float)DAT_00d1e818 *

                         ((float)(*(int *)(unaff_EDI + 0x560) * iVar4) + *pfVar6) * DAT_00aaa67c);

      (**(code **)(*(int *)piVar3[-8] + 0x110))(&puStack_80);

      if (piVar3[-4] != 0) {

        iVar5 = (**(code **)(*(int *)piVar3[-4] + 0x124))(auStack_24);

        fStack_98 = (float)DAT_00d1e81c *

                    ((float)(*(int *)(unaff_EDI + 0x564) * iStack_a8) + *(float *)(iVar5 + 4)) *

                    DAT_00aaa678;

        pfVar6 = (float *)(**(code **)(*(int *)piVar3[-4] + 0x124))(auStack_58);

        puStack_80 = puVar7 + (int)fStack_9c;

        iStack_84 = (int)((float)DAT_00d1e818 *

                          ((float)(*(int *)(unaff_EDI + 0x560) * iVar4) + *pfVar6) * DAT_00aaa67c);

        (**(code **)(*(int *)piVar3[-4] + 0x110))(&iStack_84);

      }

      if (*piVar3 != 0) {

        iVar5 = (**(code **)(*(int *)*piVar3 + 0x124))(auStack_34);

        puStack_94 = (uint8_t *)

                     ((float)DAT_00d1e81c *

                      ((float)(*(int *)(unaff_EDI + 0x564) * iStack_a8) + *(float *)(iVar5 + 4)) *

                     DAT_00aaa678);

        pfVar6 = (float *)(**(code **)(*(int *)*piVar3 + 0x124))(auStack_48);

        puStack_90 = puVar7 + (int)fStack_98;

        puStack_94 = (uint8_t *)

                     (int)((float)DAT_00d1e818 *

                           ((float)(*(int *)(unaff_EDI + 0x560) * iVar4) + *pfVar6) * DAT_00aaa67c);

        (**(code **)(*(int *)*piVar3 + 0x110))(&puStack_94);

      }

      if (piVar3[4] != 0) {

        (**(code **)(*(int *)piVar3[4] + 0x124))(auStack_6c);

        pfVar6 = (float *)(**(code **)(*(int *)piVar3[4] + 0x124))(auStack_60);

        puStack_b0 = puVar7 + (int)(float)puVar8;

        unaff_EBX = (uint8_t *)

                    (int)((float)DAT_00d1e818 *

                          ((float)(*(int *)(unaff_EDI + 0x560) * iVar4) + *pfVar6) * DAT_00aaa67c);

        (**(code **)(*(int *)piVar3[4] + 0x110))(&stack0xffffff4c);

      }

      FUN_00853210();

      FUN_00853210();

      FUN_00853210();

      FUN_00853210();

      piVar1 = (int *)piVar3[-8];

      puStack_b0 = (uint8_t *)(**(code **)(*piVar1 + 0x120))(auStack_4c,1,0);

      iVar4 = (**(code **)(*piVar1 + 0x140))(auStack_48,1);

      if ((int)puStack_94 < *(int *)((int)fStack_98 + 4) + *(int *)(iVar4 + 4)) {

        piVar1 = (int *)piVar3[-8];

        local_a0 = (**(code **)(*piVar1 + 0x120))(auStack_20,1,0);

        iVar4 = (**(code **)(*piVar1 + 0x140))(auStack_1c,1);

        puStack_94 = (uint8_t *)(*(int *)(puStack_94 + 4) + *(int *)(iVar4 + 4));

      }

    }

    puStack_90 = puStack_90 + 1;

    piVar3 = piVar3 + 1;

  } while ((int)puStack_90 < 4);

  return;

}
