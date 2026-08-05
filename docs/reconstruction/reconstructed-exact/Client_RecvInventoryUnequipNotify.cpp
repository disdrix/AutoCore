// READABILITY (auto CF):
//  - Body size: ~145 non-empty decompiler lines.
//  - Control keywords: if×12, return×9, goto×5, switch×2.
//  - Notable callees: CONCAT31×4, FUN_007a4480×2, FUN_009440e0×2, Object_ResolveFromTFID×2, Client_RecvInventoryUnequipNotify, Client_RefreshOpenMissionUiWindows, FUN_004bafe0, FUN_004fe110.
//  - Strings: "Requesting InventoryUnequip: char:%I64d Old:%I64d\n"; "This equipment cannot be changed at this time."; "VOG_DEBUG_STOP".
//  - Return sites: 9.

// =============================================================================
// Client_RecvInventoryUnequipNotify
// -----------------------------------------------------------------------------
// Purpose:  S2C InventoryUnequip notify (opcode 0x203E, size 0x30): item@+8,
//           vehicle@+0x18, destX@+0x28, destY@+0x29, invType@+0x2A. Distinct
//           from C2S Client_SendInventoryUnequip (same opcode, bidirectional).
//
// Address:  0x00813bf0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00813bf0
// System:   inventory-transfer
//
// Convention: Decompiler __fastcall shell - param_1 = client, packet in EAX.
//             Modeled as (pClient, pPacket) for readability.
//
// Bidirectional demux (sealed dual residual 2026-07-29):
//   S2C: Client_PacketDispatch case 0x203e → this function
//   C2S: Client_SendInventoryUnequip builds 0x30 + SendSectorPacket
//   No content-based demux; C2S omits vehicle@+0x18 / invType@+0x2A fill.
//
// Packet layout (0x30):
//   +0x08  TFID item
//   +0x10  u8   type hint (non-local path)
//   +0x18  i64  vehicle id
//   +0x20  u8   vehicle realm byte
//   +0x28  u8   destX
//   +0x29  u8   destY
//   +0x2A  u8   invType (0 none, 1 cargo, 2 hardpoint UI, 3 locker, …)
//
// Local path invType switch:
//   0  no grid place
//   1  cargo via char+0x250 → +0x2b0, PlaceItemFootprint
//   2  FUN_0093d6e0(client, 1) UI path
//   3  locker via char+0xcbc, PlaceItemFootprint
//   fail place → toast "This equipment cannot be changed at this time."
//
// Non-local hardpoint clear (clonebase+0x38) — sealed residual:
//   6  + subtype 10 → FUN_004fe620 null  (ornament +0x26c)
//   10 → Vehicle_EquipPowerPlant(vehicle, null, …)  (+0x268)
//   0xc + subtype 9 → FUN_004fe800 null  (melee +0x264)
//   0xc else → FUN_004fe110 null slot   (weapon +0x260[i])
//   0x10 → FUN_004ff510 null            (wheelset +0x258)
//   0x1c → FUN_00502180 null            (armor +0x254)
//   RaceItem (+0x270, type6/sub 0xb) NOT in this switch.
//
// Control flow summary:
//   1) Log unequip; vehicle = FUN_004bafe0(realm@+0x20, id@+0x18)
//   2) null vehicle → optional item destroy; return
//   3) if local owner (vehicle owner == client+0xe98):
//        invType switch → place into cargo/locker or UI helper; toast on fail
//   4) else non-local: resolve item by type-hint; clear equip class switch
//   5) mission UI / equip UI refresh helpers
//
// Exactness: CF mirrors raw. Bit-for-bit / runtime / diff: DEFERRED.
// Dual residual: reviews/a_00813bf0.md (demux + class map sealed 2026-07-29).
// =============================================================================

#include <cstdint>

struct TFID_16 {
    std::uint32_t dwCoidLo;
    std::uint32_t dwCoidHi;
};

void  FUN_007a4480(std::uint32_t level, const char* fmt, ...);
void* FUN_004bafe0(std::uint8_t realm, std::uint32_t idLo, std::uint32_t idHi);
void* Object_ResolveFromTFID(TFID_16* tfid);
void  FUN_009440e0(std::int32_t obj, std::int32_t a, std::int32_t b,
                   std::uint32_t c, std::uint32_t d);
std::uint64_t FUN_00504f60(void* obj);
void  FUN_0093d6e0(std::int32_t client, std::int32_t a);
char  FUN_00571620(int* item, std::uint32_t x, std::uint32_t y, std::int32_t flag);
void  FUN_007a69d0();
std::uint32_t FUN_007a6de0(const char* msg, std::uint32_t a);
void  FUN_007fdfb0(std::int32_t client, std::uint32_t a, std::uint32_t b,
                   std::uint32_t c, std::uint32_t d);
