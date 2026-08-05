// =============================================================================
// FUN_00931db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00931db0
// Address:   0x00931db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00931db0 @ 0x00931db0
// Stable ID: aa_00931db0
// Embedded strings (evidence for future rename):
//   - "This item can only be changed in town."
//   - "There is not enough space in your inventory for this equipment."
//   - "You cannot equip unidentified technology."
//   - "This equipment is too heavy for your vehicle."
//   - "This technology is too advanced for you to use."
//   - "This equipment does not match your vehicle\'s size requirements."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: return×13, for×3, switch×1, goto×1, while×1.
//  - Notable callees: FUN_007a6de0×13, FUN_007fdfb0×13, FUN_007a69d0, FUN_00931db0.
//  - Strings: "This item can only be changed in town."; "You cannot equip unidentified technology."; "This equipment is too heavy for your vehicle."; "This technology is too advanced for you to use.".
//  - Return sites: 13.

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

void FUN_00931db0(void)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  FUN_007a69d0();

  switch(unaff_EDI) {

  case 0:

  case 3:

    goto switchD_00931dc0_caseD_0;

  case 1:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("This item can only be changed in town.",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  case 2:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("There is not enough space in your inventory for this equipment.",

                         0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  case 4:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("You cannot equip unidentified technology.",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  case 5:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("This equipment is too heavy for your vehicle.",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  case 6:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("This technology is too advanced for you to use.",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  case 7:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("This equipment does not match your vehicle\'s size requirements.",

                         0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  case 8:

  case 0xc:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("This item cannot be equipped.",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  case 9:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("You cannot equip a broken item.",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  case 10:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("This item must be swapped directly with another item.",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  default:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("This equipment cannot be changed at this time.",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

switchD_00931dc0_caseD_0:

    return;

  case 0xd:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("Cannot change this item while in Hazard Mode!",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  case 0xe:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("You must remove everything from your vehicle first.!",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  case 0xf:

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("This equipment cannot be changed in an arena.",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    return;

  }

}
