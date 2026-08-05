# Annotated low-level: FUN_0042bdd0

| Field | Value |
|---|---|
| Stable ID | `aa_0042bdd0` |
| VA | `0x0042bdd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042bdd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0042bdd0(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  
  FUN_00784d20(param_2,in_EAX + 0x138,*(int *)(in_EAX + 0x18) + 7U >> 3);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
