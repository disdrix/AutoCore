// =============================================================================
// FUN_0051d150
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d150
// Address:   0x0051d150  (autoassault.exe, image base 0x400000)
// System:    container / missions-progression (medal CNDHash)
// Generated: 2026-07-29 W24-H dual A/B (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// PURPOSE: Zero count, reclaim all hash nodes to freelist, free bucket table.
// Named plate: CNDHash_FreeBuckets.cpp

#include <cstdint>
#include <cstdlib>

void __fastcall FUN_0051d150(int param_1)
{
  // ECX/this = param_1 (mov esi,ecx)
  *(uint32_t *)(param_1 + 0xc) = 0;           // count = 0
  FUN_0051bfb0();                             // reclaim nodes (this in ECX)
  if (*(uint32_t **)(param_1 + 0x10) != 0) {
    free((void *)**(uint32_t **)(param_1 + 0x10)); // free sentinel slab
    operator_delete__(*(void **)(param_1 + 0x10)); // delete[] pointer table
    *(uint32_t *)(param_1 + 0x10) = 0;
  }
  return;
}
