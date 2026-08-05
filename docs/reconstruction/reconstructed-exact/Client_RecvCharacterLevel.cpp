// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: CVOGCharacter_ApplyCharacterLevelPacket, Client_LookupObjectByTfid_Inferred, Client_RecvCharacterLevel, Client_RefreshLocalCharacterLevelUi, Client_RefreshOpenMissionUiWindows, FUN_008a05a0, TFID, pGameClient.
//  - Return sites: 1.

// =============================================================================
// Client_RecvCharacterLevel
// -----------------------------------------------------------------------------
// Purpose:  S2C CharacterLevel (opcode 0x2017) client handler. Applies an
//           ABSOLUTE money/XP/level/points snapshot to the target object by
//           TFID, then refreshes local level UI / mission windows / HUD.
//
// Address:  0x00810f00  (autoassault.exe, image base 0x400000)
// Stable:   aa_00810f00
// System:   missions-progression / client net (progress snapshot)
//
// Convention: MSVC __fastcall
//   pGameClient = client state* (this/ECX) - local char @ +0xe98
//   pPacket     = formal Packet_CharacterLevel* (often unused)
//   pPacketInEax / packet body often arrives in EAX from dispatch:
//     +0x08  coidLo
//     +0x0c  coidHi
//     +0x10  bGlobal (byte)
//   (full snapshot fields consumed inside ApplyCharacterLevelPacket vfunc)
//
// Algorithm:
//   1) pObj = Client_LookupObjectByTfid_Inferred(bGlobal, coidLo, coidHi)
//   2) if pObj: vtable +0xcc → CVOGCharacter_ApplyCharacterLevelPacket
//   3) if local char TFID matches packet TFID:
//        Client_RefreshLocalCharacterLevelUi
//        if HUD widget game+0x1034 visible: vtable +0x448 / +0x34c refresh
//   4) Client_RefreshOpenMissionUiWindows(pGameClient)
//   5) if secondary HUD game+0x10b0 visible: FUN_008a05a0
//
// AutoCore: login restore, /credits money UI, post-level CharacterLevel sync.
// Absolute Currency/Experience - NOT an additive grant (contrast GiveCredits /
// GiveXP). Do not send a full-total GiveXP on login (would re-apply XP).
//
// Dispatched from Client_PacketDispatch case 0x2017 @ 0x00815710
// Exactness: Human-refined; control flow mirrors raw Ghidra decompile (2026-07-23).
// Dual reviews: reviews/A_aa_00810f00_review.md, reviews/B_aa_00810f00_review.md
// =============================================================================

#include <cstdint>

// Lookup + UI
int*  Client_LookupObjectByTfid_Inferred(uint8_t bGlobal, unsigned coidLo,
                                         unsigned coidHi);
void  Client_RefreshLocalCharacterLevelUi();
void  Client_RefreshOpenMissionUiWindows(void* pGameClient);
void  FUN_008a05a0();

// Packet_CharacterLevel stand-in (header fields used at this layer only)
struct Packet_CharacterLevel {
    uint32_t dwOpcode; // +0
    // ... header ...
    // body used via EAX framing below
};

void __fastcall Client_RecvCharacterLevel(void* pGameClient,
                                          Packet_CharacterLevel* /* pPacket */)
{
    char  bUiVisible;
    int   pPacketInEax;     // packet body framing (coid @ +8/+0xc, global @ +0x10)
    int*  pObject;          // resolved world object*
    int   nLocalPlayerOff;  // dual-base offset on local character
    int   nLocalTfidBase;   // local TFID triple base (+0x164 from dual-base)
    int   pLocalChar;       // local Character* @ game+0xe98

    // ----- 1-2) Resolve target by TFID and apply absolute snapshot -----
    pObject = Client_LookupObjectByTfid_Inferred(
        *(uint8_t*)(pPacketInEax + 0x10),
        *(unsigned*)(pPacketInEax + 8),
        *(unsigned*)(pPacketInEax + 0xc));
    if (pObject != (int*)0x0) {
        // vtable +0xcc → CVOGCharacter_ApplyCharacterLevelPacket(obj, packet)
        (**(int (**)())(*pObject + 0xcc))();
    }

    // ----- 3) Local-player TFID match → level UI -----
    if (*(int*)((int)pGameClient + 0xe98) != 0) {
        pLocalChar = *(int*)((int)pGameClient + 0xe98);
        nLocalPlayerOff = *(int*)(*(int*)(pLocalChar + 4) + 4);
        nLocalTfidBase = nLocalPlayerOff + 0x164 + pLocalChar;
        // Compare packet coidLo/coidHi/bGlobal to local TFID triple
        if (((*(int*)(pPacketInEax + 8) ==
              *(int*)(nLocalPlayerOff + 0x164 + pLocalChar)) &&
             (*(int*)(pPacketInEax + 0xc) == *(int*)(nLocalTfidBase + 4))) &&
            (*(char*)(pPacketInEax + 0x10) == *(char*)(nLocalTfidBase + 8))) {
            Client_RefreshLocalCharacterLevelUi();
            // Primary character HUD widget at game+0x1034
            if (*(int*)((int)pGameClient + 0x1034) != 0) {
                bUiVisible =
                    (**(char (**)())(**(int**)((int)pGameClient + 0x1034) + 0x3d8))();
                if (bUiVisible != '\0') {
                    pObject = *(int**)((int)pGameClient + 0x1034);
                    (**(int (**)())(*pObject + 0x448))();
                    (**(int (**)())(*pObject + 0x34c))();
                }
            }
        }
    }

    // ----- 4-5) Mission windows + secondary HUD -----
    Client_RefreshOpenMissionUiWindows(pGameClient);
    if (*(int*)((int)pGameClient + 0x10b0) != 0) {
        bUiVisible =
            (**(char (**)())(**(int**)((int)pGameClient + 0x10b0) + 0x3d8))();
        if (bUiVisible != '\0') {
            FUN_008a05a0();
        }
    }
    return;
}
