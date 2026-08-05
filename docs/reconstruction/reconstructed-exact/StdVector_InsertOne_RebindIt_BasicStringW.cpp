// =============================================================================
// StdVector_InsertOne_RebindIt_BasicStringW  (aa_004a7ff0)
// -----------------------------------------------------------------------------
// Address:   0x004a7ff0–0x004a8063 exclusive (115 B / 0x73)
// Module:    autoassault.exe @ image base 0x400000
// Ghidra:    FUN_004a7ff0
// System:    MSVC vector insert-one + rebind, basic_string<wchar_t> (elem 0x1c)
// Wave:      W37-W OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving from decompile + read_memory. Not modernization.
// Bit-for-bit / runtime: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   __thiscall ECX = vector*
//   stack: outIt*, where*, value*
//   RET 0x0C; void (writes *outIt)
//
// Semantics:
//   Save insert index from (where - begin) / 0x1c when size != 0;
//   else index = 0. Call StdVector_InsertN_BasicStringW(where, 1, value).
//   Rebind *outIt = begin' + index * 0x1c (post-insert begin survives realloc).
//
// Caller: FUN_004a8100 (push_back slow path when size == capacity).
// Callee: StdVector_InsertN_BasicStringW (0x004a7ad0, W34-R).
// Name is structural (_Inferred). Reject scaffold Named_CalleeOf_*attachmentRe*.
// =============================================================================

#include <cstdint>

struct BasicStringW_0x1c {
  // MSVC basic_string<wchar_t> storage footprint (0x1c) — fields not dualed here.
  uint8_t storage[0x1c];
};

struct StdVectorBasicStringW {
  void* unknown0;                 // +0x00
  BasicStringW_0x1c* begin;       // +0x04
  BasicStringW_0x1c* end;         // +0x08
  BasicStringW_0x1c* cap_end;     // +0x0C
};

// Sealed W34-R
extern "C" void StdVector_InsertN_BasicStringW(
    StdVectorBasicStringW* vec /*ECX*/,
    BasicStringW_0x1c* where,
    uint32_t count,
    const BasicStringW_0x1c* value);

// Retail: __thiscall; RET 0x0C
extern "C" void StdVector_InsertOne_RebindIt_BasicStringW(
    StdVectorBasicStringW* vec,          /* ECX */
    BasicStringW_0x1c** outIt,           /* stack0 */
    BasicStringW_0x1c* where,            /* stack1 */
    const BasicStringW_0x1c* value)      /* stack2 */
{
  BasicStringW_0x1c* begin = vec->begin;
  uint32_t index = 0;

  if (begin != nullptr) {
    const uint32_t size = static_cast<uint32_t>(
        (reinterpret_cast<char*>(vec->end) -
         reinterpret_cast<char*>(begin)) / 0x1c);
    if (size != 0) {
      index = static_cast<uint32_t>(
          (reinterpret_cast<char*>(where) -
           reinterpret_cast<char*>(begin)) / 0x1c);
    }
  }

  StdVector_InsertN_BasicStringW(vec, where, 1, value);

  *outIt = reinterpret_cast<BasicStringW_0x1c*>(
      reinterpret_cast<char*>(vec->begin) + index * 0x1c);
}
