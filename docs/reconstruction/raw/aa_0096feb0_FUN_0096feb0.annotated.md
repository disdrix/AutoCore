# Annotated low-level: FUN_0096feb0

| Field | Value |
|---|---|
| Stable ID | `aa_0096feb0` |
| VA | `0x0096feb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0096feb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0096feb0(int param_1)

{
  int iVar1;
  char cVar2;
  int *in_EAX;
  int iVar3;
  int unaff_EDI;
  
  cVar2 = FUN_0096fdf0();
  iVar1 = *in_EAX;
  if (param_1 < 0) {
    if ((cVar2 != '\0') && (iVar1 != 0)) {
      iVar3 = *(int *)(iVar1 + 0x18);
      if (*(int *)(iVar1 + 0x18) == 0) {
        iVar3 = iVar1;
      }
      if (iVar3 != iVar1) {
        FUN_00448fc0(iVar3);
      }
    }
    return 0xffffffff;
  }
  if (0xf < *(uint *)(unaff_EDI + 0x18)) {
    FUN_00752800(param_1);
    return 0;
  }
  FUN_00752800(param_1);
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
