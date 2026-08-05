// =============================================================================
// Client_CreateObjectFromCbidPacket_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Client create path for sector-style packets: allocate object by
//           packet CBID, run vtbl init + create-from-packet (mode 2), optional
//           table/selection post-steps. Twin of ProcessSectorUpdate (FUN_00811e00).
//
// Address:  0x008120d0 – 0x008122de exclusive (526 bytes / 0x20E)
// Stable:   aa_008120d0
// Ghidra:   FUN_008120d0
// String:   "allocatenewobjectfromcbid failed %d Get a programmer"
// Callers:  FUN_00814400 (0x201C), FUN_00814470/b0/f0, FUN_008122e0/320/360
// Callees:  CVOGReaction_GiveItemByCbid, FUN_007a4480, vtbl+8/+0x1cc/+0xc4,
//           FUN_009972a0, FUN_008024d0, FUN_007fb2b0 (+ residual FUN_0092a3b0)
//
// Convention: 2 stack args (game*, packet*); RET 8; EAX = object*|null
// Exactness:  Preserves decompiler CF; see raw for byte residual on 0092a3b0.
// Bit-for-bit package: DEFERRED. Runtime / differential: OPEN.
// Dual A/B (static): SEALED accept-with-gaps 2026-07-29 (W26-L).
// =============================================================================

#include <cstdint>

struct GameClient;
struct SectorCreatePacket;
struct GameObject;

extern "C" GameObject* CVOGReaction_GiveItemByCbid(std::int32_t cbid);
extern "C" void FUN_007a4480(int level, const char* fmt, ...);
extern "C" void FUN_009972a0(void);
extern "C" void FUN_008024d0(GameClient* game, std::uint32_t a, std::uint32_t b,
                             int z0, int z1, int z2,
                             std::uint32_t idLo, std::uint32_t idHi);
extern "C" void FUN_007fb2b0(std::uint32_t idLo, std::uint32_t idHi);
extern std::uint32_t DAT_00d1d86c;
extern std::uint32_t DAT_00d1d870;

/// Allocate + init client object from packet CBID (create path).
GameObject* Client_CreateObjectFromCbidPacket_Inferred(
    GameClient* game,
    SectorCreatePacket* packet)
{
  auto* g = reinterpret_cast<std::uint8_t*>(game);
  auto* pkt = reinterpret_cast<std::uint8_t*>(packet);

  std::int32_t cbid = *reinterpret_cast<std::int32_t*>(pkt + 4);
  GameObject* obj = CVOGReaction_GiveItemByCbid(cbid);
  if (obj == nullptr) {
    FUN_007a4480(1, "allocatenewobjectfromcbid failed %d Get a programmer", cbid);
    return nullptr;
  }

  auto* vtbl = *reinterpret_cast<void***>(obj);
  using VfnInit = void(__thiscall*)(GameObject*, std::uint32_t, std::uint32_t, int);
  using VfnProbe = void(__thiscall*)(GameObject*);
  using VfnFromPacket = void(__thiscall*)(GameObject*, void*, int, std::uint32_t,
                                          std::uint32_t, std::uint32_t, std::uint32_t);

  reinterpret_cast<VfnInit>(vtbl[8 / sizeof(void*)])(
      obj,
      static_cast<std::uint32_t>(cbid),
      *reinterpret_cast<std::uint32_t*>(g + 0xe04),
      0);
  reinterpret_cast<VfnProbe>(vtbl[0x1cc / sizeof(void*)])(obj);

  auto* od = reinterpret_cast<std::uint32_t*>(obj);
  std::uint32_t mask = *reinterpret_cast<std::uint32_t*>(pkt + 8) &
                       *reinterpret_cast<std::uint32_t*>(pkt + 0xc);
  std::uint32_t bit0 = 0;
  if (mask == 0xffffffffu && pkt[0xa8] == 0 && pkt[0xa7] == 0 && pkt[0xa0] == 0) {
    bit0 = 1;
  }
  od[0x61] = od[0x61] ^ ((bit0 ^ od[0x61]) & 1);

  std::uint32_t flag_u3 = 0;
  std::uint8_t host_f5 =
      *reinterpret_cast<std::uint8_t*>(*reinterpret_cast<std::uint8_t**>(g + 0xe04) + 0xf5);
  if (mask != 0xffffffffu ||
      (pkt[0xc0] == 0 && pkt[0xa8] == 0 && pkt[0xa7] == 0 && pkt[0xa2] == 0 &&
       (pkt[0xa0] == 0 || host_f5 == 0))) {
    flag_u3 = 1;
  }

  reinterpret_cast<VfnFromPacket>(vtbl[0xc4 / sizeof(void*)])(
      obj,
      packet,
      /*mode=*/2,
      *reinterpret_cast<std::uint32_t*>(g + 0xe04),
      static_cast<std::uint32_t>(pkt[0xa1] == 0),
      flag_u3,
      flag_u3);

  if (pkt[0xa1] != 0) {
    FUN_009972a0();
    FUN_008024d0(game, DAT_00d1d86c, DAT_00d1d870, 0, 0, 0, od[0x58], od[0x59]);
  }

  // Residual (bytes): optional FUN_0092a3b0(*(game+0x4d0), ...) under multi-flag gate.

  if (pkt[0xc0] != 0) {
    FUN_007fb2b0(od[0x58], od[0x59]);
  }
  return obj;
}
