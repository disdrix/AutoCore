# Annotated low-level: FUN_0080efe0

| Field | Value |
|---|---|
| Stable ID | `aa_0080efe0` |
| VA | `0x0080efe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0080efe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0080efe0(int param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int in_EAX;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  char local_108 [2];
  undefined4 local_106 [64];
  
  FUN_007a69d0();
  if (*(char *)(in_EAX + 4) == '\0') {
    uVar6 = FUN_007a6de0("Character not found!",0xffffffff);
    if (DAT_00d1b8dc != 0) {
      FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar6,0);
    }
  }
  else {
    puVar4 = operator_new(0x28);
    iVar8 = *(int *)(param_1 + 0xe98);
    iVar3 = *(int *)(*(int *)(iVar8 + 4) + 4);
    *puVar4 = *(undefined4 *)(iVar3 + 0x164 + iVar8);
    puVar4[1] = *(undefined4 *)(iVar3 + 0x168 + iVar8);
    pcVar1 = (char *)(in_EAX + 0x10);
    puVar4[2] = *(undefined4 *)(in_EAX + 8);
    puVar4[3] = *(undefined4 *)(in_EAX + 0xc);
    pcVar7 = pcVar1;
    do {
      cVar2 = *pcVar7;
      pcVar7[(int)puVar4 + (0x10 - (int)pcVar1)] = cVar2;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    FUN_005740f0(puVar4);
    if (*(int *)(param_1 + 0x1038) != 0) {
      piVar5 = (int *)__RTDynamicCast(*(int *)(param_1 + 0x1038),0,&CVOGDialog::RTTI_Type_Descriptor
                                      ,&CDlgTabsSocial::RTTI_Type_Descriptor,0);
      (**(code **)(*piVar5 + 0x448))();
    }
    local_108[0] = '\0';
    local_108[1] = '\0';
    puVar4 = local_106;
    for (iVar8 = 0x3f; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    *(undefined2 *)puVar4 = 0;
    uVar6 = FUN_007a6de0("has been added to your ignore list",0xffffffff);
    sprintf(local_108,"%s %s.",pcVar1,uVar6);
    if (DAT_00d1b8dc != 0) {
      FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_108,0);
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
