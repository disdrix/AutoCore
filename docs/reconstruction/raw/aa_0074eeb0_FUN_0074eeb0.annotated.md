# Annotated low-level: FUN_0074eeb0

| Field | Value |
|---|---|
| Stable ID | `aa_0074eeb0` |
| VA | `0x0074eeb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0074eeb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0074eeb0(void)

{
  char cVar1;
  char *in_EAX;
  
  for (; ((((cVar1 = *in_EAX, cVar1 == ' ' || (cVar1 == ',')) || (cVar1 == '\n')) || (cVar1 == '\r')
          ) && (cVar1 != '\0')); in_EAX = in_EAX + 1) {
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
