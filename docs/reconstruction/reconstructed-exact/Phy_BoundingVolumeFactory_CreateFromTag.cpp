// =============================================================================
// Phy_BoundingVolumeFactory_CreateFromTag
// -----------------------------------------------------------------------------
// Purpose:  Factory create-by-tag path for phy bounding volumes (sibling of
//           Phy_BoundingVolumeFactory_InvalidTag assert). Constructs volume
//           from chunk/tag id for collision asset load.
//
// Address:  0x00467820  (autoassault.exe, image base 0x400000)
// Stable:   aa_00467820
// System:   physics / phy
// String:   "../palantir/physics/phyBoundingVolumeFactory.h"
//
// Exactness: CF mirrors raw scaffold; tag->type table still open.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

uint32_t /* width from decompiler */ * __fastcall Phy_BoundingVolumeFactory_CreateFromTag(void *param_1)

{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009befeb;

  local_c = ExceptionList;

  local_10 = param_1;

  switch(param_1) {

  case (void *)0x1:

    ExceptionList = &local_c;

    puVar2 = operator_new(0x18);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar2[1] = 0;

      *puVar2 = &PTR_FUN_00aa5c54;

      puVar2[2] = DAT_00d1a6c0;

      puVar2[3] = DAT_00d1a6c4;

      puVar2[4] = DAT_00d1a6c8;

      puVar2[5] = 0;

      ExceptionList = local_c;

      return puVar2;

    }

    break;

  case (void *)0x2:

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x20);

    if (pvVar1 != (void *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_00467440();

      ExceptionList = local_c;

      return puVar2;

    }

    break;

  case (void *)0x3:

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x28);

    if (pvVar1 != (void *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_004674e0();

      ExceptionList = local_c;

      return puVar2;

    }

    break;

  case (void *)0x4:

    ExceptionList = &local_c;

    puVar2 = operator_new(8);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar2[1] = 0;

      *puVar2 = &PTR_FUN_00aa5c6c;

      ExceptionList = local_c;

      return puVar2;

    }

    break;

  case (void *)0x5:

    ExceptionList = &local_c;

    local_10 = operator_new(0x100);

    local_4 = 0;

    if (local_10 != (void *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_00467600(local_10);

      ExceptionList = local_c;

      return puVar2;

    }

    break;

  default:

    ExceptionList = &local_c;

    uVar3 = FUN_0076cec0(&local_10,"Invalid type [ %c ] for phyBoundingVolume",param_1);

    vog_LogMessage("..\\palantir/physics/phyBoundingVolumeFactory.h",0x66,3,uVar3);

    ExceptionList = local_c;

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  ExceptionList = local_c;

  return (uint32_t /* width from decompiler */ *)0x0;

}
