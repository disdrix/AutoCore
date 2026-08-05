# Annotated low-level: CVOGObjectiveRequirement_UseItem_SlotAction

| Field | Value |
|---|---|
| Stable ID | `aa_0060d060` |
| VA | `0x0060d060` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0060d060`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall
CVOGObjectiveRequirement_UseItem_SlotAction
          (int param_1,undefined4 param_2,int param_3,char *param_4,size_t param_5)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  char local_200 [512];
  
  FUN_007a69d0();
  uVar5 = *(undefined4 *)(param_1 + 0x50);
  iVar4 = (int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);
  uVar2 = FUN_007a6de0(*(undefined4 *)(param_1 + 0x20),0xffffffff);
  sprintf(local_200,"%s: %i / %i",uVar2,iVar4,uVar5);
  strncat(param_4,local_200,param_5);
  pcVar3 = local_200;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return (int)pcVar3 - (int)(local_200 + 1);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
