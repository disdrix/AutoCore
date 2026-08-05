# Annotated low-level: FUN_005ee4e0

| Field | Value |
|---|---|
| Stable ID | `aa_005ee4e0` |
| VA | `0x005ee4e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ee4e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005ee4e0(int *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *param_3;
  FUN_005ee030(iVar1 + *param_1 * 0xc,iVar1 + param_1[1] * 0xc,iVar1 + param_1[2] * 0xc);
  *param_2 = local_10;
  param_2[1] = local_c;
  param_2[2] = local_8;
  param_2[3] = local_4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
