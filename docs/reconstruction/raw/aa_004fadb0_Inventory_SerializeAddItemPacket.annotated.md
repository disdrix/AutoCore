# Annotated low-level: Inventory_SerializeAddItemPacket

| Field | Value |
|---|---|
| Stable ID | `aa_004fadb0` |
| VA | `0x004fadb0` |
| System | inventory-transfer |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fadb0`.
- **`this+0x2b0`** must be non-null cargo inventory; else return 0.
- Packet field map (matches `Documentation/PACKET STRUCTURES.md` opcode `0x2047`):

| Packet off | Written as | Meaning |
|-----------:|------------|---------|
| +0x08/+0x0c | item[0x58]/[0x59] or match+0x160/164 | **Item COID lo/hi** (NOT grid X/Y — older plate was wrong) |
| +0x10/+0x11 | `FUN_005714e0` outs or 0 | Cargo slot X/Y |
| +0x12 | 0 or 1 | bAddToExisting |
| +0x18 | 0 then maybe 1 | wasAdded / bWasSuccessful |

- Item dword `[0x58]` = byte `+0x160` (COID lo); `[0x59]` = `+0x164` (COID hi).
- `FUN_00513e70()` non-zero → stack-merge scan path; zero → free-slot only.
- Stack match: same CBID (`clonebase+0x34`), flag bit 19 clear on both (`+0x17c` / item[0x5f]), qty gate `vfunc+0x25c` + `FUN_0040abf0`.
- Cargo CS: inventory `+0x54` held flag, `+0x30` CRITICAL_SECTION — released after scan.
- Caller: `Client_SendInventoryAddItem` stamps opcode `0x2047` then branches on `+0x12`.

## Pseudocode (annotated copy of raw)

```c
/* Inventory_SerializeAddItemPacket - fills an InventoryAddItem packet (param_2) from an item object
   (param_3/piVar2). Writes packet+8/+0xc = item COID (item[0x58]/[0x59] = +0x160/+0x164),
   packet+0x10/+0x11 = grid X/Y, packet+0x12 = addToExisting, packet+0x18 = wasAdded.
   item[0x2a] (+0xa8) -> type/clonebase ptr; +0x38==4 is a slot-type check. item[0x5f] (+0x17c) = flags. */

char __thiscall Inventory_SerializeAddItemPacket(int param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  
  piVar2 = param_3;
  *(undefined1 *)(param_2 + 0x18) = 0;
  if (*(int *)(param_1 + 0x2b0) == 0) {
    return '\0';
  }
  cVar1 = '\0';
  cVar4 = FUN_00513e70();
  if (cVar4 == '\0') {
    if ((*(int *)(piVar2[0x2a] + 0x38) == 4) ||
       (cVar4 = FUN_005714e0(piVar2,param_2 + 0x10,param_2 + 0x11,1,0xffffffff), cVar4 != '\0')) {
      *(undefined1 *)(param_2 + 0x18) = 1;
      *(undefined1 *)(param_2 + 0x12) = 0;
      *(int *)(param_2 + 8) = piVar2[0x58];
      *(int *)(param_2 + 0xc) = piVar2[0x59];
      cVar1 = '\x01';
    }
  }
  else {
    param_3 = (int *)0x0;
    FUN_004294f0();
    piVar3 = param_4;
    iVar5 = FUN_004022a0(&param_3,param_4);
    while (iVar5 == 0) {
      iVar5 = *piVar3;
      if ((((iVar5 != 0) &&
           (*(int *)(*(int *)(iVar5 + 0xa8) + 0x34) == *(int *)(piVar2[0x2a] + 0x34))) &&
          ((*(uint *)(iVar5 + 0x17c) >> 0x13 & 1) == 0)) && (((uint)piVar2[0x5f] >> 0x13 & 1) == 0))
      {
        uVar6 = (**(code **)(*piVar2 + 0x25c))();
        cVar4 = FUN_0040abf0(uVar6);
        if (cVar4 != '\0') {
          *(undefined1 *)(param_2 + 0x18) = 1;
          *(undefined1 *)(param_2 + 0x12) = 1;
          *(undefined1 *)(param_2 + 0x10) = 0;
          *(undefined1 *)(param_2 + 0x11) = 0;
          iVar5 = *piVar3;
          *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar5 + 0x160);
          cVar1 = '\x01';
          *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar5 + 0x164);
          break;
        }
      }
      iVar5 = FUN_004022a0(&param_3,piVar3);
    }
    iVar5 = *(int *)(param_1 + 0x2b0);
    if (*(char *)(iVar5 + 0x54) != '\0') {
      *(undefined1 *)(iVar5 + 0x54) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x30));
    }
    if ((cVar1 == '\0') &&
       ((*(int *)(piVar2[0x2a] + 0x38) == 4 ||
        (cVar4 = FUN_005714e0(piVar2,param_2 + 0x10,param_2 + 0x11,1,0xffffffff), cVar4 != '\0'))))
    {
      *(undefined1 *)(param_2 + 0x18) = 1;
      *(undefined1 *)(param_2 + 0x12) = 0;
      *(int *)(param_2 + 8) = piVar2[0x58];
      *(int *)(param_2 + 0xc) = piVar2[0x59];
      return '\x01';
    }
  }
  return cVar1;
}
```
