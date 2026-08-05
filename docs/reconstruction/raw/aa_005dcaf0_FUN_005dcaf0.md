# Raw capture: FUN_005dcaf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dcaf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dcaf0` |
| **Canonical name** | `FUN_005dcaf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005dcaf0(int param_1)

{
  FUN_00581d10();
  FUN_004e2600(&LAB_005db400,0,0);
  if (*(char *)(param_1 + -0x60) != '\x01') {
    *(undefined1 *)(param_1 + -0x60) = 1;
    if (*(CVOGHBBase **)(param_1 + -0xe8) != (CVOGHBBase *)0x0) {
      CVOGHBBase_Start(*(CVOGHBBase **)(param_1 + -0xe8));
    }
    if (*(char *)(param_1 + -0x35) != '\0') {
      FUN_005de1b0(0,0,0,0,0);
    }
  }
  return;
}
```
