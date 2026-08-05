# Raw capture: FUN_004cd5d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd5d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cd5d0` |
| **Canonical name** | `FUN_004cd5d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cd5d0(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0xe82c + param_2 * 4);
  *piVar1 = *piVar1 + 1;
  return;
}
```
