# Raw capture: FUN_005fc1f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc1f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fc1f0` |
| **Canonical name** | `FUN_005fc1f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005fc1f0(undefined4 *param_1,int param_2,undefined4 param_3)

{
  CVOGHBBase_ctor(param_1);
  *param_1 = &PTR_FUN_009dd2f0;
  CVOGHBBase_SetPeriodAndCounter(param_1,1,true);
  param_1[2] = param_3;
  if (param_2 == 0) {
    CVOGHBBase_AttachOwnerObject(param_1,(void *)0x0);
    return param_1;
  }
  CVOGHBBase_AttachOwnerObject(param_1,(void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2));
  return param_1;
}
```
