// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×14, for×13, return×1.
//  - Notable callees: CNDHash_LookupByKey×13, FUN_007a4480×13, ID×13, FUN_00933650.
//  - Strings: "Invalid clonebase ID (%d) for %s"; "Character"; "Front Weapon"; "Turret Weapon".
//  - Return sites: 1.

// =============================================================================
// Inv_ValidateEquippedClonebaseSlots
// -----------------------------------------------------------------------------
// Purpose:  Validate character equipment clonebase IDs for each equip slot (Character body, Front/Turret/Drop Weapon, PowerPlant, Armor, Wheelset, Race item, Melee, Ornament, Trailer, Trailer Wheelset). Looks up CNDHash clonebase and asserts expected type codes.
//
// Address:  0x00933650  (autoassault.exe, image base 0x400000)
// Stable:   aa_00933650
// System:   inventory-transfer
//
// Evidence strings (from raw decompile):
//   - "Invalid clonebase ID (%d) for %s"
//   - "Character"
//   - "Front Weapon"
//   - "Turret Weapon"
//   - "Drop Weapon"
//   - "PowerPlant"
//   - "Armor"
//   - "Wheelset"
//   - "Race item"
//   - "Melee weapon"
//   - "Ornament"
//   - "Trailer"
//   - "Trailer Wheelset"
//
// Notable callees:
//   - CNDHash_LookupByKey
//   - FUN_007a4480
//
// Notes:    unaff_ESI = character equip blob; offsets +0x15c.. weapons at +0x180/+0x184/+0x188, powerplant/armor/wheelset nearby.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

void Inv_ValidateEquippedClonebaseSlots(void)



{

  uint uVar1;

  void *pvVar2;

  int unaff_ESI;

  

  if (*(char *)(unaff_ESI + 0x10) == '\0') {

    uVar1 = *(uint *)(unaff_ESI + 0x15c);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 0x14)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Character");

    }

    uVar1 = *(uint *)(unaff_ESI + 0x17c);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 0xe)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,&DAT_00a2e6e4);

    }

    uVar1 = *(uint *)(unaff_ESI + 0x180);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 0xc)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Front Weapon");

    }

    uVar1 = *(uint *)(unaff_ESI + 0x184);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 0xc)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Turret Weapon");

    }

    uVar1 = *(uint *)(unaff_ESI + 0x188);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 0xc)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Drop Weapon");

    }

    uVar1 = *(uint *)(unaff_ESI + 0x18c);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 10)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"PowerPlant");

    }

    uVar1 = *(uint *)(unaff_ESI + 400);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 0x1c)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Armor");

    }

    uVar1 = *(uint *)(unaff_ESI + 0x194);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 0x10)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Wheelset");

    }

    uVar1 = *(uint *)(unaff_ESI + 0x198);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 6)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Race item");

    }

    uVar1 = *(uint *)(unaff_ESI + 0x19c);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 0xc)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Melee weapon");

    }

    uVar1 = *(uint *)(unaff_ESI + 0x1a0);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 6)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Ornament");

    }

    uVar1 = *(uint *)(unaff_ESI + 0x1a4);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 0xe)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Trailer");

    }

    uVar1 = *(uint *)(unaff_ESI + 0x1a8);

    if (((uVar1 != 0xffffffff) && (uVar1 != 0)) &&

       ((pvVar2 = CNDHash_LookupByKey(*(void **)(*(int *)(unaff_ESI + 0xd30) + 0xf10),uVar1),

        pvVar2 == (void *)0x0 || (*(int *)((int)pvVar2 + 0x38) != 0x10)))) {

      FUN_007a4480(1,"Invalid clonebase ID (%d) for %s",uVar1,"Trailer Wheelset");

    }

  }

  return;

}
