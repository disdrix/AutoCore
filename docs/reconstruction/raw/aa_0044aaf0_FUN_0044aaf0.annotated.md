# Annotated low-level: FUN_0044aaf0

| Field | Value |
|---|---|
| Stable ID | `aa_0044aaf0` |
| VA | `0x0044aaf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0044aaf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0044aaf0(void)

{
  int *piVar1;
  int *piVar2;
  void *pvVar3;
  int *piVar4;
  int *unaff_EDI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009befeb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar3 = operator_new(0x14);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_004371c0(pvVar3);
  }
  local_4 = 0xffffffff;
  if ((piVar4 != (int *)0x0) && (piVar4[1] = piVar4[1] + 1, piVar4[1] == 1)) {
    (**(code **)(*piVar4 + 4))();
  }
  piVar2 = (int *)*unaff_EDI;
  if (piVar2 != (int *)0x0) {
    piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*piVar2 + 8))();
    }
  }
  *unaff_EDI = (int)piVar4;
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
