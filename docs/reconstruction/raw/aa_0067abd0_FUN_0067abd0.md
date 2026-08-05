# Raw capture: FUN_0067abd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067abd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067abd0` |
| **Canonical name** | `FUN_0067abd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0067abd0(int param_1,int param_2)

{
  if ((param_2 != 0) && (3 < *(uint *)(param_1 + 0xc))) {
    FUN_00680c80(param_2,4);
  }
  return;
}
```
