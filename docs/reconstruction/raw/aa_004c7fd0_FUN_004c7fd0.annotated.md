# Annotated low-level: FUN_004c7fd0

| Field | Value |
|---|---|
| Stable ID | `aa_004c7fd0` |
| VA | `0x004c7fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c7fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004c7fd0(int param_1)

{
  int iVar1;
  char cVar2;
  int local_4;
  
  local_4 = 0;
  cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) + 0x228
                      ))();
  if (cVar2 != '\0') {
    FUN_004e2600(&LAB_00513060,&local_4,0);
  }
  if (((local_4 == 0) && (iVar1 = *(int *)(param_1 + -0x2b0), iVar1 != 0)) &&
     (*(char *)(param_1 + -500) != '\0')) {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x224))();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
