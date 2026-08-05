# Annotated low-level: FUN_0088cbd0

| Field | Value |
|---|---|
| Stable ID | `aa_0088cbd0` |
| VA | `0x0088cbd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0088cbd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0088cbd0(undefined4 param_1,undefined4 param_2)

{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x5bc) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x5bc) + 0x1d8))(param_2,1,1);
                    /* WARNING: Could not recover jumptable at 0x0088cbf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(unaff_ESI + 0x5bc) + 0x34c))();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
