# Raw capture: FUN_004ccbe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ccbe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ccbe0` |
| **Canonical name** | `FUN_004ccbe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004ccbe0(int param_1,int param_2)

{
  char cVar1;
  
  cVar1 = FUN_00513e70();
  if (cVar1 != '\0') {
    if (*(int *)(param_1 + -0x28) != param_2) {
      FUN_00512670();
    }
    *(int *)(param_1 + -0x28) = param_2;
    return;
  }
  *(int *)(param_1 + -0x28) = param_2;
  return;
}
```
