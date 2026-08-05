// READABILITY (auto CF):
//  - Body size: ~167 non-empty decompiler lines.
//  - Control keywords: if×22, return×5, switch×1, goto×1.
//  - Notable callees: FUN_008801b0×2, FUN_009440e0×2, CONCAT31, Client_RecvInventoryEquip, FUN_004bafe0, FUN_004fe110, FUN_004fe620, FUN_004fe800.
//  - Strings: "Requesting InventoryEquip: char:%I64d Old:%I64d New:%I64d\n".
//  - Return sites: 5.

// =============================================================================
// Client_RecvInventoryEquip
// -----------------------------------------------------------------------------
// Purpose:  S2C InventoryEquip (opcode 0x203C, size 0x40). Resolve vehicle and
//           item; if the local player owns the vehicle, hand/cursor or cargo
//           pull then FUN_00502e90 vehicle equip + UI; otherwise non-local
//           hardpoint equip by object class (ornament, plant, weapon, wheelset,
//           armor).
//
// Address:  0x00813f40  (autoassault.exe, image base 0x400000)
// Stable:   aa_00813f40
// System:   inventory-transfer
//
// Convention: Packet on stack (dispatch PUSH ESI); client context in EAX
//             (decompiler `in_EAX`). Call site 0x0081597c:
//               PUSH ESI; MOV EAX,EBP; CALL 0x00813f40
//             Modeled here as explicit (pPacket, pClient /* in_EAX */).
//
// Packet layout (0x40) - Documentation/PACKET STRUCTURES.md:
//   +0x08  TFID item (new) — COID lo/hi
//   +0x10  u8   new-item global flag (also ResolveObjectTarget first arg)
//   +0x18  i64  vehicle TFID / id
//   +0x20  u8   vehicle global/realm byte (FUN_004bafe0)
//   +0x28  i64  oldItem TFID
//   +0x38  u8   putInHand (1 = hand/cursor path)
//   +0x39  u8   srcX
//   +0x3A  u8   srcY
//   +0x3B  u8   invTypeFrom
//
// Note: No client C2S 0x203C builder - equip is requested via Drop type
//       HARDPOINT=2. This handler applies the server result.
//
// Control flow summary:
//   1) Log Requesting InventoryEquip (vehicle / old / new TFIDs)
//   2) vehicle = FUN_004bafe0(realm@+0x20, id@+0x18/+0x1c)
//   3) null vehicle → resolve item TFID; optional FUN_009440e0 destroy; return
//   4) owner = vehicle+0xb0 → vfunc +0x1dc; if owner == client+0xe98:
//        LOCAL path:
//          putInHand@+0x38==1 → resolve item to hand/cursor
//          else cargo pull FUN_00571010 + FUN_00571b80 (unstamp footprint)
//          FUN_00502e90(vehicle, item) — full class equip dispatcher
//          UI refresh / cursor / place at srcX,srcY (FUN_00571620)
//          flags client+0x30b4/0x30b5; equip UI vcall; return
//   5) NON-LOCAL path:
//        resolve by globalFlag@+0x10 + TFID
//        switch clonebase class (+0x38): 6 / 10 / 0xc / 0x10 / 0x1c
//        if previous-out set → destroy old view; FUN_0092f120
//
// Hardpoint class switch (clonebase+0x38) — sealed strings 2026-07-29:
//   6     ornament (subtype 10) → FUN_004fe620 (vehicle +0x26c)
//   10    power plant → Vehicle_EquipPowerPlant
//   0xc   weapon: subtype 9 melee FUN_004fe800 (+0x264);
//         else FUN_004fe110 → Vehicle_AttachWeapon (+0x260)
//   0x10  wheelset → FUN_004ff510 → Vehicle_SetWheelset (+0x258)
//   0x1c  armor → FUN_00502180 → Vehicle_SetEquippedArmor (+0x254)
//
// Key offsets:
//   client+0xe98   local character*
//   client+0x1040  sheet UI host (+0x50c child)
//   client+0x1078 / +0x104c inventory UI refresh handles
//   client+0x309c  equip UI; +0x30b4/+0x30b5 dirty flags
//   vehicle+0xb0   linked owner object
//   vehicle+0x2b0  cargo-grid presence (local pull gate)
//   vehicle+0x254 / +0x258 / +0x260 / +0x264 / +0x26c hardpoint slots
//
// Related: Client_RecvInventoryUnequipNotify, Vehicle_EquipPowerPlant,
//          Vehicle_SetWheelset, FUN_00502e90 (local equip)
//          dispatched from Client_PacketDispatch case 0x203C @ 0x0081597c
// Exactness: CF mirrors raw; names/types cleaned; no invented clamps.
//            Bit-for-bit / runtime / diff: DEFERRED.
// Dual residual: 2026-07-29 sealed opcode/ABI + class map (incl. wheelset).
// Dual reviews:
//   reviews/A_aa_00813f40_Client_RecvInventoryEquip.md
//   reviews/B_aa_00813f40_Client_RecvInventoryEquip.md
// =============================================================================

