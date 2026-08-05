# Annotated low-level: FUN_007f9df0

| Field | Value |
|---|---|
| Stable ID | `aa_007f9df0` |
| VA | `0x007f9df0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007f9df0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007f9df0(undefined4 param_1)

{
  int in_EAX;
  int *unaff_EDI;
  undefined4 local_4;
  
  local_4 = param_1;
  if (in_EAX == 0) {
    if (*(char *)((int)unaff_EDI + 0x489) == '\0') {
      (**(code **)(*unaff_EDI + 0x15c))(0,unaff_EDI + 0x139);
      (**(code **)(*unaff_EDI + 0x34c))();
    }
  }
  else if ((in_EAX == 5) && (*(char *)((int)unaff_EDI + 0x489) == '\0')) {
    local_4 = 0xffff0000;
    (**(code **)(*unaff_EDI + 0x15c))(0,&local_4);
    (**(code **)(*unaff_EDI + 0x34c))();
  }
  unaff_EDI[0x13a] = 0;
  unaff_EDI[0x13b] = in_EAX;
  if (unaff_EDI[0x13c] != (&DAT_00afa098)[in_EAX]) {
    FUN_007f9cc0();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
