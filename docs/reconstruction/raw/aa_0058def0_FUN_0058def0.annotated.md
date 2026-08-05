# Annotated low-level: FUN_0058def0

| Field | Value |
|---|---|
| Stable ID | `aa_0058def0` |
| VA | `0x0058def0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0058def0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0058def0(int param_1,undefined4 *param_2,float *param_3)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar4 = true;
  cVar2 = *(char *)((int)puVar7 + 0x29);
  puVar5 = *(undefined4 **)(param_1 + 4);
  while (cVar2 == '\0') {
    fVar1 = (float)puVar7[4];
    if (fVar1 < *param_3 || fVar1 == *param_3) {
      puVar6 = (undefined4 *)puVar7[2];
    }
    else {
      puVar6 = (undefined4 *)*puVar7;
    }
    bVar4 = fVar1 >= *param_3 && fVar1 != *param_3;
    puVar5 = puVar7;
    puVar7 = puVar6;
    cVar2 = *(char *)((int)puVar6 + 0x29);
  }
  puVar7 = (undefined4 *)FUN_0058da40(&param_3,bVar4,puVar5,param_3);
  uVar3 = *puVar7;
  *(undefined1 *)(param_2 + 1) = 1;
  *param_2 = uVar3;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
