# Annotated low-level: FUN_0053cfd0

| Field | Value |
|---|---|
| Stable ID | `aa_0053cfd0` |
| VA | `0x0053cfd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0053cfd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0053cfd0(int param_1,FILE *param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if (param_2 == (FILE *)0x0) {
    return 0;
  }
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1) + 0xac))(param_2)
  ;
  pcVar3 = fwrite_exref;
  iVar1 = *(int *)(param_1 + -0x48);
  if (iVar1 == 0) {
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    FUN_00567ce0(&DAT_00af2460,0x38d1b717);
    pcVar3 = fwrite_exref;
    uStack_34 = uStack_24;
    uStack_30 = uStack_20;
    uStack_2c = uStack_1c;
    uStack_28 = uStack_18;
    fwrite(&uStack_44,0x10,1,param_2);
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x3c);
    uStack_44 = *(undefined4 *)(iVar2 + 0xb0);
    uStack_40 = *(undefined4 *)(iVar2 + 0xb4);
    uStack_3c = *(undefined4 *)(iVar2 + 0xb8);
    uStack_38 = *(undefined4 *)(iVar2 + 0xbc);
    iVar1 = *(int *)(iVar1 + 0x3c);
    uStack_34 = *(undefined4 *)(iVar1 + 0x30);
    uStack_30 = *(undefined4 *)(iVar1 + 0x34);
    uStack_2c = *(undefined4 *)(iVar1 + 0x38);
    uStack_28 = *(undefined4 *)(iVar1 + 0x3c);
    fwrite(&uStack_44,0x10,1,param_2);
  }
  (*pcVar3)(&uStack_34,0x10,1,param_2);
  (*pcVar3)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x6c + param_1,4,1,param_2);
  (*pcVar3)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x70 + param_1,4,1,param_2);
  (*pcVar3)(&stack0xffffffbb,1,1,param_2);
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
