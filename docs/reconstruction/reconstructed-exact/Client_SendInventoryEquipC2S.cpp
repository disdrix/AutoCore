// =============================================================================
// Client_SendInventoryEquipC2S
// -----------------------------------------------------------------------------
// Stable ID: aa_00931440
// Address:   0x00931440 – 0x009314ec  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-29 W19-T dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prior scaffold names: FUN_00931440,
//   Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_00931440
// =============================================================================
//
// PURPOSE: After parent equip/customize pre-gates succeed, emit the C2S packet:
//   clone type == 0xe  → opcode 0x2053, size 0x10 (COID lo/hi only)
//   otherwise          → opcode 0x203c, size 0x40 (TFID 16B + mode byte)
// via client net iface at client+0xc78, vtbl+0x18.
//
// ABI (bytes-sealed):
//   EAX = item*
//   ECX = client*
//   stack = mode (uint8; one arg, RET 4)
//   return always 0
//
// Callers:
//   Client_ConfirmEquipOrCustomizeItem (0x00941b20) — success tail
//   Client_SendInventoryDrop_Hardpoint (0x00863430) — type 0xe branch, mode=1
// =============================================================================

#include <cstdint>

// Opaque host types (layout fragments only).
struct Client;
struct Item;

using NetSendFn = void(__thiscall *)(void *net, uint32_t token, void *buf,
                                     uint32_t size, uint32_t flag);

uint32_t __fastcall Client_SendInventoryEquipC2S(Client *client /*ECX*/,
                                                 Item *item /*EAX*/,
                                                 uint8_t mode /*stack*/)
{
  // Decompiler: *(int *)(*(int *)(item + 0xa8) + 0x38)
  int *cloneMeta = *reinterpret_cast<int **>(reinterpret_cast<char *>(item) + 0xa8);
  int type = cloneMeta[0x38 / 4];

  void *net = *reinterpret_cast<void **>(reinterpret_cast<char *>(client) + 0xc78);

  if (type == 0xe) {
    // 0x10-byte stack packet: opcode + COID pair
    alignas(4) uint8_t buf[0x10] = {};
    *reinterpret_cast<uint32_t *>(buf + 0x00) = 0x2053;
    *reinterpret_cast<uint32_t *>(buf + 0x08) =
        *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(item) + 0x160);
    *reinterpret_cast<uint32_t *>(buf + 0x0c) =
        *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(item) + 0x164);
    if (net != nullptr) {
      void **vtbl = *reinterpret_cast<void ***>(net);
      auto send = reinterpret_cast<NetSendFn>(vtbl[0x18 / 4]);
      send(net, 0xffffffffu, buf, 0x10, 0);
      return 0;
    }
  } else {
    // 0x40-byte stack packet: opcode + 16B identity + mode
    alignas(4) uint8_t buf[0x40] = {};
    *reinterpret_cast<uint32_t *>(buf + 0x00) = 0x203c;
    // item+0x160 .. +0x16c → four dwords at buf+0x08
    *reinterpret_cast<uint32_t *>(buf + 0x08) =
        *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(item) + 0x160);
    *reinterpret_cast<uint32_t *>(buf + 0x0c) =
        *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(item) + 0x164);
    *reinterpret_cast<uint32_t *>(buf + 0x10) =
        *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(item) + 0x168);
    *reinterpret_cast<uint32_t *>(buf + 0x14) =
        *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(item) + 0x16c);
    buf[0x38] = 0;
    buf[0x3b] = mode;
    if (net != nullptr) {
      void **vtbl = *reinterpret_cast<void ***>(net);
      auto send = reinterpret_cast<NetSendFn>(vtbl[0x18 / 4]);
      send(net, 0xffffffffu, buf, 0x40, 0);
    }
  }
  return 0;
}
