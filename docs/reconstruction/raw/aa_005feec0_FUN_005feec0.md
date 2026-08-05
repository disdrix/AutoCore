# Raw capture: FUN_005feec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005feec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005feec0` |
| **Canonical name** | `FUN_005feec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005feec0(int param_1)

{
  FUN_005fee20(*(float *)(param_1 + -0x1c) + g_flOne);
  FUN_005fe9a0(*(float *)(param_1 + -0x18) + g_flOne);
  return;
}
```
