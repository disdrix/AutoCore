// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: CVOGHBList_Enqueue, EnterCriticalSection, FUN_005b3370, LeaveCriticalSection, Vehicle_CreateCombatPoolAction, list.
//  - Return sites: 2.

// =============================================================================
// CVOGHBList_Enqueue
// -----------------------------------------------------------------------------
// Purpose:  Append a CVOGHBBase* into the pending queue of a map-owned heartbeat
//           list (later promoted into the active set by CVOGHBList_Tick).
//
// Address:  0x005078f0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005078f0
// System:   client heartbeat / timed actions
//
// Convention: MSVC __thiscall
//   this     CVOGHBList*
//   pAction  CVOGHBBase* to enqueue (null → E_INVALIDARG)
//
// Returns:  0 on success; 0x80070057 (E_INVALIDARG) if pAction is null.
//
// Layout (list object):
//   +0x04  CRITICAL_SECTION
//   +0x28  CVOGHBBase** pending buffer
//   +0x2c  int pending count
//   +0x30  int pending capacity (low 31 bits; high bit may be sentinel)
//
// Grow path: FUN_005b3370(bufSlot, elementSize=4) when count == (cap & 0x7fffffff).
// Grow policy (FUN_005b3370): newCap = count==0 ? 1 : count*2; count unchanged.
// Callers: Vehicle_EnsureRegenerationHeartbeat, first-time tip HB, cast-again HB, ...
//
// Exactness: Behavior-preserving rewrite of raw decompile.
// Dual A/B sealed: 2026-07-29 (accept / accept)
// Human-refined plate: 2026-07-23 (AI managers readability); 2026-07-29 seal note
// =============================================================================

#include <cstdint>
#include <windows.h>

struct CVOGHBBase;

void FUN_005b3370(int* pBufSlot, int elementSize);

// list+offsets
static constexpr int kOffCritSec        = 0x04;
static constexpr int kOffPendingBuf     = 0x28;
static constexpr int kOffPendingCount   = 0x2c;
static constexpr int kOffPendingCapRaw  = 0x30;

static constexpr unsigned kEInvalidArg = 0x80070057u;

unsigned __thiscall CVOGHBList_Enqueue(void* thisList, CVOGHBBase* pAction)
{
    if (pAction == nullptr) {
        return kEInvalidArg;
    }

    auto* const base = reinterpret_cast<std::uint8_t*>(thisList);
    auto* const pCs  = reinterpret_cast<CRITICAL_SECTION*>(base + kOffCritSec);

    EnterCriticalSection(pCs);

    unsigned count = *reinterpret_cast<unsigned*>(base + kOffPendingCount);
    unsigned cap   = *reinterpret_cast<unsigned*>(base + kOffPendingCapRaw) & 0x7fffffffu;
    if (count == cap) {
        FUN_005b3370(reinterpret_cast<int*>(base + kOffPendingBuf), 4);
    }

    auto** ppBuf = *reinterpret_cast<CVOGHBBase***>(base + kOffPendingBuf);
    // re-read count after possible grow
    count = *reinterpret_cast<unsigned*>(base + kOffPendingCount);
    ppBuf[count] = pAction;
    *reinterpret_cast<int*>(base + kOffPendingCount) =
        static_cast<int>(count) + 1;

    LeaveCriticalSection(pCs);
    return 0;
}
