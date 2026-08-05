# Annotated low-level: FUN_0040dab0

| Field | Value |
|---|---|
| Stable ID | `aa_0040dab0` |
| VA | `0x0040dab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040dab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int FUN_0040dab0(float param_1)

{
  if (param_1 < 0.0) {
    return (int)(param_1 - g_flMissionXpRoundBias);
  }
  return (int)(param_1 + g_flMissionXpRoundBias);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
