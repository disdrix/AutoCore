// =============================================================================
// FUN_0075dae0  (twin of Owner_ClearDestroyGuardedPtrDequeAt28)
// -----------------------------------------------------------------------------
// Stable ID: aa_0075dae0
// Address:   0x0075dae0–0x0075db93  (autoassault.exe, image base 0x400000)
// Dual:      W30-C 2026-07-29
// Note: Ghidra decompile is non-authoritative; body from read_memory.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  int32_t  capacity;
  int32_t  begin;
  int32_t  size;
};

extern "C" void GuardedVector_ClearAndSwap(GuardedVectorHeader* a /*ESI*/,
                                           GuardedVectorHeader* b /*EDI*/);
extern "C" void FUN_0040d9c0(GuardedVectorHeader* container /*ESI*/);

using ScalarDeletingDtor = void(__thiscall*)(void* self, int flags);

void FUN_0075dae0(void* owner /*ECX*/)
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
    const uint32_t sub = static_cast<uint32_t>(idx) - (page << 2);
    if (static_cast<uint32_t>(local.capacity) <= page) {
      page -= static_cast<uint32_t>(local.capacity);
    }
    uint32_t* page_ptr = local.pages[page];
    void* elem = reinterpret_cast<void*>(page_ptr[sub]);
    if (elem != nullptr) {
      auto** vtbl = *reinterpret_cast<ScalarDeletingDtor**>(elem);
      vtbl[0](elem, 1);
    }
  }

  FUN_0040d9c0(&local);
}
