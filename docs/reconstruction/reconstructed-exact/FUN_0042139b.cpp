// =============================================================================
// FUN_0042139b  (scaffold — prefer OleDb_BuildBindingsAllocRow_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0042139b
// Address:   0x0042139b–0x0042166d  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB binding build + row alloc
// Generated: 2026-07-23 scaffold; W23-C dual seal 2026-07-29 (named plate separate)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Canonical: OleDb_BuildBindingsAllocRow_Inferred
// =============================================================================

// PURPOSE: SEH-split OLE DB binding builder + row alloc; continues into FUN_00421677.
// Stable ID: aa_0042139b
// Dual A/B: accept-with-gaps (W23-C). See named plate for sealed CF + ABI.

// READABILITY (auto CF):
//  - Body size: ~204 non-empty decompiler lines.
//  - Control keywords: if×13, goto×6, return×3, switch×2, for×1, do×1, while×1.
//  - Notable callees: FUN_0042139b, FUN_00421677, FUN_00422880, FUN_00422900, WARNING.
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

/* WARNING (jumptable): Unable to track spacebase fully for stack */



int FUN_0042139b(void)



{

  uint8_t uVar1;

  ushort uVar2;

  uint16_t uVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  void *pvVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint uVar11;

  int *unaff_EBX;

  int unaff_EBP;

  int iVar12;

  uint uVar13;

  

  *(uint32_t /* width from decompiler */ *)(unaff_EBP + -4) = 0;

  if (unaff_EBX[4] == 0) {

    operator_delete__(*(void **)(unaff_EBP + -0x1c));

    *(uint32_t /* width from decompiler */ *)(unaff_EBP + -4) = 0xffffffff;

    piVar4 = *(int **)(unaff_EBP + -0x18);

    if (piVar4 != (int *)0x0) {

      (**(code **)(*piVar4 + 8))(piVar4);

    }

    ExceptionList = *(void **)(unaff_EBP + -0xc);

    return -0x7ff8fff2;

  }

  iVar12 = unaff_EBX[3];

  *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x2c) = 0;

  if (iVar12 != 0) {

    iVar8 = FUN_00422900();

    *(int *)(unaff_EBP + -0x34) = iVar8;

    iVar12 = 0;

    *(uint *)(unaff_EBP + -0x38) = ~(iVar8 - 1U);

    *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x30) = 0;

    puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_EBP + -0x1c) + 0x14);

    do {

      iVar5 = *(int *)(unaff_EBP + -0x2c);

      *(uint8_t *)(iVar5 + unaff_EBX[4]) = 0;

      iVar8 = iVar12 + unaff_EBX[5];

      uVar11 = *(uint *)(iVar8 + 0x10);

      uVar13 = unaff_EBX[9];

      *(int *)(unaff_EBP + -0x28) = iVar8;

      if (uVar13 < uVar11) {

LAB_00421519:

        *(uint16_t *)(iVar8 + 0x14) = 0x4082;

        *(uint32_t /* width from decompiler */ *)(iVar12 + 0x10 + unaff_EBX[5]) = 4;

        *(uint8_t *)(iVar5 + unaff_EBX[4]) = 1;

      }

      else {

        uVar2 = *(ushort *)(iVar8 + 0x14);

        if (uVar2 == 0xd) {

          iVar8 = *(int *)(unaff_EBP + -0x28);

          goto LAB_00421519;

        }

        if (uVar2 < 0x41) {

          if (uVar2 == 0x40) goto switchD_00421457_caseD_6;

          switch(uVar2) {

          case 2:

            uVar11 = 7;

            break;

          case 3:

            uVar11 = 0xc;

            break;

          case 4:

            uVar11 = 0xd;

            break;

          case 5:

          case 0xe:

switchD_00421457_caseD_5:

            uVar11 = 0x17;

            break;

          default:

            goto switchD_00421457_caseD_6;

          case 8:

            break;

          case 0xb:

            uVar11 = 2;

            break;

          case 0xc:

            uVar11 = 0x14;

            break;

          case 0x10:

            uVar11 = 5;

            break;

          case 0x11:

            uVar11 = 4;

            break;

          case 0x12:

            uVar11 = 6;

            break;

          case 0x13:

            uVar11 = 0xb;

            break;

          case 0x14:

            uVar11 = 0x16;

            break;

          case 0x15:

            uVar11 = 0x15;

          }

        }

        else {

          if (uVar2 < 0x87) {

            switch(uVar2) {

            case 0x48:

              uVar11 = 0x26;

              break;

            default:

              goto switchD_00421457_caseD_6;

            case 0x80:

              uVar11 = uVar11 * 2;

              break;

            case 0x81:

            case 0x82:

              break;

            case 0x83:

              goto switchD_00421457_caseD_5;

            }

            goto switchD_00421457_caseD_8;

          }

switchD_00421457_caseD_6:

          uVar11 = 0x20;

        }

switchD_00421457_caseD_8:

        *(uint *)(*(int *)(unaff_EBP + -0x28) + 0x10) = uVar11 * 2 + 2;

        *(uint16_t *)(iVar12 + 0x14 + unaff_EBX[5]) = 0x82;

      }

      iVar8 = *(int *)(iVar12 + 0x10 + unaff_EBX[5]);

      iVar12 = iVar12 + unaff_EBX[5];

      uVar13 = *(int *)(unaff_EBP + -0x34) + -1 + *(int *)(unaff_EBP + -0x24) &

               *(uint *)(unaff_EBP + -0x38);

      *(uint *)(unaff_EBP + -0x40) = uVar13;

      uVar13 = iVar8 + 3 + uVar13 & 0xfffffffc;

      *(uint *)(unaff_EBP + -0x28) = uVar13;

      *(uint16_t *)(unaff_EBP + -0x3c) = *(uint16_t *)(iVar12 + 0x14);

      *(uint *)(unaff_EBP + -0x44) = uVar13 + 4;

      iVar5 = *(int *)(unaff_EBP + -0x28);

      *(uint *)(unaff_EBP + -0x24) = uVar13 + 8;

      *(uint8_t *)(unaff_EBP + -0x14) = *(uint8_t *)(iVar12 + 0x17);

      uVar6 = *(uint32_t /* width from decompiler */ *)(iVar12 + 8);

      *(uint8_t *)((int)puVar10 + 0x1e) = *(uint8_t *)(iVar12 + 0x16);

      uVar1 = *(uint8_t *)(unaff_EBP + -0x14);

      puVar10[-5] = uVar6;

      uVar3 = *(uint16_t *)(unaff_EBP + -0x3c);

      *(uint8_t *)((int)puVar10 + 0x1f) = uVar1;

      uVar6 = *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x40);

      puVar10[3] = 0;

      *puVar10 = 0;

      puVar10[4] = 0;

      *(uint16_t *)(puVar10 + 7) = uVar3;

      puVar10[6] = 0;

      puVar10[-3] = 0;

      puVar10[-2] = 0;

      puVar10[-1] = 0;

      puVar10[1] = 0;

      puVar10[5] = iVar8;

      puVar10[2] = 1;

      puVar10[-4] = uVar6;

      if (iVar5 != 0) {

        uVar7 = *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x28);

        puVar10[2] = 3;

        puVar10[-3] = uVar7;

      }

      iVar12 = *(int *)(unaff_EBP + -0x44);

      if (iVar12 != 0) {

        puVar10[2] = puVar10[2] | 4;

        puVar10[-2] = iVar12;

      }

      iVar12 = *(int *)(unaff_EBP + -0x30);

      *(uint32_t /* width from decompiler */ *)(iVar12 + 4 + unaff_EBX[5]) = uVar6;

      uVar11 = *(int *)(unaff_EBP + -0x2c) + 1;

      iVar12 = iVar12 + 0x30;

      puVar10 = puVar10 + 0xd;

      uVar13 = unaff_EBX[3];

      *(uint *)(unaff_EBP + -0x2c) = uVar11;

      *(int *)(unaff_EBP + -0x30) = iVar12;

    } while (uVar11 < uVar13);

  }

  if (*unaff_EBX == 0) {

    iVar12 = FUN_00422880();

    if (iVar12 < 0) {

      operator_delete__(*(void **)(unaff_EBP + -0x1c));

      operator_delete__((void *)unaff_EBX[4]);

      *(uint32_t /* width from decompiler */ *)(unaff_EBP + -4) = 0xffffffff;

      piVar4 = *(int **)(unaff_EBP + -0x18);

      unaff_EBX[4] = 0;

      if (piVar4 != (int *)0x0) {

        (**(code **)(*piVar4 + 8))(piVar4);

      }

      ExceptionList = *(void **)(unaff_EBP + -0xc);

      return iVar12;

    }

    *(uint8_t *)(*unaff_EBX + 4) = 1;

  }

  uVar13 = *(uint *)(unaff_EBP + -0x24);

  unaff_EBX[2] = 0;

  *(uint8_t *)(unaff_EBP + -4) = 6;

  pvVar9 = operator_new__(uVar13);

  unaff_EBX[2] = (int)pvVar9;

  iVar12 = FUN_00421677();

  return iVar12;

}