void  Client_RefreshOpenMissionUiWindows(std::int32_t client);
void  FUN_008801b0(int* ui);
void* CVOGReaction_ResolveObjectTarget(std::uint32_t hint, std::uint32_t lo,
                                       std::uint32_t hi);
void  FUN_004fe620(std::int32_t a, void* b, std::int32_t c);
void  Vehicle_EquipPowerPlant(void* vehicle, void* plant, void** out, bool keep);
void  FUN_004fe800(std::int32_t a, std::int32_t b, std::int32_t c);
void  FUN_004fe110(std::int32_t a, std::uint32_t b, void* c);
void  FUN_004ff510(std::int32_t a, void* b, std::int32_t c);
void  FUN_00502180(std::int32_t a, void* b, std::int32_t c);
void  FUN_0092f120();

// CONCAT31 helper matching decompiler (high 24 bits of a | low byte of b)
static inline std::uint32_t CONCAT31(std::uint32_t hi24, std::uint8_t lo)
{
    return (hi24 & 0xFFFFFF00u) | lo;
}

/// @param pClient  Client context (decompiler param_1)
/// @param pPacket  S2C 0x203E body in retail EAX
void Client_RecvInventoryUnequipNotify(std::int32_t pClient, std::int32_t pPacket /* in_EAX */)
{
    TFID_16* pTfid;
    char cVar1;
    void* pvVar2;
    unsigned uVar3;
    std::uint32_t uVar4;
    int* piVar5;
    void* pvVar6;
    int iVar7;
    int iVar8;
    std::uint32_t extraout_EDX = 0; // decompiler residue
    std::uint64_t uVar9;
    std::uint32_t uVar10;
    std::uint32_t uVar11;
    std::uint8_t* puVar12;
    std::uint32_t uVar13;

    // Raw: packet pointer is in_EAX
    std::int32_t in_EAX = pPacket;
    std::int32_t param_1 = pClient;

    pTfid = reinterpret_cast<TFID_16*>(in_EAX + 8);
    FUN_007a4480(
        0xFFFFFFFFu,
        "Requesting InventoryUnequip: char:%I64d Old:%I64d\n",
        *reinterpret_cast<std::uint32_t*>(in_EAX + 0x18),
        *reinterpret_cast<std::uint32_t*>(in_EAX + 0x1c),
        pTfid->dwCoidLo,
        *reinterpret_cast<std::uint32_t*>(in_EAX + 0xc));

    pvVar2 = FUN_004bafe0(
        *reinterpret_cast<std::uint8_t*>(in_EAX + 0x20),
        *reinterpret_cast<std::uint32_t*>(in_EAX + 0x18),
        *reinterpret_cast<std::uint32_t*>(in_EAX + 0x1c));

    if (pvVar2 == nullptr) {
        pvVar2 = Object_ResolveFromTFID(pTfid);
        if (pvVar2 == nullptr) {
            return;
        }
        FUN_009440e0(
            reinterpret_cast<std::int32_t>(pvVar2), 1, 0, 0xFFFFFFFFu, 0xFFFFFFFFu);
        return;
    }

    iVar7 = *reinterpret_cast<int*>(reinterpret_cast<std::uintptr_t>(pvVar2) + 4);
    piVar5 = *reinterpret_cast<int**>(
        *reinterpret_cast<int*>(iVar7 + 4) + 0xb0
        + reinterpret_cast<std::uintptr_t>(pvVar2));

    if (piVar5 != nullptr) {
        uVar9 = (**(std::uint64_t(**)())(*piVar5 + 0x1dc))();
        iVar7 = static_cast<int>(uVar9 >> 32);
        if ((static_cast<int>(uVar9) == 0)
            || (static_cast<int>(uVar9)
                != *reinterpret_cast<int*>(param_1 + 0xe98))) {
            goto LAB_00813d95;
        }

        // --- Local unequip path ---
        pvVar2 = Object_ResolveFromTFID(pTfid);
        uVar9 = FUN_00504f60(pvVar2);
        uVar4 = static_cast<std::uint32_t>(uVar9 >> 32);
        piVar5 = reinterpret_cast<int*>(static_cast<std::uintptr_t>(uVar9));
        if (piVar5 != nullptr) {
            (**(void(**)(std::uint32_t))(*piVar5 + 0x2ac))(
                *reinterpret_cast<std::uint32_t*>(param_1 + 0xd34));
            uVar4 = extraout_EDX;
        }

        iVar7 = static_cast<int>(
            CONCAT31(uVar4 >> 8, *reinterpret_cast<std::uint8_t*>(in_EAX + 0x2a)));
        uVar3 = *reinterpret_cast<std::uint8_t*>(in_EAX + 0x2a);

        switch (uVar3) {
        case 0:
            break;
        case 1:
            iVar7 = *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(param_1 + 0xe98) + 0x250);
            iVar8 = *reinterpret_cast<int*>(iVar7 + 0x2b0);
            goto LAB_00813cff;
        case 2:
            FUN_0093d6e0(param_1, 1);
            break;
        case 3:
            uVar3 = *reinterpret_cast<unsigned*>(param_1 + 0xe98);
            iVar8 = *reinterpret_cast<int*>(uVar3 + 0xcbc);
        LAB_00813cff:
            if ((iVar8 != 0)
                && (cVar1 = FUN_00571620(
                                  piVar5,
                                  CONCAT31(uVar3 >> 8,
                                           *reinterpret_cast<std::uint8_t*>(in_EAX + 0x28)),
                                  CONCAT31(static_cast<unsigned>(iVar7) >> 8,
                                           *reinterpret_cast<std::uint8_t*>(in_EAX + 0x29)),
                                  1),
                    cVar1 == '\0')) {
                FUN_007a69d0();
                uVar13 = 0;
                uVar11 = 1;
                uVar10 = 0xFFFFFFFFu;
                uVar4 = FUN_007a6de0(
                    "This equipment cannot be changed at this time.", 0xFFFFFFFFu);
                FUN_007fdfb0(param_1, uVar4, uVar10, uVar11, uVar13);
                return;
            }
            break;
        default:
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }

        Client_RefreshOpenMissionUiWindows(param_1);
        piVar5 = *reinterpret_cast<int**>(param_1 + 0x1078);
        if (piVar5 == nullptr) {
            return;
        }
        FUN_008801b0(piVar5);
        (**(void(**)())(*piVar5 + 0x34c))();
        return;
    }

