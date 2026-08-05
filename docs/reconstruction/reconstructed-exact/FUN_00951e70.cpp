// =============================================================================
// FUN_00951e70
// -----------------------------------------------------------------------------
// Stable ID: aa_00951e70
// Address:   0x00951e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00951e70 @ 0x00951e70
// Stable ID: aa_00951e70
// Embedded strings (evidence for future rename):
//   - "You begin to get out of your vehicle, but you catch scent of a Wumpus and you\'re all out "
//   - "You recline back in the driver\'s seat and ponder sitting while you\'re sitting."
//   - "You try and urge your vehicle to squat on its rear tires, but quickly grow tired of the ef"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_007fdfb0×3, CVOGReaction_RandomUnitScalar, FUN_00424830, FUN_00951e70.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_00951e70(int param_1)



{

  uint uVar1;

  

  if ((*(int *)(param_1 + 0xe04) != 0) && (*(char *)(*(int *)(param_1 + 0xe04) + 0xf5) == '\0')) {

    CVOGReaction_RandomUnitScalar();

    uVar1 = FUN_00424830();

    uVar1 = uVar1 % 3;

    if (uVar1 == 0) {

      FUN_007fdfb0(param_1,

                   "You begin to get out of your vehicle, but you catch scent of a Wumpus and you\'re all out of arrows!"

                   ,0xffffffff,1,0);

    }

    else {

      if (uVar1 == 1) {

        FUN_007fdfb0(param_1,

                     "You recline back in the driver\'s seat and ponder sitting while you\'re sitting."

                     ,0xffffffff,1,0);

        return 1;

      }

      if (uVar1 == 2) {

        FUN_007fdfb0(param_1,

                     "You try and urge your vehicle to squat on its rear tires, but quickly grow tired of the effort."

                     ,0xffffffff,1,0);

        return 1;

      }

    }

  }

  return 1;

}
