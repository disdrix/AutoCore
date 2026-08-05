# Annotated low-level: FUN_005beae0

| Field | Value |
|---|---|
| Stable ID | `aa_005beae0` |
| VA | `0x005beae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005beae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_005beae0(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int local_60;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = *(int *)(param_1 + 0xd0) * -0x10;
  uVar5 = param_3 + iVar1;
  param_5 = param_5 + iVar1;
  iVar1 = *(int *)(param_1 + 0xd4) * -0x10;
  uVar2 = param_6 + iVar1;
  param_4 = param_4 + iVar1;
  uVar2 = ((int)uVar2 < 1) - 1 & uVar2;
  if (0xe < param_4) {
    param_4 = 0xf;
  }
  uVar5 = ((int)uVar5 < 1) - 1 & uVar5;
  if (0xe < param_5) {
    param_5 = 0xf;
  }
  if ((int)uVar5 <= param_5) {
    puVar3 = (undefined4 *)((uVar5 * 0x10 + uVar2) * 0x180 + 0xe0 + param_1);
    local_60 = (param_5 - uVar5) + 1;
    do {
      if ((int)uVar2 <= param_4) {
        iVar1 = (param_4 - uVar2) + 1;
        puVar4 = puVar3;
        do {
          local_14 = puVar4[-2];
          local_10 = puVar4[-1];
          local_c = *puVar4;
          FUN_004b0b40(&local_14);
          local_14 = puVar4[0xe];
          local_10 = puVar4[0xf];
          local_c = puVar4[0x10];
          FUN_004b0b40(&local_14);
          local_14 = puVar4[0x1e];
          local_10 = puVar4[0x1f];
          local_c = puVar4[0x20];
          FUN_004b0b40(&local_14);
          local_14 = puVar4[0x2e];
          local_10 = puVar4[0x2f];
          local_c = puVar4[0x30];
          FUN_004b0b40(&local_14);
          local_14 = puVar4[0x3e];
          local_10 = puVar4[0x3f];
          local_c = puVar4[0x40];
          FUN_004b0b40(&local_14);
          local_14 = puVar4[0x4e];
          local_10 = puVar4[0x4f];
          local_c = puVar4[0x50];
          FUN_004b0b40(&local_14);
          puVar4 = puVar4 + 0x60;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      puVar3 = puVar3 + 0x600;
      local_60 = local_60 + -1;
    } while (local_60 != 0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
