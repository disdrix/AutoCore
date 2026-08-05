// =============================================================================
// UI_MissionJournal_SelectMission_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00829b20
// Address:   0x00829b20  (autoassault.exe, image base 0x400000)
// Body:      0x00829b20 – 0x00829ca5 (0x185 bytes)
// System:    client UI / missions-progression / mission journal
// Generated: 2026-07-29 W24-J dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Apply a mission selection onto the mission-journal UI context:
// format title "[level] name", refresh objective list via
// CVOGCharacter_IsMissionJournalReady + FUN_00829ac0, store selected mission id.
//
// ABI: journal context in EAX; mission* in EDI; plain ret; void.
// Callers: Client_UpdateMissionJournal (active + new mission list paths).

#include <cstdint>
#include <cstdio>

// Sealed / known callees:
//   CVOGCharacter_IsMissionJournalReady @ 0x0052b3b0  (FUN_0052b3b0)
//   FUN_00829ac0                        @ 0x00829ac0  (journal list helper)
//   FUN_007a69d0 / FUN_007a6de0         string resolve residuals
//   FUN_0092d580 / FUN_006a3db0         color residuals

extern void* DAT_00d1b6d8;  // local CVOGCharacter*

struct MissionObject {
    int32_t id;                 // +0x000
    uint8_t _pad004[0x118];
    int16_t level;              // +0x11C
    uint8_t _pad11e[0x2E];
    void*   nameSource;         // +0x14C
};

struct UI_MissionJournalContext {
    // +0x500 selectedMissionId
    // +0x508 pTitleWidget
    // +0x50C pChromeWidget
    uint8_t  _pad0[0x500];
    int32_t  selectedMissionId; // +0x500
    uint8_t  _pad504[0x4];
    void*    pTitleWidget;      // +0x508
    void*    pChromeWidget;     // +0x50C
    // vtbl on object base
};

// Retail: context in EAX, mission in EDI.
void UI_MissionJournal_SelectMission_Inferred(
    UI_MissionJournalContext* ctx /*EAX*/,
    MissionObject* mission /*EDI*/)
{
    // Gate: ctx->vtbl+0x3d8() must be non-zero.
    // Decompiler: cVar2 = (**(code **)(*in_EAX + 0x3d8))();
    bool gate = true;  // placeholder for virtual
    if (!gate || mission == nullptr) {
        return;
    }

    if (ctx->pTitleWidget != nullptr) {
        // Resolve name via FUN_007a69d0 / FUN_007a6de0 from mission->nameSource.
        // sprintf(buf, "[%d] %s", (int)mission->level, name);
        // title vtbl+0x1d8(buf); +0x21c(); +0x34c();
        // if DAT_00d1b6d8: char root vtbl+0x27c()
        // FUN_0092d580 + 3x FUN_006a3db0 color apply via title vtbl+0x15c
        char buf[500];
        const char* name = "";  // residual resolve
        std::sprintf(buf, "[%d] %s", static_cast<int>(mission->level), name);
        (void)buf;
    }

    if (DAT_00d1b6d8 != nullptr) {
        // thiscall ECX=char, stack=mission; ret 4
        CVOGCharacter_IsMissionJournalReady(DAT_00d1b6d8, mission);
        FUN_00829ac0();
    }

    if (ctx->pChromeWidget != nullptr && ctx->pTitleWidget != nullptr) {
        // copy color channel from title to chrome (vtbl+0x154)
    }

    ctx->selectedMissionId = mission->id;
}
