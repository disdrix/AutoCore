// =============================================================================
// UI_AppendItemRequirements  (canonical role name for FUN_00845360)
// -----------------------------------------------------------------------------
// Stable ID: aa_00845360
// Address:   0x00845360  (autoassault.exe, image base 0x400000)
// Body:      0x00845360 – 0x00845871 (~1298 B, plain ret after add esp,0x8c)
// System:    UI / item tooltip requirements
// Generated: 2026-07-29 W23-J dual A/B (replaces misleading Named_Combat primary)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      reviews/A_aa_00845360_UI_AppendItemRequirements.md + B_*.md
// =============================================================================

// PURPOSE:
//   Append a localized "Requires:" block to a UI text object for an item row:
//   Level, race, class, Combat, Tech, Theory, Perception — colored white/red by
//   comparing against the local player (DAT_00d1b6d8).
//
// ABI (sealed):
//   Item / template row in **EAX** (custom register ABI)
//   Stack: UI text object pointer (param_1), char show flag (param_2)
//   Return: int line count (0 if suppressed / empty)
//
// Product strings (via FUN_007a6de0):
//   "Requires:", "Level", "Combat", "Tech"@DAT_00a2e4fc, "Theory", "Perception"
// Race/class tables: FUN_0051f8e0 / FUN_0051f940
//
// Rejected scaffold name: Named_Combat_00845360 (Combat is one line only).

/*
 * Behavioral notes (2026-07-29 W23-J):
 * - Early out: show==0 OR nested type +0x38==0x1a OR no local player.
 * - Empty-req out: level inactive AND race==-1 AND class==-1 AND all stat shorts <1.
 * - Colors: header 0xffbbbbbb; met 0xffffffff (or vfunc+0x250 for race/class);
 *   fail 0xffff2020.
 * - Decomp hazard: Perception tail "unaff_EBP+1" == lines+1.
 * - Callers: FUN_00843a60, FUN_0084b890, FUN_0088d980 x2 (vehicle load UI).
 */

// Ghidra-shaped twin kept in FUN_00845360.cpp.
// This file is the role-named plate for registry / port notes.

int UI_AppendItemRequirements(int *uiText, char showFlag /* item in EAX at call */)
{
  /* See FUN_00845360.cpp for full decompiler-faithful body.
   * Role summary only — do not diverge CF from raw. */
  return FUN_00845360(uiText, showFlag);
}
