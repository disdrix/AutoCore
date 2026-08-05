# Annotated low-level: CVOGHBAIDriver_ReturnToNormalLocation

| Field | Value |
|---|---|
| Stable ID | `aa_005d6e80` |
| VA | `0x005d6e80` |
| System | input-drive-control |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d6e80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
char __fastcall CVOGHBAIDriver_ReturnToNormalLocation(int *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  float *pfVar6;
  bool bVar7;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a7158;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_0076cf00("CVOGHBAIDriver::ReturnToNormalLocation()");
  bVar7 = *(int *)(param_1[6] + 0xa0) != 0;
  iVar5 = param_1[0x19];
  local_24 = *(undefined4 *)(iVar5 + 0x234);
  cVar4 = '\0';
  local_14 = 0;
  if (((*(uint *)(iVar5 + 0x228) & *(uint *)(iVar5 + 0x22c)) == 0xffffffff) &&
     ((char)*(undefined4 *)(iVar5 + 0x230) == '\0')) {
    iVar5 = *(int *)(param_1[0x2f] + 0xf8);
    CVOGWaypoint_UpdateState();
    if (*(char *)(iVar5 + 0x52) == '\0') {
      iVar1 = param_1[0x2f];
      if (*(int *)(iVar1 + 0x280) == 0) {
        if (!bVar7) {
          param_1[10] = 1000;
        }
        goto LAB_005d6f1a;
      }
      if (*(int *)(iVar1 + 8) == 0) {
        pfVar6 = (float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);
      }
      else {
        pfVar6 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);
      }
      iVar1 = *(int *)(iVar1 + 0x280);
      iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);
      local_30 = *(float *)(iVar2 + 0x84 + iVar1);
      iVar1 = iVar2 + 0x84 + iVar1;
      local_2c = *(float *)(iVar1 + 4);
      local_28 = *(float *)(iVar1 + 8);
      local_24 = *(undefined4 *)(iVar1 + 0xc);
      fVar3 = SQRT((local_28 - pfVar6[2]) * (local_28 - pfVar6[2]) +
                   (local_2c - pfVar6[1]) * (local_2c - pfVar6[1]) +
                   (local_30 - *pfVar6) * (local_30 - *pfVar6));
      if (*(char *)((int)param_1 + 0x95) == '\0') {
        if (*(float *)(iVar5 + 0x4c) < fVar3) {
          *(undefined1 *)((int)param_1 + 0x95) = 1;
        }
        if (*(char *)((int)param_1 + 0x95) == '\0') goto LAB_005d6f1a;
      }
      if ((bVar7) &&
         ((fVar3 < *(float *)(iVar5 + 0x4c) * DAT_00a0f70c ||
          (fVar3 < *(float *)(iVar5 + 0x4c) * g_flMultiKillCountBlend)))) {
        *(undefined1 *)((int)param_1 + 0x95) = 0;
        goto LAB_005d6f1a;
      }
      (**(code **)(*param_1 + 0x4c))(&local_30,1);
      cVar4 = '\x01';
    }
    else {
      if ((bVar7) &&
         ((*(char *)(iVar5 + 0x50) != '\0' ||
          ((*(char *)(iVar5 + 0x53) != '\0' && (*(float *)(iVar5 + 0x4c) != g_flZero))))))
      goto LAB_005d6f1a;
      (**(code **)(*param_1 + 0x4c))(iVar5 + 0x20,1);
      FUN_005d6de0(0,*(undefined4 *)(iVar5 + 0x58),0x40a00000);
      cVar4 = '\x01';
    }
  }
  else {
    cVar4 = (**(code **)(*param_1 + 0x54))();
    if (cVar4 == '\0') goto LAB_005d6f1a;
  }
  if (!bVar7) {
    iVar5 = param_1[9] / 2 + param_1[9];
    param_1[10] = iVar5;
    param_1[2] = iVar5;
  }
LAB_005d6f1a:
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_1c;
  return cVar4;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
