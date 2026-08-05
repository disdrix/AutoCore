# Raw capture: FUN_007ab2e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ab2e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ab2e0` |
| **Canonical name** | `FUN_007ab2e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007ab2e0(int *param_1)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int *unaff_retaddr;
  undefined1 local_28 [32];
  undefined1 local_8 [8];
  
  if (*(char *)((int)param_1 + 0x1ca) == '\0') {
    pfVar3 = (float *)(**(code **)(*param_1 + 0x134))(local_8);
    iVar1 = DAT_00d1e818;
    iVar2 = DAT_00d1e81c;
  }
  else {
    pfVar3 = (float *)(**(code **)(*param_1 + 0x134))(local_28);
    iVar1 = *(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80);
    iVar2 = *(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84);
  }
  if (*(char *)((int)param_1 + 0x1c9) == '\0') {
    if (DAT_00d17944 != 0) {
      fVar4 = ((float)param_1[0x1e] * DAT_00aaa674) / (float)DAT_00d1e818;
      fVar6 = ((float)param_1[0x1f] * DAT_00aaa670) / (float)DAT_00d1e81c;
      goto LAB_007ab3eb;
    }
  }
  else if (DAT_00d17944 != 0) {
    fVar4 = ((float)param_1[0x1e] * DAT_00aaa674) /
            (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80);
    fVar6 = ((float)param_1[0x1f] * DAT_00aaa670) /
            (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84);
    goto LAB_007ab3eb;
  }
  fVar6 = 0.0;
  fVar4 = 0.0;
LAB_007ab3eb:
  if (DAT_00d17944 == 0) {
    fVar5 = 0.0;
    fVar7 = 0.0;
  }
  else {
    fVar5 = ((float)param_1[0x97] * (float)iVar1 * *pfVar3 * DAT_00aaa67c * DAT_00aaa674) /
            (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80);
    fVar7 = ((float)param_1[0x98] * (float)iVar2 * pfVar3[1] * DAT_00aaa678 * DAT_00aaa670) /
            (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84);
  }
  *unaff_retaddr = (int)ROUND(fVar5 + fVar4);
  unaff_retaddr[1] = (int)ROUND(fVar7 + fVar6);
  return;
}
```
