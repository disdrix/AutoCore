# Annotated low-level: FUN_0065cfe0

| Field | Value |
|---|---|
| Stable ID | `aa_0065cfe0` |
| VA | `0x0065cfe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0065cfe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0065cfe0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  *param_1 = &PTR_FUN_009e7068;
  if (0 < (int)param_1[4]) {
    iVar1 = 0;
    do {
      (*(code *)**(undefined4 **)(param_1[3] + iVar1))(0);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x1c;
    } while (iVar2 < (int)param_1[4]);
  }
  if (-1 < (int)param_1[5]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[3],(param_1[5] & 0x7fffffff) * 0x1c,0x12);
  }
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
