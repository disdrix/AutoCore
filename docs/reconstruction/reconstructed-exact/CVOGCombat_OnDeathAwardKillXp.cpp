// READABILITY (auto CF):
//  - Body size: ~357 non-empty decompiler lines.
//  - Control keywords: if×46, goto×8, return×5, while×5, do×4.
//  - Notable callees: FUN_00521510×4, FUN_00404c90×3, FUN_004d2820×3, SQRT×3, __RTDynamicCast×3, FUN_004c4b20×2, FUN_004d31a0×2, FUN_00574760×2.
//  - Strings: "allocatenewobjectfromcbid failed %d".
//  - Return sites: 5.

// =============================================================================
// CVOGCombat_OnDeathAwardKillXp
// -----------------------------------------------------------------------------
// Purpose:  Death/loot handler: resolve killer character, build participation
//           mult (XPPercent × share × convoy terms), award kill XP to solo or
//           up to 4 in-range convoy members, then credits/loot side paths.
//
// Address:  0x004da630  (autoassault.exe, image base 0x400000)
// Stable:   aa_004da630
// System:   missions-progression / combat XP
//
// Convention: MSVC __thiscall
//   this / param_1  = combat / loot context (flags +0x100, +0x108, +0xac)
//   param_2         = killer-side object* (null → early return)
//   param_3         = victim cloned object* (creature/vehicle)
//
// Returns:  void* (SEH / loot object leftovers; side-effect heavy)
//
// Major phases:
//   A) Resolve killer character via param_2 vtable +0x210; ensure loot helper
//   B) Snapshot victim position (param_3[0x20..0x23]); optional damage share
//   C) Type switch on template kind (+0x38): 0x0e vehicle, 0x12 creature
//   D) Award path:
//        - solo (no convoy flag +0xcb0): CalculateAndAwardKillXP count=0
//        - convoy: loop 0..3, distance < DAT_00aaa8a8, award with member count
//        - list path: TFID list at +0x158, count hardcoded 4
//   E) Credits / loot drops if local flag +0xf6 clear (after XP block)
//
// Mult product at award: template.XPPercent(+0x500) * local_74 * share(fStack_70)
// Distance gate: SQRT((dz)^2 + (dx)^2) < DAT_00aaa8a8 (image 0x00AAA8A8 ≈ 300.f)
//
// Ghidra note: unreachable block at 0x004dad5f removed by decompiler.
// Exactness: Human-refined; control flow / call order mirrors raw (2026-07-23).
// Dual reviews: reviews/A_aa_004da630_review.md, reviews/B_aa_004da630_review.md
// =============================================================================

#include <cmath>
#include <cstdint>

// SEH / CRT
extern void* ExceptionList;
void* operator_new(unsigned size);

// Kill award
void CVOGCombat_CalculateAndAwardKillXP(int nPlayerLevel, int nVictimLevel,
                                        float flParticipationMult, void* pCharacter,
                                        int nConvoyMemberCount, int nUnused);

// Helpers still FUN_* / named where known
void* Object_ResolveFromTFID(void* pTfid16);
void* __RTDynamicCast(void* obj, int, void* from, void* to, int);
int   CVOGReaction_RandomUnitScalar();
int*  CVOGReaction_GiveItemByCbid(int cbid);
int   FUN_0050c1b0(int);
int   FUN_0051f7b0();
int   FUN_004d31a0(int, int);
int   FUN_00574760(float index);
int   FUN_004f4e50();
int   FUN_004c4b20();
char  FUN_004c4aa0();
void  FUN_00574900();
int   FUN_00574e60(void* killerChar);
void  FUN_00574910();
void  FUN_004cb270();
long long FUN_00508e70(void* killerChar, float);
void* FUN_00521510(void* pos);
void  FUN_004d2750(long long, void* pos, float, int, void*);
void* FUN_00404c90();
void  FUN_0050ac80(void*, int, void*, int, float, int, int);
void  FUN_004d4440(int, void*, void*, float, int, int);
void* FUN_0040fb90();
void  FUN_0050aa80(unsigned, int, unsigned char, void*);
void  FUN_00404060();
void  FUN_00509010(int* victim, unsigned char, void*);
void  FUN_00403430();
void* FUN_004d2820(void* item, void* pos, float, int);
void* FUN_007a4480(int, const char*, ...);
int   FUN_005001f0();

