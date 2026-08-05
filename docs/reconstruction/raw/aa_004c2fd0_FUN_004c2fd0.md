# Raw capture: FUN_004c2fd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2fd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c2fd0` |
| **Canonical name** | `FUN_004c2fd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004c2fd0(int param_1,short param_2)

{
  if (*(short *)(param_1 + 0x12e) < param_2) {
    param_2 = *(short *)(param_1 + 0x12e);
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_2 != *(short *)(param_1 + 300)) {
    *(short *)(param_1 + 300) = param_2;
    FUN_00512150(3,(float)(int)param_2,0,0);
  }
  return;
}
```
