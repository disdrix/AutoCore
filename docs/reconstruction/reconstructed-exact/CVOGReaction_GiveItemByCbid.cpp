// READABILITY (auto CF):
//  - Body size: ~305 non-empty decompiler lines.
//  - Control keywords: if×48, return×47, goto×9, for×1, switch×1.
//  - Notable callees: FUN_005c7f30×3, FUN_0051e7d0×2, FUN_00609620×2, item×2, Ammo, Armor, Blueprint, CVOGReaction_GiveItemByCbid.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 47.

// =============================================================================
// CVOGReaction_GiveItemByCbid
// -----------------------------------------------------------------------------
// Purpose:  Factory - look up a clonebase by CBID and construct the matching
//           inventory item runtime object; return dual-base simple-object ptr.
//
// Address:  0x0051a170  (autoassault.exe, image base 0x400000)
// Stable:   aa_0051a170
// System:   inventory-transfer
//
// Convention: MSVC __cdecl
//   nCbidOrParams  CBID / creation key passed to FUN_00404d70
//                  (0 is a special case for types 0x1A and 0x20)
//
// Returns:  item simple-object base pointer, or 0 on failure.
//           Most paths:  item + *( *(item+4) + 4 ) + 4   (dual-base adjust)
//           Blueprint (0x20): item + *( *item + 4 )       (slightly different)
//           Key/Salvage/Token: return ctor result raw
//
// Type switch is on itemDef+0x38 (CloneBase type id). operator_new sizes and
// per-type ctors are preserved exactly; pvVar4 is often unused by the ctor
// call (decompiler surface - allocation may be side-effect / placement).
//
// Exactness: Behavior-preserving rewrite of raw decompile control flow.
// =============================================================================

#include <cstdint>
#include <new>

void* operator_new(std::uint32_t size);
void  FUN_007a4480(int level, const char* fmt, ...);

// CloneBase lookup by CBID (INFERRED)
int   FUN_00404d70(int nCbid);

// Per-type constructors (placement / factory; arg 1 = flags INFERRED)
int   FUN_005c7f30(int);   // weapon / currency / ammo
int   FUN_005c82a0(int);   // armor
int   FUN_0051ef40(int);   // module
int   FUN_006092a0(int);   // container
int   FUN_00609620(int);   // vehicle item
int   FUN_004f1e20(int, int);
int   FUN_005ff780(int);   // special subtype 9
int   FUN_005ff910(int);   // special subtype 0x11
int   FUN_0056e730(int);   // special default
int   FUN_00501970(int);   // mount
int   FUN_005a84f0(int);   // pet
int   FUN_004c9aa0(int);   // consumable
int   FUN_00536920(int);   // mission item
int   FUN_00588dc0(int);   // crafting material
int   FUN_005fe7a0(int);   // quest item
int   FUN_00605940(int);   // trade good
int*  FUN_0051e7d0(int);   // blueprint
int   FUN_00577df0(int);   // upgrade
int   FUN_00575440();      // key
int   FUN_00608fb0(int);   // data chip
int   FUN_00566c10(int);   // repair kit
int   FUN_005dbfa0(int);   // paint
int   FUN_0057b0e0();      // salvage
int   FUN_006054a0(int);   // resource
int   FUN_005dfe20();      // token
int   FUN_0051ea10(int);   // component
int   FUN_00607f90(int);   // misc

// Dual-base adjust used by most item types
static inline int DualBaseSimpleObject(int pItem)
{
    return *reinterpret_cast<int*>(
               *reinterpret_cast<int*>(pItem + 4) + 4) +
           4 + pItem;
}

