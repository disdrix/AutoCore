# Annotated low-level: FUN_004cd7f0

| Field | Value |
|---|---|
| Stable ID | `aa_004cd7f0` |
| VA | `0x004cd7f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cd7f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004cd7f0(int *param_1,float param_2)

{
  if ((param_1[0x393e] != 0) && (param_2 != *(float *)(param_1[0x393e] + 0x18))) {
    (**(code **)(*param_1 + 0xc))();
    FUN_004a82d0(param_2);
    (**(code **)(*param_1 + 8))();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
