# Raw capture: FUN_005be7b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005be7b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005be7b0` |
| **Canonical name** | `FUN_005be7b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_005be7b0(int *param_1)

{
  if (DAT_00b45514 == 0) {
    return 0;
  }
  *param_1 = DAT_00b45514;
  FUN_005be6a0();
  return 1;
}
```
