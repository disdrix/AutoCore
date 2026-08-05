# Annotated low-level: FUN_004c3fb0

| Field | Value |
|---|---|
| Stable ID | `aa_004c3fb0` |
| VA | `0x004c3fb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c3fb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004c3fb0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + -0x2b0);
  if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x004c3fc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x2a0))();
    return;
  }
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + param_1 + -0x418);
  *piVar1 = *piVar1 + param_2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
