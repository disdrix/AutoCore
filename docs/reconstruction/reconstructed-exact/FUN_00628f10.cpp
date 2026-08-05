// =============================================================================
// FUN_00628f10 — scaffold alias → ActionHost_RemoveReverseListEntry_Inferred
// Stable ID: aa_00628f10
// Address:   0x00628f10
// Sealed:    2026-07-29 W24-P
// Body:      84 B; thiscall host, action; ret 4
// =============================================================================

#include <cstdint>

void __thiscall FUN_00628f10(void *host, void *action)
{
  int32_t index = 0;
  int32_t count = *reinterpret_cast<int32_t *>(reinterpret_cast<char *>(host) + 0x50);

  if (count > 0) {
    void **slot = *reinterpret_cast<void ***>(reinterpret_cast<char *>(host) + 0x4c);
    do {
      if (*slot == action) {
        goto found;
      }
      ++index;
      ++slot;
    } while (index < count);
  }
  index = -1;

found:
  *reinterpret_cast<int32_t *>(reinterpret_cast<char *>(host) + 0x50) = count - 1;
  // re-read count after decrement
  count = *reinterpret_cast<int32_t *>(reinterpret_cast<char *>(host) + 0x50);
  if (index < count) {
    void **base = *reinterpret_cast<void ***>(reinterpret_cast<char *>(host) + 0x4c);
    do {
      base[static_cast<uint32_t>(index)] = base[static_cast<uint32_t>(index) + 1];
      ++index;
    } while (index < count);
  }

  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(action) + 0x10) = 0;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(host) + 0x28) = 1;
}
