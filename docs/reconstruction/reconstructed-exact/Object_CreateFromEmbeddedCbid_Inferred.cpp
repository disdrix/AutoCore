// =============================================================================
// Object_CreateFromEmbeddedCbid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b230
// Address:   0x0051b230–0x0051b298 exclusive (autoassault.exe, image base 0x400000)
// System:    object-spawn / CVOGClonedObjectBase virtual factory
// Generated: 2026-07-23 scaffold; **sealed 2026-08-04** dual A/B WQ9R-H
// Exactness: Behavior-preserving. Corrects decompiler traps (thiscall, GiveItem
//            trailing 0, FUN_00516720 thiscall pair) from read_memory seal.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-04)
// Product:   open (no plate); RTTI consumers CVOGCreature / CVOGWeapon
// =============================================================================

/*
 * Behavioral notes (2026-08-04 seal):
 * - __thiscall: ECX = cloned-object host with embedded descriptor fields.
 * - cbid = *(*(this+0xA8)+0x34); factory CVOGReaction_GiveItemByCbid(cbid, 0).
 * - On success: vtbl+8(cbid, *(this+0xA4), 1); vtbl+0xB8(*(this+0xB8));
 *   FUN_00516720(obj, *(this+0x158)); *(obj+0xC4)=*(this+0xC4).
 * - Returns obj* (NULL on factory fail). Callers dynamic_cast to Creature/Weapon.
 * - Sibling family: AllocateNewObjectFromCbid (0x004cf120).
 */

#include <cstdint>

using VInit = int(__thiscall *)(void *self, int cbid, void *host, int one);
using VArg  = void(__thiscall *)(void *self, std::uint32_t arg);

extern "C" void *CVOGReaction_GiveItemByCbid(int cbid, int trailing_zero);
extern "C" void __thiscall FUN_00516720(void *obj, char *name_or_null);

extern "C" void *__thiscall Object_CreateFromEmbeddedCbid_Inferred(void *self)
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
