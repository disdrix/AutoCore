// =============================================================================
// FUN_005092b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005092b0
// Address:   0x005092b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005092b0 @ 0x005092b0
// Stable ID: aa_005092b0
// Embedded strings (evidence for future rename):
//   - "CVOGLootGenerator::GetTypeFromIDPrefix() passed an invalid prefix (%d), couldn\'t find typ"
//   - "GetModifierLevelOffset() passed an invalid IDPrefix: %i\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: return×7, if×2, switch×1.
//  - Notable callees: FUN_007a4480×2, CVOGLootGenerator::GetTypeFromIDPrefix, FUN_00508ac0, FUN_00508b10, FUN_00508b60, FUN_00508bb0, FUN_00508c00, FUN_00508c50.
//  - Strings: "GetModifierLevelOffset() passed an invalid IDPrefix: %i\n".
//  - Return sites: 7.

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

int FUN_005092b0(int param_1)



{

  int *extraout_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *unaff_EDI;

  uint8_t local_4 [4];

  

  iVar2 = param_1;

  Map_LowerBoundFindByIntKey(&DAT_00b041dc,local_4,&param_1,unaff_EDI);

  if (*extraout_EAX == DAT_00b041e0) {

    if (iVar2 != 0) {

      FUN_007a4480(0,

                   "CVOGLootGenerator::GetTypeFromIDPrefix() passed an invalid prefix (%d), couldn\'t find type in map"

                   ,iVar2);

    }

    uVar1 = 0;

  }

  else {

    uVar1 = *(uint32_t /* width from decompiler */ *)(*extraout_EAX + 0x10);

  }

  switch(uVar1) {

  case 10:

    iVar2 = FUN_00508b60(iVar2);

    return (int)*(short *)(iVar2 + 0x84);

  default:

    FUN_007a4480(0,"GetModifierLevelOffset() passed an invalid IDPrefix: %i\n",iVar2);

    return 0;

  case 0xc:

    iVar2 = FUN_00508ac0(iVar2);

    return (int)*(short *)(iVar2 + 0x84);

  case 0xe:

    iVar2 = FUN_00508bb0(iVar2);

    return (int)*(short *)(iVar2 + 0x84);

  case 0x1c:

    iVar2 = FUN_00508b10(iVar2);

    return (int)*(short *)(iVar2 + 0x84);

  case 0x44:

    iVar2 = FUN_00508c50(iVar2);

    return (int)*(short *)(iVar2 + 0x84);

  case 0x46:

    iVar2 = FUN_00508c00(iVar2);

    return (int)*(short *)(iVar2 + 0x84);

  }

}
