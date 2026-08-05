// =============================================================================
// FUN_00933650
// -----------------------------------------------------------------------------
// Stable ID: aa_00933650
// Address:   0x00933650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00933650 @ 0x00933650
// Stable ID: aa_00933650
// Embedded strings (evidence for future rename):
//   - "Invalid clonebase ID (%d) for %s"
//   - "Character"
//   - "Front Weapon"
//   - "Turret Weapon"
//   - "Drop Weapon"
//   - "PowerPlant"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×14, for×13, return×1.
//  - Notable callees: CNDHash_LookupByKey×13, FUN_007a4480×13, ID×13, FUN_00933650.
//  - Strings: "Invalid clonebase ID (%d) for %s"; "Character"; "Front Weapon"; "Turret Weapon".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_00933650(void)



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
