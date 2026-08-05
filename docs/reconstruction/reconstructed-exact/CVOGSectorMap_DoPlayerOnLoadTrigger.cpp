// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGSectorMap_DoPlayerOnLoadTrigger, FUN_004bb1c0.
//  - Return sites: 2.

// =============================================================================
// CVOGSectorMap_DoPlayerOnLoadTrigger
// -----------------------------------------------------------------------------
// Purpose:  Fire m_coidPerPlayerLoadTrigger after a character is added to the
//           sector map (per-player on-load mission / reaction hook).
//
// Address:  0x004cdcc0  (autoassault.exe, image base 0x400000)
// Stable:   aa_004cdcc0
// System:   missions-progression (sector load hooks)
//
// Convention: MSVC __fastcall (sector map in ECX / param_1)
//
// Algorithm:
//   1) Resolve trigger object by TFID at sector+0xE7E0 / +0xE7E4
//      via FUN_004bb1c0 (object lookup by TFID, INFERRED)
//   2) If found: dual-base vtable+0x114 fire/activate (indirect call)
//
// Server analogue: SectorMap.FireOnLoadPlayerMissions after Stage3 creates.
// Caller: CVOGSectorMap_AddCharacter (always, after optional CreatorLoadTrigger).
// Sibling: CVOGSectorMap_DoCreatorLoadTrigger (once-per-map, flag sector+0x74).
//
// Exactness: Behavior-preserving rewrite of raw decompile.
// =============================================================================

#include <cstdint>

// sector map offsets
static constexpr int kOffPerPlayerLoadTriggerLo = 0xE7E0;
static constexpr int kOffPerPlayerLoadTriggerHi = 0xE7E4;

// Lookup world object by TFID pair (INFERRED name Client_LookupObjectByTfid path)
int FUN_004bb1c0(int unused, std::uint32_t tfidLo, std::uint32_t tfidHi);

void __fastcall CVOGSectorMap_DoPlayerOnLoadTrigger(void* pSectorMap)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(pSectorMap);

    const std::uint32_t tfidLo =
        *reinterpret_cast<std::uint32_t*>(base + kOffPerPlayerLoadTriggerLo);
    const std::uint32_t tfidHi =
        *reinterpret_cast<std::uint32_t*>(base + kOffPerPlayerLoadTriggerHi);

    int pTriggerObj = FUN_004bb1c0(0, tfidLo, tfidHi);
    if (pTriggerObj == 0) {
        return;
    }

    // Dual-base simple-object: this' = obj + *( *(obj+4) + 4 ) + 4
    // vtable slot +0x114 = fire / activate reaction chain.
    int* const pInner =
        reinterpret_cast<int*>(
            pTriggerObj +
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(pTriggerObj + 4) + 4) +
            4);
    using VFire = void (__thiscall*)(void*);
    auto* const pVTable = *reinterpret_cast<void***>(pInner);
    auto  const pFire   = reinterpret_cast<VFire>(pVTable[0x114 / sizeof(void*)]);
    pFire(pInner);
}
