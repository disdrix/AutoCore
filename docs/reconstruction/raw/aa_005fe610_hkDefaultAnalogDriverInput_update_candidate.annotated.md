# Annotated low-level: hkDefaultAnalogDriverInput_update_candidate

| Field | Value |
|---|---|
| Stable ID | `aa_005fe610` |
| VA | `0x005fe610` |
| System | input-drive-control |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fe610`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined * hkDefaultAnalogDriverInput_update_candidate(void)

{
  return &DAT_00d02878;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
