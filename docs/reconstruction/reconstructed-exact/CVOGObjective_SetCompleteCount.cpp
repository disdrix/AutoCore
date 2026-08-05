// =============================================================================
// CVOGObjective_SetCompleteCount
// -----------------------------------------------------------------------------
// Stable ID: aa_0059d890
// Address:   0x0059d890  (autoassault.exe, image base 0x400000)
// Body:      0x0059d890–0x0059d89c (13 B; exclusive end 0x0059d89d)
// System:    missions-progression
// Generated: dual A/B seal 2026-07-29 (W21-J)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (static seal only).
// =============================================================================
//
// PURPOSE:
//   Write objective template field CompleteCount at this+0x164.
//   Product English sealed by sibling getter + FUN_005468c0 XML dump:
//     fprintf(..., "\t\t<CompleteCount>%i</CompleteCount>\r\n", GetCompleteCount());
//
//   Sole production caller (static):
//     - FUN_00547050 @ 0x005478a9 — mission/objective load path
//
//   Sibling getter (not this unit): CVOGObjective_GetCompleteCount @ 0x0059d880
//
// BODY (asm / memory):
//   0059d890  mov eax, [esp+4]         ; 8b 44 24 04
//   0059d894  mov [ecx+0x164], eax     ; 89 81 64 01 00 00
//   0059d89a  ret 4                    ; c2 04 00
//
// ABI: __thiscall (ECX = objective). One stack dword. ret 4.
// =============================================================================

#include <cstdint>

void __thiscall CVOGObjective_SetCompleteCount(void* objective /* ECX */,
                                               std::uint32_t completeCount)
{
  *reinterpret_cast<std::uint32_t*>(
      reinterpret_cast<std::uint8_t*>(objective) + 0x164) = completeCount;
}

// FUN_ alias for call-graph fidelity with unrenamed parents:
void __thiscall FUN_0059d890(void* objective, std::uint32_t completeCount)
{
  CVOGObjective_SetCompleteCount(objective, completeCount);
}
