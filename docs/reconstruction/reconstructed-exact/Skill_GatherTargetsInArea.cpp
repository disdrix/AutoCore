// READABILITY (auto CF):
//  - Body size: ~244 non-empty decompiler lines.
//  - Control keywords: if×26, goto×7, return×3, while×2, do×1.
//  - Notable callees: CONCAT31, FUN_004073a0, FUN_004e8a40, FUN_004e9aa0, FUN_004ea350, FUN_00567ce0, FUN_0058a810, FUN_0058c7a0.
//  - Return sites: 3.

// =============================================================================
// Skill_GatherTargetsInArea
// -----------------------------------------------------------------------------
// Purpose:  Area / chain target collection (INFERRED name). When skill flags
//           request multi-target resolution, query nearby objects, filter by
//           mode (param_8), validate via FUN_0058a810, and append TFID entries
//           into the output list at param_1 (stride 0x10). Terminates with
//           invalid TFID sentinel (DAT_009d4d28..).
//
// Address:  0x0058d330  (autoassault.exe, image base 0x400000)
// Stable:   aa_0058d330
// System:   skills-abilities
//
// Parameters (decomp order; meanings Probable/INFERRED):
//   param_1   out TFID list base
//   param_2   starting write index (short count)
//   param_3   query arg
//   param_4   source/caster object*
//   param_5   origin TFID / pos dword4*
//   param_6   radius / range scalar
//   param_7   max targets (countdown)
//   param_8   gather mode — CF table sealed 2026-07-29 (see reviews/a_0058d330.md):
//             0 self/related  1 ally(+0x298==0)  2 hostile(+0x298!=0)
//             3 living interact (Veh/Cre/Char)  4 same +0x214 TFID
//             6 +0xdc-only broadphase  7 type-filter special (query 10)
//             8 unfiltered early-accept  9 type3 or hostile
//             10 dead/corpse (+0x198 allowed)  0xb same vehicle/crew
//             Skill path: skill+0x60c → mode, skill+0x610 → filterA
//   param_9   type filter into FUN_0058a810 (−1 = any)
//   param_10  chain-origin refresh flag
//   param_11  allow-self flag (with mode 1)
//   param_12  filterB → FUN_0058a810 (0 enables FUN_005134e0 gate)
//   param_13  filterC → FUN_0058a810 (non-0 allows flag bit10 outside mode 3)
//   param_14  sort-by-distance path (uses FUN_0058def0 / FUN_0058c7a0)
//   param_15  score arg
//
// Exactness: Behavior-preserving decompiler CF (labels collapsed to structured
//            control where equivalent). Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// Mode enum English/PDB names: INFERRED; CF sealed dual residual 2026-07-29.
//
// Remaining FUN_* / DAT_*: unresolved pending type recovery.
// =============================================================================

#include <cstdint>

extern "C" void* FUN_0058d9c0();
extern "C" void  FUN_00567ce0(void*, std::uint32_t);
extern "C" void  FUN_004e8a40(void*, void*);
extern "C" void  FUN_004ea350(std::uint32_t, std::uint32_t*, std::uint32_t, void*, int, std::uint32_t);
extern "C" void  FUN_004073a0(int* end, int count, int* value);
extern "C" char  FUN_0058a810(int*, int*, int, int, std::uint32_t, std::uint32_t, std::uint32_t, void*);
extern "C" long double FUN_004e9aa0(void*, int, std::uint32_t, std::uint32_t);
extern "C" void  FUN_0058def0(void*, float*);
extern "C" int   FUN_0058c7a0(int, void*, int, int);
extern "C" void  FUN_0058df60(void*, std::uint32_t, std::uint32_t*);
extern "C" void  operator_delete(void*);
extern "C" float g_flZero;
extern "C" std::uint32_t DAT_009d4d28, DAT_009d4d2c, DAT_009d4d30, DAT_009d4d34;
extern "C" char  DAT_00af32a0;
extern "C" void* ExceptionList;

