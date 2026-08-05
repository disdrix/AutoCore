// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_005a8650
// -----------------------------------------------------------------------------
// Stable ID: aa_005a8650
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali
// Address:   0x005a8650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×12, do×4, while×4, return×1.
//  - Notable callees: FUN_004e88e0, FUN_004e8bf0, FUN_004e9530, FUN_004e96e0, FUN_005a7180, FUN_005a75f0, FUN_005a8650.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali
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



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_005a8650(int param_1,int param_2,float *param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  float fVar2;

  char cVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float *pfVar6;

  int iVar7;

  int iVar8;

  float fVar9;

  char cStack_69;

  float local_68;

  uint32_t /* width from decompiler */ *local_64;

  uint32_t /* width from decompiler */ uStack_5c;

  float fStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint8_t auStack_40 [16];

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [28];

  

  if (*(int *)(param_1 + 0xe8) != 0) {

    FUN_005a7180(param_2,0x3f800000);

    iVar7 = 0;

    local_68 = DAT_00aaa630;

    if ('\0' < *(char *)(param_1 + 0xb0)) {

      iVar8 = 0;

      do {

        if (iVar7 < (int)(uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) +

                                                           0xac + param_1) + 0x3c) + 0x4cc)) {

          fVar9 = *(float *)(param_2 + 0x55c);

        }

        else {

          fVar9 = *(float *)(param_2 + 0x560);

        }

        iVar4 = (**(code **)(*(int *)(iVar8 + *(int *)(param_1 + 0xe8)) + 0xc))();

        fVar2 = *(float *)(iVar4 + 0x9c);

        iVar4 = (**(code **)(*(int *)(*(int *)(param_1 + 0xe8) + iVar8) + 0x48))();

        fVar9 = (*(float *)(param_2 + 0x518 + (char)iVar7 * 0xc) - fVar9 * _DAT_009d86f8) -

                *(float *)(iVar4 + 0xc) * fVar2;

        if (fVar9 < local_68) {

          local_68 = fVar9;

        }

        iVar7 = iVar7 + 1;

        iVar8 = iVar8 + 0x14c;

      } while (iVar7 < *(char *)(param_1 + 0xb0));

    }

    iVar7 = 0;

    local_64 = (uint32_t /* width from decompiler */ *)0x0;

    if ('\0' < *(char *)(param_1 + 0xb0)) {

      do {

        puVar5 = (uint32_t /* width from decompiler */ *)(param_2 + 0x514 + (char)local_64 * 0xc);

        iVar8 = (**(code **)(*(int *)(iVar7 + *(int *)(param_1 + 0xe8)) + 0xc))();

        fVar9 = *(float *)(iVar8 + 0x9c);

        iVar8 = (**(code **)(*(int *)(iVar7 + *(int *)(param_1 + 0xe8)) + 0x48))();

        fStack_58 = *(float *)(iVar8 + 0xc) * fVar9 + local_68;

        uStack_5c = *puVar5;

        uStack_54 = puVar5[2];

        if ((((int)local_64 < (int)*(char *)(param_1 + 0xb0)) && (-1 < iVar7)) &&

           (*(int *)(param_1 + 0xe8) != 0)) {

          (**(code **)(*(int *)(*(int *)(param_1 + 0xe8) + iVar7) + 0x18))(&uStack_5c);

          (**(code **)(*(int *)(*(int *)(param_1 + 0xe8) + iVar7) + 0x14))(param_3);

        }

        local_64 = (uint32_t /* width from decompiler */ *)((int)local_64 + 1);

        iVar7 = iVar7 + 0x14c;

      } while ((int)local_64 < (int)*(char *)(param_1 + 0xb0));

    }

    FUN_004e96e0(auStack_40,param_3);

    cVar3 = *(char *)(param_1 + 0xb0);

    cStack_69 = '\0';

    if ('\0' < cVar3) {

      do {

        if (((*(int *)(param_1 + 0xe8) != 0) && (-1 < cStack_69)) &&

           ((cStack_69 < cVar3 &&

            (piVar1 = (int *)(*(int *)(param_1 + 0xe8) + cStack_69 * 0x14c), piVar1 != (int *)0x0)))

           ) {

          iVar7 = (**(code **)(*piVar1 + 0xc))();

          puVar5 = (uint32_t /* width from decompiler */ *)FUN_004e9530(auStack_20,iVar7 + 0x90);

          uStack_50 = *puVar5;

          uStack_4c = puVar5[1];

          uStack_48 = puVar5[2];

          uStack_44 = puVar5[3];

          FUN_004e8bf0(param_4,auStack_40,&uStack_50,auStack_30);

          pfVar6 = (float *)FUN_004e88e0(&uStack_5c,auStack_30);

          iVar7 = (**(code **)(*piVar1 + 0x10))(3);

          if (((*pfVar6 != *(float *)(iVar7 + 0x90)) || (pfVar6[1] != *(float *)(iVar7 + 0x94))) ||

             (pfVar6[2] != *(float *)(iVar7 + 0x98))) {

            *(float *)(iVar7 + 0x90) = *pfVar6;

            *(float *)(iVar7 + 0x94) = pfVar6[1];

            *(float *)(iVar7 + 0x98) = pfVar6[2];

            if ((*(byte *)(iVar7 + 0xbc) & 1) == 0) {

              *(uint32_t /* width from decompiler */ *)(iVar7 + 0x30) = *local_64;

              *(uint32_t /* width from decompiler */ *)(iVar7 + 0x34) = local_64[1];

              *(uint32_t /* width from decompiler */ *)(iVar7 + 0x38) = local_64[2];

              *(uint *)(iVar7 + 0xbc) = *(uint *)(iVar7 + 0xbc) | 2;

            }

            *(int *)(iVar7 + 0xb4) = *(int *)(iVar7 + 0xb4) + 1;

          }

          iVar7 = (**(code **)(*piVar1 + 0x10))(3);

          if ((((*param_3 != *(float *)(iVar7 + 0x80)) || (param_3[1] != *(float *)(iVar7 + 0x84)))

              || (param_3[2] != *(float *)(iVar7 + 0x88))) ||

             (param_3[3] != *(float *)(iVar7 + 0x8c))) {

            *(float *)(iVar7 + 0x80) = *param_3;

            *(float *)(iVar7 + 0x84) = param_3[1];

            *(float *)(iVar7 + 0x88) = param_3[2];

            *(float *)(iVar7 + 0x8c) = param_3[3];

            *(uint32_t /* width from decompiler */ *)(iVar7 + 0xbc) = 0xffffffff;

            *(int *)(iVar7 + 0xb4) = *(int *)(iVar7 + 0xb4) + 1;

          }

        }

        cVar3 = *(char *)(param_1 + 0xb0);

        cStack_69 = cStack_69 + '\x01';

      } while (cStack_69 < cVar3);

    }

    cVar3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c

                              ) + 0x4ce);

    if (((cVar3 != '\x02') && (cVar3 != '\x04')) && (iVar7 = 0, 0 < *(int *)(param_1 + 0xf0))) {

      do {

        FUN_005a75f0(iVar7,param_2,param_3);

        iVar7 = iVar7 + 1;

      } while (iVar7 < *(int *)(param_1 + 0xf0));

    }

  }

  return;

}
