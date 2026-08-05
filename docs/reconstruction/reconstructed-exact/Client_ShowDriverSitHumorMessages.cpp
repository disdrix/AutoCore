// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_007fdfb0×3, CVOGReaction_RandomUnitScalar, FUN_00424830, FUN_00951e70.
//  - Return sites: 3.

// =============================================================================
// Client_ShowDriverSitHumorMessages
// -----------------------------------------------------------------------------
// Purpose:  Easter-egg / humor lines for redundant sit/exit/driver seat actions.
//
// Address:  0x00951e70  (autoassault.exe, image base 0x400000)
// Stable:   aa_00951e70
// System:   input-drive-control
//
// String evidence: "recline back in the driver's seat" / Wumpus exit humor
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_00951e70.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_00951e70 using string evidence: "recline back in the driver's seat" / Wumpus exit humor
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

uint32_t /* width from decompiler */ __fastcall Client_ShowDriverSitHumorMessages(int param_1)

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
