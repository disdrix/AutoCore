# Annotated low-level: CVOGReaction_UpdateRepairStationPosition

| Field | Value |
|---|---|
| Stable ID | `aa_004d38b0` |
| VA | `0x004d38b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d38b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGReaction_UpdateRepairStationPosition — per-map player TFID -> station key map.
   
   this = large map/world object (+0xe740 set/map of repair station entries).
   param2 = player TFID (2 dwords).
   param3 = station key (GenericVar1).
   
   Inserts or updates station key for player; returns 1 if changed/inserted, 0 if unchanged. */

undefined4 __thiscall
CVOGReaction_UpdateRepairStationPosition(int param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  int local_18 [2];
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar2 = param_2;
  param_2 = (uint *)FUN_004e2320(param_2);
  if (param_2 != (uint *)*(int *)(param_1 + 0xe740)) {
    if ((*(int *)((int)param_2 + 0x14) <= (int)puVar2[1]) &&
       ((*(int *)((int)param_2 + 0x14) < (int)puVar2[1] ||
        (*(uint *)((int)param_2 + 0x10) <= *puVar2)))) {
      piVar3 = (int *)&param_2;
      goto LAB_004d38f4;
    }
  }
  local_18[0] = *(int *)(param_1 + 0xe740);
  piVar3 = local_18;
LAB_004d38f4:
  iVar1 = *piVar3;
  if (iVar1 == *(int *)(param_1 + 0xe740)) {
    local_10 = *puVar2;
    local_c = puVar2[1];
    local_8 = param_3;
    FUN_004e48b0(local_18,&local_10);
    return 1;
  }
  if (*(int *)(iVar1 + 0x18) != param_3) {
    *(int *)(iVar1 + 0x18) = param_3;
    return 1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
