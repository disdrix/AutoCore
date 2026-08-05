# Raw capture: FUN_005cebd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cebd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cebd0` |
| **Canonical name** | `FUN_005cebd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
char __thiscall FUN_005cebd0(int *param_1,char param_2)

{
  int iVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  
  iVar5 = *(int *)(param_1[0x19] + 0xf8);
  if (iVar5 == 0) {
    return '\0';
  }
  CVOGWaypoint_UpdateState();
  if (*(char *)(iVar5 + 0x52) == '\0') {
    if (param_2 == '\0') {
      iVar4 = param_1[0x19];
      local_30 = *(float *)(iVar4 + 0x228);
      local_2c = *(float *)(iVar4 + 0x22c);
      local_28 = *(float *)(iVar4 + 0x230);
      local_24 = *(undefined4 *)(iVar4 + 0x234);
      iVar4 = TFID_NotEquals(&local_30,g_abTfidInvalid_9DA850);
      if ((char)iVar4 != '\0') {
        cVar3 = (**(code **)(*param_1 + 0x54))();
        if (cVar3 == '\0') {
          return '\0';
        }
        goto LAB_005cec99;
      }
    }
    iVar4 = param_1[0x19];
    if (*(int *)(iVar4 + 600) == 0) {
      return '\0';
    }
    pfVar6 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1a0))
                                ();
    iVar4 = *(int *)(param_1[0x19] + 600);
    iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);
    fStack_20 = *(float *)(iVar1 + 0x84 + iVar4);
    iVar4 = iVar1 + 0x84 + iVar4;
    fStack_1c = *(float *)(iVar4 + 4);
    fStack_18 = *(float *)(iVar4 + 8);
    local_28 = fStack_18 - pfVar6[2];
    local_2c = fStack_1c - pfVar6[1];
    local_30 = fStack_20 - *pfVar6;
    uStack_14 = *(undefined4 *)(iVar4 + 0xc);
    fVar2 = SQRT(local_30 * local_30 + local_2c * local_2c + local_28 * local_28);
    if (*(char *)((int)param_1 + 0x95) == '\0') {
      if (*(float *)(iVar5 + 0x4c) <= fVar2 && fVar2 != *(float *)(iVar5 + 0x4c)) {
        *(undefined1 *)((int)param_1 + 0x95) = 1;
      }
      if (*(char *)((int)param_1 + 0x95) == '\0') {
        return '\0';
      }
    }
    if (((*(int *)(param_1[6] + 0xa0) != 0) && (fVar2 < *(float *)(iVar5 + 0x4c) * DAT_00a0f710)) ||
       (fVar2 < *(float *)(iVar5 + 0x4c) * g_flMultiKillCountBlend)) {
      *(undefined1 *)((int)param_1 + 0x95) = 0;
      return '\0';
    }
    (**(code **)(*param_1 + 0x4c))(&fStack_20,0);
    cVar3 = '\x01';
  }
  else if ((*(char *)(iVar5 + 0x53) == '\0') || (*(float *)(iVar5 + 0x4c) == g_flZero)) {
    (**(code **)(*param_1 + 0x4c))(iVar5 + 0x20,0);
    cVar3 = '\x01';
  }
  else {
    if (*(int *)(param_1[6] + 0xa0) != 0) {
      return '\0';
    }
    (**(code **)(*param_1 + 0x4c))(iVar5 + 0x20,0);
    cVar3 = '\x01';
  }
LAB_005cec99:
  if ((uint)param_1[10] <= (uint)param_1[2]) {
    iVar5 = param_1[9] / 2 + param_1[9];
    param_1[10] = iVar5;
    param_1[2] = iVar5;
  }
  return cVar3;
}
```
