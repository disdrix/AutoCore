# Raw capture: FUN_006bb0c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bb0c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bb0c0` |
| **Canonical name** | `FUN_006bb0c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006bb0c0(int *param_1,float *param_2)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  
  if (0 < param_1[1]) {
    pfVar2 = (float *)*param_1;
    fVar1 = pfVar2[1];
    fVar3 = pfVar2[2];
    fVar4 = pfVar2[3];
    *param_2 = *pfVar2;
    param_2[1] = fVar1;
    param_2[2] = fVar3;
    param_2[3] = fVar4;
    pfVar2 = (float *)*param_1;
    fVar1 = pfVar2[1];
    fVar3 = pfVar2[2];
    fVar4 = pfVar2[3];
    param_2[4] = *pfVar2;
    param_2[5] = fVar1;
    param_2[6] = fVar3;
    param_2[7] = fVar4;
    iVar6 = 0;
    if (0 < param_1[1]) {
      iVar5 = 0;
      do {
        fVar1 = *(float *)(iVar5 + *param_1);
        if (*param_2 < *(float *)(iVar5 + *param_1)) {
          fVar1 = *param_2;
        }
        *param_2 = fVar1;
        fVar1 = *(float *)(iVar5 + *param_1);
        if (*(float *)(iVar5 + *param_1) < param_2[4]) {
          fVar1 = param_2[4];
        }
        param_2[4] = fVar1;
        fVar1 = *(float *)(iVar5 + 4 + *param_1);
        if (param_2[1] < fVar1) {
          fVar1 = param_2[1];
        }
        param_2[1] = fVar1;
        fVar1 = *(float *)(iVar5 + 4 + *param_1);
        if (fVar1 < param_2[5]) {
          fVar1 = param_2[5];
        }
        param_2[5] = fVar1;
        fVar1 = *(float *)(iVar5 + 8 + *param_1);
        if (param_2[2] < fVar1) {
          fVar1 = param_2[2];
        }
        param_2[2] = fVar1;
        fVar1 = *(float *)(iVar5 + 8 + *param_1);
        if (fVar1 < param_2[6]) {
          fVar1 = param_2[6];
        }
        param_2[6] = fVar1;
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x10;
      } while (iVar6 < param_1[1]);
    }
  }
  return;
}
```
