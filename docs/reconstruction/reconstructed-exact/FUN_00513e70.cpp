// =============================================================================
// Item_IsStackEligible  (FUN_00513e70)
// -----------------------------------------------------------------------------
// Stable ID: aa_00513e70
// Address:   0x00513e70  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; dual residual refine 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Stack-merge / stack-display eligibility probe (NOT stack capacity).
// Stable ID: aa_00513e70
//
// Returns 1 iff:
//   typeClass(holder+0x38) == 4
//   OR ( (cloneblob+0x3f2 & 0x40) != 0  AND  ItemFlag_Broken clear at item+0x17c bit19 )
//
// Related (not this unit):
//   - Stack capacity: FUN_0040abf0 @ 0x0040abf0
//   - Broken setter:  FUN_00513de0 @ 0x00513de0
//
// Dual: docs/reconstruction/reviews/A|B_aa_00513e70_Item_IsStackEligible.md
// Residual: docs/reconstruction/reviews/a_00513e70.md

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines; 0x34 bytes asm.
//  - Control keywords: return×2, if×1.
//  - Notable callees: none.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile + read_memory 2026-07-29; live body ≡ raw 2026-07-23.
 * - Calling convention: single arg in ECX (item*); plain ret.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

#include <cstdint>

// item: CVOG cloned inventory object (ECX)
// returns: 1 eligible for stack-oriented client paths; 0 otherwise
std::uint32_t /* bool */ __fastcall Item_IsStackEligible(int item)
{
  // Ghidra name retained for xref: FUN_00513e70
  if ((((*(std::uint8_t *)(*(int *)(*(int *)(item + 0xa8) + 0x3c) + 0x3f2) & 0x40) == 0) ||
       ((*(std::uint32_t *)(item + 0x17c) >> 0x13 & 1) != 0)) &&
      (*(int *)(*(int *)(item + 0xa8) + 0x38) != 4)) {
    return 0;
  }
  return 1;
}

// Compatibility alias (scaffold name)
std::uint32_t /* bool */ __fastcall FUN_00513e70(int param_1)
{
  return Item_IsStackEligible(param_1);
}
