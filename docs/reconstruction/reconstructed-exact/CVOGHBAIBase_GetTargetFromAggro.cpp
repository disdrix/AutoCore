// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×18, goto×6, return×5, while×3, do×1.
//  - Notable callees: FUN_004cb270×3, FUN_0051c7c0×2, CONCAT31, CVOGHBAIBase_GetTargetFromAggro, CVOGReaction_ResolveObjectTarget, FUN_004c9380, FUN_005134e0, FUN_0051cb40.
//  - Strings: "CVOGHBAIBase::GetTargetFromAggro".
//  - Return sites: 5.

// =============================================================================
// CVOGHBAIBase_GetTargetFromAggro
// -----------------------------------------------------------------------------
// Purpose:  Pick an in-range target from the owner's aggro / hate list rather than a
//           fresh spatial scan. Builds temp list, resolves entries, faction-
//           filters, range-checks vs attack radius, returns first valid.
//
// Address:  0x00638ec0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00638ec0
// System:   npc-ai / HBAI
//
// Convention: __fastcall this.
// Control flow:
//   1) Owner via this+0x18; validate vtbl+0x214
//   2) New list FUN_0058d9c0; load entities FUN_004c9380
//   3) Attack radius owner profile +0x4c8
//   4) Per entry: CVOGReaction_ResolveObjectTarget; faction vtbl+0x1dc/+0x1d8;
//      skip vehicle-flag +0x250; hostile FUN_005134e0; pos vtbl+0x1c8/+0x1a0
//   5) In range -> keep; else remove FUN_0051cb40
// Complements FindTargetToAttack (aggro path vs world scan).
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

/* Get the current target from the aggro list.
   
   Algorithm:
   1. Get owner via this+0x18, validate via vtable +0x214
   2. Create new list via FUN_0058d9c0, initialize circular linked list
   3. Load entities via FUN_004c9380
   4. Get attack radius from owner+0xac at +0x4c8
   5. Iterate list entries:
      - Resolve target via CVOGReaction_ResolveObjectTarget
      - If unresolved, walk linked list to find valid entry (check +0x29 flag)
      - Check if entity vtable +0x1dc returns 0 (faction check)
      - If faction matches or vtable +0x1d8 returns vehicle reference:
        - Skip if vehicle flag +0x250 is set
      - Check if hostile via FUN_005134e0
      - Get position via vtable +0x1c8 and +0x1a0
      - Check if within attack radius
      - If in range: add to result list, return target
      - Otherwise: remove from list via FUN_0051cb40
   6. Clean up list and return */
