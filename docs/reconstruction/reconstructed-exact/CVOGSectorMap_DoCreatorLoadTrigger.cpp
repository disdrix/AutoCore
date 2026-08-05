// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CVOGSectorMap_DoCreatorLoadTrigger, FUN_004bb1c0, GetTickCount, instance.
//  - Return sites: 2.

// =============================================================================
// CVOGSectorMap_DoCreatorLoadTrigger
// -----------------------------------------------------------------------------
// Purpose:  Once-per-map-instance fire of m_coidCreatorLoadTrigger (sector
//           creator / instance-start reaction hook).
//
// Address:  0x004cdd20  (autoassault.exe, image base 0x400000)
// Stable:   aa_004cdd20
// System:   missions-progression (sector load hooks)
//
// Convention: MSVC __fastcall (sector map in ECX)
//
// Algorithm:
//   if sector+0x74 already set: return
//   set +0x74 = 1; stamp +0x6C = GetTickCount()
//   resolve TFID at +0xE7E8/+0xE7EC via FUN_004bb1c0
//   if found: dual-base vtable+0x114 fire
//
// Caller: CVOGSectorMap_AddCharacter when character-count condition met.
// Sibling: CVOGSectorMap_DoPlayerOnLoadTrigger (every add).
//
// Exactness: Behavior-preserving rewrite of raw decompile.
// =============================================================================

#include <cstdint>
#include <windows.h>

static constexpr int kOffCreatorFiredFlag   = 0x74;
static constexpr int kOffCreatorStampMs     = 0x6C;
static constexpr int kOffCreatorTriggerLo   = 0xE7E8;
static constexpr int kOffCreatorTriggerHi   = 0xE7EC;

int FUN_004bb1c0(int unused, std::uint32_t tfidLo, std::uint32_t tfidHi);

void __fastcall CVOGSectorMap_DoCreatorLoadTrigger(void* pSectorMap)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(pSectorMap);

    if (*reinterpret_cast<char*>(base + kOffCreatorFiredFlag) != '\0') {
        return;
    }

    *reinterpret_cast<char*>(base + kOffCreatorFiredFlag) = 1;
    *reinterpret_cast<DWORD*>(base + kOffCreatorStampMs) = GetTickCount();

    const std::uint32_t tfidLo =
        *reinterpret_cast<std::uint32_t*>(base + kOffCreatorTriggerLo);
    const std::uint32_t tfidHi =
        *reinterpret_cast<std::uint32_t*>(base + kOffCreatorTriggerHi);

    int pTriggerObj = FUN_004bb1c0(0, tfidLo, tfidHi);
    if (pTriggerObj == 0) {
        return;
    }

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
