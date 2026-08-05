// =============================================================================
// FUN_005149d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005149d0
// Address:   0x005149d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005149d0 @ 0x005149d0
// Stable ID: aa_005149d0
// Embedded strings (evidence for future rename):
//   - "Broken: "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~169 non-empty decompiler lines.
//  - Control keywords: do×8, while×8, if×6, return×3, goto×2, switch×1.
//  - Notable callees: FUN_007a6de0×9, FUN_00514050, FUN_005149d0, FUN_007a69d0, __RTDynamicCast, sprintf, strncat, strncpy.
//  - Strings: "Broken: ".
//  - Return sites: 3.

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

int * __thiscall FUN_005149d0(int *param_1,int param_2)



{

  byte bVar1;

  char cVar2;

  short sVar3;

  int iVar4;

  int *piVar5;

  void *pvVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  size_t sVar9;

  int *piVar10;

  char *pcVar11;

  char *pcVar12;

  char acStack_20 [32];

  

  if (param_1[0x2b] == 0) {

    switch(*(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x38)) {

    case 1:

      bVar1 = *(byte *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3f2) & 0x80;

      break;

    default:

      goto switchD_005149f7_caseD_2;

    case 4:

    case 6:

    case 8:

    case 10:

    case 0xc:

    case 0x10:

    case 0x1a:

    case 0x1c:

    case 0x32:

    case 0x34:

    case 0x42:

      goto switchD_005149f7_caseD_4;

    case 0xe:

      iVar4 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                              &CVOGVehicle::RTTI_Type_Descriptor,0);

      if (iVar4 == 0) {

        return (int *)0x0;

      }

      bVar1 = *(byte *)(iVar4 + 0x2ac);

    }

    if (bVar1 != 0) {

switchD_005149f7_caseD_4:

      FUN_007a69d0();

      piVar5 = operator_new(0x60);

      if (piVar5 == (int *)0x0) {

        piVar5 = (int *)0x0;

      }

      else {

        *piVar5 = 0;

        *(uint8_t *)((int)piVar5 + 0x26) = 0xff;

        *(uint8_t *)((int)piVar5 + 0x25) = 0xff;

        *(uint8_t *)(piVar5 + 9) = 0xff;

        *(uint8_t *)((int)piVar5 + 0x27) = 0xff;

        piVar5[0x17] = 0;

      }

      piVar5[7] = param_2;

      piVar5[8] = param_2;

      if (*(int *)(param_1[0x2a] + 0x38) == 0x42) {

        pvVar6 = operator_new__(0x20);

        *piVar5 = (int)pvVar6;

        uVar7 = (**(code **)(*param_1 + 0x168))();

        sprintf(acStack_20,"%i",uVar7);

        pcVar12 = (char *)*piVar5;

        pcVar11 = acStack_20;

        do {

          cVar2 = *pcVar11;

          *pcVar12 = cVar2;

          pcVar11 = pcVar11 + 1;

          pcVar12 = pcVar12 + 1;

        } while (cVar2 != '\0');

      }

      else {

        uVar7 = 0xffffffff;

        if (((uint)param_1[0x5f] >> 0x13 & 1) == 0) {

          uVar8 = (**(code **)(*param_1 + 0x15c))(0xffffffff);

          pcVar11 = (char *)FUN_007a6de0(uVar8,uVar7);

          sVar3 = (short)pcVar11;

          do {

            cVar2 = *pcVar11;

            pcVar11 = pcVar11 + 1;

          } while (cVar2 != '\0');

          pvVar6 = operator_new__((int)(short)((short)pcVar11 - (sVar3 + 1)) + 1);

          *piVar5 = (int)pvVar6;

          uVar8 = 0xffffffff;

          uVar7 = (**(code **)(*param_1 + 0x15c))(0xffffffff);

          pcVar11 = (char *)FUN_007a6de0(uVar7,uVar8);

          sVar3 = (short)pcVar11;

          do {

            cVar2 = *pcVar11;

            pcVar11 = pcVar11 + 1;

          } while (cVar2 != '\0');

          *(uint8_t *)((int)(short)((short)pcVar11 - (sVar3 + 1)) + *piVar5) = 0;

          uVar8 = 0xffffffff;

          uVar7 = (**(code **)(*param_1 + 0x15c))(0xffffffff);

          pcVar11 = (char *)FUN_007a6de0(uVar7,uVar8);

          sVar3 = (short)pcVar11;

          do {

            cVar2 = *pcVar11;

            pcVar11 = pcVar11 + 1;

          } while (cVar2 != '\0');

          sVar9 = (size_t)(short)((short)pcVar11 - (sVar3 + 1));

          uVar8 = 0xffffffff;

          uVar7 = (**(code **)(*param_1 + 0x15c))(0xffffffff);

          pcVar11 = (char *)FUN_007a6de0(uVar7,uVar8);

          strncpy((char *)*piVar5,pcVar11,sVar9);

        }

        else {

          uVar8 = (**(code **)(*param_1 + 0x15c))();

          pcVar11 = (char *)FUN_007a6de0(uVar8,uVar7);

          sVar3 = (short)pcVar11;

          do {

            cVar2 = *pcVar11;

            pcVar11 = pcVar11 + 1;

          } while (cVar2 != '\0');

          pvVar6 = operator_new__((int)(short)((short)pcVar11 - (sVar3 + 1)) + 9);

          *piVar5 = (int)pvVar6;

          uVar8 = 0xffffffff;

          uVar7 = (**(code **)(*param_1 + 0x15c))(0xffffffff);

          pcVar11 = (char *)FUN_007a6de0(uVar7,uVar8);

          sVar3 = (short)pcVar11;

          do {

            cVar2 = *pcVar11;

            pcVar11 = pcVar11 + 1;

          } while (cVar2 != '\0');

          *(uint8_t *)((short)((short)pcVar11 - (sVar3 + 1)) + 8 + *piVar5) = 0;

          pcVar12 = (char *)FUN_007a6de0("Broken: ",0xffffffff);

          pcVar11 = (char *)*piVar5;

          do {

            cVar2 = *pcVar12;

            *pcVar11 = cVar2;

            pcVar12 = pcVar12 + 1;

            pcVar11 = pcVar11 + 1;

          } while (cVar2 != '\0');

          uVar8 = 0xffffffff;

          uVar7 = (**(code **)(*param_1 + 0x15c))(0xffffffff);

          pcVar11 = (char *)FUN_007a6de0(uVar7,uVar8);

          sVar3 = (short)pcVar11;

          do {

            cVar2 = *pcVar11;

            pcVar11 = pcVar11 + 1;

          } while (cVar2 != '\0');

          sVar9 = (size_t)(short)((short)pcVar11 - (sVar3 + 1));

          uVar8 = 0xffffffff;

          uVar7 = (**(code **)(*param_1 + 0x15c))(0xffffffff);

          pcVar11 = (char *)FUN_007a6de0(uVar7,uVar8);

          strncat((char *)*piVar5,pcVar11,sVar9);

        }

      }

      *(uint8_t *)((int)piVar5 + 0x26) = 0xff;

      *(uint8_t *)((int)piVar5 + 0x25) = 0xff;

      *(uint8_t *)(piVar5 + 9) = 0xff;

      *(uint8_t *)((int)piVar5 + 0x27) = 0xff;

      piVar5[0xe] = param_1[0x58];

      piVar5[0xf] = param_1[0x59];

      piVar5[0x10] = param_1[0x5a];

      piVar5[0x11] = param_1[0x5b];

      piVar5[0x12] = 2;

      piVar5[0x13] = 0;

      piVar5[0x14] = 0;

      piVar10 = (int *)FUN_00514050(&param_2);

      piVar5[9] = *piVar10;

      return piVar5;

    }

  }

switchD_005149f7_caseD_2:

  return (int *)0x0;

}
