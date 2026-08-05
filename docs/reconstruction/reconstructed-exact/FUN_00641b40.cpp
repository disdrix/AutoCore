// =============================================================================
// FUN_00641b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00641b40
// Address:   0x00641b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00641b40 @ 0x00641b40
// Stable ID: aa_00641b40
// Embedded strings (evidence for future rename):
//   - "VisualDebugger: ["
//   - ". Its radius is "
//   - " Sending sub geometry of type "
//   - ". Its half extents are "
//   - "Max Extent = "
//   - ". Min Extent =  "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~213 non-empty decompiler lines.
//  - Control keywords: if×10, goto×8, do×1, switch×1, while×1, return×1.
//  - Notable callees: FUN_00631dc0×24, FUN_00631eb0×7, FUN_00631e10×2, FUN_006588b0×2, FUN_0066b6e0×2, FUN_00631da0, FUN_00631f80, FUN_00641900.
//  - Strings: "VisualDebugger: ["; ". Its radius is "; " Sending sub geometry of type "; ". Its half extents are ".
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

void FUN_00641b40(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  undefined *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  char *pcVar11;

  char *pcVar12;

  uint32_t /* width from decompiler */ uVar13;

  char *pcVar14;

  uint32_t /* width from decompiler */ uVar15;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint8_t auStack_20 [28];

  

  FUN_00641900(param_1[1]);

  iVar4 = 0;

  if (0 < param_1[1]) {

    do {

      iVar1 = *(int *)(*param_1 + iVar4 * 4);

      switch(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x54)) {

      case 1:

        iVar1 = FUN_006588b0(auStack_20);

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

        if (1 < DAT_00d030ec) {

          pcVar14 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar14);

          iVar1 = *(int *)(*(int *)(*param_1 + iVar4 * 4) + 0x54);

LAB_00641c6c:

          puVar5 = (&PTR_s_HK_DISPLAY_RECTANGLE_00af4ff4)[iVar1];

          uVar15 = 0x5d;

          pcVar12 = ". Its radius is ";

          pcVar14 = " Sending sub geometry of type ";

          (**(code **)(*DAT_00d030e0 + 4))

                    (" Sending sub geometry of type ",puVar5,". Its radius is ",uVar3,0x5d);

          FUN_00631dc0(pcVar14);

          FUN_00631dc0(puVar5);

          FUN_00631dc0(pcVar12);

          FUN_00631eb0(uVar3);

LAB_00641fa7:

          uVar15 = FUN_00631da0(uVar15);

          FUN_00631f80(uVar15);

        }

        break;

      case 2:

        if (1 < DAT_00d030ec) {

          pcVar14 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar14);

          uVar13 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x68);

          puVar5 = (&PTR_s_HK_DISPLAY_RECTANGLE_00af4ff4)

                   [*(int *)(*(int *)(*param_1 + iVar4 * 4) + 0x54)];

          uVar10 = *(uint32_t /* width from decompiler */ *)(iVar1 + 100);

          uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x60);

          pcVar14 = ". Its half extents are ";

          pcVar12 = " Sending sub geometry of type ";

LAB_00641f20:

          uVar15 = 0x5d;

          (**(code **)(*DAT_00d030e0 + 4))(pcVar12,puVar5,pcVar14,uVar3,uVar10,uVar13,0x5d);

          FUN_00631dc0(pcVar12);

          FUN_00631dc0(puVar5);

