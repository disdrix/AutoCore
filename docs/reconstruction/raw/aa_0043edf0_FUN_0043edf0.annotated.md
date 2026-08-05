# Annotated low-level: FUN_0043edf0

| Field | Value |
|---|---|
| Stable ID | `aa_0043edf0` |
| VA | `0x0043edf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0043edf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0043edf0(void)

{
  int in_EAX;
  
  FUN_00436030();
  FUN_00436030();
  FUN_00436030();
  FUN_00436030();
  return *(undefined4 *)(in_EAX + 4);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
