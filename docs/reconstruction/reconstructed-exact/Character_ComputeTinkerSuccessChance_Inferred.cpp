// =============================================================================
// Character_ComputeTinkerSuccessChance_Inferred  (FUN_00521f20)
// -----------------------------------------------------------------------------
// Stable ID: aa_00521f20
// Address:   0x00521f20–0x00521fe7 inclusive (200 B / 0xC8)
//            jump table data @ 0x00521fe8 (5 dwords)
// Module:    autoassault.exe (image base 0x400000)
// System:    inventory-transfer / tinker success chance
// Generated: 2026-08-05 R10-035 dual seal
//            (decompile_function + analyze_function_complete + disassemble_function
//             + read_memory + callers/xrefs + caller disasm @ 0x0085f660)
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false (no runtime Confirmed)
// =============================================================================
//
// PURPOSE: Compute tinkering success chance as a fraction (~0..1) for the
// apply-confirm UI. Sole caller FUN_0085f660 (when Item_ValidateTinkerKitUse
// returns status 4) multiplies the result by 100.0 and formats:
//   "Attempting to tinker this item may result in its destruction.
//    You have a %.02f %% chance of success."
//
// ABI (assembly-sealed):
//   __thiscall: ECX = character*
//   stack:      item*, kit*   (RET 8)
//   return:     float in ST0
//
// Callees:
//   item->vtbl[+0x8c]()  — open slot count (short)
//   FUN_00521eb0         — skill tier 0..5 (ECX=character; leaf dual residual)
//
// Retires scaffold: Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00521f20
//
// Closed form:
//   if character[+0x6b4] >= 1: return 1.0
//   need = (uint8)(item_slots + 1)
//   if FUN_00521eb0(character) < need: return 0.0
//   base = {1:0.4, 2:0.35, 3:0.3, 4:0.25, 5:0.2}[need] or 0
//   term = (int16)( character[+0x59b] - 2*need + kit[+0xb0] )
//   return term * 0.04f + base
//
// =============================================================================

#include <cstdint>

// Shared float pool (addresses sealed via read_memory).
static constexpr float kFlOne = 1.0f;      // 0x00a0f2a0
static constexpr float kFlZero = 0.0f;     // 0x00a0f518
static constexpr float kBaseNeed1 = 0.4f;  // 0x00a0f720
static constexpr float kBaseNeed2 = 0.35f; // 0x00a0f728
static constexpr float kBaseNeed3 = 0.3f;  // 0x00a0f714 g_flOverheatCoolFrac
static constexpr float kBaseNeed4 = 0.25f; // 0x00a0f704
static constexpr float kBaseNeed5 = 0.2f;  // 0x009ceea8
static constexpr float kTermScale = 0.04f; // 0x00aaa8f4

// Unowned leaf: maps character+0x59b → tier 0..5 (Ghidra FUN_00521eb0).
// Call-site here: MOV ECX, character; CALL. Sibling dual name is residual.
extern "C" std::uint8_t __thiscall FUN_00521eb0(void *character);

// item vfunc +0x8c → open slot count (short in AX on machine).
using Item_GetOpenSlotCount_Fn = std::int16_t(__thiscall *)(void *item);

// __thiscall: ECX = character; stack item*, kit*; float return; RET 8
extern "C" float __thiscall Character_ComputeTinkerSuccessChance_Inferred(
    void *character, /* ECX */
    void *item,      /* stack+4 */
    void *kit)       /* stack+8 */
{
  auto *const ch = reinterpret_cast<std::uint8_t *>(character);

  // CMP [EDI+0x6b4],1 / JL normal — return 1.0 when >= 1
  if (*reinterpret_cast<std::int32_t *>(ch + 0x6b4) >= 1) {
    return kFlOne;
  }

  auto *const itemVtbl = *reinterpret_cast<void ***>(item);
  auto *const getSlots = reinterpret_cast<Item_GetOpenSlotCount_Fn>(itemVtbl[0x8c / 4]);
  const std::int16_t slots = getSlots(item);
  const unsigned need = static_cast<unsigned>(static_cast<std::uint8_t>(
      static_cast<std::uint8_t>(slots) + 1u));

  // ECX=character; EAX = tier 0..5
  const int tier = static_cast<int>(FUN_00521eb0(character));
  if (tier < static_cast<int>(need)) {
    return kFlZero;
  }

  float base = 0.0f;
  switch (need) {
  case 1:
    base = kBaseNeed1;
    break;
  case 2:
    base = kBaseNeed2;
    break;
  case 3:
    base = kBaseNeed3;
    break;
  case 4:
    base = kBaseNeed4;
    break;
  case 5:
    base = kBaseNeed5;
    break;
  default:
    base = 0.0f;
    break;
  }

  // term = (int16)( character[+0x59b] - 2*need + kit[+0xb0] )
  // Machine keeps need in DL across CALL 00521eb0 ("extraout_DL").
  const std::uint16_t rank = ch[0x59b];
  const std::int16_t kitLevel =
      *reinterpret_cast<std::int16_t *>(reinterpret_cast<std::uint8_t *>(kit) + 0xb0);
  const std::int16_t term = static_cast<std::int16_t>(
      static_cast<std::int16_t>(rank) -
      static_cast<std::int16_t>(2 * static_cast<int>(need)) + kitLevel);

  return static_cast<float>(static_cast<std::int32_t>(term)) * kTermScale + base;
}
