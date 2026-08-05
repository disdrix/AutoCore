// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×10, return×4.
//  - Notable callees: FUN_008aa510×4, FUN_008aaf60×3, FUN_008ac110×3, CNDHash_LookupByKey×2, FUN_0053fff0×2, FUN_007fef20×2, FUN_008aa4b0×2, FUN_008ab550×2.
//  - Strings: "NPC dialog already active!".
//  - Return sites: 4.

// =============================================================================
// Client_ShowNpcMissionDialogUI
// -----------------------------------------------------------------------------
// Purpose:  Present / reconfigure the NPC mission dialog UI for a chosen
//           mission. Called after S2C 0x206D staging (RecvNpcMissionDialog)
//           and from MissionDialogHandleButton state 3 (re-show).
//
//           Gate: client dialog stack at +0xf40 must match +0xf38, local
//           character at +0xe98, and mission UI controller at +0x1058.
//
// Address:  0x009438f0  (autoassault.exe, image base 0x400000)
// Stable:   aa_009438f0
// System:   missions-progression
//
// Parameters (decompiler formals; EAX framing sealed 2026-07-29, 4/4 xrefs):
//   param_1  - client / UI root (offsets +0xe98 char, +0x1058 dialog ctrl)
//   param_2  - NPC object (compared to dialog+0x644; int* index [0x191])
//   param_3  - mode: Recv / unmapped open=1; HandleButton re-show / list=0.
//              When mode!=0 and EAX==-1: multi-active journal shortcut or
//              first active mission key. mode==0 still looks up by EAX.
//   in_EAX   - mission id key for CNDHash_LookupByKey:
//              Recv @ 0x00815189: OR EAX,-1 (always)
//              Unmapped @ 0x00924605: OR EAX,-1 (if char+0x510 != EBX)
//              HandleButton state3 @ 0x008ae92e: dialog[+0x518+idx*8]
//              FUN_008aec40 list @ 0x008aecbc: *(entry+0x500)
//
// Control flow summary:
//   1) Guard client dialog + character + mission UI controller
//   2) Resolve mission def table (FUN_0053fff0) and mission key (EAX or
//      first active at char+0x50c when multi-mission journal path)
//   3) If active count > 1 and key is -1 with mode set: open journal view
//      via Client_UpdateMissionJournal and return
//   4) Lookup mission def; require (char)def[0x4c] != 0 (objectives @ +0x130)
//   5) Early-out "NPC dialog already active!" if same mission+NPC open
//      (dialog+0x670 def, +0x644 NPC)
//   6) FUN_0052b420(mission, npc) → turn-in readiness (last obj active)
//   7) Client_NpcDialog_PrepareResponseOpcode → dialog+0x650 = 0x206E
//   8) Set dialog+0x510 (int*[0x144]): 2 = fresh offer, 1 = active / turn-in;
//      FUN_008aa760(rewards, 4, flag) first-stores dialog+0x64c = turn-in flag
//      (HandleButton state 1 + reward captions consume +0x64c).
//      Does NOT write +0x648 router.
//
// Callers:
//   Client_RecvNpcMissionDialog   - mode=1, EAX=-1 after staging offers
//   Unmapped 0x00924608            - mode=1, EAX=-1 (active-count gate)
//   Client_MissionDialogHandleButton - state 3 re-show (mode=0)
//   FUN_008aec40                     - list click (mode=0)
//
// Exactness: Control flow mirrors raw Ghidra decompile (live ≡ raw 2026-07-29).
// Bit-for-bit vs retail EXE: DEFERRED. Many FUN_* UI helpers unresolved.
// Dual reviews (strengthened 2026-07-29):
//   reviews/A_aa_009438f0_Client_ShowNpcMissionDialogUI.md
//   reviews/B_aa_009438f0_Client_ShowNpcMissionDialogUI.md
// =============================================================================

#include <cstdint>

std::uint32_t* FUN_0053fff0(); // mission def table root
void* CNDHash_LookupByKey(void* hash, unsigned key);
void  FUN_00547920(int mode); // mission UI/side prep
void  FUN_007fef20(int a, int b, int c); // ensure / open panel
void  FUN_007a4480(int level, const char* msg);
char  FUN_0052b420(void* missionDef, int npcObj); // turn-in readiness probe
void  FUN_008aa490();
void  Client_NpcDialog_PrepareResponseOpcode(); // dialog+0x650 = 0x206E
void  FUN_008ab550();
void  FUN_008aa4b0();
std::uint32_t FUN_0052dac0(unsigned missionId, int flags); // reward region ptr (or 0)
void  FUN_008aaf60();
void  FUN_008ac110();
void  FUN_008aa510(unsigned a, unsigned b); // reward / slot clear
// FUN_008aa760(rewardPtr, slotCount, turnInFlag) → dialog+0x64c = turnInFlag
void  FUN_008aa760(std::uint32_t rewardPtr, int slotCount, std::uint32_t turnInFlag);
void  FUN_0092f090(); // finalize dialog present
void  Client_UpdateMissionJournal(void* self, int* pContext);

