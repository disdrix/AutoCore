// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: EnterCriticalSection, GetTickCount, LeaveCriticalSection,
//    CVOGHBBase::TryFire (vtbl+8), FUN_005b3370, HB dtor path.
//  - Return sites: 1.

// =============================================================================
// CVOGHBList_Tick
// -----------------------------------------------------------------------------
// Purpose:  Advance all active HBs one frame: update g_dwClientTickMs, TryFire
//           each, destroy/pop Remove (status & 0x10), then promote pending under CS.
//
// Address:  0x00507950  (autoassault.exe, image base 0x400000)
// Stable:   aa_00507950
// System:   heartbeat / timed-actions
//
// Convention: MSVC __thiscall
//   this                  CVOGHBList*
//   nForcedDeltaMsOrNull  0 -> GetTickCount(); else g_dwClientTickMs += delta
//
// Layout (this):
//   +0x04  CRITICAL_SECTION
//   +0x1c  active CVOGHBBase**    +0x20 count    +0x24 cap_raw (&0x7fffffff)
//   +0x28  pending CVOGHBBase**   +0x2c count    +0x30 cap_raw
//
// Remove: (*status & 0x10) → swap-pop last into hole (no index++); if !cStopped
//   call vtbl+0x18(1,1); refcount++; vtbl[0](1) deleting dtor. Under CS.
// Promote: after active loop, CS, append pending[0..n) to active (grow if full),
//   pending count = 0. Enqueue writes pending; Start only clears dormant.
//
// Live callers (both pass 0): FUN_0093e010, FUN_0094b520 via client+0xd38.
// NOTE: 16/0x10 is Remove status (shared token), NOT combat-pool regen period.
//
// Exactness: CF mirrors raw + live decompile 2026-07-29; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-29 (dual A/B strengthen)
// =============================================================================

#include <cstdint>
#include <windows.h>

extern unsigned g_dwClientTickMs; // VA 0x00b041cc

void FUN_005b3370(int* pBufSlot, int elementSize);

void __thiscall CVOGHBList_Tick(void* thisList, int nForcedDeltaMsOrNull)
{
    int* piVar1;
    int iVar2;
    unsigned char* pbVar3;
    int iVar4;
    LPCRITICAL_SECTION lpCriticalSection;

    if (nForcedDeltaMsOrNull == 0) {
        g_dwClientTickMs = GetTickCount();
    } else {
        g_dwClientTickMs = g_dwClientTickMs + static_cast<unsigned>(nForcedDeltaMsOrNull);
    }

    iVar4 = 0;
    if (0 < *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x20)) {
        do {
            piVar1 = *reinterpret_cast<int**>(
                *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x1c) + iVar4 * 4);
            // Decomp reuses nForcedDeltaMsOrNull stack slot as TryFire out-status.
            pbVar3 = reinterpret_cast<unsigned char*>(
                (*reinterpret_cast<int*(__thiscall**)(int*, int*)>(*piVar1 + 8))(
                    piVar1, &nForcedDeltaMsOrNull));
            if ((*pbVar3 & 0x10) == 0) {
                iVar4 = iVar4 + 1;
            } else {
                EnterCriticalSection(
                    reinterpret_cast<LPCRITICAL_SECTION>(reinterpret_cast<char*>(thisList) + 4));
                *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x20) =
                    *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x20) - 1;
                *reinterpret_cast<std::uint32_t*>(
                    *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x1c) + iVar4 * 4) =
                    *reinterpret_cast<std::uint32_t*>(
                        *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x1c) +
                        *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x20) * 4);
                if (static_cast<char>(piVar1[8]) == '\0') {
                    (*reinterpret_cast<void(__thiscall**)(int*, int, int)>(*piVar1 + 0x18))(
                        piVar1, 1, 1);
                }
                piVar1[1] = piVar1[1] + 1;
                (*reinterpret_cast<void(__thiscall**)(int*, int)>(*piVar1))(piVar1, 1);
                LeaveCriticalSection(
                    reinterpret_cast<LPCRITICAL_SECTION>(reinterpret_cast<char*>(thisList) + 4));
            }
        } while (iVar4 < *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x20));
    }

    lpCriticalSection =
        reinterpret_cast<LPCRITICAL_SECTION>(reinterpret_cast<char*>(thisList) + 4);
    nForcedDeltaMsOrNull = reinterpret_cast<int>(lpCriticalSection);
    EnterCriticalSection(lpCriticalSection);
    iVar4 = 0;
    if (0 < *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x2c)) {
        do {
            iVar2 = *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x28);
            if (*reinterpret_cast<unsigned*>(reinterpret_cast<char*>(thisList) + 0x20) ==
                (*reinterpret_cast<unsigned*>(reinterpret_cast<char*>(thisList) + 0x24) &
                 0x7fffffffu)) {
                FUN_005b3370(
                    reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x1c), 4);
            }
            *reinterpret_cast<std::uint32_t*>(
                *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x1c) +
                *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x20) * 4) =
                *reinterpret_cast<std::uint32_t*>(iVar2 + iVar4 * 4);
            *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x20) =
                *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x20) + 1;
            iVar4 = iVar4 + 1;
            lpCriticalSection = reinterpret_cast<LPCRITICAL_SECTION>(nForcedDeltaMsOrNull);
        } while (iVar4 < *reinterpret_cast<int*>(reinterpret_cast<char*>(thisList) + 0x2c));
    }
    *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(thisList) + 0x2c) = 0;
    LeaveCriticalSection(lpCriticalSection);
}
