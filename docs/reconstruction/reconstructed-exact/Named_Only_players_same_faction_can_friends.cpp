// =============================================================================
// Named_Only_players_same_faction_can_friends
// -----------------------------------------------------------------------------
// Stable ID: aa_0080f630
// Address:   0x0080f630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Only_players_same_faction_can_friends @ 0x0080f630
// Stable ID: aa_0080f630
// Embedded strings (evidence for future rename):
//   - "has been added to your friends list"
//   - "%s %s."
//   - "Friend not found!"
//   - "Only players of the same faction can be friends!"
//   - "You have reached the limit of how many friends you can have!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, for×2, switch×1, goto×1.
//  - Notable callees: FUN_007a6de0×2, FUN_008f8200×2, __RTDynamicCast×2, FUN_00574020, FUN_007a69d0, Named_Only_players_same_faction_can_friends, sprintf.
//  - Strings: "has been added to your friends list"; "%s %s."; "Friend not found!"; "Only players of the same faction can be friends!".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Only players of the same faction can be friends!"
 * Domain alias of FUN_0080f630 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Only_players_same_faction_can_friends(int param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char *pcVar7;

  char acStack_108 [2];

  uint32_t /* width from decompiler */ auStack_106 [64];

  

  FUN_007a69d0();

  switch(*(uint32_t /* width from decompiler */ *)(param_1 + 4)) {

  case 0:

    puVar1 = operator_new(0x30);

    puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 8);

    puVar6 = puVar1;

    for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    FUN_00574020(puVar1);

    if (*(int *)(in_EAX + 0x1038) != 0) {

      piVar2 = (int *)__RTDynamicCast(*(int *)(in_EAX + 0x1038),0,&CVOGDialog::RTTI_Type_Descriptor,

                                      &CDlgTabsSocial::RTTI_Type_Descriptor,0);

      (**(code **)(*piVar2 + 0x448))();

    }

    if (*(int *)(in_EAX + 0x108c) != 0) {

      piVar2 = (int *)__RTDynamicCast(*(int *)(in_EAX + 0x108c),0,&CVOGDialog::RTTI_Type_Descriptor,

                                      &CDlgFriendsDetails::RTTI_Type_Descriptor,0);

      (**(code **)(*piVar2 + 0x448))();

    }

    acStack_108[0] = '\0';

    acStack_108[1] = '\0';

    puVar5 = auStack_106;

    for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    *(uint16_t *)puVar5 = 0;

    uVar3 = FUN_007a6de0("has been added to your friends list",0xffffffff);

    sprintf(acStack_108,"%s %s.",param_1 + 0x22,uVar3);

    if (DAT_00d1b8dc == 0) {

      return;

    }

    FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,acStack_108,0);

    return;

  case 1:

    pcVar7 = "Friend not found!";

    break;

  case 2:

    pcVar7 = "Only players of the same faction can be friends!";

    break;

  case 3:

    pcVar7 = "You have reached the limit of how many friends you can have!";

    break;

  default:

    goto switchD_0080f65b_default;

  }

  uVar3 = FUN_007a6de0(pcVar7,0xffffffff);

  if (DAT_00d1b8dc != 0) {

    FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar3,0);

  }

switchD_0080f65b_default:

  return;

}
