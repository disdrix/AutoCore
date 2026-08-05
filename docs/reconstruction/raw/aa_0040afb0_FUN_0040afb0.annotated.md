# Annotated low-level: FUN_0040afb0

| Field | Value |
|---|---|
| Stable ID | `aa_0040afb0` |
| VA | `0x0040afb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040afb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0040afb0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x34)) {
    piVar2 = *(int **)(param_1 + 0x30);
    do {
      if (*piVar2 == param_3) {
        *param_2 = (*(int **)(param_1 + 0x30))[iVar1 * 2 + 1];
        return;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar1 < *(int *)(param_1 + 0x34));
  }
  *param_2 = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
