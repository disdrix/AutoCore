// =============================================================================
// Named_Crazy_null_checking_flipper_failed
// -----------------------------------------------------------------------------
// Stable ID: aa_005075f0
// Address:   0x005075f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Crazy_null_checking_flipper_failed @ 0x005075f0
// Stable ID: aa_005075f0
// Embedded strings (evidence for future rename):
//   - "Crazy null checking on the flipper has failed! v:%u m:%u w:%u f:%u"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_ctor, Named_Crazy_null_checking_flipper_failed, FUN_005083f0, FUN_0055fe50, FUN_00600140, FUN_007a4480.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Crazy null checking on the flipper has failed! v:%u m:%u w:%u f:%u"
 * Domain alias of FUN_005075f0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall Named_Crazy_null_checking_flipper_failed(uint32_t /* width from decompiler */ *param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ *local_38 [2];

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  void *pvStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a3173;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  local_38[0] = param_1;

  CVOGHBBase_ctor(param_1);

  *param_1 = &PTR_FUN_009cda10;

  local_14 = 0;

  if (*(char *)((int)param_2 + 0x102) != '\0') {

    FUN_005083f0(0,0);

    ExceptionList = pvStack_24;

    return param_1;

  }

  CVOGHBBase_AttachOwnerObject(param_1,(void *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2));

  *(uint8_t *)((int)param_2 + 0x102) = 1;

  CVOGHBBase_SetPeriodAndCounter(param_1,1,true);

  param_1[2] = param_3;

  param_1[10] = param_2;

  param_1[9] = 0;

  (**(code **)(*param_2 + 0x28))();

  iVar2 = *(int *)(param_1[10] + 600);

  if (iVar2 != 0) {

    if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) + 0x3c) +

                 0x4ce) == '\x02') {

      uStack_30 = DAT_00af1900;

      uStack_2c = DAT_00af1904;

      uStack_28 = DAT_00af1908;

      pvStack_24 = DAT_00af190c;

    }

    else {

      uStack_30 = DAT_00af18f0;

      uStack_2c = DAT_00af18f4;

      uStack_28 = DAT_00af18f8;

      pvStack_24 = DAT_00af18fc;

    }

  }

  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x50,0x24);

  *(uint16_t *)(iVar2 + 4) = 0x50;

  pvStack_1c._0_1_ = 1;

  iVar3 = FUN_00600140(*(uint32_t /* width from decompiler */ *)(param_1[10] + 8),local_38,&DAT_00af18e0,uStack_44,0x3dcccccd)

  ;

  iVar2 = param_1[10];

  pvStack_1c = (void *)((uint)pvStack_1c._1_3_ << 8);

  param_1[9] = iVar3;

  if ((((iVar2 != 0) &&

       (iVar1 = *(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xa8 + iVar2), iVar1 != 0)) &&

      (*(int *)(iVar1 + 0xe4a4) != 0)) && (iVar3 != 0)) {

    FUN_0055fe50(iVar3);

    ExceptionList = pvStack_24;

    return param_1;

  }

  iVar1 = *(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xa8 + iVar2);

  FUN_007a4480(1,"Crazy null checking on the flipper has failed! v:%u m:%u w:%u f:%u",iVar2,iVar1,

               *(uint32_t /* width from decompiler */ *)(iVar1 + 0xe4a4),iVar3);

  ExceptionList = pvStack_24;

  return param_1;

}
