// =============================================================================
// Client_MissionDialog_FlushPreparedResponse  (was FUN_008ab8f0)
// -----------------------------------------------------------------------------
// Address:  0x008ab8f0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008ab8f0
// System:   missions-progression
//
// Purpose: On mission-dialog close/teardown, if a prepared C2S response opcode
// is sitting at dialog+0x650, flush 0x20 bytes of that buffer through the sector
// connection vtable (+0x18). That buffer starts with opcode 0x206E when
// Client_NpcDialog_PrepareResponseOpcode has run.
//
// Sealed chain (static):
//   1. Client_ShowNpcMissionDialogUI @ 0x009438f0  (host: client+0x1058)
//        → Client_NpcDialog_PrepareResponseOpcode @ 0x008abd70
//          sets *(dialog+0x650) = 0x206E
//   2. Client_MissionDialogHandleButton @ 0x008ae7c0 state 1
//        fills +0x654 missionId, +0x658 accepted, +0x660 NPC TFID16
//        (does NOT call Client_SendSectorPacket for 0x206E)
//   3. UI event FUN_008aec40 / FUN_008af020 → FUN_007fca10 (if visible)
//        → dialog.vtbl+0x440 = this function
//        if (*(dialog+0x650) != 0) send size 0x20 from dialog+0x650
//
// Object / vtable (UF-010 sealed static):
//   Ctor FUN_008ac3f0: *this = PTR_FUN_00a4a51c (vtable base 0x00a4a51c)
//   Host: client+0x1058 (dialog table index 10 from +0x1030)
//   This method: vtbl+0x440 → DATA 0x00a4a95c → 0x008ab8f0
//   BuildWidgets sibling: vtbl+0x43c
//   NOT invoked by Client_HideMissionDialogIfOpen (+0x107c only)
//
// Assembly (send site):
//   CMP dword ptr [ESI+0x650], 0
//   LEA EAX, [ESI+0x650]
//   MOV ECX, [DAT_00d1b4b8]          ; sector net connection
//   PUSH 0 ; PUSH 0x20 ; PUSH EAX ; PUSH -1
//   CALL dword ptr [EDX+0x18]       ; same send slot as Client_SendSectorPacket
//
// Packet layout (0x20 total, matches AutoCore MissionDialogResponsePacket):
//   +0x00 u32 opcode (0x206E)
//   +0x04 i32 missionId
//   +0x08 u8  accepted + pad3 + pad4
//   +0x10 TFID16 mission giver
//
// Exactness: control flow mirrors Ghidra decompile 2026-07-29 residual re-verify.
// Dual reviews: reviews/A_aa_008ab8f0_* and B_aa_008ab8f0_*
// =============================================================================

#include <cstdint>

// Inferred global: sector connection object used by dialog flush path.
// Distinct binding from Client_SendSectorPacket's this+0xc78, same vtbl+0x18 send.
extern void* g_pSectorNetConnection; // DAT_00d1b4b8
extern int* DAT_00d1d8dc;
extern char DAT_00d1d8f4;
extern char DAT_00d1d8f5;

void FUN_008aa320();
void FUN_00792490();

// this = mission dialog UI object
void __fastcall Client_MissionDialog_FlushPreparedResponse(int* dialog)
{
    char cVisible;
    int* pSlot;
    int i;

    // param_1[0x194] == *(dialog + 0x650) — prepared opcode / packet head
    if ((dialog[0x194] != 0) && (g_pSectorNetConnection != nullptr)) {
        // Send 0x20 bytes starting at dialog+0x650 (opcode already in buffer)
        (**(void (**)(std::uint32_t, int*, int, int))(
            *(int*)g_pSectorNetConnection + 0x18))(
            0xffffffffu, dialog + 0x194, 0x20, 0);
    }

    // Optional cursor/reward UI cleanup (secondary; not part of wire seal)
    if ((((DAT_00d1d8dc != nullptr) &&
          (cVisible = (**(char (**)())(*DAT_00d1d8dc + 0x3d8))(), cVisible != '\0')) &&
         (cVisible = (**(char (**)())(*DAT_00d1d8dc + 0xd0))(), cVisible != '\0')) &&
        (DAT_00d1d8dc[0x146] != 0))
    {
        i = 0;
        pSlot = dialog + 0x156; // reward COID slots near +0x558
        do {
            if ((*pSlot == DAT_00d1d8dc[0x148]) && (pSlot[1] == DAT_00d1d8dc[0x149])) {
                DAT_00d1d8f4 = 1;
                DAT_00d1d8f5 = 0;
                (**(void (**)(int))(*DAT_00d1d8dc + 4))(0);
                break;
            }
            i = i + 1;
            pSlot = pSlot + 2;
        } while (i < 4);
    }

    FUN_008aa320();
    (**(void (**)())(*dialog + 0x3ac))();
    FUN_00792490();
}
