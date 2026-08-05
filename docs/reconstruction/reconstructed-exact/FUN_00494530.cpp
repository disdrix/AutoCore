// =============================================================================
// FUN_00494530  (clean twin — Ghidra plate)
// -----------------------------------------------------------------------------
// Stable ID: aa_00494530
// Address:   0x00494530–0x0049459d  (110 B / 0x6E)
// Canonical: Host_ClearListTrackedOwnedInRect_Inferred
// Generated: 2026-07-29 W31-D (twin of named clean)
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_004be2a0(void* self);
extern "C" void operator_delete(void* p);

// Prefer Host_ClearListTrackedOwnedInRect_Inferred.cpp for named port.
extern "C" void __fastcall FUN_00494530(void* host)
{
  auto* h = reinterpret_cast<uint8_t*>(host);

  uint32_t x = *reinterpret_cast<uint32_t*>(h + 0x64);
  if (x >= *reinterpret_cast<uint32_t*>(h + 0x6C)) {
    return;
  }

  do {
    uint32_t y = *reinterpret_cast<uint32_t*>(h + 0x68);
    if (y < *reinterpret_cast<uint32_t*>(h + 0x70)) {
      do {
        int index = *reinterpret_cast<int*>(h + 4) * static_cast<int>(y)
                    + static_cast<int>(x);
        auto* arr = *reinterpret_cast<uint8_t**>(h + 0x28);
        auto* elem = arr + index * 0x28;
        void* owned = *reinterpret_cast<void**>(elem + 0x24);
        if (owned != nullptr) {
          FUN_004be2a0(owned);
          operator_delete(owned);
        }
        *reinterpret_cast<void**>(elem + 0x24) = nullptr;
        ++y;
      } while (y < *reinterpret_cast<uint32_t*>(h + 0x70));
    }
    ++x;
  } while (x < *reinterpret_cast<uint32_t*>(h + 0x6C));
}
