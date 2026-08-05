# Annotated low-level: FUN_006ede50

| Field | Value |
|---|---|
| Stable ID | `aa_006ede50` |
| VA | `0x006ede50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ede50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_006ede50(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined8 uVar1;
  undefined4 local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TthkBvAgent";
    uVar1 = rdtsc();
    DAT_00bc5644[1] = (int)uVar1;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_8 = param_2[2];
  local_4 = param_2;
  local_c = param_2[1];
  local_10 = *(undefined4 *)(*param_2 + 0xc);
  (**(code **)(**(int **)(param_1 + 0xc) + 4))(&local_10,param_3,param_4,param_5);
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
