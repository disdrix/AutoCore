// =============================================================================
// FUN_00970060 — twin of EffectHandle_SetSlot_CoW_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00970060
// Address:   0x00970060–0x009700a8 (73 B)
// Dual A/B:  2026-08-04 W38-P
// Prefer:    EffectHandle_SetSlot_CoW_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" int8_t __fastcall FUN_0096fdf0(void* handle /*ECX*/);
extern "C" int32_t __thiscall FUN_007528f0(void* effect /*ECX*/, int32_t a, void* b);
extern "C" void __thiscall FUN_00448fc0(void* handle /*ECX*/, void* neu /*stack*/);

// Retail ABI: ESI = handle*; stack (slotIndex, resource*); ret 8.
// C++ cannot express ESI-this cleanly; pass handle explicitly for reconstruction.
int32_t FUN_00970060(void* handle /*ESI*/, int32_t slotIndex, void* resource)
{
  const int8_t cowed = FUN_0096fdf0(handle);
  void* effect = *reinterpret_cast<void**>(handle);
  const int32_t status = FUN_007528f0(effect, slotIndex, resource);

  if (status == -1 && cowed != 0) {
    void* obj = *reinterpret_cast<void**>(handle);
    if (obj != nullptr) {
      void* parent = *reinterpret_cast<void**>(reinterpret_cast<char*>(obj) + 0x18);
      if (parent == nullptr) {
        parent = obj;
      }
      if (parent != obj) {
        FUN_00448fc0(handle, parent);
      }
    }
  }
  return status;
}
