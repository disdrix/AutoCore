// =============================================================================
// FUN_00941f50  (scaffold twin of Client_UseInventoryItemByCoid)
// -----------------------------------------------------------------------------
// Stable ID: aa_00941f50
// Address:   0x00941f50
// See named clean: Client_UseInventoryItemByCoid.cpp
// WQ8R-I 2026-08-04: twin kept for FUN_* path stability.
// =============================================================================

#include <cstdint>

extern "C" {
void *FUN_00571010(std::uint32_t coidLo, std::uint32_t coidHi); // thiscall grid ECX
std::uint32_t FUN_00941d50(std::uint32_t mode); // ESI=client, EDI=item
}

// EAX = client; ret 0x0C
std::uint8_t FUN_00941f50(std::uint32_t param_1, std::uint32_t param_2,
                          std::uint32_t param_3)
{
  int client = /* EAX */;
  int ch = *reinterpret_cast<int *>(client + 0xE98);
  if (ch == 0)
    return 0;
  int host = *reinterpret_cast<int *>(ch + 0x250);
  if (host == 0)
    return 0;
  if ((param_1 & param_2) == 0xFFFFFFFFu)
    return 0; // bytes: xor al,al — NOT (host & 0xffffff00)

  // ECX = *(host + 0x2B0) cargo grid
  void *item = FUN_00571010(param_1, param_2);
  // EDI = item, ESI = client
  return static_cast<std::uint8_t>(FUN_00941d50(param_3));
}
