# Annotated low-level: Client_SendInventoryDrop_Hardpoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00863430` |
| **VA** | `0x00863430` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | inventory-transfer |
| **Source raw** | `aa_00863430_Client_SendInventoryDrop_Hardpoint.md` |
| **Refine** | Human pass 2026-07-23 (named_hl keyword wave) |

This file is the **annotated** layer: packet/UI offsets, branch order, and decompiler corrections.

---

## 1. Purpose

C2S drop/unequip-from-cursor for hardpoint items. Blocks paint/customize-only-in-town cases and certain locked items with toast 'This item can only be changed in town.'

## 2. Corrected signature

```c
uint8_t Client_SendInventoryDrop_Hardpoint(void);
```

## 3. Key offsets / packet fields

| Offset / symbol | Role |
|---|---|
| `cursor item` | DAT_00d1b1f8 vtable+0x3ac |
| `clone+0x38==0x0E` | vehicle/paint special case |
| `char+0x6b4` | town/in-world gate residual |

## 4. Machine-level notes

- Requires DAT_00d1b6d8; cursor item via DAT_00d1b1f8 vtable+0x3ac.
- FUN_00862860 gate; FUN_004fabc0 may force FUN_00931db0.
- Clone type 0x0E (vehicle paint path) with FUN_004ce5f0 / char+0x6b4 town checks.
- Town-only toast shared with other equip paths.

## 5. Pseudocode (authoritative raw, retained)

```c
undefined1 Client_SendInventoryDrop_Hardpoint(void)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined4 auStack_20 [2];

  int iStack_18;

  int iStack_14;

  undefined1 uStack_10;

  undefined1 uStack_8;

  undefined1 uStack_7;

  undefined1 uStack_6;

  

  if (DAT_00d1b6d8 == 0) {

    return 0;

  }

  piVar2 = (int *)(**(code **)(*DAT_00d1b1f8 + 0x3ac))();

  if (piVar2 == (int *)0x0) {

    return 0;

  }

  cVar1 = FUN_00862860();

  if (cVar1 == '\0') {

    return 0;

  }

  uVar4 = *(undefined4 *)(DAT_00d1b6d8 + 0x250);

  iVar3 = FUN_004fabc0(piVar2,0);

  if (iVar3 != 0) {

    FUN_00931db0();

    return 1;

  }

  if (*(int *)(piVar2[0x2a] + 0x38) == 0xe) {

    cVar1 = FUN_004ce5f0(uVar4);

    if ((cVar1 != '\0') || (0 < *(int *)(DAT_00d1b6d8 + 0x6b4))) {

      FUN_008012f0();

      FUN_00931440(1);

      return 1;

    }

LAB_0086351d:

    FUN_007a69d0();

    uVar7 = 0;

    uVar6 = 1;

    uVar5 = 0xffffffff;

    uVar4 = FUN_007a6de0("This item can only be changed in town.",0xffffffff);

    FUN_007fdfb0(&DAT_00d1a840,uVar4,uVar5,uVar6,uVar7);

    return 1;

  }

  cVar1 = FUN_004ce5f0(uVar4);

  if (cVar1 == '\0') {

    iVar3 = (**(code **)(*piVar2 + 0x1f0))();

    if ((iVar3 != 0) && (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) goto LAB_0086351d;

  }

  uStack_10 = (undefined1)piVar2[0x5a];

  iStack_14 = piVar2[0x59];

  iStack_18 = piVar2[0x58];

  uStack_8 = 0xff;

  uStack_7 = 0xff;

  auStack_20[0] = 0x2036;

  uStack_6 = 2;

  Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_20);

  return 1;

}
```

## 6. Open questions

- Name FUN_00862860 cursor validity helper.
