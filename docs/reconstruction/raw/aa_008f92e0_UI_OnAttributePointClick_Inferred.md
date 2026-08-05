# Raw capture: UI_OnAttributePointClick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f92e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008f92e0` |
| **Canonical name** | `UI_OnAttributePointClick_Inferred` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall UI_OnAttributePointClick_Inferred(int *param_1,int param_2,undefined4 param_3)

{
  RE_VehicleCombatPoolFields *pVehicle;
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (DAT_00d1b6d8 == (int *)0x0) {
    return 0;
  }
  switch(param_3) {
  case 40000:
    if (param_2 == 8) {
      FUN_007fca10();
      return 1;
    }
    break;
  case 0x9c41:
    if (param_2 == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) {
        return 1;
      }
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) {
LAB_008f9342:
        FUN_007fdfb0(&DAT_00d1a840,"You cannot apply attribute points while in an arena!",0xffffffff
                     ,1,0);
        return 1;
      }
      iVar2 = FUN_0040de30();
      FUN_004c2ef0(iVar2 + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      Client_RefreshMissionDialogChrome();
      (**(code **)(*param_1 + 0x448))();
      (**(code **)(*param_1 + 0x34c))();
      cVar1 = FUN_00807440();
      if (cVar1 == '\0') {
        return 1;
      }
      uStack_4 = 1;
LAB_008f9649:
      uStack_8 = 0x205a;
      Client_SendSectorPacket(&DAT_00d1a840,8,&uStack_8);
      return 1;
    }
    break;
  case 0x9c42:
    if (param_2 == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) {
        return 1;
      }
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) goto LAB_008f9342;
      iVar2 = FUN_0040de10();
      FUN_004c2ee0(iVar2 + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      if ((void *)DAT_00d1b6d8[0x94] != (void *)0x0) {
        Vehicle_RecalcCombatPools((void *)DAT_00d1b6d8[0x94]);
      }
      if (DAT_00d1b6d8[0x94] != 0) {
        pVehicle = (RE_VehicleCombatPoolFields *)DAT_00d1b6d8[0x94];
        iVar2 = Vehicle_CalcHeatMaximum(pVehicle);
        pVehicle->nMaxHeat = iVar2;
      }
      Client_RefreshMissionDialogChrome();
      (**(code **)(*param_1 + 0x448))();
      (**(code **)(*param_1 + 0x34c))();
      if ((DAT_00d1b8b8 != (int *)0x0) &&
         (cVar1 = (**(code **)(*DAT_00d1b8b8 + 0x3d8))(), cVar1 != '\0')) {
        FUN_008801b0(DAT_00d1b8b8);
      }
      cVar1 = FUN_00807440();
      if (cVar1 == '\0') {
        return 1;
      }
      uStack_4 = 0x10000;
      goto LAB_008f9649;
    }
    break;
  case 0x9c43:
    if (param_2 == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) {
        return 1;
      }
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) goto LAB_008f9342;
      iVar2 = FUN_0040ddf0();
      FUN_004c2f00(iVar2 + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      (**(code **)(*DAT_00d1b6d8 + 0x5c))();
      Client_RefreshMissionDialogChrome();
      (**(code **)(*param_1 + 0x448))();
      (**(code **)(*param_1 + 0x34c))();
      if ((DAT_00d1b8b8 != (int *)0x0) &&
         (cVar1 = (**(code **)(*DAT_00d1b8b8 + 0x3d8))(), cVar1 != '\0')) {
        FUN_008801b0(DAT_00d1b8b8);
      }
      cVar1 = FUN_00807440();
      if (cVar1 == '\0') {
        return 1;
      }
      uStack_4 = 0x100;
      goto LAB_008f9649;
    }
    break;
  case 0x9c44:
    if (param_2 == 8) {
      if (*(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1) {
        return 1;
      }
      if ((DAT_00d1b644 != 0) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) {
        FUN_007fdfb0(&DAT_00d1a840,"You cannot apply attribute points while in an arena!",0xffffffff
                     ,1,0);
        return 1;
      }
      iVar2 = FUN_0040ddd0();
      FUN_004c2f10(iVar2 + 1);
      CVOGCharacter_AddSkillPoints(*(short *)((int)DAT_00d1b6d8 + 0x6ce) + -1);
      Client_RefreshMissionDialogChrome();
      (**(code **)(*param_1 + 0x448))();
      (**(code **)(*param_1 + 0x34c))();
      cVar1 = FUN_00807440();
      if (cVar1 == '\0') {
        return 1;
      }
      uStack_4 = 0x1000000;
      goto LAB_008f9649;
    }
  }
  switch(param_2) {
  case 7:
  case 8:
  case 0xd:
  case 0xe:
    return 1;
  default:
    uVar3 = FUN_0087b500(param_2,param_3);
    return uVar3;
  }
}
```

---

## Version note — 2026-07-29 dual A/B (do not alter body above)

| Field | Value |
|---|---|
| **Tool** | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` entry/epilogue |
| **Integrity** | Live decompile **≡** authoritative raw body above |
| **Body range** | `0x008f92e0`–`0x008f96bc` |
| **DATA xref** | `0x00a35a2c` → `0x008f92e0` (handler table) |
| **Dual** | `reviews/A_aa_008f92e0_UI_OnAttributePointClick_Inferred.md`, `reviews/B_aa_008f92e0_UI_OnAttributePointClick_Inferred.md` |

Sealed additions (documented in dual/annotated/clean, not rewritten into the 2026-07-23 pseudocode block):

- `ret 8` thiscall; switch base `controlId - 0x9C40`
- Stat map: `0x9C41→+0x13E/flag1`, `0x9C42→+0x13C/flag0x10000`, `0x9C43→+0x140/flag0x100`, `0x9C44→+0x142/flag0x1000000`
- Get soft-cap 200; pool spend `+0x6CE` via `CVOGCharacter_AddSkillPoints` assign
- Packet opcode `0x205A`, size 8
