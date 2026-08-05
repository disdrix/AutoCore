// =============================================================================
// CVOGCharacter_SetLevelWithFlags_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Set absolute character level and selectively rebuild skill /
//           attribute / research pools from tExperienceLevel (levels 2..N),
//           clamp total XP, refresh skills/vehicle/missions, rebind equip.
//
// Address:  0x00533220  (autoassault.exe, image base 0x400000)
// Body:     0x00533220–0x00533c2e (2574 bytes; ret 8)
// Stable:   aa_00533220
// System:   missions-progression / XP
// Ghidra:   FUN_00533220
//
// ABI:      __thiscall
//             ECX = CVOGCharacter *self
//             stack: int newLevel, unsigned flags
//             ret 8
//
// Flags:    0x1  rebuild skill pool (+0x6ce) + race base-stat seed
//           0x4  rebuild attribute pool (+0x6cc) + skill rank reeval
//           0x40 rebuild research pool (+0x580) + dirty bytes
//
// Exactness: CF mirrors raw + live decompile; names cleaned / INFERRED.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W19-J).
// =============================================================================

#include <cstdint>

// Experience level table
extern int   g_nExperienceLevelTableReady;
extern void *g_pExperienceLevelMap_INFERRED;
extern void *g_pExperienceLevelMapEnd;
void Experience_EnsureLevelTableLoaded_INFERRED();
void StdMap_LowerBoundByIntKey_INFERRED(void *map, void *outIt, int *pKey);

// Flag-gated helpers
void FUN_00521230(); // race base-stat seed (uses this via register path)
void FUN_004c2ef0(unsigned);
void FUN_004c2ee0(short);
void FUN_004c2f00(short);
void FUN_004c2f10(short);
void Skill_SetRankAndReevaluate(void *skill, void *arg1, short arg2);
void Vehicle_RecalcCombatPools(void *vehicle);
void CVOGCharacter_SearchAutoMissions(void *character);
void FUN_007a4480(int, const char *);

// Vehicle equip rebind (residual names)
char FUN_00514390(void *self, int);
void Vehicle_AttachWeapon(int, int, int);
char FUN_005714e0(void *itemSide, int *a, int *b, int, unsigned);
void FUN_00571620(void *itemSide, int a, int b, int);
void FUN_004d0e90(void *itemSide);
void FUN_004fe800(int, int, int);
void FUN_004fe620(int, int, int);
void Vehicle_EquipPowerPlant(void *vehicle, void *, void **, bool);
void Vehicle_SetEquippedArmor(void *vehicle, void *, char);
void Vehicle_SetEquippedRaceItem(void *vehicle, void *, void **, char);

/*
 * CVOGCharacter_SetLevelWithFlags_Inferred
 *
 * Character fields (sealed):
 *   +0x6c8 nLevel
 *   +0x6cc attribute points (short)  — AddAttributePoints dual
 *   +0x6ce skill points (short)      — AddSkillPoints dual
 *   +0x580 research points (short)
 *   +0x730 total XP
 *   +0x250 vehicle*
 *   +0x12c ← +0x12e after vtable +0x5c
 *   +0x4f2 flag byte = 1
 *   +0x74c 100× int wipe (−1) when flags&4
 *
 * tExperienceLevel row (via map node):
 *   +0x10 intExperience (total XP threshold)
 *   +0x14 attribute grant (short)
 *   +0x16 skill grant (short)
 *   +0x18 research grant (short)
 *
 * Sole caller: FUN_0080bec0 (CharacterLevel apply) with
 *   ECX = character, newLevel = vfunc(+0x27c), flags = packet/obj +0x8.
 */

