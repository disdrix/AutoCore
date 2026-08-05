// =============================================================================
// CVOGHBRecreateObject_OnHeartBeat
// -----------------------------------------------------------------------------
// Stable ID: aa_005dae50
// Address:   0x005dae50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for CVOGHBRecreateObject_OnHeartBeat @ 0x005dae50
// Stable ID: aa_005dae50
// Embedded strings (evidence for future rename):
//   - "CVOGHBRecreateObject::OnHeartBeat"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_006c6d00×3, FUN_006c6d40×3, CVOGHBBase_RescheduleAfterFire×2, CONCAT31, CVOGReaction_RandomUnitScalar, FUN_004eacc0, FUN_00560c90, FUN_005dac00.
//  - Strings: "CVOGHBRecreateObject::OnHeartBeat".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGHBRecreateObject::OnHeartBeat"
 * Domain alias of FUN_005dae50 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall CVOGHBRecreateObject_OnHeartBeat(CVOGHBBase *param_1,uint32_t /* width from decompiler */ param_2)



{

  ushort uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint *extraout_EDX;

  uint *pOutNextDelayMs;

  uint *pOutNextDelayMs_00;

  uint32_t /* width from decompiler */ local_148;

  uint32_t /* width from decompiler */ local_144;

  uint32_t /* width from decompiler */ local_140;

  uint32_t /* width from decompiler */ local_13c;

  undefined **local_138;

  uint8_t local_134;

  uint8_t *local_130;

  int local_12c;

  uint32_t /* width from decompiler */ local_128;

  uint8_t local_124 [264];

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a7236;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  FUN_0076cf00("CVOGHBRecreateObject::OnHeartBeat");

  local_14 = 0;

  iVar3 = __RTDynamicCast(param_1->pOwnerObject,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                          &CVOGPhysicsBase::RTTI_Type_Descriptor,0);

  if ((iVar3 == 0) || (*(int *)(iVar3 + 8) == 0)) {

    (**(code **)((int)param_1->pVTable + 0x18))(1,1);

    CVOGHBBase_RescheduleAfterFire(param_1,pOutNextDelayMs_00);

  }

  else {

    local_130 = local_124;

    local_138 = &PTR_FUN_009ccbb4;

    local_128 = 0x80000010;

    local_12c = 0;

    local_134 = 0;

    puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar3 + 8) + 8) + 0xcc);

    local_148 = *puVar2;

    local_144 = puVar2[1];

    local_140 = puVar2[2];

    local_13c = puVar2[3];

    local_14 = CONCAT31(local_14._1_3_,1);

    FUN_006c6d00(0x10,10);

    FUN_006c6d00(0x10,0xc);

    FUN_006c6d00(0x10,0xb);

    FUN_00560c90(*(int *)(iVar3 + 8) + 0xc,&local_138,&local_148);

    FUN_006c6d40(0x10,10);

    FUN_006c6d40(0x10,0xc);

    FUN_006c6d40(0x10,0xb);

    if (local_12c == 0) {

      FUN_005dac00();

      (**(code **)((int)param_1->pVTable + 0x18))(1,1);

      pOutNextDelayMs = extraout_EDX;

    }

    else {

      iVar3 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar3 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

      *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

      pOutNextDelayMs = (uint *)((uint)uVar1 % 0x14 + 0xc);

      param_1->nPeriodMs = (int)pOutNextDelayMs * 0xfa;

    }

    CVOGHBBase_RescheduleAfterFire(param_1,pOutNextDelayMs);

    local_14 = local_14 & 0xffffff00;

    FUN_004eacc0();

  }

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_1c;

  return param_2;

}
