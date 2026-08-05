// =============================================================================
// FUN_004a7ff0 — scaffold twin of StdVector_InsertOne_RebindIt_BasicStringW
// -----------------------------------------------------------------------------
// Stable ID: aa_004a7ff0
// Address:   0x004a7ff0  (autoassault.exe, image base 0x400000)
// Wave:      W37-W 2026-08-04 (scaffold twin kept; prefer named clean)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Sealed W34-R insert-n (thiscall)
extern "C" void FUN_004a7ad0(void* where, uint32_t count, const void* value);

// __thiscall; ECX=vec*; stack outIt*, where*, value*; RET 0x0C
extern "C" void FUN_004a7ff0(
    void* vec /*ECX*/,
    void** outIt,
    void* where,
    const void* value)
{
  auto* base = reinterpret_cast<uint8_t*>(vec);
  int begin = *reinterpret_cast<int*>(base + 4);
  int index;

  if (begin != 0) {
    if ((*reinterpret_cast<int*>(base + 8) - begin) / 0x1c != 0) {
      index = (reinterpret_cast<int>(where) - begin) / 0x1c;
      goto do_insert;
    }
  }
  index = 0;
do_insert:
  FUN_004a7ad0(where, 1, value);
  *outIt = reinterpret_cast<void*>(
      *reinterpret_cast<int*>(base + 4) + index * 0x1c);
}
