// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: InitialPatrolDistance, MapPathCoid.
//  - Return sites: 1.

// =============================================================================
// CVOGWaypoint_InitFromSpawn
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5580
// Address:   0x005d5580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* AutoCore Phase D: Init waypoint from spawn MapPathCoid (+0xa0) and InitialPatrolDistance (+0x7c).

   Patrol float at waypoint+0x4c. */



void __thiscall

CVOGWaypoint_InitFromSpawn

          (int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

          char param_6,uint8_t param_7)



{

  *(uint8_t *)(param_1 + 0x51) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0xffffffff;

  if (param_6 == '\0') {

    *(uint8_t *)(param_1 + 0x50) = 0;

  }

  else {

    *(uint8_t *)(param_1 + 0x50) = 2;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = param_4;

  *(uint8_t *)(param_1 + 0x51) = param_7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = param_5;

  return;

}
