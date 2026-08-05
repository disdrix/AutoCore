# Annotated low-level: FUN_005ee8e0

| Field | Value |
|---|---|
| Stable ID | `aa_005ee8e0` |
| VA | `0x005ee8e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ee8e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_005ee8e0(float param_1,int param_2)

{
  *(float *)(param_2 + 4) = param_1 * *(float *)(param_2 + 4);
  *(float *)(param_2 + 0x20) = param_1 * *(float *)(param_2 + 0x20);
  *(float *)(param_2 + 0x30) = param_1 * *(float *)(param_2 + 0x30);
  *(float *)(param_2 + 0x40) = param_1 * *(float *)(param_2 + 0x40);
  *(float *)(param_2 + 0x24) = param_1 * *(float *)(param_2 + 0x24);
  *(float *)(param_2 + 0x34) = param_1 * *(float *)(param_2 + 0x34);
  *(float *)(param_2 + 0x44) = param_1 * *(float *)(param_2 + 0x44);
  *(float *)(param_2 + 0x28) = param_1 * *(float *)(param_2 + 0x28);
  *(float *)(param_2 + 0x38) = param_1 * *(float *)(param_2 + 0x38);
  *(float *)(param_2 + 0x48) = param_1 * *(float *)(param_2 + 0x48);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
