// =============================================================================
// FUN_0080eb60
// -----------------------------------------------------------------------------
// Stable ID: aa_0080eb60
// Address:   0x0080eb60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080eb60 @ 0x0080eb60
// Stable ID: aa_0080eb60
// Embedded strings (evidence for future rename):
//   - "You are no longer in a clan."
//   - "has left the clan"
//   - "%s %s."
//   - "The leader of the clan can only leave by disbanding the clan."
//   - "Clan not found."
//   - "You do not have permission to do that."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, goto×2, do×2, switch×1, for×1.
//  - Notable callees: FUN_007a6de0×3, FUN_008f8200×2, FUN_004c22a0, FUN_004c2500, FUN_004c25b0, FUN_007a69d0, FUN_007fdfb0, FUN_0080eb60.
//  - Strings: "You are no longer in a clan."; "has left the clan"; "%s %s."; ";

    break;

  case 2:

    pcVar6 = ".
//  - Return sites: 4.

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

void FUN_0080eb60(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  char local_108 [2];

  uint32_t /* width from decompiler */ local_106 [64];

  

  FUN_007a69d0();

  switch(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x10)) {

  case 0:

    if (*(int *)(unaff_ESI + 0xe98) != 0) {

      iVar2 = *(int *)(unaff_ESI + 0xe98);

      iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

      if ((*(int *)(in_EAX + 8) == *(int *)(iVar3 + 0x164 + iVar2)) &&

         (*(int *)(in_EAX + 0xc) == *(int *)(iVar3 + 0x168 + iVar2))) {

        FUN_004c2500();

        **(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x31f0) = 0xffffffff;

        FUN_0094c6d0();

        uVar8 = 0;

        uVar7 = 1;

        uVar5 = 0xffffffff;

        uVar1 = FUN_007a6de0("You are no longer in a clan.",0xffffffff);

        FUN_007fdfb0(unaff_ESI,uVar1,uVar5,uVar7,uVar8);

        goto LAB_0080ecd1;

      }

    }

    iVar2 = FUN_004c22a0(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc));

    if (iVar2 != 0) {

      local_108[0] = '\0';

      local_108[1] = '\0';

      puVar4 = local_106;

      for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

      *(uint16_t *)puVar4 = 0;

      uVar1 = FUN_007a6de0("has left the clan",0xffffffff);

      sprintf(local_108,"%s %s.",iVar2 + 8,uVar1);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_108,0);

      }

    }

    FUN_004c25b0(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc),

                 *(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc));

LAB_0080ecd1:

    if (*(int *)(unaff_ESI + 0x1090) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x1090) + 0x448))();

    }

    if (*(int *)(unaff_ESI + 0x1038) == 0) {

      return;

    }

    (**(code **)(**(int **)(unaff_ESI + 0x1038) + 0x448))();

    return;

  case 1:

    pcVar6 = "The leader of the clan can only leave by disbanding the clan.";

    break;

  case 2:

    pcVar6 = "Clan not found.";

    break;

  case 3:

    pcVar6 = "You do not have permission to do that.";

    break;

  default:

    goto switchD_0080eb87_default;

  }

  uVar1 = FUN_007a6de0(pcVar6,0xffffffff);

  if (DAT_00d1b8dc != 0) {

    FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar1,0);

    return;

  }

switchD_0080eb87_default:

  return;

}
