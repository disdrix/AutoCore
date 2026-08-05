# Annotated low-level: FUN_007fbb70

| Field | Value |
|---|---|
| Stable ID | `aa_007fbb70` |
| VA | `0x007fbb70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fbb70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007fbb70(undefined4 param_1,int param_2)

{
  int in_EAX;
  
  if (((param_2 == 0) || (*(int *)(in_EAX + 0x309c) == 0)) ||
     (param_2 == *(int *)(*(int *)(in_EAX + 0x309c) + 0x518))) {
    *(undefined1 *)(in_EAX + 0x30b4) = 1;
    *(undefined1 *)(in_EAX + 0x30b5) = 0;
    if (*(int **)(in_EAX + 0x309c) != (int *)0x0) {
      (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
