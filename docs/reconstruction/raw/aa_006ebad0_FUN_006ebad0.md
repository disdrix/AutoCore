# Raw capture: FUN_006ebad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ebad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ebad0` |
| **Canonical name** | `FUN_006ebad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006ebad0(undefined4 *param_1,int *param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  undefined8 uVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined1 auStack_38c [12];
  undefined1 local_380 [32];
  undefined1 local_360 [44];
  undefined4 *puStack_334;
  int iStack_330;
  undefined1 *puStack_32c;
  undefined4 uStack_328;
  undefined4 uStack_324;
  undefined1 auStack_320 [508];
  undefined1 auStack_124 [288];
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "LtBvTree";
    uVar2 = rdtsc();
    DAT_00bc5644[1] = (int)uVar2;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  FUN_0063a3f0(param_2[2] + 0x20,param_1[2] + 0x20);
  iVar7 = param_3[2];
  (**(code **)(*(int *)*param_1 + 0x18))(local_360,iVar7,local_380);
  piVar1 = (int *)*param_2;
  puStack_32c = auStack_320;
  uStack_328 = 0;
  uStack_324 = 0x80000080;
  (**(code **)(*piVar1 + 0x30))(auStack_38c,&puStack_32c);
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "StNarrowPhase";
    uVar2 = rdtsc();
    DAT_00bc5644[1] = (int)uVar2;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  (**(code **)(*(int *)*param_1 + 0x14))();
  piVar1 = (int *)piVar1[3];
  puVar8 = puStack_334 + iStack_330;
  puVar6 = puStack_334;
  if (puStack_334 != puVar8) {
    do {
      pcVar3 = (char *)(*(code *)**(undefined4 **)param_3[1])
                                 (&stack0xfffffc57,param_3,param_1,param_2,piVar1,*puVar6);
      if (*pcVar3 != '\0') {
        piVar4 = (int *)(**(code **)(*piVar1 + 0x34))(*puVar6,auStack_124);
        puVar8 = (undefined4 *)*puVar6;
        iVar5 = (**(code **)(*piVar4 + 0x14))();
        (**(code **)(*param_3 + 0x218c + (iVar7 * 0x20 + iVar5) * 4))
                  (param_1,&stack0xfffffc54,param_3,param_4);
      }
      puVar6 = puVar6 + 1;
    } while (puVar6 != puVar8);
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d282c;
    uVar2 = rdtsc();
    DAT_00bc5644[1] = (int)uVar2;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  if (-1 < (int)puStack_32c) {
    (**(code **)(*DAT_00b05060 + 0x14))(puStack_334,(int)puStack_32c << 2,0x12);
  }
  return;
}
```
