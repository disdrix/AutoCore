// =============================================================================
// GuardedVector_InsertN
// -----------------------------------------------------------------------------
// Stable ID: aa_0043cb00
// Address:   0x0043cb00–0x0043cdfe  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043cb00
// System:    STL / guarded ring-deque container
// Dual:      W29-A 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = N; stack (container, seed, insert_at, fill*); RET 0x10.
// Inserts N copies of *fill at absolute insert_at using shorter-side policy.
// Sole known caller GuardedVector_Resize grow always hits back-biased suffix<N
// arm (insert_at = begin+size → suffix 0).
// Nested construct free: FUN_0043ce10 / FUN_0043c830 (W29-B).
// Name is structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  void**   slots;     // +0x04
  uint32_t capacity;  // +0x08  pages
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
};

// Unowned W29-B: EAX=container; push_front / push_back one dword from *src.
extern "C" void FUN_0043ce10(const uint32_t* src /*EAX container*/);
extern "C" void FUN_0043c830(const uint32_t* src /*EAX container*/);

// Sealed family helpers.
extern "C" void GuardedVector_RingFillRange(
    GuardedVectorHeader* c_from, uint32_t idx_from,
    GuardedVectorHeader* c_to, uint32_t idx_to,
    const uint32_t* fill /*retail EBX*/);
extern "C" void FUN_0043d390(void* out, void* a, uint32_t b, void* c, uint32_t d,
                             void* e, uint32_t f, void* g);
extern "C" void FUN_0043d300(void* out, void* a, uint32_t b, void* c, uint32_t d,
                             void* e, uint32_t f, void* g);

// Retail: ECX=N; 4 stack args; RET 0x10. Container also loaded from stack[0].
void GuardedVector_InsertN(uint32_t n /*ECX*/,
                           GuardedVectorHeader* container,
                           GuardedVectorHeader* /*seed*/,
                           int32_t insert_at,
                           uint32_t* fill)
{
  const int32_t begin = container->begin;
  const int32_t size = container->size;
  const uint32_t prefix = static_cast<uint32_t>(insert_at - begin);
  const uint32_t suffix = static_cast<uint32_t>(size) - prefix;

  if (prefix < suffix) {
    // Front-biased.
    if (prefix < n) {
      for (uint32_t i = n - prefix; i != 0; --i) {
        // Retail: MOV EAX, container; CALL FUN_0043ce10(fill)
        FUN_0043ce10(fill);
      }
      for (uint32_t left = prefix; left != 0; --left) {
        // push_front copy of mapped old-front element (page map walk)
        // Exact slot address packing residual in unowned FUN_0043ce10 path.
        FUN_0043ce10(fill);  // shape: element* from ring map; see raw
      }
      const int32_t base = begin + static_cast<int32_t>(n);
      GuardedVector_RingFillRange(container, static_cast<uint32_t>(base),
                                  container,
                                  static_cast<uint32_t>(base + static_cast<int32_t>(prefix)),
                                  fill);
      return;
    }
    for (uint32_t i = n; i != 0; --i) {
      FUN_0043ce10(fill);  // near-insert mapped copies; see raw for map
    }
    // FUN_0043d390 ring copy; then fall through to fill.
    const int32_t i6 = begin + static_cast<int32_t>(n);
    FUN_0043d390(nullptr, container, static_cast<uint32_t>(i6 + static_cast<int32_t>(n)),
                 container, static_cast<uint32_t>(i6 + static_cast<int32_t>(prefix)),
                 container, static_cast<uint32_t>(i6), fill);
    const int32_t fill_from = begin + static_cast<int32_t>(prefix);
    const int32_t fill_to = i6 + static_cast<int32_t>(prefix);
    GuardedVector_RingFillRange(container, static_cast<uint32_t>(fill_from),
                                container, static_cast<uint32_t>(fill_to), fill);
    return;
  }

  // Back-biased.
  if (suffix < n) {
    for (uint32_t i = n - suffix; i != 0; --i) {
      FUN_0043c830(fill);
    }
    for (uint32_t i = 0; i < suffix; ++i) {
      FUN_0043c830(fill);  // mapped old-back copies; see raw
    }
    const int32_t base = begin + static_cast<int32_t>(prefix);
    GuardedVector_RingFillRange(container, static_cast<uint32_t>(base),
                                container,
                                static_cast<uint32_t>(base + static_cast<int32_t>(suffix)),
                                fill);
    return;
  }

  for (uint32_t i = 0; i < n; ++i) {
    FUN_0043c830(fill);  // mapped copies; see raw
  }
  const int32_t i2 = begin + static_cast<int32_t>(prefix);
  FUN_0043d300(nullptr, container, static_cast<uint32_t>(i2),
               container, static_cast<uint32_t>(i2 + static_cast<int32_t>(suffix) - static_cast<int32_t>(n)),
               container, static_cast<uint32_t>(i2 + static_cast<int32_t>(suffix)), fill);
  GuardedVector_RingFillRange(container, static_cast<uint32_t>(i2),
                              container,
                              static_cast<uint32_t>(i2 + static_cast<int32_t>(n)), fill);
}
