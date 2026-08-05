# Raw capture: FUN_0048bfd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048bfd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0048bfd0` |
| **Canonical name** | `FUN_0048bfd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0048bfd0(int param_1)

{
  FUN_0048aa20(&DAT_00a89e08,1);
  FUN_0048aa20(*(undefined4 **)(param_1 + 0x20) + 2,**(undefined4 **)(param_1 + 0x20));
  FUN_0048aa20(&DAT_00a3a4a0,1);
  return;
}
```
