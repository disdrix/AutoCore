# Annotated low-level: FUN_006edef0

| Field | Value |
|---|---|
| Stable ID | `aa_006edef0` |
| VA | `0x006edef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006edef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006edef0(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  int *local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TthkBvAgent";
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_8 = param_1[2];
  local_4 = param_1;
  local_10 = *(int **)(*param_1 + 0xc);
  local_c = param_1[1];
  iVar2 = (**(code **)(*local_10 + 0x14))();
  iVar3 = (**(code **)(*(int *)*param_2 + 0x14))();
  (**(code **)(*param_3 + 0x118c + (iVar2 * 0x20 + iVar3) * 4))(&local_10,param_2,param_3,param_4);
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d2878;
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
