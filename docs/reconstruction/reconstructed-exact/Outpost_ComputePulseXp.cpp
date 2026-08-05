// =============================================================================
// Outpost_ComputePulseXp
// -----------------------------------------------------------------------------
// Purpose:  Compute the periodic outpost (or non-outpost) pulse XP amount for a
//           character: levelSpan * percent * scalar, rounded via helper.
//
// Address:  0x00607830  (autoassault.exe, image base 0x400000)
// Stable:   aa_00607830
// System:   missions-progression / outpost XP
//
// Convention: MSVC __thiscall
//   this         outpost / pulse-state object
//   pCharacter   player character receiving the pulse
//
// Fields (INFERRED; see Outpost_GetPulseXpPercent sibling):
//   this+0x238  int   active/state gate  (< 1 → return 0)
//   this+0x21c  f32   pulse scalar       (consumed inside FUN_006a3db0 path)
//   this+0x220  char  bIsOutpost         (percent-table select)
//   this+0x23c  int   percent-table row
//
// Algorithm (docs/XP.md § Outpost pulse XP):
//   1) if state@+0x238 < 1: return 0
//   2) level = character.GetLevel() via vtable +0x27c on entity iface
//   3) thrHi = Experience_GetCumulativeThreshold(level)
//   4) if level > 1: thrLo = Experience_GetCumulativeThreshold(level - 1)
//      else thrLo is left as prior FPU/stack state (decompiler does not zero)
//   5) percent = Outpost_GetPulseXpPercent(this)   // table lookup
//   6) amount  = FUN_006a3db0()  // round(levelSpan * percent * scalar@+0x21c)
//
// Note: decompiler drops explicit FPU inputs to FUN_006a3db0; x87 stack carries
// thrHi/thrLo/percent/scalar from the preceding calls. Do not invent locals that
// the binary does not show.
//
// Callers often gate player level >= 60. Pulse interval data: 900000 ms.
// Sibling: Outpost_GetPulseXpPercent @ 0x006075b0
//
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// vtable slot for GetLevel (character entity iface) — retail +0x27c
// Path: *( *( *(character+4) + 4 ) + 4 + character )  then call [vtbl+0x27c]

unsigned  Experience_GetCumulativeThreshold(unsigned short level);
/*float10*/ Outpost_GetPulseXpPercent(/* this in ECX */);
// Round/combine helper: levelSpan * percent * scalar → integer XP
std::int64_t FUN_006a3db0(/* x87 args */);

std::int64_t __thiscall Outpost_ComputePulseXp(void* thisOutpost, void* pCharacter)
{
    unsigned short wPlayerLevel;
    short          sLevelMinus1;
    int            nLevelInt;
    std::int64_t   lAmount;

    // -------------------------------------------------------------------------
    // 1) Inactive / not ready → zero award
    // -------------------------------------------------------------------------
    if (*(int*)((int)thisOutpost + 0x238) < 1) {
        return 0;
    }

    // -------------------------------------------------------------------------
    // 2–3) Character level via multi-inherit vtable, cumulative threshold (hi)
    // -------------------------------------------------------------------------
    {
        // iface = *( *( *(pCharacter+4) + 4 ) + 4 + pCharacter )
        int* const pIface = reinterpret_cast<int*>(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>((int)pCharacter + 4) + 4)
            + 4 + (int)pCharacter);
        auto* const pVtbl = *reinterpret_cast<void***>(pIface);
        using GetLevelFn = unsigned short(__thiscall*)(int*);
        wPlayerLevel = reinterpret_cast<GetLevelFn>(pVtbl[0x27c / 4])(pIface);
    }
    Experience_GetCumulativeThreshold(wPlayerLevel);

    // -------------------------------------------------------------------------
    // 4) Level span lower edge when level > 1
    // -------------------------------------------------------------------------
    {
        int* const pIface = reinterpret_cast<int*>(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>((int)pCharacter + 4) + 4)
            + 4 + (int)pCharacter);
        auto* const pVtbl = *reinterpret_cast<void***>(pIface);
        using GetLevelFn = int(__thiscall*)(int*);
        nLevelInt = reinterpret_cast<GetLevelFn>(pVtbl[0x27c / 4])(pIface);
    }
    if (1 < nLevelInt) {
        int* const pIface = reinterpret_cast<int*>(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>((int)pCharacter + 4) + 4)
            + 4 + (int)pCharacter);
        auto* const pVtbl = *reinterpret_cast<void***>(pIface);
        using GetLevelFn = short(__thiscall*)(int*);
        sLevelMinus1 = reinterpret_cast<GetLevelFn>(pVtbl[0x27c / 4])(pIface);
        Experience_GetCumulativeThreshold(static_cast<unsigned short>(sLevelMinus1 - 1));
    }

    // -------------------------------------------------------------------------
    // 5–6) Percent table + round(span * percent * scalar)
    // -------------------------------------------------------------------------
    Outpost_GetPulseXpPercent(); // this = thisOutpost in ECX
    lAmount = FUN_006a3db0();
    return lAmount;
}
