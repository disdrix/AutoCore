// =============================================================================
// StdVector_PushBack_BasicStringW  (aa_004a8100)
// -----------------------------------------------------------------------------
// Address:   0x004a8100–0x004a8187 exclusive (135 B / 0x87)
// Module:    autoassault.exe @ image base 0x400000
// Ghidra:    FUN_004a8100
// System:    MSVC vector::push_back, basic_string<wchar_t> (elem 0x1c)
// Wave:      W38-K OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving from decompile + read_memory. Not modernization.
// Bit-for-bit / runtime: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   __thiscall ECX = vector*
//   stack: const BasicStringW_0x1c* value  (call site passes one stack formal)
//   RET 0x04; void
//
// Semantics:
//   If begin != null && size < capacity: uninit-fill-n count=1 at end; end += 0x1c.
//   Else: insert-one-rebind at end (growth / empty buffer); discard outIt.
//
// Callers: FUN_004a1d80 @ 0x004a1e57 (wstring token push).
// Callees: StdUninitFillN_BasicStringW (0x004a74f0, W36-R);
//          StdVector_InsertOne_RebindIt_BasicStringW (0x004a7ff0, W37-W).
// Name is structural (_Inferred). Reject scaffold Named_CalleeOf_*attachment*.
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

// Sealed W36-R (body uses dest/count/value; retail call sites often push 5 dwords)
extern "C" void StdUninitFillN_BasicStringW(
    BasicStringW_0x1c* dest,
    int count,
    const BasicStringW_0x1c* value);

// Sealed W37-W
extern "C" void StdVector_InsertOne_RebindIt_BasicStringW(
    StdVectorBasicStringW* vec,          /* ECX */
    BasicStringW_0x1c** outIt,           /* stack0 */
    BasicStringW_0x1c* where,            /* stack1 */
    const BasicStringW_0x1c* value);     /* stack2 */

// Retail: __thiscall; RET 0x04
extern "C" void StdVector_PushBack_BasicStringW(
    StdVectorBasicStringW* vec,          /* ECX */
    const BasicStringW_0x1c* value)      /* stack0 */
{
  BasicStringW_0x1c* begin = vec->begin;
  uint32_t size = 0;

  if (begin != nullptr) {
    size = static_cast<uint32_t>(
        (reinterpret_cast<char*>(vec->end) -
         reinterpret_cast<char*>(begin)) / 0x1c);
  }

  if (begin != nullptr) {
    const uint32_t cap = static_cast<uint32_t>(
        (reinterpret_cast<char*>(vec->cap_end) -
         reinterpret_cast<char*>(begin)) / 0x1c);
    if (size < cap) {
      BasicStringW_0x1c* dest = vec->end;
      // retail: push value; push vec; push value; push 1; push dest; call; add esp,0x14
      StdUninitFillN_BasicStringW(dest, 1, value);
      vec->end = reinterpret_cast<BasicStringW_0x1c*>(
          reinterpret_cast<char*>(dest) + 0x1c);
      return;
    }
  }

  BasicStringW_0x1c* outIt = nullptr;
  StdVector_InsertOne_RebindIt_BasicStringW(vec, &outIt, vec->end, value);
  (void)outIt;
}
