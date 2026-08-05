# Annotated low-level: FUN_004ce8d0

| Field | Value |
|---|---|
| Stable ID | `aa_004ce8d0` |
| VA | `0x004ce8d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ce8d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004ce8d0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 local_4;
  
  local_4 = 0;
  iVar1 = FUN_004bae00(0,&local_4);
  while (iVar1 != 0) {
    if (*(int *)(*(int *)(iVar1 + 0xa8) + 0x38) == 0x38) {
      piVar2 = (int *)__RTDynamicCast(iVar1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                      &CVOGTrigger::RTTI_Type_Descriptor,0);
      (**(code **)(*piVar2 + 0x7c))();
    }
    iVar1 = FUN_004bae00(0,&local_4);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
