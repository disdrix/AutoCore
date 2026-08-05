# Raw capture: FUN_005c5fe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c5fe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c5fe0` |
| **Canonical name** | `FUN_005c5fe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005c5fe0(int param_1,undefined4 *param_2,int *param_3,float *param_4)

{
  float *pfVar1;
  int *piVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined1 local_8 [8];
  
  if (*(int *)(param_1 + 8) == 0) {
    FUN_005c5d40(param_2,1,*(undefined4 *)(param_1 + 4),param_4);
    return param_2;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_3 == (int *)*piVar2) {
    if (*param_4 <= (float)param_3[3] && (float)param_3[3] != *param_4) {
      FUN_005c5d40(param_2,1,param_3,param_4);
      return param_2;
    }
  }
  else if (param_3 == piVar2) {
    pfVar1 = (float *)(piVar2[2] + 0xc);
    if (*pfVar1 <= *param_4 && *param_4 != *pfVar1) {
      FUN_005c5d40(param_2,0,piVar2[2],param_4);
      return param_2;
    }
  }
  else {
    if (*param_4 <= (float)param_3[3] && (float)param_3[3] != *param_4) {
      FUN_005a2850();
      cVar3 = FUN_0058d960(param_3 + 3,param_4);
      if (cVar3 != '\0') {
        if (*(char *)(param_3[2] + 0x15) != '\0') {
          FUN_005c5d40(param_2,0,param_3,param_4);
          return param_2;
        }
        FUN_005c5d40(param_2,1,param_3,param_4);
        return param_2;
      }
    }
    if ((float)param_3[3] <= *param_4 && *param_4 != (float)param_3[3]) {
      FUN_00673070();
      if (param_3 != *(int **)(param_1 + 4)) {
        cVar3 = FUN_0058d960(param_4,param_3 + 3);
        if (cVar3 == '\0') goto LAB_005c6149;
      }
      if (*(char *)(param_3[2] + 0x15) != '\0') {
        FUN_005c5d40(param_2,0,param_3,param_4);
        return param_2;
      }
      FUN_005c5d40(param_2,1,param_3,param_4);
      return param_2;
    }
  }
LAB_005c6149:
  puVar4 = (undefined4 *)FUN_005c5f30(local_8,param_4);
  *param_2 = *puVar4;
  return param_2;
}
```
