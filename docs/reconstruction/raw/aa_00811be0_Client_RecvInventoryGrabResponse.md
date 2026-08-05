# Raw capture: Client_RecvInventoryGrabResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811be0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00811be0` |
| **Canonical name** | `Client_RecvInventoryGrabResponse` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* S2C InventoryGrabResponse (dispatch 0x2035). EBX=packet EAX=client from PacketDispatch. Handles
   stack split / cursor object creation. Shared jump slot with 0x2039 (early-out). */

void __cdecl Client_RecvInventoryGrabResponse(void *client,void *packet)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *unaff_EBX;
  uint uVar8;
  char acStack_84 [4];
  char local_80 [128];
  
  *(undefined1 *)(in_EAX + 0xb6) = 0;
  puVar2 = (undefined4 *)FUN_007a69d0();
  if (*unaff_EBX != 0x2039) {
    piVar3 = Object_ResolveFromTFID((TFID_16 *)(unaff_EBX + 2));
    if ((piVar3 != (int *)0x0) && ((char)unaff_EBX[0xe] != '\0')) {
      if ((char)unaff_EBX[8] == '\0') {
        FUN_0093d6e0(in_EAX,unaff_EBX[7]);
        Client_RefreshOpenMissionUiWindows(in_EAX);
        return;
      }
      iVar1 = *piVar3;
      iVar4 = (**(code **)(iVar1 + 0x25c))();
      (**(code **)(iVar1 + 0x260))(iVar4 - unaff_EBX[7]);
      piVar5 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(piVar3[0x2a] + 0x34));
      if (piVar5 == (int *)0x0) {
        uVar7 = *puVar2;
        uVar6 = FUN_007a6de0("Grab Item failed: Failed creating new stack object on coid",0xffffffff
                            );
        sprintf(acStack_84,"%s: %i\n",uVar6,uVar7);
        FUN_007fdfb0(in_EAX,acStack_84,0xffffffff,1,0);
        FUN_007fc150();
        return;
      }
      FUN_00512160(unaff_EBX[10],unaff_EBX[0xb],1);
      (**(code **)(*piVar5 + 8))
                (*(undefined4 *)(piVar3[0x2a] + 0x34),*(undefined4 *)(in_EAX + 0xe04),0);
      (**(code **)(*piVar5 + 0x260))(unaff_EBX[7]);
      FUN_004bc180(piVar5);
      puVar2 = (undefined4 *)(**(code **)(*piVar5 + 0x1cc))();
      (**(code **)*puVar2)(0,0,0,0,0,0,0,g_flOne,0);
      FUN_0093d6e0(in_EAX,unaff_EBX[7]);
      Client_RefreshOpenMissionUiWindows(in_EAX);
      return;
    }
    uVar8 = ((TFID_16 *)(unaff_EBX + 2))->dwCoidLo;
    uVar7 = FUN_007a6de0("Grab Item failed: Failed on coid",0xffffffff);
    sprintf(local_80,"%s: %i\n",uVar7,uVar8);
    OutputDebugStringA(local_80);
    Client_RefreshOpenMissionUiWindows(in_EAX);
  }
  return;
}
```

---

## Version note — dual residual 2026-07-29

Live re-decompile CF **≡** body above. Residual **asm** seals (not changing frozen pseudocode):

- Dispatch sole caller `Client_PacketDispatch` @ `0x008159b0`: `EAX=client`, `EBX=packet`.
- `FUN_0093d6e0` true args: `EAX=item`, `DL=inventoryType@+0x18`, stack `client, count` (decompiler 2-arg form is incomplete).
- Gates: `byte [EBX+0x38]` success; `byte [EBX+0x20]` splitFlag.
- `FUN_00512160` thiscall `ECX=newStack` with COID `[EBX+0x28/0x2c]`, flag `1`.
- `DAT_00d1a8f6` not referenced in this function.

See `tmp/a_00811be0.md` and dual A/B reviews.
