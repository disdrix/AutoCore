# Annotated low-level: FUN_0041aef0

| Field | Value |
|---|---|
| Stable ID | `aa_0041aef0` |
| VA | `0x0041aef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0041aef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0041aef0(int param_1)

{
  int iVar1;
  undefined4 in_EAX;
  int local_4;
  
  iVar1 = *(int *)(param_1 + 4);
  local_4 = param_1;
  if ((iVar1 != 0) &&
     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x934) <
      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x934))) {
    iVar1 = *(int *)(param_1 + 8);
    FUN_004220c0(param_1);
    *(int *)(param_1 + 8) = iVar1 + 0x934;
    return;
  }
  FUN_0041c920(&local_4,*(undefined4 *)(param_1 + 8),in_EAX);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
