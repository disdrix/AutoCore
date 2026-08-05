# Annotated low-level: CVOGSectorMap_AddCharacter

| Field | Value |
|---|---|
| Stable ID | `aa_004d35c0` |
| VA | `0x004d35c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d35c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGSectorMap_AddCharacter: push character into sector list; maybe DoCreatorLoadTrigger once;
   always DoPlayerOnLoadTrigger. Invoked from character create path (FUN_00521310 /
   CreateFromPacket). */

void __thiscall CVOGSectorMap_AddCharacter(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  bool bVar4;
  
  uVar3 = param_2;
  iVar1 = *(int *)(param_1 + 0xe75c);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(param_1 + 0xe764) - iVar1 >> 2) <=
      (uint)(*(int *)(param_1 + 0xe760) - iVar1 >> 2))) {
    FUN_004e39d0(*(undefined4 *)(param_1 + 0xe760),1,&param_2);
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 0xe760);
    *puVar2 = param_2;
    *(undefined4 **)(param_1 + 0xe760) = puVar2 + 1;
  }
  iVar1 = *(int *)(param_1 + 0xe75c);
  if (*(char *)(param_1 + 0xf6) == '\0') {
    if (iVar1 == 0) goto LAB_004d365d;
    bVar4 = *(int *)(param_1 + 0xe760) - iVar1 >> 2 == 1;
  }
  else if (iVar1 == 0) {
    bVar4 = *(int *)(*(int *)(param_1 + 0xe5d0) + 0xc) == 0;
  }
  else {
    bVar4 = *(int *)(param_1 + 0xe760) - iVar1 >> 2 == *(int *)(*(int *)(param_1 + 0xe5d0) + 0xc);
  }
  if (bVar4) {
    CVOGSectorMap_DoCreatorLoadTrigger(uVar3);
  }
LAB_004d365d:
  CVOGSectorMap_DoPlayerOnLoadTrigger(uVar3);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
