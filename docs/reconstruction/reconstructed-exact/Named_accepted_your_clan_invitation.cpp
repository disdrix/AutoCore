// =============================================================================
// Named_accepted_your_clan_invitation
// -----------------------------------------------------------------------------
// Stable ID: aa_0080ed20
// Address:   0x0080ed20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_accepted_your_clan_invitation @ 0x0080ed20
// Stable ID: aa_0080ed20
// Embedded strings (evidence for future rename):
//   - "has accepted your clan invitation"
//   - "%s %s."
//   - "has refused your clan invitation"
//   - "is already in another clan"
//   - "could not be found"
//   - "Player"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: switch×1, goto×1, if×1, return×1.
//  - Notable callees: FUN_007a6de0×8, sprintf×6, FUN_007a69d0, Named_accepted_your_clan_invitation, FUN_008f8200.
//  - Strings: "has accepted your clan invitation"; "%s %s."; "has refused your clan invitation"; "is already in another clan".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "has accepted your clan invitation"
 * Domain alias of FUN_0080ed20 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_accepted_your_clan_invitation(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  int iVar4;

  char local_200 [512];

  

  FUN_007a69d0();

  switch(*(uint32_t /* width from decompiler */ *)(in_EAX + 4)) {

  case 0:

    uVar1 = FUN_007a6de0("has accepted your clan invitation",0xffffffff);

    sprintf(local_200,"%s %s.",in_EAX + 8,uVar1);

    break;

  case 1:

    uVar1 = FUN_007a6de0("has refused your clan invitation",0xffffffff);

    sprintf(local_200,"%s %s.",in_EAX + 8,uVar1);

    break;

  case 2:

    uVar1 = FUN_007a6de0("is already in another clan",0xffffffff);

    sprintf(local_200,"%s %s.",in_EAX + 8,uVar1);

    break;

  case 3:

    uVar1 = FUN_007a6de0("could not be found",0xffffffff);

    pcVar3 = "Player";

    goto LAB_0080ee4b;

  default:

    uVar1 = FUN_007a6de0("has failed",0xffffffff);

    pcVar3 = "Your clan invitation to";

LAB_0080ee4b:

    iVar4 = in_EAX + 8;

    uVar2 = FUN_007a6de0(pcVar3,0xffffffff);

    sprintf(local_200,"%s %s %s.",uVar2,iVar4,uVar1);

    break;

  case 5:

    uVar1 = FUN_007a6de0("belongs to a different faction and cannot join your clan",0xffffffff);

    sprintf(local_200,"%s %s.",in_EAX + 8,uVar1);

    break;

  case 6:

    uVar1 = FUN_007a6de0("is currently considering another clan\'s offer",0xffffffff);

    sprintf(local_200,"%s %s.",in_EAX + 8,uVar1);

  }

  if (DAT_00d1b8dc != 0) {

    FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_200,0);

  }

  return;

}
