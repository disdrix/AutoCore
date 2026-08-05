// =============================================================================
// CVOGCharacter_CompleteRegionMissions
// -----------------------------------------------------------------------------
// Stable ID: aa_00536740
// Address:   0x00536740  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 dual W18-J (raw 2026-07-23 + live re-decompile)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Debug / bulk driver that walks the global mission-definition hash
// (via Mission_EnsureRegionMissions / FUN_0053fff0), filters by region (+0x128)
// and optional pocket (+0x12c, -1 = any), race/class-ish gates against the
// nested game blob, skips completed hash char+0x538 live entries, then fires
// CVOGCharacter_CheckMissionPrerequisites(this, id, autoComplete=1, checkLevel=1)
// for each remaining def. Always returns 1.
//
// Sole sealed caller: client debug chat @ 0x009544aa
//   toast "Completing region: %i, pocket: %i" (0x00a28a18).
//
// Contrast: SearchAutoMissions (0x00532b60) filters AutoAssign def+0xF8 and
// uses Requirements+GiveMission — different product path.
// =============================================================================

#include <cstdint>

extern void *ExceptionList;
extern int DAT_00b041fc;

// Mission_EnsureRegionMissions — ECX = DAT_00b041fc; returns wrapper* (hash at *wrapper).
int *FUN_0053fff0();

// Temp intrusive list helpers (MS list node family used as snapshot buffer).
int *FUN_0040fb90();                 // empty list head
int FUN_00418700(int *list, int tail, int *valueHolder);
void FUN_00404840(int flag);
void FUN_00403430();                 // list dtor / clear (thiscall on list)

void FUN_007a4480(int level, const char *fmt, ...);

// Award cascade — dual aa_00536540.
std::uint32_t __thiscall CVOGCharacter_CheckMissionPrerequisites(
    void *character,
    std::uint32_t missionId,
    char autoComplete,
    char checkLevel);

// -----------------------------------------------------------------------------
// uint __thiscall CompleteRegionMissions(character, region, pocket)
// ret 8
// -----------------------------------------------------------------------------
std::uint32_t __thiscall CVOGCharacter_CompleteRegionMissions(
    void *thisCharacter,
    std::uint32_t region,
    std::uint32_t pocket)
{
    std::uint32_t *missionDef;
    std::uint32_t missionId;
    int *listHead;
    int *hashWrap;
    int hashObj;
    int cursor;
    int listNode;
    int valueSlot[2];
    int *listSaved;
    std::uint32_t sehGuard;
    void *prevException;
    std::uint8_t *sehHandler;
    std::uint32_t sehState;

    sehState = 0xffffffffu;
    sehHandler = reinterpret_cast<std::uint8_t *>(&sehState); // LAB_009a3d0c in image
    (void)sehHandler;
    prevException = ExceptionList;
    cursor = 0;
    ExceptionList = &prevException;

    listHead = FUN_0040fb90();
    sehGuard = 0;
    sehState = 0;
    listSaved = listHead;

    // --- Phase 1: lock mission-def hash and snapshot all values into temp list ---
    hashWrap = FUN_0053fff0(); // ECX loaded from DAT_00b041fc by caller convention
    hashObj = *hashWrap;
    if (*reinterpret_cast<char *>(hashObj + 0x1d) != '\0') {
        FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    *reinterpret_cast<std::uint8_t *>(hashObj + 0x1d) = 1;

    while (true) {
        hashWrap = FUN_0053fff0();
        hashObj = *hashWrap;
        if (*reinterpret_cast<char *>(hashObj + 0x1d) == '\0') {
            FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }
        if (cursor == 0) {
            cursor = *reinterpret_cast<int *>(hashObj + 0x14);
        } else {
            cursor = *reinterpret_cast<int *>(cursor + 0x14);
        }
        if (cursor == 0) {
            valueSlot[0] = 0;
        } else {
            valueSlot[0] = *reinterpret_cast<int *>(cursor + 8);
        }
        if (valueSlot[0] == 0) {
            break;
        }
        listNode = FUN_00418700(listSaved, listHead[1], valueSlot);
        FUN_00404840(1);
        listHead[1] = listNode;
        **reinterpret_cast<int **>(listNode + 4) = listNode;
        listHead = listSaved;
    }

    hashWrap = FUN_0053fff0();
    *reinterpret_cast<std::uint8_t *>(*hashWrap + 0x1d) = 0;

    // --- Phase 2: filter snapshot + award cascade (hash unlocked) ---
    int *it = reinterpret_cast<int *>(*listHead);
    if (it != listHead) {
        do {
            missionDef = reinterpret_cast<std::uint32_t *>(it[2]);
            if (missionDef[0x4a] == region && // def+0x128
                (pocket == 0xffffffffu || missionDef[0x4b] == pocket)) { // def+0x12c
                int game = *reinterpret_cast<int *>(
                    *reinterpret_cast<int *>(
                        *reinterpret_cast<int *>(
                            *reinterpret_cast<int *>(
                                reinterpret_cast<char *>(thisCharacter) + 4) +
                            4) +
                        0xac + reinterpret_cast<int>(thisCharacter)) +
                    0x3c);
                if (static_cast<std::uint16_t>(missionDef[0x24]) == // def+0x90
                        static_cast<std::uint16_t>(
                            *reinterpret_cast<std::uint8_t *>(game + 0x532)) &&
                    (*reinterpret_cast<std::uint16_t *>(
                         reinterpret_cast<char *>(missionDef) + 0x92) == 0xffffu ||
                     *reinterpret_cast<std::uint16_t *>(
                         reinterpret_cast<char *>(missionDef) + 0x92) ==
                         static_cast<std::uint16_t>(
                             *reinterpret_cast<std::uint8_t *>(game + 0x531)))) {
                    missionId = *missionDef;
                    // completed-hash walk at this+0x538
                    int completed = *reinterpret_cast<int *>(
                        reinterpret_cast<char *>(thisCharacter) + 0x538);
                    int bucketMask = *reinterpret_cast<int *>(completed + 8);
                    int table = *reinterpret_cast<int *>(completed + 0x10);
                    int node = *reinterpret_cast<int *>(
                        *reinterpret_cast<int *>(table + (bucketMask & missionId) * 4) + 4);
                    for (; node != 0; node = *reinterpret_cast<int *>(node + 0x0c)) {
                        if (missionId == *reinterpret_cast<std::uint32_t *>(node + 0x10)) {
                            if (node != 0 &&
                                *reinterpret_cast<int *>(node + 8) != 0) {
                                goto next_def; // already completed with live payload
                            }
                            break;
                        }
                    }
                    CVOGCharacter_CheckMissionPrerequisites(
                        thisCharacter, missionId, /*autoComplete*/ 1, /*checkLevel*/ 1);
                }
            }
        next_def:
            it = reinterpret_cast<int *>(*it);
        } while (it != listSaved);
    }

    FUN_00403430(); // destroy temp list (thiscall ECX = list)
    ExceptionList = prevException;
    return 1;
}
