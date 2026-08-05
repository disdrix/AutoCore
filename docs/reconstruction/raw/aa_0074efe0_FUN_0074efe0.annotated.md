# Annotated low-level: FUN_0074efe0

| Field | Value |
|---|---|
| Stable ID | `aa_0074efe0` |
| VA | `0x0074efe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0074efe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0074efe0(int param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_ESI;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    if (in_EAX == 0) {
      in_EAX = (**(code **)(**(int **)(param_1 + 0xc) + 0xec))(*(int **)(param_1 + 0xc));
    }
    uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x38))(*(int **)(param_1 + 0xc),in_EAX,param_2)
    ;
    iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x4c))
                      (*(int **)(param_1 + 0xc),uVar1,unaff_ESI);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x54))
                        (*(int **)(param_1 + 0xc),iVar2,param_2,0xffffffff);
      if (-1 < iVar2) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
