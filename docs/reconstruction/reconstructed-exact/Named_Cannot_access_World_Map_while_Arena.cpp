// =============================================================================
// Named_Cannot_access_World_Map_while_Arena
// -----------------------------------------------------------------------------
// Stable ID: aa_00937470
// Address:   0x00937470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Cannot_access_World_Map_while_Arena @ 0x00937470
// Stable ID: aa_00937470
// Embedded strings (evidence for future rename):
//   - "Cannot access the World Map while in an Arena!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: return×4, if×3, while×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_007feb20, FUN_007fef20, Named_Cannot_access_World_Map_while_Arena.
//  - Strings: "Cannot access the World Map while in an Arena!".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Cannot access the World Map while in an Arena!"
 * Domain alias of FUN_00937470 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Cannot_access_World_Map_while_Arena(void)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  if ((*(int *)(unaff_ESI + 0xe98) != 0) &&

     (cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 4) + 4) + 4 +

                                   *(int *)(unaff_ESI + 0xe98)) + 0x194))(), cVar2 != '\0')) {

    return;

  }

  FUN_007a69d0();

  if (*(char *)(DAT_00d1b644 + 0xf6) != '\0') {

    uVar6 = 0;

    uVar5 = 1;

    uVar4 = 0xffffffff;

    uVar3 = FUN_007a6de0("Cannot access the World Map while in an Arena!",0xffffffff);

    FUN_007fdfb0(&DAT_00d1a840,uVar3,uVar4,uVar5,uVar6);

    return;

  }

  if (((*(int *)(unaff_ESI + 0xe98) != 0) &&

      (iVar1 = *(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250), iVar1 != 0)) &&

     (cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x194))(),

     cVar2 != '\0')) {

    return;

  }

  FUN_007feb20();

  *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_ESI + 0xf40) + 0x514) =

       *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_ESI + 0xf40) + 0x498);

  *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_ESI + 0xf40) + 0x518) =

       *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_ESI + 0xf40) + 0x49c);

  *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_ESI + 0xf40) + 0x498) = 0x4e2e;

  *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_ESI + 0xf40) + 0x49c) = 0x4e2e;

  FUN_007fef20(0x14,1,0);

  return;

}
