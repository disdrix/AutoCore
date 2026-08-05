// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×16, return×9, do×1, while×1.
//  - Notable callees: Client_QuickBarActivateSkillSlot×2, Client_CastSkillFromQuickBarSlot, FUN_005710c0, FUN_008a0ed0 (page), FUN_00922270 (primary), FUN_00941d50 (use-item 0x2045), FUN_00941fb0 (chat 0x2021).
//  - Return sites: 9.

// =============================================================================
// Client_QuickBar_ActivateSlot
// -----------------------------------------------------------------------------
// Purpose:  Activate a quick-bar slot by (slot, mode, page). Dispatches on slot
//           binding type: cast skill, use cargo item, or chat-macro bank.
//           On-foot (character+0x6b9) with vehicle-host visibility also remaps
//           slot 0/1 to skill-slot cast or primary/secondary weapon fire.
//
// Address:  0x009436c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_009436c0
// System:   skills-abilities
//
// Convention: Client object in EAX (decomp in_EAX). Stack formals: slot, mode,
//             page. Clean keeps register convention for client.
//
// Args:
//   nSlot   Slot index within page (0..9 typical); for mode 1 = page to select
//   nMode   0 = activate; 1 = select page (shift-QB; FUN_008a0ed0 / SelectPage)
//   nPage   Page index; -1 → read page from quick-bar UI host +0x50c
//
// Index math: flatIndex = nSlot + page * 10
// Slot table @ client+0x3220 + flatIndex*0x18  (stride 0x18):
//   +0x00  i32 type  (1=skill, 2=item, 5=chat-macro bank)
//   +0x08  payload lo (skillId / item COID / macro-row base as int64 lo)
//   +0x0c  payload hi
// Packing identity (residual sealed 2026-07-29):
//   client+(flatIndex*3+0x645)*8  ==  client+0x3220+flatIndex*0x18+8
// Busy latch @ client+0x3b80+flatIndex (set 1 while activating, clear after)
//
// Control flow summary:
//   1) char = client+0xe98
//   2) if char non-null AND (on-foot or related flag) AND vehicle host
//      client+0xf38 non-null AND vtbl+0x3d8 visible:
//          slot0 → Client_QuickBarActivateSkillSlot(0) if +0x6b9
//                  else FUN_00922270 (primary fire / hardpoint skill)
//          slot1 → Client_QuickBarActivateSkillSlot(1) if +0x6b9
//                  else Input_TryFireSecondaryWeapons
//   3) else if quick-bar UI client+0x10b0 non-null:
//        page = (nPage==-1) ? UI+0x50c : nPage
//        if nMode==1 → FUN_008a0ed0 (page select 0..9); return
//        flatIndex = nSlot + page*10
//        if busy latch clear:
//          set latch; switch type:
//            1 → Client_CastSkillFromQuickBarSlot(skillId)
//            2 → cargo lookup FUN_005710c0(itemCoid); block subtype 8 at
//                cloneMeta+0x3f4; FUN_00941d50(1) use-item (C2S 0x2045);
//                clear latch
//            5 → chat-macro bank: require int64(payload)+3000 ∈ [0,14]
//                (carry const 0xfffff447 == UINT32_MAX-3000); walk
//                DAT_00d177c8 + row*5 for 5 phrases; FUN_00941fb0 (0x2021)
//          clear latch
//
// Key offsets:
//   client+0xe98   character
//   char+0x6b9     on-foot
//   char+0x6b8     related vehicle-state flag
//   client+0xf38   vehicle / sim host (vtbl+0x3d8 visibility)
//   client+0x10b0  quick-bar UI controller
//   client+0x3220  slot type table (stride 0x18)
//   client+0x3b80  per-slot busy bytes
//   client+0x1138  UI host for type-5 macro send path (identity Probable)
//
// Callees (residual roles 2026-07-29; product names _Inferred only in duals):
//   Client_CastSkillFromQuickBarSlot   0x009418e0
//   Client_QuickBarActivateSkillSlot   0x00921b50
//   Input_TryFireSecondaryWeapons      0x0091a550
//   FUN_005710c0  cargo find by COID
//   FUN_00941d50  use-item activate (C2S 0x2045) — UseInventoryItem_Inferred
//   FUN_00941fb0  chat/macro send (0x2021) — SendChatOrMacro_Inferred
//   FUN_008a0ed0  mode-1 page select — QuickBar_SelectPage_Inferred
//   FUN_00922270  primary fire / hardpoint — TryFirePrimaryWeapons_Inferred
//
// Type-5 note: NOT combat power. DAT_00d177c8 owned by Client_ChatMacroQuickPhrases.
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual reviews:
//   reviews/A_aa_009436c0_Client_QuickBar_ActivateSlot.md
//   reviews/B_aa_009436c0_Client_QuickBar_ActivateSlot.md
// Residual scratch: tmp/a_009436c0.md (2026-07-29)
// =============================================================================

#include <cstdint>

