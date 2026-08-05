# Annotated low-level: FUN_007aac60

| Field | Value |
|---|---|
| Stable ID | `aa_007aac60` |
| VA | `0x007aac60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007aac60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007aac60(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = &DAT_00d1e7e0;
  do {
    piVar2 = (int *)*piVar3;
    if (piVar2 != (int *)0x0) {
      piVar1 = piVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar2 + 8))();
      }
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0xd1e818);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