void Skill_GatherTargetsInArea(
    int outTfidList,            // param_1
    int startIndex,             // param_2
    std::uint32_t queryArg,     // param_3
    int* pSource,               // param_4
    std::uint32_t* pOrigin,     // param_5
    std::uint32_t rangeArg,     // param_6
    int maxTargets,             // param_7
    int gatherMode,             // param_8
    std::uint32_t filterA,      // param_9
    char chainRefresh,          // param_10
    char allowSelfMode1,        // param_11
    std::uint32_t filterB,      // param_12
    std::uint32_t filterC,      // param_13
    char sortByDistance,        // param_14
    std::uint32_t scoreArg)     // param_15
{
    char ok;
    std::uint32_t* posPtr;
    std::uint32_t queryMode;
    int iTmp;
    int candRaw;
    int* selfRelated;
    void* candVecBase = nullptr; // filtered candidate entity ptrs
    int* candVecEnd = nullptr;
    bool skipCand;
    long double dist80;
    int entitySlot;
    std::uint32_t candIndex;
    int writeIndex = startIndex;
    std::uint32_t scratchPos[4];
    void* queryResults = nullptr;
    int queryEnd = 0;
    std::uint32_t queryCap = 0;
    std::uint32_t originCopy[4];
    float distF;
    std::uint8_t matScratch[24];
    std::uint8_t sortNode[8];
    std::uint8_t filterScratch[20];
    std::uint8_t sortHead[4];
    std::uint32_t* rbTree;
    std::uint32_t rbCount = 0;
    int sourceHandle = 0;
    int sourceExtra = 0;
    int candWalk = 0;
    float sortKey[2];
    int tfidTmp[4];
    void* sehPrev;
    // SEH frame simplified — retail installs ExceptionList

    sehPrev = ExceptionList;
    ExceptionList = &sehPrev;

    // Red-black / set root for distance sort path
    rbTree = (std::uint32_t*)FUN_0058d9c0();
    *(std::uint8_t*)((int)rbTree + 0x29) = 1;
    rbTree[1] = (std::uint32_t)rbTree;
    *rbTree = (std::uint32_t)rbTree;
    candVecEnd = nullptr;
    rbTree[2] = (std::uint32_t)rbTree;
    rbCount = 0;

    originCopy[0] = pOrigin[0];
    originCopy[1] = pOrigin[1];
    originCopy[2] = pOrigin[2];
    originCopy[3] = pOrigin[3];

    writeIndex = startIndex;

    // sourceHandle = source->vtbl[+0x1c8]()
    sourceHandle = (**(int(***)())(*pSource + 0x1c8))();
    if (sourceHandle == 0) {
        FUN_00567ce0(&DAT_00af32a0, 0x38d1b717);
        // decomp reuses uninitialized stack into pos — leave as-is (UB in retail path)
        scratchPos[0] = scratchPos[0];
        scratchPos[1] = scratchPos[1];
        scratchPos[2] = scratchPos[2];
    } else {
        posPtr = (std::uint32_t*)(**(int(***)())(
            *(int*)(*(int*)(*(int*)(sourceHandle + 4) + 4) + 4 + sourceHandle) + 0x1a4))();
        scratchPos[0] = posPtr[0];
        scratchPos[1] = posPtr[1];
        scratchPos[2] = posPtr[2];
        sourceExtra = posPtr[3];
    }
    scratchPos[3] = (std::uint32_t)sourceExtra;

    FUN_004e8a40(scratchPos, matScratch);

    candVecBase = nullptr;
    // cand vector triple (begin/end/cap) zeroed
    void* candBegin = nullptr;
    int* candEnd = nullptr;
    int candCap = 0;
    queryResults = nullptr;
    queryEnd = 0;
    queryCap = 0;

    // Spatial query mode from gatherMode
    queryMode = 1;
    if (0 < gatherMode) {
        if (gatherMode < 3) {
            queryMode = 0x11;
        } else if (gatherMode == 7) {
            queryMode = 10;
        }
    }

    FUN_004ea350(queryArg, pOrigin, rangeArg, &queryResults, 0, queryMode);

    // --- pass 1: filter query hits into candidate entity vector ---
    candIndex = 0;
    while ((queryResults != nullptr)
           && (candIndex < (std::uint32_t)(queryEnd - (int)queryResults >> 2)))
    {
        candRaw = *(int*)((int)queryResults + candIndex * 4);

        if (gatherMode == 7) {
            iTmp = (**(int(***)())(
                *(int*)(*(int*)(*(int*)(candRaw + 4) + 4) + 4 + candRaw) + 0x1dc))();
            skipCand = (iTmp == 0);
            goto filter_common;
        }

        if (gatherMode == 10) {
            ok = (**(char(***)())(
                *(int*)(*(int*)(*(int*)(candRaw + 4) + 4) + 4 + candRaw) + 0x198))();
            skipCand = (ok == '\0');
            goto filter_common;
        }

        if (gatherMode != 6) {
            // LAB_0058d534 — require +0xd4 object
            iTmp = *(int*)(*(int*)(candRaw + 4) + 4);
            if (*(int*)(iTmp + 0xd4 + candRaw) == 0) {
                goto try_0xdc;
            }
            goto accept_entity;
        }

    try_0xdc:
        // LAB_0058d547
        iTmp = *(int*)(*(int*)(candRaw + 4) + 4);
        if (*(int*)(iTmp + 0xdc + candRaw) != 0) {
        accept_entity:
            // LAB_0058d55a
            entitySlot = iTmp + candRaw + 4;
            goto push_candidate;
        }
        goto next_query;

    filter_common:
        // LAB_0058d521
        if (skipCand) {
            // fall into LAB_0058d534 path
            iTmp = *(int*)(*(int*)(candRaw + 4) + 4);
            if (*(int*)(iTmp + 0xd4 + candRaw) == 0) {
                goto try_0xdc;
            }
            goto accept_entity;
        }

        entitySlot = *(int*)(*(int*)(candRaw + 4) + 4) + 4 + candRaw;

    push_candidate:
        // LAB_0058d55d — push entitySlot into cand vector
        if ((candVecBase == nullptr)
            || ((std::uint32_t)(candCap - (int)candVecBase >> 2)
                <= (std::uint32_t)((int)candVecEnd - (int)candVecBase >> 2)))
        {
            FUN_004073a0(candVecEnd, 1, &entitySlot);
            candVecBase = candBegin;
            candVecEnd = candEnd;
            goto next_query;
        }

        *candVecEnd = entitySlot;
        candVecEnd = candVecEnd + 1;
        candIndex = candIndex + 1;
        candEnd = candVecEnd;
        continue;

    next_query:
        // LAB_0058d5a7
        candIndex = candIndex + 1;
    }

    // Count candidates
    if (candVecBase == nullptr) {
        candIndex = 0;
    } else {
        candIndex = (std::uint32_t)((int)candVecEnd - (int)candVecBase >> 2);
    }

    // sourceExtra from related object +0x34
    entitySlot = 0;
    iTmp = (**(int(***)())(*pSource + 0x19c))();
    if (iTmp != 0) {
        iTmp = (**(int(***)())(*pSource + 0x19c))();
        entitySlot = *(int*)(iTmp + 0x34);
    }

    // --- pass 2: validate + emit TFIDs ---
    candWalk = 0;
    if (0 < (int)candIndex) {
        do {
            int srcHandleSnap = sourceHandle;
            int* candEnt = *(int**)((int)candVecBase + candWalk * 4);

            if ((((chainRefresh == '\0') || (sourceHandle == 0))
                 || (iTmp = (**(int(***)())(*candEnt + 0x1c8))(), iTmp != srcHandleSnap))
                && (ok = FUN_0058a810(
                            candEnt, pSource, outTfidList, gatherMode, filterA, filterB, filterC,
                            filterScratch),
                    ok != '\0'))
            {
                selfRelated = (int*)(**(int(***)())(*pSource + 0x19c))();
                if (selfRelated != nullptr) {
                    selfRelated =
                        (int*)(*(int*)(selfRelated[1] + 4) + 4 + (int)selfRelated);
                }

                if (((selfRelated != candEnt) || (gatherMode == 0))
                    || ((gatherMode == 0xb
                         || ((gatherMode == 1 && (allowSelfMode1 != '\0'))))))
                {
                    iTmp = (**(int(***)(int))(*pSource + 0x210))(0);
                    std::uint32_t score = (**(std::uint32_t(***)(int*, std::uint32_t, int))(
                        *candEnt + 0x1c8))(&tfidTmp[0], scoreArg, iTmp != 0);

                    dist80 = FUN_004e9aa0(originCopy, entitySlot, rangeArg, score);
                    distF = (float)dist80;

                    if (sortByDistance == '\0') {
                        // Direct append TFID from candEnt[+0x58 .. +0x5b]
                        int* slot = (int*)((std::int16_t)writeIndex * 0x10 + outTfidList);
                        *slot = candEnt[0x58];
                        slot[1] = candEnt[0x59];
                        slot[2] = candEnt[0x5a];
                        writeIndex = writeIndex + 1;
                        slot[3] = candEnt[0x5b];

                        if (chainRefresh != '\0') {
                            // Refresh origin from candidate position
                            iTmp = (**(int(***)())(*candEnt + 0x1c8))();
                            if (*(int*)(iTmp + 8) == 0) {
                                posPtr = (std::uint32_t*)(
                                    *(int*)(*(int*)(iTmp + 4) + 4) + 0x84 + iTmp);
                            } else {
                                posPtr = (std::uint32_t*)(
                                    *(int*)(*(int*)(iTmp + 8) + 0x3c) + 0xb0);
                            }
                            originCopy[0] = posPtr[0];
                            originCopy[1] = posPtr[1];
                            originCopy[2] = posPtr[2];
                            originCopy[3] = posPtr[3];
                        }

                        if ((maxTargets != 0)
                            && (maxTargets = maxTargets + -1, maxTargets < 1))
                        {
                            goto write_terminator;
                        }
                    } else if (g_flZero < distF) {
                        // Sort-by-distance path
                        tfidTmp[0] = candEnt[0x58];
                        tfidTmp[1] = candEnt[0x59];
                        tfidTmp[2] = candEnt[0x5a];
                        tfidTmp[3] = candEnt[0x5b];
                        sortKey[0] = distF;
                        FUN_0058def0(sortNode, sortKey);
                    }
                }

                if ((std::int16_t)writeIndex == 99) {
                    break;
                }
            }

            candWalk = candWalk + 1;
        } while (candWalk < (int)candIndex);
    }

    if (sortByDistance != '\0') {
        writeIndex = FUN_0058c7a0(outTfidList, sortHead, maxTargets, (int)(std::int16_t)writeIndex);
    }

write_terminator:
    // Append invalid TFID sentinel
    posPtr = (std::uint32_t*)((std::int16_t)writeIndex * 0x10 + outTfidList);
    *posPtr = DAT_009d4d28;
    posPtr[1] = DAT_009d4d2c;
    posPtr[2] = DAT_009d4d30;
    posPtr[3] = DAT_009d4d34;

    if (queryResults != nullptr) {
        operator_delete(queryResults);
    }
    queryResults = nullptr;
    queryEnd = 0;
    queryCap = 0;

    if (candVecBase == nullptr) {
        FUN_0058df60(&distF, *rbTree, rbTree);
        operator_delete(rbTree);
    } else {
        operator_delete(candVecBase);
    }

    ExceptionList = sehPrev;
}
