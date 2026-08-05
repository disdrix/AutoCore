# Annotated low-level: FUN_0044cff0

| Field | Value |
|---|---|
| Stable ID | `aa_0044cff0` |
| VA | `0x0044cff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0044cff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0044cff0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = param_1;
  if (param_1 != param_2) {
    while (iVar2 = iVar1, iVar1 = iVar2 + 8, iVar1 != param_2) {
      iVar4 = FUN_00746810();
      iVar5 = FUN_00746810();
      iVar3 = iVar1;
      if (iVar4 < iVar5) {
        if ((param_1 != iVar1) && (iVar1 != iVar2 + 0x10)) {
          FUN_0044d320(param_1,iVar1,iVar2 + 0x10);
        }
      }
      else {
        do {
          iVar6 = iVar3;
          iVar4 = FUN_00746810();
          iVar5 = FUN_00746810();
          iVar3 = iVar6 + -8;
        } while (iVar5 < iVar4);
        if ((iVar6 != iVar1) && (iVar1 != iVar2 + 0x10)) {
          FUN_0044d320(iVar6,iVar1,iVar2 + 0x10);
        }
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
