# Raw capture: FUN_0090daf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090daf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0090daf0` |
| **Canonical name** | `FUN_0090daf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0090daf0(int param_1,undefined1 param_2)

{
  FUN_004ba600();
  FUN_00590120();
  FUN_00593d70();
  FUN_007fc360();
  *(undefined1 *)(param_1 + 0x50e) = param_2;
  *(undefined4 *)(param_1 + 0x220) = 0xffffffff;
  return;
}
```
