# Annotated low-level: FUN_007a4ee0

| Field | Value |
|---|---|
| Stable ID | `aa_007a4ee0` |
| VA | `0x007a4ee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007a4ee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int FUN_007a4ee0(int param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  if (*(int *)(in_EAX + 8) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_EAX + 0xc) - *(int *)(in_EAX + 8) >> 2;
  }
  uVar3 = 0;
  if (uVar2 != 0) {
    piVar4 = *(int **)(in_EAX + 8);
    do {
      iVar1 = *piVar4;
      if (((iVar1 != 0) && (*(int *)(iVar1 + 0x200) == param_1)) &&
         (*(int *)(iVar1 + 0x204) == param_2)) {
        return (*(int **)(in_EAX + 8))[uVar3];
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < uVar2);
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
