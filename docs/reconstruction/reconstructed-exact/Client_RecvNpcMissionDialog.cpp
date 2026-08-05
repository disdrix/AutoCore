// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, goto×2, while×2, for×1, return×1.
//  - Notable callees: Client_RecvNpcMissionDialog×2, Client_ShowNpcMissionDialogUI, FUN_004bb070, FUN_0052c700, FUN_0052d8b0, FUN_0053fff0, Layout, widgets.
//  - Return sites: 1.

// =============================================================================
// Client_RecvNpcMissionDialog
// -----------------------------------------------------------------------------
// Purpose:  S2C handler for opcode **0x206D** - open NPC mission dialog.
//           For each offered mission entry: lookup mission def, copy 8 item
//           COID slots into a scratch array, call FUN_0052c700 to stage offer
//           data, then Client_ShowNpcMissionDialogUI.
//
// Address:  0x00815070  (autoassault.exe, image base 0x400000)
// Stable:   aa_00815070
// System:   missions-progression
//
// Packet layout (opcode at +0; packet base in EBX):
//   +0x08  NPC TFID (16 bytes) - FUN_004bb070(packet+8)  [stdcall stack-only]
//   +0x18  count **u8** client bound (asm: CMP BYTE / MOVZX BYTE [EBX+0x18])
//          wire may write i32 LE; AutoCore uses i32, low byte only is read
//   +0x20  first missionId; +0x28 first 8× item COID i32 (-1 = empty)
//   per entry stride 40 (ADD EBP, 0x28): missionId @ entry+0, 8× COID @ entry+8
//
// Framing (PacketDispatch @ 0x00815af1): PUSH EBP; MOV EBX,ESI; CALL; RET 4 stdcall.
// Opcode seal: sole case 0x206D → this handler (body never compares opcode).
// Prolog also loads ECX = *(*(pClientCtx+0xe04)+0xe4e8) — DEAD (FUN_004bb070 ignores ECX).
// Before Show: OR EAX,-1 (Show uses in_EAX when mode!=0).
// FUN_0053fff0 this = *(pClientCtx+0xd30); staging FUN this = DAT_00d1b6d8.
//
// Note: client does not filter offered missions — server-side eligibility is
// assumed (see docs/missionWork.md). AutoCore: do not auto-send immediately
// after dialog deliver turn-in.
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch);
//            count/framing/dead+0xe04/Show-EAX sealed via read_memory 2026-07-29 p2.
// Dual reviews:
//   reviews/A_aa_00815070_Client_RecvNpcMissionDialog.md
//   reviews/B_aa_00815070_Client_RecvNpcMissionDialog.md
// Chain:
//   reviews/CHAIN_2026-07-29_s2c_206d_npcmissiondialog.md
// =============================================================================

#include <cstdint>

std::uint32_t FUN_004bb070(void* tfidPtr); // resolve NPC TFID / object
void FUN_0052d8b0(int a, std::uint32_t b); // clear / reset mission dialog staging
int* FUN_0053fff0(); // mission def table root
void FUN_0052c700(std::uint32_t missionKey, std::uint32_t* itemSlots11); // stage offer
void Client_ShowNpcMissionDialogUI(std::uint32_t ctx, std::uint32_t npc, int mode);

void Client_RecvNpcMissionDialog(std::uint32_t param_1) // pClientCtx; stdcall stack formal
{
    unsigned missionId;
    std::uint32_t* puScratch;
    std::uint32_t uNpc;
    int* pTable;
    std::uint32_t* pMissionDef;
    int iNode;
    // Packet base in EBX on entry (call site MOV EBX,ESI). Not a formal stack arg.
    std::uint32_t* unaff_EBX;
    std::uint32_t* puSrc;
    std::uint32_t* puDst;
    int local_index;
    std::uint32_t local_slots[11]; // local_30[11]
    std::uint8_t local_4;

    uNpc = FUN_004bb070(unaff_EBX + 2); // TFID at packet+8 (dword index 2)
    FUN_0052d8b0(0, 0xffffffffu); // thiscall character; clear staging key=-1

    local_index = 0;
    puScratch   = unaff_EBX;
    // count = *(u8*)(packet+0x18) — sealed CMP BYTE / MOVZX BYTE (not dword)
    if (*(char*)(unaff_EBX + 6) != '\0') {
        do {
            // mission id at entry dword index 8; stride 10 dwords (40 bytes)
            missionId = puScratch[8];
            pTable    = (int*)FUN_0053fff0();
            iNode     = *pTable;
            if (iNode != 0) {
                // Manual hash walk of mission def table
                iNode = *(int*)(*(int*)(*(int*)(iNode + 0x10) +
                                        (*(unsigned*)(iNode + 8) & missionId) * 4) +
                                4);
                if (iNode == 0) {
                LAB_00815102:
                    pMissionDef = (std::uint32_t*)0x0;
                } else {
                    do {
                        if (missionId == *(unsigned*)(iNode + 0x10)) {
                            if (iNode == 0) goto LAB_00815102;
                            pMissionDef = *(std::uint32_t**)(iNode + 8);
                            goto LAB_00815109;
                        }
                        iNode = *(int*)(iNode + 0xc);
                    } while (iNode != 0);
                    pMissionDef = (std::uint32_t*)0x0;
                }
            LAB_00815109:
                if (pMissionDef != (std::uint32_t*)0x0) {
                    // Init 11 slots to -1, then copy 8 item COIDs from entry+0x28
                    local_slots[8]  = 0xffffffffu;
                    local_slots[9]  = 0xffffffffu;
                    local_slots[10] = 0xffffffffu;
                    local_slots[0]  = 0xffffffffu;
                    local_slots[1]  = 0xffffffffu;
                    local_slots[2]  = 0xffffffffu;
                    local_slots[3]  = 0xffffffffu;
                    local_slots[4]  = 0xffffffffu;
                    local_slots[5]  = 0xffffffffu;
                    local_slots[6]  = 0xffffffffu;
                    local_slots[7]  = 0xffffffffu;
                    local_4         = 0;
                    puSrc           = puScratch + 10;
                    puDst           = local_slots;
                    for (iNode = 8; iNode != 0; iNode = iNode + -1) {
                        *puDst = *puSrc;
                        puSrc  = puSrc + 1;
                        puDst  = puDst + 1;
                    }
                    FUN_0052c700(*pMissionDef, local_slots);
                }
            }
            local_index = local_index + 1;
            puScratch   = puScratch + 10;
        } while (local_index < (int)(unsigned)*(std::uint8_t*)(unaff_EBX + 6));
    }

    // Image: OR EAX,-1 immediately before CALL — Show reads in_EAX when mode!=0.
    // (Not expressible as a C formal; required register pre-seed for live client.)
    Client_ShowNpcMissionDialogUI(param_1, uNpc, 1);
    return;
}
