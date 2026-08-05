# Annotated low-level: FUN_0066bfb0

| Field | Value |
|---|---|
| Stable ID | `aa_0066bfb0` |
| VA | `0x0066bfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0066bfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0066bfb0(int param_1,int param_2)

{
  FUN_00651a40(param_2);
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_1 + 0x3c);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
