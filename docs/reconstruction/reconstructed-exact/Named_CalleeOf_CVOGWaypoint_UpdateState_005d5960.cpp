// =============================================================================
// Named_CalleeOf_CVOGWaypoint_UpdateState_005d5960
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5960
// Callee of CVOGWaypoint_UpdateState
// Address:   0x005d5960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGWaypoint_UpdateState: AI/path helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×12, return×5, goto×2, do×1, while×1.
//  - Notable callees: FUN_00404c90×3, SQRT×2, FUN_004d2c60, FUN_004e8a40, FUN_005d5960, __RTDynamicCast.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of CVOGWaypoint_UpdateState
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

void __fastcall Named_CalleeOf_CVOGWaypoint_UpdateState_005d5960(int param_1)



{

  char cVar1;

  int iVar2;

  float *pfVar3;

  int *piVar4;

  float10 fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  int local_28;

  float local_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  local_28 = 0;

  *(uint8_t *)(param_1 + 0x52) = 0;

  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x10) + 4) + 4) + 0xa8 +

                  *(int *)(param_1 + 0x10));

  iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0xe568) +

                           (*(uint *)(iVar2 + 0xe560) & *(uint *)(param_1 + 0x40)) * 4) + 4);

  if (iVar2 == 0) {

LAB_005d59b9:

    piVar4 = (int *)0x0;

  }

  else {

    do {

      if (*(uint *)(param_1 + 0x40) == *(uint *)(iVar2 + 0x10)) {

        if (iVar2 == 0) goto LAB_005d59b9;

        piVar4 = *(int **)(iVar2 + 8);

        goto LAB_005d59c0;

      }

      iVar2 = *(int *)(iVar2 + 0xc);

    } while (iVar2 != 0);

    piVar4 = (int *)0x0;

  }

LAB_005d59c0:

  local_24 = DAT_00aaa7a4;

  if (piVar4 == (int *)0x0) {

    return;

  }

  iVar2 = (**(code **)(*piVar4 + 0x1c))();

  if (iVar2 == 0) {

    fVar5 = (float10)local_24;

  }

  else {

    piVar4 = (int *)(**(code **)(*piVar4 + 0x1c))();

    fVar5 = (float10)(**(code **)(*piVar4 + 0xac))();

    fVar5 = fVar5 * (float10)DAT_00a0f298;

  }

  iVar2 = *(int *)(param_1 + 0x10);

  *(uint8_t *)(param_1 + 0x52) = 1;

  if (*(int *)(iVar2 + 8) == 0) {

    pfVar3 = (float *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x84 + iVar2);

  }

  else {

    pfVar3 = (float *)(*(int *)(*(int *)(iVar2 + 8) + 0x3c) + 0xb0);

  }

  fStack_18 = pfVar3[2] - *(float *)(param_1 + 0x28);

  fStack_1c = pfVar3[1] - *(float *)(param_1 + 0x24);

  fStack_20 = *pfVar3 - *(float *)(param_1 + 0x20);

  if (SQRT((float10)fStack_20 * (float10)fStack_20 +

           (float10)fStack_1c * (float10)fStack_1c + (float10)fStack_18 * (float10)fStack_18) <

      fVar5) {

    iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x214))();

    if ((((iVar2 == 0) ||

         (iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xa4 + iVar2), iVar2 == 0)) ||

        ((*(uint *)(iVar2 + 0x17c) >> 5 & 1) == 0)) ||

       (iVar2 = __RTDynamicCast(iVar2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                &CVOGPhysicsBase::RTTI_Type_Descriptor,0), iVar2 == 0)) {

      iVar2 = *(int *)(param_1 + 0x10);

      if (*(int *)(iVar2 + 8) == 0) {

        iVar2 = *(int *)(*(int *)(iVar2 + 4) + 4) + 0x94 + iVar2;

      }

      else {

        iVar2 = *(int *)(*(int *)(iVar2 + 8) + 0x3c) + 0x30;

      }

      FUN_004e8a40(iVar2,&fStack_20);

    }

    else {

      pfVar3 = (float *)FUN_00404c90();

      fStack_20 = *pfVar3;

      fStack_1c = pfVar3[1];

      fStack_18 = pfVar3[2];

      fStack_14 = pfVar3[3];

      pfVar3 = (float *)FUN_00404c90();

      fStack_20 = fStack_20 - *pfVar3;

      fStack_1c = fStack_1c - pfVar3[1];

      fStack_18 = fStack_18 - pfVar3[2];

      local_24 = fStack_18 * fStack_18 + fStack_1c * fStack_1c + fStack_20 * fStack_20;

      if (local_24 == 0.0) {

        fVar6 = 0.0;

      }

      else {

        fVar6 = g_flOne / SQRT(local_24);

        local_24 = fVar6;

      }

      fStack_20 = fVar6 * fStack_20;

      fStack_1c = fStack_1c * fVar6;

      fStack_18 = fStack_18 * fVar6;

      fStack_14 = (fStack_14 - pfVar3[3]) * fVar6;

    }

    cVar1 = FUN_004d2c60(*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),*(uint32_t /* width from decompiler */ *)(param_1 + 0x48),&fStack_20,

                         (float *)(param_1 + 0x20),&local_28);

    *(char *)(param_1 + 0x52) = cVar1;

    if (cVar1 == '\0') {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0xffffffff;

      return;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

    iVar2 = *(int *)(local_28 + 0x134);

    *(int *)(param_1 + 0x40) = iVar2;

    *(int *)(param_1 + 0x44) = iVar2 >> 0x1f;

    pfVar3 = (float *)FUN_00404c90();

    fVar8 = pfVar3[2] - *(float *)(param_1 + 0x28);

    fVar7 = pfVar3[1] - *(float *)(param_1 + 0x24);

    fVar6 = *pfVar3 - *(float *)(param_1 + 0x20);

    if (*(float *)(param_1 + 0x4c) * *(float *)(param_1 + 0x4c) <=

        fVar8 * fVar8 + fVar7 * fVar7 + fVar6 * fVar6) {

      *(uint8_t *)(param_1 + 0x53) = 0;

      return;

    }

    *(uint8_t *)(param_1 + 0x53) = 1;

    return;

  }

  return;

}
