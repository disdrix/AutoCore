// =============================================================================
// Client_ItemMatchesActiveHardpointMode_Inferred  (was FUN_00862860)
// -----------------------------------------------------------------------------
// Stable ID: aa_00862860
// Address:   0x00862860  (autoassault.exe, image base 0x400000)
// Body:      0x00862860–0x008629a1 (322 bytes)
// System:    inventory-transfer / hardpoint equip UI
//
// ABI (call-site Confirmed):
//   ECX = item*   (null → false)
//   ESI = uiHost* with vtbl+0x3cc → active hardpoint/equip mode (int)
//   returns bool in AL
//
// CloneBase class at *(item+0xA8)+0x38 — same set as Client_RecvInventoryEquip:
//   6 ornament, 10 plant, 0x0C weapon, 0x0E town-gated class, 0x10 wheelset, 0x1C armor
//
// Jump table @ 0x008629a4 + byte map @ 0x008629c0 (class-6 index).
// Name INFERRED — role from drop/click callers + class map; no product string in body.
// Dual: reviews/A|B_aa_00862860_Client_ItemMatchesActiveHardpointMode_Inferred.md
// Exactness: CF mirrors decompile + table; not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" int FUN_0040da70(void* after_item_vfunc /*ECX into callee*/);

// Modeled with explicit args; retail binds ECX/ESI.
bool Client_ItemMatchesActiveHardpointMode_Inferred(int* item, int* uiHost)
{
    if (item == nullptr) {
        return false;
    }

    int* cloneBase = reinterpret_cast<int*>(item[0x2a]); // +0xA8
    const int cls = *reinterpret_cast<int*>(reinterpret_cast<char*>(cloneBase) + 0x38);

    auto getMode = [&]() -> int {
        return (**(int(**)())(*uiHost + 0x3cc))();
    };

    switch (cls) {
    case 6: {
        // ornament / race cosmetic subtypes at *(cb+0x3c)+0x3f4
        const short sub = *reinterpret_cast<short*>(
            *reinterpret_cast<int*>(reinterpret_cast<char*>(cloneBase) + 0x3c) + 0x3f4);
        if (sub == 10) {
            return getMode() == 9;
        }
        if (sub == 0xb) {
            return getMode() == 8;
        }
        break;
    }
    case 10: // power plant
        return getMode() == 1;
    case 0xc: { // weapon
        (**(void(**)())(*item + 0x1e0))();
        int nested = FUN_0040da70(); // uses ECX from prior vfunc return path
        if (*reinterpret_cast<char*>(nested + 0x3f4) == 9) {
            return getMode() == 7; // melee family
        }
        const std::uint8_t flags = *reinterpret_cast<std::uint8_t*>(nested + 0x536);
        if ((flags & 2) != 0) {
            return getMode() == 4;
        }
        if ((flags & 0x10) != 0) {
            return getMode() == 5;
        }
        if ((flags & 4) != 0) {
            return getMode() == 6;
        }
        break;
    }
    case 0xe:
        return getMode() == 0xd;
    case 0x10: // wheelset
        return getMode() == 2;
    case 0x1c: // armor
        return getMode() == 3;
    default:
        break;
    }
    return false;
}
