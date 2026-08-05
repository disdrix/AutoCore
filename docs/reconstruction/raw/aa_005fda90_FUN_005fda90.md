# Raw capture: FUN_005fda90

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fda90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fda90` |
| **Canonical name** | `FUN_005fda90` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005fda90(int param_1)

{
  if (-1 < *(int *)(param_1 + 0x58)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x50),*(int *)(param_1 + 0x58) * 4,0x12);
  }
  return;
}
```
