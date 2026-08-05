// =============================================================================
// FUN_005787a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005787a0
// Address:   0x005787a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005787a0 @ 0x005787a0
// Stable ID: aa_005787a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT22, CONCAT31, CVOGHBBase_RescheduleAfterFire, FUN_005787a0, __RTDynamicCast.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ * __fastcall FUN_005787a0(CVOGHBBase *param_1,uint *param_2,uint32_t /* width from decompiler */ *param_3)



{

  short sVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  uint16_t extraout_var;

  uint *extraout_EDX;

  uint32_t /* width from decompiler */ uVar4;

  TypeDescriptor *pTVar5;

  TypeDescriptor *pTVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  if (*(short *)((int)&param_1[1].nRefOrFlags + 2) != 0) {

    uVar7 = 0;

    pTVar6 = &CVOGCreature::RTTI_Type_Descriptor;

    pTVar5 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

    uVar4 = 0;

    uVar2 = CVOGReaction_ResolveObjectTarget

                      (CONCAT31((int3)((uint)param_1[0x28].nUnusedOrFlags >> 8),

                                param_1[0x28].cStopped),param_1[0x28].pOwnerObject,

                       param_1[0x28].nUnusedOrFlags);

    piVar3 = (int *)__RTDynamicCast(uVar2,uVar4,pTVar5,pTVar6,uVar7);

    if ((piVar3 == (int *)0x0) ||

       (sVar1 = *(short *)((int)&param_1[1].nRefOrFlags + 2), (short)piVar3[0x4b] < sVar1)) {

      (**(code **)((int)param_1->pVTable + 0x40))();

      *param_3 = DAT_00af31e8;

      return param_3;

    }

    (**(code **)(*piVar3 + 0xb0))(CONCAT22(extraout_var,sVar1));

    param_2 = extraout_EDX;

  }

  CVOGHBBase_RescheduleAfterFire(param_1,param_2);

  return param_3;

}