LAB_00641f39:

          FUN_00631dc0(pcVar14);

          FUN_00631eb0(uVar3);

          FUN_00631eb0(uVar10);

          FUN_00631eb0(uVar13);

          goto LAB_00641fa7;

        }

        break;

      case 3:

        puVar2 = (uint32_t /* width from decompiler */ *)FUN_00657d50();

        uVar6 = *puVar2;

        uVar7 = puVar2[1];

        uVar9 = puVar2[2];

        puVar2 = (uint32_t /* width from decompiler */ *)FUN_0066b6e0();

        uVar3 = *puVar2;

        uVar10 = puVar2[1];

        uVar13 = puVar2[2];

        if (1 < DAT_00d030ec) {

          pcVar14 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar14);

          puVar5 = (&PTR_s_HK_DISPLAY_RECTANGLE_00af4ff4)

                   [*(int *)(*(int *)(*param_1 + iVar4 * 4) + 0x54)];

          uVar15 = 0x5d;

          pcVar14 = "Max Extent = ";

          pcVar8 = ". Min Extent =  ";

          pcVar12 = " Sending geometry of type ";

          (**(code **)(*DAT_00d030e0 + 4))

                    (" Sending geometry of type ",puVar5,". Min Extent =  ",uVar6,uVar7,uVar9,

                     "Max Extent = ",uVar3,uVar10,uVar13,0x5d);

          FUN_00631dc0(pcVar12);

          FUN_00631dc0(puVar5);

          FUN_00631dc0(pcVar8);

          FUN_00631eb0(uVar6);

          FUN_00631eb0(uVar7);

          FUN_00631eb0(uVar9);

          goto LAB_00641f39;

        }

        break;

      case 4:

        FUN_006588b0(&uStack_40);

        if (1 < DAT_00d030ec) {

          pcVar14 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar14);

          iVar1 = *(int *)(*(int *)(*param_1 + iVar4 * 4) + 0x54);

          pcVar14 = "position : ";

          uVar3 = uStack_40;

          uVar10 = uStack_3c;

          uVar13 = uStack_38;

LAB_00641f13:

          puVar5 = (&PTR_s_HK_DISPLAY_RECTANGLE_00af4ff4)[iVar1];

          pcVar12 = " Sending geometry of type ";

          goto LAB_00641f20;

        }

        break;

      case 5:

        FUN_00656660(&uStack_30);

        if (1 < DAT_00d030ec) {

          pcVar14 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar14);

          iVar1 = *(int *)(*(int *)(*param_1 + iVar4 * 4) + 0x54);

          uVar3 = uStack_30;

          uVar10 = uStack_2c;

          uVar13 = uStack_28;

LAB_00641f0d:

          pcVar14 = "center : ";

          goto LAB_00641f13;

        }

        break;

      case 6:

        uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x50) + 0x10);

        uVar10 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x50) + 4);

        if (1 < DAT_00d030ec) {

          pcVar14 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar14);

          puVar5 = (&PTR_s_HK_DISPLAY_RECTANGLE_00af4ff4)

                   [*(int *)(*(int *)(*param_1 + iVar4 * 4) + 0x54)];

          uVar15 = 0x5d;

          pcVar14 = " triangles.";

          pcVar11 = " vertices and ";

          pcVar8 = ". It has ";

          pcVar12 = " Sending sub geometry of type ";

          (**(code **)(*DAT_00d030e0 + 4))

                    (" Sending sub geometry of type ",puVar5,". It has ",uVar10," vertices and ",

                     uVar3," triangles.",0x5d);

          FUN_00631dc0(pcVar12);

          FUN_00631dc0(puVar5);

          FUN_00631dc0(pcVar8);

          FUN_00631e10(uVar10);

          FUN_00631dc0(pcVar11);

          FUN_00631e10(uVar3);

LAB_00641fa0:

          FUN_00631dc0(pcVar14);

          goto LAB_00641fa7;

        }

        break;

      case 7:

        puVar2 = (uint32_t /* width from decompiler */ *)FUN_0066b6e0();

        if (1 < DAT_00d030ec) {

          pcVar14 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar14);

          iVar1 = *(int *)(*(int *)(*param_1 + iVar4 * 4) + 0x54);

          uVar3 = *puVar2;

          uVar10 = puVar2[1];

          uVar13 = puVar2[2];

          goto LAB_00641f0d;

        }

        break;

      case 8:

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x80);

        if (1 < DAT_00d030ec) {

          pcVar14 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar14);

          iVar1 = *(int *)(*(int *)(*param_1 + iVar4 * 4) + 0x54);

          goto LAB_00641c6c;

        }

        break;

      default:

        if (-1 < DAT_00d030ec) {

          pcVar14 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar14);

          pcVar14 = "ERROR: ";

          (**(code **)(*DAT_00d030e0 + 4))("ERROR: ");

          FUN_00631dc0(pcVar14);

          uVar15 = 0x5d;

          pcVar14 = "Trying to send unknown geometry type";

          (**(code **)(*DAT_00d030e0 + 4))("Trying to send unknown geometry type",0x5d);

          goto LAB_00641fa0;

        }

      }

      FUN_006562d0(*(uint32_t /* width from decompiler */ *)(*param_1 + iVar4 * 4));

      iVar4 = iVar4 + 1;

    } while (iVar4 < param_1[1]);

  }

  return;

}