void Client_ShowNpcMissionDialogUI(int param_1, int param_2, char param_3)
{
    int iVar1;                 // local character*
    int* piVar2;               // mission UI controller* at client+0x1058
    int* piVar3;               // active-mission list node
    char cVar4;
    unsigned in_EAX;           // mission key (EAX; sealed at callers 2026-07-29)
    std::uint32_t* puVar5;     // mission def table root
    unsigned* puVar6;          // mission def*
    std::uint32_t uVar7;       // reward region ptr from FUN_0052dac0
    void* pvVar8;              // active-mission hash hit
    void* this_unused;         // decompiler framing for journal call
    int* unaff_EDI;            // decompiler framing for journal call
    std::uint32_t uVar9;       // turn-in flag → FUN_008aa760 → dialog+0x64c

    // -------------------------------------------------------------------------
    // Guard: dialog stack valid, local character present, mission UI non-null
    // -------------------------------------------------------------------------
    if ((((*(int**)(param_1 + 0xf40) != (int*)0x0) &&
          (**(int**)(param_1 + 0xf40) == *(int*)(param_1 + 0xf38))) &&
         (iVar1 = *(int*)(param_1 + 0xe98), iVar1 != 0)) &&
        (piVar2 = *(int**)(param_1 + 0x1058), piVar2 != (int*)0x0))
    {
        // Resolve mission key + def table
        if ((param_3 == '\0') || (in_EAX != 0xffffffffu)) {
            // Explicit key path (or mode=0 re-show)
            puVar5 = (std::uint32_t*)FUN_0053fff0();
        } else {
            // mode!=0 and mission key == -1: multi-active → journal; else first active
            if (1 < *(unsigned*)(iVar1 + 0x510)) {
                *(std::uint8_t*)(param_1 + 0x19) = 0;
                cVar4 = (**(char (**)())(*piVar2 + 0x3d8))();
                if (cVar4 == '\0') {
                    FUN_007fef20(10, 1, 0);
                }
                FUN_008ab550();
                FUN_008aa4b0();
                Client_UpdateMissionJournal(this_unused, unaff_EDI);
                FUN_0092f090();
                return;
            }
            piVar3 = (int*)**(int**)(iVar1 + 0x50c);
            if (piVar3 == *(int**)(iVar1 + 0x50c)) {
                return; // empty active list
            }
            puVar5 = (std::uint32_t*)FUN_0053fff0();
            in_EAX = (unsigned)piVar3[4]; // first active mission id
        }

        puVar6 = (unsigned*)CNDHash_LookupByKey((void*)*puVar5, in_EAX);
        // Require mission def with non-zero objective-count byte at dword[0x4c]
        if ((puVar6 != (unsigned*)0x0) && ((char)puVar6[0x4c] != '\0')) {
            *(std::uint8_t*)(param_1 + 0x19) = 0;
            FUN_00547920(0);
            cVar4 = (**(char (**)())(*piVar2 + 0x3d8))();
            if (cVar4 == '\0') {
                FUN_007fef20(10, 1, 0);
            } else if (((unsigned*)piVar2[0x19c] == puVar6) && (piVar2[0x191] == param_2)) {
                // Same mission + same NPC already open
                FUN_007a4480(0, "NPC dialog already active!");
                return;
            }

            // cVar4: true if dialog probe says turn-in / active path
            cVar4 = FUN_0052b420(puVar6, param_2);
            FUN_008aa490();
            Client_NpcDialog_PrepareResponseOpcode();
            FUN_008ab550();
            FUN_008aa4b0();
            uVar7 = FUN_0052dac0(*puVar6, 0);

            if (cVar4 == '\0') {
                // Not turn-in probe: check whether mission already active on char
                pvVar8 = CNDHash_LookupByKey(
                    *(void**)(*(int*)(param_1 + 0xe98) + 0x540), *puVar6);
                if (pvVar8 == (void*)0x0) {
                    // Fresh offer — dialog+0x510 = 2 (int*[0x144])
                    FUN_008aaf60();
                    piVar2[0x144] = 2;
                    FUN_008ac110();
                    FUN_008aa510(0xffffffffu, 0xffffffffu);
                    FUN_008aa510(0xffffffffu, 0xffffffffu);
                    uVar9 = 0;
                } else {
                    // Already active — dialog+0x510 = 1
                    FUN_008aaf60();
                    piVar2[0x144] = 1;
                    FUN_008ac110();
                    FUN_008aa510(0xffffffffu, 0xffffffffu);
                    uVar9 = 0;
                }
            } else {
                // Turn-in / claim path — dialog+0x510 = 1, +0x64c = 1 via aa760
                FUN_008aaf60();
                piVar2[0x144] = 1;
                FUN_008ac110();
                FUN_008aa510(0xffffffffu, 0xffffffffu);
                uVar9 = 1;
            }
            FUN_008aa760(uVar7, 4, uVar9);
            FUN_0092f090();
        }
    }
    return;
}
