// =============================================================================
// FUN_005130e0  (twin of Object_IsWorldPickupType_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005130e0
// Address:   0x005130e0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / client-interact / object-type filter
// Generated: 2026-08-04 WQ9R-C dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named plate: reconstructed-exact/Object_IsWorldPickupType_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" int __cdecl __RTDynamicCast(void *obj, int vfDelta, void *srcType,
                                       void *targetType, int isReference);
extern "C" void CVOGClonedObjectBase_RTTI_Type_Descriptor;
extern "C" void CVOGVehicle_RTTI_Type_Descriptor;

/*
 * Soft type / world-pickup eligibility (see named clean for full plate).
 * thiscall; RET 4; AL bool.
 * requireLoose: when non-zero, require this+0xac == 0.
 */

extern "C" uint8_t __thiscall FUN_005130e0(int this_obj, char requireLoose)
{
  int vehicle;

  if ((requireLoose == 0) || (*(int *)(this_obj + 0xac) == 0)) {
    switch (*(uint32_t *)(*(int *)(this_obj + 0xa8) + 0x38)) {
    case 1:
      return (uint8_t)(*(uint8_t *)(*(int *)(*(int *)(this_obj + 0xa8) + 0x3c) +
                                    0x3f2) >>
                       7);
    case 4:
    case 6:
    case 8:
    case 10:
    case 0xc:
    case 0x10:
    case 0x1a:
    case 0x1c:
    case 0x32:
    case 0x34:
    case 0x42:
      return 1;
    case 0xe:
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