void __thiscall CVOGCharacter_SetLevelWithFlags_Inferred(
    int *self,
    int newLevel,
    unsigned flags)
{
    int *extraout_EAX;
    void *pRow;
    int L;
    int oldLevel;
    unsigned fSkill;
    unsigned fAttrib;
    unsigned fResearch;
    char levelChanged;
    char leveledUp;
    void *pScratch;
    unsigned hashKeys[12];
    int i;
    int *pWipe;
    int pHb;
    int pNode;
    void *pSkill;
    char cOk;
    int pVeh;
    int pItem;

    fSkill = flags & 1u;
    if (fSkill != 0) {
        FUN_00521230();
    }

    fAttrib = flags & 4u;
    if (fAttrib != 0) {
        *(uint16_t *)(self + 0x1b3) = 0; /* +0x6cc attribute pool */
    }
    if (fSkill != 0) {
        *(uint16_t *)((int)self + 0x6ce) = 0; /* skill pool */
    }

    fResearch = flags & 0x40u;
    if (fResearch != 0) {
        *(uint16_t *)(self + 0x160) = 0; /* +0x580 research */
        *(uint8_t *)((int)self + 0x599) = 1;
        *(uint8_t *)((int)self + 0x59b) = 1;
        *(uint8_t *)(self + 0x166) = 1;
        *(uint8_t *)((int)self + 0x59a) = 1;
    }

    oldLevel = self[0x1b2]; /* +0x6c8 */
    levelChanged = (char)(oldLevel != newLevel);
    leveledUp = (char)(oldLevel < newLevel);
    self[0x1b2] = newLevel;

    /* ----- reaccumulate table grants for L = 2 .. newLevel ----- */
    if (1 < newLevel) {
        L = 2;
        do {
            int key = L;
            if (g_nExperienceLevelTableReady == 0) {
                Experience_EnsureLevelTableLoaded_INFERRED();
            }
            StdMap_LowerBoundByIntKey_INFERRED(
                &g_pExperienceLevelMap_INFERRED, &pScratch, &key);
            pRow = (void *)*extraout_EAX;
            if (g_nExperienceLevelTableReady == 0) {
                Experience_EnsureLevelTableLoaded_INFERRED();
            }
            if (pRow != g_pExperienceLevelMapEnd) {
                if (fSkill != 0) {
                    *(int16_t *)((int)self + 0x6ce) =
                        (int16_t)(*(int16_t *)((int)self + 0x6ce) +
                                  *(int16_t *)((int)pRow + 0x16));
                    FUN_004c2ef0(*(int16_t *)((int)self + 0x13e) + 1);
                    FUN_004c2ee0((int16_t)self[0x4f] + 1);
                    FUN_004c2f00((int16_t)self[0x50] + 1);
                    FUN_004c2f10(*(int16_t *)((int)self + 0x142) + 1);
                }
                if (fAttrib != 0) {
                    *(int16_t *)(self + 0x1b3) =
                        (int16_t)((int16_t)self[0x1b3] +
                                  *(int16_t *)((int)pRow + 0x14));
                }
                if (fResearch != 0) {
                    *(int16_t *)(self + 0x160) =
                        (int16_t)((int16_t)self[0x160] +
                                  *(int16_t *)((int)pRow + 0x18));
                }
                /* Clamp total XP (+0x730) when level changed */
                if (levelChanged != '\0') {
                    if (leveledUp == '\0') {
                        if (L == newLevel) {
                            self[0x1cc] = *(int *)((int)pRow + 0x10) - 1;
                        }
                    } else if (L == newLevel - 1) {
                        self[0x1cc] = *(int *)((int)pRow + 0x10);
                    }
                }
            }
            L = L + 1;
        } while (L <= newLevel);
    }

    /* ----- flag 0x4: skill HB reevaluate + wipe ----- */
    if (fAttrib != 0) {
        pHb = *(int *)(*(int *)(self[1] + 4) + 0x74 + (int)self);
        if (pHb != 0) {
            pNode = 0;
            if (*(char *)(pHb + 0x1d) != '\0') {
                FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
                FUN_007a4480(0, "VOG_DEBUG_STOP");
            }
            *(uint8_t *)(pHb + 0x1d) = 1;
            while (true) {
                pHb = *(int *)(*(int *)(self[1] + 4) + 0x74 + (int)self);
                if (*(char *)(pHb + 0x1d) == '\0') {
                    FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
                    FUN_007a4480(0, "VOG_DEBUG_STOP");
                }
                if (pNode == 0) {
                    pNode = *(int *)(pHb + 0x14);
                } else {
                    pNode = *(int *)(pNode + 0x14);
                }
                if (pNode == 0) {
                    pSkill = (void *)0;
                } else {
                    pSkill = *(void **)(pNode + 8);
                }
                if (pSkill == (void *)0) {
                    break;
                }
                if ((*(char *)((int)pSkill + 0x5f8) != '\0') ||
                    (*(char *)((int)pSkill + 0x5f9) != '\0')) {
                    /* third arg: decompiler unaff_EDI — residual */
                    Skill_SetRankAndReevaluate(pSkill, (void *)0, 0);
                }
            }
            *(uint8_t *)(*(int *)(*(int *)(self[1] + 4) + 0x74 + (int)self) + 0x1d) = 0;

            /* Hash-table skill lookup (12 fixed keys) then optional reevaluate */
            {
                int iRace = *(int *)(*(int *)(*(int *)(self[1] + 4) + 0xac + (int)self) + 0x3c);
                int iBucket = *(int *)((int)self + *(int *)(self[1] + 4) + 0x74);
                hashKeys[0] = 0x294;
                hashKeys[1] = 0x29b;
                hashKeys[2] = 0x333;
                hashKeys[3] = 0x837;
                hashKeys[4] = 0x224;
                hashKeys[5] = 0x2bd;
                hashKeys[6] = 0x310;
                hashKeys[7] = 0x2fc;
                hashKeys[8] = 0x225;
                hashKeys[9] = 0x29a;
                hashKeys[10] = 0x317;
                hashKeys[11] = 0x365;
                {
                    unsigned idx =
                        (unsigned)*(uint8_t *)(iRace + 0x531) +
                        (unsigned)*(uint8_t *)(iRace + 0x532) * 4;
                    int chain = *(int *)(*(int *)(*(int *)(iBucket + 0x10) +
                        (*(unsigned *)(iBucket + 8) & hashKeys[idx]) * 4) + 4);
                    pSkill = (void *)0;
                    if (chain != 0) {
                        do {
                            if (hashKeys[idx] == *(unsigned *)(chain + 0x10)) {
                                pSkill = *(void **)(chain + 8);
                                break;
                            }
                            chain = *(int *)(chain + 0xc);
                        } while (chain != 0);
                    }
                    if (pSkill != (void *)0) {
                        Skill_SetRankAndReevaluate(pSkill, (void *)1, 0);
                    }
                }
            }
        }
        pWipe = self + 0x1d3; /* +0x74c */
        for (i = 100; i != 0; i = i - 1) {
            *pWipe = -1;
            pWipe = pWipe + 1;
        }
    }

    /* ----- always: vehicle pools, vtable refresh, auto-missions ----- */
    if ((void *)self[0x94] != (void *)0) {
        Vehicle_RecalcCombatPools((void *)self[0x94]);
    }
    (**(void (__thiscall **)(int *))(*self + 0x5c))(self);
    *(uint16_t *)(self + 0x4b) = *(uint16_t *)((int)self + 0x12e); /* +0x12c */
    *(uint8_t *)((int)self + 0x4f2) = 1;
    if (*(char *)(*(int *)(*(int *)(self[1] + 4) + 0xa8 + (int)self) + 0x7e) != '\0') {
        CVOGCharacter_SearchAutoMissions(self);
    }

    /* ----- vehicle equip rebind (when vehicle + condition) ----- */
    pVeh = self[0x94];
    if ((pVeh != 0) && (*(int *)(pVeh + 0x2b0) != 0) && (self[0x32f] != 0)) {
        /* weapons 0..2 */
        for (i = 0; i < 3; i = i + 1) {
            pItem = *(int *)(*(int *)(pVeh + 0x260) + i * 4);
            if ((pItem != 0) && (cOk = FUN_00514390(self, 1), cOk == '\0')) {
                Vehicle_AttachWeapon(0, i, 0);
                /* try place / commit / clear — CF preserved from raw */
                cOk = FUN_005714e0(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    &newLevel, (int *)&flags, 1, 0xffffffff);
                if (cOk == '\0') {
                    cOk = FUN_005714e0(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                        &newLevel, (int *)&flags, 1, 0xffffffff);
                    if (cOk == '\0') {
                        FUN_004d0e90(
                            (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem));
                    } else {
                        FUN_00571620(
                            (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                            newLevel, (int)flags, 1);
                    }
                } else {
                    FUN_00571620(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                        newLevel, (int)flags, 1);
                }
            }
        }
        /* special slots @ vehicle+0x264 / +0x26c / +0x268 / +0x254 / +0x270
           same place/commit pattern with slot-specific detach helpers — see raw */
        pItem = *(int *)(pVeh + 0x264);
        if ((pItem != 0) && (cOk = FUN_00514390(self, 1), cOk == '\0')) {
            FUN_004fe800(0, 0, 0);
            cOk = FUN_005714e0(
                (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                &newLevel, (int *)&flags, 1, 0xffffffff);
            if (cOk == '\0') {
                cOk = FUN_005714e0(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    &newLevel, (int *)&flags, 1, 0xffffffff);
                if (cOk == '\0') {
                    FUN_004d0e90(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem));
                } else {
                    FUN_00571620(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                        newLevel, (int)flags, 1);
                }
            } else {
                FUN_00571620(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    newLevel, (int)flags, 1);
            }
        }
        pItem = *(int *)(pVeh + 0x26c);
        if ((pItem != 0) && (cOk = FUN_00514390(self, 1), cOk == '\0')) {
            FUN_004fe620(0, 0, 0);
            cOk = FUN_005714e0(
                (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                &newLevel, (int *)&flags, 1, 0xffffffff);
            if (cOk == '\0') {
                cOk = FUN_005714e0(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    &newLevel, (int *)&flags, 1, 0xffffffff);
                if (cOk == '\0') {
                    FUN_004d0e90(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem));
                } else {
                    FUN_00571620(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                        newLevel, (int)flags, 1);
                }
            } else {
                FUN_00571620(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    newLevel, (int)flags, 1);
            }
        }
        pItem = *(int *)(pVeh + 0x268);
        if ((pItem != 0) && (cOk = FUN_00514390(self, 1), cOk == '\0')) {
            Vehicle_EquipPowerPlant((void *)pVeh, (void *)0, (void **)0, false);
            cOk = FUN_005714e0(
                (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                &newLevel, (int *)&flags, 1, 0xffffffff);
            if (cOk == '\0') {
                cOk = FUN_005714e0(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    &newLevel, (int *)&flags, 1, 0xffffffff);
                if (cOk == '\0') {
                    FUN_004d0e90(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem));
                } else {
                    FUN_00571620(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                        newLevel, (int)flags, 1);
                }
            } else {
                FUN_00571620(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    newLevel, (int)flags, 1);
            }
        }
        pItem = *(int *)(pVeh + 0x254);
        if ((pItem != 0) && (cOk = FUN_00514390(self, 1), cOk == '\0')) {
            Vehicle_SetEquippedArmor((void *)pVeh, (void *)0, '\0');
            cOk = FUN_005714e0(
                (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                &newLevel, (int *)&flags, 1, 0xffffffff);
            if (cOk == '\0') {
                cOk = FUN_005714e0(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    &newLevel, (int *)&flags, 1, 0xffffffff);
                if (cOk == '\0') {
                    FUN_004d0e90(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem));
                } else {
                    FUN_00571620(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                        newLevel, (int)flags, 1);
                }
            } else {
                FUN_00571620(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    newLevel, (int)flags, 1);
            }
        }
        pItem = *(int *)(pVeh + 0x270);
        if ((pItem != 0) && (cOk = FUN_00514390(self, 1), cOk == '\0')) {
            Vehicle_SetEquippedRaceItem((void *)pVeh, (void *)0, (void **)0, '\0');
            cOk = FUN_005714e0(
                (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                &newLevel, (int *)&flags, 1, 0xffffffff);
            if (cOk == '\0') {
                cOk = FUN_005714e0(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    &newLevel, (int *)&flags, 1, 0xffffffff);
                if (cOk == '\0') {
                    FUN_004d0e90(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem));
                } else {
                    FUN_00571620(
                        (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                        newLevel, (int)flags, 1);
                }
            } else {
                FUN_00571620(
                    (void *)(*(int *)(*(int *)(pItem + 4) + 4) + 4 + pItem),
                    newLevel, (int)flags, 1);
            }
        }
    }

    /* ----- buff/item locked list: fold grants into selected pools ----- */
    pHb = self[0x14e];
    if (pHb != 0) {
        pNode = 0;
        if (*(char *)(pHb + 0x1d) != '\0') {
            FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }
        *(uint8_t *)(pHb + 0x1d) = 1;
        while (true) {
            pHb = self[0x14e];
            if (*(char *)(pHb + 0x1d) == '\0') {
                FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
                FUN_007a4480(0, "VOG_DEBUG_STOP");
            }
            if (pNode == 0) {
                pNode = *(int *)(pHb + 0x14);
            } else {
                pNode = *(int *)(pNode + 0x14);
            }
            if (pNode == 0) {
                pItem = 0;
            } else {
                pItem = *(int *)(pNode + 8);
            }
            if (pItem == 0) {
                break;
            }
            {
                int pMod = *(int *)(*(int *)(pItem + 0x13c) + -4 +
                                    (unsigned)*(uint8_t *)(pItem + 0x130) * 4);
                if (pMod != 0) {
                    if ((0 < *(int *)(pMod + 0x130)) && (fSkill != 0)) {
                        *(int16_t *)((int)self + 0x6ce) =
                            (int16_t)(*(int16_t *)((int)self + 0x6ce) +
                                      (int16_t)*(int *)(pMod + 0x130));
                    }
                    if ((0 < *(int *)(pMod + 0x134)) && (fAttrib != 0)) {
                        *(int16_t *)(self + 0x1b3) =
                            (int16_t)((int16_t)self[0x1b3] +
                                      (int16_t)*(int *)(pMod + 0x134));
                    }
                }
                if ((0 < *(int *)(pItem + 0x114)) && (fResearch != 0)) {
                    *(int16_t *)(self + 0x160) =
                        (int16_t)((int16_t)self[0x160] +
                                  (int16_t)*(int *)(pItem + 0x114));
                }
            }
        }
        *(uint8_t *)(self[0x14e] + 0x1d) = 0;
    }
    return;
}
