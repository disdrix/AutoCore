// =============================================================================
// GuardedVector_InsertN_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e080
// Address:   0x0043e080–0x0043e37d  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043e080
// System:    STL / guarded ring-deque container
// Dual:      W32-F 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX=container; stack (seed, insert_at, N, fill*); RET 0x10.
// Inserts N copies of *fill at absolute insert_at using shorter-side policy.
// Twin of W29-A GuardedVector_InsertN (ECX=N / EAX push pair).
// This unit uses W31-I thiscall push_back/push_front.
// Sole known caller FUN_0043d940 resize-grow always end-inserts (suffix < N arm).
// Nested FUN_0043e910 / FUN_0043ebb0 / FUN_0043ec50 residual (unowned).
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

// Sealed W31-I thiscall push pair.
extern "C" void GuardedVector_PushBack_Thiscall(
    GuardedVectorHeader* container /*ECX*/, const uint32_t* value);
extern "C" void GuardedVector_PushFront_Thiscall(
    GuardedVectorHeader* container /*ECX*/, const uint32_t* value);

// Unowned range helpers (residual).
extern "C" void FUN_0043e910(GuardedVectorHeader* c_from, uint32_t idx_from,
                             GuardedVectorHeader* c_to, uint32_t idx_to,
                             const uint32_t* fill);
extern "C" void FUN_0043ec50(void* out, void* a, uint32_t b, void* c, uint32_t d,
                             void* e, uint32_t f, void* g);
extern "C" void FUN_0043ebb0(void* out, void* a, uint32_t b, void* c, uint32_t d,
                             void* e, uint32_t f, void* g);

// Retail: ECX=container; 4 stack args; RET 0x10.
void GuardedVector_InsertN_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                    GuardedVectorHeader* /*seed*/,
                                    int32_t insert_at,
                                    uint32_t n,
                                    const uint32_t* fill)
{
  const int32_t begin = container->begin;
  const int32_t size = container->size;
  const uint32_t prefix = static_cast<uint32_t>(insert_at - begin);
  const uint32_t suffix = static_cast<uint32_t>(size) - prefix;

  if (prefix < suffix) {
    // Front-biased — push via GuardedVector_PushFront_Thiscall (0043e3d0).
    if (prefix < n) {
      for (uint32_t i = n - prefix; i != 0; --i) {
        GuardedVector_PushFront_Thiscall(container, fill);
      }
      // Then push_front mapped copies of old front elements (page map walk in bytes).
      for (uint32_t left = prefix; left != 0; --left) {
        // Exact slot address packing: begin-1+N page wrap; see raw hex.
        GuardedVector_PushFront_Thiscall(container, fill /*shape: mapped slot**/);
      }
      const int32_t base = begin + static_cast<int32_t>(n);
      FUN_0043e910(container, static_cast<uint32_t>(base),
                   container,
                   static_cast<uint32_t>(base + static_cast<int32_t>(prefix)),
                   fill);
      return;
    }
    for (uint32_t i = n; i != 0; --i) {
      // push_front mapped near-insert elements; see raw for map.
      GuardedVector_PushFront_Thiscall(container, fill /*shape: mapped*/);
    }
    // FUN_0043ec50 ring copy; fall through to fill.
    const int32_t i5 = begin + static_cast<int32_t>(n);
    FUN_0043ec50(nullptr, container, static_cast<uint32_t>(i5 + static_cast<int32_t>(n)),
                 container, static_cast<uint32_t>(i5 + static_cast<int32_t>(prefix)),
                 container, static_cast<uint32_t>(i5),
                 const_cast<uint32_t*>(fill));
    const int32_t fill_lo = begin + static_cast<int32_t>(prefix);
    const int32_t fill_hi = i5 + static_cast<int32_t>(prefix);
    FUN_0043e910(container, static_cast<uint32_t>(fill_lo),
                 container, static_cast<uint32_t>(fill_hi),
                 reinterpret_cast<const uint32_t*>(&fill));
    return;
  }

  // Back-biased — push via GuardedVector_PushBack_Thiscall (0043d670).
  if (suffix < n) {
    for (int32_t i = static_cast<int32_t>(n - suffix); i != 0; --i) {
      GuardedVector_PushBack_Thiscall(container, fill);
    }
    for (uint32_t i = 0; i < suffix; ++i) {
      // push_back mapped old-back element at begin+i+prefix; page wrap in bytes.
      GuardedVector_PushBack_Thiscall(container, fill /*shape: mapped*/);
    }
    const int32_t base = begin + static_cast<int32_t>(prefix);
    FUN_0043e910(container, static_cast<uint32_t>(base),
                 container,
                 static_cast<uint32_t>(base + static_cast<int32_t>(suffix)),
                 fill);
    return;
  }

  for (uint32_t i = 0; i < n; ++i) {
    // push_back mapped near-insert elements; see raw for map.
    GuardedVector_PushBack_Thiscall(container, fill /*shape: mapped*/);
  }
  const int32_t i2 = begin + static_cast<int32_t>(prefix);
  FUN_0043ebb0(nullptr, container, static_cast<uint32_t>(i2),
               container, static_cast<uint32_t>((i2 + static_cast<int32_t>(suffix)) - static_cast<int32_t>(n)),
               container, static_cast<uint32_t>(i2 + static_cast<int32_t>(suffix)),
               const_cast<uint32_t*>(fill));
  const int32_t fill_hi = i2 + static_cast<int32_t>(n);
  FUN_0043e910(container, static_cast<uint32_t>(i2),
               container, static_cast<uint32_t>(fill_hi),
               reinterpret_cast<const uint32_t*>(&fill));
}
