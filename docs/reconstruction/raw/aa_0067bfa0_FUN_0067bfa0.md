# Raw capture: FUN_0067bfa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067bfa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067bfa0` |
| **Canonical name** | `FUN_0067bfa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall
FUN_0067bfa0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  *param_1 = 0;
  param_1[1] = param_4;
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  param_1[4] = param_2[2];
  param_1[5] = param_2[3];
  if (param_4 != 0) {
    puVar1 = operator_new__(param_4);
    uVar2 = param_4 >> 2;
    *param_1 = puVar1;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar1 = *param_3;
      param_3 = param_3 + 1;
      puVar1 = puVar1 + 1;
    }
    for (param_4 = param_4 & 3; param_4 != 0; param_4 = param_4 - 1) {
      *(undefined1 *)puVar1 = *(undefined1 *)param_3;
      param_3 = (undefined4 *)((int)param_3 + 1);
      puVar1 = (undefined4 *)((int)puVar1 + 1);
    }
  }
  return param_1;
}
```
