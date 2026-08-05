// Twin of StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred.cpp
// Stable ID: aa_00411180  VA: 0x00411180
// See named clean for full plate + semantics.

#include <cstdint>

struct StdVectorDword {
  uint32_t _pad0;
  uint32_t* begin;
  uint32_t* end;
  uint32_t* cap_end;
};

extern "C" void FUN_0040b6d0(uint32_t* end, const uint32_t* value);

// Ghidra name retained for xref continuity.
extern "C" void FUN_00411180(StdVectorDword* vec /*EAX*/,
                             const uint32_t* value /*ESI*/)
{
  uint32_t* begin = vec->begin;
  uint32_t size = 0;
  if (begin != nullptr) {
    size = static_cast<uint32_t>(vec->end - begin);
  }

  if (begin != nullptr) {
    uint32_t cap = static_cast<uint32_t>(vec->cap_end - begin);
    if (size < cap) {
      uint32_t* end = vec->end;
      *end = *value;
      vec->end = end + 1;
      return;
    }
  }

  FUN_0040b6d0(vec->end, value);
}
