// =============================================================================
// FUN_00858080
// -----------------------------------------------------------------------------
// Stable ID: aa_00858080
// Address:   0x00858080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00858080 @ 0x00858080
// Stable ID: aa_00858080
// Embedded strings (evidence for future rename):
//   - "Incorrect minimap texture format for %s."
//   - "C:\\vog\\1_code\\vog_14_117_branch\\appClient\\WndMiniMap.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~221 non-empty decompiler lines.
//  - Control keywords: if×23, while×5, do×3, return×2, for×1, goto×1.
//  - Notable callees: CONCAT44×2, FUN_0096bb40×2, FUN_0096be60×2, FUN_0096f0e0×2, ROUND×2, FUN_0040ead0, FUN_0076cec0, FUN_00858080.
//  - Strings: "Incorrect minimap texture format for %s."; "C:\\vog\\1_code\\vog_14_117_branch\\appClient\\WndMiniMap.cpp".
//  - Return sites: 2.

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

void FUN_00858080(void)



{

  uint8_t uVar1;

  byte bVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  int *piVar8;

  int iVar9;

  byte *pbVar10;

  uint uVar11;

  int iVar12;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint8_t *puVar13;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ uVar14;

  uint32_t /* width from decompiler */ uVar15;

  int iStack_60;

  int iStack_5c;

  int iStack_58;

  int iStack_54;

  int iStack_4c;

  uint uStack_44;

  uint uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint64_t uStack_38;

  uint8_t auStack_30 [4];

  uint32_t /* width from decompiler */ uStack_2c;

  int iStack_28;

  int iStack_24;

  void *pvStack_1c;

  void *pvStack_18;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b0fb7;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  piVar3 = (int *)(**(code **)(*unaff_EDI + 700))();

  iVar4 = (**(code **)(*unaff_EDI + 0x2dc))(*(uint32_t /* width from decompiler */ *)(*piVar3 + 0x24));

  if (iVar4 == 0) {

    uVar5 = FUN_0076cec0((int)&uStack_38 + 4,"Incorrect minimap texture format for %s.",

                         DAT_00d1b644 + 0xb4);

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\appClient\\WndMiniMap.cpp",0x354,2,uVar5);

    ExceptionList = pvStack_18;

    return;

  }

  puVar6 = operator_new(4);

  uStack_38 = CONCAT44(puVar6,(uint)uStack_38);

  if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar6 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar6 = 0;

  }

  puStack_10 = (uint8_t *)0xffffffff;

  unaff_EDI[0x172] = (int)puVar6;

  uVar5 = *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b644 + 0xe4f8) + 0x10);

  iVar4 = *(int *)(*(int *)(DAT_00d1b644 + 0xe4f8) + 0x14);

  iVar7 = (**(code **)(*unaff_EDI + 700))();

  if (iVar7 != 0) {

    piVar3 = (int *)(**(code **)(*unaff_EDI + 700))();

    iVar7 = (**(code **)(*unaff_EDI + 0x2dc))(*(uint32_t /* width from decompiler */ *)(*piVar3 + 0x24));

    if (iVar7 != 0) {

      piVar3 = (int *)(**(code **)(*unaff_EDI + 700))();

      piVar3 = *(int **)(*piVar3 + 0x10);

      piVar8 = (int *)(**(code **)(*unaff_EDI + 700))();

      iVar4 = *piVar8;

      uVar15 = 1;

      uVar14 = 1;

      uVar5 = (**(code **)(*piVar3 + 0x34))(piVar3,1,1,0);

      FUN_0096f0e0(0x15,iVar4 + 0x1c,uVar5,piVar3,uVar14,uVar15);

      (**(code **)(*unaff_EDI + 700))();

      goto LAB_008581e7;

    }

  }

  uStack_2c = uVar5;

  iStack_28 = iVar4;

  FUN_0096f0e0(0x15,&uStack_2c,1,1,1,0);

