# Annotated low-level: FUN_007fe8d0

| Field | Value |
|---|---|
| Stable ID | `aa_007fe8d0` |
| VA | `0x007fe8d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fe8d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_007fe8d0(void)

{
  int *piVar1;
  int in_EAX;
  void *pvVar2;
  int iVar3;
  char acStack_98 [128];
  undefined4 uStack_18;
  float fStack_14;
  float fStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(uint *)(in_EAX + 0x3c20) != 0) {
    pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(in_EAX + 0xe98) + 0x548),
                                 *(uint *)(in_EAX + 0x3c20));
    if (pvVar2 != (void *)0x0) {
      if (*(int *)((int)pvVar2 + 0x158) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)((int)pvVar2 + 0x15c) - *(int *)((int)pvVar2 + 0x158) >> 2;
      }
      if (*(int *)(in_EAX + 0x3c24) < iVar3) {
        piVar1 = *(int **)(*(int *)((int)pvVar2 + 0x158) + *(int *)(in_EAX + 0x3c24) * 4);
        iVar3 = (**(code **)(*piVar1 + 0x50))();
        if (iVar3 == 0xc) {
          iVar3 = __RTDynamicCast(piVar1,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,
                                  &CVOGObjectiveRequirement_UseItem::RTTI_Type_Descriptor,0);
          if (iVar3 != 0) {
            uStack_18 = 0xffffffff;
            acStack_98[0] = '\0';
            strncpy(acStack_98,*(char **)(iVar3 + 0x40),0x7f);
            uStack_8 = 0xffffffff;
            uStack_4 = 0xffffffff;
            fStack_14 = g_flLevelUpUiBase_Inferred;
            uStack_c = 2;
            fStack_10 = g_flMultiKillCountBlend;
            uStack_18 = 0xffff0000;
            FUN_0040c5c0(acStack_98);
            FUN_007fb640();
            return 1;
          }
        }
        return 0;
      }
    }
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
