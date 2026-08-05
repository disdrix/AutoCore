// READABILITY (auto CF):
//  - Body size: ~143 non-empty decompiler lines.
//  - Control keywords: if×13, return×5, for×3.
//  - Notable callees: CNDHash_LookupByKey×7, CVOGCharacter_WeaponAllowsKillXpBonus×3, CVOGReaction_UnlockContinentObject×2, FUN_0053c360×2, FUN_00547920×2, FUN_007a4480×2, FUN_007a6de0×2, CVOGMission_AddActiveObjective.
//  - Strings: "Already had objective %l for COID %I64d\n"; "Received Mission"; "%s: %s"; "gen_give_quest".
//  - Return sites: 5.

// =============================================================================
// CVOGReaction_GiveMission
// -----------------------------------------------------------------------------
// Purpose:  Grant mission `missionId` to the character:
//           - validate mission def exists and byte objCount@def+0x130 >= 1
//           - reject if already active (+0x540) or completed (repeat rules)
//           - AddActiveObjective(char, firstObj) on first objective list entry
//           - UnlockContinentObject(objective+0x120)
//           - CNDHash_Insert active +0x540; optional sibling +0x544; state blob +0x530
//           - toast "Received Mission" + gen_give_quest audio when word def+0xF8==0
//
// Address:  0x005327c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005327c0
// System:   missions-progression
//
// Convention: MSVC __thiscall  (this = CVOGCharacter*)
// Returns:    1 on grant (or already-had-mission log path), 0 on reject
//
// Character hashes (docs/missionState.md §2.1 + residual 2026-07-29):
//   +0x538 completed, +0x53c instanced-completed, +0x540 active missions,
//   +0x544 paired active (second FUN_0053c360), +0x548 active objectives,
//   +0x530 state-blob hash (FUN_0053c660), +0x508/+0x50c prior-state tree
//
// Server mirror: GiveMission reaction + OnMissionStateChanged (logic type 11) — external prose.
// Does NOT open volume gates itself - map triggers re-eval after state change.
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch).
// Residual 2026-07-29: callee this/roles sealed (reviews/a_005327c0.md) — no CF rewrite.
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstring>

// Callees (residual 2026-07-29 sealed roles; keep FUN_* product names unless string-sealed)
std::uint32_t* FUN_0053fff0(); // GetMissionDefTableRoot
void* CNDHash_LookupByKey(void* hash, unsigned key); // VA 0x005b0920
// FUN_00547920: MissionDef_EnsureXmlLoaded — thiscall/fastcall ECX=def; stack 0/1 (decompiler free form)
void  FUN_00547920(int mode);
// Mode gate on entity +0xa8 object (not character this); historical name
char  CVOGCharacter_WeaponAllowsKillXpBonus();
void  CVOGMission_AddActiveObjective(int objectiveDef); // thiscall(char, objDef) — 2 formals
void  CVOGReaction_UnlockContinentObject(void* character, unsigned unlockId);
void  FUN_007a4480(int level, const char* fmt, ...); // log
// FUN_0053c360: CNDHash_Insert — this=hash; (key, payload, soft). Sites: +0x540 then optional +0x544
void  FUN_0053c360(unsigned missionId, void* missionDef, int flags);
// FUN_00538b20: CNDHash_Remove — this=+0x538 on re-grant strip
void  FUN_00538b20(unsigned missionId, int flags);
void* operator_new(std::size_t);
std::uint32_t* FUN_004111f0(); // init 0x30 state blob (-1 fills)
// FUN_00538a40: lower_bound on tree this=+0x508
void  FUN_00538a40(int* outNode, unsigned* missionId);
// FUN_0053c660: CNDHash_Insert twin — this=+0x530 state-blob hash
void  FUN_0053c660(std::uint32_t missionKey, std::uint32_t* stateBlob, int flags);
void  FUN_0052d8b0(int a, std::uint32_t missionKey); // state-tree notify (this=char)
void  FUN_007a69d0(); // UI string table lock/setup
std::uint32_t FUN_007a6de0(const char* s, std::uint32_t unk); // localize / resolve string
void  FUN_0040c5c0(char* toastBuf); // push toast
void  Client_GetMissionCompleteAudioTable(
    const char* name, int, std::uint32_t, std::uint32_t, int, int, int, int);
void  Client_PlayNamedInterfaceSound(
    char* name, std::uint32_t, std::uint32_t, std::uint32_t,
    std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t);

