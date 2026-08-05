# Raw capture: FUN_0070fbc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0070fbc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0070fbc0` |
| **Canonical name** | `FUN_0070fbc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0070fbc0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  
  fVar2 = ((float)param_5 + (float)_DAT_00aaa5f8) / (float)param_6;
  iVar6 = 0;
  if (3 < param_4) {
    fVar3 = g_flOne - fVar2;
    pfVar4 = (float *)(param_2 + 4);
    pfVar5 = (float *)(param_3 + 8);
    do {
      iVar1 = iVar6 * 4;
      iVar6 = iVar6 + 4;
      pfVar5[-2] = fVar2 * pfVar4[-1] + fVar3 * *(float *)(param_1 + iVar1);
      *(float *)((int)pfVar4 + (param_3 - param_2)) =
           fVar2 * *pfVar4 + fVar3 * *(float *)((param_1 - param_2) + -0x10 + (int)(pfVar4 + 4));
      *pfVar5 = fVar2 * pfVar4[1] + fVar3 * *(float *)((int)pfVar5 + (param_1 - param_3));
      pfVar5[1] = fVar2 * pfVar4[2] + fVar3 * *(float *)(param_1 + -4 + iVar6 * 4);
      pfVar4 = pfVar4 + 4;
      pfVar5 = pfVar5 + 4;
    } while (iVar6 < param_4 + -3);
  }
  if (iVar6 < param_4) {
    fVar3 = g_flOne - fVar2;
    param_4 = param_4 - iVar6;
    pfVar4 = (float *)(param_2 + iVar6 * 4);
    do {
      param_4 = param_4 + -1;
      *(float *)((int)pfVar4 + (param_3 - param_2)) =
           fVar2 * *pfVar4 + fVar3 * *(float *)((int)pfVar4 + (param_1 - param_2));
      pfVar4 = pfVar4 + 1;
    } while (param_4 != 0);
  }
  return;
}
```
