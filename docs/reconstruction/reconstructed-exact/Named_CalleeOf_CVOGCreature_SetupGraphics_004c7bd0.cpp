// =============================================================================
// Named_CalleeOf_CVOGCreature_SetupGraphics_004c7bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c7bd0
// Callee of CVOGCreature_SetupGraphics
// Address:   0x004c7bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// SUPERSEDED 2026-07-29 W22-J: canonical name CVOGCreature_SlewFacingYaw_Inferred
//   (see CVOGCreature_SlewFacingYaw_Inferred.cpp). Parent-seed scaffold incomplete.
// PURPOSE (auto): Called from CVOGCreature_SetupGraphics: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×17, return×2.
//  - Notable callees: SQRT×3, __RTDynamicCast×2, FUN_00404c90, FUN_0040d0a0, FUN_004c7bd0, FUN_004e8a40, FUN_004e8ad0, FUN_004e9530.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGCreature_SetupGraphics
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_CalleeOf_CVOGCreature_SetupGraphics_004c7bd0(int param_1,int param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float *pfVar5;

  float10 fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float local_48;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t local_20 [28];

  

  if (*(int *)(param_1 + 8) != 0) {

    FUN_004e8a40(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x30,&local_40);

    iVar4 = _finite((double)local_40);

    if (iVar4 != 0) {

      iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1);

      if (((iVar4 == 0) || ((*(uint *)(iVar4 + 0x17c) >> 5 & 1) == 0)) ||

         (iVar4 = __RTDynamicCast(iVar4,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                  &CVOGPhysicsBase::RTTI_Type_Descriptor,0),

         *(int *)(iVar4 + 8) == 0)) {

        local_24 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x114);

        if (((*(uint *)(param_1 + 0x108) & *(uint *)(param_1 + 0x10c)) == 0xffffffff) &&

           ((char)*(uint32_t /* width from decompiler */ *)(param_1 + 0x110) == '\0')) {

          return;

        }

        pfVar5 = (float *)FUN_004e9530(&local_30,

                                       *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8

                                                        + param_1) + 0xe894) + 0x11c);

        local_30 = *pfVar5;

        local_28 = pfVar5[2];

      }

      else {

        __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1),0,

                        &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                        &CVOGPhysicsBase::RTTI_Type_Descriptor,0);

        pfVar5 = (float *)FUN_00404c90();

        local_30 = local_40 + *pfVar5;

        local_28 = local_38 + pfVar5[2];

      }

      iVar4 = *(int *)(param_1 + 8);

      if (iVar4 == 0) {

        pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

      }

      else {

        pfVar5 = (float *)(*(int *)(iVar4 + 0x3c) + 0xb0);

      }

      local_30 = local_30 - *pfVar5;

      local_28 = local_28 - pfVar5[2];

      fVar8 = local_28 * local_28 + local_30 * local_30;

      if (DAT_009cb8d4 < SQRT(fVar8)) {

        if (fVar8 == 0.0) {

          local_2c = 0.0;

        }

        else {

          local_2c = g_flOne / SQRT(fVar8);

        }

        local_28 = local_28 * local_2c;

        local_48 = *(float *)(param_1 + 0x11c);

        local_30 = local_2c * local_30;

        local_2c = local_2c * 0.0;

        fVar6 = (float10)FUN_0040d0a0();

        fVar8 = (float)fVar6;

        if (iVar4 == 0) {

          iVar4 = *(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1;

        }

        else {

          iVar4 = *(int *)(iVar4 + 0x3c) + 0x30;

        }

        FUN_004e8ad0(iVar4,local_20);

        if (local_38 * 0.0 + local_3c * 0.0 + local_40 < 0.0) {

          fVar8 = DAT_00aaa7dc - fVar8;

        }

        local_48 = fVar8 + local_48;

        if (DAT_00aaa7dc < local_48) {

          local_48 = local_48 - DAT_00aaa7dc;

        }

        if (local_48 < 0.0) {

          local_48 = local_48 + DAT_00aaa7dc;

        }

        fVar6 = (float10)fsin((float10)local_48);

        fVar1 = (float)fVar6;

        fVar6 = (float10)fcos((float10)local_48);

        fVar2 = (float)fVar6;

        fVar7 = fVar2 * fVar2 + fVar1 * fVar1;

        if (fVar7 == 0.0) {

          fVar7 = 0.0;

        }

        else {

          fVar7 = g_flOne / SQRT(fVar7);

        }

        fVar9 = fVar2 * fVar7 * local_28 + fVar7 * 0.0 * local_2c + fVar7 * fVar1 * local_30;

        if (fVar9 < (float)_DAT_009cbab8) {

          fVar3 = (float)param_2;

          if (param_2 < 0) {

            fVar3 = fVar3 + _DAT_00aaa5dc;

          }

          fVar9 = (g_flOne - fVar9) * fVar3 * g_flMsToSeconds_Inferred * _DAT_009cbab0;

          if (0.0 <= local_28 * fVar7 * fVar1 - fVar2 * fVar7 * local_30) {

            fVar9 = local_48 - fVar9;

          }

          else {

            fVar9 = fVar9 + local_48;

          }

          fVar9 = fVar9 - fVar8;

          if (DAT_00aaa7dc < fVar9) {

            fVar9 = fVar9 - DAT_00aaa7dc;

          }

          if (fVar9 < 0.0) {

            fVar9 = fVar9 + DAT_00aaa7dc;

          }

          *(float *)(param_1 + 0x11c) = fVar9;

        }

      }

    }

  }

  return;

}
