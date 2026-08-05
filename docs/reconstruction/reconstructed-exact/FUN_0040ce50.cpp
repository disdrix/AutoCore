// =============================================================================
// Vehicle_GetModChipSkill_Inferred  (Ghidra: FUN_0040ce50)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ce50
// Address:   0x0040ce50  (autoassault.exe, image base 0x400000)
// System:    input-drive-control / vehicle race-item (mod-chip skill binding)
// Generated: 2026-07-29 dual A/B (from raw 2026-07-23 + live decompile/bytes)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Pure vehicle getter for the equipped **mod-chip skill binding**.
//   Loads race-item hardpoint vehicle+0x270; if null returns sentinel -1;
//   else dual-base walk (same form as Vehicle_GetHpRegenRate / GetShieldRegenRate)
//   to subrecord +0x3C and returns dword at +0x3BC.
//
// ABI: __fastcall — ECX = vehicle*; no stack args; plain ret.
// Returns: u32 skill-binding dword, or 0xFFFFFFFF when no race item.
//
// Sole caller: Client_Input_TryUseModChip (0x0091f6b0)
//   ret == -1 → modal "You have no mod chip!"
//   else → Skill_LocalCastValidate(..., skill=ret) then C2S 0x202c on allow.
//
// Twin field walks on same race-item subrecord:
//   GetHpRegenRate     short @ +0x3FA (null → 0)
//   GetShieldRegenRate short @ +0x4B6 (null → 0)
//   THIS               dword @ +0x3BC (null → -1)
// =============================================================================

#include <cstdint>

/* dual-base: adj = *(*( *(obj+4)+4 ) + 0xAC + obj); sub = *(adj + 0x3C) */

uint32_t __fastcall Vehicle_GetModChipSkill_Inferred(void *vehicle /* ECX */)
{
  void *pRaceItem;
  int adj;
  int sub;

  /* SECTION 1: race-item hardpoint */
  pRaceItem = *(void **)((char *)vehicle + 0x270);
  if (pRaceItem == (void *)0x0) {
    /* SECTION 2: no race item → sentinel -1 (not null/0) */
    return 0xffffffffu;
  }

  /* SECTION 3: dual-base adjust → subrecord → skill binding dword */
  adj = *(int *)(*(int *)(*(int *)((char *)pRaceItem + 4) + 4) + 0xac +
                 (int)pRaceItem);
  sub = *(int *)(adj + 0x3c);
  return *(uint32_t *)(sub + 0x3bc);
}
