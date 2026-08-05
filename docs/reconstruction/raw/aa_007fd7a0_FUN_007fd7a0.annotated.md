# Annotated low-level: FUN_007fd7a0

| Field | Value |
|---|---|
| Stable ID | `aa_007fd7a0` |
| VA | `0x007fd7a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fd7a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_007fd7a0(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  
  if ((in_EAX != -1) && (in_EAX != 0)) {
    piVar1 = (int *)CVOGReaction_ResolveObjectTarget(0,in_EAX,in_EAX >> 0x1f);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x1e4))();
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*piVar1 + 0x1e4))();
        if (*(char *)(iVar2 + 0x1d1) == '=') {
          FUN_007fb690(0,(float)*(int *)(iVar2 + 0x25c),0,"Working..",DAT_00afdef4,DAT_00afdef0,0,0)
          ;
          return 1;
        }
      }
    }
    return 0;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
