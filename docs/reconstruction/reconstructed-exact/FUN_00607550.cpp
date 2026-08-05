// =============================================================================
// FUN_00607550  (scaffold twin of Outpost_GetScheduleEntryValueAtCursor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00607550
// Address:   0x00607550–0x006075a8 exclusive (88 B / 0x58)
// Preferred: Outpost_GetScheduleEntryValueAtCursor_Inferred
// Generated: 2026-08-04 WQ8R-E (upgraded from 2026-07-23 scaffold)
// =============================================================================

#include <cstdint>

extern "C" uint8_t DAT_00d029e0[];
extern "C" uint8_t DAT_00d029f0[];
extern "C" void FUN_00608620(void);

extern "C" uint32_t __thiscall FUN_00607550(void* self)
{
  uint8_t* table = (*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0x220) != 0)
      ? DAT_00d029e0
      : DAT_00d029f0;

  int32_t index = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x23c);
  if (index < 0) {
    return 0;
  }

  uint8_t* begin = *reinterpret_cast<uint8_t**>(table + 4);
  uint32_t size = 0;
  if (begin != nullptr) {
    uint8_t* end = *reinterpret_cast<uint8_t**>(table + 8);
    size = static_cast<uint32_t>((end - begin) >> 4);
  }

  if (static_cast<uint32_t>(index) >= size) {
    return 0;
  }

  if (begin == nullptr || size <= static_cast<uint32_t>(index)) {
    FUN_00608620();
  }

  return *reinterpret_cast<uint32_t*>(begin + static_cast<uint32_t>(index) * 0x10u + 4u);
}
