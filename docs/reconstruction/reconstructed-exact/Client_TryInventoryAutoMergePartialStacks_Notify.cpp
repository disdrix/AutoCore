// =============================================================================
// Client_TryInventoryAutoMergePartialStacks_Notify
// -----------------------------------------------------------------------------
// Stable ID: aa_008c2f50
// Address:   0x008c2f50–0x008c2fdf  (143 B / 0x8F, autoassault.exe base 0x400000)
// System:    client / inventory-transfer notify
// Generated: 2026-07-29 W30-N dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_008c2f50
// =============================================================================
//
// PURPOSE:
//   Client wrapper: if not busy and host has an inventory grid, run
//   InventoryGrid_AutoMergePartialStacks_Inferred. On dirty, stamp host+0x564
//   from DAT_00d17768[index], refresh via FUN_00860700 (ESI=inventory host),
//   send sector packet 0x204a (8 bytes), return 1. Otherwise return 0.
//
// ABI (retail):
//   EDI = client/character host* (custom; ECX unused for this unit).
//   Bare RET; bool in AL.
//
// TWINS / CALLEES:
//   FUN_00572ab0 — InventoryGrid_AutoMergePartialStacks_Inferred (W29-E)
//   FUN_00860700 — inventory reaction/UI refresh (ESI host; not owned W30-N)
//   Client_SendSectorPacket
// =============================================================================

#include <cstdint>

extern "C" uint8_t __thiscall InventoryGrid_AutoMergePartialStacks_Inferred(void* grid);
// Retail: void FUN_00860700(void) with unaff_ESI = inventory host*
extern "C" void FUN_00860700(void);
extern "C" void Client_SendSectorPacket(void* conn, uint32_t size, const void* buf);

extern uint8_t DAT_00d1a8f6;
extern uint8_t DAT_00d17768[]; // retail indexes as byte ptr [index*4 + table]
extern void* DAT_00d1a840;

// Port takes explicit host* (retail: EDI).
extern "C" uint8_t Client_TryInventoryAutoMergePartialStacks_Notify(void* host /* EDI */)
{
  if (DAT_00d1a8f6 != 0) {
    return 0;
  }

  auto* host_b = static_cast<uint8_t*>(host);
  void* inv_host = *reinterpret_cast<void**>(host_b + 0x580);
  if (inv_host == nullptr) {
    return 0;
  }

  auto* inv_b = static_cast<uint8_t*>(inv_host);
  void* grid = *reinterpret_cast<void**>(inv_b + 0x56c);
  if (grid == nullptr) {
    return 0;
  }

  if (InventoryGrid_AutoMergePartialStacks_Inferred(grid) == 0) {
    return 0;
  }

  const int index = *reinterpret_cast<int*>(host_b + 0x50c);
  // Retail: mov dl, byte ptr [eax*4 + DAT_00d17768]
  const uint8_t stamp =
      *reinterpret_cast<const uint8_t*>(
          reinterpret_cast<const uint8_t*>(DAT_00d17768) +
          static_cast<uintptr_t>(index) * 4u);
  *(inv_b + 0x564) = stamp;

  // Retail: mov esi, inv_host; call FUN_00860700
  // (helper consumes inventory host via ESI — not ECX.)
  FUN_00860700();

  struct Packet8 {
    uint32_t opcode;
    uint8_t index_byte;
    uint8_t b_ff;
    uint8_t b_00;
    uint8_t pad;
  } packet{};
  packet.opcode = 0x204au;
  packet.index_byte = static_cast<uint8_t>(index);
  packet.b_ff = 0xFFu;
  packet.b_00 = 0;

  Client_SendSectorPacket(&DAT_00d1a840, 8, &packet);
  return 1;
}

// Scaffold alias
extern "C" uint8_t FUN_008c2f50(void* host)
{
  return Client_TryInventoryAutoMergePartialStacks_Notify(host);
}
