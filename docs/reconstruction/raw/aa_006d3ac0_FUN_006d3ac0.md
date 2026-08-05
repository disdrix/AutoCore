# Raw capture: FUN_006d3ac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006d3ac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006d3ac0` |
| **Canonical name** | `FUN_006d3ac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006d3ac0(undefined1 *param_1,float *param_2,float *param_3,int param_4)

{
  float fVar1;
  
  if (DAT_00aaa6d4 <= param_3[3]) {
    if ((param_3[4] * param_2[4] + param_3[5] * param_2[5] + param_3[6] * param_2[6] <
         *(float *)(param_4 + 0x10)) &&
       (fVar1 = (*param_3 - *param_2) * param_2[4] +
                (param_3[1] - param_2[1]) * param_2[5] + (param_3[2] - param_2[2]) * param_2[6],
       fVar1 < *(float *)(param_4 + 0xc) != (fVar1 == *(float *)(param_4 + 0xc)))) {
      *param_1 = 0;
      return;
    }
  }
  *param_1 = 1;
  return;
}
```
