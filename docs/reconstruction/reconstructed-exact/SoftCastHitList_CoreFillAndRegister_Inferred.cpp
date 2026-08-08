// =============================================================================
// SoftCastHitList_CoreFillAndRegister_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_006ca890
// Address:   0x006ca890 – 0x006ca93b inclusive (172 B / 0xAC)
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-062 OWN dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler + assembly CF.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_006ca890
// =============================================================================
//
// PURPOSE
//   Soft-cast hit-list **core fill + register**: initialize a hit-entry object
//   from a soft-cast descriptor (and optional related object), pack a 16-byte-
//   aligned query packet, and dispatch manager->vtbl[+0x30](&query, entry, 0).
//
//   Sole retail caller: thin wrapper FUN_0055e1e0 (local entry + vtbl
//   0x009d27a8), itself called from dualed Client_InteractWorldClickHub
//   (0x00925820) after hit-list init FUN_0040c410 and before sort gate
//   SoftCastHitList_SortIfCountGt1_Inferred (0x0048a060).
//
// ABI (sealed)
//   thiscall: ECX = SoftCastHitEntry* (entry being filled)
//   5 stack formals; RET 0x14 (C2 14 00)
//   void return (no EAX contract)
//
// ENTRY WRITES (this)
//   +0x04  soft_desc*
//   +0x08  related ? related+0x14 : 0
//   +0x0C  hit_list_backref (param_6)
//   +0x10  0
//   +0x40  soft_desc[+0x24] when flag soft_desc[+0x20] != 0
//   +0x44  0 if flag==0 or related==0; else related+0x10
//
// ODD BEHAVIOR PRESERVED
//   - Parent decompile of FUN_0055e1e0 drops local-entry construction; retail
//     always builds a stack entry with vtbl 0x009d27a8 before this call.
//   - Wrapper always passes query_payload (param_5) = 0.
//   - When flag==0, entry+0x40 is left untouched (not zeroed).
//   - Stack frame forced 16-byte aligned before packing the query.
//
// READABILITY
//   - Decompiler __thiscall formals match assembly storage after RET 0x14 seal.
//   - Indirect vcall kept as raw slot +0x30 (product name open).
// =============================================================================

#include <cstdint>

struct SoftCastHitEntry {
  void *vtbl;                 // +0x00 (installed by caller; not written here)
  uint32_t *soft_desc;        // +0x04
  int related_plus_14;        // +0x08
  uint32_t hit_list_backref;  // +0x0C
  uint32_t field_10;          // +0x10
  // ... intervening fields not written by this unit ...
  uint32_t desc_field_24;     // +0x40
  int related_plus_10;        // +0x44
};

// Query packet laid out on the 16-byte-aligned frame (field order matches
// decompiler locals local_30..local_14 / assembly ESP stores).
struct SoftCastQueryPacket {
  uint32_t header0;   // soft_desc[0]
  uint32_t header1;   // soft_desc[1]
  uint32_t header2;   // soft_desc[2]
  uint32_t header3;   // soft_desc[3]
  uint32_t flag_one;  // 1
  uint32_t *ext;      // soft_desc + 0x10
  uint32_t size_10;   // 0x10
  uint32_t payload;   // param_5
};

// Manager face: first dword is vtbl*; slot +0x30 is the register/add method.
// thiscall-like: ECX = manager; stack (&query, entry, 0). Callee cleanup unknown
// at this unit (call is indirect).
using SoftCastRegisterFn = void(__thiscall *)(void *manager,
                                              SoftCastQueryPacket *query,
                                              SoftCastHitEntry *entry,
                                              int zero);

// ECX = entry; RET 0x14
void __thiscall SoftCastHitList_CoreFillAndRegister_Inferred(
    SoftCastHitEntry *entry,
    void *manager,
    uint32_t *soft_desc,
    int related_obj,
    uint32_t query_payload,
    uint32_t hit_list_backref)
{
  entry->soft_desc = soft_desc;
  entry->hit_list_backref = hit_list_backref;
  entry->field_10 = 0;

  if (related_obj == 0) {
    entry->related_plus_14 = 0;
  } else {
    entry->related_plus_14 = related_obj + 0x14;
  }

  // soft_desc flag byte @ +0x20  (decompiler: *(char *)(soft_desc + 8) on dword*)
  if (*reinterpret_cast<const char *>(
          reinterpret_cast<const uint8_t *>(soft_desc) + 0x20) == '\0') {
    entry->related_plus_10 = 0;
    // note: entry->desc_field_24 (+0x40) not written when flag is clear
  } else if (related_obj == 0) {
    entry->related_plus_10 = 0;
    entry->desc_field_24 = soft_desc[9]; // soft_desc + 0x24
  } else {
    entry->related_plus_10 = related_obj + 0x10;
    entry->desc_field_24 = soft_desc[9];
  }

  SoftCastQueryPacket query;
  query.header0 = soft_desc[0];
  query.header1 = soft_desc[1];
  query.header2 = soft_desc[2];
  query.header3 = soft_desc[3];
  query.ext = soft_desc + 4; // soft_desc + 0x10
  query.payload = query_payload;
  query.flag_one = 1;
  query.size_10 = 0x10;

  void **vtbl = *reinterpret_cast<void ***>(manager);
  auto register_fn = reinterpret_cast<SoftCastRegisterFn>(vtbl[0x30 / 4]);
  // Retail: PUSH 0; PUSH entry; PUSH &query; CALL [vtbl+0x30] with ECX=manager
  register_fn(manager, &query, entry, 0);
}