#include <cstdint>

struct TFID_16 {
    std::uint32_t dwCoidLo;
    std::uint32_t dwCoidHi;
};

// RTTI symbols (Ghidra)
extern "C" void* CVOGClonedObjectBase_RTTI_Type_Descriptor;
extern "C" void* CVOGSimpleObject_CVOGGraphicsBase_RTTI_Type_Descriptor;

void         FUN_007a4480(std::uint32_t level, const char* fmt, ...);
void*        FUN_004bafe0(std::uint8_t realm, std::uint32_t idLo, std::uint32_t idHi);
void*        Object_ResolveFromTFID(TFID_16* tfid);
void         FUN_009440e0(void* obj, std::int32_t a, std::int32_t b,
                          std::uint32_t c, std::uint32_t d);
void*        CVOGReaction_ResolveObjectTarget(std::uint32_t a, std::uint32_t lo,
                                              std::uint32_t hi);
void*        FUN_00571010(std::uint32_t lo, std::uint32_t hi);
void         FUN_00571b80(void* item, std::int32_t a, std::int32_t b);
void*        FUN_00502e90(std::uint32_t a);
void         FUN_008c2940();
void         FUN_007fc150();
void         FUN_007fc270(std::uint8_t invType);
std::uint32_t FUN_00571620(void* itemOrGrid, std::uint8_t x, std::uint8_t y,
                           std::int32_t flag); // PlaceItemFootprint
void         FUN_008c3120();
void         FUN_008801b0(std::int32_t ui);
void         FUN_0092f120();
void         Vehicle_EquipPowerPlant(void* vehicle, void* plant, void** out,
                                     bool flag);
void         FUN_004fe620(std::uint32_t a, void* b, std::uint32_t c);
void         FUN_004fe800(void* a, void** b, std::int32_t c);
void         FUN_004fe110(void* a, std::uint32_t b, void* c);
void         FUN_004ff510(void* a, void** b, std::int32_t c);
void         FUN_00502180(std::int32_t a, void** b, std::int32_t c);
std::uint32_t __RTDynamicCast(void* obj, std::int32_t a, void* from, void* to,
                              std::int32_t b, void* c, std::int32_t d);

