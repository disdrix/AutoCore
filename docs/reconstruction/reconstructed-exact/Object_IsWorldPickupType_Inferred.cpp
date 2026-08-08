// =============================================================================
// Object_IsWorldPickupType_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005130e0
// Address:   0x005130e0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / client-interact / object-type filter
// Generated: 2026-08-04 WQ9R-C dual seal (from live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra name: FUN_005130e0
// =============================================================================

// PURPOSE:
// Soft type filter / world-pickup eligibility for a CVOGClonedObjectBase.
// Used by Skill_GatherTargetPairFilter when filterA==-1, interact "to pick up"
// prompt, graphics post-load gate, and related list/register paths.
//
// Returns 1 iff:
//   (requireLoose==0 OR this+0xac==null) AND clone type is in the accept set
//     type 1 Object:     (cloneBlob[+0x3f2] >> 7) & 1
//     fixed types:      QuestObject/Item/Gadget/PowerPlant/Weapon/WheelSet/
//                       Commodity/Armor/TinkeringKit/Accessory/Money → 1
//     type 0xe Vehicle: RTTI CVOGVehicle and vehicle+0x2ac != 0
// Else 0. Creatures/Characters and unlisted types never pass.

// ABI (sealed):
//   thiscall ECX = object
//   stack: char requireLoose
//   RET 4
//   AL = bool

#include <cstdint>

extern "C" int __cdecl __RTDynamicCast(void *obj, int vfDelta, void *srcType,
                                       void *targetType, int isReference);

// RTTI descriptors — addresses from live decompile immediates
extern "C" void CVOGClonedObjectBase_RTTI_Type_Descriptor; // 0x00af8e10
extern "C" void CVOGVehicle_RTTI_Type_Descriptor;          // 0x00aff68c

extern "C" uint8_t __thiscall Object_IsWorldPickupType_Inferred(int this_obj,
                                                               char requireLoose)
{
  int vehicle;

  if ((requireLoose == 0) || (*(int *)(this_obj + 0xac) == 0)) {
    switch (*(uint32_t *)(*(int *)(this_obj + 0xa8) + 0x38)) {
    case 1: // CloneBaseObjectType::Object
      return (uint8_t)(*(uint8_t *)(*(int *)(*(int *)(this_obj + 0xa8) + 0x3c) +
                                    0x3f2) >>
                       7);
    case 4:    // QuestObject
    case 6:    // Item
    case 8:    // Gadget
    case 10:   // PowerPlant
    case 0xc:  // Weapon
    case 0x10: // WheelSet
    case 0x1a: // Commodity
    case 0x1c: // Armor
    case 0x32: // TinkeringKit
    case 0x34: // Accessory
    case 0x42: // Money
      return 1;
    case 0xe: // Vehicle
      vehicle = __RTDynamicCast(
          (void *)this_obj, 0, &CVOGClonedObjectBase_RTTI_Type_Descriptor,
          &CVOGVehicle_RTTI_Type_Descriptor, 0);
      if ((vehicle != 0) && (*(char *)(vehicle + 0x2ac) != 0)) {
        return 1;
      }
      break;
    default:
      break;
    }
  }
  return 0;
}

// Compatibility alias (Ghidra symbol)
extern "C" uint8_t __thiscall FUN_005130e0(int this_obj, char requireLoose)
{
  return Object_IsWorldPickupType_Inferred(this_obj, requireLoose);
}
