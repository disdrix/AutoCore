# Raw capture: FUN_004ccee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ccee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ccee0` |
| **Canonical name** | `FUN_004ccee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined1 FUN_004ccee0(undefined4 param_1)

{
  int iVar1;
  
  FUN_005c9be0(param_1);
  iVar1 = FUN_004ccf00(param_1);
  return *(undefined1 *)(iVar1 + 2);
}
```
