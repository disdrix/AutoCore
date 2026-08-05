# Raw capture: FUN_0040acb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040acb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040acb0` |
| **Canonical name** | `FUN_0040acb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0040acb0(int param_1,float param_2)

{
  int iVar1;
  
  iVar1 = _isnan((double)param_2);
  if (iVar1 == 0) {
    *(float *)(param_1 + 0x138) = param_2;
  }
  return;
}
```
