// =============================================================================
// StringVec_PushBackIfAbsent_EnsureTrailingDirSep
// -----------------------------------------------------------------------------
// Stable ID: aa_009697a0
// Address:   0x009697a0–0x0096982D exclusive (141 B / 0x8D, autoassault.exe base 0x400000)
// System:    StringVecShell path list — unique push_back after trailing-sep normalize
// Generated: 2026-07-29 W34-J dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Nested helpers dual-owned elsewhere.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_009697a0
// =============================================================================
//
// PURPOSE:
//   Normalize a path so it ends with a directory separator if needed
//   (FUN_009694e0 / BasicString_CopyEnsureTrailingDirSep), then append it to
//   the StringVecShell **only if** no equal element already exists (linear scan,
//   stride 0x1c, case-sensitive basic_string==).
//
// ABI (bytes):
//   EDI = StringVecShell*
//   stack formal = const basic_string* (path)
//   ret 4; void
//   SEH LAB_009acae3; local basic_string 0x1c
//
// TWINS / CALLEES:
//   FUN_009694e0 / BasicString_CopyEnsureTrailingDirSep (W32-A)
//   FUN_004301f0 / StringVec_PushBack (W33-D)
//   IAT operator==, IAT ~basic_string
//   Sibling push_front: 0x00969830 (W31-E); sibling erase: 0x009696c0
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;   // +0x00
  uint8_t* begin;  // +0x04  basic_string* as bytes
  uint8_t* end;    // +0x08
  uint8_t* capEnd; // +0x0c (used by push_back grow)
};

static constexpr uint32_t kElemStride = 0x1cu;

// Unowned / dual-owned elsewhere
extern "C" void* FUN_009694e0(void* out_string, const void* in_string);
extern "C" void __thiscall StringVec_PushBack(StringVecShell* self,
                                              const void* value_string);
extern "C" bool basic_string_eq(const void* a, const void* b); // IAT operator==
extern "C" void basic_string_dtor(void* self);                 // IAT dtor

// Retail: EDI=self, stack path*; ret 4
extern "C" void StringVec_PushBackIfAbsent_EnsureTrailingDirSep(
    StringVecShell* self /*EDI*/,
    const void* path /*stack basic_string* */)
{
  alignas(4) uint8_t local[0x1c];
  // SEH + ExceptionList omitted (structure only)

  FUN_009694e0(local, path);

  uint8_t* it  = self->begin;
  uint8_t* end = self->end;
  bool absent = (it == end);
  if (!absent) {
    do {
      if (basic_string_eq(it, local)) {
        break; // found
      }
      it += kElemStride;
    } while (it != end);
    absent = (it == end);
  }

  if (absent) {
    StringVec_PushBack(self, local);
  }

  basic_string_dtor(local);
}

// Scaffold alias
extern "C" void FUN_009697a0(const void* path /*stack; EDI=self*/)
{
  // Port note: retail requires EDI preset to the target StringVecShell.
  (void)path;
}