LAB_00813d95:
    // --- Non-local / other-player path ---
    piVar5 = reinterpret_cast<int*>(CVOGReaction_ResolveObjectTarget(
        CONCAT31(static_cast<unsigned>(iVar7) >> 8,
                 *reinterpret_cast<std::uint8_t*>(in_EAX + 0x10)),
        pTfid->dwCoidLo,
        *reinterpret_cast<std::uint32_t*>(in_EAX + 0xc)));
    if (piVar5 == nullptr) {
        return;
    }
    (**(void(**)(std::int32_t))(*piVar5 + 0x104))(0);

    switch (*reinterpret_cast<std::uint32_t*>(piVar5[0x2a] + 0x38)) {
    case 6:
        if (*reinterpret_cast<std::int16_t*>(
                *reinterpret_cast<int*>(piVar5[0x2a] + 0x3c) + 0x3f4)
            != 10) {
            return;
        }
        piVar5 = nullptr;
        // raw uses &stack0xfffffff8 as previous-out scratch
        FUN_004fe620(0, &puVar12, 0);
        break;
    default:
        return;
    case 10:
        pvVar6 = (**(void*(**)())(*piVar5 + 500))();
        Vehicle_EquipPowerPlant(pvVar2, nullptr, reinterpret_cast<void**>(&puVar12), false);
        goto LAB_00813e97;
    case 0xc:
        piVar5 = reinterpret_cast<int*>((**(void*(**)())(*piVar5 + 0x1e0))());
        if (*reinterpret_cast<std::int16_t*>(
                *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(piVar5[1] + 4) + 0xac
                        + reinterpret_cast<std::uintptr_t>(piVar5))
                    + 0x3c)
                + 0x3f4)
            == 9) {
            FUN_004fe800(0, 0, 0);
        } else {
            puVar12 = reinterpret_cast<std::uint8_t*>(&puVar12);
            uVar4 = (**(std::uint32_t(**)(void*))(*piVar5 + 0x60))(&puVar12);
            FUN_004fe110(0, uVar4, puVar12);
        }
        break;
    case 0x10:
        piVar5 = reinterpret_cast<int*>((**(void*(**)())(*piVar5 + 0x1f0))());
        FUN_004ff510(0, &puVar12, 0);
        break;
    case 0x1c:
        pvVar6 = (**(void*(**)())(*piVar5 + 0x1f8))();
        FUN_00502180(0, &puVar12, 0);
    LAB_00813e97:
        if (pvVar6 == nullptr) {
            goto LAB_00813ef0;
        }
        iVar7 = *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(
                        reinterpret_cast<std::uintptr_t>(pvVar6) + 4)
                    + 4)
                + 4 + reinterpret_cast<std::uintptr_t>(pvVar6);
        goto LAB_00813ee2;
    }

    if (piVar5 != nullptr) {
        iVar7 = *reinterpret_cast<int*>(piVar5[1] + 4) + 4
                + reinterpret_cast<std::uintptr_t>(piVar5);
    LAB_00813ee2:
        FUN_009440e0(iVar7, 1, 0, 0xFFFFFFFFu, 0xFFFFFFFFu);
    }

LAB_00813ef0:
    FUN_0092f120();
}
