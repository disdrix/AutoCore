// =============================================================================
// GuardedVector_InsertRange
// -----------------------------------------------------------------------------
// Stable ID: aa_0044e1c0
// Address:   0x0044e1c0–0x0044e4ee  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0044e1c0
// System:    STL / guarded ring-deque container
// Dual:      W32-G 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: stdcall 6 stack formals; RET 0x18.
// Inserts N = (last-first)>>2 dwords from [first,last) at absolute insert_at
// using shorter-side policy (prefix vs suffix).
// Front arms: GuardedVector_PushFront_Thiscall (0x0043e3d0).
// Back arms:  GuardedVector_PushBack_Thiscall  (0x0043d670).
// Nested move/assign: FUN_0043ec50 / FUN_0043ebb0 / FUN_0044e4f0 (unowned).
// Name is structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;   // +0x04
  uint32_t capacity;  // +0x08  page count
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
};

// Sealed W31-I: ECX=container; stack value*; RET 4
extern "C" void GuardedVector_PushFront_Thiscall(GuardedVectorHeader* c /*ECX*/,
                                                 const uint32_t* value /*stack*/);
extern "C" void GuardedVector_PushBack_Thiscall(GuardedVectorHeader* c /*ECX*/,
                                                const uint32_t* value /*stack*/);

// Unowned nested helpers (residual free)
extern "C" void FUN_0043ec50(void* out, void* a, uint32_t b, void* c, uint32_t d,
                             void* e, uint32_t f, void* g);
extern "C" void FUN_0043ebb0(void* out, void* a, uint32_t b, void* c, uint32_t d,
                             void* e, uint32_t f, void* g);
extern "C" void FUN_0044e4f0(void* out, const uint32_t* first, const uint32_t* last,
                             GuardedVectorHeader* c, uint32_t dest_idx, void* tail);

// Map absolute ring index → element address (page wrap).
static const uint32_t* map_slot(GuardedVectorHeader* c, uint32_t abs_idx)
{
  uint32_t page = abs_idx >> 2;
  if (c->capacity <= page) {
    page -= c->capacity;
  }
  return c->pages[page] + (abs_idx & 3);
}

// Retail: 6 stack args; RET 0x18. Container in stack[0] (ESI).
extern "C" void GuardedVector_InsertRange(GuardedVectorHeader* container,
                                          void* seed_out,
                                          uint32_t insert_at,
                                          const uint32_t* first,
                                          const uint32_t* last,
                                          uint32_t /*sixth_residual*/)
{
  const int32_t begin = container->begin;
  const int32_t size = container->size;
  const uint32_t prefix = static_cast<uint32_t>(insert_at - static_cast<uint32_t>(begin));
  const uint32_t suffix = static_cast<uint32_t>(size) - prefix;
  const uint32_t n = static_cast<uint32_t>((last - first)); // already >>2 in retail byte distance

  // Retail computes N as (last-first)>>2 on byte pointers.
  const uint32_t N = static_cast<uint32_t>(
      (reinterpret_cast<const char*>(last) - reinterpret_cast<const char*>(first)) >> 2);

  (void)n;
  (void)seed_out;

  if (prefix < suffix) {
    // Front-biased.
    if (prefix < N) {
      // push_front excess source elements (from end of excess span), then old prefix.
      const uint32_t* p = first + (N - prefix);
      while (p != first) {
        --p;
        GuardedVector_PushFront_Thiscall(container, p);
      }
      uint32_t left = prefix;
      while (left != 0) {
        const uint32_t abs = static_cast<uint32_t>(begin) + (N - 1);
        GuardedVector_PushFront_Thiscall(container, map_slot(container, abs));
        --left;
      }
      FUN_0044e4f0(&seed_out, first + (N - prefix) /*shape: retail iVar1*/, last,
                   container, static_cast<uint32_t>(begin) + N, last);
      return;
    }
    for (uint32_t i = N; i != 0; --i) {
      const uint32_t abs = static_cast<uint32_t>(begin) + (N - 1);
      GuardedVector_PushFront_Thiscall(container, map_slot(container, abs));
    }
    const int32_t i6 = begin + static_cast<int32_t>(N);
    FUN_0043ec50(&seed_out, container, static_cast<uint32_t>(i6 + static_cast<int32_t>(N)),
                 container, static_cast<uint32_t>(i6 + static_cast<int32_t>(prefix)),
                 container, static_cast<uint32_t>(i6), last);
    // fall through — assign source into [begin+prefix, …)
  } else {
    // Back-biased.
    if (suffix < N) {
      const uint32_t* p = first + suffix;
      for (; p != last; ++p) {
        GuardedVector_PushBack_Thiscall(container, p);
      }
      for (uint32_t i = 0; i < suffix; ++i) {
        const uint32_t abs = static_cast<uint32_t>(begin) + i + prefix;
        GuardedVector_PushBack_Thiscall(container, map_slot(container, abs));
      }
      FUN_0044e4f0(&seed_out, first, first + suffix, container,
                   static_cast<uint32_t>(begin) + prefix, last);
      return;
    }
    for (uint32_t i = 0; i < N; ++i) {
      const uint32_t abs =
          static_cast<uint32_t>(begin) + (i - N) + suffix + prefix;
      GuardedVector_PushBack_Thiscall(container, map_slot(container, abs));
    }
    const int32_t base = begin + static_cast<int32_t>(prefix);
    FUN_0043ebb0(&seed_out, container, static_cast<uint32_t>(base),
                 container,
                 static_cast<uint32_t>(base + static_cast<int32_t>(suffix) - static_cast<int32_t>(N)),
                 container, static_cast<uint32_t>(base + static_cast<int32_t>(suffix)), last);
  }

  const int32_t fill_at = begin + static_cast<int32_t>(prefix);
  FUN_0044e4f0(&seed_out, first, last, container, static_cast<uint32_t>(fill_at), last);
}
