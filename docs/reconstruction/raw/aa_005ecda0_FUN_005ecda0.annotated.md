# Annotated low-level: FUN_005ecda0

| Field | Value |
|---|---|
| Stable ID | `aa_005ecda0` |
| VA | `0x005ecda0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ecda0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005ecda0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  float *pfVar2;
  float fVar3;
  undefined1 local_2c [12];
  float local_20;
  float local_1c;
  float local_18;
  float local_10;
  float local_c;
  float local_8;
  
  if (*(int *)(param_1 + 0xc) == 1) {
    return 1;
  }
  if (*(int *)(param_1 + 0xc) != 2) {
    return 5;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  FUN_005ecba0(&local_20,uVar1);
  FUN_005ecba0(&local_10,*(undefined4 *)(param_1 + 0x14));
  pfVar2 = (float *)FUN_005ec550(local_2c,uVar1,param_2);
  fVar3 = local_8 * (pfVar2[1] * local_20 - *pfVar2 * local_1c) +
          local_c * (*pfVar2 * local_18 - pfVar2[2] * local_20) +
          (pfVar2[2] * local_1c - pfVar2[1] * local_18) * local_10;
  if (fVar3 < (float)_DAT_009dcfb0) {
    return 2;
  }
  if (_DAT_009dcfa8 < (double)fVar3) {
    return 3;
  }
  return 4;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
