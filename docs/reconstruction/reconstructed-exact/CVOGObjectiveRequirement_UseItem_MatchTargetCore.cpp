// =============================================================================
// CVOGObjectiveRequirement_UseItem_MatchTargetCore  (was FUN_0060d460)
// -----------------------------------------------------------------------------
// Address:  0x0060d460  (autoassault.exe, image base 0x400000)
// Stable:   aa_0060d460
// Systems:  missions-progression (UseItem objective MatchTarget helper)
//
// Purpose: Shared match implementation behind
//          CVOGObjectiveRequirement_UseItem_MatchTarget (vtable +0x38 trampoline
//          @ 0x0060d7f0). Returns 1 if the world/object target satisfies this
//          UseItem requirement's identity + inventory + optional field gates.
//
// Exactness: Ghidra decompile + read_memory 220 B @ entry (2026-07-29).
//            Duals A/B. ret 0x08. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// InventoryGrid_FindItemByCoid @ 0x00571010 — ECX = grid; stack coidLo, coidHi; ret 8
extern int* __thiscall InventoryGrid_FindItemByCoid(void* grid, int coidLo, int coidHi);

// InventoryGrid_FindItemByCbid @ 0x005710c0 — ECX = grid; stack cbid, skipGate, addQty; ret 0xC
extern int* __thiscall InventoryGrid_FindItemByCbid(
    void* grid, int itemCbid, char skipStackGate, unsigned short addQty);

// thiscall: ECX = UseItem requirement*
// stack:   character*, targetObject*
// ret 0x08
// returns: 1 = match, 0 = no match (AL)
std::uint8_t __thiscall CVOGObjectiveRequirement_UseItem_MatchTargetCore(
    void* req,
    void* character,
    void* target)
{
    if (character == nullptr || target == nullptr) {
        return 0;
    }

    auto* r = reinterpret_cast<std::uint8_t*>(req);
    auto* ch = reinterpret_cast<std::uint8_t*>(character);
    auto* obj = reinterpret_cast<std::uint8_t*>(target);

    const std::uint32_t reqCoidLo = *reinterpret_cast<std::uint32_t*>(r + 0x10);
    const std::uint32_t reqCoidHi = *reinterpret_cast<std::uint32_t*>(r + 0x14);
    const int reqPrimaryCbid = *reinterpret_cast<int*>(r + 0x18);

    // Identity: instance COID pair OR primary CBID (clonebase+0x34).
    // COID path enabled only when (req+0x10 & req+0x14) != 0xFFFFFFFF
    // (both all-ones → no instance filter).
    bool identityOk = false;
    if ((reqCoidLo & reqCoidHi) != 0xFFFFFFFFu) {
        const std::uint32_t objCoidLo = *reinterpret_cast<std::uint32_t*>(obj + 0x160);
        const std::uint32_t objCoidHi = *reinterpret_cast<std::uint32_t*>(obj + 0x164);
        if (objCoidLo == reqCoidLo && objCoidHi == reqCoidHi) {
            identityOk = true;
        }
    }
    if (!identityOk) {
        if (reqPrimaryCbid == -1) {
            return 0;
        }
        void* clonebase = *reinterpret_cast<void**>(obj + 0xA8);
        if (clonebase == nullptr
            || *reinterpret_cast<int*>(reinterpret_cast<std::uint8_t*>(clonebase) + 0x34)
                   != reqPrimaryCbid) {
            return 0;
        }
        identityOk = true;
    }
    if (!identityOk) {
        return 0;
    }

    // Inventory path: character+0x250 → manager; manager+0x2B0 → InventoryGrid*
    void* invMgr = *reinterpret_cast<void**>(ch + 0x250);
    if (invMgr == nullptr) {
        return 0;
    }
    void* grid = *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(invMgr) + 0x2B0);
    if (grid == nullptr) {
        return 0;
    }

    const int objCoidLo = *reinterpret_cast<int*>(obj + 0x160);
    const int objCoidHi = *reinterpret_cast<int*>(obj + 0x164);
    int* foundByCoid = InventoryGrid_FindItemByCoid(grid, objCoidLo, objCoidHi);

    // req+0x1D: invert presence — 0 => must be in cargo; 1 => must NOT be in cargo
    const bool wantAbsent = (*reinterpret_cast<char*>(r + 0x1D) != 0);
    const bool isAbsent = (foundByCoid == nullptr);
    if (isAbsent != wantAbsent) {
        return 0;
    }

    // Optional secondary CBID gate (req+0x2C); -1 = skip. FindByCbid(cbid, 0, 0).
    const int secondaryCbid = *reinterpret_cast<int*>(r + 0x2C);
    if (secondaryCbid != -1) {
        int* foundByCbid = InventoryGrid_FindItemByCbid(grid, secondaryCbid, 0, 0);
        if (foundByCbid == nullptr) {
            return 0;
        }
    }

    // Optional field gate: req+0x54 < 1 → pass; else must equal character
    // clonebase+0xFC via MI this-adjust: *( *(ch+4)+4 + ch + 0xA8 ) → +0xFC.
    const int fieldGate = *reinterpret_cast<int*>(r + 0x54);
    if (fieldGate >= 1) {
        void* vadj = *reinterpret_cast<void**>(ch + 4);
        int adj = *reinterpret_cast<int*>(reinterpret_cast<std::uint8_t*>(vadj) + 4);
        void* chClone = *reinterpret_cast<void**>(
            reinterpret_cast<std::uint8_t*>(ch) + adj + 0xA8);
        const int chField = *reinterpret_cast<int*>(
            reinterpret_cast<std::uint8_t*>(chClone) + 0xFC);
        if (fieldGate != chField) {
            return 0;
        }
    }

    return 1;
}
