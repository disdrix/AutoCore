# Annotated low-level: CVOGReaction_RemoveObject

| Field | Value |
|---|---|
| Stable ID | `aa_004db8b0` |
| VA | `0x004db8b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004db8b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Remove an object from the world.
   
   Parameters:
   this - Reaction context (offsets: +0x7e=dead flag, +0xe4e8=spawn params, +0xe500=notify,
   +0xe5c0=hash)
   uObjectID - Object definition ID
   uInstanceID - Instance/variant ID
   bRemoveType - 0=normal remove, 1=destroy animation
   
   Returns: 1 if removed successfully, 0 if failed
   
   Algorithm:
   1. Resolve target via CVOGReaction_ResolveObjectTarget
   2. If not found: lookup via FUN_004e23d0, clear bit 3 at +0x17d, return 0
   3. If alive (+0x214 != 0) and dead flag +0x7e set: call FUN_004d0e90, return 1
   4. If type 1 or 3 (weapon/armor):
      - Clear bit 3 at +0x17d
      - Call vtable +0x144 (destroy)
      - If bRemoveType == 0: call vtable +0x50 with 0, else with 2
      - Notify via *(this+0xe500)
      - Handle vehicle refs via +0x5f bits 5,6
   5. If type 0x36 (repair station): handle special removal
   6. Call vtable +0x2a8 with spawn params
   7. Clear bit 1 at +0x17d
   8. Insert into removal hash at this+0xe5c0 */

char __thiscall
CVOGReaction_RemoveObject(void *this,uint uObjectID,undefined4 uInstanceID,char bRemoveType)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  
  uVar2 = uInstanceID;
  uVar1 = uObjectID;
  piVar3 = (int *)CVOGReaction_ResolveObjectTarget(0,uObjectID,uInstanceID);
  if (piVar3 == (int *)0x0) {
    iVar6 = FUN_004e23d0(uVar1,uVar2,&uObjectID);
    iVar4 = 0;
    if (iVar6 != 0) {
      iVar4 = *(int *)(iVar6 + 0xc);
    }
    if (iVar4 != 0) {
      *(byte *)(iVar4 + 0x17d) = *(byte *)(iVar4 + 0x17d) & 0xef;
      uObjectID = uObjectID & 0xffffff00;
      FUN_004e2600(FUN_004cd4e0,&uObjectID,0);
    }
    return '\0';
  }
  iVar4 = (**(code **)(*piVar3 + 0x214))();
  if (iVar4 != 0) {
    if (*(char *)((int)this + 0x7e) != '\0') {
      FUN_004d0e90(piVar3);
    }
    return '\x01';
  }
  iVar4 = *(int *)(piVar3[0x2a] + 0x38);
  if ((iVar4 == 1) || (iVar4 == 3)) {
    *(byte *)((int)piVar3 + 0x17d) = *(byte *)((int)piVar3 + 0x17d) & 0xef;
    (**(code **)(*piVar3 + 0x144))();
    if (bRemoveType == '\0') {
      (**(code **)(*piVar3 + 0x50))(0);
    }
    else {
      (**(code **)(*piVar3 + 0x50))(2);
    }
    if (*(int *)((int)this + 0xe500) != 0) {
      (**(code **)**(undefined4 **)((int)this + 0xe500))(piVar3);
    }
    if (((uint)piVar3[0x5f] >> 5 & 1) != 0) {
      piVar5 = (int *)(**(code **)(*piVar3 + 0x1c8))();
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 4))();
      }
    }
    if (((uint)piVar3[0x5f] >> 6 & 1) != 0) {
      piVar5 = (int *)(**(code **)(*piVar3 + 0x1cc))();
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 4))();
        *(undefined1 *)((int)piVar5 + 0xf) = 0;
      }
    }
  }
  else if (iVar4 == 0x36) {
    iVar4 = (**(code **)(*piVar3 + 0x1ec))();
    if (iVar4 != 0) {
      FUN_004e2600(FUN_00563800,&bRemoveType,0);
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x118))();
      FUN_004e2600(FUN_00563760,0,0);
      FUN_004bc580();
    }
  }
  (**(code **)(*piVar3 + 0x2a8))(*(undefined4 *)((int)this + 0xe4e8));
  *(byte *)((int)piVar3 + 0x17d) = *(byte *)((int)piVar3 + 0x17d) & 0xfd;
  iVar4 = *(int *)((int)this + 0xe5c0);
  if (*(char *)(iVar4 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:insert, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  iVar6 = FUN_004e23d0(uVar1,uObjectID,&stack0xfffffff8);
  if ((iVar6 == 0) || (*(int *)(iVar6 + 0xc) == 0)) {
    iVar6 = FUN_004e23d0(uVar1,uObjectID,&stack0xfffffff8);
    if ((iVar6 != 0) && (*(int *)(iVar6 + 0xc) != 0)) {
      FUN_007a4480(0,"Duplicate hash insert %u, failing out",uVar1,uObjectID);
      return '\x01';
    }
    puVar7 = (undefined4 *)FUN_00589890();
    puVar7[4] = 0;
    *puVar7 = &PTR_FUN_009cb360;
    puVar7[8] = 0;
    puVar7[9] = 0;
    *(undefined1 *)(puVar7 + 2) = 0;
    puVar7[3] = piVar3;
    puVar7[6] = uVar1;
    puVar7[7] = uObjectID;
    iVar6 = *(int *)(*(int *)(iVar4 + 0x10) + (uVar1 & *(uint *)(iVar4 + 8)) * 4);
    puVar7[4] = *(undefined4 *)(iVar6 + 4);
    *(undefined4 **)(iVar6 + 4) = puVar7;
    FUN_004e2360();
    if (*(int *)(iVar4 + 0x18) != 0) {
      *(undefined4 **)(*(int *)(iVar4 + 0x18) + 0x20) = puVar7;
      puVar7[8] = 0;
      puVar7[9] = *(undefined4 *)(iVar4 + 0x18);
      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
      *(undefined4 **)(iVar4 + 0x18) = puVar7;
      return '\x01';
    }
    *(undefined4 **)(iVar4 + 0x18) = puVar7;
    *(undefined4 **)(iVar4 + 0x14) = puVar7;
    puVar7[9] = 0;
    puVar7[8] = 0;
    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
  }
  return '\x01';
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
