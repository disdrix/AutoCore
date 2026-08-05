// =============================================================================
// Named_character_name_already_taken
// -----------------------------------------------------------------------------
// Stable ID: aa_0080c330
// Address:   0x0080c330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_character_name_already_taken @ 0x0080c330
// Stable ID: aa_0080c330
// Embedded strings (evidence for future rename):
//   - "That character name is already taken."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fc360, FUN_007fdfb0, Named_character_name_already_taken, FUN_008cd070, FUN_009133a0.
//  - Strings: "That character name is already taken.".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "That character name is already taken."
 * Domain alias of FUN_0080c330 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_character_name_already_taken(int param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  FUN_007a69d0();

  if (((int)*(uint *)(param_1 + 4) < 0) && ((*(uint *)(param_1 + 4) & 1) == 0)) {

    FUN_007fc360();

    FUN_009133a0(2);

    piVar1 = *(int **)(DAT_00d1b77c + 0xa7c);

    DAT_00d1a980 = DAT_00d1a984 + -1;

    FUN_008cd070();

    (**(code **)(*piVar1 + 0x444))();

    return;

  }

  uVar5 = 0;

  uVar4 = 1;

  uVar3 = 0xffffffff;

  uVar2 = FUN_007a6de0("That character name is already taken.",0xffffffff);

  FUN_007fdfb0(in_EAX,uVar2,uVar3,uVar4,uVar5);

  return;

}
