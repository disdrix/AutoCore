# Annotated low-level: FUN_005fead0

| Field | Value |
|---|---|
| Stable ID | `aa_005fead0` |
| VA | `0x005fead0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fead0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005fead0(int param_1)

{
  int iVar1;
  
  FUN_005c88b0();
  iVar1 = *(int *)(*(int *)(param_1 + -0xdc) + 4);
  *(undefined4 *)(iVar1 + param_1 + -0x1c) =
       *(undefined4 *)(*(int *)(*(int *)(iVar1 + -0x34 + param_1) + 0x3c) + 0x3e4);
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x34 + param_1) + 0x3c);
  *(undefined4 *)(param_1 + -0x30) = *(undefined4 *)(iVar1 + 0x4c0);
  *(undefined4 *)(param_1 + -0x2c) = *(undefined4 *)(iVar1 + 0x4c4);
  *(undefined4 *)(param_1 + -0x28) = *(undefined4 *)(iVar1 + 0x4c8);
  *(undefined4 *)(param_1 + -0x24) = *(undefined4 *)(iVar1 + 0x4cc);
  *(undefined4 *)(param_1 + -0x20) = *(undefined4 *)(iVar1 + 0x4d0);
  *(undefined2 *)(param_1 + -0x14) =
       *(undefined2 *)
        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x34 + param_1) + 0x3c) +
        0x4d2);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
