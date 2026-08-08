// =============================================================================
// FUN_004111d0  (Ghidra twin of Character_GetXpRemainingToMaxLevelSoftCap_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004111d0
// Address:   0x004111d0 – 0x004111e9  (26 B)  autoassault.exe base 0x400000
// System:    missions-progression
// Generated: 2026-08-05 MEGA-124 dual (live Ghidra)
// Exactness: Behavior-preserving rewrite of decompiler + bytes. Not modernization.
// Canonical clean: Character_GetXpRemainingToMaxLevelSoftCap_Inferred.cpp
// =============================================================================

#include <cstdint>

unsigned __cdecl Experience_GetCumulativeThreshold(unsigned short wLevel);

// Decompiler shape (unaff_ESI = character*):
//   threshold = Experience_GetCumulativeThreshold(*(ushort*)(esi+0xc50));
//   return (threshold - *(int*)(esi+0x730)) - 1;
//
// ABI: ESI=Character*, EAX=int, bare RET.

int FUN_004111d0(/* ESI */ void* character)
{
    unsigned uVar1 = Experience_GetCumulativeThreshold(
        *reinterpret_cast<unsigned short*>(
            reinterpret_cast<char*>(character) + 0xc50));
    return static_cast<int>(uVar1)
         - *reinterpret_cast<int*>(reinterpret_cast<char*>(character) + 0x730)
         - 1;
}
