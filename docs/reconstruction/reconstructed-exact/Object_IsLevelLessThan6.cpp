// =============================================================================
// Object_IsLevelLessThan6
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc460
// Address:   0x005cc460 – 0x005cc488  (autoassault.exe, image base 0x400000)
// System:    npc-ai / vehicle pursue gate
// Generated: 2026-07-29 W23-R dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Null-safe predicate: resolve object MI inner, call vtbl+0x27c (GetLevel),
//   return 1 iff level < 6. Sole named consumer: CVOGHBAICreatureBase_DoVehiclePursue
//   (low-level pursue branch — not a heading helper).
//
// ABI:
//   stdcall; one stack arg (obj*); ret 4; AL/EAX = 0/1.
// =============================================================================

#include <cstdint>

// Project convention: vtbl+0x27c = GetLevel (int). Sealed across combat/level duals.
using GetLevelFn = int(__thiscall *)(void *self);

extern "C" std::uint8_t __stdcall Object_IsLevelLessThan6(void *obj)
{
    if (obj == nullptr) {
        return 0;
    }

    // MSVC multi-inheritance this-adjust:
    //   adj = *(*(obj + 4) + 4); inner = obj + adj + 4
    auto *basePtr = *reinterpret_cast<std::uint8_t **>(reinterpret_cast<char *>(obj) + 4);
    auto  adj     = *reinterpret_cast<int *>(basePtr + 4);
    auto *inner   = reinterpret_cast<void *>(reinterpret_cast<char *>(obj) + adj + 4);
    auto *vtbl    = *reinterpret_cast<void ***>(inner);
    auto  getLvl  = reinterpret_cast<GetLevelFn>(vtbl[0x27c / sizeof(void *)]);

    int level = getLvl(inner);
    return (level < 6) ? 1 : 0;
}

// Ghidra name alias
extern "C" std::uint8_t __stdcall FUN_005cc460(void *obj)
{
    return Object_IsLevelLessThan6(obj);
}
