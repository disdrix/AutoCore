# Annotated low-level: CVOGObjectiveRequirement_UseItem_InitActive

| Field | Value |
|---|---|
| Stable ID | `aa_0060d540` |
| VA | `0x0060d540` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0060d540`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall CVOGObjectiveRequirement_UseItem_InitActive(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  
  if (*(char *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) + 0x7e) != '\0') {
    if ((*(int *)(param_1 + 0x18) != -1) && (*(char *)(param_1 + 0x24) != '\0')) {
      uVar4 = 1;
      if (*(char *)(param_1 + 0x25) == '\0') {
        uVar4 = *(undefined4 *)(param_1 + 0x50);
      }
      cVar3 = FUN_005310a0(*(int *)(param_1 + 0x18),uVar4);
      if (cVar3 == '\0') {
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x14c);
        iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);
        FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission: %S(%d)",
                     *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(iVar2 + 0x164 + param_2),
                     *(undefined4 *)(iVar2 + 0x168 + param_2),
                     *(undefined4 *)(*(int *)(param_1 + 4) + 0x10),puVar1 + 1,*puVar1);
      }
    }
    if ((*(int *)(param_1 + 0x2c) != -1) && (*(char *)(param_1 + 0x31) != '\0')) {
      uVar4 = 1;
      if (*(char *)(param_1 + 0x32) == '\0') {
        uVar4 = *(undefined4 *)(param_1 + 0x50);
      }
      cVar3 = FUN_005310a0(*(int *)(param_1 + 0x2c),uVar4);
      if (cVar3 == '\0') {
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x14c);
        iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);
        FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission: %S(%d)",
                     *(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(iVar2 + 0x164 + param_2),
                     *(undefined4 *)(iVar2 + 0x168 + param_2),
                     *(undefined4 *)(*(int *)(param_1 + 4) + 0x10),puVar1 + 1,*puVar1);
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
