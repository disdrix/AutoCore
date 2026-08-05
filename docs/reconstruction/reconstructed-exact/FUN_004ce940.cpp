// =============================================================================
// FUN_004ce940  (scaffold alias → CVOGLootGenerator_GetOrCreate)
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce940
// Address:   0x004ce940  (autoassault.exe, image base 0x400000)
// Prefer:    reconstructed-exact/CVOGLootGenerator_GetOrCreate.cpp
// Dual:      2026-07-29 W17-J — bytes seal EAX return of DAT_00b037e8
// =============================================================================

#include <cstdint>

extern "C" void* operator_new(std::uint32_t size);
extern "C" void* __thiscall FUN_0050c1b0(void* self, void* tableRoot);
extern "C" void* DAT_00b037e8;
extern "C" void* DAT_00b041fc;

// Bytes-correct: returns singleton in EAX (decompiler said void).
void* FUN_004ce940(void)
{
  if (DAT_00b037e8 != nullptr) {
    return DAT_00b037e8;
  }
  void* mem = operator_new(0xbc);
  if (mem == nullptr) {
    DAT_00b037e8 = nullptr;
    return nullptr;
  }
  DAT_00b037e8 = FUN_0050c1b0(mem, DAT_00b041fc);
  return DAT_00b037e8;
}
