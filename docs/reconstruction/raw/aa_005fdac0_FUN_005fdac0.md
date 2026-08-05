# Raw capture: FUN_005fdac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fdac0` |
| **Canonical name** | `FUN_005fdac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005fdac0(int param_1)

{
  if (-1 < (int)*(uint *)(param_1 + 0x14)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0xc),*(uint *)(param_1 + 0x14) & 0x7fffffff,0x12);
  }
  return;
}
```
