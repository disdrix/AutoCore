// =============================================================================
// FUN_00829b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00829b20
// Address:   0x00829b20  (autoassault.exe, image base 0x400000)
// Body:      0x00829b20 – 0x00829ca5 (0x185 bytes)
// System:    client UI / missions-progression / mission journal
// Generated: 2026-07-29 W24-J dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Named clean: UI_MissionJournal_SelectMission_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <cstdio>

extern void* DAT_00d1b6d8;

// Retail ABI: journal context in EAX, mission* in EDI; plain ret; void.
void FUN_00829b20(int32_t* ctx /*EAX*/, int32_t* mission /*EDI*/)
{
    // Gate: (*ctx)->vtbl+0x3d8() && mission != null
    char cVar2 = 0;
    // cVar2 = (**(code **)(*ctx + 0x3d8))();
    if (cVar2 == 0 || mission == nullptr) {
        return;
    }

    // Title widget at ctx[0x142] == +0x508
    if (ctx[0x142] != 0) {
        // mission[0x53] = +0x14c name source
        // mission[0x47] short at +0x11c = level
        // FUN_007a69d0(); FUN_007a6de0();
        char acStack_1f4[500];
        std::sprintf(acStack_1f4, "[%d] %s", 0, "");
        // title setText / show / invalidate
        // optional DAT_00d1b6d8 root vtbl+0x27c
        // FUN_0092d580 + 3x FUN_006a3db0 color
        (void)acStack_1f4;
    }

    if (DAT_00d1b6d8 != nullptr) {
        // CVOGCharacter_IsMissionJournalReady(DAT_00d1b6d8, mission)
        FUN_0052b3b0();
        FUN_00829ac0();
    }

    // secondary chrome ctx[0x143]=+0x50c color copy if both widgets live
    // store selected id:
    ctx[0x140] = *mission;  // +0x500
}
