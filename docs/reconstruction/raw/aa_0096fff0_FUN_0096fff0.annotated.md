# Annotated low-level: FUN_0096fff0

| Field | Value |
|---|---|
| Stable ID | `aa_0096fff0` |
| VA | `0x0096fff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0096fff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int FUN_0096fff0(int *param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  undefined4 *in_EAX;
  int iVar3;
  int iVar4;
  
  cVar2 = FUN_0096fdf0();
  iVar3 = FUN_00753160(param_2,*in_EAX,in_EAX[1],in_EAX[2],in_EAX[3]);
  if (((iVar3 == -1) && (cVar2 != '\0')) && (iVar1 = *param_1, iVar1 != 0)) {
    iVar4 = *(int *)(iVar1 + 0x18);
    if (*(int *)(iVar1 + 0x18) == 0) {
      iVar4 = iVar1;
    }
    if (iVar4 != iVar1) {
      FUN_00448fc0(iVar4);
    }
  }
  return iVar3;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
