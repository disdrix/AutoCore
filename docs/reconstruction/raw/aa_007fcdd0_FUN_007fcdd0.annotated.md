# Annotated low-level: FUN_007fcdd0

| Field | Value |
|---|---|
| Stable ID | `aa_007fcdd0` |
| VA | `0x007fcdd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fcdd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007fcdd0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x3c08);
  iVar2 = FUN_00418700(iVar1,*(undefined4 *)(iVar1 + 4),&stack0x00000008);
  FUN_00418790();
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
