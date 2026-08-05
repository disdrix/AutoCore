# Raw capture: FUN_004ab3d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ab3d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ab3d0` |
| **Canonical name** | `FUN_004ab3d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_004ab3d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar4 = param_1;
  if (*(int *)(param_1 + 4) == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3;
  }
  iVar5 = uVar6 * -0x55555555;
  uVar6 = uVar6 / 3;
  iVar7 = 0;
  if (3 < uVar6) {
    param_1 = (uVar6 - 4 >> 2) + 1;
    iVar7 = param_1 * 4;
    iVar5 = 0x18;
    do {
      iVar1 = *(int *)(iVar4 + 4);
      if (0.0 < (*(float *)(iVar1 + -0xc + iVar5) - *(float *)(iVar1 + -4 + iVar5)) *
                (*(float *)(iVar1 + -0x18 + iVar5) - *(float *)(iVar1 + -0x10 + iVar5)) -
                (*(float *)(iVar1 + -0x14 + iVar5) - *(float *)(iVar1 + -0xc + iVar5)) *
                (*(float *)(iVar1 + -0x10 + iVar5) - *(float *)(iVar1 + -8 + iVar5))) {
        uVar2 = *(undefined4 *)(iVar1 + -0x18 + iVar5);
        uVar3 = *(undefined4 *)(iVar1 + -0x14 + iVar5);
        *(undefined4 *)(iVar1 + -0x18 + iVar5) = *(undefined4 *)(iVar1 + -0x10 + iVar5);
        *(undefined4 *)(iVar1 + -0x14 + iVar5) = *(undefined4 *)(iVar1 + -0xc + iVar5);
        iVar1 = *(int *)(iVar4 + 4);
        *(undefined4 *)(iVar5 + -0x10 + iVar1) = uVar2;
        *(undefined4 *)(iVar5 + -0xc + iVar1) = uVar3;
      }
      iVar1 = *(int *)(iVar4 + 4);
      if (0.0 < (*(float *)(iVar1 + 0xc + iVar5) - *(float *)(iVar1 + 0x14 + iVar5)) *
                (*(float *)(iVar1 + iVar5) - *(float *)(iVar1 + 8 + iVar5)) -
                (*(float *)(iVar1 + 4 + iVar5) - *(float *)(iVar1 + 0xc + iVar5)) *
                (*(float *)(iVar1 + 8 + iVar5) - *(float *)(iVar1 + 0x10 + iVar5))) {
        uVar2 = *(undefined4 *)(iVar1 + iVar5);
        uVar3 = *(undefined4 *)(iVar1 + 4 + iVar5);
        *(undefined4 *)(iVar1 + iVar5) = *(undefined4 *)(iVar1 + 8 + iVar5);
        *(undefined4 *)(iVar1 + 4 + iVar5) = *(undefined4 *)(iVar1 + 0xc + iVar5);
        iVar1 = *(int *)(iVar4 + 4);
        *(undefined4 *)(iVar5 + 8 + iVar1) = uVar2;
        *(undefined4 *)(iVar5 + 0xc + iVar1) = uVar3;
      }
      iVar1 = *(int *)(iVar4 + 4);
      if (0.0 < (*(float *)(iVar1 + 0x24 + iVar5) - *(float *)(iVar1 + 0x2c + iVar5)) *
                (*(float *)(iVar1 + 0x18 + iVar5) - *(float *)(iVar1 + 0x20 + iVar5)) -
                (*(float *)(iVar1 + 0x1c + iVar5) - *(float *)(iVar1 + 0x24 + iVar5)) *
                (*(float *)(iVar1 + 0x20 + iVar5) - *(float *)(iVar1 + 0x28 + iVar5))) {
        uVar2 = *(undefined4 *)(iVar1 + 0x18 + iVar5);
        uVar3 = *(undefined4 *)(iVar1 + 0x1c + iVar5);
        *(undefined4 *)(iVar1 + 0x18 + iVar5) = *(undefined4 *)(iVar1 + 0x20 + iVar5);
        *(undefined4 *)(iVar1 + 0x1c + iVar5) = *(undefined4 *)(iVar1 + 0x24 + iVar5);
        iVar1 = *(int *)(iVar4 + 4);
        *(undefined4 *)(iVar5 + 0x20 + iVar1) = uVar2;
        *(undefined4 *)(iVar5 + 0x24 + iVar1) = uVar3;
      }
      iVar1 = *(int *)(iVar4 + 4);
      if (0.0 < (*(float *)(iVar1 + 0x3c + iVar5) - *(float *)(iVar1 + 0x44 + iVar5)) *
                (*(float *)(iVar1 + 0x30 + iVar5) - *(float *)(iVar1 + 0x38 + iVar5)) -
                (*(float *)(iVar1 + 0x34 + iVar5) - *(float *)(iVar1 + 0x3c + iVar5)) *
                (*(float *)(iVar1 + 0x38 + iVar5) - *(float *)(iVar1 + 0x40 + iVar5))) {
        uVar2 = *(undefined4 *)(iVar1 + 0x30 + iVar5);
        uVar3 = *(undefined4 *)(iVar1 + 0x34 + iVar5);
        *(undefined4 *)(iVar1 + 0x30 + iVar5) = *(undefined4 *)(iVar1 + 0x38 + iVar5);
        *(undefined4 *)(iVar1 + 0x34 + iVar5) = *(undefined4 *)(iVar1 + 0x3c + iVar5);
        iVar1 = *(int *)(iVar4 + 4);
        *(undefined4 *)(iVar5 + 0x38 + iVar1) = uVar2;
        *(undefined4 *)(iVar5 + 0x3c + iVar1) = uVar3;
      }
      iVar5 = iVar5 + 0x60;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  if (iVar7 < (int)uVar6) {
    iVar5 = iVar7 * 0x18;
    iVar7 = uVar6 - iVar7;
    do {
      iVar1 = *(int *)(iVar4 + 4);
      if (0.0 < (*(float *)(iVar1 + 0xc + iVar5) - *(float *)(iVar1 + 0x14 + iVar5)) *
                (*(float *)(iVar1 + iVar5) - *(float *)(iVar1 + 8 + iVar5)) -
                (*(float *)(iVar1 + 4 + iVar5) - *(float *)(iVar1 + 0xc + iVar5)) *
                (*(float *)(iVar1 + 8 + iVar5) - *(float *)(iVar1 + 0x10 + iVar5))) {
        uVar2 = *(undefined4 *)(iVar1 + iVar5);
        uVar3 = *(undefined4 *)(iVar1 + 4 + iVar5);
        *(undefined4 *)(iVar1 + iVar5) = *(undefined4 *)(iVar1 + 8 + iVar5);
        *(undefined4 *)(iVar1 + 4 + iVar5) = *(undefined4 *)(iVar1 + 0xc + iVar5);
        iVar1 = *(int *)(iVar4 + 4);
        *(undefined4 *)(iVar5 + 8 + iVar1) = uVar2;
        *(undefined4 *)(iVar5 + 0xc + iVar1) = uVar3;
      }
      iVar5 = iVar5 + 0x18;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  return iVar5;
}
```
