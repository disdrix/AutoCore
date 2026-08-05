# Annotated low-level: CVOGObjectiveRequirement_UseItem_OnComplete

| Field | Value |
|---|---|
| Stable ID | `aa_0060cfd0` |
| VA | `0x0060cfd0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0060cfd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void CVOGObjectiveRequirement_UseItem_OnComplete(void)

{
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
