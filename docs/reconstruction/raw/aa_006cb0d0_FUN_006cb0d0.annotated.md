# Annotated low-level: FUN_006cb0d0

| Field | Value |
|---|---|
| Stable ID | `aa_006cb0d0` |
| VA | `0x006cb0d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006cb0d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_006cb0d0(int param_1,undefined4 *param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  int local_424;
  int local_420;
  int local_418;
  int local_414;
  int local_40c;
  undefined1 local_400 [1024];
  
  iVar7 = 0;
  *(undefined1 *)(param_1 + 0x4d8c) = 1;
  if (0 < *(int *)(param_1 + 0x4d94)) {
    do {
      iVar6 = *(int *)(*(int *)(param_1 + 0x4d90) + 4 + iVar7 * 8);
      piVar1 = (int *)(*(int *)(param_1 + 0x4d90) + iVar7 * 8);
      if (iVar6 == param_3) {
LAB_006cb125:
        iVar12 = *piVar1;
        iVar6 = param_4;
LAB_006cb15e:
        FUN_006cb0d0(param_2,iVar12,iVar6,param_5,param_6,param_7 + 1);
      }
      else if (iVar6 == param_4) {
        if (iVar6 == param_3) goto LAB_006cb125;
        iVar6 = *piVar1;
        iVar12 = param_3;
        goto LAB_006cb15e;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x4d94));
  }
  local_40c = param_4 + 1;
  local_424 = param_4;
  local_418 = param_3 + 1;
  iVar7 = param_3;
  if (param_3 == -1) {
    param_7 = param_7 + 1;
    iVar7 = 1;
    local_418 = 0x20;
  }
  local_420 = param_7;
  if (param_4 == -1) {
    local_420 = param_7 + 1;
    local_424 = 1;
    local_40c = 0x20;
  }
  if (iVar7 < local_418) {
    iVar6 = iVar7 * 0x20 + local_424;
    pcVar9 = (char *)(iVar6 * 3 + 0x418d + param_1);
    puVar10 = (undefined4 *)(param_1 + 0x118c + iVar6 * 4);
    local_418 = local_418 - iVar7;
    do {
      if (local_424 < local_40c) {
        local_414 = local_40c - local_424;
        pcVar8 = pcVar9;
        puVar11 = puVar10;
        do {
          puVar11[-0x400] = *param_2;
          *puVar11 = param_2[1];
          puVar11[0x400] = param_2[2];
          puVar11[0x800] = param_2[3];
          if ((*(char *)(param_1 + 0x4d8d) != '\0') && (pcVar8[1] < local_420)) {
            uVar2 = FUN_006eee60((int)pcVar8[-1]);
            uVar3 = FUN_006eee60((int)*pcVar8);
            uVar4 = FUN_006eee60(param_3);
            uVar5 = FUN_006eee60(param_4);
            FUN_00637f30(local_400,1000,
                         "Agent handling types <%s-%s> would override more specialized agent <%s-%s>\nMaybe the order of registering your collision agent is wrong, make sure you register your alternate type agents first"
                         ,uVar4,uVar5,uVar2,uVar3);
          }
          *pcVar8 = (char)param_6;
          pcVar8[1] = (char)local_420;
          pcVar8[-1] = (char)param_5;
          puVar11 = puVar11 + 1;
          pcVar8 = pcVar8 + 3;
          local_414 = local_414 + -1;
        } while (local_414 != 0);
      }
      puVar10 = puVar10 + 0x20;
      pcVar9 = pcVar9 + 0x60;
      local_418 = local_418 + -1;
    } while (local_418 != 0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
