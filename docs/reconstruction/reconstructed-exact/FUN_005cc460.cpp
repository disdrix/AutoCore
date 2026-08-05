// =============================================================================
// FUN_005cc460  (alias twin of Object_IsLevelLessThan6)
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc460
// Address:   0x005cc460 – 0x005cc488  (autoassault.exe, image base 0x400000)
// System:    npc-ai / vehicle pursue gate
// Generated: 2026-07-29 W23-R dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// See Object_IsLevelLessThan6.cpp for named plate. This twin keeps Ghidra symbol
// for coverage / FUN_* index links.
// =============================================================================

#include <cstdint>

using GetLevelFn = int(__thiscall *)(void *self);

extern "C" std::uint8_t __stdcall Object_IsLevelLessThan6(void *obj);

extern "C" std::uint8_t __stdcall FUN_005cc460(void *obj)
{
    if (obj == nullptr) {
        return 0;
    }

    auto *basePtr = *reinterpret_cast<std::uint8_t **>(reinterpret_cast<char *>(obj) + 4);
    auto  adj     = *reinterpret_cast<int *>(basePtr + 4);
    auto *inner   = reinterpret_cast<void *>(reinterpret_cast<char *>(obj) + adj + 4);
    auto *vtbl    = *reinterpret_cast<void ***>(inner);
    auto  getLvl  = reinterpret_cast<GetLevelFn>(vtbl[0x27c / sizeof(void *)]);

    int level = getLvl(inner);
    return (level < 6) ? 1 : 0;
}
