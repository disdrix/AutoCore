// =============================================================================
// FUN_0055e1e0  (clean twin of SoftCastHitList_ControllerFillWrapper_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e1e0
// Address:   0x0055e1e0 – 0x0055e21f inclusive (64 B / 0x40)
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 R11-003 OWN dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite. Not modernization.
//            Bit-for-bit vs retail EXE: DEFERRED.
// Named twin: SoftCastHitList_ControllerFillWrapper_Inferred.cpp
// =============================================================================
//
// Scaffold note: 2026-07-23 auto CF used decompiler free-call shape of
// FUN_006ca890 and omitted local-entry + vtbl install. Assembly-corrected.
// =============================================================================

#include <cstdint>

struct SoftCastHitEntry {
  void *vtbl;
  uint32_t *soft_desc;
  int related_plus_14;
  uint32_t hit_list_backref;
  uint32_t field_10;
  uint32_t desc_field_24; // +0x40
  int related_plus_10;    // +0x44
};

extern void __thiscall SoftCastHitList_CoreFillAndRegister_Inferred(
    SoftCastHitEntry *entry,
    void *manager,
    uint32_t *soft_desc,
    int related_obj,
    uint32_t query_payload,
    uint32_t hit_list_backref);

// Ghidra symbol kept as export alias of the named unit.
void __thiscall FUN_0055e1e0(void *controller,
                             uint32_t *soft_desc,
                             uint32_t hit_list_backref)
{
  SoftCastHitEntry local_entry;

  void *manager =
      *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(controller) + 0xC4);
  int related =
      *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(controller) + 0xD0);

  local_entry.vtbl = reinterpret_cast<void *>(0x009D27A8u);
  local_entry.related_plus_10 = 0;

  SoftCastHitList_CoreFillAndRegister_Inferred(
      &local_entry,
      manager,
      soft_desc,
      related,
      0,
      hit_list_backref);
}
