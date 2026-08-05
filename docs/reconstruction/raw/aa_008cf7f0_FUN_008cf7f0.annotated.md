# Annotated low-level: FUN_008cf7f0

| Field | Value |
|---|---|
| Stable ID | `aa_008cf7f0` |
| VA | `0x008cf7f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cf7f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008cf7f0(undefined4 param_1)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(in_EAX + 0x794);
  iVar3 = 3;
  do {
    cVar1 = (**(code **)(*(int *)*puVar2 + 0xd8))();
    if (cVar1 != (char)param_1) {
      (**(code **)(*(int *)*puVar2 + 0xd4))(param_1);
      (**(code **)(*(int *)*puVar2 + 0x34c))();
    }
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
