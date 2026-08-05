# Annotated low-level: FUN_005c5cd0

| Field | Value |
|---|---|
| Stable ID | `aa_005c5cd0` |
| VA | `0x005c5cd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005c5cd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005c5cd0(int param_1,undefined4 *param_2,float *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  cVar1 = *(char *)((int)puVar4 + 0x15);
  puVar2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    if (*param_3 < (float)puVar4[3] || *param_3 == (float)puVar4[3]) {
      puVar3 = (undefined4 *)*puVar4;
    }
    else {
      puVar3 = (undefined4 *)puVar4[2];
      puVar4 = puVar2;
    }
    puVar2 = puVar4;
    puVar4 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x15);
  }
  if ((puVar2 != *(undefined4 **)(param_1 + 4)) &&
     ((float)puVar2[3] < *param_3 || (float)puVar2[3] == *param_3)) {
    *param_2 = puVar2;
    return;
  }
  *param_2 = *(undefined4 **)(param_1 + 4);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
