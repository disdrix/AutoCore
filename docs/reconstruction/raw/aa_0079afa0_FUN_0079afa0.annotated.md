# Annotated low-level: FUN_0079afa0

| Field | Value |
|---|---|
| Stable ID | `aa_0079afa0` |
| VA | `0x0079afa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0079afa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_0079afa0(int *param_1)

{
  char cVar1;
  undefined4 unaff_ESI;
  undefined4 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 0xd8))();
  if (cVar1 != '\0') {
    if (*(char *)((int)param_1 + 0xd3) != '\0') {
      uVar2 = 0;
      (**(code **)(*param_1 + 0x3d0))(0);
      (**(code **)(*param_1 + 0x3c8))(*(char *)((int)param_1 + 0x48e) == '\0',1);
      (**(code **)(*param_1 + 0x34c))();
      FUN_007a81e0(uVar2,unaff_ESI);
    }
    return 1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
