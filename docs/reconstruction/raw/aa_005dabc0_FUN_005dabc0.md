# Raw capture: FUN_005dabc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dabc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dabc0` |
| **Canonical name** | `FUN_005dabc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005dabc0(undefined4 *param_1,void *param_2,undefined4 param_3)

{
  CVOGHBBase_ctor(param_1);
  *param_1 = &PTR_FUN_009db56c;
  CVOGHBBase_SetPeriodAndCounter(param_1,-1000,true);
  param_1[2] = param_3;
  CVOGHBBase_AttachOwnerObject(param_1,param_2);
  return param_1;
}
```
