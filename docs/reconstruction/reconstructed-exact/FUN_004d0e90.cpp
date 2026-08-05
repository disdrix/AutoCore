// =============================================================================
// FUN_004d0e90  (scaffold alias → Object_EnqueueDeferredOnce)
// -----------------------------------------------------------------------------
// Stable ID: aa_004d0e90
// Address:   0x004d0e90  (autoassault.exe, image base 0x400000)
// Prefer:    reconstructed-exact/Object_EnqueueDeferredOnce.cpp
// Dual:      2026-07-29 W17-J — bytes seal ECX host + ret 4 (decompiler incomplete)
// =============================================================================

#include <cstdint>

extern "C" std::uint8_t __thiscall FUN_004e15a0(void* queue, void* obj);
extern "C" void         __thiscall FUN_004024d0(void* queue, void* obj);

// Bytes-correct signature (Ghidra surface omits ECX):
void __thiscall FUN_004d0e90(void* host /*ECX*/, void* obj /*stack*/)
{
  if ((*(std::uint8_t*)((std::uint8_t*)obj + 0x17c) & 1) == 0) {
    void* queue = *(void**)((std::uint8_t*)host + 0xe5fc);
    if (FUN_004e15a0(queue, obj) == 0) {
      FUN_004024d0(queue, obj);
      *(std::uint32_t*)((std::uint8_t*)obj + 0x17c) |= 1u;
    }
  }
}
