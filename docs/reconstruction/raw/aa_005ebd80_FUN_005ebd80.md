# Raw capture: FUN_005ebd80

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebd80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ebd80` |
| **Canonical name** | `FUN_005ebd80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005ebd80(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xc4)) {
    do {
      (**(code **)(**(int **)(*(int *)(param_1 + 0xc0) + iVar1 * 8) + 0x1c))
                (param_1 + 0xc,*(undefined4 *)(*(int *)(param_1 + 0xc0) + iVar1 * 8 + 4),
                 *(undefined4 *)(*(int *)(param_1 + 8) + 0xcc));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0xc4));
  }
  return;
}
```