uint32_t /* width from decompiler */ __fastcall CVOGHBAIBase_GetTargetFromAggro(int this)
{
  float fVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  int *piVar7;
  int *piStack_54;
  uint8_t auStack_40 [4];
  uint8_t auStack_3c [4];
  int *piStack_38;
  uint32_t /* width from decompiler */ uStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  void *pvStack_1c;
  uint8_t *puStack_18;
  uint local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a8e54;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_0076cf00("CVOGHBAIBase::GetTargetFromAggro");
  local_14 = 0;
  iVar4 = (**(code **)(**(int **)(this + 0x18) + 0x214))();
  if (iVar4 == 0) {
    local_14 = 0xffffffff;
    FUN_0076cef0();
    ExceptionList = pvStack_1c;
    return 0;
  }
  piStack_38 = (int *)FUN_0058d9c0();
  *(uint8_t *)((int)piStack_38 + 0x29) = 1;
  piStack_38[1] = (int)piStack_38;
  *piStack_38 = (int)piStack_38;
  piStack_38[2] = (int)piStack_38;
  uStack_34 = 0;
  local_14 = CONCAT31(local_14._1_3_,1);
  FUN_004c9380(auStack_3c);
  piVar7 = (int *)*piStack_38;
  fVar1 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c) +
                    0x4c8);
  piStack_54 = piVar7;
  if (piVar7 != piStack_38) {
    do {
      piVar5 = (int *)CVOGReaction_ResolveObjectTarget((char)piVar7[8],piVar7[6],piVar7[7]);
      if (piVar5 == (int *)0x0) {
        if (*(char *)((int)piVar7 + 0x29) == '\0') {
          piVar5 = (int *)piVar7[2];
          if (*(char *)((int)piVar5 + 0x29) == '\0') {
            cVar3 = *(char *)(*piVar5 + 0x29);
            piVar7 = piVar5;
            piVar5 = (int *)*piVar5;
            while (piStack_54 = piVar7, cVar3 == '\0') {
              cVar3 = *(char *)(*piVar5 + 0x29);
              piVar7 = piVar5;
              piVar5 = (int *)*piVar5;
            }
          }
          else {
            cVar3 = *(char *)(piVar7[1] + 0x29);
            piVar2 = (int *)piVar7[1];
            piVar5 = piVar7;
            while ((piVar7 = piVar2, piStack_54 = piVar7, cVar3 == '\0' &&
                   (piVar5 == (int *)piVar7[2]))) {
              cVar3 = *(char *)(piVar7[1] + 0x29);
              piVar2 = (int *)piVar7[1];
              piVar5 = piVar7;
            }
          }
        }
        goto LAB_00639153;
      }
      iVar4 = (**(code **)(*piVar5 + 0x1dc))();
      if (iVar4 == 0) {
LAB_0063903c:
        if (piVar5 == (int *)0x0) goto LAB_00639137;
        iVar4 = (**(code **)(*piVar5 + 0x1d8))();
        if (iVar4 != 0) {
          iVar4 = (**(code **)(*piVar5 + 0x1d8))();
          iVar4 = *(int *)(iVar4 + 0x250);
          if (iVar4 == 0) goto LAB_00639137;
          piVar5 = (int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);
        }
        if (piVar5 == (int *)0x0) goto LAB_00639137;
        cVar3 = FUN_005134e0();
        if (cVar3 == '\0') {
          iVar4 = (**(code **)(*piVar5 + 0x1c8))();
          if (iVar4 == 0) goto LAB_00639137;
          pfVar6 = (float *)(**(code **)(*piVar5 + 0x1a0))();
          fStack_30 = *pfVar6;
          fStack_2c = pfVar6[1];
          fStack_28 = pfVar6[2];
          pfVar6 = (float *)(**(code **)(**(int **)(this + 0x18) + 0x1a0))();
          if ((fStack_28 - pfVar6[2]) * (fStack_28 - pfVar6[2]) +
              (fStack_2c - pfVar6[1]) * (fStack_2c - pfVar6[1]) +
              (fStack_30 - *pfVar6) * (fStack_30 - *pfVar6) < fVar1 * fVar1) {
            (**(code **)(*piVar5 + 0x1c8))();
            local_14 = local_14 & 0xffffff00;
            FUN_0051c7c0(auStack_40,*piStack_38,piStack_38);
                    /* WARNING: Subroutine does not return */
            operator_delete(piStack_38);
          }
          FUN_004cb270();
          piVar7 = piStack_54;
        }
        else {
          FUN_004cb270();
          piVar7 = piStack_54;
        }
      }
      else {
        iVar4 = (**(code **)(*piVar5 + 0x1dc))();
        iVar4 = *(int *)(iVar4 + 0x250);
        if (iVar4 != 0) {
          piVar5 = (int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);
          goto LAB_0063903c;
        }
LAB_00639137:
        FUN_004cb270();
        FUN_0051cb40(auStack_40,piVar7);
        piVar7 = piStack_54;
      }
LAB_00639153:
    } while (piVar7 != piStack_38);
  }
  local_14 = local_14 & 0xffffff00;
  FUN_0051c7c0(auStack_40,*piStack_38,piStack_38);
                    /* WARNING: Subroutine does not return */
  operator_delete(piStack_38);
}
