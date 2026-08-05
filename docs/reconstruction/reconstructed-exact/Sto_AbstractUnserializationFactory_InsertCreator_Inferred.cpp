// =============================================================================
// Sto_AbstractUnserializationFactory_InsertCreator_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004449b0
// Address:   0x004449b0–0x00444a35  (autoassault.exe, image base 0x400000)
// System:    arda2/storage — stoAbstractUnserializationFactory (map A)
// Generated: 2026-07-23 scaffold as FUN_004449b0; dual A/B seal 2026-07-29 (W36-A)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Register a creator function for a FourCC tag in UnserialFactory **map A**
//   (NestedHash via Sto_UnserialFactoryMapA_GetInstance_Inferred / FUN_00438c40).
//
//   1. Lookup tag in map A.
//   2. If present (node != map.sentinel): vog_LogMessage duplicate-tag warning
//      (plate stoAbstractUnserializationFactory.h line 0x24, level 2).
//   3. Lookup again; if missing: NestedHash insert {tag, 0}.
//   4. Always store creator fn* from **EBX** at **node+0x0c**.
//
// ABI (bytes):
//   cdecl; stack arg0 = uint32 FourCC tag; **EBX** = creator fn* (register input).
//   plain RET after ADD ESP,0x10. Body 134 B. Callers PUSH tag; MOV EBX,imm; CALL;
//   ADD ESP,4; they save/restore EBX around the call.
//
// CALLEES:
//   FUN_00438c40  MapA GetInstance (×3)
//   FUN_0046c1b0  NestedHash lookup (ESI=map, ECX=key*, EAX=out*) — unowned W36-B
//   FUN_0046bf90  NestedHash insert (EDI=map) — unowned W36-B
//   vog_LogMessage
//
// CALLERS (3 thin wrappers):
//   FUN_004448b0  tag 0x47504345 ('GPCE') creator 0x00444d00
//   FUN_004448d0  tag 0x47534b4e ('GSKN') creator 0x00444d60
//   FUN_004448f0  tag 0x474d5048 ('GMPH') creator 0x00444dc0
//
// SIBLING (not this VA): FUN_00444a40 — MapB insert (W36-C)
// REJECT scaffold: Named_CalleeOf_Named_CalleeOf_Named_Palantir_004449b0
//

#include <cstdint>

struct NestedHash_Sentinel0x10;
struct NestedHashNode0x10 {
  NestedHashNode0x10* next;     // +0x00 (family)
  NestedHashNode0x10* prev;     // +0x04
  uint32_t            key;      // +0x08  FourCC
  void*               creator;  // +0x0c  fn*
}; // 0x10

using CreatorFn = void* (*)(void); // sample creators: operator_new + ctor, 0 stack args

// Sealed MapA getter (W35-D)
extern "C" NestedHash_Sentinel0x10*
Sto_UnserialFactoryMapA_GetInstance_Inferred(void); // FUN_00438c40

// Unowned map ops (W36-B) — signatures approximate from call sites
extern "C" void FUN_0046c1b0(void); // ESI=map, ECX=key*, EAX=node**
extern "C" void* FUN_0046bf90(void* out_pair, uint32_t* key_pair); // EDI=map

extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);

// Retail: cdecl; tag on stack; creator in EBX
extern "C" void
Sto_AbstractUnserializationFactory_InsertCreator_Inferred(
    uint32_t tag /* stack */,
    CreatorFn creator_ebx /* register EBX — not a C++ param at ABI level */)
{
  // --- byte-faithful outline (locals match 0x10 frame + ESI/EDI saves) ---
  NestedHash_Sentinel0x10* map =
      Sto_UnserialFactoryMapA_GetInstance_Inferred();
  NestedHashNode0x10* sentinel =
      *reinterpret_cast<NestedHashNode0x10**>(
          reinterpret_cast<char*>(map) + 0x08);

  map = Sto_UnserialFactoryMapA_GetInstance_Inferred();
  NestedHashNode0x10* found = nullptr;
  // FUN_0046c1b0: ESI=map, ECX=&tag, EAX=&found
  (void)map;
  (void)tag;
  // found = NestedHash_Lookup(map, tag);

  if (found != sentinel) {
    vog_LogMessage(
        "..\\arda2/storage/stoAbstractUnserializationFactory.h",
        0x24,
        2,
        "Inserting duplicate creator tag to factory");
  }

  map = Sto_UnserialFactoryMapA_GetInstance_Inferred();
  // found = NestedHash_Lookup(map, tag);
  if (found == *reinterpret_cast<NestedHashNode0x10**>(
                   reinterpret_cast<char*>(map) + 0x08)) {
    uint32_t key_pair[2] = { tag, 0 };
    uint8_t out_pair[8];
    // EDI = map; FUN_0046bf90(out_pair, key_pair)
    void* result = FUN_0046bf90(out_pair, key_pair);
    found = *reinterpret_cast<NestedHashNode0x10**>(result);
  }

  // always (re)bind creator — MOV [EAX+0xC], EBX
  found->creator = reinterpret_cast<void*>(creator_ebx);
}
