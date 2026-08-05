# Raw capture: FUN_007fd3d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fd3d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fd3d0` |
| **Canonical name** | `FUN_007fd3d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fd3d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x30a0) != 0) {
    FUN_0083edf0();
    FUN_0083ee80(param_1,param_2,param_3,param_4);
    *(undefined1 *)(unaff_EDI + 0x30b6) = 0;
    *(undefined1 *)(unaff_EDI + 0x30b7) = 1;
  }
  return;
}
```
