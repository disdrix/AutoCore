# Annotated low-level: CVOGObjectiveRequirement_Patrol_GetSomething

| Field | Value |
|---|---|
| Stable ID | `aa_0060e9e0` |
| VA | `0x0060e9e0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0060e9e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall CVOGObjectiveRequirement_Patrol_GetSomething(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
