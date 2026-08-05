// READABILITY (auto CF):
//  - Body size: ~183 non-empty decompiler lines.
//  - Control keywords: if×25, return×12, for×3, goto×1.
//  - Notable callees: FUN_007a6de0×5, Client_HideMissionDialogIfOpen×2, FUN_007fdfb0×2, sprintf×2, CVOGReaction_GiveMission, Client_MaybeShowFirstTimeTip, Client_MissionDialogHandleButton, Client_RefreshMissionDialogChrome.
//  - Strings: "this mission"; "Are you sure you wish to abandon"; "%s \"%s\"?"; "You need to select a reward first!".
//  - Return sites: 12.

// =============================================================================
// Client_MissionDialogHandleButton
// -----------------------------------------------------------------------------
// Purpose:  Mission dialog button router. Dialog state at context+0x648:
//     0 = send sector packet 0x206F (accept-request)
//     1 = accept offer OR claim/complete deliver (CompleteObjective path)
//     2 = abandon confirmation prompt
//     3 = re-show NPC mission dialog UI
//
// Address:  0x008ae7c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008ae7c0
// System:   missions-progression
//
// Convention: MSVC __cdecl
//   pDialogContext  - overloaded: button index / mode (decompiler int*)
//   iButtonIndex    - second arg (often unused; primary state on global ctx)
//   in_EAX          - mission dialog UI object / global dialog context
//
// State 1 complete path (dialog+0x64c turn-in mode):
//   reward selection checks → "Finished Mission" toast →
//   Client_ShowMissionRewardChatToast → CVOGReaction_CompleteObjective →
//   Client_RefreshMissionDialogChrome / Hide / RefreshOpenMissionUiWindows
//
// Response payload fields filled at dialog+0x650.. for C2S 0x206E.
// Opcode 0x206E is written by Client_NpcDialog_PrepareResponseOpcode.
// THIS FUNCTION does not send 0x206E — send is Client_MissionDialog_FlushPreparedResponse
// @ 0x008ab8f0 (dialog teardown; size 0x20 from +0x650). State 0 still sends 0x206F directly.
// Abandon state 2: stash DAT_00d1b4b4; open dual-id modal via Client_ShowModalPrompt:
//   Yes/OK  = EAX 0x4e46 at open site (image MOV EAX,0x4e46; decompiler often omits)
//   No/Cancel = stack secondary 0x4e47 (decompiler third arg)
// Confirm C2S 0x20B2 is NOT here — UiModal case 0x4e46 (see chain). Residual: runtime only.
// Chains: reviews/CHAIN_2026-07-29_c2s_206e_seal.md, CHAIN_2026-07-29_abandon_failmission.md
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch; seal notes 2026-07-29).
// Dual reviews:
//   reviews/A_aa_008ae7c0_Client_MissionDialogHandleButton.md
//   reviews/B_aa_008ae7c0_Client_MissionDialogHandleButton.md
// =============================================================================

#include <cstdint>
#include <cstdio>

extern int DAT_00d1b6d8; // global client / game singleton
extern std::uint32_t DAT_00d1b4b4;
extern std::uint8_t DAT_00d1a840[]; // UI / sector send context
extern char DAT_00d1b216;
extern int DAT_00d1ad10;
extern int DAT_00d1b8dc;
extern char DAT_00a156cc;

void FUN_007a69d0();
std::uint32_t FUN_007a6de0(const char* s, std::uint32_t unk);
// Modal prompt: also takes Yes id in EAX (not in this C signature). Abandon open:
//   EAX=0x4e46 (Yes), code/param_3=0x4e47 (No). See dual A §3 / UF-009.
void FUN_007fdfb0(void* ui, const char* msg, int code, int a, int b);
void Client_SendSectorPacket(void* ctx, int size, void* packet);
void Client_ShowNpcMissionDialogUI(void* ctx, std::uint32_t npc, int mode);
int  CVOGReaction_ResolveObjectTarget(int mode, unsigned lo, unsigned hi);
char FUN_005714e0(int obj, void* a, void* b, int c, int d); // inventory space check
// thiscall on character; decompiler often shows only mission id
void CVOGReaction_GiveMission(std::uint32_t missionId);
void FUN_0092fd00(); // post-accept complete helper
void Client_HideMissionDialogIfOpen();
void Client_MaybeShowFirstTimeTip(int tipId);
void FUN_008ac7a0(); // refresh dialog lists
void FUN_008f8200(int chat, int channel, void* style, char* text, int z);
void Client_ShowMissionRewardChatToast(int objectiveDef);
char CVOGReaction_CompleteObjective(
    std::uint32_t objectiveId, std::uint32_t a, std::uint32_t b, std::uint32_t reason);
void Client_RefreshMissionDialogChrome();
void Client_RefreshOpenMissionUiWindows(void* ctx);

