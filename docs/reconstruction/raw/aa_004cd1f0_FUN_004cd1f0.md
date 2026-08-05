# Raw capture: FUN_004cd1f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd1f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cd1f0` |
| **Canonical name** | `FUN_004cd1f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004cd1f0(int param_1)

{
  if (*(undefined4 **)(param_1 + 0xe4fc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xe4fc))(1);
  }
  *(undefined4 *)(param_1 + 0xe4fc) = 0;
  return;
}
```
