# Raw capture: FUN_006c7bc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c7bc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c7bc0` |
| **Canonical name** | `FUN_006c7bc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_006c7bc0(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  undefined4 uVar2;
  
  *param_1 = &PTR_FUN_009e5fdc;
  *(undefined2 *)((int)param_1 + 6) = 1;
  uVar2 = *param_2;
  *param_1 = &PTR_FUN_009e6008;
  param_1[2] = uVar2;
  param_1[3] = param_2[1];
  *param_1 = &PTR_FUN_00a0d530;
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  if ((float)param_1[5] <= (float)param_1[4]) {
    fVar1 = (float)param_1[5];
  }
  else {
    fVar1 = (float)param_1[4];
  }
  param_1[7] = fVar1;
  if ((float)param_1[6] < fVar1) {
    fVar1 = (float)param_1[6];
  }
  param_1[7] = fVar1;
  return param_1;
}
```
