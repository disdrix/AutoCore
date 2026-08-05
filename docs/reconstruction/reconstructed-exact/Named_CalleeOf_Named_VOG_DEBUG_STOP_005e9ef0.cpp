// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005e9ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e9ef0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x005e9ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, goto×2.
//  - Notable callees: FUN_004cd220×4, __RTDynamicCast×3, FUN_0040d2a0, FUN_005e9ef0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_VOG_DEBUG_STOP_005e9ef0(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  float10 fVar4;

  uint32_t /* width from decompiler */ uStack_2c;

  float fStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  int local_20;

  float local_1c;

  int local_18;

  int local_14;

  

  if (param_1 == (int *)0x0) {

    return;

  }

  if (((uint)param_1[0x5f] >> 5 & 1) == 0) {

LAB_005ea036:

    if (((uint)param_1[0x5f] >> 6 & 1) != 0) {

      iVar1 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                              &CVOGGraphicsBase::RTTI_Type_Descriptor,0);

      if (*(int **)(iVar1 + 8) != (int *)0x0) {

        iVar2 = (**(code **)(**(int **)(iVar1 + 8) + 0xc))();

        uStack_2c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x90);

        fStack_28 = *(float *)(iVar2 + 0x94);

        uStack_24 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x98);

        fVar4 = (float10)FUN_004cd220(uStack_2c,uStack_24);

        fStack_28 = (float)(fVar4 + (float10)(float)param_1[0x2f]);

        (**(code **)(**(int **)(iVar1 + 8) + 0x18))(&uStack_2c);

        (**(code **)(*param_1 + 0x144))();

        return;

      }

    }

    local_20 = param_1[0x20];

    local_1c = (float)param_1[0x21];

    local_18 = param_1[0x22];

    local_14 = param_1[0x23];

    fVar4 = (float10)FUN_004cd220(local_20,local_18);

    param_1[0x21] = (int)(float)fVar4;

    param_1[0x20] = local_20;

    param_1[0x22] = local_18;

    param_1[0x23] = local_14;

    return;

  }

  iVar1 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                          &CVOGPhysicsBase::RTTI_Type_Descriptor,0);

  if (*(int *)(iVar1 + 8) == 0) goto LAB_005ea036;

  iVar2 = *(int *)(*(int *)(iVar1 + 8) + 0x3c);

  local_20 = *(int *)(iVar2 + 0xb0);

  local_1c = *(float *)(iVar2 + 0xb4);

  local_18 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb8);

  local_14 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xbc);

  if ((*(int *)(iVar1 + 8) == 0) ||

     (iVar2 = (**(code **)(**(int **)(*(int *)(iVar1 + 8) + 0x3c) + 0x18))(), iVar2 != 6)) {

    if (*(char *)(*(int *)(iVar1 + 8) + 0x40) != '\0') goto LAB_005e9ff8;

    fVar4 = (float10)FUN_004cd220(local_20,local_18);

    local_1c = (local_1c + (float)fVar4) - *(float *)(param_3 + 4);

  }

  else {

    fVar4 = (float10)FUN_004cd220(local_20,local_18);

    local_1c = (float)(fVar4 + (float10)(float)param_1[0x2f]);

  }

  FUN_0040d2a0(&local_20);

LAB_005e9ff8:

  if (((uint)param_1[0x5f] >> 6 & 1) != 0) {

    piVar3 = (int *)__RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                    &CVOGGraphicsPhysicsBase::RTTI_Type_Descriptor,0);

    (**(code **)(*piVar3 + 0x44))();

  }

  (**(code **)(*param_1 + 0x144))();

  return;

}
