// =============================================================================
// StringVec_PushBack
// -----------------------------------------------------------------------------
// Stable ID: aa_004301f0
// Address:   0x004301f0–0x00430278 exclusive (136 B / 0x88, autoassault.exe base 0x400000)
// System:    std::vector<basic_string> push_back (elem stride 0x1c)
// Generated: 2026-07-29 W33-D dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Nested FUN_00431700 unowned.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004301f0
// Reject:    Named_CalleeOf_*VOG_DEBUG*_004301f0 (scaffold)
// =============================================================================
//
// PURPOSE:
//   Append one basic_string (sizeof 0x1c) to a StringVecShell.
//   If the buffer has spare capacity, construct in place at end via FUN_00431700
//   and bump end by 0x1c. Otherwise fall through to StringVec_InsertOne at end
//   (FUN_00430310 / W32-A), which may reallocate via FUN_004306b0 (W32-B).
//
// ABI (bytes):
//   __thiscall ECX = StringVecShell*
//   stack: value (const basic_string* / void*)
//   RET 0x04 (C2 04 00); void
//
// Shell fields:
//   +0x04 begin, +0x08 end, +0x0c capEnd
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;   // +0x00
  uint8_t* begin;  // +0x04
  uint8_t* end;    // +0x08
  uint8_t* capEnd; // +0x0c
};

// Unowned: construct `count` basic_string copies at dest (cdecl; count here always 1)
extern "C" void FUN_00431700(uint8_t* dest, int count, const void* value_string);

// Owned W32-A: insert one + rebind out-iterator
extern "C" void __thiscall StringVec_InsertOne(StringVecShell* self,
                                               uint8_t** out_iterator,
                                               uint8_t* pos,
                                               const void* value_string);

static constexpr uint32_t kElemStride = 0x1cu;

// Retail: thiscall; ret 4
extern "C" void __thiscall StringVec_PushBack(StringVecShell* self,
                                              const void* value_string)
{
  uint8_t* begin = self->begin;
  uint32_t size = 0;
  if (begin != nullptr) {
    // (end - begin) / 0x1c  — retail uses imul magic 0x92492493
    size = static_cast<uint32_t>(self->end - begin) / kElemStride;
  }

  if (begin != nullptr) {
    const uint32_t cap =
        static_cast<uint32_t>(self->capEnd - begin) / kElemStride;
    if (size < cap) {
      uint8_t* end = self->end;
      FUN_00431700(end, /*count=*/1, value_string);
      self->end = end + kElemStride;
      return;
    }
  }

  // Capacity miss or null buffer: insert at end (may grow)
  uint8_t* out_unused = nullptr;
  StringVec_InsertOne(self, &out_unused, self->end, value_string);
}

// Scaffold alias
extern "C" void __thiscall FUN_004301f0(StringVecShell* self,
                                        const void* value_string)
{
  StringVec_PushBack(self, value_string);
}
