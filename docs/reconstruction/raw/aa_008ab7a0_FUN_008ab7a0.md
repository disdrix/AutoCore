# Raw capture: FUN_008ab7a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab7a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ab7a0` |
| **Canonical name** | `FUN_008ab7a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008ab7a0(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char cVar5;
  float *pfVar6;
  
  fVar2 = g_flOne;
  fVar1 = (float)param_1[0x143];
  param_1[0x143] = (int)(param_2 + fVar1);
  if (fVar2 < param_2 + fVar1) {
    cVar5 = (**(code **)(*param_1 + 0x3d8))();
    if (cVar5 != '\0') {
      cVar5 = (**(code **)(*param_1 + 0xd0))();
      if ((((cVar5 != '\0') && (iVar4 = param_1[0x191], iVar4 != 0)) && (DAT_00d1b6d8 != 0)) &&
         (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {
        param_1[0x143] = 0;
        pfVar6 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) +
                                      0x1a0))();
        fVar1 = *pfVar6;
        fVar2 = pfVar6[1];
        fVar3 = pfVar6[2];
        pfVar6 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +
                                               DAT_00d1b6d8) + 0x1a0))();
        if (DAT_00aaa6fc <
            SQRT((*pfVar6 - fVar1) * (*pfVar6 - fVar1) +
                 (pfVar6[1] - fVar2) * (pfVar6[1] - fVar2) +
                 (pfVar6[2] - fVar3) * (pfVar6[2] - fVar3))) {
          FUN_007fcdd0(&DAT_00d1a840,10);
        }
      }
    }
  }
  FUN_00791f30(param_2);
  return;
}
```