// Globals referenced by toast path
extern float g_flLevelUpUiBase_Inferred;
extern std::uint32_t DAT_00aaa68c;

std::uint32_t __thiscall CVOGReaction_GiveMission(void* thisCharacter, unsigned missionId)
{
    int* piObjList;
    char cGate;
    std::uint32_t* pMissionDef;
    void* pvHit;
    std::uint32_t uVar5;
    std::uint32_t uVar6;
    int iVar7;
    std::uint32_t* puSrc;
    std::uint32_t* puDst;
    char* pcSound;
    std::uint32_t uVar11, uVar12, uVar13, uVar14, uVar15;

    std::uint32_t* local_stateBlob; // local_1a4
    int local_priorNode;            // local_1a0
    unsigned local_missionId;       // local_19c
    char local_toastTitle[128];     // local_198
    std::uint32_t local_118;
    float local_114;
    std::uint32_t local_110;
    std::uint32_t local_10c;
    std::uint32_t local_108;
    std::uint32_t local_104;
    char local_toastBody[256];      // local_100

    // -------------------------------------------------------------------------
    // Resolve mission definition; require byte objCount at def+0x130 >= 1
    // (decompiler: *(char*)(puVar3 + 0x4c) on undefined4* typing)
    // -------------------------------------------------------------------------
    pMissionDef = (std::uint32_t*)FUN_0053fff0();
    if ((((void*)*pMissionDef != (void*)0x0) &&
         (pMissionDef = (std::uint32_t*)CNDHash_LookupByKey((void*)*pMissionDef, missionId),
          pMissionDef != (std::uint32_t*)0x0)) &&
        (*(char*)(pMissionDef + 0x4c) != '\0'))
    {
        // EnsureXmlLoaded(def): ECX=def; stack 1 then maybe 0 if byte def+0x168==0
        // (decompiler free-form keeps constants; residual sealed ECX framing)
        FUN_00547920(1);
        if (*(char*)(pMissionDef + 0x5a) == '\0') {
            FUN_00547920(0);
        }

        // Already active? (+0x540)
        pvHit = CNDHash_LookupByKey(*(void**)((int)thisCharacter + 0x540), missionId);
        if (pvHit == (void*)0x0) {
            // -----------------------------------------------------------------
            // Repeat / instance completion gate when short at dword 0x2b != -1
            // -----------------------------------------------------------------
            if (*(short*)(pMissionDef + 0x2b) != -1) {
                // Non-instance: reject if in completed hash (+0x538)
                cGate = CVOGCharacter_WeaponAllowsKillXpBonus();
                if ((cGate == '\0') &&
                    (pvHit = CNDHash_LookupByKey(
                         *(void**)((int)thisCharacter + 0x538), missionId),
                     pvHit != (void*)0x0))
                {
                    return 0;
                }
                // Instance: reject if in instance-completed hash (+0x53c)
                cGate = CVOGCharacter_WeaponAllowsKillXpBonus();
                if ((cGate != '\0') &&
                    (pvHit = CNDHash_LookupByKey(
                         *(void**)((int)thisCharacter + 0x53c), missionId),
                     pvHit != (void*)0x0))
                {
                    return 0;
                }
            }

            // -----------------------------------------------------------------
            // First objective in list at def dword index 0x4f
            // -----------------------------------------------------------------
            piObjList = (int*)pMissionDef[0x4f];
            // Active objectives hash +0x548 keyed by objective id (+0x10)
            pvHit = CNDHash_LookupByKey(
                *(void**)((int)thisCharacter + 0x548),
                *(unsigned*)(*piObjList + 0x10));
            if (pvHit == (void*)0x0) {
                CVOGMission_AddActiveObjective(*piObjList);
            } else {
                // Already had objective - log COID pair from character entity
                iVar7 = *(int*)(*(int*)((int)thisCharacter + 4) + 4);
                FUN_007a4480(
                    1,
                    "Already had objective %l for COID %I64d\n",
                    *(std::uint32_t*)(*piObjList + 0x10),
                    *(std::uint32_t*)(iVar7 + 0x164 + (int)thisCharacter),
                    *(std::uint32_t*)(iVar7 + 0x168 + (int)thisCharacter));
            }

            // Unlock continent object id stored at first objective +0x120
            CVOGReaction_UnlockContinentObject(
                thisCharacter,
                *(unsigned*)(*(int*)pMissionDef[0x4f] + 0x120));

            // Re-check active mission hash before insert
            pvHit = CNDHash_LookupByKey(*(void**)((int)thisCharacter + 0x540), missionId);
            if (pvHit == (void*)0x0) {
                // CNDHash_Insert into active +0x540 (this elided in decompile form)
                FUN_0053c360(missionId, pMissionDef, 0);

                // Optional sibling insert into +0x544 when mode && (word+0xF8==0 || dword+0x100!=-1)
                cGate = CVOGCharacter_WeaponAllowsKillXpBonus();
                if ((cGate != '\0') &&
                    ((*(short*)(pMissionDef + 0x3e) == 0 || (pMissionDef[0x40] != (std::uint32_t)-1))))
                {
                    FUN_0053c360(missionId, pMissionDef, 0); // ECX = char+0x544
                }

                // If repeatable (word def+0xAC == -1) and already completed → CNDHash_Remove +0x538
                if ((*(short*)(pMissionDef + 0x2b) == -1) &&
                    (pvHit = CNDHash_LookupByKey(
                         *(void**)((int)thisCharacter + 0x538), missionId),
                     pvHit != (void*)0x0))
                {
                    FUN_00538b20(missionId, 0);
                }

                // Allocate 0x30-byte mission runtime state blob
                pvHit = operator_new(0x30);
                if (pvHit == (void*)0x0) {
                    local_stateBlob = (std::uint32_t*)0x0;
                } else {
                    local_stateBlob = (std::uint32_t*)FUN_004111f0();
                }

                // Lookup prior state for this mission id; copy 0xC dwords from +0x18 if present
                local_missionId = missionId;
                FUN_00538a40(&local_priorNode, &local_missionId);
                if ((local_priorNode != *(int*)((int)thisCharacter + 0x50c)) &&
                    ((std::uint32_t*)(local_priorNode + 0x18) != (std::uint32_t*)0x0))
                {
                    puSrc = (std::uint32_t*)(local_priorNode + 0x18);
                    puDst = local_stateBlob;
                    for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
                        *puDst = *puSrc;
                        puSrc  = puSrc + 1;
                        puDst  = puDst + 1;
                    }
                }

                // Bind state blob on +0x530 hash; notify state tree
                FUN_0053c660(*pMissionDef, local_stateBlob, 0); // ECX = char+0x530
                FUN_0052d8b0(0, *pMissionDef);

                // Toast + audio only when word def+0xF8 == 0
                if (*(short*)(pMissionDef + 0x3e) == 0) {
                    FUN_007a69d0();
                    uVar6 = pMissionDef[0x53]; // mission name string key
                    uVar5 = FUN_007a6de0("Received Mission", 0xffffffffu);
                    uVar6 = FUN_007a6de0((const char*)uVar6, 0xffffffffu);
                    sprintf(local_toastBody, "%s: %s", (const char*)uVar6, (const char*)uVar5);

                    local_118 = 0xffffffffu;
                    local_toastTitle[0] = '\0';
                    strncpy(local_toastTitle, local_toastBody, 0x80);
                    local_114 = g_flLevelUpUiBase_Inferred;
                    local_118 = 0xffeee3d8u; // toast color
                    local_10c = 0;
                    local_110 = DAT_00aaa68c;
                    local_108 = 0xffffffffu;
                    local_104 = 0xffffffffu;
                    FUN_0040c5c0(local_toastTitle);

                    uVar15 = 0;
                    uVar14 = 0x1e;
                    uVar13 = 0;
                    uVar12 = 0;
                    uVar11 = 0xffffffffu;
                    uVar5  = 0xffffffffu;
                    uVar6  = 0;
                    pcSound = (char*)"gen_give_quest";
                    Client_GetMissionCompleteAudioTable(
                        "gen_give_quest", 0, 0xffffffffu, 0xffffffffu, 0, 0, 0x1e, 0);
                    Client_PlayNamedInterfaceSound(
                        pcSound, uVar6, uVar5, uVar11, uVar12, uVar13, uVar14, uVar15);
                    return 1;
                }
            } else {
                // Active hash race: already had mission entry
                iVar7 = *(int*)(*(int*)((int)thisCharacter + 4) + 4);
                FUN_007a4480(
                    1,
                    "Already had mission %l for COID %I64d\n",
                    missionId,
                    *(std::uint32_t*)(iVar7 + 0x164 + (int)thisCharacter),
                    *(std::uint32_t*)(iVar7 + 0x168 + (int)thisCharacter));
            }
            return 1;
        }
    }
    return 0;
}
