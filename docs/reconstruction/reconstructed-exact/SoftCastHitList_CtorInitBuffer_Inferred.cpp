// =============================================================================
// SoftCastHitList_CtorInitBuffer_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c410
// Address:   0x0040c410 – 0x0040c4df inclusive (208 B / 0xD0)
// Module:    autoassault.exe (image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-111 OWN dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler + assembly CF.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0040c410
// =============================================================================
//
// PURPOSE
//   Construct / initialize the soft-cast hit-list container used by
//   Client_InteractWorldClickHub before soft-cast fill + optional sort + walk:
//     - install class vtbl (temp base then final)
//     - zero count, point begin at inline storage, mark capacity 8 as inline
//     - seed 8×0x30 elements: float key @ +0x14 = 1.0f, object slot @ +0x20 = 0
//
// ABI (sealed)
//   stdcall: stack SoftCastHitList* self (NOT ECX-this)
//   void return; RET 4 (C2 04 00)
//   SEH frame (handler 0x009bd03d); leaf (no callees)
//
// LAYOUT (this)
//   +0x00  void*  vtbl  (final PTR_LAB_00a2f538)
//   +0x04  float  default 1.0f
//   +0x10  void*  array_base  (= this+0x20 inline)
//   +0x14  int    count       (= 0)
//   +0x18  int    capacity    (= 0x80000008  → 8 | high-bit inline)
//   +0x20  SoftCastHit[8]     elem size 0x30
//     elem+0x14  float sort key seed 1.0f
//     elem+0x20  void* object/slot seed 0
//
// RELATED (not dualed here)
//   Sort gate: SoftCastHitList_SortIfCountGt1_Inferred @ 0x0048a060 (MEGA-116)
//   Dtor:      FUN_0040c510 (frees only if capacity signed >= 0)
//   Hub:       Client_InteractWorldClickHub @ 0x00925820 (sole caller)
// =============================================================================

#include <cstdint>

// External constants / vtbls (image addresses; names from Ghidra symbols).
extern "C" float g_flOne;                 // DAT_00a0f2a0 = 1.0f
extern "C" void *PTR_LAB_00a2f52c;         // base/temp vtbl
extern "C" void *PTR_LAB_00a2f538;         // SoftCastHitList final vtbl

struct SoftCastHit {
  uint8_t _pad_00[0x14];
  float key;           // +0x14  sort key (seeded 1.0f)
  uint8_t _pad_18[0x08];
  void *object_or_slot; // +0x20  resolved later by hub walk
  uint8_t _pad_24[0x0C];
};
static_assert(sizeof(SoftCastHit) == 0x30, "hit elem stride");

struct SoftCastHitList {
  void *vtbl;              // +0x00
  float default_float;     // +0x04
  uint32_t _pad_08[2];     // +0x08 .. +0x0C
  SoftCastHit *array_base; // +0x10
  int count;               // +0x14
  int capacity_word;       // +0x18  (low 31 = cap, bit31 = inline sentinel)
  SoftCastHit inline_hits[8]; // +0x20
};

// Stack self*; void; RET 4. SEH omitted (ephemeral construction only).
void __stdcall SoftCastHitList_CtorInitBuffer_Inferred(SoftCastHitList *self)
{
  const float one = g_flOne;

  // Temp base vtbl then final class vtbl (same pattern as MSVC phased ctor).
  self->vtbl = &PTR_LAB_00a2f52c;
  self->default_float = one;
  self->vtbl = &PTR_LAB_00a2f538;

  // Vector-like header over inline storage.
  self->array_base = &self->inline_hits[0]; // self+0x20
  self->count = 0;
  self->capacity_word = static_cast<int>(0x80000008u); // cap 8 | inline bit

  // Seed all 8 inline slots (assembly uses 0x30 pointer walk; order preserved).
  for (int i = 0; i < 8; ++i) {
    self->inline_hits[i].key = one;
    self->inline_hits[i].object_or_slot = nullptr;
  }

  // Epilog reasserts (present in bytes; keep for exact store order fidelity).
  self->count = 0;
  self->default_float = one;
}
