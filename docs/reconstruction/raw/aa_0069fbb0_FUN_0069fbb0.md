# Raw capture: FUN_0069fbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0069fbb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0069fbb0` |
| **Canonical name** | `FUN_0069fbb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4
FUN_0069fbb0(undefined4 param_1,float *param_2,float *param_3,float *param_4,float *param_5,
            float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (*param_3 - *param_2) * param_6 + *param_2;
  fVar2 = (param_3[1] - param_2[1]) * param_6 + param_2[1];
  fVar3 = (*param_4 - *param_3) * param_6 + *param_3;
  fVar4 = (param_4[1] - param_3[1]) * param_6 + param_3[1];
  fVar1 = (fVar3 - fVar1) * param_6 + fVar1;
  fVar2 = (fVar4 - fVar2) * param_6 + fVar2;
  FUN_00696d50((((((*param_5 - *param_4) * param_6 + *param_4) - fVar3) * param_6 + fVar3) - fVar1)
               * param_6 + fVar1,
               (((((param_5[1] - param_4[1]) * param_6 + param_4[1]) - fVar4) * param_6 + fVar4) -
               fVar2) * param_6 + fVar2);
  return param_1;
}
```
