# Raw capture: CVOGReaction_SpawnObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_004de550` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004de550` |
| **Canonical name** | `CVOGReaction_SpawnObject` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Spawn an object in the world by ID.
   
   Parameters:
   this - Reaction context (offsets: +0xe4e8=spawn params, +0x100=flag)
   uObjectID - Object definition ID
   uInstanceID - Instance/variant ID
   
   Returns: 1 if spawned successfully, 0 if failed
   
   Algorithm:
   1. Resolve object via FUN_004e23d0, get pointer from result+0xc
   2. If null: log via FUN_004bcda0, clear bit 1 at +0x17d
   3. If bit 12 of object+0x5f set: check spawn flag, return early
   4. Get position via vtable +0x1c8, set velocity via +0x10c
   5. Set bit 1 at +0x17d, call vtable +0x2a4 with spawn params
   6. If object type != 0x36:
      - Check bits at +0xe and +0xf, init via FUN_004dbef0
      - Call vtable +0x244 and +0x240 for init
      - If flag at +0x100 set: set bit 4 at +0x17d
      - Call vtable +0xfc, set state 3 via FUN_00518370
      - Set +0x45 = -1
   7. Handle vehicle references via vtable +0x1cc and +0x1ec
   8. Return 1 */

char __thiscall CVOGReaction_SpawnObject(void *this,undefined4 uObjectID,undefined4 uInstanceID)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar1 = uInstanceID;
                    /* // Resolve object via FUN_004e23d0, get pointer from result+0xc */
  uVar3 = uObjectID;
                    /* // If object not found: log error, clear bit 1 at +0x17d */
  iVar2 = FUN_004e23d0(uObjectID,uInstanceID,&uObjectID);
  if (iVar2 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar2 + 0xc);
  }
  if (piVar4 == (int *)0x0) {
    return '\0';
  }
  iVar2 = (**(code **)(*piVar4 + 0x214))();
  if (iVar2 == 0) {
                    /* // Get position via vtable +0x1c8, set velocity via +0x10c */
    FUN_004bcda0(uVar3,uVar1,0);
    *(byte *)((int)piVar4 + 0x17d) = *(byte *)((int)piVar4 + 0x17d) & 0xfe;
                    /* // Set bit 1 at +0x17d, call vtable +0x2a4 with spawn params */
    if (((uint)piVar4[0x5f] >> 0xc & 1) != 0) {
                    /* // If type != 0x36: initialize object state */
      uObjectID = CONCAT31(uObjectID._1_3_,1);
      FUN_004e2600(FUN_004cd4e0,&uObjectID,0);
      if (uObjectID._1_1_ != '\0') {
        return '\x01';
      }
    }
    iVar2 = (**(code **)(*piVar4 + 0x1c8))();
    if ((iVar2 != 0) && (iVar2 = (**(code **)(*piVar4 + 0x1c8))(), *(int *)(iVar2 + 8) != 0)) {
      iVar2 = (**(code **)(*piVar4 + 0x1c8))();
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x10c))();
      return '\x01';
    }
    *(byte *)((int)piVar4 + 0x17d) = *(byte *)((int)piVar4 + 0x17d) | 2;
    (**(code **)(*piVar4 + 0x2a4))(*(undefined4 *)((int)this + 0xe4e8));
    if (*(int *)(piVar4[0x2a] + 0x38) != 0x36) {
      if ((piVar4[0xe] & piVar4[0xf]) != 0xffffffff) {
        FUN_004dbef0(piVar4,0,piVar4[0xe],piVar4[0xf],0xffffffff);
      }
      iVar2 = *piVar4;
      uVar3 = (**(code **)(iVar2 + 0x244))();
      (**(code **)(iVar2 + 0x240))(uVar3);
      if (*(char *)((int)this + 0x100) != '\0') {
        *(byte *)((int)piVar4 + 0x17d) = *(byte *)((int)piVar4 + 0x17d) | 0x10;
      }
      (**(code **)(*piVar4 + 0xfc))();
      FUN_00518370(3);
      piVar4[0x45] = -1;
      iVar2 = (**(code **)(*piVar4 + 0x1cc))();
      if ((iVar2 != 0) && (iVar2 = (**(code **)(*piVar4 + 0x1cc))(), *(int *)(iVar2 + 8) != 0)) {
        iVar2 = (**(code **)(*piVar4 + 0x1cc))();
        *(undefined4 *)(*(int *)(iVar2 + 8) + 0x148) = 0xffffffff;
      }
      iVar2 = (**(code **)(*piVar4 + 0x1cc))();
      if (iVar2 == 0) {
        (**(code **)(*piVar4 + 0xb4))();
        (**(code **)(*piVar4 + 0x148))();
        return '\x01';
      }
      *(undefined1 *)(iVar2 + 0xf) = 0;
      FUN_004c00f0(iVar2);
      (**(code **)(*piVar4 + 0x148))();
      return '\x01';
    }
    iVar2 = (**(code **)(*piVar4 + 0x1ec))();
    if (iVar2 != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x148))();
    }
  }
  return '\x01';
}
```
