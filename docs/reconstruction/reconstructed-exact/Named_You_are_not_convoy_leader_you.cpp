// =============================================================================
// Named_You_are_not_convoy_leader_you
// -----------------------------------------------------------------------------
// Stable ID: aa_0093a180
// Address:   0x0093a180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_You_are_not_convoy_leader_you @ 0x0093a180
// Stable ID: aa_0093a180
// Embedded strings (evidence for future rename):
//   - "You are not the convoy leader, so you cannot join a tournament."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00574880, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, Named_You_are_not_convoy_leader_you.
//  - Strings: ";

        FUN_007a69d0(".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "You are not the convoy leader, so you cannot join a tournament."
 * Domain alias of FUN_0093a180 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_You_are_not_convoy_leader_you(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int unaff_ESI;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (*(int *)(unaff_ESI + 0xe98) != 0) {

    if (*(int *)(*(int *)(unaff_ESI + 0xe98) + 0xcb0) != 0) {

      iVar1 = FUN_00574880();

      if (iVar1 != *(int *)(unaff_ESI + 0xe98)) {

        uVar6 = 0;

        uVar5 = 1;

        uVar4 = 0xffffffff;

        uVar3 = 0xffffffff;

        pcVar2 = "You are not the convoy leader, so you cannot join a tournament.";

        FUN_007a69d0("You are not the convoy leader, so you cannot join a tournament.",0xffffffff,

                     0xffffffff,1,0);

        uVar3 = FUN_007a6de0(pcVar2,uVar3);

        FUN_007fdfb0(unaff_ESI,uVar3,uVar4,uVar5,uVar6);

        return;

      }

    }

    local_8 = 0x20ab;

    local_4 = param_1;

    if (*(int *)(unaff_ESI + 0xc78) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,&local_8,8,0);

    }

  }

  return;

}
