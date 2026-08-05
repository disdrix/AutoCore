# Annotated low-level: FUN_004cd4e0

| Field | Value |
|---|---|
| Stable ID | `aa_004cd4e0` |
| VA | `0x004cd4e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cd4e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_004cd4e0(int *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = __RTDynamicCast(param_1,0,&CVOGHBBase::RTTI_Type_Descriptor,
                          &CVOGHBRecreateObject::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    if (*param_2 != '\0') {
      FUN_005dac00();
    }
    (**(code **)(*param_1 + 0x18))(1,0);
    param_2[1] = '\x01';
    *(undefined1 *)param_1 = 1;
    return 1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
