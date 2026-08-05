// =============================================================================
// StringVec_Tidy
// -----------------------------------------------------------------------------
// Stable ID: aa_00431ae0
// Address:   0x00431ae0–0x00431b27 exclusive (71 B / 0x47, autoassault.exe base 0x400000)
// System:    std::vector<basic_string> tidy / buffer release (elem stride 0x1c)
// Generated: 2026-07-29 W33-D dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Bytes win over decompiler post-delete.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00431ae0
// Reject:    Named_CalleeOf_*assManager*_00431ae0 (scaffold)
// =============================================================================
//
// PURPOSE:
//   Release a StringVecShell buffer: destroy every live basic_string in
//   [begin, end), free the buffer, and null begin/end/capEnd.
//   Null begin is an idempotent tidy (still writes zeros).
//
//   Sibling FUN_00431aa0 destroys a half-open range only (no free/null) and is
//   used during reallocation; this unit is the full tidy path.
//
// ABI (bytes):
//   ECX = StringVecShell*  (thiscall / single-arg fastcall-this)
//   no stack formals; bare RET (C3); void
//
// Thunk: 0x00431ad0 JMP 0x00431ae0
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;   // +0x00
  uint8_t* begin;  // +0x04  basic_string elements as bytes
  uint8_t* end;    // +0x08
  uint8_t* capEnd; // +0x0c
};

// Retail IAT ~basic_string(thiscall ECX=elem)
extern "C" void __thiscall BasicString_Dtor(void* self);

// CRT free
extern "C" void operator_delete(void* p);

static constexpr uint32_t kElemStride = 0x1cu;

// Retail: ECX=self; bare ret
extern "C" void __fastcall StringVec_Tidy(StringVecShell* self)
{
  uint8_t* begin = self->begin;
  if (begin == nullptr) {
    self->begin = nullptr;
    self->end = nullptr;
    self->capEnd = nullptr;
    return;
  }

  uint8_t* end = self->end;
  for (uint8_t* p = begin; p != end; p += kElemStride) {
    BasicString_Dtor(p);
  }

  operator_delete(begin);

  self->begin = nullptr;
  self->end = nullptr;
  self->capEnd = nullptr;
}

// Scaffold alias (Ghidra name)
extern "C" void __fastcall FUN_00431ae0(StringVecShell* self)
{
  StringVec_Tidy(self);
}
