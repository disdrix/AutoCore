# Annotated low-level: FUN_005bfa90

| Field | Value |
|---|---|
| Stable ID | `aa_005bfa90` |
| VA | `0x005bfa90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005bfa90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_005bfa90(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  (**(code **)(*param_1 + 0x20))(*(undefined4 *)(*param_2 + 0x390));
  param_1[0x2f] = param_1[0x2f] & 0xfffffffe;
  fStack_10 = (float)param_1[0x33] * (float)param_2[0x10];
  fStack_c = (float)*(ushort *)((int)param_1 + 0xea) * (float)param_2[0x11];
  fStack_8 = (float)param_1[0x34] * (float)param_2[0x10];
  if ((*(byte *)(param_1 + 0x2f) & 1) != 0) {
    (**(code **)(*param_1 + 0x5c))();
  }
  FUN_0074b8f0(&fStack_10,&stack0xffffffe4);
  iVar1 = (**(code **)(**(int **)(*param_2 + 0x390) + 0xc))();
  param_1[0x19] = iVar1;
  iVar1 = *param_1;
  uVar2 = (**(code **)(**(int **)(*param_2 + 0x390) + 100))();
  (**(code **)(iVar1 + 0x34))(uVar2);
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
