// =============================================================================
// FUN_0058cd60
// -----------------------------------------------------------------------------
// Stable ID: aa_0058cd60
// Address:   0x0058cd60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058cd60 @ 0x0058cd60
// Stable ID: aa_0058cd60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~222 non-empty decompiler lines.
//  - Control keywords: if×28, goto×8, while×4, do×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_004badf0×2, FUN_005130e0×2, FUN_004294f0, FUN_004bade0, FUN_005134e0, FUN_005714e0, FUN_005749d0.
//  - Return sites: 1.

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

void FUN_0058cd60(int *param_1,int param_2,int param_3,int *param_4,float *param_5,float param_6,

                 int param_7,int param_8,uint32_t /* width from decompiler */ param_9,char param_10,char param_11)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ *puVar8;

  short sVar9;

  int *piVar10;

  uint32_t /* width from decompiler */ uVar11;

  char cStack_6b;

  char local_6a;

  uint8_t uStack_69;

  int local_68;

  int *local_64;

  int *piStack_60;

  int iStack_5c;

  uint32_t /* width from decompiler */ local_58;

  int local_54;

  float local_50 [2];

  uint32_t /* width from decompiler */ *local_48;

  uint32_t /* width from decompiler */ local_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a576a;

  pvStack_1c = ExceptionList;

  local_30 = *param_5;

  local_2c = param_5[1];

  local_28 = param_5[2];

  local_24 = param_5[3];

  ExceptionList = &pvStack_1c;

  local_48 = (uint32_t /* width from decompiler */ *)FUN_0058d9c0();

  *(uint8_t *)((int)local_48 + 0x29) = 1;

  local_48[1] = local_48;

  *local_48 = local_48;

  local_48[2] = local_48;

  local_44 = 0;

  local_6a = param_7 != 0;

  local_14 = 0;

  local_64 = (int *)0x0;

  local_58 = 0;

  local_68 = param_2;

  FUN_004bade0();

  local_54 = *(int *)(*(int *)(param_3 + 0xe4e8) + 0x20);

  if (local_54 == 0) {

    FUN_004badf0();

    uVar11 = *local_48;

  }

  else {

    FUN_004294f0();

    iVar5 = FUN_004022a0(&local_58,&local_64);

    piVar7 = local_64;

    while (local_64 = piVar7, iVar5 == 0) {

      if ((((((piVar7 != (int *)0x0) && (piVar7 != param_4)) &&

            (cVar3 = (**(code **)(*piVar7 + 0x198))(), cVar3 == '\0')) &&

           (((piVar10 = piVar7 + 0x58, piStack_60 = piVar10, piVar7[0x58] != *param_1 ||

             (piVar7[0x59] != param_1[1])) || ((char)piVar7[0x5a] != (char)param_1[2])))) &&

          ((param_10 != '\0' || (cVar3 = FUN_005134e0(), cVar3 == '\0')))) &&

         (((uint)piVar7[0x5f] >> 2 & 1) == 0)) {

        iStack_5c = *(int *)(piVar7[0x2a] + 0x38);

        cStack_6b = '\0';

        if (iStack_5c == 0xe) {

          iVar5 = __RTDynamicCast(piVar7,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                  &CVOGVehicle::RTTI_Type_Descriptor,0);

          if (((iVar5 == 0) ||

              (iVar6 = *(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xb0 + iVar5), iVar6 == 0)) ||

             (iVar6 = TFID_EqualsObjectId((void *)(iVar6 + 0x160),param_1), (char)iVar6 == '\0')) {

            piVar10 = piStack_60;

            cVar3 = cStack_6b;

            if ((*(char *)(iVar5 + 0x2ac) != '\0') &&

               (cVar4 = FUN_005130e0(1), piVar10 = piStack_60, cVar3 = cStack_6b, cVar4 != '\0')) {

              fStack_40 = (float)piVar7[0x20];

              fStack_3c = (float)piVar7[0x21];

              fStack_38 = (float)piVar7[0x22];

              fStack_34 = (float)piVar7[0x23];

              cStack_6b = '\x01';

              cVar3 = cStack_6b;

            }

            goto LAB_0058cfd8;

          }

        }

        else {

          cVar3 = FUN_005130e0(1);

          if (cVar3 != '\0') {

            fStack_40 = (float)piVar7[0x20];

            fStack_3c = (float)piVar7[0x21];

            fStack_38 = (float)piVar7[0x22];

            fStack_34 = (float)piVar7[0x23];

LAB_0058cfd8:

            if (param_8 == 2) {

              cVar3 = (**(code **)(*param_4 + 0x298))(piVar7);

joined_r0x0058d05a:

              if (cVar3 != '\0') goto LAB_0058d1d1;

            }

            else if (param_8 == 1) {

              cVar3 = (**(code **)(*param_4 + 0x298))(piVar7);

              if (cVar3 == '\0') goto LAB_0058d1d1;

            }

            else if (param_8 == 0xb) {

              iVar5 = (**(code **)(*param_4 + 0x210))(0);

              iVar6 = (**(code **)(*piVar7 + 0x210))(0);

              if (iVar5 != 0) {

                if (iVar5 == iVar6) goto LAB_0058d1d1;

                if (*(int *)(iVar5 + 0xcb0) != 0) {

                  cVar3 = FUN_005749d0(iVar6);

                  goto joined_r0x0058d05a;

                }

              }

            }

            else {

              if (param_8 == 3) {

                if ((iStack_5c != 0x12) && (iStack_5c != 0x14)) goto LAB_0058d1d9;

              }

              else if (param_8 == 6) {

                if (cVar3 == '\0') goto LAB_0058d1d9;

                fStack_34 = fStack_34 - local_24;

                fStack_40 = fStack_40 - local_30;

                fStack_38 = fStack_38 - local_28;

                fStack_3c = fStack_3c - local_2c;

                local_50[0] = fStack_40 * fStack_40 + fStack_38 * fStack_38 + fStack_3c * fStack_3c;

                piStack_60 = (int *)SQRT(local_50[0]);

                iVar5 = (**(code **)(*param_4 + 0x1dc))();

                if (((iVar5 != 0) && (iStack_5c != 0x42)) &&

                   ((iVar5 = (**(code **)(*param_4 + 0x1dc))(), *(int *)(iVar5 + 0x250) != 0 &&

                    (iVar5 = (**(code **)(*param_4 + 0x1dc))(),

                    *(int *)(*(int *)(iVar5 + 0x250) + 0x2b0) != 0)))) {

                  uStack_69 = 0;

                  cStack_6b = '\0';

                  (**(code **)(*param_4 + 0x1dc))();

                  cVar3 = FUN_005714e0(piVar7,&uStack_69,&cStack_6b,1,0xffffffff);

                  if (cVar3 == '\0') goto LAB_0058d1d1;

                }

                if ((float)piStack_60 < param_6) {

                  piVar7 = param_1 + (short)local_68 * 4;

                  local_68 = local_68 + 1;

                  *piVar7 = *piVar10;

                  piVar7[1] = piVar10[1];

                  piVar7[2] = piVar10[2];

                  piVar7[3] = piVar10[3];

                  if ((local_6a != '\0') && (param_7 = param_7 + -1, param_7 < 1)) break;

                }

              }

LAB_0058d1d1:

              if ((short)local_68 == 99) break;

            }

          }

        }

      }

LAB_0058d1d9:

      iVar5 = FUN_004022a0(&local_58,&local_64);

      piVar7 = local_64;

    }

    if (*(char *)(local_54 + 0x28) != '\0') {

      *(uint8_t *)(local_54 + 0x28) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(local_54 + 4));

    }

    FUN_004badf0();

    if ((param_11 == '\0') ||

       (puVar8 = (uint32_t /* width from decompiler */ *)*local_48, iVar5 = local_68, puVar8 == local_48)) {

      sVar9 = (short)local_68;

    }

    else {

      do {

        piVar7 = param_1 + (short)iVar5 * 4;

        *piVar7 = puVar8[6];

        piVar7[1] = puVar8[7];

        piVar7[2] = puVar8[8];

        sVar9 = (short)(iVar5 + 1);

        piVar7[3] = puVar8[9];

        if ((sVar9 == 99) || ((local_6a != '\0' && (param_7 = param_7 + -1, param_7 < 1)))) break;

        if (*(char *)((int)puVar8 + 0x29) == '\0') {

          puVar1 = (uint32_t /* width from decompiler */ *)puVar8[2];

          if (*(char *)((int)puVar1 + 0x29) == '\0') {

            cVar3 = *(char *)((int)*puVar1 + 0x29);

            puVar8 = puVar1;

            puVar1 = (uint32_t /* width from decompiler */ *)*puVar1;

            while (cVar3 == '\0') {

              cVar3 = *(char *)((int)*puVar1 + 0x29);

              puVar8 = puVar1;

              puVar1 = (uint32_t /* width from decompiler */ *)*puVar1;

            }

          }

          else {

            cVar3 = *(char *)((int)puVar8[1] + 0x29);

            puVar2 = (uint32_t /* width from decompiler */ *)puVar8[1];

            puVar1 = puVar8;

            while ((puVar8 = puVar2, cVar3 == '\0' && (puVar1 == (uint32_t /* width from decompiler */ *)puVar8[2]))) {

              cVar3 = *(char *)((int)puVar8[1] + 0x29);

              puVar2 = (uint32_t /* width from decompiler */ *)puVar8[1];

              puVar1 = puVar8;

            }

          }

        }

        iVar5 = iVar5 + 1;

      } while (puVar8 != local_48);

    }

    param_1 = param_1 + sVar9 * 4;

    *param_1 = DAT_009d4d28;

    param_1[1] = DAT_009d4d2c;

    param_1[2] = DAT_009d4d30;

    param_1[3] = DAT_009d4d34;

    uVar11 = *local_48;

  }

  local_14 = 0xffffffff;

  FUN_0058df60(local_50,uVar11,local_48);

                    /* WARNING: Subroutine does not return */

  operator_delete(local_48);

}
