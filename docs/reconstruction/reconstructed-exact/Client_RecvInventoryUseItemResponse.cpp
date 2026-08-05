// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: Client_RecvInventoryUseItemResponse, Client_RefreshOpenMissionUiWindows, FUN_00571010, FUN_00571d80, FUN_007fee30, FUN_00933310.
//  - Return sites: 1.

// =============================================================================
// Client_RecvInventoryUseItemResponse
// -----------------------------------------------------------------------------
// Purpose:  S2C use-item response. On remaining count < 1 removes/consumes the
//           item and runs failure UI; otherwise updates stack count on the
//           resolved cargo item. Always refreshes open mission windows and
//           optional craft/use UI hosts.
//
// Address:  0x00810280  (autoassault.exe, image base 0x400000)
// Stable:   aa_00810280
// System:   inventory-transfer
//
// Convention: pGameState stack arg; packet base in ESI (unaff_ESI).
//
// Packet fields:
//   +0x08/+0x0c  item TFID lo/hi
//   +0x10        i32 remaining count (<1 → consume/fail path)
//   +0x14        u16 stack metadata written to item+0x180
//
// Control flow summary:
//   1) Require local char game+0xe98 and char+0x250 (in-world vehicle/cargo)
//   2) if count@+0x10 < 1:
//        FUN_00571d80(item TFID) → fail UI FUN_007fee30 + FUN_00933310
//      else:
//        item = FUN_00571010(TFID); vtbl+0x260(count); short@item+0x180 = pkt+0x14
//   3) Client_RefreshOpenMissionUiWindows(pGameState)
//   4) if game+0x309c: vtbl+4(0); if dialog+0x10b0 visible: vtbl+0x450(0)
//
// Exactness: CF mirrors raw; some vcall bodies noted as comments where width
//            recovery is incomplete. Bit-for-bit deferred.
// Dual reviews: pending (not transfer-core critical path).
// =============================================================================

extern int  FUN_00571d80(unsigned a, unsigned b, int c);
extern int* FUN_00571010(unsigned a, unsigned b);
extern void FUN_007fee30(void);
extern void FUN_00933310(int game, int, int, unsigned, unsigned);
extern void Client_RefreshOpenMissionUiWindows(int pGameState);

/// @param pGameState  Client / game state host.
/// @note packet base = unaff_ESI at entry.
void Client_RecvInventoryUseItemResponse(int pGameState)
{
    int pPacket = 0; // ESI residual (packet)
    int* pItem;
    int* pDlg;
    char bVisible;

    if (*(int*)(pGameState + 0xe98) == 0) {
        return;
    }
    if (*(int*)(*(int*)(pGameState + 0xe98) + 0x250) == 0) {
        return;
    }

    if (*(int*)(pPacket + 0x10) < 1) {
        if (FUN_00571d80(*(unsigned*)(pPacket + 8), *(unsigned*)(pPacket + 0xc),
                         0)
            != 0) {
            FUN_007fee30();
            FUN_00933310(pGameState, 1, 0, 0xffffffffu, 0xffffffffu);
        }
    } else {
        pItem = FUN_00571010(*(unsigned*)(pPacket + 8),
                             *(unsigned*)(pPacket + 0xc));
        if (pItem != 0) {
            // (**(code **)(*pItem + 0x260))(count @ +0x10);
            // *(uint16*)((char*)pItem + 0x180) = *(uint16*)(pPacket + 0x14);
            (void)pItem;
        }
    }

    Client_RefreshOpenMissionUiWindows(pGameState);
    if (*(int*)(pGameState + 0x309c) != 0) {
        // (**(code **)(**(int**)(pGameState+0x309c) + 4))(0);
    }
    pDlg = *(int**)(pGameState + 0x10b0);
    if (pDlg != 0) {
        // bVisible = vtable+0x3d8(); if visible → vtable+0x450(0)
        (void)bVisible;
        (void)pDlg;
    }
}
