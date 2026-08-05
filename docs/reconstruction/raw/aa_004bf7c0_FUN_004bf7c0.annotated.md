# Annotated low-level: FUN_004bf7c0

| Field | Value |
|---|---|
| Stable ID | `aa_004bf7c0` |
| VA | `0x004bf7c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bf7c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004bf7c0(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[2] == 0) {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(*(int *)(param_1 + 4) + 4);
    }
    else {
      *(undefined4 *)(param_2[2] + 4) = param_2[1];
    }
    if (param_2[1] != 0) {
      *(undefined4 *)(param_2[1] + 8) = param_2[2];
    }
    (**(code **)*param_2)(1);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
