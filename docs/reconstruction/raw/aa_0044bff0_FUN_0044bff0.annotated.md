# Annotated low-level: FUN_0044bff0

| Field | Value |
|---|---|
| Stable ID | `aa_0044bff0` |
| VA | `0x0044bff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0044bff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0044bff0(void)

{
  undefined4 *in_EAX;
  
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = DAT_00d21908;
    DAT_00d21908 = in_EAX;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
