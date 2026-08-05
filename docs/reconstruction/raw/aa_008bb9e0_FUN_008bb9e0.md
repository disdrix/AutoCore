# Raw capture: FUN_008bb9e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bb9e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bb9e0` |
| **Canonical name** | `FUN_008bb9e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008bb9e0(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  HWND pHVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float fVar8;
  undefined4 auStack_e0 [44];
  undefined4 uStack_30;
  undefined *puStack_2c;
  char *pcStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined *puStack_1c;
  
  if (DAT_00d1b644 == 0) goto LAB_008bba51;
  cVar1 = *(char *)(DAT_00d1b644 + 0x80);
  if (cVar1 != '\0') {
    iVar2 = param_1[0x145];
    if (iVar2 < 0) {
      param_1[0x145] = 10;
      puStack_1c = &DAT_00d1af90;
      uStack_20 = 0x8bba29;
      FUN_004ce020();
      puStack_1c = (undefined *)0x8bba39;
      FUN_005abba0();
      puStack_1c = (undefined *)0x8bba40;
      FUN_008bb520();
      *(undefined1 *)(param_1 + 0x144) = 1;
      puStack_1c = (undefined *)0x8bba51;
      (**(code **)(*param_1 + 0x448))();
    }
    else if (iVar2 < 1) {
      *(undefined1 *)(DAT_00d1b644 + 0x80) = 0;
      param_1[0x145] = -1;
      puStack_1c = (undefined *)0x8bba8f;
      iVar2 = FUN_00931fa0();
      if (iVar2 == 0) {
        puStack_1c = (undefined *)0x0;
        uStack_20 = 1;
        uStack_24 = 0xffffffff;
        pcStack_28 = "Failed to load map file.";
        puStack_2c = &DAT_00d1a840;
        uStack_30 = 0x8bbb86;
        FUN_007fdfb0();
        return;
      }
      if (iVar2 == 2) {
        param_1[0x145] = 8;
        *(char *)(DAT_00d1b644 + 0x80) = cVar1;
        return;
      }
      iVar5 = 0;
      iVar2 = 0;
      while( true ) {
        iVar4 = 0;
        if (*(int *)(DAT_00d1b644 + 0xe908) != 0) {
          iVar4 = (*(int *)(DAT_00d1b644 + 0xe90c) - *(int *)(DAT_00d1b644 + 0xe908)) / 200;
        }
        if (iVar4 <= iVar5) break;
        puVar6 = (undefined4 *)(*(int *)(DAT_00d1b644 + 0xe908) + iVar2);
        puVar7 = auStack_e0;
        for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        FUN_00720d40();
        FUN_00720670();
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + 200;
      }
      puStack_1c = (undefined *)0x8bbb16;
      FUN_00691630();
      if ((DAT_00d1b644 != 0) && (DAT_00d1b644 != -0x98)) {
        puStack_1c = (undefined *)(DAT_00d1b644 + 0xb4);
        uStack_20 = 0x8bbb34;
        uStack_20 = FUN_00720d40();
        uStack_24 = 0x8bbb3a;
        FUN_00720da0();
      }
      puStack_1c = (undefined *)0x8bbb46;
      (**(code **)(*param_1 + 0x448))();
    }
    else {
      param_1[0x145] = iVar2 + -1;
    }
    goto LAB_008bba51;
  }
  if (*(char *)(DAT_00d1b644 + 0x81) == '\0') goto LAB_008bba51;
  if (*(char *)(DAT_00d1b628 + 5) == '\0') {
    puStack_1c = (undefined *)0x8bbbaf;
    pHVar3 = GetForegroundWindow();
    if (pHVar3 == DAT_00d1d9c8) goto LAB_008bbbbd;
  }
  else {
LAB_008bbbbd:
    puStack_1c = (undefined *)param_2;
    uStack_20 = 0x8bbbc7;
    FUN_004e0ad0();
  }
  iVar2 = *(int *)(*(int *)(DAT_00d1b644 + 0xe64c) + 0xc);
  if (*(int *)(DAT_00d1b644 + 0x84) < 1) {
    fVar8 = 0.0;
  }
  else {
    fVar8 = (float)(*(int *)(DAT_00d1b644 + 0x84) - iVar2) / (float)*(int *)(DAT_00d1b644 + 0x84);
  }
  if ((float)param_1[0x146] + (float)param_1[0x147] < fVar8) {
    param_1[0x147] = (int)((float)param_1[0x146] + (float)param_1[0x147]);
    puStack_1c = (undefined *)0x8bbc21;
    FUN_008bb470();
  }
  uStack_20 = 0x8bbc38;
  puStack_1c = (undefined *)fVar8;
  (**(code **)(*(int *)param_1[0x164] + 0x3ac))();
  if (iVar2 < 1) {
    puStack_1c = (undefined *)0x8bbc4a;
    FUN_009347b0();
    return;
  }
LAB_008bba51:
  puStack_1c = (undefined *)param_2;
  uStack_20 = 0x8bba5d;
  FUN_00791f30();
  return;
}
```
