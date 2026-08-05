# Annotated low-level: FUN_004a8fb0

| Field | Value |
|---|---|
| Stable ID | `aa_004a8fb0` |
| VA | `0x004a8fb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004a8fb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 __fastcall FUN_004a8fb0(int param_1)

{
  float10 fVar1;
  
  if (*(int *)(param_1 + 0x3d8) != 0) {
    fVar1 = (float10)FUN_005a58c0();
    return fVar1;
  }
  return (float10)g_flZero;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
