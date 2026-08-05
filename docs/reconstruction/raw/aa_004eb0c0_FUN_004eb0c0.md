# Raw capture: FUN_004eb0c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eb0c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004eb0c0` |
| **Canonical name** | `FUN_004eb0c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004eb0c0(int param_1)

{
  if ((DAT_00b04694 == '\0') && (*(undefined4 **)(param_1 + 0x3c) != (undefined4 *)0x0)) {
    (**(code **)**(undefined4 **)(param_1 + 0x3c))(1);
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  FUN_0059c000(param_1);
  return;
}
```
