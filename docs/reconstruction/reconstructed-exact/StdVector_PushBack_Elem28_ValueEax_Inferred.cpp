// =============================================================================
// StdVector_PushBack_Elem28_ValueEax_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00469c80
// Address:   0x00469c80–0x00469d04 exclusive (132 B / 0x84)
// Module:    autoassault.exe @ 0x400000
// System:    MSVC vector::push_back, POD elem 0x1c
// Wave:      W37-C OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving from decompile + full-body read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Append one POD-0x1c element. If spare capacity, uninit-fill one slot at
//   end and advance end; else grow via insert-one-at-end (rebind) helper.
//
// ABI (register — not thiscall):
//   ECX = StdVectorElem28* vec
//   EAX = const Elem28* value
//   bare RET (C3)
//
// Distinct from StdVector_PushBack_RcElem28 (0x00460f90): that uses EAX=vec,
// ECX=value and RC fill-n / insert-one family.
//
// Callees:
//   0x0046a260 StdUninitFillN_Elem28_CountEcx_Inferred (W36-M)
//   0x00469e20 StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred (W36-Q)
//
// Ghidra: FUN_00469c80
// Reject: Named_CalleeOf_*assPackManag*_00469c80
//

#include <cstdint>

struct Elem28 {
  uint32_t w[7];
};
static_assert(sizeof(Elem28) == 0x1c, "Elem28 stride");

struct StdVectorElem28 {
  void* unknown0;     // +0x00
  Elem28* begin;      // +0x04
  Elem28* end;        // +0x08
  Elem28* cap_end;    // +0x0c
};

// W36-M: ECX=count, EAX=dest*, EBX=template*; bare RET
extern "C" void StdUninitFillN_Elem28_CountEcx_Inferred(
    uint32_t count, /*ECX*/
    Elem28* dest,   /*EAX*/
    const Elem28* tmpl /*EBX*/);

// W36-Q: EDI=vec*, stack (outIt*, where, value*); RET 0xC
extern "C" Elem28** StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred(
    StdVectorElem28* vec, /*EDI*/
    Elem28** outIt,
    Elem28* where,
    const Elem28* value);

// Portable semantic equivalent of register ABI.
extern "C" void StdVector_PushBack_Elem28_ValueEax_Inferred(
    StdVectorElem28* vec,   /* ECX → EDI */
    const Elem28* value)    /* EAX → EBX */
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
      // retail: ECX=1, EAX=dest, EBX=value; call 0046a260
      StdUninitFillN_Elem28_CountEcx_Inferred(1, dest, value);
      vec->end = reinterpret_cast<Elem28*>(
          reinterpret_cast<char*>(dest) + 0x1c);
      return;
    }
  }

  // Slow path: insert-one at end (may realloc); outIt discarded.
  Elem28* outIt = nullptr;
  StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred(
      vec, &outIt, vec->end, value);
  (void)outIt;
}

// Ghidra / scaffold alias
extern "C" void FUN_00469c80(StdVectorElem28* vec /*ECX*/,
                             const Elem28* value /*EAX*/)
{
  StdVector_PushBack_Elem28_ValueEax_Inferred(vec, value);
}