LAB_008581e7:

  puVar13 = (uint8_t *)0x0;

  iVar4 = (**(code **)(*unaff_EDI + 700))();

  if (iVar4 == 0) {

    piVar3 = (int *)unaff_EDI[0x172];

  }

  else {

    piVar3 = (int *)(**(code **)(*unaff_EDI + 700))();

  }

  bVar2 = (**(code **)(**(int **)(*piVar3 + 0x10) + 0x34))(*(int **)(*piVar3 + 0x10));

  if (bVar2 != 0) {

    uStack_40 = (uint)bVar2;

    uStack_44 = 0;

    do {

      iVar4 = (**(code **)(*unaff_EDI + 700))();

      if ((iVar4 == 0) || (piVar3 = (int *)(**(code **)(*unaff_EDI + 700))(), *piVar3 == 0)) {

        iStack_60 = 0;

      }

      else {

        iStack_60 = FUN_0096be60(uStack_44,0,0,4);

      }

      if (*(int *)unaff_EDI[0x172] == 0) {

        iStack_5c = 0;

      }

      else {

        iStack_5c = FUN_0096be60(uStack_44,0,0,

                                 (*(uint *)(*(int *)unaff_EDI[0x172] + 0x2c) & 0x80) != 0);

      }

      iVar4 = *(int *)unaff_EDI[0x172];

      iVar7 = 2;

      uVar11 = uStack_44;

      if ((int)uStack_44 < 0) {

        uVar11 = -uStack_44;

      }

      iStack_58 = 1;

      while( true ) {

        if ((uVar11 & 1) != 0) {

          iStack_58 = iStack_58 * iVar7;

        }

        uVar11 = uVar11 >> 1;

        if (uVar11 == 0) break;

        iVar7 = iVar7 * iVar7;

      }

      if ((int)uStack_44 < 0) {

        iStack_58 = (int)(1 / (longlong)iStack_58);

      }

      uStack_38._0_4_ = (uint)(longlong)ROUND((float10)*(int *)(iVar4 + 0x1c) / (float10)iStack_58);

      iVar7 = (uint)uStack_38;

      iVar9 = 2;

      uVar11 = uStack_44;

      if ((int)uStack_44 < 0) {

        uVar11 = -uStack_44;

      }

      iStack_58 = 1;

      while( true ) {

        if ((uVar11 & 1) != 0) {

          iStack_58 = iStack_58 * iVar9;

        }

        uVar11 = uVar11 >> 1;

        if (uVar11 == 0) break;

        iVar9 = iVar9 * iVar9;

      }

      if ((int)uStack_44 < 0) {

        iStack_58 = (int)(1 / (longlong)iStack_58);

      }

      uStack_38 = (longlong)ROUND((float10)*(int *)(iVar4 + 0x20) / (float10)iStack_58);

      iVar9 = (uint)uStack_38;

      if (*(int *)unaff_EDI[0x172] == 0) {

        iStack_54 = 0;

      }

      else {

        iStack_54 = *(int *)(*(int *)unaff_EDI[0x172] + 0x40);

      }

      uVar11 = FUN_0040ead0(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x24));

      uVar11 = uVar11 >> 3;

      uStack_38 = CONCAT44(uStack_38._4_4_,uVar11);

      iStack_4c = 0;

      if (0 < iVar7) {

        iVar4 = 0;

        do {

          iVar12 = 0;

          if (0 < iVar9) {

            iStack_58 = 0;

            do {

              if ((iStack_60 == 0) || (iStack_5c == 0)) {

                *puVar13 = 0;

                puVar13[1] = 0;

                puVar13[2] = 0;

                puVar13[3] = 0xff;

              }

              else {

                if ((char)((uint)unaff_ESI >> 0x18) == '\0') {

                  pbVar10 = (byte *)(iVar4 + iStack_58 + iStack_60);

                }

                else {

                  iStack_28 = iStack_4c;

                  iStack_24 = iVar12;

                  piVar3 = (int *)(**(code **)(*unaff_EDI + 700))();

                  uVar5 = *(uint32_t /* width from decompiler */ *)(*piVar3 + 0x40);

                  piVar3 = (int *)(**(code **)(*unaff_EDI + 700))();

                  puVar6 = (uint32_t /* width from decompiler */ *)

                           FUN_0099b230(auStack_30,*(uint32_t /* width from decompiler */ *)(*piVar3 + 0x24),&iStack_28,

                                        iStack_60,uVar5);

                  uStack_3c = *puVar6;

                  pbVar10 = (byte *)&uStack_3c;

                }

                puVar13 = (uint8_t *)(iVar4 + iStack_58 + iStack_5c);

                uVar1 = (uint8_t)

                        ((ulonglong)

                         ((longlong)(int)((uint)pbVar10[2] + (uint)pbVar10[1] + (uint)*pbVar10) *

                         0x2aaaaaab) >> 0x20);

                *puVar13 = uVar1;

                puVar13[1] = uVar1;

                puVar13[2] = uVar1;

                puVar13[3] = pbVar10[3];

              }

              iStack_58 = iStack_58 + iStack_54;

              iVar12 = iVar12 + 1;

            } while (iVar12 < iVar9);

            uVar11 = (uint)uStack_38;

          }

          iVar4 = iVar4 + uVar11;

          iStack_4c = iStack_4c + 1;

        } while (iStack_4c < iVar7);

      }

      if (*(int *)unaff_EDI[0x172] != 0) {

        FUN_0096bb40(uStack_44);

      }

      iVar4 = (**(code **)(*unaff_EDI + 700))();

      if ((iVar4 != 0) && (piVar3 = (int *)(**(code **)(*unaff_EDI + 700))(), *piVar3 != 0)) {

        FUN_0096bb40(uStack_44);

      }

      uStack_44 = uStack_44 + 1;

      uStack_40 = uStack_40 - 1;

    } while (uStack_40 != 0);

  }

  ExceptionList = pvStack_1c;

  return;

}
