# Annotated low-level: CVOGReaction_TeleportTarget

| Field | Value |
|---|---|
| Stable ID | `aa_0053d790` |
| VA | `0x0053d790` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0053d790`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Teleport a target to a new position.
   
   Parameters:
   this - Reaction context (offsets: +0x2=target, +0x1=source)
   pTeleportData - Teleport data array [4] (position xyz + orientation)
   
   Algorithm:
   1. Call vtable +0x40 on this (pre-teleport callback)
   2. If this+0x2 == 0 (no target):
      - Copy pTeleportData to this+0x1+0x84 (4 dwords)
   3. Else if this+0x2 != 0:
      - Check via FUN_005070b0 (validation)
      - If validation passes and +0x44 != 0: call FUN_005070d0
      - If flag +0x40 clear or +0x8 == 0:
        - Call vtable +0x40 on +0x3c with teleport data */

void __thiscall CVOGReaction_TeleportTarget(void *this,undefined4 *pTeleportData)

{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uStack_4;
  
  uStack_4 = this;
  (**(code **)(*(int *)this + 0x40))();
  iVar2 = *(int *)((int)this + 8);
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x84 + (int)this);
    *puVar1 = *pTeleportData;
    puVar1[1] = pTeleportData[1];
    puVar1[2] = pTeleportData[2];
    puVar1[3] = pTeleportData[3];
  }
  else {
    pcVar3 = (char *)FUN_005070b0((int)&uStack_4 + 3);
    if ((*pcVar3 == '\0') && (*(int *)(iVar2 + 0x44) != 0)) {
      FUN_005070d0();
    }
    if ((*(char *)(iVar2 + 0x40) == '\0') || (*(int *)(iVar2 + 8) == 0)) {
      (**(code **)(**(int **)(iVar2 + 0x3c) + 0x40))(pTeleportData);
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
