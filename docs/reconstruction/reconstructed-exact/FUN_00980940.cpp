// =============================================================================
// FUN_00980940
// -----------------------------------------------------------------------------
// Stable ID: aa_00980940
// Address:   0x00980940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00980940 @ 0x00980940
// Stable ID: aa_00980940
// Embedded strings (evidence for future rename):
//   - "Auction no longer exists."
//   - "Cannot cancel auctions that aren\'t your own."
//   - "Auction has already been bid on."
//   - "Cancel was unsuccessful."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, if×4, return×2, for×1, switch×1, goto×1.
//  - Notable callees: FUN_007fde80, FUN_007fdfb0, FUN_008f8200, FUN_00980940.
//  - Strings: "Auction no longer exists."; "Cannot cancel auctions that aren\'t your own."; "Auction has already been bid on."; "Cancel was unsuccessful.".
//  - Return sites: 2.

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

void __thiscall FUN_00980940(int *param_1,int param_2)



{

  int *piVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  char *pcVar5;

  char unaff_SI;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_106 [64];

  

  puVar6 = local_106;

  for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  *(uint16_t *)puVar6 = 0;

  switch(*(uint32_t /* width from decompiler */ *)(param_2 + 4)) {

  case 1:

  case 4:

    pcVar3 = (char *)(**(code **)(*param_1 + 0x58))("Auction no longer exists.");

    pcVar5 = &stack0xfffffef4;

    do {

      cVar2 = *pcVar3;

      *pcVar5 = cVar2;

      pcVar3 = pcVar3 + 1;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    (**(code **)*param_1)(*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_2 + 0xc));

    piVar1 = DAT_00d1b94c;

    if ((DAT_00d1b94c != (int *)0x0) &&

       (cVar2 = (**(code **)(*DAT_00d1b94c + 0x3d8))(), cVar2 != '\0')) {

      (**(code **)(*piVar1 + 0x450))(0xffffffff,0xffffffff);

    }

    break;

  case 2:

    pcVar3 = (char *)(**(code **)(*param_1 + 0x58))("Cannot cancel auctions that aren\'t your own.")

    ;

    pcVar5 = &stack0xfffffef4;

    do {

      cVar2 = *pcVar3;

      *pcVar5 = cVar2;

      pcVar3 = pcVar3 + 1;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    break;

  case 3:

    pcVar3 = (char *)(**(code **)(*param_1 + 0x58))("Auction has already been bid on.");

    pcVar5 = &stack0xfffffef4;

    do {

      cVar2 = *pcVar3;

      *pcVar5 = cVar2;

      pcVar3 = pcVar3 + 1;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    break;

  case 5:

    pcVar3 = (char *)(**(code **)(*param_1 + 0x58))("Cancel was unsuccessful.");

    pcVar5 = &stack0xfffffef4;

    do {

      cVar2 = *pcVar3;

      *pcVar5 = cVar2;

      pcVar3 = pcVar3 + 1;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    break;

  default:

    goto LAB_00980aac;

  }

  if (((DAT_00d1b780 != (int *)0x0) && (*DAT_00d1b780 != 0)) && (DAT_00d1b8dc != 0)) {

    FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,&stack0xfffffef4,0);

  }

  if (*(int *)(param_2 + 4) == 0) {

    if (unaff_SI != '\0') {

      FUN_007fde80(&stack0xfffffef4,0,0x40800000,0x3f800000,0);

      return;

    }

  }

  else {

    FUN_007fdfb0(&DAT_00d1a840,&stack0xfffffef4,0xffffffff,1,0);

  }

LAB_00980aac:

  return;

}
