# Annotated low-level: FUN_004f8fe0

| Field | Value |
|---|---|
| Stable ID | `aa_004f8fe0` |
| VA | `0x004f8fe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f8fe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004f8fe0(int param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x210))(0);
    if ((iVar3 == 0) || (*(char *)(param_1 + 0x103) != '\0')) {
      pbVar1 = (byte *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x17d);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  FUN_004f7d60();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
