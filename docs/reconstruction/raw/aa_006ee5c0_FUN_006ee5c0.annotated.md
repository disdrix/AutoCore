# Annotated low-level: FUN_006ee5c0

| Field | Value |
|---|---|
| Stable ID | `aa_006ee5c0` |
| VA | `0x006ee5c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ee5c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006ee5c0(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  local_8 = param_1[2];
  local_4 = param_1;
  piVar1 = *(int **)(*param_1 + 0xc);
  local_c = param_1[1];
  local_10 = piVar1;
  iVar2 = (**(code **)(*(int *)*param_2 + 0x14))();
  iVar3 = (**(code **)(*piVar1 + 0x14))();
  (**(code **)(*param_3 + 0x118c + (iVar3 * 0x20 + iVar2) * 4))(&local_10,param_2,param_3,param_4);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
