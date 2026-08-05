# Annotated low-level: FUN_004cbee0

| Field | Value |
|---|---|
| Stable ID | `aa_004cbee0` |
| VA | `0x004cbee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cbee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004cbee0(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 uVar1;
  bool bVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_4;
  
  puVar3 = param_3;
  puVar5 = *(undefined4 **)(param_1 + 4);
  bVar2 = true;
  local_4 = 1;
  if (*(char *)((int)puVar5[1] + 0x29) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      if (((int)puVar5[5] < (int)param_3[1]) ||
         (((int)puVar5[5] <= (int)param_3[1] && ((uint)puVar5[4] <= *param_3)))) {
        puVar4 = (undefined4 *)puVar5[2];
        bVar2 = false;
        local_4 = 0;
      }
      else {
        puVar4 = (undefined4 *)*puVar5;
        bVar2 = true;
        local_4 = 1;
      }
    } while (*(char *)((int)puVar4 + 0x29) == '\0');
  }
  param_3 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar5 = (undefined4 *)FUN_004cbb60(&param_3,1,puVar5,puVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_2 + 1) = 1;
      *param_2 = uVar1;
      return;
    }
    FUN_004cb4f0();
  }
  if (((int)param_3[5] <= (int)puVar3[1]) &&
     (((int)param_3[5] < (int)puVar3[1] || (param_3[4] < *puVar3)))) {
    puVar5 = (undefined4 *)FUN_004cbb60(&param_3,local_4,puVar5,puVar3);
    *param_2 = *puVar5;
    *(undefined1 *)(param_2 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_2 + 1) = 0;
  *param_2 = param_3;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
