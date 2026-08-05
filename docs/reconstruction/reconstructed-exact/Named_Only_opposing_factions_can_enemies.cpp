// =============================================================================
// Named_Only_opposing_factions_can_enemies
// -----------------------------------------------------------------------------
// Stable ID: aa_0080f290
// Address:   0x0080f290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Only_opposing_factions_can_enemies @ 0x0080f290
// Stable ID: aa_0080f290
// Embedded strings (evidence for future rename):
//   - "is now your Enemy"
//   - "%s %s!"
//   - "Enemy not found!"
//   - "Only opposing factions can be enemies!"
//   - "You have too many enemies already!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×2, switch×1, goto×1.
//  - Notable callees: FUN_007a6de0×2, FUN_008f8200×2, FUN_00574270, FUN_007a69d0, Named_Only_opposing_factions_can_enemies, sprintf.
//  - Strings: "is now your Enemy"; "%s %s!"; "Enemy not found!"; "Only opposing factions can be enemies!".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Only opposing factions can be enemies!"
 * Domain alias of FUN_0080f290 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Only_opposing_factions_can_enemies(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char *pcVar6;

  char local_108 [2];

  uint32_t /* width from decompiler */ local_106 [64];

  

  FUN_007a69d0();

  switch(*(uint32_t /* width from decompiler */ *)(param_2 + 4)) {

  case 0:

    puVar1 = operator_new(0x38);

    puVar4 = (uint32_t /* width from decompiler */ *)(param_2 + 8);

    puVar5 = puVar1;

    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    FUN_00574270(puVar1);

    if (*(int **)(param_1 + 0x1038) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x1038) + 0x448))();

    }

    local_108[0] = '\0';

    local_108[1] = '\0';

    puVar4 = local_106;

    for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = 0;

    uVar2 = FUN_007a6de0("is now your Enemy",0xffffffff);

    sprintf(local_108,"%s %s!",param_2 + 0x2b,uVar2);

    if (DAT_00d1b8dc == 0) {

      return;

    }

    FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_108,0);

    return;

  case 1:

    pcVar6 = "Enemy not found!";

    break;

  case 2:

    pcVar6 = "Only opposing factions can be enemies!";

    break;

  case 3:

    pcVar6 = "You have too many enemies already!";

    break;

  default:

    goto switchD_0080f2b5_default;

  }

  uVar2 = FUN_007a6de0(pcVar6,0xffffffff);

  if (DAT_00d1b8dc != 0) {

    FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar2,0);

  }

switchD_0080f2b5_default:

  return;

}
