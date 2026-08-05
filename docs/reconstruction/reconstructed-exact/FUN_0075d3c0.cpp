// =============================================================================
// FUN_0075d3c0  (clean twin of AssManager_EnsureAssPreloader_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d3c0
// Address:   0x0075d3c0–0x0075d466
// Dual:      W33-O 2026-07-29
// See:       AssManager_EnsureAssPreloader_Inferred.cpp for named surface.
// =============================================================================

#include <cstdint>

extern "C" void* operator_new(uint32_t size);
extern "C" void* FUN_00970cf0(void* mem);
extern "C" void FUN_0043e8f0(void);
extern "C" void FUN_0043e7f0(void);

void FUN_0075d3c0(void* host /*stack*/)
{
  if (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(host) + 0x6c) != 0) {
    return;
  }

  void* mem = operator_new(0x114);
  void* pre = (mem != nullptr) ? FUN_00970cf0(mem) : nullptr;
  *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(host) + 0x6c) = pre;

  int* head = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(host) + 0x08);
  for (int* node = reinterpret_cast<int*>(*head); node != head;
       node = reinterpret_cast<int*>(*node)) {
    // Retail: pack {node[2], 1}; EDI = pre+0xAC; locked push
    FUN_0043e8f0();
    FUN_0043e7f0();
  }
}
