// =============================================================================
// Client_ClearObjectReferences
// -----------------------------------------------------------------------------
// Stable ID: aa_00944d50
// Address:   0x00944d50  (autoassault.exe, image base 0x400000)
// Body:      0x00944d50 – 0x00945367
// System:    client / object lifecycle / UI unbind
// Prior:     FUN_00944d50
// Dual A/B:  2026-07-29 W17-H
// Tools:     decompile_function + read_memory (no disassemble_bytes)
// Exactness: Behavior-preserving stage order from decompiler. Not modernization.
// Bit-for-bit / runtime: DEFERRED / OPEN
// =============================================================================
//
// PURPOSE
//   Fan-out cleanup of client/UI references to a departing object. Clears sticky
//   pointers, COID tree entries, select chrome, inventory/mission bindings,
//   selection targets, and ends with FUN_00996ff0(COID).
//
//   Distinct from VOGClient_CompletelyDestroyObject (0x009440e0). Callers today:
//   ClientSpecialEvent_Respawn_dtor (ship), FUN_009791c0, FUN_009788b0.
//
// ABI (sealed)
//   void __thiscall Client_ClearObjectReferences(Client* this, Object* obj);
//   ECX=this, stack obj*, RET 4.
// =============================================================================

// Forward decls (named where sealed; else FUN_*)
void FUN_00405920(void *cb, void *arg);
void FUN_00402ae0(void *outIt);
void FUN_00402850(void *tree, void *it, int node);
void FUN_0093e120(int arg);
void FUN_00837d50(void);                 // UiSelectWidget_ApplySelectChrome
void FUN_007fca10(void);
void FUN_008719d0(void);
void FUN_008bf020(void);
char FUN_00571b60(void *item);           // InventoryGrid_ContainsItem
char FUN_004f70f0(int coidLo, int coidHi); // Vehicle_HasEquippedTFID
void FUN_00571b80(void *item, void *a, int b);
void Client_RefreshOpenMissionUiWindows(void *client);
void FUN_0085fd20(void);                 // Client_UI_InventorySheet_RemoveByItem
char FUN_00574a90(void *arg);
void FUN_007fdab0(void *obj);
void FUN_008027e0(void *obj);
void FUN_0044f5a0(void *scratch);
void Object_SetSelectedTarget(void *self, void *target, void *unused);
void FUN_007fe140(void *globalList);
void FUN_0083dae0(void);
void FUN_007fbbb0(void);
void FUN_00996ff0(int coidLo, int coidHi);

extern int *DAT_00d1d8dc;
extern char DAT_00d1d8f4;
extern char DAT_00d1d8f5;
extern int DAT_00d1a840;
extern void LAB_0092d8e0;

