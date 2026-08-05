# Annotated low-level: FUN_005eaf20

| Field | Value |
|---|---|
| Stable ID | `aa_005eaf20` |
| VA | `0x005eaf20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005eaf20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005eaf20(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_20 [28];
  
  FUN_00567ce0(param_1,param_2);
  FUN_005eadb0(local_20);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
