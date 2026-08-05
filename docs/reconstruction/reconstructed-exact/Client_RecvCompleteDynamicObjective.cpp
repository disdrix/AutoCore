// =============================================================================
// Client_RecvCompleteDynamicObjective
// -----------------------------------------------------------------------------
// Purpose:  S2C handler for opcode **0x2070** (CompleteDynamicObjective).
//           Server-driven force-complete of one objective on the local character:
//             - clear mission UI helper state
//             - optional world-target capture from requirement type==3
//             - ALWAYS CVOGReaction_CompleteObjective(id, -1, -1, force=1)
//             - refresh mission dialog / journal chrome
//             - optional Client_SendUseObject when world target id matches
//             - bulk Client_RefreshOpenMissionUiWindows
//
//           Distinct from Client_RecvObjectiveState (0x2071) which only writes
//           progress slots and never calls CompleteObjective.
//
//           AutoCore protocol note (docs/missionState.md, missionHandler.md):
//             Do NOT send 0x2070 on dialog deliver turn-in - client already ran
//             CompleteObjective locally from MissionDialogHandleButton.
//
// Address:  0x0080ff00  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080ff00
// System:   missions-progression
//
// Convention: packet pointer in stack arg; client/global object in EDI
//             (decompiler `unaff_EDI`) - registered packet-handler pattern.
//
// Packet layout (absolute on buffer):
//   +0x10  objective id (u32) - active-objectives hash key; CompleteObjective arg0
//
// Client object offsets used:
//   +0xe98   local CVOGCharacter*
//   +0x107c  mission UI controller (vtable +0x3d8 / +0x448 / +0x34c)
//   +0x10b0  mission dialog chrome controller
//   +0x1034  optional secondary UI (FUN_0090cbc0)
// Character:
//   +0x548   active objectives hash
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch).
// Bit-for-bit vs retail EXE: DEFERRED. UI vcall identities open.
// =============================================================================

#include <cstdint>
#include <windows.h> // CRITICAL_SECTION / LeaveCriticalSection

void* CNDHash_LookupByKey(void* hash, unsigned key);
void  FUN_0052d8b0(int a, unsigned missionOrSentinel);
std::uint32_t CVOGReaction_CompleteObjective(
    unsigned objectiveId,
    unsigned rewardCoidLo,
    unsigned rewardCoidHi,
    char forceComplete); // thiscall on character often elided by decompiler
void  FUN_008af180(int a);
void  FUN_008a0370();
int   FUN_009197a0(unsigned floatBitsOrKey); // world pick / camera helper
void  FUN_004294f0();
int   FUN_004022a0(int* pIter, int* pOutObj);
void  Client_SendUseObject();
void  Client_RefreshOpenMissionUiWindows(int clientCtx);
void  FUN_0090cbc0();