extern float g_flOne;
extern float DAT_00aaa8a8; // convoy range ≈ 300.f
extern int   DAT_00b037e8; // loot helper singleton
extern int   DAT_00b041fc;

// RTTI anchors (names from decompiler)
extern void* CVOGClonedObjectBase_RTTI;
extern void* CVOGCreature_RTTI;
extern void* CVOGVehicle_RTTI;
extern void* CVOGPhysicsBase_RTTI;
extern unsigned char LAB_009a22ad;

// Template kind discriminators (param_3[0x2a]+0x38)
enum { kTemplateVehicle = 0x0e, kTemplateCreature = 0x12 };

void* __thiscall CVOGCombat_OnDeathAwardKillXp(int pLootCtx, int* pKillerObj, int* pVictimObj)
{
    float  fLootChance;
    unsigned short uRand;
    char   cCreatureOk;
    char   cShareFlag;
    void*  pKillerChar;
    void*  pTmp;
    int    iTmp;
    float* pfPos;
    int    iMember;
    int*   piListHead;
    int*   piListNode;
    unsigned uKind;
    unsigned uRandFull;
    int    unaff_EDI;
    long double fShare10;
    long long lCredits;
    void*  uPosPack;
    int    nConvoyMemberCount;
    int    pVehicleSide;   // local_80 - non-zero when victim template is vehicle (0xe)
    int    nVictimLevel;   // iStack_7c
    int    pCreatureSide;  // local_78 - non-zero when victim template is creature (0x12)
    float  flShareOrOne;   // local_74 - starts g_flOne; reused for credit scalar later
    float  flParticipationShare; // fStack_70 - damage/share product input
    int    pXpTemplate;    // iStack_6c - points at structure with XPPercent @ +0x500
    int    iConvoyIdx;     // iStack_68
    unsigned char auStack_4c[4];
    int*   piLootList;
    int    iLootFlag;
    float  fPosX;          // fStack_40 - victim X
    int    iPosY;
    float  fPosZ;          // fStack_38 - victim Z
    int    iPosW;
    int    iStack_30, iStack_2c, iStack_24;
    void*  pvStack_28;
    void*  pSehPrev;
    unsigned char* pSehHandler;
    unsigned uSehState;

    // SEH frame
    uSehState = 0xffffffff;
    pSehHandler = &LAB_009a22ad;
    pSehPrev = ExceptionList;
    if (pKillerObj == nullptr) {
        return ExceptionList;
    }
    pCreatureSide = 0;
    pVehicleSide = 0;
    flShareOrOne = g_flOne;
    ExceptionList = &pSehPrev;

    // ----- A) Killer character via vtable +0x210 -----
    pKillerChar = (void*)(**(int (**)(int))(*pKillerObj + 0x210))(0);
    if (pKillerChar == nullptr) {
        ExceptionList = pSehPrev;
        return nullptr;
    }

    // Ensure global loot helper singleton DAT_00b037e8
    if (DAT_00b037e8 == 0) {
        pTmp = operator_new(0xbc);
        uSehState = 0;
        if (pTmp == nullptr) {
            DAT_00b037e8 = 0;
        } else {
            DAT_00b037e8 = FUN_0050c1b0(DAT_00b041fc);
        }
        uSehState = 0xffffffff;
    }

    // ----- B) Victim position snapshot + optional damage share -----
    (**(int (**)())(*pVictimObj + 0x144))();
    fPosX = (float)pVictimObj[0x20];
    iPosY = pVictimObj[0x21];
    fPosZ = (float)pVictimObj[0x22];
    iPosW = pVictimObj[0x23];

    iTmp = (**(int (**)(int))(*pVictimObj + 0x210))(0);
    if (iTmp != 0) {
        (**(int (**)(int))(*pVictimObj + 0x210))(0);
        fShare10 = (long double)FUN_0051f7b0();
        flShareOrOne = (float)fShare10;

        // Optional assist bookkeeping when loot-ctx mode==3 and victim flag +0x529
        if (((*(char*)(pLootCtx + 0x100) != '\0') && (*(int*)(pLootCtx + 0x108) != -1)) &&
            (*(int*)(pLootCtx + 0xac) == 3) &&
            ((iTmp = (**(int (**)(int))(*pVictimObj + 0x210))(0),
              *(char*)(iTmp + 0x529) != '\0') &&
             (pTmp = (void*)(**(int (**)(int))(*pVictimObj + 0x210))(0),
              pKillerChar != pTmp))) {
            if (*(int*)((int)pKillerChar + 0xcb0) == 0) {
                // Solo assist tag
                iTmp = (**(int (**)(int))(*pVictimObj + 0x210))(0);
                if (iTmp == 0) {
                    iTmp = 0;
                } else {
                    iTmp = *(int*)(*(int*)(iTmp + 4) + 4) + 4 + iTmp;
                }
                FUN_004d31a0(*(int*)(*(int*)((int)pKillerChar + 4) + 4) + 4 + (int)pKillerChar,
                            iTmp);
            } else {
                // Convoy assist: up to 4 in-range members
                flParticipationShare = 0.0f;
                do {
                    iTmp = FUN_00574760(flParticipationShare);
                    if ((iTmp != 0) &&
                        (pfPos = (float*)(**(int (**)())(
                                     *(int*)(*(int*)(*(int*)(iTmp + 4) + 4) + 4 + iTmp) + 0x1a0))(),
                         sqrtf((fPosZ - pfPos[2]) * (fPosZ - pfPos[2]) +
                               (fPosX - *pfPos) * (fPosX - *pfPos)) < DAT_00aaa8a8)) {
                        iMember = (**(int (**)(int))(*pVictimObj + 0x210))(0);
                        if (iMember != 0) {
                            iMember = *(int*)(*(int*)(iMember + 4) + 4) + 4 + iMember;
                        }
                        FUN_004d31a0(*(int*)(*(int*)(iTmp + 4) + 4) + 4 + iTmp, iMember);
                    }
                    flParticipationShare = (float)((int)flParticipationShare + 1);
                } while ((int)flParticipationShare < 4);
            }
        }
    }

    // ----- C) Resolve victim level + XP template by type (0xe vehicle / 0x12 creature) -----
    if (*(int*)(pVictimObj[0x2a] + 0x38) == kTemplateVehicle) {
        pVehicleSide = (**(int (**)())(*pVictimObj + 0x1d4))();
        nVictimLevel = FUN_004f4e50();
        iTmp = (**(int (**)())(
            *(int*)(*(int*)(*(int*)(pVehicleSide + 4) + 4) + 4 + pVehicleSide) + 0x214))();
        pXpTemplate =
            *(int*)(*(int*)(*(int*)(*(int*)(iTmp + 4) + 4) + 0xac + iTmp) + 0x3c);
        (**(int (**)())(
            *(int*)(*(int*)(*(int*)(pVehicleSide + 4) + 4) + 4 + pVehicleSide) + 0x214))();
        fShare10 = (long double)FUN_004c4b20();
        iTmp = (**(int (**)())(
            *(int*)(*(int*)(*(int*)(pVehicleSide + 4) + 4) + 4 + pVehicleSide) + 0x214))();
        cShareFlag = *(char*)(iTmp + 0x30a);
    } else {
        if (*(int*)(pVictimObj[0x2a] + 0x38) != kTemplateCreature)
            goto loot_and_exit; // LAB_004dae57
        pCreatureSide = (**(int (**)())(*pVictimObj + 0x214))();
        nVictimLevel = (**(int (**)())(
            *(int*)(*(int*)(*(int*)(pCreatureSide + 4) + 4) + 4 + pCreatureSide) + 0x27c))();
        cCreatureOk = FUN_004c4aa0();
        cShareFlag = *(char*)(pCreatureSide + 0x30a);
        pXpTemplate = *(int*)(*(int*)(*(int*)(*(int*)(pCreatureSide + 4) + 4) + 0xac +
                                     pCreatureSide) +
                              0x3c);
        fShare10 = (long double)FUN_004c4b20();
        if (cCreatureOk == '\0')
            goto loot_and_exit;
    }

    flParticipationShare = (float)fShare10;
    if (pXpTemplate == 0)
        goto loot_and_exit;

    // ----- D) Kill XP award branches -----
    if ((cShareFlag == '\0') ||
        (iTmp = (**(int (**)())(*pVictimObj + 0x214))(), iTmp == 0)) {
        // No multi-share list: solo or convoy slots on killer
        if (*(int*)((int)pKillerChar + 0xcb0) == 0) {
            // Solo: mult = XPPercent * shareOrOne * participationShare; count=0
            flParticipationShare =
                *(float*)(pXpTemplate + 0x500) * flShareOrOne * flParticipationShare;
            nConvoyMemberCount = 0;
            iTmp = nVictimLevel;
            pTmp = pKillerChar;
            iMember = (**(int (**)())(
                *(int*)(*(int*)(*(int*)((int)pKillerChar + 4) + 4) + 4 + (int)pKillerChar) +
                0x27c))();
            CVOGCombat_CalculateAndAwardKillXP(iMember, iTmp, flParticipationShare, pTmp,
                                               nConvoyMemberCount, unaff_EDI);
        } else {
            // Convoy roster: lock, count members, loop 4 slots with range gate
            FUN_00574900();
            iTmp = FUN_00574e60(pKillerChar); // convoy member count for blend
            iConvoyIdx = 0;
            do {
                pTmp = (void*)FUN_00574760((float)iConvoyIdx);
                if (((pTmp != nullptr) && (iMember = *(int*)((int)pTmp + 0x250), iMember != 0)) &&
                    (cShareFlag = (**(char (**)())(
                                      *(int*)(*(int*)(*(int*)(iMember + 4) + 4) + 4 + iMember) +
                                      0x198))(),
                     cShareFlag == '\0')) {
                    iMember = (**(int (**)())(
                        *(int*)(*(int*)(*(int*)((int)pTmp + 4) + 4) + 4 + (int)pTmp) + 0x27c))();
                    pfPos = (float*)(**(int (**)())(
                        *(int*)(*(int*)(*(int*)((int)pTmp + 4) + 4) + 4 + (int)pTmp) + 0x1a0))();
                    if (sqrtf((fPosZ - pfPos[2]) * (fPosZ - pfPos[2]) +
                              (fPosX - *pfPos) * (fPosX - *pfPos)) < DAT_00aaa8a8) {
                        CVOGCombat_CalculateAndAwardKillXP(
                            iMember, nVictimLevel,
                            *(float*)(pXpTemplate + 0x500) * flShareOrOne * flParticipationShare,
                            pTmp, iTmp, unaff_EDI);
                    }
                }
                iConvoyIdx = iConvoyIdx + 1;
            } while (iConvoyIdx < 4);
            FUN_00574910();
        }
    } else {
        // Multi-contributor list at victim-side +0x158 (TFID nodes); count fixed 4
        iTmp = (**(int (**)())(*pVictimObj + 0x214))();
        piListHead = *(int**)(iTmp + 0x158);
        piListNode = (int*)*piListHead;
        while (piListNode != piListHead) {
            if (((0 < piListNode[8]) &&
                 (piListHead = (int*)Object_ResolveFromTFID((void*)(piListNode + 4)),
                  piListHead != nullptr)) &&
                ((pTmp = (void*)(**(int (**)(int))(*piListHead + 0x210))(0), pTmp != nullptr &&
                  ((iMember = *(int*)((int)pTmp + 0x250), iMember != 0 &&
                    (cShareFlag = (**(char (**)())(
                                      *(int*)(*(int*)(*(int*)(iMember + 4) + 4) + 4 + iMember) +
                                      0x198))(),
                     cShareFlag == '\0')))))) {
                iMember = (**(int (**)())(
                    *(int*)(*(int*)(*(int*)((int)pTmp + 4) + 4) + 4 + (int)pTmp) + 0x27c))();
                pfPos = (float*)(**(int (**)())(
                    *(int*)(*(int*)(*(int*)((int)pTmp + 4) + 4) + 4 + (int)pTmp) + 0x1a0))();
                if (sqrtf((fPosZ - pfPos[2]) * (fPosZ - pfPos[2]) +
                          (fPosX - *pfPos) * (fPosX - *pfPos)) < DAT_00aaa8a8) {
                    CVOGCombat_CalculateAndAwardKillXP(
                        iMember, nVictimLevel,
                        *(float*)(pXpTemplate + 0x500) * flShareOrOne * flParticipationShare,
                        pTmp, 4, unaff_EDI);
                }
            }
            FUN_004cb270();
            piListHead = *(int**)(iTmp + 0x158);
        }
    }

    // Early exit if entity flag +0xf6 set (skip credits/loot)
    pTmp = *(void**)(*(int*)(*(int*)((int)pKillerChar + 4) + 4) + 0xa8 + (int)pKillerChar);
    if (*(char*)((int)pTmp + 0xf6) != '\0') {
        ExceptionList = pSehPrev;
        return pTmp;
    }

    // ----- E) Credits path (level delta < 11) -----
    flShareOrOne = -NAN; // sentinel; overwritten from template credit fields
    if (pVehicleSide == 0) {
        if (pCreatureSide != 0) {
            flShareOrOne = *(float*)(*(int*)(*(int*)(*(int*)(*(int*)(pCreatureSide + 4) + 4) +
                                                    0xac + pCreatureSide) +
                                             0x3c) +
                                     0x514);
        }
    } else {
        iTmp = FUN_005001f0();
        flShareOrOne = *(float*)(iTmp + 0x178);
    }
    iTmp = (**(int (**)())(
        *(int*)(*(int*)(*(int*)((int)pKillerChar + 4) + 4) + 4 + (int)pKillerChar) + 0x27c))();
    if (iTmp - nVictimLevel < 0xb) {
        if (pCreatureSide == 0) {
            if (pVehicleSide == 0)
                goto loot_and_exit;
            piListNode = *(int**)(*(int*)(*(int*)(pVehicleSide + 4) + 4) + 0xb0 + pVehicleSide);
            if ((piListNode == nullptr) ||
                (iTmp = (**(int (**)())(*piListNode + 0x1d8))(), iTmp == 0))
                goto credits_mid; // LAB_004dad8c
        }
        lCredits = FUN_00508e70(pKillerChar, flShareOrOne);
        if (0 < lCredits) {
            uPosPack = FUN_00521510(&fPosX);
            FUN_004d2750(lCredits, &fPosX, 0x41200000 /* 10.f */, 1, uPosPack);
        }
    }

credits_mid: // LAB_004dad8c
    if (pVehicleSide == 0) {
        if (pCreatureSide == 0)
            goto loot_and_exit;
        piListNode = (int*)FUN_00404c90();
        iStack_30 = *piListNode;
        iStack_2c = piListNode[1];
        pvStack_28 = (void*)piListNode[2];
        iStack_24 = piListNode[3];
        if (*(int*)(pCreatureSide + 0x250) != 0)
            goto credits_tfid_reload; // LAB_004dade2
    } else {
    credits_tfid_reload:
        piListNode = (int*)FUN_00404c90();
        iStack_30 = *piListNode;
        iStack_2c = piListNode[1];
        pvStack_28 = (void*)piListNode[2];
        iStack_24 = piListNode[3];
    }
    if (-1 < (int)flShareOrOne) {
        FUN_0050ac80(pKillerChar, pLootCtx, &iStack_30, nVictimLevel, flShareOrOne, 0, 0);
    }
    FUN_004d4440(nVictimLevel, pKillerChar, &fPosX, flShareOrOne, 0, 0);

loot_and_exit: // LAB_004dae57
    pTmp = *(void**)(*(int*)(*(int*)((int)pKillerChar + 4) + 4) + 0xa8 + (int)pKillerChar);
    if (*(char*)((int)pTmp + 0xf6) == '\0') {
        // Loot table rolls via DAT_00b037e8 helper
        if (DAT_00b037e8 != 0) {
            piLootList = (int*)FUN_0040fb90();
            iLootFlag = 0;
            uSehState = 1;
            if (pVictimObj[0x2a] == 0) {
                uKind = 0xffffffff;
            } else {
                uKind = *(unsigned*)(pVictimObj[0x2a] + 0x34);
            }
            FUN_0050aa80(uKind, pVictimObj[0x29],
                         *(unsigned char*)(*(int*)(*(int*)(*(int*)(*(int*)((int)pKillerChar + 4) +
                                                                  4) +
                                                          0xac + (int)pKillerChar) +
                                                   0x3c) +
                                           0x532),
                         auStack_4c);
            if ((iLootFlag != 0) && (piListNode = (int*)*piLootList, piListNode != piLootList)) {
                do {
                    if (pVehicleSide == 0) {
                    drop_item:
                        uPosPack = FUN_00521510(&fPosX);
                        *(void**)(piListNode[2] + 0x170) = uPosPack;
                        FUN_004d2820((void*)piListNode[2], &fPosX, 0x3f800000 /* 1.f */, 1);
                    } else {
                        iTmp = *(int*)(*(int*)(pVehicleSide + 4) + 4);
                        iMember = (**(int (**)())(*(int*)piListNode[2] + 0x27c))();
                        iTmp = (**(int (**)())(*(int*)(iTmp + 4 + pVehicleSide) + 0x27c))();
                        if (iMember <= iTmp)
                            goto drop_item;
                    }
                    piListNode = (int*)*piListNode;
                } while (piListNode != piLootList);
            }
            FUN_00404060();
            FUN_00509010(pVictimObj,
                         *(unsigned char*)(*(int*)(*(int*)(*(int*)(*(int*)((int)pKillerChar + 4) +
                                                                  4) +
                                                          0xac + (int)pKillerChar) +
                                                   0x3c) +
                                           0x532),
                         auStack_4c);
            if ((iLootFlag != 0) && (piListNode = (int*)*piLootList, piListNode != piLootList)) {
                do {
                    uPosPack = FUN_00521510(&fPosX);
                    *(void**)(piListNode[2] + 0x170) = uPosPack;
                    FUN_004d2820((void*)piListNode[2], &fPosX, 0x3f800000, 1);
                    piListNode = (int*)*piListNode;
                } while (piListNode != piLootList);
            }
            uSehState = 0xffffffff;
            FUN_00403430();
        }

        // Special drop: creature +600 / vehicle +0x280 table with chance +0x1a4
        pTmp = (void*)pVictimObj[0x2a];
        flParticipationShare = 0.0f;
        if ((*(int*)((int)pTmp + 0x38) == kTemplateCreature) &&
            (pTmp = __RTDynamicCast(pVictimObj, 0, &CVOGClonedObjectBase_RTTI, &CVOGCreature_RTTI,
                                    0),
             pTmp != nullptr)) {
            flParticipationShare = *(float*)((int)pTmp + 600);
        }
        if ((*(int*)(pVictimObj[0x2a] + 0x38) == kTemplateVehicle) &&
            (pTmp = __RTDynamicCast(pVictimObj, 0, &CVOGClonedObjectBase_RTTI, &CVOGVehicle_RTTI, 0),
             pTmp != nullptr)) {
            flParticipationShare = *(float*)((int)pTmp + 0x280);
        }
        if (flParticipationShare != 0.0f) {
            fLootChance = *(float*)((int)flParticipationShare + 0x1a4);
            iTmp = CVOGReaction_RandomUnitScalar();
            if (0xfffff < *(int*)(iTmp + 0xc)) {
                *(int*)(iTmp + 0xc) = 0;
            }
            uRand = *(unsigned short*)(*(int*)(iTmp + 8) + *(int*)(iTmp + 0xc) * 2);
            *(int*)(iTmp + 0xc) = *(int*)(iTmp + 0xc) + 1;
            uRandFull = (unsigned)uRand;
            pTmp = (void*)(uRandFull / 100);
            if ((float)(uRandFull % 100) < fLootChance) {
                iTmp = (int)__RTDynamicCast(pVictimObj, 0, &CVOGClonedObjectBase_RTTI,
                                            &CVOGPhysicsBase_RTTI, 0);
                pTmp = nullptr;
                if (iTmp != 0) {
                    piListNode =
                        CVOGReaction_GiveItemByCbid(*(int*)((int)flParticipationShare + 0x1a0));
                    if (piListNode != nullptr) {
                        (**(int (**)(int, int, int))(*piListNode + 8))(
                            *(int*)((int)flParticipationShare + 0x1a0), pLootCtx, 1);
                        uPosPack = FUN_00521510(auStack_4c);
                        *((void**)(piListNode + 0x5c)) = uPosPack;
                        piListHead = (int*)FUN_00404c90();
                        // reuses position stack slots for spawn
                        iPosY = *piListHead;
                        fPosZ = (float)piListHead[1];
                        iPosW = piListHead[2];
                        iStack_30 = piListHead[3];
                        pKillerChar = FUN_004d2820(piListNode, &iPosY, 0, 1);
                        ExceptionList = pvStack_28;
                        return pKillerChar;
                    }
                    pTmp = FUN_007a4480(0, "allocatenewobjectfromcbid failed %d",
                                        *(int*)((int)flParticipationShare + 0x1a0));
                }
            }
        }
    }
    ExceptionList = pSehPrev;
    return pTmp;
}
