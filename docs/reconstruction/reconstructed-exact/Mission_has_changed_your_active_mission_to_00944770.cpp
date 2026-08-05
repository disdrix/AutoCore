// READABILITY (auto CF):
//  - Body size: ~165 non-empty decompiler lines.
//  - Control keywords: if×16, do×3, while×3, return×2, goto×1.
//  - Notable callees: FUN_0040b020×4, CNDHash_LookupByKey×3, CONCAT31×3, FUN_007a69d0×3, FUN_007a6de0×3, FUN_00402b30×2, FUN_007a4480×2, CONCAT22.
//  - Strings: "Debug KQDI:%x-%I64d-%s"; "Debug DQDI:%x-%I64d-%s"; "has changed your active mission to"; "Your Convoy Leader".
//  - Return sites: 2.

// =============================================================================
// Mission_has_changed_your_active_mission_to_00944770
// -----------------------------------------------------------------------------
// Stable ID: aa_00944770
// Address:   0x00944770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "has changed your active mission to"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Mission_has_changed_your_active_mission_to_00944770(void)



{

  char cVar1;

  int in_EAX;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  void *pvVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ uVar10;

  int local_140 [2];

  int *local_138;

  int *local_130;

  uint local_12c;

  int local_128;

  uint32_t /* width from decompiler */ local_124;

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint local_114;

  int iStack_110;

  uint32_t /* width from decompiler */ local_10c;

  char acStack_100 [256];

  

  piVar2 = (int *)FUN_0040b020();

  if (piVar2 != (int *)0x0) {

    local_114 = local_114 & 0xffff0000;

    do {

      uVar5 = local_114;

      piVar2[0x5f] = piVar2[0x5f] & 0xfffffffe;

      local_128 = piVar2[0x33];

      local_114 = local_114 & 0xffffff00;

      if ((*(int *)(piVar2[0x2a] + 0x38) == 3) && (piVar2[5] != 0)) {

        local_114._1_3_ = SUB43(uVar5,1);

        local_114 = CONCAT31(local_114._1_3_,1);

      }

      local_124 = local_10c;

      local_120 = 0xffffffff;

      local_11c = 0xffffffff;

      local_12c = local_114;

      local_138 = piVar2;

      local_130 = piVar2;

      FUN_00402b30(local_140);

      iVar8 = piVar2[0x58];

      iVar4 = piVar2[0x59];

      uVar3 = (**(code **)(*piVar2 + 0x160))();

      FUN_007a4480(0,"Debug KQDI:%x-%I64d-%s",piVar2,iVar8,iVar4,uVar3);

      piVar2 = (int *)FUN_0040b020();

    } while (piVar2 != (int *)0x0);

  }

  piVar2 = (int *)FUN_0040b020();

  if (piVar2 != (int *)0x0) {

    local_114 = CONCAT22(local_114._2_2_,0x100);

    iStack_110 = 0;

    local_114 = CONCAT31(local_114._1_3_,1);

    do {

      local_124 = local_10c;

      local_120 = 0xffffffff;

      local_12c = local_114;

      local_11c = 0xffffffff;

      local_128 = iStack_110;

      local_138 = piVar2;

      local_130 = piVar2;

      FUN_00402b30(local_140);

      iVar8 = piVar2[0x58];

      iVar4 = piVar2[0x59];

      uVar3 = (**(code **)(*piVar2 + 0x160))();

      FUN_007a4480(0,"Debug DQDI:%x-%I64d-%s",piVar2,iVar8,iVar4,uVar3);

      piVar2 = (int *)FUN_0040b020();

    } while (piVar2 != (int *)0x0);

  }

  local_140[0] = **(int **)(in_EAX + 0xf18);

  if ((int *)local_140[0] != *(int **)(in_EAX + 0xf18)) {

    do {

      piVar2 = *(int **)(local_140[0] + 0x10);

      if (*(char *)(local_140[0] + 0x1c) == '\0') {

        cVar1 = (**(code **)(*piVar2 + 0x198))();

        if (cVar1 == '\0') {

          iVar8 = piVar2[0x33];

          uVar3 = 0xffffffff;

          uVar10 = 0xffffffff;

          uVar7 = 0;

          goto LAB_0094494c;

        }

      }

      else {

        uVar3 = *(uint32_t /* width from decompiler */ *)(local_140[0] + 0x2c);

        uVar10 = *(uint32_t /* width from decompiler */ *)(local_140[0] + 0x28);

        iVar8 = *(int *)(local_140[0] + 0x20);

        uVar7 = CONCAT31((int3)((uint)uVar10 >> 8),*(uint8_t *)(local_140[0] + 0x1d));

LAB_0094494c:

        FUN_009440e0(piVar2,uVar7,iVar8,uVar10,uVar3);

      }

      FUN_00408590();

    } while (local_140[0] != *(int *)(in_EAX + 0xf18));

  }

  pvVar6 = *(void **)(*(int *)(in_EAX + 0xf18) + 4);

  if (*(char *)((int)pvVar6 + 0x31) == '\0') {

    FUN_00406bc0(*(uint32_t /* width from decompiler */ *)((int)pvVar6 + 8));

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar6);

  }

  *(int *)(*(int *)(in_EAX + 0xf18) + 4) = *(int *)(in_EAX + 0xf18);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xf1c) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(in_EAX + 0xf18) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xf18);

  *(int *)(*(int *)(in_EAX + 0xf18) + 8) = *(int *)(in_EAX + 0xf18);

  FUN_0092f3b0();

  iVar8 = *(int *)(in_EAX + 0x4d4);

  if ((iVar8 != -1) && (*(int *)(in_EAX + 0xe98) != 0)) {

    uVar5 = (*(int **)(in_EAX + 0x4d0))[4];

    if (uVar5 == 0) {

      iVar4 = 0;

    }

    else {

      pvVar6 = CNDHash_LookupByKey(*(void **)(*(int *)(**(int **)(in_EAX + 0x4d0) + 0xe98) + 0x548),

                                   uVar5);

      iVar4 = 0;

      if ((pvVar6 != (void *)0x0) && (iVar4 = 0, *(int **)((int)pvVar6 + 0x14c) != (int *)0x0)) {

        iVar4 = **(int **)((int)pvVar6 + 0x14c);

      }

    }

    if (iVar4 != iVar8) {

      FUN_009346e0(in_EAX);

      uVar5 = (*(int **)(in_EAX + 0x4d0))[4];

      if (uVar5 == 0) {

        uVar5 = 0;

      }

      else {

        pvVar6 = CNDHash_LookupByKey(*(void **)(*(int *)(**(int **)(in_EAX + 0x4d0) + 0xe98) + 0x548

                                               ),uVar5);

        uVar5 = 0;

        if ((pvVar6 != (void *)0x0) && (uVar5 = 0, *(uint **)((int)pvVar6 + 0x14c) != (uint *)0x0))

        {

          uVar5 = **(uint **)((int)pvVar6 + 0x14c);

        }

      }

      if ((uVar5 == *(uint *)(in_EAX + 0x4d4)) &&

         (pvVar6 = *(void **)(*(int *)(in_EAX + 0xe98) + 0x540), pvVar6 != (void *)0x0)) {

        pvVar6 = CNDHash_LookupByKey(pvVar6,*(uint *)(in_EAX + 0x4d4));

        if ((pvVar6 != (void *)0x0) &&

           ((*(int **)(in_EAX + 0xf40) != (int *)0x0 && (**(int **)(in_EAX + 0xf40) != 0)))) {

          uVar3 = *(uint32_t /* width from decompiler */ *)((int)pvVar6 + 0x14c);

          uVar10 = 0xffffffff;

          FUN_007a69d0(uVar3,0xffffffff);

          uVar3 = FUN_007a6de0(uVar3,uVar10);

          uVar10 = 0xffffffff;

          pcVar9 = "has changed your active mission to";

          FUN_007a69d0("has changed your active mission to",0xffffffff,uVar3);

          uVar3 = FUN_007a6de0(pcVar9,uVar10);

          uVar10 = 0xffffffff;

          pcVar9 = "Your Convoy Leader";

          FUN_007a69d0("Your Convoy Leader",0xffffffff,uVar3);

          uVar3 = FUN_007a6de0(pcVar9,uVar10);

          sprintf(acStack_100,"%s %s \"%s.\"",uVar3);

          if (DAT_00d1b8dc != 0) {

            FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,acStack_100,0);

          }

        }

      }

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x4d4) = 0xffffffff;

  }

  return;

}