void Client_RecvCompleteDynamicObjective(int pPacket)
{
    int*  piReq;            // piVar1 - requirement object*
    char  cUi;              // cVar2
    void* pActiveObj;       // pvVar3 - active-objective payload
    int   nWorldTargetId;   // iVar4 - captured then reused
    int   iDialog;          // iVar5
    unsigned uReq;          // uVar6 - requirement index
    int   unaff_EDI;        // client / game object (handler binding; register)
    int   nCapturedTarget;  // local_4 - world target id or -1
    int   pWorldObj;        // reuses param_1 after complete in raw

    // =========================================================================
    // 1) Clear / prep mission UI helper (mission id sentinel -1)
    // =========================================================================
    FUN_0052d8b0(0, 0xffffffffu);

    // =========================================================================
    // 2) Lookup objective in active hash (char+0x548); scan requirements for
    //    type == 3 (vtable+0x50); capture requirement field [6] as world target.
    // =========================================================================
    pActiveObj = CNDHash_LookupByKey(
        *(void**)(*(int*)(unaff_EDI + 0xe98) + 0x548),
        *(unsigned*)(pPacket + 0x10));

    nCapturedTarget = -1;
    if (pActiveObj != (void*)0x0) {
        uReq = 0;
        while (true) {
            int iReqBase = *(int*)((int)pActiveObj + 0x158);
            if ((iReqBase == 0) ||
                ((unsigned)(*(int*)((int)pActiveObj + 0x15c) - iReqBase >> 2) <= uReq))
            {
                goto LAB_after_req_scan;
            }
            piReq = *(int**)(iReqBase + uReq * 4);
            // vtable+0x50 → requirement "type" query; 3 = world/use-object class
            if ((**(int (**)())(*piReq + 0x50))() == 3) {
                break;
            }
            uReq = uReq + 1;
        }
        nCapturedTarget = piReq[6];
    }
LAB_after_req_scan:
    nWorldTargetId = nCapturedTarget;

    // =========================================================================
    // 3) ALWAYS force-complete: CompleteObjective(id, -1, -1, force=1)
    //    Reward COID filter (-1,-1) means accept all inventory reward slots.
    // =========================================================================
    CVOGReaction_CompleteObjective(
        *(unsigned*)(pPacket + 0x10),
        0xffffffffu,
        0xffffffffu,
        1);

    // =========================================================================
    // 4) Mission UI refresh at client+0x107c (same vcall pair as ObjectiveState)
    // =========================================================================
    if ((*(int*)(unaff_EDI + 0x107c) != 0) &&
        (cUi = (**(char (**)())(**(int**)(unaff_EDI + 0x107c) + 0x3d8))(),
         cUi != '\0'))
    {
        (**(void (**)())(**(int**)(unaff_EDI + 0x107c) + 0x448))();
        (**(void (**)())(**(int**)(unaff_EDI + 0x107c) + 0x34c))();
    }

    // =========================================================================
    // 5) Mission dialog chrome at +0x10b0 when open (+0x684 != 0)
    // =========================================================================
    if (((*(int*)(unaff_EDI + 0x10b0) != 0) &&
         (cUi = (**(char (**)())(**(int**)(unaff_EDI + 0x10b0) + 0x3d8))(),
          cUi != '\0')) &&
        (iDialog = *(int*)(unaff_EDI + 0x10b0), *(int*)(iDialog + 0x684) != 0))
    {
        FUN_008af180(0);
        FUN_008a0370();
        if (*(int*)(iDialog + 0x664) != 0) {
            (**(void (**)())(**(int**)(iDialog + 0x664) + 0x480))();
        }
    }

    // =========================================================================
    // 6) Optional world UseObject when requirement captured a target id
    // =========================================================================
    if (nWorldTargetId != -1) {
        pWorldObj = FUN_009197a0(0x41700000); // float bits ~15.0f as key/mode
        if ((pWorldObj == 0) ||
            (*(int*)(*(int*)(pWorldObj + 0xa8) + 0x34) != nWorldTargetId))
        {
            // Scan world object list for matching +0xa8→+0x34 id
            nCapturedTarget = 0;
            FUN_004294f0();
            iDialog = FUN_004022a0(&nCapturedTarget, &pWorldObj);
            while (iDialog != 0) {
                if ((pWorldObj != 0) &&
                    (*(int*)(*(int*)(pWorldObj + 0xa8) + 0x34) == nWorldTargetId))
                {
                    Client_SendUseObject();
                    break;
                }
                iDialog = FUN_004022a0(&nCapturedTarget, &pWorldObj);
            }
            // Release character interaction critical section if held
            nWorldTargetId =
                *(int*)(*(int*)(*(int*)(*(int*)(*(int*)(*(int*)(unaff_EDI + 0xe98) + 4) + 4) +
                                        0xa8 + *(int*)(unaff_EDI + 0xe98)) +
                                0xe4e8) +
                        0x1c);
            if (*(char*)(nWorldTargetId + 0x28) != '\0') {
                *(std::uint8_t*)(nWorldTargetId + 0x28) = 0;
                LeaveCriticalSection((LPCRITICAL_SECTION)(nWorldTargetId + 4));
            }
        } else {
            Client_SendUseObject();
        }
    }

    // =========================================================================
    // 7) Bulk mission UI windows + optional secondary UI at +0x1034
    // =========================================================================
    Client_RefreshOpenMissionUiWindows(unaff_EDI);
    if ((*(int*)(unaff_EDI + 0x1034) != 0) &&
        (cUi = (**(char (**)())(**(int**)(unaff_EDI + 0x1034) + 0x3d8))(),
         cUi != '\0'))
    {
        FUN_0090cbc0();
    }
    return;
}
