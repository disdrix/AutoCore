# Raw capture: FUN_004bbbc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbbc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bbbc0` |
| **Canonical name** | `FUN_004bbbc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_004bbbc0(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x140);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)CVOGReaction_ResolveObjectTarget
                              (*(undefined4 *)(param_1 + 0x130),*(uint *)(param_1 + 0x128),
                               *(undefined4 *)(param_1 + 300));
    *(int **)(param_1 + 0x140) = piVar2;
    if (piVar2 == (int *)0x0) {
      if ((*(uint *)(param_1 + 0x128) & *(uint *)(param_1 + 300)) == 0xffffffff) {
        return 1;
      }
      return 0;
    }
  }
  (**(code **)(*piVar2 + 0x144))();
  *(int *)(param_1 + 0x10) = piVar2[0x20];
  *(int *)(param_1 + 0x14) = piVar2[0x21];
  *(int *)(param_1 + 0x18) = piVar2[0x22];
  *(int *)(param_1 + 0x1c) = piVar2[0x23];
  uVar1 = (**(code **)(*piVar2 + 0x198))();
  *param_2 = uVar1;
  return 1;
}
```
