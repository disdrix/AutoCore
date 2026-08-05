// =============================================================================
// FUN_00842420
// -----------------------------------------------------------------------------
// Stable ID: aa_00842420
// Address:   0x00842420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00842420 @ 0x00842420
// Stable ID: aa_00842420
// Embedded strings (evidence for future rename):
//   - "Chance to Successfully Add a Single Enhancement with Low Material Difficulty while Craftin"
//   - "Number of Enhancement Slots That Can Be Experimented On at a Time"
//   - "%s: %d\n\n%s: %d%%\n\n"
//   - "

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: return×4, if×2, switch×1, while×1, for×1.
//  - Notable callees: FUN_007a6de0×10, sprintf×4, floor×3, Item×2, Enhancement, FUN_007a69d0, FUN_00842420.
//  - Strings: "

                   ,0xffffffff);

      FUN_007a6de0("; ",0xffffffff);

      sprintf(unaff_EBX,"; ",

                   0xffffffff);

      sprintf(unaff_EBX,"; "Max Memorized Items".
//  - Return sites: 4.

                   ,0xffffffff);

      FUN_007a6de0("
//   - ",

                   0xffffffff);

      sprintf(unaff_EBX,"
//   - "Minimum Chance to Memorize Crafted Item (with No Enhancements)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00842420(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *unaff_EBX;

  int iVar5;

  float fVar6;

  double dVar7;

  double dVar8;

  double dVar9;

  

  if (unaff_EBX != (char *)0x0) {

    FUN_007a69d0();

    switch(param_1) {

    case 0:

      floor((double)((float)param_2 * _DAT_009da8a4));

      FUN_007a6de0("Chance to Successfully Add a Single Enhancement with Low Material Difficulty while Crafting"

                   ,0xffffffff);

      FUN_007a6de0("Number of Enhancement Slots That Can Be Experimented On at a Time",0xffffffff);

      sprintf(unaff_EBX,"%s: %d\n\n%s: %d%%\n\n");

      return;

    case 1:

      fVar6 = (float)param_2 * _DAT_009da8a4;

      floor((double)fVar6);

      floor((double)fVar6);

      FUN_007a6de0("Chance To Reverse Engineer An Item (with Low Material Difficulty) And One Enhancement (with Low Material Difficulty)"

                   ,0xffffffff);

      FUN_007a6de0("Bonus to Success Chance for Reverse Engineering an Item with 1 Enhancement",

                   0xffffffff);

      sprintf(unaff_EBX,"%s: +%d%%\n\n%s: %d%%\n\n");

      return;

    case 2:

      iVar5 = param_2 / 2 + 3;

      if (7 < iVar5) {

        iVar5 = 8;

      }

      fVar6 = (float)param_2 * DAT_00aaa688 + _DAT_00aaa7c0;

      dVar9 = (double)(fVar6 * DAT_00a14000);

      uVar1 = FUN_007a6de0();

      dVar8 = (double)(fVar6 * DAT_00a0f704);

      uVar2 = FUN_007a6de0();

      dVar7 = (double)fVar6;

      uVar3 = FUN_007a6de0("Minimum Chance to Memorize Crafted Item (with No Enhancements)",

                           0xffffffff);

      uVar4 = FUN_007a6de0("Max Memorized Items",0xffffffff);

      sprintf(unaff_EBX,"%s: %d\n\n%s: %0.1f%%\n\n%s: %0.1f%%\n\n%s: %0.1f%%\n\n",uVar4,iVar5,uVar3,

              dVar7,uVar2,dVar8,uVar1,dVar9);

      return;

    case 3:

      FUN_007a6de0("On An Item\n\nBonus Success Chance For Unlocking Gadget Slots",0xffffffff);

      FUN_007a6de0("Can Open Gadget Slots Up To",0xffffffff);

      sprintf(unaff_EBX,"%s #%d %s: +%d%%\n\n");

    }

  }

  return;

}
