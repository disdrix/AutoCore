// =============================================================================
// FUN_008c2f50  (scaffold alias → Client_TryInventoryAutoMergePartialStacks_Notify)
// -----------------------------------------------------------------------------
// Stable ID: aa_008c2f50
// Address:   0x008c2f50  (autoassault.exe, image base 0x400000)
// System:    client / inventory-transfer notify
// Generated: 2026-07-29 W30-N dual seal
// Exactness: Behavior-preserving; see named clean for authority.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" uint8_t Client_TryInventoryAutoMergePartialStacks_Notify(void* host);

extern "C" uint8_t FUN_008c2f50(void* host)
{
  return Client_TryInventoryAutoMergePartialStacks_Notify(host);
}
