# Annotated low-level: FUN_006f1dd0

| Field | Value |
|---|---|
| Stable ID | `aa_006f1dd0` |
| VA | `0x006f1dd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006f1dd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006f1dd0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_3 + 0x34) = *(undefined4 *)(param_2 + 0x34);
  uVar1 = *(uint *)(param_3 + 0x38);
  uVar2 = (uVar1 - *(int *)(param_2 + 0x34)) + *(int *)(param_1 + 0x24);
  if (((0x1f < uVar2) && ((2 < uVar1 || (0xff < uVar2)))) &&
     (((uVar1 < 0x20 && (0x1f < *(uint *)(param_2 + 0x38))) ||
      (((uVar1 < 0x100 && (0xff < *(uint *)(param_2 + 0x38))) ||
       ((uVar1 < 0x10000 && (0xffff < *(uint *)(param_2 + 0x38))))))))) {
    *(int *)(param_3 + 0x34) = *(int *)(param_1 + 0x24);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
