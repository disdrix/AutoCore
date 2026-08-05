# Annotated low-level: FUN_006bfd90

| Field | Value |
|---|---|
| Stable ID | `aa_006bfd90` |
| VA | `0x006bfd90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bfd90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006bfd90(int param_1,undefined4 *param_2,int param_3,int param_4,int *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  char local_38 [4];
  char local_34 [4];
  undefined1 local_30 [16];
  undefined1 local_20 [28];
  
  param_5[1] = 0;
  if (0 < param_3) {
    do {
      if (param_5[1] == (param_5[2] & 0x7fffffffU)) {
        FUN_005b3370(param_5,0x10);
      }
      puVar5 = (undefined4 *)(param_5[1] * 0x10 + *param_5);
      param_5[1] = param_5[1] + 1;
      uVar1 = *param_2;
      uVar2 = param_2[1];
      uVar3 = param_2[2];
      uVar4 = param_2[3];
      param_2 = param_2 + 4;
      param_3 = param_3 + -1;
      *puVar5 = uVar1;
      puVar5[1] = uVar2;
      puVar5[2] = uVar3;
      puVar5[3] = uVar4;
    } while (param_3 != 0);
  }
  if (1 < param_5[1]) {
    FUN_006bacf0(*param_5,0,param_5[1] + -1,&LAB_006babf0);
  }
  FUN_006bb1c0(param_5,local_20,local_30);
  FUN_006bc200(*(undefined4 *)(param_1 + 4),param_5,local_34);
  local_38[0] = '\x01';
  cVar7 = '\0';
  while ((cVar7 == '\0' || (local_38[0] != '\0'))) {
    local_34[0] = local_38[0] == '\0';
    iVar6 = 0;
    if (0 < param_5[1]) {
      iVar8 = 0;
      do {
        *(undefined4 *)(iVar8 + 0xc + *param_5) = 0;
        iVar6 = iVar6 + 1;
        iVar8 = iVar8 + 0x10;
      } while (iVar6 < param_5[1]);
    }
    *(undefined4 *)(param_4 + 8) = 0;
    FUN_006bf8c0(param_1,param_5,0,param_5[1] + -1,param_4);
    FUN_006bddb0(param_4,param_5);
    FUN_006bc5b0(param_5);
    FUN_006bc990(param_4,0,param_5[1] + -1,param_1,local_38);
    FUN_006bc5b0(param_5);
    cVar7 = local_34[0];
  }
  FUN_006bb3a0(param_5,local_20,local_30);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
