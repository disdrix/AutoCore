# Raw capture: FUN_005dcaa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dcaa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dcaa0` |
| **Canonical name** | `FUN_005dcaa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005dcaa0(int param_1)

{
  FUN_00581d50();
  FUN_004e2600(&LAB_005db3d0,0,0);
  if ((*(char *)(param_1 + -0x60) != '\0') &&
     (*(undefined1 *)(param_1 + -0x60) = 0, *(int *)(param_1 + -0xe8) != 0)) {
    FUN_005081d0();
    return;
  }
  return;
}
```
