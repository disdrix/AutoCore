# Raw capture: FUN_0080bec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080bec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0080bec0` |
| **Canonical name** | `FUN_0080bec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0080bec0(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  int unaff_ESI;
  undefined8 uVar8;
  undefined4 uVar9;
  
  if ((*(char *)(param_1 + 4) != '\0') && (*(int *)(unaff_ESI + 0xe98) != 0)) {
    uVar9 = *(undefined4 *)(param_1 + 8);
    uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 4) + 4) + 4 +
                                 *(int *)(unaff_ESI + 0xe98)) + 0x27c))(uVar9);
    FUN_00533220(uVar7,uVar9);
    iVar3 = *(int *)(unaff_ESI + 0xe98);
    if (*(int *)(iVar3 + 0x660) < 1) {
      uVar8 = FUN_004119e0(0);
      puVar1 = (uint *)(iVar3 + 0x720);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 - (uint)uVar8;
      *(int *)(iVar3 + 0x724) =
           (*(int *)(iVar3 + 0x724) - (int)((ulonglong)uVar8 >> 0x20)) - (uint)(uVar2 < (uint)uVar8)
      ;
      *(uint *)(iVar3 + 0x634) = *(uint *)(iVar3 + 0x634) | 1;
    }
    FUN_00411990(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
    if ((((*(byte *)(param_1 + 8) & 1) != 0) && (DAT_00d1b874 != (int *)0x0)) &&
       (cVar5 = (**(code **)(*DAT_00d1b874 + 0x3d8))(), cVar5 == '\0')) {
      DAT_00d17928 = 1;
    }
    if ((((*(byte *)(param_1 + 8) & 0x40) != 0) && (DAT_00d1b870 != (int *)0x0)) &&
       (cVar5 = (**(code **)(*DAT_00d1b870 + 0x3d8))(), cVar5 == '\0')) {
      DAT_00d17929 = 1;
    }
    if ((((*(byte *)(param_1 + 8) & 4) != 0) && (DAT_00d1b87c != (int *)0x0)) &&
       (cVar5 = (**(code **)(*DAT_00d1b87c + 0x3d8))(), cVar5 == '\0')) {
      DAT_00d1792a = 1;
    }
    if ((*(int *)(unaff_ESI + 0x10b0) != 0) &&
       (cVar5 = (**(code **)(**(int **)(unaff_ESI + 0x10b0) + 0x3d8))(), cVar5 != '\0')) {
      FUN_008a05a0();
    }
    piVar4 = *(int **)(unaff_ESI + 0x10b0);
    if (piVar4 != (int *)0x0) {
      uVar6 = (**(code **)(*piVar4 + 0xd0))();
      cVar5 = (**(code **)(*piVar4 + 0x3d8))();
      FUN_007fca10();
      if (cVar5 != '\0') {
        FUN_007fef20(0x20,1,0);
        (**(code **)(*piVar4 + 4))(uVar6);
      }
    }
  }
  return;
}
```
