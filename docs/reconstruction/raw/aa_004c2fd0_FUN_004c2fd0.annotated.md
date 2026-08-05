# Annotated low-level: FUN_004c2fd0

| Field | Value |
|---|---|
| Stable ID | `aa_004c2fd0` |
| VA | `0x004c2fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c2fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004c2fd0(int param_1,short param_2)

{
  if (*(short *)(param_1 + 0x12e) < param_2) {
    param_2 = *(short *)(param_1 + 0x12e);
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_2 != *(short *)(param_1 + 300)) {
    *(short *)(param_1 + 300) = param_2;
    FUN_00512150(3,(float)(int)param_2,0,0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
