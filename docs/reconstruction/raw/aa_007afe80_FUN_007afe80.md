# Raw capture: FUN_007afe80

| Field | Value |
|---|---|
| **Stable ID** | `aa_007afe80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007afe80` |
| **Canonical name** | `FUN_007afe80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007afe80(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc0) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2;
    }
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (*(int *)(*(int *)(param_1 + 0xc0) + iVar2 * 4) != 0) {
          FUN_004246a0();
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
  }
  return;
}
```
