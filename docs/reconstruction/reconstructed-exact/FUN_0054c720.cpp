// =============================================================================
// FUN_0054c720
// -----------------------------------------------------------------------------
// Stable ID: aa_0054c720
// Address:   0x0054c720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0054c720 @ 0x0054c720
// Stable ID: aa_0054c720
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, while×1, return×1.
//  - Notable callees: __RTDynamicCast×5, CONCAT31, FUN_0054c720, FUN_0058ab60, FUN_0058c850, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */

FUN_0054c720(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  void *pvVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  char local_15;

  

  iVar1 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                          &CVOGCharacter::RTTI_Type_Descriptor,0);

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  if ((((param_3 != 0) && (*(int *)(param_3 + 0xe4e8) != 0)) && (iVar1 != 0)) &&

     (*(int *)(iVar1 + 0x250) != 0)) {

    pvVar2 = (void *)FUN_0058ab60(param_6);

    FUN_0058c850(param_1,param_4,param_2,param_3,pvVar2,0);

    if (pvVar2 != (void *)0x0) {

      operator_delete__(pvVar2);

    }

    if (*(int *)(param_2 + 0x620) != 0) {

      local_15 = '\0';

      while (((piVar3 = (int *)(local_15 * 0x10 + param_4), *piVar3 != -1 || (piVar3[1] != -1)) ||

             ((char)piVar3[2] != '\0'))) {

        iVar4 = CVOGReaction_ResolveObjectTarget

                          (CONCAT31((int3)((uint)piVar3 >> 8),(char)piVar3[2]),*piVar3,piVar3[1]);

        if (iVar4 != 0) {

          iVar5 = __RTDynamicCast(iVar4,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                  &CVOGCreature::RTTI_Type_Descriptor,0);

          if (iVar5 == 0) {

            iVar5 = __RTDynamicCast(iVar4,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                    &CVOGVehicle::RTTI_Type_Descriptor,0);

            if (iVar5 != 0) {

              iVar4 = __RTDynamicCast(iVar4,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                      &CVOGVehicle::RTTI_Type_Descriptor,0);

              __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xb0 + iVar4),0,

                              &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                              &CVOGCreature::RTTI_Type_Descriptor,0);

            }

          }

        }

        local_15 = local_15 + '\x01';

      }

    }

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x238))

              (2,*(uint32_t /* width from decompiler */ *)(param_2 + 0x5fc),(int)*(short *)(param_2 + 0x5f6),0,0,0,0,0);

  }

  return 1;

}
