# Raw capture: FUN_0070fcd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0070fcd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0070fcd0` |
| **Canonical name** | `FUN_0070fcd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0070fcd0(undefined4 *param_1,float *param_2,int param_3)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float10 fVar10;
  
  fVar9 = (float10)*param_2;
  if (*param_2 != g_flZero) {
    uVar6 = 0;
    if (0 < param_3) {
      pfVar3 = param_2 + -2;
      do {
        iVar5 = 0;
        fVar10 = -(float10)pfVar3[3];
        if (3 < (int)uVar6) {
          iVar7 = (uVar6 - 4 >> 2) + 1;
          iVar5 = iVar7 * 4;
          pfVar2 = (float *)(param_1 + 2);
          pfVar4 = pfVar3;
          do {
            iVar7 = iVar7 + -1;
            fVar10 = (((fVar10 - (float10)pfVar4[2] * (float10)pfVar2[-2]) -
                      (float10)pfVar4[1] * (float10)pfVar2[-1]) -
                     (float10)*pfVar4 * (float10)*pfVar2) - (float10)pfVar4[-1] * (float10)pfVar2[1]
            ;
            pfVar2 = pfVar2 + 4;
            pfVar4 = pfVar4 + -4;
          } while (iVar7 != 0);
        }
        if (iVar5 < (int)uVar6) {
          pfVar2 = param_2 + (uVar6 - iVar5);
          do {
            pfVar4 = (float *)(param_1 + iVar5);
            iVar5 = iVar5 + 1;
            fVar1 = *pfVar2;
            pfVar2 = pfVar2 + -1;
            fVar10 = fVar10 - (float10)*pfVar4 * (float10)fVar1;
          } while (iVar5 < (int)uVar6);
        }
        iVar7 = (int)uVar6 >> 1;
        iVar5 = 0;
        fVar10 = fVar10 / (fVar9 + (float10)*param_2 * (float10)_DAT_00a0f290);
        param_1[uVar6] = (float)fVar10;
        if (3 < iVar7) {
          iVar8 = (iVar7 - 4U >> 2) + 1;
          iVar5 = iVar8 * 4;
          pfVar2 = (float *)(param_1 + 2);
          pfVar4 = (float *)(((int)param_1 - (int)param_2) + (int)pfVar3);
          do {
            fVar1 = pfVar2[-2];
            iVar8 = iVar8 + -1;
            pfVar2[-2] = (float)(fVar10 * (float10)pfVar4[1] + (float10)pfVar2[-2]);
            pfVar4[1] = (float)((float10)fVar1 * fVar10 + (float10)pfVar4[1]);
            fVar1 = pfVar2[-1];
            pfVar2[-1] = (float)(fVar10 * (float10)*pfVar4 + (float10)pfVar2[-1]);
            *pfVar4 = (float)((float10)fVar1 * fVar10 + (float10)*pfVar4);
            fVar1 = *pfVar2;
            *pfVar2 = (float)(fVar10 * (float10)pfVar4[-1] + (float10)*pfVar2);
            pfVar4[-1] = (float)((float10)fVar1 * fVar10 + (float10)pfVar4[-1]);
            fVar1 = pfVar2[1];
            pfVar2[1] = (float)(fVar10 * (float10)pfVar4[-2] + (float10)pfVar2[1]);
            pfVar4[-2] = (float)((float10)fVar1 * fVar10 + (float10)pfVar4[-2]);
            pfVar2 = pfVar2 + 4;
            pfVar4 = pfVar4 + -4;
          } while (iVar8 != 0);
        }
        if (iVar5 < iVar7) {
          pfVar2 = (float *)(param_1 + (uVar6 - iVar5) + -1);
          iVar8 = iVar5;
          do {
            fVar1 = (float)param_1[iVar8];
            iVar5 = iVar8 + 1;
            param_1[iVar8] = (float)(fVar10 * (float10)*pfVar2 + (float10)(float)param_1[iVar8]);
            *pfVar2 = (float)((float10)fVar1 * fVar10 + (float10)*pfVar2);
            pfVar2 = pfVar2 + -1;
            iVar8 = iVar5;
          } while (iVar5 < iVar7);
        }
        if ((uVar6 & 1) != 0) {
          param_1[iVar5] =
               (float)(fVar10 * (float10)(float)param_1[iVar5] + (float10)(float)param_1[iVar5]);
        }
        uVar6 = uVar6 + 1;
        pfVar3 = pfVar3 + 1;
        fVar9 = fVar9 - fVar10 * fVar9 * fVar10;
      } while ((int)uVar6 < param_3);
    }
    return fVar9;
  }
  if (0 < param_3) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      *param_1 = 0;
      param_1 = param_1 + 1;
    }
  }
  return (float10)g_flZero;
}
```