char __cdecl Client_MissionDialogHandleButton(int* pDialogContext, int /*iButtonIndex*/)
{
    std::uint32_t* puMission;
    char cOk;
    int in_EAX; // dialog UI context (register)
    char* pcMsg;
    std::uint32_t uVar4;
    int iVar5;
    std::uint32_t uVar6, uVar7, uVar8;
    std::uint8_t uStack_21a, uStack_219;
    std::uint32_t auStack_218[2];
    std::uint32_t uStack_210, uStack_20c;
    std::uint8_t uStack_208;
    char acStack_200[512];

    // Global client must be alive
    if (DAT_00d1b6d8 == 0) {
        return '\0';
    }
    FUN_007a69d0();

    // Active dialog slot: in_EAX + 0x708 + pDialogContext*4
    if (*(int*)(in_EAX + 0x708 + (int)pDialogContext * 4) != 0) {
        // If a modal child is open (vtable +0x1f8), close it (+0x1fc) and abort
        if ((*(int**)(in_EAX + 0x6e0) != (int*)0x0) &&
            (cOk = (**(char (**)())(**(int**)(in_EAX + 0x6e0) + 0x1f8))(), cOk != '\0'))
        {
            (**(void (**)())(**(int**)(in_EAX + 0x6e0) + 0x1fc))();
            return '\0';
        }

        // Route by dialog state at +0x648
        iVar5 = *(int*)(in_EAX + 0x648);

        // -----------------------------------------------------------------
        // State 2: abandon confirmation
        // -----------------------------------------------------------------
        if (iVar5 == 2) {
            if (pDialogContext == (int*)0x1) {
                if (*(std::uint32_t**)(in_EAX + 0x670) == (std::uint32_t*)0x0) {
                    DAT_00d1b4b4 = 0xffffffffu;
                } else {
                    DAT_00d1b4b4 = **(std::uint32_t**)(in_EAX + 0x670);
                }
                uVar7 = 0xffffffffu;
                if (*(int**)(in_EAX + 0x6dc) == (int*)0x0) {
                    pcMsg = (char*)"this mission";
                } else {
                    pcMsg = (char*)(**(std::uint32_t*(**)(std::uint32_t))(
                        **(int**)(in_EAX + 0x6dc) + 0x1dc))(0xffffffffu);
                }
                uVar7 = FUN_007a6de0(pcMsg, uVar7);
                uVar4 = FUN_007a6de0("Are you sure you wish to abandon", 0xffffffffu);
                sprintf(acStack_200, "%s \"%s\"?", (const char*)uVar4, (const char*)uVar7);
                // Image: MOV EAX,0x4e46 (Yes) then CALL; third arg 0x4e47 is No only.
                FUN_007fdfb0(&DAT_00d1a840, acStack_200, 0x4e47, 1, 0);
                return '\0';
            }
        } else {
            // -------------------------------------------------------------
            // State 0: send sector 0x206F accept-request
            // -------------------------------------------------------------
            if (iVar5 == 0) {
                uStack_210      = *(std::uint32_t*)(in_EAX + 0x678);
                uStack_20c      = *(std::uint32_t*)(in_EAX + 0x67c);
                uStack_208      = (std::uint8_t)(uintptr_t)pDialogContext;
                auStack_218[0]  = 0x206f;
                Client_SendSectorPacket(&DAT_00d1a840, 0x18, auStack_218);
                return '\x01';
            }

            // -------------------------------------------------------------
            // State 3: re-show NPC dialog UI
            // -------------------------------------------------------------
            if (iVar5 == 3) {
                Client_ShowNpcMissionDialogUI(
                    &DAT_00d1a840, *(std::uint32_t*)(in_EAX + 0x644), 0);
                return '\0';
            }

            // -------------------------------------------------------------
            // State 1: accept mission / claim reward
            // -------------------------------------------------------------
            if ((iVar5 == 1) && (*(int*)(in_EAX + 0x670) != 0)) {
                // Turn-in mode (+0x64c): require reward selection masks
                if ((*(char*)(in_EAX + 0x64c) != '\0') &&
                    (((*(unsigned*)(in_EAX + 0x558) & *(unsigned*)(in_EAX + 0x55c)) !=
                          0xffffffffu &&
                      ((*(unsigned*)(in_EAX + 0x578) & *(unsigned*)(in_EAX + 0x57c)) ==
                       0xffffffffu))))
                {
                    pcMsg = (char*)"You need to select a reward first!";
                LAB_008ae999:
                    uVar6 = 1;
                    uVar4 = 0xffffffffu;
                    uVar8 = 0;
                    uVar7 = FUN_007a6de0(pcMsg, 0xffffffffu);
                    FUN_007fdfb0(&DAT_00d1a840, (const char*)uVar7, (int)uVar4, (int)uVar6,
                                 (int)uVar8);
                    return '\0';
                }

                // Optional reward object COID at +0x578/+0x57c - inventory space
                if ((*(unsigned*)(in_EAX + 0x578) & *(unsigned*)(in_EAX + 0x57c)) !=
                    0xffffffffu)
                {
                    if (DAT_00d1b6d8 == 0) {
                        return '\0';
                    }
                    if (*(int*)(DAT_00d1b6d8 + 0x250) == 0) {
                        return '\0';
                    }
                    if (*(int*)(*(int*)(DAT_00d1b6d8 + 0x250) + 0x2b0) == 0) {
                        return '\0';
                    }
                    iVar5 = CVOGReaction_ResolveObjectTarget(
                        1, *(unsigned*)(in_EAX + 0x578), *(unsigned*)(in_EAX + 0x57c));
                    if (iVar5 != 0) {
                        uStack_21a = 0;
                        uStack_219 = 0;
                        cOk = FUN_005714e0(iVar5, &uStack_21a, &uStack_219, 1, 0xffffffff);
                        if (cOk == '\0') {
                            pcMsg =
                                (char*)"Your inventory is full. You must have space in "
                                       "your inventory to receive the mission reward.";
                            goto LAB_008ae999;
                        }
                    }
                }

                // Snapshot NPC TFID into dialog+0x660.. from entity at +0x644
                iVar5 = *(int*)(in_EAX + 0x644);
                if (iVar5 == 0) {
                    *(std::uint8_t*)(in_EAX + 0x668)  = 0;
                    *(std::uint32_t*)(in_EAX + 0x660) = 0xffffffffu;
                    *(std::uint32_t*)(in_EAX + 0x664) = 0xffffffffu;
                } else {
                    puMission =
                        (std::uint32_t*)(*(int*)(*(int*)(iVar5 + 4) + 4) + 0x164 + iVar5);
                    *(std::uint32_t*)(in_EAX + 0x660) = *puMission;
                    *(std::uint32_t*)(in_EAX + 0x664) = puMission[1];
                    *(std::uint32_t*)(in_EAX + 0x668) = puMission[2];
                    *(std::uint32_t*)(in_EAX + 0x66c) = puMission[3];
                }

                // Mission def pointer at dialog+0x670; store mission id at +0x654
                puMission = *(std::uint32_t**)(in_EAX + 0x670);
                *(std::uint32_t*)(in_EAX + 0x654) = *puMission;

                if (*(char*)(in_EAX + 0x64c) == '\0') {
                    // ----- Accept-offer path (not turn-in) -----
                    *(int**)(in_EAX + 0x658) = pDialogContext;
                    *(int*)(in_EAX + 0x65c)  = (int)pDialogContext >> 0x1f;
                    if ((pDialogContext == (int*)0x0) && (DAT_00d1b6d8 != 0)) {
                        // Award new mission (thiscall: character in ECX from caller
                        // context; decompiler surfaces only mission id stack arg).
                        CVOGReaction_GiveMission(*puMission);
                        // Auto-complete first objective under certain UI flags
                        if (((DAT_00d1b216 != '\0') ||
                             ((*(short*)(*(int*)(in_EAX + 0x670) + 0xfa) != 0 ||
                               (*(int*)(DAT_00d1ad10 + 0x10) < 1)))) &&
                            (*(char*)(*(int*)(in_EAX + 0x670) + 0x130) != '\0'))
                        {
                            FUN_0092fd00();
                        }
                        Client_HideMissionDialogIfOpen();
                        Client_MaybeShowFirstTimeTip(2);
                        FUN_008ac7a0();
                    }
                } else {
                    // ----- Turn-in / claim reward path -----
                    *(std::uint32_t*)(in_EAX + 0x65c) = *(std::uint32_t*)(in_EAX + 0x57c);
                    *(std::uint32_t*)(in_EAX + 0x658) = *(std::uint32_t*)(in_EAX + 0x578);

                    // Last objective in list: def[0x4f] array, index (byte def[0x4c])-1
                    iVar5 = *(int*)(puMission[0x4f] + -4 +
                                    (unsigned)*(std::uint8_t*)(puMission + 0x4c) * 4);
                    if (iVar5 != 0) {
                        uVar7 = FUN_007a6de0((const char*)puMission[0x53], 0xffffffffu);
                        uVar4 = FUN_007a6de0("Finished Mission", 0xffffffffu);
                        sprintf(acStack_200, "%s \"%s\"", (const char*)uVar4,
                                (const char*)uVar7);
                        if (DAT_00d1b8dc != 0) {
                            FUN_008f8200(DAT_00d1b8dc, 6, &DAT_00a156cc, acStack_200, 0);
                        }
                        Client_ShowMissionRewardChatToast(iVar5);
                        cOk = CVOGReaction_CompleteObjective(
                            *(std::uint32_t*)(iVar5 + 0x10),
                            *(std::uint32_t*)(in_EAX + 0x578),
                            *(std::uint32_t*)(in_EAX + 0x57c),
                            0);
                        if (cOk == '\0') {
                            return '\0';
                        }
                        Client_RefreshMissionDialogChrome();
                        Client_HideMissionDialogIfOpen();
                        Client_RefreshOpenMissionUiWindows(&DAT_00d1a840);
                        return '\x01';
                    }
                }
            }
        }
    }
    return '\x01';
}
