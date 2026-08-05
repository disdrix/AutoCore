# Annotated low-level: FUN_0078edf0

| Field | Value |
|---|---|
| Stable ID | `aa_0078edf0` |
| VA | `0x0078edf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0078edf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0078edf0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_8 [8];
  
  iVar2 = 1;
  iVar1 = 1;
  (**(code **)(*param_1 + 0x120))(local_8,1,1);
  if (*(char *)((int)param_1 + 0x4fd) == '\0') {
    iVar1 = (*(int *)(DAT_00d17948 + 0x10) - iVar2) - param_1[0x143];
    iVar2 = param_1[0x145] - param_1[0x143];
  }
  else {
    iVar1 = (*(int *)(DAT_00d17948 + 0xc) - iVar1) - param_1[0x142];
    iVar2 = param_1[0x144] - param_1[0x142];
  }
  (**(code **)(*param_1 + 0x454))((float)iVar1 / (float)iVar2,1);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