extern "C" void  FUN_008a0ed0();
extern "C" void  Client_CastSkillFromQuickBarSlot(std::uint32_t skillId);
extern "C" int   FUN_005710c0(std::uint32_t coidLo, int a, int b);
extern "C" void  FUN_00941d50(int mode);
extern "C" void  FUN_00941fb0(int client, std::uint32_t host, int flag);
extern "C" void  Client_QuickBarActivateSkillSlot(char slot);
extern "C" void  FUN_00922270();
extern "C" void  Input_TryFireSecondaryWeapons();
extern "C" int   DAT_00d177c8;

/// @param nSlot  Slot within page.
/// @param nMode  Activate mode (1 = alternate early path).
/// @param nPage  Page index, or -1 to read from UI+0x50c.
/// @note client arrives in EAX (retail / decomp in_EAX).
void Client_QuickBar_ActivateSlot(char nSlot, char nMode, char nPage)
{
    unsigned packLo;
    char hostVisible;
    int client = 0; // in_EAX
    int pageOrUi;
    int slotType;
    int* macroTable;

    int character = *(int*)(client + 0xe98);

    // Vehicle-sim / on-foot gate: when character present, (on-foot OR related
    // flag), vehicle host non-null, and host visible → remap slot 0/1.
    if ((character == 0)
        || ((((*(char*)(character + 0x6b9) == '\0'
              && (*(char*)(character + 0x6b8) == '\0'))
             || (*(int*)(client + 0xf38) == 0))
            || (hostVisible =
                    (**(char(***)())(**(int**)(client + 0xf38) + 0x3d8))(),
                hostVisible == '\0'))))
    {
        if (*(int*)(client + 0x10b0) != 0) {
            if (nPage == -1) {
                pageOrUi = *(int*)(*(int*)(client + 0x10b0) + 0x50c);
            } else {
                pageOrUi = (int)nPage;
            }

            if (nMode == '\x01') {
                FUN_008a0ed0();
                return;
            }

            int flatIndex = (int)nSlot + pageOrUi * 10;

            if (*(char*)(flatIndex + 0x3b80 + client) == '\0') {
                *(std::uint8_t*)(flatIndex + 0x3b80 + client) = 1;
                slotType = *(int*)(client + 0x3220 + flatIndex * 0x18);

                if (slotType == 1) {
                    Client_CastSkillFromQuickBarSlot(
                        *(std::uint32_t*)(client
                                          + (flatIndex * 3 + 0x645) * 8));
                } else if (slotType == 2) {
                    if ((*(int*)(client + 0xe98) != 0)
                        && (*(int*)(*(int*)(client + 0xe98) + 0x250) != 0)
                        && (*(int*)(*(int*)(*(int*)(client + 0xe98) + 0x250)
                                    + 0x2b0)
                            != 0)
                        && (slotType = FUN_005710c0(
                                           *(std::uint32_t*)(
                                               client
                                               + (flatIndex * 3 + 0x645) * 8),
                                           0, 0),
                            slotType != 0))
                    {
                        int cloneMeta =
                            *(int*)(*(int*)(slotType + 0xa8) + 0x3c);
                        if ((cloneMeta != 0)
                            && (*(short*)(cloneMeta + 0x3f4) == 8)) {
                            return;
                        }
                        FUN_00941d50(1);
                        *(std::uint8_t*)(flatIndex + 0x3b80 + client) = 0;
                        return;
                    }
                } else if (slotType == 5) {
                    // Chat-macro bank: int64(payload)+3000 must be in [0,14]
                    // (0xfffff447 == UINT32_MAX-3000 → add-with-carry of 3000).
                    int pack = flatIndex * 3 + 0x645;
                    packLo = *(unsigned*)(client + pack * 8);
                    unsigned packLoPlus = packLo + 3000;
                    int packHi =
                        *(int*)(client + 4 + pack * 8)
                        + (unsigned)(0xfffff447 < packLo);
                    if ((*(int*)(client + 0x1138) != 0) && (packHi < 1)
                        && ((packHi < 0) || (packLoPlus < 0xf))
                        && (-1 < packHi))
                    {
                        macroTable = &DAT_00d177c8 + packLoPlus * 5;
                        int remaining = 5;
                        do {
                            if (*macroTable != 0) {
                                FUN_00941fb0(
                                    client,
                                    *(std::uint32_t*)(
                                        *(int*)(client + 0x1138) + 0x510),
                                    1);
                            }
                            macroTable = macroTable + 1;
                            remaining = remaining + -1;
                        } while (remaining != 0);
                        *(std::uint8_t*)(flatIndex + 0x3b80 + client) = 0;
                        return;
                    }
                }

                *(std::uint8_t*)(flatIndex + 0x3b80 + client) = 0;
            }
        }
    } else {
        if (nSlot == '\0') {
            if (*(char*)(*(int*)(client + 0xe98) + 0x6b9) != '\0') {
                Client_QuickBarActivateSkillSlot('\0');
                return;
            }
            FUN_00922270();
            return;
        }
        if (nSlot == '\x01') {
            if (*(char*)(*(int*)(client + 0xe98) + 0x6b9) != '\0') {
                Client_QuickBarActivateSkillSlot('\x01');
                return;
            }
            Input_TryFireSecondaryWeapons();
            return;
        }
    }
    return;
}
