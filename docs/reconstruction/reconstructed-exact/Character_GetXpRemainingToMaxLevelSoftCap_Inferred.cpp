// =============================================================================
// Character_GetXpRemainingToMaxLevelSoftCap_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004111d0
// Address:   0x004111d0 – 0x004111e9  (26 B)  autoassault.exe base 0x400000
// System:    missions-progression
// Generated: 2026-08-05 MEGA-124 dual (live Ghidra)
// Exactness: Behavior-preserving rewrite of decompiler + bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Return how much XP the character can still receive before the max-level
//   soft-cap:  threshold(maxLevel) - totalXp - 1.
//
//   Used by Client_ShowMissionRewardChatToast to clamp the "Awarded N …" XP
//   toast when specialMode (char+0x6b4) < 1 and the scaled award would exceed
//   remaining room.
//
// ABI (customcall):
//   ESI  = Character*
//   EAX  = int remaining (may be negative if already over soft-cap)
//   bare RET (no stack formals)
//
// Character offsets (sealed cross-units):
//   +0xc50  nMaxLevel            ushort  → Experience_GetCumulativeThreshold key
//   +0x730  nTotalExperience     int32   absolute XP
//
// Callee:
//   Experience_GetCumulativeThreshold @ 0x0052c860  (__cdecl, ushort level)
//
// Callers (2):
//   Client_ShowMissionRewardChatToast @ 0x008ac63d, 0x008ac64c
//
// Soft-cap policy twin (not this unit):
//   CVOGReaction_AddExperience writes totalXp = threshold(level) - 1 at max.
// =============================================================================

#include <cstdint>

// Forward: dualed XP table lookup (aa_0052c860)
unsigned __cdecl Experience_GetCumulativeThreshold(unsigned short wLevel);

// Ghidra twin name retained for xref search.
// int FUN_004111d0(void);  // ESI = character*

int Character_GetXpRemainingToMaxLevelSoftCap_Inferred(/* ESI */ void* character)
{
    // Bytes: MOV AX, word ptr [ESI+0xc50]; PUSH EAX; CALL 0x0052c860
    unsigned threshold = Experience_GetCumulativeThreshold(
        *reinterpret_cast<unsigned short*>(
            reinterpret_cast<char*>(character) + 0xc50));

    // Bytes: SUB EAX, dword ptr [ESI+0x730]; ADD ESP,4; SUB EAX,1; RET
    int totalXp = *reinterpret_cast<int*>(
        reinterpret_cast<char*>(character) + 0x730);

    return static_cast<int>(threshold) - totalXp - 1;
}
