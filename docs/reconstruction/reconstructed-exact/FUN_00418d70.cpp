// =============================================================================
// FUN_00418d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00418d70
// Address:   0x00418d70  (autoassault.exe, image base 0x400000)
// Body:      0x00418d70–0x00418dc6 exclusive (86 B / 0x56)
// System:    util / container (std::vector elem stride 8)
// Generated: 2026-08-05 R10-025 dual seal twin of named plate
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named:     StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred
// Dual A/B:  accept-with-gaps (2026-08-05)
// =============================================================================

#include <cstdint>

extern "C" void FUN_00418e10(
    void* vec /*ECX*/,
    void** outIt,
    void* where,
    const void* value);

// Ghidra twin — same body as named plate.
extern "C" void FUN_00418d70(void* vec /*ECX*/, const uint32_t* value /*stack*/)
{
  int begin = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 4);
  unsigned size;
  if (begin == 0) {
    size = 0;
  } else {
    size = static_cast<unsigned>(
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) - begin) >> 3);
  }

  if (begin != 0) {
    unsigned capacity = static_cast<unsigned>(
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 0xc) - begin) >> 3);
    if (size < capacity) {
      uint32_t* end =
          *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(vec) + 8);
      end[0] = value[0];
      end[1] = value[1];
      *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(vec) + 8) = end + 2;
      return;
    }
  }

  void* outScratch = const_cast<uint32_t*>(value);
  void* end = *reinterpret_cast<void**>(reinterpret_cast<char*>(vec) + 8);
  FUN_00418e10(vec, &outScratch, end, value);
}
