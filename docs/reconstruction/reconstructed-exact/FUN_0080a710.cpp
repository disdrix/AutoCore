// =============================================================================
// FUN_0080a710
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a710
// Address:   0x0080a710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080a710 @ 0x0080a710
// Stable ID: aa_0080a710
// Embedded strings (evidence for future rename):
//   - "Clan successfully updated."
//   - "Server could not find your clan!"
//   - "One or more of the Rank titles are invalid."
//   - "The Message of the Day is invalid."
//   - "The Monthly Dues is invalid"
//   - "Unknown Clan Update Error"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: return×6, if×1, switch×1.
//  - Notable callees: FUN_007a6de0×6, FUN_007fdfb0×6, FUN_007a69d0, FUN_0080a710.
//  - Strings: "Clan successfully updated."; "Server could not find your clan!"; "One or more of the Rank titles are invalid."; "The Message of the Day is invalid.".
//  - Return sites: 6.

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

void FUN_0080a710(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  FUN_007a69d0();

  if (in_EAX != 0) {

    switch(*(uint32_t /* width from decompiler */ *)(in_EAX + 4)) {

    case 0:

      uVar4 = 0;

      uVar3 = 1;

      uVar2 = 0xffffffff;

      uVar1 = FUN_007a6de0("Clan successfully updated.",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

      return;

    case 1:

      uVar4 = 0;

      uVar3 = 1;

      uVar2 = 0xffffffff;

      uVar1 = FUN_007a6de0("Server could not find your clan!",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

      return;

    case 2:

      uVar4 = 0;

      uVar3 = 1;

      uVar2 = 0xffffffff;

      uVar1 = FUN_007a6de0("One or more of the Rank titles are invalid.",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

      return;

    case 3:

      uVar4 = 0;

      uVar3 = 1;

      uVar2 = 0xffffffff;

      uVar1 = FUN_007a6de0("The Message of the Day is invalid.",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

      return;

    case 4:

      uVar4 = 0;

      uVar3 = 1;

      uVar2 = 0xffffffff;

      uVar1 = FUN_007a6de0("The Monthly Dues is invalid",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

      return;

    default:

      uVar4 = 0;

      uVar3 = 1;

      uVar2 = 0xffffffff;

      uVar1 = FUN_007a6de0("Unknown Clan Update Error",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar1,uVar2,uVar3,uVar4);

    }

  }

  return;

}
