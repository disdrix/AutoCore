// =============================================================================
// AI_CheckSlotTimerReady
// -----------------------------------------------------------------------------
// Purpose:  Gate an HBAI per-slot cooldown timer. If elapsed client ms since
//           last stamp exceeds the slot period, latch ready-flag=1 and return
//           true (AL); else return false. Does not restamp last-fire or reseed
//           period (reschedule/fire paths own those writes).
//
// Address:  0x005cced0  (autoassault.exe, image base 0x400000)
// Body:     0x005cced0 – 0x005ccefc
// Stable:   aa_005cced0
// System:   npc-ai / HBAI
//
// Convention: MSVC __thiscall
//   this         HBAI object (timer bank at +0x70)
//   nSlotIndex   stack dword; RET 4
//   return       AL bool (callers TEST AL); high EAX bytes unused
//
// Slot table (stride 0x0C) at this+0x70:
//   +0x00  last stamp (ms, dword; subtracted from g_dwClientTickMs)
//   +0x04  period / threshold (ms, uint)
//   +0x08  ready flag (uint8_t; set to 1 on success only)
//
// Decomp identity for ready write:
//   *(u8*)(this + (index*3 + 0x1e)*4)  ==  *(u8*)(this + index*0xC + 0x78)
//
// Control flow:
//   1) elapsed = g_dwClientTickMs - last
//   2) if period < elapsed  (equiv elapsed > period; equal = not ready)
//        ready=1; return 1
//   3) else return 0
//
// Callers (6):
//   CVOGHBAICreatureBase_OnHeartBeat  (EDI)
//   CVOGHBAIDriver_DoLogic ×2         (imm 0)
//   NPC_TryCastSkillFromSet           (imm 2)
//   FUN_005d7f70 ×2                   (EBX)
//
// Exactness: CF mirrors raw body bytes; signature arity corrected (RET 4).
// Dual A/B: 2026-07-29 accept-with-gaps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================

#include <stdint.h>

extern uint32_t g_dwClientTickMs; // VA 0x00b041cc

uint8_t __thiscall AI_CheckSlotTimerReady(void *this, uint32_t nSlotIndex)
{
  uint32_t elapsed =
      g_dwClientTickMs - *(int32_t *)((uint8_t *)this + nSlotIndex * 0x0Cu + 0x70u);
  uint32_t period =
      *(uint32_t *)((uint8_t *)this + nSlotIndex * 0x0Cu + 0x74u);

  if (period < elapsed) {
    *(uint8_t *)((uint8_t *)this + nSlotIndex * 0x0Cu + 0x78u) = 1;
    return 1;
  }
  return 0;
}