void __thiscall Client_ClearObjectReferences(int client, int *obj)
{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int treeNode;
  undefined4 uVar8;
  void *pNewTarget;

  // --- 1. Null guard ---
  if (obj == (int *)0x0) {
    return;
  }

  // --- 2. Sticky client slot +0x3bf8 ---
  if (*(int **)(client + 0x3bf8) == obj) {
    *(undefined4 *)(client + 0x3bf8) = 0;
  }

  // --- 3. Optional related-object notify via FUN_00405920 ---
  if (*(int *)(*(int *)(*(int *)(client + 0xe04) + 0xe5fc) + 0xc) != 0) {
    FUN_00405920(&LAB_0092d8e0, obj);
    iVar2 = (**(code **)(*obj + 0x1d4))();          // parent/vehicle-ish
    if ((iVar2 == 0) ||
        (iVar2 = (**(code **)(*obj + 0x1d4))(),
         *(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xb0 + iVar2) == 0)) {
      iVar2 = (**(code **)(*obj + 0x1d8))();        // cargo/container-ish
      if ((iVar2 == 0) ||
          (iVar2 = (**(code **)(*obj + 0x1d8))(), *(int *)(iVar2 + 0x250) == 0))
        goto LAB_after_related;
      iVar2 = (**(code **)(*obj + 0x1d8))();
      uVar5 = *(undefined4 *)(iVar2 + 0x250);
    }
    else {
      iVar2 = (**(code **)(*obj + 0x1d4))();
      uVar5 = *(undefined4 *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xb0 + iVar2);
    }
    FUN_00405920(&LAB_0092d8e0, uVar5);
  }

LAB_after_related:
  // --- 4. COID tree erase at client+0xd24 / +0xd28 ---
  pNewTarget = (void *)0x0;
  iVar2 = (**(code **)(*obj + 0x210))();
  if ((iVar2 != 0) &&
      (FUN_00402ae0(&treeNode), treeNode != *(int *)(client + 0xd28))) {
    do {
      (**(code **)(**(int **)(treeNode + 0x20) + 8))();
      if (*(int **)(treeNode + 0x20) != (int *)0x0) {
        (**(code **)(**(int **)(treeNode + 0x20) + 4))(1);
      }
      FUN_00402850((void *)(client + 0xd24), &treeNode, treeNode);
      // re-lower-bound by COID obj[0x58]/[0x59] on tree at +0xd28
      puVar7 = *(undefined4 **)(client + 0xd28);
      if (*(char *)((int)puVar7[1] + 0x29) == '\0') {
        puVar3 = (undefined4 *)puVar7[1];
        do {
          if ((obj[0x59] < (int)puVar3[5]) ||
              ((obj[0x59] <= (int)puVar3[5] &&
                ((uint)obj[0x58] <= (uint)puVar3[4])))) {
            puVar4 = (undefined4 *)*puVar3;
            puVar7 = puVar3;
          }
          else {
            puVar4 = (undefined4 *)puVar3[2];
          }
          puVar3 = puVar4;
        } while (*(char *)((int)puVar4 + 0x29) == '\0');
      }
      if (puVar7 == *(undefined4 **)(client + 0xd28)) {
        treeNode = *(int *)(client + 0xd28); // end sentinel path (decomp noise)
        break;
      }
      else if ((obj[0x59] < (int)puVar7[5]) ||
               ((obj[0x59] <= (int)puVar7[5] &&
                 ((uint)obj[0x58] < (uint)puVar7[4])))) {
        break;
      }
      // continue with next match node (decomp uses stack iterator)
      treeNode = (int)puVar7; // structural; raw uses unaff iterator reload
    } while (treeNode != *(int *)(client + 0xd28));
  }

  // --- 5. UI host notify vtbl+0x444 ---
  piVar6 = *(int **)(client + 0xf40);
  if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
    (**(code **)(*(int *)*piVar6 + 0x444))(obj);
  }

  // --- 6. Selection + select-chrome slots ---
  if (*(int **)(client + 0x3048) == obj) {
    FUN_0093e120(0);
  }
  if (((*(int *)(client + 0x10a4) != 0) &&
       (iVar2 = *(int *)(*(int *)(client + 0x10a4) + 0x520), iVar2 != 0)) &&
      (*(int **)(iVar2 + 0x518) == obj)) {
    FUN_00837d50();
  }
  if (((*(int *)(client + 0x10b4) != 0) &&
       (iVar2 = *(int *)(*(int *)(client + 0x10b4) + 0x54c), iVar2 != 0)) &&
      (*(int **)(iVar2 + 0x518) == obj)) {
    FUN_00837d50();
  }
  iVar2 = *(int *)(client + 0x1088);
  if ((iVar2 != 0) && (*(int **)(iVar2 + 0x50c) == obj)) {
    *(undefined4 *)(iVar2 + 0x50c) = 0;
  }
  iVar2 = *(int *)(client + 0x1068);
  if ((iVar2 != 0) && (obj == *(int **)(iVar2 + 0x7cc))) {
    FUN_007fca10();
    *(undefined4 *)(iVar2 + 0x7cc) = 0;
  }

  // --- 7. Misc panels ---
  if (*(int *)(client + 0x10cc) != 0) {
    (**(code **)(*obj + 0x1dc))();
    FUN_008719d0();
  }
  if ((*(int **)(client + 0x1098) != (int *)0x0) &&
      (cVar1 = (**(code **)(**(int **)(client + 0x1098) + 0x3d8))(), cVar1 != '\0')) {
    FUN_008bf020();
  }

  // --- 8. Inventory / equip membership → mission UI refresh ---
  if ((((*(int *)(client + 0xe98) == 0) ||
        (*(int *)(*(int *)(client + 0xe98) + 0x250) == 0) ||
        (cVar1 = FUN_00571b60(obj), cVar1 == '\0')) &&
       ((*(int *)(client + 0xe98) == 0 ||
         (cVar1 = FUN_00571b60(obj), cVar1 == '\0')))) {
    if (((*(int *)(client + 0xe98) == 0) ||
         (*(int *)(*(int *)(client + 0xe98) + 0x250) == 0) ||
         (cVar1 = FUN_004f70f0(obj[0x58], obj[0x59]), cVar1 == '\0')))
      goto LAB_after_mission;
  }
  else {
    uVar8 = 1;
    uVar5 = (**(code **)(*obj + 0x25c))(1);
    FUN_00571b80(obj, uVar5, uVar8);
  }
  Client_RefreshOpenMissionUiWindows((void *)client);

LAB_after_mission:
  // --- 9. Inventory sheet windows +0x105c / +0x1060 ---
  if ((((*(int **)(client + 0x105c) != (int *)0x0) &&
        (cVar1 = (**(code **)(**(int **)(client + 0x105c) + 0x3d8))(), cVar1 != '\0')) &&
       (iVar2 = *(int *)(*(int *)(client + 0x105c) + 0x588), iVar2 != 0)) &&
      ((*(int *)(iVar2 + 0x35c) != 0 && (cVar1 = FUN_00571b60(obj), cVar1 != '\0')))) {
    uVar8 = 1;
    uVar5 = (**(code **)(*obj + 0x25c))(1);
    FUN_00571b80(obj, uVar5, uVar8);
    piVar6 = *(int **)(client + 0x105c);
    if ((piVar6 != (int *)0x0) &&
        ((cVar1 = (**(code **)(*piVar6 + 0x3d8))(), cVar1 != '\0' &&
          (piVar6[0x16b] != 0)))) {
      FUN_0085fd20();
    }
  }
  if ((((*(int **)(client + 0x1060) != (int *)0x0) &&
        (cVar1 = (**(code **)(**(int **)(client + 0x1060) + 0x3d8))(), cVar1 != '\0')) &&
       (iVar2 = *(int *)(*(int *)(client + 0x1060) + 0x5a0), iVar2 != 0)) &&
      ((*(int *)(iVar2 + 0x35c) != 0 && (cVar1 = FUN_00571b60(obj), cVar1 != '\0')))) {
    uVar8 = 1;
    uVar5 = (**(code **)(*obj + 0x25c))(1);
    FUN_00571b80(obj, uVar5, uVar8);
    piVar6 = *(int **)(client + 0x1060);
    if ((piVar6 != (int *)0x0) &&
        (cVar1 = (**(code **)(*piVar6 + 0x3d8))(), cVar1 != '\0')) {
      if (piVar6[0x183] != 0) {
        FUN_0085fd20();
      }
      if ((int *)piVar6[0x169] == obj) {
        (**(code **)(*piVar6 + 0x448))();
      }
    }
  }

  // --- 10. Cargo / CBID panel ---
  iVar2 = (**(code **)(*obj + 0x1dc))();
  if (((iVar2 != 0) && (*(int *)(client + 0xe98) != 0)) &&
      (*(int *)(*(int *)(client + 0xe98) + 0xcb0) != 0)) {
    uVar5 = (**(code **)(*obj + 0x1dc))();
    cVar1 = FUN_00574a90(uVar5);
    if ((cVar1 != '\0') && (*(int **)(client + 0x10a0) != (int *)0x0)) {
      (**(code **)(**(int **)(client + 0x10a0) + 0x448))();
      (**(code **)(**(int **)(client + 0x10a0) + 0x34c))();
    }
  }

  // --- 11. Always-run unbind helpers ---
  FUN_007fdab0(obj);
  FUN_008027e0(obj);

  // --- 12. Character class (clonebase+0x38 == 0x0E) ---
  if (*(int *)(obj[0x2a] + 0x38) == 0xe) {
    (**(code **)(*obj + 0x1d4))();
    FUN_0044f5a0(&treeNode);
  }

  // --- 13. Selection list: clear targets pointing at obj ---
  piVar6 = (int *)**(int **)(client + 0xf0c);
  if (piVar6 != *(int **)(client + 0xf0c)) {
    do {
      iVar2 = piVar6[2];
      if ((iVar2 != 0) &&
          (iVar2 = iVar2 + *(int *)(*(int *)(iVar2 + 4) + 4),
           *(int **)(iVar2 + 0xa4) == obj)) {
        Object_SetSelectedTarget((void *)(iVar2 + 4), (void *)0x0, pNewTarget);
      }
      piVar6 = (int *)*piVar6;
    } while (piVar6 != (int *)*(int *)(client + 0xf0c));
  }

  // --- 14. Secondary related clear ---
  iVar2 = (**(code **)(*obj + 0x1d8))();
  if (iVar2 != 0) {
    FUN_0044f5a0(&treeNode);
  }

  // --- 15. Global dialog DAT_00d1d8dc ---
  if ((DAT_00d1d8dc == (int *)0x0) || (obj == (int *)DAT_00d1d8dc[0x146])) {
    DAT_00d1d8f4 = 1;
    DAT_00d1d8f5 = 0;
    if (DAT_00d1d8dc != (int *)0x0) {
      (**(code **)(*DAT_00d1d8dc + 4))(0);
    }
  }

  // --- 16–17. Global list + panel +0x113c ---
  FUN_007fe140(&DAT_00d1a840);
  iVar2 = *(int *)(client + 0x113c);
  if ((iVar2 != 0) && (*(int **)(iVar2 + 0x500) == obj)) {
    *(undefined4 *)(iVar2 + 0x500) = 0;
    *(undefined4 *)(iVar2 + 0x4fc) = 0;
    FUN_0083dae0();
    FUN_007fbbb0();
  }

  // --- 18. Local-player identity panel ---
  piVar6 = *(int **)(client + 0xe98);
  if (piVar6 != (int *)0x0) {
    piVar6 = (int *)(*(int *)(piVar6[1] + 4) + 4 + (int)piVar6);
  }
  if ((obj == piVar6) &&
      (piVar6 = *(int **)(client + 0x30a0), piVar6 != (int *)0x0)) {
    piVar6[0x145] = 0;
    *(undefined1 *)(piVar6 + 0x13f) = 0;
    (**(code **)(*piVar6 + 0x444))();
    (**(code **)(*piVar6 + 0x34c))();
  }

  // --- 19. COID notify tail ---
  FUN_00996ff0(obj[0x58], obj[0x59]);
  return;
}

// Ghidra name alias
void __thiscall FUN_00944d50(int param_1, int *param_2)
{
  Client_ClearObjectReferences(param_1, param_2);
}
