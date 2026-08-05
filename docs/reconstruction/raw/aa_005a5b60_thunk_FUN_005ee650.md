# Raw capture: thunk_FUN_005ee650

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a5b60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a5b60` |
| **Canonical name** | `thunk_FUN_005ee650` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall thunk_FUN_005ee650(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009d81e8;
  if ((short)*(ushort *)(param_1 + 1) < 0) {
    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;
    FUN_005ffdb0(0);
  }
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```
