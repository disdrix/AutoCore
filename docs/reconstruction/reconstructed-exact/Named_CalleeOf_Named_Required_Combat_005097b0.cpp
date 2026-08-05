// =============================================================================
// Named_CalleeOf_Named_Required_Combat_005097b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005097b0
// Callee of Named_Required_Combat
// Address:   0x005097b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Required_Combat: combat/reward helper. Evidence string: "CVOGLootGenerator::GetTypeFromIDPrefix() passed an invalid prefix (%d), couldn\'t find typ". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "CVOGLootGenerator::GetTypeFromIDPrefix() passed an invalid prefix (%d), couldn\'t find typ"
//   - "GetTypelessRecipe() passed an invalid IDPrefix: %i\n"
//   - "CVOGLootGenerator::GetTypeFromIDPrefix() passed an invalid prefix (%d), couldn\'t find typ"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×8, return×7, switch×1.
//  - Notable callees: FUN_00508ac0×2, FUN_00508b10×2, FUN_00508b60×2, FUN_00508bb0×2, FUN_00508c00×2, FUN_00508c50×2, FUN_007a4480×2, CVOGLootGenerator::GetTypeFromIDPrefix.
//  - Strings: "GetTypelessRecipe() passed an invalid IDPrefix: %i\n".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_Required_Combat
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_CalleeOf_Named_Required_Combat_005097b0(int param_1)



{

  int *extraout_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  int *unaff_EDI;

  uint8_t local_4 [4];

  

  iVar3 = param_1;

  Map_LowerBoundFindByIntKey(&DAT_00b041dc,local_4,&param_1,unaff_EDI);

  if (*extraout_EAX == DAT_00b041e0) {

    if (iVar3 != 0) {

      FUN_007a4480(0,

                   "CVOGLootGenerator::GetTypeFromIDPrefix() passed an invalid prefix (%d), couldn\'t find type in map"

                   ,iVar3);

    }

    uVar1 = 0;

  }

  else {

    uVar1 = *(uint32_t /* width from decompiler */ *)(*extraout_EAX + 0x10);

  }

  switch(uVar1) {

  case 0xc:

    iVar2 = FUN_00508ac0(iVar3);

    if (iVar2 != 0) {

      iVar3 = FUN_00508ac0(iVar3);

      return iVar3 + 0x70;

    }

  case 0x1c:

    iVar2 = FUN_00508b10(iVar3);

    if (iVar2 != 0) {

      iVar3 = FUN_00508b10(iVar3);

      return iVar3 + 0x70;

    }

  case 10:

    iVar2 = FUN_00508b60(iVar3);

    if (iVar2 != 0) {

      iVar3 = FUN_00508b60(iVar3);

      return iVar3 + 0x70;

    }

  case 0xe:

    iVar2 = FUN_00508bb0(iVar3);

    if (iVar2 != 0) {

      iVar3 = FUN_00508bb0(iVar3);

      return iVar3 + 0x70;

    }

  case 0x46:

    iVar2 = FUN_00508c00(iVar3);

    if (iVar2 != 0) {

      iVar3 = FUN_00508c00(iVar3);

      return iVar3 + 0x70;

    }

  case 0x44:

    iVar2 = FUN_00508c50(iVar3);

    if (iVar2 != 0) {

      iVar3 = FUN_00508c50(iVar3);

      return iVar3 + 0x70;

    }

  default:

    FUN_007a4480(1,"GetTypelessRecipe() passed an invalid IDPrefix: %i\n",iVar3);

    return 0;

  }

}