/// @param pPacket  S2C 0x203C body (0x40)
/// @param pClient  Client context (retail EAX / decompiler in_EAX)
void Client_RecvInventoryEquip(void* pPacket, std::int32_t pClient /* in_EAX */)
{
    void* packet = pPacket;
    auto* pkt = reinterpret_cast<std::uint8_t*>(packet);
    std::int32_t client = pClient;

    TFID_16* itemTfid = reinterpret_cast<TFID_16*>(pkt + 8);

    FUN_007a4480(
        0xFFFFFFFFu,
        "Requesting InventoryEquip: char:%I64d Old:%I64d New:%I64d\n",
        *reinterpret_cast<std::uint32_t*>(pkt + 0x18),
        *reinterpret_cast<std::uint32_t*>(pkt + 0x1c),
        *reinterpret_cast<std::uint32_t*>(pkt + 0x28),
        *reinterpret_cast<std::uint32_t*>(pkt + 0x2c),
        *reinterpret_cast<std::uint32_t*>(pkt + 8),
        *reinterpret_cast<std::uint32_t*>(pkt + 0xc));

    // Resolve vehicle from packet vehicle id
    void* vehicle = FUN_004bafe0(
        pkt[0x20],
        *reinterpret_cast<std::uint32_t*>(pkt + 0x18),
        *reinterpret_cast<std::uint32_t*>(pkt + 0x1c));

    void* scratch = vehicle; // decompiler reuses param_1 as scratch / previous-out

    if (vehicle == nullptr) {
        void* item = Object_ResolveFromTFID(itemTfid);
        if (item != nullptr) {
            FUN_009440e0(item, 1, 0, 0xFFFFFFFFu, 0xFFFFFFFFu);
            return;
        }
        // raw: fall through to final return when item also null
        return;
    }

    // Walk vehicle → linked object at +0xb0; vfunc +0x1dc → owner character
    std::int32_t link =
        *reinterpret_cast<std::int32_t*>(
            *reinterpret_cast<std::int32_t*>(
                reinterpret_cast<std::uint8_t*>(vehicle) + 4) + 4);
    std::int32_t* ownerObj = *reinterpret_cast<std::int32_t**>(
        link + 0xb0 + reinterpret_cast<std::uintptr_t>(vehicle));

    if (ownerObj == nullptr) {
        goto non_local_equip;
    }

    {
        using GetOwnerFn = std::uint64_t(__thiscall*)(void*);
        auto* ovt = *reinterpret_cast<void***>(ownerObj);
        std::uint64_t ownerPair = reinterpret_cast<GetOwnerFn>(
            *reinterpret_cast<void**>(
                reinterpret_cast<std::uint8_t*>(ovt) + 0x1dc))(ownerObj);
        std::int32_t ownerChar = static_cast<std::int32_t>(ownerPair);

        // Local player owns this vehicle?
        if (ownerChar == 0
            || ownerChar != *reinterpret_cast<std::int32_t*>(client + 0xe98)) {
            goto non_local_equip;
        }

        // --- Local equip path ---
        std::uint32_t handOrGridItem = 0;

        if (pkt[0x38] == 1) {
            // putInHand: resolve item into hand/cursor
            handOrGridItem = reinterpret_cast<std::uint32_t>(
                CVOGReaction_ResolveObjectTarget(
                    1, itemTfid->dwCoidLo,
                    *reinterpret_cast<std::uint32_t*>(pkt + 0xc)));
        } else if (*reinterpret_cast<std::int32_t*>(
                       reinterpret_cast<std::uint8_t*>(vehicle) + 0x2b0)
                   != 0) {
            // Pull from cargo grid
            handOrGridItem = reinterpret_cast<std::uint32_t>(
                FUN_00571010(itemTfid->dwCoidLo,
                             *reinterpret_cast<std::uint32_t*>(pkt + 0xc)));
            FUN_00571b80(reinterpret_cast<void*>(handOrGridItem), 1, 0);
        }

        // thiscall: ECX = vehicle (this), arg = item — full hardpoint equip
        scratch = FUN_00502e90(handOrGridItem);

        // Optional character-sheet UI callback
        std::int32_t* sheetUi = *reinterpret_cast<std::int32_t**>(
            *reinterpret_cast<std::int32_t*>(client + 0x1040) + 0x50c);
        if (sheetUi != nullptr) {
            char vis = (**(char(**)())(*sheetUi + 0x3d8))();
            if (vis != '\0') {
                FUN_008c2940();
            }
        }

        if (scratch == nullptr) {
            // No placeable result - clear cursor if putInHand + oldItem invalid
            if (pkt[0x38] == 1
                && ((*reinterpret_cast<std::uint32_t*>(pkt + 0x28)
                     & *reinterpret_cast<std::uint32_t*>(pkt + 0x2c))
                    == 0xFFFFFFFFu)) {
                FUN_007fc150();
            }
        } else if (pkt[0x38] == 1) {
            FUN_007fc270(pkt[0x3b]); // invTypeFrom → cursor/hand UI
        } else {
            // Place back into grid at srcX/srcY
            FUN_00571620(scratch, pkt[0x39], pkt[0x3a], 1);
            if (sheetUi != nullptr) {
                char vis = (**(char(**)())(*sheetUi + 0x3d8))();
                if (vis != '\0') {
                    FUN_008c3120();
                }
            }
        }

        // Refresh inventory UIs
        if (*reinterpret_cast<std::int32_t*>(client + 0x1078) != 0) {
            FUN_008801b0(*reinterpret_cast<std::int32_t*>(client + 0x1078));
        }
        if (*reinterpret_cast<std::int32_t*>(client + 0x104c) != 0) {
            FUN_008801b0(*reinterpret_cast<std::int32_t*>(client + 0x104c));
        }

        *reinterpret_cast<std::uint8_t*>(client + 0x30b4) = 1;
        *reinterpret_cast<std::uint8_t*>(client + 0x30b5) = 0;

        std::int32_t* equipUi =
            *reinterpret_cast<std::int32_t**>(client + 0x309c);
        if (equipUi == nullptr) {
            return;
        }
        (**(void(**)(std::int32_t))(*equipUi + 4))(0);
        return;
    }

non_local_equip:
    // Resolve item by type-hint@+0x10 + TFID; switch on object class
    {
        std::int32_t* item = reinterpret_cast<std::int32_t*>(
            CVOGReaction_ResolveObjectTarget(
                pkt[0x10], itemTfid->dwCoidLo,
                *reinterpret_cast<std::uint32_t*>(pkt + 0xc)));

        if (item == nullptr) {
            return;
        }

        std::uint32_t objClass =
            *reinterpret_cast<std::uint32_t*>(item[0x2a] + 0x38);

        switch (objClass) {
        case 6: {
            // Ornament: subtype 10 → FUN_004fe620 (vehicle +0x26c)
            if (*reinterpret_cast<std::int16_t*>(
                    *reinterpret_cast<std::int32_t*>(item[0x2a] + 0x3c) + 0x3f4)
                != 10) {
                return;
            }
            scratch = nullptr;
            std::uint32_t casted = __RTDynamicCast(
                item, 0,
                &CVOGClonedObjectBase_RTTI_Type_Descriptor,
                &CVOGSimpleObject_CVOGGraphicsBase_RTTI_Type_Descriptor,
                0, &scratch, 0);
            FUN_004fe620(casted, &scratch, 0);
            break;
        }
        case 10: {
            // Power plant - vfunc +0x1f4 (decimal 500 in raw)
            void* plant =
                (**(void*(**)())(*item + 500))();
            scratch = nullptr;
            // Scale / show graphics if present
            {
                std::int32_t gfxHost =
                    *reinterpret_cast<std::int32_t*>(
                        *reinterpret_cast<std::int32_t*>(
                            *reinterpret_cast<std::int32_t*>(
                                reinterpret_cast<std::uint8_t*>(plant) + 4)
                            + 4)
                        + 4
                        + reinterpret_cast<std::uintptr_t>(plant));
                std::int32_t gfx =
                    (**(std::int32_t(**)())(gfxHost + 0x1cc))();
                if (*reinterpret_cast<std::int32_t*>(gfx + 8) != 0) {
                    std::int32_t nested =
                        *reinterpret_cast<std::int32_t*>(
                            *reinterpret_cast<std::int32_t*>(
                                *reinterpret_cast<std::int32_t*>(gfx + 4) + 4)
                            + 4 + gfx);
                    (**(void(**)(std::uint32_t))(nested + 0xb8))(0x3f800000u);
                    (**(void(**)(std::int32_t))(
                        **reinterpret_cast<std::int32_t**>(gfx + 8) + 0x10))(3);
                }
            }
            Vehicle_EquipPowerPlant(vehicle, plant, &scratch, false);
            break;
        }
        case 0xc: {
            // Weapon via vfunc +0x1e0: subtype 9 melee (+0x264) else AttachWeapon
            item = reinterpret_cast<std::int32_t*>(
                (**(void*(**)())(*item + 0x1e0))());
            scratch = nullptr;
            {
                std::int32_t gfx =
                    (**(std::int32_t(**)())(
                        *reinterpret_cast<std::int32_t*>(
                            *reinterpret_cast<std::int32_t*>(item[1] + 4)
                            + 4 + reinterpret_cast<std::uintptr_t>(item))
                        + 0x1cc))();
                if (*reinterpret_cast<std::int32_t*>(gfx + 8) != 0) {
                    std::int32_t nested =
                        *reinterpret_cast<std::int32_t*>(
                            *reinterpret_cast<std::int32_t*>(
                                *reinterpret_cast<std::int32_t*>(gfx + 4) + 4)
                            + 4 + gfx);
                    (**(void(**)(std::uint32_t))(nested + 0xb8))(0x3f800000u);
                    (**(void(**)(std::int32_t))(
                        **reinterpret_cast<std::int32_t**>(gfx + 8) + 0x10))(3);
                }
            }
            if (*reinterpret_cast<std::int16_t*>(
                    *reinterpret_cast<std::int32_t*>(
                        *reinterpret_cast<std::int32_t*>(
                            *reinterpret_cast<std::int32_t*>(item[1] + 4)
                            + 0xac + reinterpret_cast<std::uintptr_t>(item))
                        + 0x3c)
                    + 0x3f4)
                == 9) {
                FUN_004fe800(item, reinterpret_cast<void**>(&scratch), 0);
                (**(void(**)(std::int32_t))(*item + 0x18))(1);
            } else {
                void** out = reinterpret_cast<void**>(&scratch);
                std::uint32_t r =
                    (**(std::uint32_t(**)(void**))(*item + 0x60))(out);
                FUN_004fe110(item, r, out);
                (**(void(**)(std::int32_t))(*item + 0x18))(1);
            }
            break;
        }
        case 0x10: {
            // Wheelset → FUN_004ff510 → Vehicle_SetWheelset (vehicle +0x258)
            item = reinterpret_cast<std::int32_t*>(
                (**(void*(**)())(*item + 0x1f0))());
            scratch = nullptr;
            {
                std::int32_t gfx =
                    (**(std::int32_t(**)())(
                        *reinterpret_cast<std::int32_t*>(
                            *reinterpret_cast<std::int32_t*>(item[1] + 4)
                            + 4 + reinterpret_cast<std::uintptr_t>(item))
                        + 0x1cc))();
                if (*reinterpret_cast<std::int32_t*>(gfx + 8) != 0) {
                    std::int32_t nested =
                        *reinterpret_cast<std::int32_t*>(
                            *reinterpret_cast<std::int32_t*>(
                                *reinterpret_cast<std::int32_t*>(gfx + 4) + 4)
                            + 4 + gfx);
                    (**(void(**)(std::uint32_t))(nested + 0xb8))(0x3f800000u);
                    (**(void(**)(std::int32_t))(
                        **reinterpret_cast<std::int32_t**>(gfx + 8) + 0x10))(3);
                }
            }
            FUN_004ff510(item, reinterpret_cast<void**>(&scratch), 0);
            (**(void(**)(std::int32_t))(*item + 0x18))(1);
            break;
        }
        case 0x1c: {
            // Armor → FUN_00502180 → Vehicle_SetEquippedArmor (+0x254)
            std::int32_t sub =
                (**(std::int32_t(**)())(*item + 0x1f8))();
            scratch = nullptr;
            {
                std::int32_t gfx =
                    (**(std::int32_t(**)())(
                        *reinterpret_cast<std::int32_t*>(
                            *reinterpret_cast<std::int32_t*>(
                                *reinterpret_cast<std::int32_t*>(sub + 4) + 4)
                            + 4 + sub)
                        + 0x1cc))();
                if (*reinterpret_cast<std::int32_t*>(gfx + 8) != 0) {
                    std::int32_t nested =
                        *reinterpret_cast<std::int32_t*>(
                            *reinterpret_cast<std::int32_t*>(
                                *reinterpret_cast<std::int32_t*>(gfx + 4) + 4)
                            + 4 + gfx);
                    (**(void(**)(std::uint32_t))(nested + 0xb8))(0x3f800000u);
                    (**(void(**)(std::int32_t))(
                        **reinterpret_cast<std::int32_t**>(gfx + 8) + 0x10))(3);
                }
            }
            FUN_00502180(sub, reinterpret_cast<void**>(&scratch), 0);
            break;
        }
        default:
            return; // switchD case 7+ fallthrough return
        }

        // Destroy visual for replaced/old attachment if scratch set
        if (scratch != nullptr) {
            std::int32_t oldView =
                *reinterpret_cast<std::int32_t*>(
                    *reinterpret_cast<std::int32_t*>(
                        reinterpret_cast<std::uint8_t*>(scratch) + 4)
                    + 4)
                + 4
                + reinterpret_cast<std::uintptr_t>(scratch);
            FUN_009440e0(reinterpret_cast<void*>(oldView), 1, 0, 0xFFFFFFFFu,
                         0xFFFFFFFFu);
        }

        FUN_0092f120();
    }
}
