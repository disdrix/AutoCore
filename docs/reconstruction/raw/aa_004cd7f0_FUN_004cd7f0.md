# Raw capture: FUN_004cd7f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd7f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cd7f0` |
| **Canonical name** | `FUN_004cd7f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cd7f0(int *param_1,float param_2)

{
  if ((param_1[0x393e] != 0) && (param_2 != *(float *)(param_1[0x393e] + 0x18))) {
    (**(code **)(*param_1 + 0xc))();
    FUN_004a82d0(param_2);
    (**(code **)(*param_1 + 8))();
  }
  return;
}
```
