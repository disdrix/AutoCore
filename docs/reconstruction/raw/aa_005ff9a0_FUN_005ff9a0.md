# Raw capture: FUN_005ff9a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ff9a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ff9a0` |
| **Canonical name** | `FUN_005ff9a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005ff9a0(int param_1)

{
  int iVar1;
  
  *(undefined ***)(param_1 + -0x150) = &PTR_LAB_009dddb4;
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1) = &PTR_LAB_009ddaec;
  iVar1 = *(int *)(*(int *)(param_1 + -0x14c) + 4);
  *(int *)(iVar1 + -0x150 + param_1) = iVar1 + -0x14c;
  FUN_0056d020();
  return;
}
```
