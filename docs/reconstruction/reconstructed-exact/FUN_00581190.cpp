// =============================================================================
// FUN_00581190  (clean twin of VOGPhysics_QueryObject_SubInit_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00581190
// Address:   0x00581190  (autoassault.exe, image base 0x400000)
// Range:     0x00581190–0x005811e7 inclusive (88 B / 0x58)
// System:    interaction-activation
// Generated: 2026-08-05 R12-027 dual seal
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN.
// Canonical inferred name: VOGPhysics_QueryObject_SubInit_Inferred
// =============================================================================

#include <cstdint>

extern uint32_t PTR_FUN_009cd99c;

void __thiscall FUN_00581190(
    uint32_t *self /* ECX */,
    uint32_t *linked_obj /* stack */,
    uint32_t mode /* stack */)
{
  *reinterpret_cast<uint16_t *>(reinterpret_cast<uint8_t *>(self) + 6) = 1;
  *self = reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_009cd99c));
  self[2] = 0;
  self[3] = reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(linked_obj));
  self[5] = 0;
  self[6] = 0;
  self[4] = 0xFFFFFFFFu;
  self[9] = mode;
  self[7] = 0;
  self[8] = 0;
  self[10] = 0;
  self[0xb] = 0;
  self[0xc] = 0;
  self[0xd] = 0;
  self[0xe] = 0x80000000u;
  self[0xb] = reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(self));
  if (linked_obj != nullptr) {
    uint16_t *rc = reinterpret_cast<uint16_t *>(
        reinterpret_cast<uint8_t *>(linked_obj) + 6);
    *rc = static_cast<uint16_t>(*rc + 1);
  }
}
