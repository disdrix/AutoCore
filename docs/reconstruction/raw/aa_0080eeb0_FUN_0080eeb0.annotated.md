# Annotated low-level: FUN_0080eeb0

| Field | Value |
|---|---|
| Stable ID | `aa_0080eeb0` |
| VA | `0x0080eeb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0080eeb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0080eeb0(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int unaff_ESI;
  undefined4 *puVar5;
  char local_108 [2];
  undefined4 local_106 [64];
  
  FUN_007a69d0();
  if (*(char *)(unaff_ESI + 4) == '\0') {
    uVar2 = FUN_007a6de0("Character not found!",0xffffffff);
    if (DAT_00d1b8dc != 0) {
      FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar2,0);
    }
  }
  else {
    iVar1 = FUN_00573a90(*(undefined4 *)(unaff_ESI + 8),*(undefined4 *)(unaff_ESI + 0xc));
    if ((iVar1 != 0) && (*(char *)(iVar1 + 0x10) != '\0')) {
      local_108[0] = '\0';
      local_108[1] = '\0';
      puVar5 = local_106;
      for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      *(undefined2 *)puVar5 = 0;
      uVar2 = FUN_007a6de0("has been removed from your ignore list",0xffffffff);
      sprintf(local_108,"%s %s.",(char *)(iVar1 + 0x10),uVar2);
      if (DAT_00d1b8dc != 0) {
        FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_108,0);
      }
    }
    iVar1 = *(int *)(in_EAX + 0xe98);
    iVar4 = *(int *)(*(int *)(iVar1 + 4) + 4);
    FUN_00573ce0(*(undefined4 *)(iVar4 + 0x164 + iVar1),*(undefined4 *)(iVar4 + 0x168 + iVar1),
                 *(undefined4 *)(unaff_ESI + 8),*(undefined4 *)(unaff_ESI + 0xc));
    if (*(int *)(in_EAX + 0x1038) != 0) {
      piVar3 = (int *)__RTDynamicCast(*(int *)(in_EAX + 0x1038),0,&CVOGDialog::RTTI_Type_Descriptor,
                                      &CDlgTabsSocial::RTTI_Type_Descriptor,0);
      (**(code **)(*piVar3 + 0x448))();
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
