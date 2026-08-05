# Annotated low-level: FUN_005ebf00

| Field | Value |
|---|---|
| Stable ID | `aa_005ebf00` |
| VA | `0x005ebf00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ebf00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005ebf00(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x31];
  *param_1 = &PTR_FUN_009dce90;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    (**(code **)(**(int **)(param_1[0x30] + iVar1 * 8) + 0x14))();
  }
  param_1[0x31] = 0;
  if (-1 < (int)param_1[0x32]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x30],param_1[0x32] * 8,0x12);
  }
  FUN_006343d0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
