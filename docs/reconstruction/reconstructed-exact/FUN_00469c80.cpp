// =============================================================================
// FUN_00469c80 — twin of StdVector_PushBack_Elem28_ValueEax_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00469c80
// Address:   0x00469c80–0x00469d04 exclusive (132 B)
// Wave:      W37-C 2026-08-04
// See:       StdVector_PushBack_Elem28_ValueEax_Inferred.cpp (canonical clean)
// =============================================================================

#include <cstdint>

struct Elem28 {
  uint32_t w[7];
};

struct StdVectorElem28 {
  void* unknown0;
  Elem28* begin;
  Elem28* end;
  Elem28* cap_end;
};

extern "C" void StdUninitFillN_Elem28_CountEcx_Inferred(uint32_t count,
                                                        Elem28* dest,
                                                        const Elem28* tmpl);
extern "C" Elem28** StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred(
    StdVectorElem28* vec, Elem28** outIt, Elem28* where, const Elem28* value);

// ABI: ECX=vec*, EAX=value*; bare RET
extern "C" void FUN_00469c80(StdVectorElem28* vec /*ECX*/,
                             const Elem28* value /*EAX*/)
{
  Elem28* begin = vec->begin;
  uint32_t size = 0;
  if (begin != nullptr) {
    size = static_cast<uint32_t>(
        (reinterpret_cast<const char*>(vec->end) -
         reinterpret_cast<const char*>(begin)) /
        0x1c);
  }
  if (begin != nullptr) {
    const uint32_t cap = static_cast<uint32_t>(
        (reinterpret_cast<const char*>(vec->cap_end) -
         reinterpret_cast<const char*>(begin)) /
        0x1c);
    if (size < cap) {
      Elem28* dest = vec->end;
      StdUninitFillN_Elem28_CountEcx_Inferred(1, dest, value);
      vec->end = reinterpret_cast<Elem28*>(
          reinterpret_cast<char*>(dest) + 0x1c);
      return;
    }
  }
  Elem28* outIt = nullptr;
  StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred(
      vec, &outIt, vec->end, value);
  (void)outIt;
}
