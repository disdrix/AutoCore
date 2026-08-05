# Annotated low-level: FUN_0055ead0

| Field | Value |
|---|---|
| Stable ID | `aa_0055ead0` |
| VA | `0x0055ead0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0055ead0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0055ead0(int param_1,int param_2)

{
  if (*(uint *)(param_1 + 0x10c) == (*(uint *)(param_1 + 0x110) & 0x7fffffff)) {
    FUN_005b3370((int *)(param_1 + 0x108),4);
  }
  *(int *)(*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x10c) * 4) = param_2;
  *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + 1;
  *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
