// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostC_00509680
// -----------------------------------------------------------------------------
// Stable ID: aa_00509680
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostCreateFromPacket
// Address:   0x00509680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostCreateFromPacket: packet/network helper. Evidence string: "CVOGLootGenerator::GetTypeFromIDPrefix() passed an invalid prefix (%d), couldn\'t find typ". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "CVOGLootGenerator::GetTypeFromIDPrefix() passed an invalid prefix (%d), couldn\'t find typ"
//   - "CVOGLootGenerator::GetTypeFromIDPrefix() passed an invalid prefix (%d), couldn\'t find typ"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×7, if×2, switch×1.
//  - Notable callees: CVOGLootGenerator::GetTypeFromIDPrefix, FUN_00508ac0, FUN_00508b10, FUN_00508b60, FUN_00508bb0, FUN_00508c00, FUN_00508c50, FUN_00509680.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostCreateFromPacket
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

uint8_t Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostC_00509680(int param_1)



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

    return *(uint8_t *)(iVar2 + 0x10);

  default:

    return 0;

  case 0xc:

    iVar2 = FUN_00508ac0(iVar2);

    return *(uint8_t *)(iVar2 + 0x10);

  case 0xe:

    iVar2 = FUN_00508bb0(iVar2);

    return *(uint8_t *)(iVar2 + 0x10);

  case 0x1c:

    iVar2 = FUN_00508b10(iVar2);

    return *(uint8_t *)(iVar2 + 0x10);

  case 0x44:

    iVar2 = FUN_00508c50(iVar2);

    return *(uint8_t *)(iVar2 + 0x10);

  case 0x46:

    iVar2 = FUN_00508c00(iVar2);

    return *(uint8_t *)(iVar2 + 0x10);

  }

}
