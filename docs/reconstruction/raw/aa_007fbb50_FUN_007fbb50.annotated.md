# Annotated low-level: FUN_007fbb50

| Field | Value |
|---|---|
| Stable ID | `aa_007fbb50` |
| VA | `0x007fbb50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fbb50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fbb50(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x30b8) = 1;
  *(undefined1 *)(in_EAX + 0x30b9) = 0;
  if (*(int **)(in_EAX + 0x30a4) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x30a4) + 4))(0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
