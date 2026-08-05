# Annotated low-level: FUN_008ccfb0

| Field | Value |
|---|---|
| Stable ID | `aa_008ccfb0` |
| VA | `0x008ccfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008ccfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008ccfb0(undefined4 param_1)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x578) = param_1;
  FUN_007fdfb0(&DAT_00d1a840,
               "Deleting your character is permanent. Are you sure you want to delete this character?  If so, type DELETE into the box below."
               ,0x4e23,1,1);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
