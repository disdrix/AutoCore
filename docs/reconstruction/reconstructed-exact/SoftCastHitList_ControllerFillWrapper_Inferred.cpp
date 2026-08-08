// =============================================================================
// SoftCastHitList_ControllerFillWrapper_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e1e0
// Address:   0x0055e1e0 – 0x0055e21f inclusive (64 B / 0x40)
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 R11-003 OWN dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler + assembly CF.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0055e1e0
// =============================================================================
//
// PURPOSE
//   Thin **controller → soft-cast hit-entry fill** wrapper used by
//   Client_InteractWorldClickHub after SoftCastHitList_CtorInitBuffer and
//   before SoftCastHitList_SortIfCountGt1.
//
//   Builds a stack SoftCastHitEntry with vtbl 0x009D27A8, pulls manager and
//   optional related object from the controller, hard-codes query payload 0,
//   and dispatches SoftCastHitList_CoreFillAndRegister_Inferred.
//
// ABI (sealed)
//   thiscall: ECX = controller*
//   2 stack formals; RET 0x8 (C2 08 00)
//   void return (no EAX contract)
//
// CONTROLLER READS
//   +0xC4  manager*  (passed to core as stack0; used for vtbl+0x30 register)
//   +0xD0  related   (may be null; core null-safe)
//
// LOCAL ENTRY
//   +0x00  vtbl = 0x009D27A8
//   +0x44  pre-zeroed before core (core rewrites on all arms)
//
// ODD BEHAVIOR PRESERVED
//   - Decompiler drops local-entry construction; retail always installs vtbl
//     and sets ECX=&entry before CALL 0x006ca890.
//   - Query payload always hard 0 (never forwarded from hub).
//   - 16-byte stack alignment before local entry (AND ESP,~0xF; SUB ESP,0x50).
//   - Pre-zero of entry+0x44 is redundant with core but present in bytes.
//
// READABILITY
//   - Named core callee is dualed MEGA-062; kept as extern with sealed ABI.
//   - Controller type left opaque (product English open).
// =============================================================================

#include <cstdint>

struct SoftCastHitEntry {
  void *vtbl;                 // +0x00 installed here
  uint32_t *soft_desc;        // +0x04 written by core
  int related_plus_14;        // +0x08 written by core
  uint32_t hit_list_backref;  // +0x0C written by core
  uint32_t field_10;          // +0x10 written by core
  // ... intervening fields not written by this unit ...
  uint32_t desc_field_24;     // +0x40 written by core when flag set
  int related_plus_10;        // +0x44 pre-zero here; rewritten by core
};

// Dualed MEGA-062 — ECX = entry; 5 stack args; RET 0x14
extern void __thiscall SoftCastHitList_CoreFillAndRegister_Inferred(
    SoftCastHitEntry *entry,
    void *manager,
    uint32_t *soft_desc,
    int related_obj,
    uint32_t query_payload,
    uint32_t hit_list_backref);

// Soft-cast hit entry vtbl installed by this wrapper (method map open).
static constexpr uintptr_t kSoftCastHitEntryVtbl = 0x009D27A8u;

// ECX = controller*; RET 0x8
void __thiscall SoftCastHitList_ControllerFillWrapper_Inferred(
    void *controller,
    uint32_t *soft_desc,
    uint32_t hit_list_backref)
{
  // Retail: AND ESP,~0xF; SUB ESP,0x50 — 16-byte-aligned local frame.
  SoftCastHitEntry local_entry;

  void *manager =
      *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(controller) + 0xC4);
  int related =
      *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(controller) + 0xD0);

  local_entry.vtbl = reinterpret_cast<void *>(kSoftCastHitEntryVtbl);
  local_entry.related_plus_10 = 0; // [ESP+0x58] relative to post-push ESP

  SoftCastHitList_CoreFillAndRegister_Inferred(
      &local_entry,
      manager,
      soft_desc,
      related,
      /*query_payload=*/0,
      hit_list_backref);
}
