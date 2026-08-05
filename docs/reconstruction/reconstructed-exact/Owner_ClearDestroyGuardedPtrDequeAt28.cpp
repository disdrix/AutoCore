// =============================================================================
// Owner_ClearDestroyGuardedPtrDequeAt28
// -----------------------------------------------------------------------------
// Stable ID: aa_0075dae0
// Address:   0x0075dae0–0x0075db93  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0075dae0
// System:    owner + guarded ring-deque of owned pointers
// Dual:      W30-C 2026-07-29
// Exactness: Behavior-preserving from bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = owner; no stack formals; SEH; ADD ESP,0x20; RET.
// Clears embedded GuardedVector at owner+0x28 by:
//   1) ClearAndSwap empty local <-> field (steal under optional CS)
//   2) scalar-deleting each non-null owned pointer in ring order
//   3) FUN_0040d9c0 free of stolen page map
// Ghidra decompile is wrong on this unit — reconstruct from read_memory.
// Name structural; product/PDB open. Zero code xrefs in Ghidra.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;   // +0x04  page map (each page 4 dword slots)
  int32_t  capacity;  // +0x08  page count
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
  // Lockable form (field at owner+0x28) may also host:
  //   CRITICAL_SECTION at +0x14, flag at +0x2c (not swapped; see ClearAndSwap)
};

// Sealed W29-A: ESI=A, EDI=B.
extern "C" void GuardedVector_ClearAndSwap(GuardedVectorHeader* a /*ESI*/,
                                           GuardedVectorHeader* b /*EDI*/);

// ESI=container: spin size to 0, delete pages[0..cap), delete map, zero +4/+8.
extern "C" void FUN_0040d9c0(GuardedVectorHeader* container /*ESI*/);

using ScalarDeletingDtor = void(__thiscall*)(void* self, int flags);

void Owner_ClearDestroyGuardedPtrDequeAt28(void* owner /*ECX*/)
{
  GuardedVectorHeader local{};
  local.pages = nullptr;
  local.capacity = 0;
  local.begin = 0;
  local.size = 0;

  auto* field =
      reinterpret_cast<GuardedVectorHeader*>(
          reinterpret_cast<char*>(owner) + 0x28);

  GuardedVector_ClearAndSwap(&local, field);

  const int32_t begin = local.begin;
  const int32_t end = local.begin + local.size;
  for (int32_t idx = begin; idx != end; ++idx) {
    uint32_t page = static_cast<uint32_t>(idx) >> 2;
    const uint32_t sub =
        static_cast<uint32_t>(idx) - (page << 2); // idx & 3
    if (static_cast<uint32_t>(local.capacity) <= page) {
      page -= static_cast<uint32_t>(local.capacity);
    }
    // pages[page] is uint32_t* of 4 slots; load pointer element
    uint32_t* page_ptr = local.pages[page];
    void* elem = reinterpret_cast<void*>(page_ptr[sub]);
    if (elem != nullptr) {
      auto** vtbl = *reinterpret_cast<ScalarDeletingDtor**>(elem);
      vtbl[0](elem, 1);
    }
  }

  FUN_0040d9c0(&local);
}
