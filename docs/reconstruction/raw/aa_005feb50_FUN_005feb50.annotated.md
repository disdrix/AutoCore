# Annotated low-level: FUN_005feb50

| Field | Value |
|---|---|
| Stable ID | `aa_005feb50` |
| VA | `0x005feb50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005feb50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005feb50(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_005cb520(param_2,param_3,param_4);
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + -0x30) = *(undefined4 *)(param_2 + 0xd8);
    *(undefined4 *)(param_1 + -0x2c) = *(undefined4 *)(param_2 + 0xdc);
    *(undefined4 *)(param_1 + -0x28) = *(undefined4 *)(param_2 + 0xe0);
    *(undefined4 *)(param_1 + -0x24) = *(undefined4 *)(param_2 + 0xe4);
    *(undefined4 *)(param_1 + -0x20) = *(undefined4 *)(param_2 + 0xe8);
    FUN_00516720(param_2 + 0xf0);
    *(undefined2 *)(param_1 + -0x14) = *(undefined2 *)(param_2 + 0x154);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x1c + param_1) =
         *(undefined4 *)(param_2 + 0xec);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x1c + param_1) =
         *(undefined4 *)(param_2 + 0xec);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
