// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004b52e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b52e0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004b52e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper. Evidence string: "..\\physics\\physx\\". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "..\\physics\\physx\\"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~152 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, for×2, return×1.
//  - Notable callees: FUN_005c6430×4, FUN_005c63d0×3, FUN_004b52e0, FUN_005c6350, FUN_005c6550, FUN_005c6590, FUN_005c65c0, FUN_005c65e0.
//  - Strings: "..\\physics\\physx\\".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004b52e0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  int *piVar1;

  char cVar2;

  float fVar3;

  float fVar4;

  char *pcVar5;

  char *pcVar6;

  int iVar7;

  float *pfVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint uVar10;

  uint local_44;

  uint8_t local_38 [4];

  uint local_34;

  uint32_t /* width from decompiler */ *puStack_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a14b3;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_005c65c0();

  local_4 = 0;

  FUN_005c6430(param_1,0x4c);

  if (*(int *)(param_1 + 0x30) != 0) {

    FUN_005c6430(*(int *)(param_1 + 0x30),0x7c);

  }

  pcVar5 = *(char **)(param_1 + 0x44);

  if (pcVar5 != (char *)0x0) {

    pcVar6 = pcVar5 + 1;

    do {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    FUN_005c63d0((int)pcVar5 - (int)pcVar6);

    pcVar5 = *(char **)(param_1 + 0x44);

    pcVar6 = pcVar5;

    do {

      cVar2 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar2 != '\0');

    FUN_005c6430(pcVar5,(int)pcVar6 - (int)(pcVar5 + 1));

  }

  uVar10 = *(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2;

  FUN_005c63d0(uVar10);

  local_44 = 0;

  if (uVar10 != 0) {

    do {

      iVar7 = *(int *)(*(int *)(param_1 + 0x50) + local_44 * 4);

      piVar1 = (int *)(iVar7 + 4);

      FUN_005c6430(piVar1,100);

      if (*piVar1 == 5) {

        iVar7 = __RTDynamicCast(iVar7,0,&NxShapeDesc::RTTI_Type_Descriptor,

                                &NxConvexShapeDesc::RTTI_Type_Descriptor,0);

        local_28 = 0;

        local_24 = 0;

        local_20 = 0;

        local_1c = 0;

        local_18 = 0;

        local_14 = 0;

        local_10 = 0;

        (**(code **)**(uint32_t /* width from decompiler */ **)(iVar7 + 0x68))(&local_28);

        NxInitCooking(0,0);

        NxCookConvexMesh(&local_28,local_38);

        NxCloseCooking();

        FUN_005c63d0(*(uint32_t /* width from decompiler */ *)(iVar7 + 0x6c));

        if (*(int *)(param_1 + 0x30) == 0) {

          pfVar8 = operator_new(0x84);

          fVar4 = g_flOne;

          if (pfVar8 == (float *)0x0) {

            pfVar8 = (float *)0x0;

          }

          else {

            pfVar8[0xb] = 0.0;

            pfVar8[10] = 0.0;

            pfVar8[9] = 0.0;

            fVar3 = DAT_009c7b84;

            *pfVar8 = fVar4;

            pfVar8[1] = 0.0;

            pfVar8[2] = 0.0;

            pfVar8[3] = 0.0;

            pfVar8[4] = fVar4;

            pfVar8[5] = 0.0;

            pfVar8[6] = 0.0;

            pfVar8[7] = 0.0;

            pfVar8[8] = fVar4;

            pfVar8[0xb] = 0.0;

            pfVar8[10] = 0.0;

            pfVar8[9] = 0.0;

            pfVar8[0xe] = 0.0;

            pfVar8[0xd] = 0.0;

            pfVar8[0xc] = 0.0;

            pfVar8[0x12] = 0.0;

            pfVar8[0x11] = 0.0;

            pfVar8[0x10] = 0.0;

            pfVar8[0x15] = 0.0;

            pfVar8[0x14] = 0.0;

            pfVar8[0x13] = 0.0;

            pfVar8[0x16] = fVar3;

            pfVar8[0x18] = DAT_00a10e78;

            fVar3 = DAT_00aaa668;

            pfVar8[0xf] = 0.0;

            pfVar8[0x17] = 0.0;

            pfVar8[0x19] = fVar3;

            pfVar8[0x1c] = fVar3;

            pfVar8[0x1d] = fVar3;

            pfVar8[0x1a] = 0.0;

            pfVar8[0x1e] = 5.60519e-45;

            pfVar8[0x1b] = 3.22859e-42;

            pfVar8[0x1f] = fVar3;

            pfVar8[0x20] = 0.0;

          }

          *(float **)(param_1 + 0x30) = pfVar8;

          pfVar8[0xf] = fVar4;

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x30) + 0x6c) = 0x80;

        }

      }

      local_44 = local_44 + 1;

    } while (local_44 < uVar10);

  }

  puVar9 = operator_new__(local_34);

  *param_3 = puVar9;

  for (uVar10 = local_34 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

    *puVar9 = *puStack_2c;

    puStack_2c = puStack_2c + 1;

    puVar9 = puVar9 + 1;

  }

  for (uVar10 = local_34 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

    *(uint8_t *)puVar9 = *(uint8_t *)puStack_2c;

    puStack_2c = (uint32_t /* width from decompiler */ *)((int)puStack_2c + 1);

    puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

  }

  FUN_0076bc00("..\\physics\\physx\\",0);

  FUN_005c6550(param_2,0);

  local_4._0_1_ = 1;

  FUN_005c6350(*param_3,local_34);

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_005c6590();

  local_4 = 0xffffffff;

  FUN_005c65e0();

  ExceptionList = pvStack_c;

  return;

}