int __cdecl CVOGReaction_GiveItemByCbid(int nCbid)
{
    char  cSpecialSub;
    int   pItemOrCtor;
    int*  piBlueprint;
    void* pAlloc;

    int pItemDef = FUN_00404d70(nCbid);
    if (pItemDef == 0) {
        return 0;
    }

    const int nType = *reinterpret_cast<int*>(pItemDef + 0x38);

    switch (nType) {
    case 1: // Weapon
        pAlloc = operator_new(0x250);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_005c7f30(1);
        if (pItemOrCtor == 0) return 0;
        return DualBaseSimpleObject(pItemOrCtor);

    case 3: // Armor
        pAlloc = operator_new(0x2a0);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_005c82a0(1);
        if (pItemOrCtor == 0) return 0;
        return DualBaseSimpleObject(pItemOrCtor);

    case 4: // Module
        pAlloc = operator_new(0x2a0);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_0051ef40(1);
        if (pItemOrCtor == 0) return 0;
        return DualBaseSimpleObject(pItemOrCtor);

    case 6: // Currency
        pAlloc = operator_new(0x250);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_005c7f30(1);
        break;

    case 8: // Container
        pAlloc = operator_new(0x260);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_006092a0(1);
        break;

    case 10: // Vehicle (both nCbid branches identical)
        pAlloc = operator_new(0x270);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_00609620(1);
        if (pItemOrCtor == 0) return 0;
        return DualBaseSimpleObject(pItemOrCtor);

    case 0x0C: { // Special - subtype at clonebase+0x3C → +0x3F4
        if (*reinterpret_cast<int*>(pItemDef + 0x3C) == 0) {
            FUN_004f1e20(1, 1);
        }
        cSpecialSub = *reinterpret_cast<char*>(
            *reinterpret_cast<int*>(pItemDef + 0x3C) + 0x3F4);
        if (cSpecialSub == '\t') {
            pAlloc = operator_new(0x2e0);
            if (pAlloc == nullptr) {
                pItemOrCtor = 0;
            } else {
                pItemOrCtor = FUN_005ff780(1);
            }
        } else if (cSpecialSub == '\x11') {
            pAlloc = operator_new(0x2e0);
            if (pAlloc == nullptr) {
                pItemOrCtor = 0;
            } else {
                pItemOrCtor = FUN_005ff910(1);
            }
        } else {
            pAlloc = operator_new(0x2e0);
            if (pAlloc == nullptr) {
                pItemOrCtor = 0;
            } else {
                pItemOrCtor = FUN_0056e730(1);
            }
        }
        break;
    }

    case 0x0E: // Mount
        pAlloc = operator_new(0x800);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_00501970(1);
        break;

    case 0x10: // Pet
        pAlloc = operator_new(0x2f0);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_005a84f0(1);
        break;

    case 0x12: // Consumable
        pAlloc = operator_new(0x690);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_004c9aa0(1);
        break;

    case 0x14: // Mission item
        pAlloc = operator_new(0xf30);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_00536920(1);
        break;

    case 0x16: // Crafting material
        pAlloc = operator_new(0x690);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_00588dc0(1);
        if (pItemOrCtor == 0) return 0;
        return DualBaseSimpleObject(pItemOrCtor);

    case 0x1A: // Ammo
        pAlloc = operator_new(0x250);
        if (nCbid != 0) {
            if (pAlloc == nullptr) return 0;
            pItemOrCtor = FUN_005c7f30(1);
            if (pItemOrCtor == 0) return 0;
            return DualBaseSimpleObject(pItemOrCtor);
        }
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_005c7f30(1);
        break;

    case 0x1C: // Quest item
        pAlloc = operator_new(0x270);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_005fe7a0(1);
        break;

    case 0x1E: // Trade good
        pAlloc = operator_new(0x260);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_00605940(1);
        break;

    case 0x20: // Blueprint - alternate dual-base formula
        pAlloc = operator_new(0x1d0);
        if (pAlloc == nullptr) return 0;
        piBlueprint = FUN_0051e7d0(1);
        if (piBlueprint == nullptr) return 0;
        return *reinterpret_cast<int*>(*piBlueprint + 4) +
               reinterpret_cast<int>(piBlueprint);

    case 0x22: // Upgrade
        pAlloc = operator_new(0x500);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_00577df0(1);
        break;

    case 0x30: // Key - return ctor raw
        pAlloc = operator_new(0x210);
        if (pAlloc == nullptr) return 0;
        return FUN_00575440();

    case 0x32: // Data chip
        pAlloc = operator_new(0x260);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_00608fb0(1);
        break;

    case 0x36: // Repair kit
        pAlloc = operator_new(0x370);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_00566c10(1);
        break;

    case 0x38: // Paint
        pAlloc = operator_new(0x350);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_005dbfa0(1);
        break;

    case 0x3A: // Salvage - return ctor raw
        pAlloc = operator_new(0x270);
        if (pAlloc == nullptr) return 0;
        return FUN_0057b0e0();

    case 0x3C: // Resource
        pAlloc = operator_new(0x250);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_006054a0(1);
        break;

    case 0x3E: // Token - return ctor raw
        pAlloc = operator_new(0x1f0);
        if (pAlloc == nullptr) return 0;
        return FUN_005dfe20();

    case 0x42: // Component
        pAlloc = operator_new(0x2a0);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_0051ea10(1);
        if (pItemOrCtor == 0) return 0;
        return DualBaseSimpleObject(pItemOrCtor);

    case 0x48: // Misc
        pAlloc = operator_new(0x3f0);
        if (pAlloc == nullptr) return 0;
        pItemOrCtor = FUN_00607f90(1);
        break;

    default:
        FUN_007a4480(0, "VOG_DEBUG_STOP");
        return 0;
    }

    if (pItemOrCtor == 0) {
        return 0;
    }
    return DualBaseSimpleObject(pItemOrCtor);
}
