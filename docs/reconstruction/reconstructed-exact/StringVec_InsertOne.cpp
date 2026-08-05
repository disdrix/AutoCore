// =============================================================================
// StringVec_InsertOne
// -----------------------------------------------------------------------------
// Stable ID: aa_00430310
// Address:   0x00430310–0x00430383 exclusive (115 B / 0x73, autoassault.exe base 0x400000)
// System:    std::vector<basic_string> insert-one (elem stride 0x1c)
// Generated: 2026-07-29 W32-A dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Nested FUN_004306b0 unowned (W32-B).
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00430310
// Reject:    Named_CalleeOf_*VOG_DEBUG*_00430310 (scaffold)
// =============================================================================
//
// PURPOSE:
//   Insert exactly one basic_string (sizeof 0x1c) into a StringVecShell at the
//   given iterator position, then write back an iterator to the inserted slot.
//   Index is computed as (pos - begin) / 0x1c when the vector is non-empty;
//   otherwise 0. After FUN_004306b0 may reallocate, the out-iterator is rebuilt
//   as begin' + index * 0x1c so it remains valid.
//
//   Callers:
//     FUN_00969830 — insert at begin (push_front of normalized path)
//     FUN_004301f0 — insert at end when capacity exhausted (push_back fallback)
//
// ABI (bytes):
//   __thiscall ECX = StringVecShell*
//   stack: out_iterator*, pos (byte*), value (basic_string*)
//   RET 0x0C (C2 0C 00); void (out via *out_iterator)
//
// Shell fields used here:
//   +0x04 begin, +0x08 end  (cap +0x0c used inside FUN_004306b0 only)
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;   // +0x00
  uint8_t* begin;  // +0x04  basic_string elements as bytes
  uint8_t* end;    // +0x08
  // uint8_t* cap; // +0x0c — used by FUN_004306b0 grow path
};

// Unowned: insert N copies of value at pos (thiscall; count here always 1)
extern "C" void __thiscall FUN_004306b0(StringVecShell* self,
                                        uint8_t* pos,
                                        uint32_t count,
                                        const void* value_string);

static constexpr uint32_t kElemStride = 0x1cu;

// Retail: thiscall; ret 12
extern "C" void __thiscall StringVec_InsertOne(StringVecShell* self,
                                               uint8_t** out_iterator,
                                               uint8_t* pos,
                                               const void* value_string)
{
  uint32_t index = 0;
  uint8_t* begin = self->begin;
  if (begin != nullptr) {
    // (end - begin) / 0x1c != 0  →  non-empty
    if (static_cast<uint32_t>(self->end - begin) / kElemStride != 0u) {
      index = static_cast<uint32_t>(pos - begin) / kElemStride;
    }
  }

  FUN_004306b0(self, pos, /*count=*/1u, value_string);

  // Rebuild iterator after possible reallocation
  *out_iterator = self->begin + index * kElemStride;
}

// Scaffold alias
extern "C" void __thiscall FUN_00430310(StringVecShell* self,
                                        uint8_t** out_iterator,
                                        uint8_t* pos,
                                        const void* value_string)
{
  StringVec_InsertOne(self, out_iterator, pos, value_string);
}
