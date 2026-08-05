# Annotated low-level: FUN_006ef5b0

| Field | Value |
|---|---|
| Stable ID | `aa_006ef5b0` |
| VA | `0x006ef5b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ef5b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006ef5b0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_006cde50(param_2);
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    puVar3 = (undefined4 *)(param_1 + 0x18);
    do {
      if (*(uint *)(param_2 + 8) == (*(uint *)(param_2 + 0xc) & 0x7fffffff)) {
        FUN_005b3370((int *)(param_2 + 4),0x10);
      }
      puVar1 = (undefined4 *)(*(int *)(param_2 + 8) * 0x10 + *(int *)(param_2 + 4));
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
      *puVar1 = puVar3[-2];
      puVar1[1] = puVar3[-1];
      puVar1[2] = *puVar3;
      puVar1[3] = puVar3[1];
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 4;
    } while (iVar2 < *(int *)(param_1 + 0xc));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
