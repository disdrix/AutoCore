// =============================================================================
// Phy_dmg_icon_physical
// -----------------------------------------------------------------------------
// Stable ID: aa_0083eff0
// Address:   0x0083eff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Phy_dmg_icon_physical @ 0x0083eff0
// Stable ID: aa_0083eff0
// Embedded strings (evidence for future rename):
//   - "dmg_icon_physical"
//   - "dmg_icon_fire"
//   - "dmg_icon_corrosive"
//   - "dmg_icon_contamination"
//   - "dmg_icon_energy"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×8, return×7.
//  - Notable callees: strncmp×5, FUN_00976e10×4, Phy_dmg_icon_physical.
//  - Strings: "dmg_icon_physical"; "dmg_icon_fire"; "dmg_icon_corrosive"; "dmg_icon_contamination".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "dmg_icon_physical"
 * Domain alias of FUN_0083eff0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ Phy_dmg_icon_physical(void)



{

  int iVar1;

  int *piVar2;

  char *unaff_EBX;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  

  if ((((unaff_EBX == (char *)0x0) || (*unaff_EBX == '\0')) || (unaff_ESI == (int *)0x0)) ||

     (DAT_00d1ad30 == 0)) {

    return 0;

  }

  iVar1 = (**(code **)(*unaff_ESI + 0x1b8))

                    ((int)((float)DAT_00d1e818 * DAT_00aaa7b8),

                     (int)((float)DAT_00d1e81c * _DAT_00aaa7b4));

  if ((iVar1 != 0) && (piVar2 = (int *)(**(code **)(*unaff_ESI + 0x1b8))(), *piVar2 != 0)) {

    (**(code **)(*unaff_ESI + 0x1b8))();

  }

  if (*unaff_EBX != 'd') {

    return 0;

  }

  iVar1 = strncmp(unaff_EBX,"dmg_icon_physical",0x11);

  if (iVar1 == 0) {

    FUN_00976e10(DAT_00d1ad30,unaff_ESI,0);

    return 1;

  }

  iVar1 = strncmp(unaff_EBX,"dmg_icon_fire",0xd);

  if (iVar1 == 0) {

    uVar3 = 1;

  }

  else {

    iVar1 = strncmp(unaff_EBX,"dmg_icon_corrosive",0x12);

    if (iVar1 == 0) {

      FUN_00976e10(DAT_00d1ad30,unaff_ESI,3);

      return 1;

    }

    iVar1 = strncmp(unaff_EBX,"dmg_icon_contamination",0x16);

    if (iVar1 == 0) {

      FUN_00976e10(DAT_00d1ad30,unaff_ESI,4);

      return 1;

    }

    iVar1 = strncmp(unaff_EBX,"dmg_icon_energy",0xf);

    if (iVar1 != 0) {

      return 0;

    }

    uVar3 = 5;

  }

  FUN_00976e10(DAT_00d1ad30,unaff_ESI,uVar3);

  return 1;

}
