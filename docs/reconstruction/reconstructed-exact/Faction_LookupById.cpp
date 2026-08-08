// =============================================================================
// Faction_LookupById
// -----------------------------------------------------------------------------
// Stable ID: aa_0051a120
// Address:   0x0051a120  (autoassault.exe, image base 0x400000)
// System:    game-data / faction table
// Dual:      WQ9R-G 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Look up a faction table record by integer faction id in the global hash
//   (DAT_00b0431c mask / DAT_00b04324 buckets / DAT_00b04320 ready). Lazy-inits
//   the table via FUN_005197b0 when ready==0. Returns record pointer at node+8,
//   or NULL on negative id / miss.
//
// ABI:
//   cdecl — one stack formal (uint factionId); bare RET (caller cleans).
//
// CALLER SEAL:
//   FUN_00614380 miss → "UNDEFINED FACTION: %i"
//   FUN_00612df0 miss → "UNKNOWN: %i"
//   Hit path uses display name at record+4; *record used as type discriminator.
//
// NOT skill-bank: nearby FUN_00519d20 / FUN_0051a0e0 are sibling game-data
// lookups with different globals; this unit is faction-only.
// =============================================================================

#include <cstdint>

extern "C" {
  void FUN_005197b0(void); // faction table loader (WQ9R-F)

  extern uint32_t DAT_00b0431c; // bucket mask
  extern uint32_t DAT_00b04320; // ready / count (0 ⇒ load)
  extern uint32_t DAT_00b04324; // bucket table base
}

// Node: key@+0x10, next@+0x0C, value@+0x08
struct FactionHashNode {
  // … other fields …
  // layout sealed by walk offsets only:
  // +0x08 value*, +0x0C next*, +0x10 key(u32)
};

void* Faction_LookupById(uint32_t factionId)
{
  if ((int32_t)factionId < 0) {
    return nullptr;
  }

  if (DAT_00b04320 == 0) {
    FUN_005197b0();
  }

  // bucket = *(DAT_00b04324 + (mask & id) * 4); node = *(bucket + 4)
  uint32_t* bucketPtr =
      *(uint32_t**)(DAT_00b04324 + (DAT_00b0431c & factionId) * 4);
  uint8_t* node = (uint8_t*)bucketPtr[1]; // +4

  if (node == nullptr) {
    return nullptr;
  }

  while (factionId != *(uint32_t*)(node + 0x10)) {
    node = *(uint8_t**)(node + 0x0C);
    if (node == nullptr) {
      return nullptr;
    }
  }

  // node non-null after match (and after empty-bucket gate)
  return *(void**)(node + 0x08);
}
