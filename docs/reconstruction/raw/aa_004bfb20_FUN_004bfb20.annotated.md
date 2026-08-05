# Annotated low-level: FUN_004bfb20

| Field | Value |
|---|---|
| Stable ID | `aa_004bfb20` |
| VA | `0x004bfb20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bfb20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_004bfb20(int param_1,int param_2)

{
  if (param_2 == 9) {
    return *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x60) + *(int *)(param_1 + 0x54) +
           *(int *)(param_1 + 0x48) + *(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x30) +
           *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0xc);
  }
  return *(int *)(param_1 + (param_2 * 3 + 3) * 4);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
