# Raw capture: FUN_007fcdd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fcdd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fcdd0` |
| **Canonical name** | `FUN_007fcdd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fcdd0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x3c08);
  iVar2 = FUN_00418700(iVar1,*(undefined4 *)(iVar1 + 4),&stack0x00000008);
  FUN_00418790();
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}
```
