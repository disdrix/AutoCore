// =============================================================================
// Named_CalleeOf_Client_NpcDialog_PrepareResponseOpcode_008ab9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ab9b0
// Callee of Client_NpcDialog_PrepareResponseOpcode
// Address:   0x008ab9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_NpcDialog_PrepareResponseOpcode: UI/dialog helper. Evidence string: "(Rewards Already Received)". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "(Rewards Already Received)"
//   - "Medal"
//   - "Unlocks"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×15, return×3, for×1.
//  - Notable callees: FUN_007a6de0×8, sprintf×6, Mission_ComputeObjectiveCredits×2, CNDHash_LookupByKey, FUN_00403450, FUN_0051a0e0, FUN_0052b040, FUN_007a69d0.
//  - Strings: "(Rewards Already Received)"; "%d %s"; "Medal"; "%s %s".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_NpcDialog_PrepareResponseOpcode
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

bool __thiscall Named_CalleeOf_Client_NpcDialog_PrepareResponseOpcode_008ab9b0(int *param_1,uint *param_2)



{

  void *pObjective;

  uint uVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  bool bVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char local_3a0 [2];

  uint32_t /* width from decompiler */ local_39e [64];

  uint8_t *puStack_29c;

  uint8_t auStack_298 [128];

  int aiStack_218 [10];

  uint8_t auStack_1ee [470];

  void *pvStack_18;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b2aaf;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  FUN_007a69d0();

  pObjective = *(void **)((param_2[0x4f] - 4) + (uint)(byte)param_2[0x4c] * 4);

  local_3a0[0] = '\0';

  local_3a0[1] = '\0';

  puVar7 = local_39e;

  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  *(uint16_t *)puVar7 = 0;

  if (pObjective != (void *)0x0) {

    if (((((short)param_2[0x2b] != -1) && (DAT_00d1b6d8 != 0)) &&

        (*(void **)(DAT_00d1b6d8 + 0x538) != (void *)0x0)) &&

       (pvVar2 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x538),*param_2),

       pvVar2 != (void *)0x0)) {

      uVar3 = FUN_007a6de0("(Rewards Already Received)",0xffffffff);

      sprintf(local_3a0,"%s",uVar3);

      (**(code **)(*param_1 + 0x250))(local_3a0);

      ExceptionList = pvStack_18;

      return true;

    }

    iVar5 = *(int *)((int)pObjective + 0x130);

    bVar6 = 0 < iVar5;

    if (bVar6) {

      uVar3 = FUN_007a6de0(&DAT_00a4abd4,0xffffffff);

      sprintf(local_3a0,"%d %s",iVar5,uVar3);

      (**(code **)(*param_1 + 0x250))(local_3a0);

    }

    if (0 < *(int *)((int)pObjective + 0x134)) {

      if (bVar6) {

        (**(code **)(*param_1 + 0x250))(&DAT_00a34230);

      }

      uVar3 = *(uint32_t /* width from decompiler */ *)((int)pObjective + 0x134);

      uVar4 = FUN_007a6de0(&DAT_00a4abd0,0xffffffff);

      sprintf(local_3a0,"%d %s",uVar3,uVar4);

      (**(code **)(*param_1 + 0x250))(local_3a0);

      bVar6 = true;

    }

    iVar5 = Mission_ComputeObjectiveCredits(pObjective);

    if (0 < iVar5) {

      if (bVar6 != false) {

        (**(code **)(*param_1 + 0x250))(&DAT_00a34230);

      }

      iVar5 = Mission_ComputeObjectiveCredits(pObjective);

      FUN_00977a30(DAT_00d1ad30,iVar5,iVar5 >> 0x1f);

      bVar6 = true;

    }

    if ((param_2[0x40] != 0xffffffff) && (iVar5 = FUN_0051a0e0(param_2[0x40]), iVar5 != 0)) {

      if (bVar6 != false) {

        (**(code **)(*param_1 + 0x250))(&DAT_00a34230);

      }

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar5 + 4);

      uVar4 = FUN_007a6de0("Medal",0xffffffff);

      uVar3 = FUN_007a6de0(uVar3,0xffffffff);

      sprintf(local_3a0,"%s %s",uVar3,uVar4);

      (**(code **)(*param_1 + 0x250))(local_3a0);

      bVar6 = true;

    }

    if (param_2[0x43] != 0xffffffff) {

      aiStack_218[0] = -1;

      FUN_0052b040(param_2[0x43],aiStack_218);

      if (aiStack_218[0] != -1) {

        if (bVar6 != false) {

          (**(code **)(*param_1 + 0x250))(&DAT_00a34230);

        }

        puStack_29c = auStack_298;

        uVar3 = (*(code *)PTR_FUN_00af8c9c)();

        FUN_00403450(auStack_1ee,uVar3);

        uStack_c = 0;

        uVar3 = FUN_007a6de0(puStack_29c,0xffffffff);

        uVar4 = FUN_007a6de0("Unlocks",0xffffffff);

        sprintf(local_3a0,"%s %s",uVar4,uVar3);

        uStack_c = 0xffffffff;

        if (puStack_29c != auStack_298) {

          free(puStack_29c);

        }

        (**(code **)(*param_1 + 0x250))(local_3a0);

        bVar6 = true;

      }

    }

    if (0 < (int)param_2[0x45]) {

      if (bVar6 != false) {

        (**(code **)(*param_1 + 0x250))(&DAT_00a34230);

      }

      uVar1 = param_2[0x45];

      uVar3 = FUN_007a6de0(&DAT_00a4abbc,0xffffffff);

      sprintf(local_3a0,"%d %s",uVar1,uVar3);

      (**(code **)(*param_1 + 0x250))(local_3a0);

      bVar6 = true;

    }

    ExceptionList = local_14;

    return bVar6;

  }

  ExceptionList = local_14;

  return false;

}
