// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004b5790
// -----------------------------------------------------------------------------
// Stable ID: aa_004b5790
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x004b5790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~247 non-empty decompiler lines.
//  - Control keywords: if×13, for×2, return×1.
//  - Notable callees: FUN_005c64d0×4, FUN_005c6520×4, FUN_004b5790, FUN_005c6610, FUN_005c6630, __RTDynamicCast, free, malloc.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_004b5790(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  float fVar3;

  float fVar4;

  float *pfVar5;

  int iVar6;

  void *pvVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint uVar13;

  uint8_t local_14 [8];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a14d7;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_005c6610(param_2);

  local_4 = 0;

  FUN_005c6520(param_1,0x4c);

  if (*(int *)(param_1 + 0x30) != 0) {

    pfVar5 = operator_new(0x84);

    fVar3 = g_flOne;

    if (pfVar5 == (float *)0x0) {

      pfVar5 = (float *)0x0;

    }

    else {

      pfVar5[0xb] = 0.0;

      pfVar5[10] = 0.0;

      pfVar5[9] = 0.0;

      *pfVar5 = fVar3;

      pfVar5[4] = fVar3;

      pfVar5[8] = fVar3;

      fVar3 = DAT_009c7b84;

      pfVar5[1] = 0.0;

      pfVar5[2] = 0.0;

      pfVar5[3] = 0.0;

      pfVar5[5] = 0.0;

      pfVar5[6] = 0.0;

      pfVar5[7] = 0.0;

      pfVar5[0xb] = 0.0;

      pfVar5[10] = 0.0;

      pfVar5[9] = 0.0;

      pfVar5[0xe] = 0.0;

      pfVar5[0xd] = 0.0;

      pfVar5[0xc] = 0.0;

      pfVar5[0x12] = 0.0;

      pfVar5[0x11] = 0.0;

      pfVar5[0x10] = 0.0;

      pfVar5[0x15] = 0.0;

      pfVar5[0x14] = 0.0;

      pfVar5[0x13] = 0.0;

      pfVar5[0x16] = fVar3;

      pfVar5[0x18] = DAT_00a10e78;

      fVar3 = DAT_00aaa668;

      pfVar5[0xf] = 0.0;

      pfVar5[0x17] = 0.0;

      pfVar5[0x19] = fVar3;

      pfVar5[0x1c] = fVar3;

      pfVar5[0x1d] = fVar3;

      pfVar5[0x1a] = 0.0;

      pfVar5[0x1e] = 5.60519e-45;

      pfVar5[0x1b] = 3.22859e-42;

      pfVar5[0x1f] = fVar3;

      pfVar5[0x20] = 0.0;

    }

    *(float **)(param_1 + 0x30) = pfVar5;

    FUN_005c6520(pfVar5,0x7c);

    fVar3 = g_flMultiKillCountBlend;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x30) + 0x78) = 1;

    *(float *)(*(int *)(param_1 + 0x30) + 0x70) = fVar3;

    *(float *)(*(int *)(param_1 + 0x30) + 0x74) = fVar3;

  }

  if (*(int *)(param_1 + 0x44) != 0) {

    iVar6 = FUN_005c64d0();

    pvVar7 = operator_new__(iVar6 + 1);

    *(void **)(param_1 + 0x44) = pvVar7;

    FUN_005c6520(pvVar7,iVar6);

    *(uint8_t *)(*(int *)(param_1 + 0x44) + 1 + iVar6) = 0;

  }

  for (iVar6 = FUN_005c64d0(); iVar6 != 0; iVar6 = iVar6 + -1) {

    iVar8 = FUN_005c64d0();

    if (iVar8 == 5) {

      param_2 = operator_new(0x70);

      fVar3 = g_flOne;

      if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

        param_2 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        param_2[1] = 5;

        param_2[0xd] = 0;

        param_2[0xc] = 0;

        param_2[0xb] = 0;

        param_2[3] = 0;

        param_2[4] = 0;

        param_2[5] = 0;

        param_2[7] = 0;

        param_2[8] = 0;

        param_2[9] = 0;

        param_2[2] = fVar3;

        param_2[6] = fVar3;

        param_2[10] = fVar3;

        param_2[3] = 0;

        param_2[4] = 0;

        param_2[5] = 0;

        param_2[7] = 0;

        param_2[8] = 0;

        param_2[9] = 0;

        param_2[2] = fVar3;

        param_2[6] = fVar3;

        param_2[10] = fVar3;

        param_2[0xd] = 0;

        param_2[0xc] = 0;

        param_2[0xb] = 0;

        *param_2 = &PTR_FUN_009cb228;

        param_2[3] = 0;

        param_2[4] = 0;

        param_2[5] = 0;

        param_2[7] = 0;

        param_2[8] = 0;

        param_2[9] = 0;

        param_2[2] = fVar3;

        param_2[6] = fVar3;

        param_2[10] = fVar3;

        param_2[0xd] = 0;

        param_2[0xc] = 0;

        param_2[0xb] = 0;

        fVar4 = DAT_00aaa668;

        param_2[0xe] = 8;

        *(uint16_t *)(param_2 + 0xf) = 0;

        *(uint16_t *)((int)param_2 + 0x3e) = 0;

        param_2[0x10] = 0;

        param_2[0x13] = fVar4;

        param_2[0x11] = fVar3;

        param_2[0x12] = fVar4;

        param_2[0x14] = 0;

        param_2[0x15] = 0;

        param_2[0x16] = 0;

        param_2[0x17] = 0;

        param_2[0x18] = 0;

        param_2[0x19] = 0;

        param_2[0x1a] = 0;

        param_2[0x1b] = 0;

      }

      if (*(int *)(param_1 + 0x30) == 0) {

        pfVar5 = operator_new(0x84);

        fVar3 = g_flOne;

        if (pfVar5 == (float *)0x0) {

          pfVar5 = (float *)0x0;

        }

        else {

          pfVar5[0xb] = 0.0;

          pfVar5[10] = 0.0;

          pfVar5[9] = 0.0;

          fVar4 = DAT_009c7b84;

          *pfVar5 = fVar3;

          pfVar5[1] = 0.0;

          pfVar5[2] = 0.0;

          pfVar5[3] = 0.0;

          pfVar5[4] = fVar3;

          pfVar5[5] = 0.0;

          pfVar5[6] = 0.0;

          pfVar5[7] = 0.0;

          pfVar5[8] = fVar3;

          pfVar5[0xb] = 0.0;

          pfVar5[10] = 0.0;

          pfVar5[9] = 0.0;

          pfVar5[0xe] = 0.0;

          pfVar5[0xd] = 0.0;

          pfVar5[0xc] = 0.0;

          pfVar5[0x12] = 0.0;

          pfVar5[0x11] = 0.0;

          pfVar5[0x10] = 0.0;

          pfVar5[0x15] = 0.0;

          pfVar5[0x14] = 0.0;

          pfVar5[0x13] = 0.0;

          pfVar5[0x16] = fVar4;

          pfVar5[0x18] = DAT_00a10e78;

          fVar4 = DAT_00aaa668;

          pfVar5[0xf] = 0.0;

          pfVar5[0x17] = 0.0;

          pfVar5[0x19] = fVar4;

          pfVar5[0x1c] = fVar4;

          pfVar5[0x1d] = fVar4;

          pfVar5[0x1a] = 0.0;

          pfVar5[0x1e] = 5.60519e-45;

          pfVar5[0x1b] = 3.22859e-42;

          pfVar5[0x1f] = fVar4;

          pfVar5[0x20] = 0.0;

        }

        *(float **)(param_1 + 0x30) = pfVar5;

        pfVar5[0xf] = fVar3;

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x30) + 0x6c) = 0x80;

      }

    }

    FUN_005c6520(param_2 + 2,0x60);

    if (iVar8 == 5) {

      iVar8 = __RTDynamicCast(param_2,0,&NxShapeDesc::RTTI_Type_Descriptor,

                              &NxConvexShapeDesc::RTTI_Type_Descriptor,0);

      uVar9 = (**(code **)(*(int *)*DAT_00b037f0 + 0x3c))(local_14);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x68) = uVar9;

      uVar9 = FUN_005c64d0();

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x6c) = uVar9;

    }

    if (*(short *)(param_2 + 0xf) == 2) {

      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 0x40;

    }

    if (*(uint *)(param_1 + 0x58) <= *(uint *)(param_1 + 0x54)) {

      iVar8 = *(int *)(param_1 + 0x50);

      uVar1 = ((int)(*(uint *)(param_1 + 0x54) - iVar8) >> 2) * 2 + 2;

      if (iVar8 == 0) {

        uVar13 = 0;

      }

      else {

        uVar13 = (int)(*(uint *)(param_1 + 0x58) - iVar8) >> 2;

      }

      if (uVar13 < uVar1) {

        puVar10 = malloc(uVar1 * 4);

        puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x54);

        puVar12 = puVar10;

        for (puVar11 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x50); puVar11 != puVar2; puVar11 = puVar11 + 1) {

          *puVar12 = *puVar11;

          puVar12 = puVar12 + 1;

        }

        if (*(void **)(param_1 + 0x50) != (void *)0x0) {

          free(*(void **)(param_1 + 0x50));

        }

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x58) = puVar10 + uVar1;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x54) =

             puVar10 + (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2);

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x50) = puVar10;

      }

    }

    **(uint32_t /* width from decompiler */ **)(param_1 + 0x54) = param_2;

    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 4;

  }

  local_4 = 0xffffffff;

  FUN_005c6630();

  ExceptionList = pvStack_c;

  return 1;

}
