# Raw capture: FUN_0063fbfa

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063fbfa` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0063fbfa` |
| **Canonical name** | `FUN_0063fbfa` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_0063fbfa(undefined4 *param_1)

{
  undefined4 in_EAX;
  bool in_ZF;
  
  param_1[5] = in_EAX;
  param_1[2] = in_EAX;
  *param_1 = in_EAX;
  if (!in_ZF) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(undefined2 *)(param_1 + 1),0x10);
  }
  return param_1;
}
```
