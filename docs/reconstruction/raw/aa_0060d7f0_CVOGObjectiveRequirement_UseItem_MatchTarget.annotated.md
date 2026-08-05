# Annotated low-level: CVOGObjectiveRequirement_UseItem_MatchTarget

| Field | Value |
|---|---|
| Stable ID | `aa_0060d7f0` |
| VA | `0x0060d7f0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0060d7f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void CVOGObjectiveRequirement_UseItem_MatchTarget(void)

{
  FUN_0060d460();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
