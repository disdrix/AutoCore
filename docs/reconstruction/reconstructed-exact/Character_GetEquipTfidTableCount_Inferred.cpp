// =============================================================================
// Character_GetEquipTfidTableCount_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Return the active equip-slot TFID table length for a Character.
//           count = min(8, (*(uint8_t*)(this + 0x59a) >> 1) + 3)
//           Callers iterate this+0x5a0 as lo/hi TFID pairs (stride 8) with
//           this count as the exclusive upper bound.
//
// Address:  0x00522000  (autoassault.exe, image base 0x400000)
// Body:     0x00522000–0x00522016 inclusive (23 bytes / 0x17)
// Stable:   aa_00522000
// System:   inventory-transfer
// Ghidra:   FUN_00522000
//
// ABI:      __thiscall / __fastcall  ECX = Character*
//           no stack formals; bare RET; EAX = count (typically 3..8)
// Callees:  none (leaf)
// Callers:  FUN_008e5ce0 (Client_UI_CraftHost_BindObjectByTfid_Inferred),
//           FUN_008e5e00, FUN_008b2f00, FUN_008b3400, FUN_008b3670
//           (+ xrefs 008b31f7, 008e83c8 — same ECX=DAT_00d1b6d8 pattern)
//
// Exactness: CF mirrors raw + force_decompile + disassemble_function + bytes.
// Bit-for-bit / runtime / differential: OPEN (no Launcher).
// Dual: MEGA-100 2026-08-05 — accept (product field English open → _Inferred).
// Prior scaffold Named_CalleeOf_* retired.
// =============================================================================

#include <cstdint>

// Field +0x59a: compact equip-slot budget byte. Written by level/flag paths
// (e.g. CVOGCharacter_SetLevelWithFlags stores 1). Low bit ignored by >>1;
// each unit of (byte>>1) adds one slot above the base of 3, hard-capped at 8.
static constexpr std::uintptr_t kEquipSlotBudgetByte = 0x59a;
static constexpr unsigned kBaseEquipSlots = 3;
static constexpr unsigned kMaxEquipTfidSlots = 8;

// __thiscall: ECX = Character*
// Returns equip TFID table entry count used by craft/UI equip scanners.
std::uint8_t __fastcall Character_GetEquipTfidTableCount_Inferred(void* character /*ECX*/)
{
  auto* base = static_cast<std::uint8_t*>(character);
  unsigned count =
      (static_cast<unsigned>(base[kEquipSlotBudgetByte]) >> 1u) + kBaseEquipSlots;

  // asm: cmp eax, 8 ; jl keep ; mov eax, 8
  // decompiler: if (7 < bVar1) bVar1 = 8;
  if (count > 7u) {
    count = kMaxEquipTfidSlots;
  }

  return static_cast<std::uint8_t>(count);
}
