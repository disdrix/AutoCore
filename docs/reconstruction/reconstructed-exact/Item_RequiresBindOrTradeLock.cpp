// =============================================================================
// Item_RequiresBindOrTradeLock  (FUN_00513fc0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00513fc0
// Address:   0x00513fc0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-05 MEGA-050
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Read-only predicate — does this inventory item require permanent
// bind / trade-lock handling (equip customize confirm, "Customizes On Equip"
// tooltip, auto-set ItemFlag_Customized on vehicle-switch failure path)?
//
// Dual: docs/reconstruction/reviews/A|B_aa_00513fc0_Item_RequiresBindOrTradeLock.md
//
// Related (not this unit):
//   - Item_SetCustomized @ 0x00513e30  (bit20 write; modal Yes / vehicle path)
//   - Client_ConfirmEquipOrCustomizeItem @ 0x00941b20  (primary equip gate)
//   - CVOGReaction_ResolveObjectTarget @ 0x004bae70
//   - Item_IsStackEligible @ 0x00513e70  (stack flag; different predicate)

// READABILITY:
//  - Body size: ~0x90 bytes; 3 RET 8 exits.
//  - Control: null resolve; type-class OR subtype gate; 0x4b8 threshold; vtbl+0x60 force.
//  - ABI: thiscall ECX=Item*, 2 stack dwords (COID halves), RET 8, AL bool.

/*
 * Behavioral notes:
 * - Live Ghidra 2026-08-05 decompile ≡ 2026-07-23 raw CF.
 * - Decompiler hides ECX=this; sealed via disassemble_function + call-site bytes.
 * - Type set {0xc,0x1c,0xa,0x10,0xe} + type6 subtypes {10,11} sealed in asm CMP chain.
 * - blob+0x4b8: short; need when >= 2 (CMP 2 / JL).
 * - vtbl+0x60 non-zero forces true inside type gate (TEST/JBE ≡ !=0).
 * - Product type / field / vfunc English: OPEN.
 * - Runtime / differential: OPEN.
 */

#include <cstdint>

// reaction thiscall; mode in stack; COID halves
extern "C" int *__thiscall CVOGReaction_ResolveObjectTarget(
    void *reaction, int mode, std::uint32_t coid_lo, std::uint32_t coid_hi);

// item: inventory / world object (ECX)
// coid_lo / coid_hi: typically item+0x160 / item+0x164 (callers push those)
bool __thiscall Item_RequiresBindOrTradeLock(
    int *item, std::uint32_t coid_lo, std::uint32_t coid_hi)
{
  void *host = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(item) + 0xa4);
  void *reaction =
      *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(host) + 0xe4e8);

  int *obj = CVOGReaction_ResolveObjectTarget(reaction, 1, coid_lo, coid_hi);
  bool need = false;
  if (obj == nullptr) {
    return false;
  }

  int *holder = reinterpret_cast<int *>(obj[0x2a]);
  const int type = *reinterpret_cast<int *>(reinterpret_cast<std::uint8_t *>(holder) + 0x38);
  int *blob = *reinterpret_cast<int **>(reinterpret_cast<std::uint8_t *>(holder) + 0x3c);

  bool type_ok = false;
  if (type == 0xc || type == 0x1c || type == 0xa || type == 0x10 || type == 0xe) {
    type_ok = true;
  } else if (type == 6) {
    const std::int16_t sub =
        *reinterpret_cast<std::int16_t *>(reinterpret_cast<std::uint8_t *>(blob) + 0x3f4);
    type_ok = (sub == 10 || sub == 11);
  }

  if (type_ok) {
    const std::int16_t lock_field =
        *reinterpret_cast<std::int16_t *>(reinterpret_cast<std::uint8_t *>(blob) + 0x4b8);
    need = (lock_field >= 2);

    // vtbl+0x60 thiscall on resolved object
    auto **vtbl = reinterpret_cast<int (__thiscall ***)(int *)>(*obj);
    const int force = (*vtbl)[0x60 / 4](obj);
    if (force != 0) {
      return true;
    }
  }
  return need;
}

// Compatibility alias (Ghidra scaffold name)
bool __thiscall FUN_00513fc0(int *param_1, std::uint32_t param_2, std::uint32_t param_3)
{
  return Item_RequiresBindOrTradeLock(param_1, param_2, param_3);
}
