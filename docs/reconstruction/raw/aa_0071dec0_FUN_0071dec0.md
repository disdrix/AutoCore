# Raw capture: FUN_0071dec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071dec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071dec0` |
| **Canonical name** | `FUN_0071dec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0071dec0(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 local_c [4];
  undefined4 local_8;
  undefined1 local_4 [4];
  
  uVar1 = param_2;
  if (*(int *)(param_2 + 0x4044) == 0) {
    FUN_00445170(&param_2);
  }
  else {
    FUN_007693e0(&param_2);
  }
  uVar2 = param_2 & 0xff;
  if (uVar2 != 0) {
    param_2 = param_1 + 0x10;
    do {
      if (*(int *)(uVar1 + 0x4044) == 0) {
        if ((*(int *)(uVar1 + 0x18) + 1 <= *(int *)(uVar1 + 0x20)) ||
           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&
            (0 < *(int *)(uVar1 + 0x20))))) {
          local_c[0] = *(undefined1 *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);
          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 1;
        }
      }
      else {
        FUN_007693e0(local_c);
      }
      if (*(int *)(uVar1 + 0x4044) == 0) {
        if ((*(int *)(uVar1 + 0x18) + 4 <= *(int *)(uVar1 + 0x20)) ||
           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&
            (3 < *(int *)(uVar1 + 0x20))))) {
          local_8 = *(undefined4 *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);
          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 4;
        }
      }
      else {
        FUN_007689e0(&local_8);
      }
      FUN_00718fd0(uVar1,local_4);
      FUN_00480ca0();
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0;
}
```
