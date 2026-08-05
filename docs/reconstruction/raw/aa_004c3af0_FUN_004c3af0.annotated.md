# Annotated low-level: FUN_004c3af0

| Field | Value |
|---|---|
| Stable ID | `aa_004c3af0` |
| VA | `0x004c3af0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c3af0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_004c3af0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + -0x2b0);
  if (iVar1 != 0) {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 600))
              (param_2,param_3,param_4,param_5);
  }
  FUN_005139f0(param_2,param_3,param_4,param_5);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
