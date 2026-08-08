// =============================================================================
// FUN_0051b230  (clean twin of Object_CreateFromEmbeddedCbid_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b230
// Address:   0x0051b230–0x0051b298 exclusive
// Dual:      2026-08-04 WQ9R-H — see Object_CreateFromEmbeddedCbid_Inferred.cpp
// =============================================================================

#include <cstdint>

using VInit = int(__thiscall *)(void *self, int cbid, void *host, int one);
using VArg  = void(__thiscall *)(void *self, std::uint32_t arg);

extern "C" void *CVOGReaction_GiveItemByCbid(int cbid, int trailing_zero);
extern "C" void __thiscall FUN_00516720(void *obj, char *name_or_null);

extern "C" void *__thiscall FUN_0051b230(void *self)
{
  void *desc = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(self) + 0xA8);
  int cbid = *reinterpret_cast<int *>(reinterpret_cast<std::uint8_t *>(desc) + 0x34);

  void *obj = CVOGReaction_GiveItemByCbid(cbid, 0);
  if (obj == nullptr) {
    return nullptr;
  }

  auto *vtbl = *reinterpret_cast<std::uint8_t **>(obj);

  auto init = *reinterpret_cast<VInit *>(vtbl + 8);
  void *host = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(self) + 0xA4);
  init(obj, cbid, host, 1);

  auto set_b8 = *reinterpret_cast<VArg *>(vtbl + 0xB8);
  std::uint32_t arg_b8 =
      *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(self) + 0xB8);
  set_b8(obj, arg_b8);

  char *name =
      *reinterpret_cast<char **>(reinterpret_cast<std::uint8_t *>(self) + 0x158);
  FUN_00516720(obj, name);

  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(obj) + 0xC4) =
      *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(self) + 0xC4);

  return obj;
}
