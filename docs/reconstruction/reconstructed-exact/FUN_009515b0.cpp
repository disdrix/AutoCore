// =============================================================================
// FUN_009515b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009515b0
// Address:   0x009515b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009515b0 @ 0x009515b0
// Stable ID: aa_009515b0
// Embedded strings (evidence for future rename):
//   - "Printing info for %f,%f"
//   - "Glom didn\'t exist"
//   - "Glom existed"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×10, return×3, while×2, for×1, do×1.
//  - Notable callees: FUN_007a4480×5, cbid×2, FUN_00402090, FUN_009515b0.
//  - Strings: "Printing info for %f,%f"; "Glom didn\'t exist"; "Glom existed".
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

uint32_t /* width from decompiler */ __fastcall FUN_009515b0(int param_1)



{

  uint8_t uVar1;

  uint8_t uVar2;

  uint8_t uVar3;

  float fVar4;

  float fVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  int iVar12;

  float *pfVar13;

  int iVar14;

  int iVar15;

  uint32_t /* width from decompiler */ uVar16;

  uint32_t /* width from decompiler */ uVar17;

  int iVar18;

  int *piVar19;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  

  if (((*(int *)(param_1 + 0xe98) != 0) && (*(int *)(param_1 + 0xe04) != 0)) &&

     (*(int *)(*(int *)(param_1 + 0xe04) + 0xe898) != 0)) {

    pfVar13 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) +

                                             4 + *(int *)(param_1 + 0xe98)) + 0x1a0))();

    fVar4 = *pfVar13;

    fVar5 = pfVar13[2];

    iVar14 = FUN_00402090(fVar4,fVar5);

    FUN_007a4480(0,"Printing info for %f,%f",(double)fVar4,(double)fVar5);

    piVar19 = *(int **)(iVar14 + 4);

    if (piVar19 != *(int **)(iVar14 + 8)) {

      do {

        iVar15 = (**(code **)(*(int *)(*(int *)(*(int *)(*piVar19 + 4) + 4) + 4 + *piVar19) + 0x1d0)

                 )();

        if (iVar15 != 0) {

          iVar18 = *(int *)(*(int *)(iVar15 + 4) + 4) + iVar15;

          uVar17 = *(uint32_t /* width from decompiler */ *)(iVar18 + 0x158);

          uVar6 = *(uint *)(iVar18 + 0x180);

          fVar4 = *(float *)(iVar18 + 0xbc);

          uVar7 = *(uint32_t /* width from decompiler */ *)(iVar15 + 0x50);

          uVar1 = *(uint8_t *)(iVar15 + 0x4f);

          uVar2 = *(uint8_t *)(iVar15 + 0x4d);

          uVar8 = *(uint32_t /* width from decompiler */ *)(iVar15 + 0xbc);

          uVar3 = *(uint8_t *)(iVar15 + 0x4e);

          uVar9 = *(uint32_t /* width from decompiler */ *)(iVar18 + 0x18);

          if (*(int *)(iVar18 + 0xac) == 0) {

            uStack_40 = 0xffffffff;

          }

          else {

            uStack_40 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar18 + 0xac) + 0x34);

          }

          iVar18 = *(int *)(*(int *)(iVar15 + 4) + 4);

          uVar10 = *(uint32_t /* width from decompiler */ *)(iVar18 + 0x168 + iVar15);

          uVar11 = *(uint32_t /* width from decompiler */ *)(iVar18 + 0x164 + iVar15);

          iVar12 = *(int *)(*(int *)(iVar15 + 4) + 4);

          uVar16 = (**(code **)(*(int *)(iVar18 + iVar15 + 4) + 0x23c))();

          uVar17 = (**(code **)(*(int *)(iVar12 + 4 + iVar15) + 0x160))

                             (uStack_40,uVar9,(byte)(uVar6 >> 3) & 1,uVar3,uVar8,uVar2,uVar1,uVar7,

                              (double)fVar4,uVar17,uVar16);

          FUN_007a4480(0,

                       "%I64d name:%s cbid(%d) Ghost:%u ghosted:%d visible:%d lastghost:%d static:%d loading:%d culllist:%d scale:%f dmg:%d hp:%d"

                       ,uVar11,uVar10,uVar17);

        }

        piVar19 = piVar19 + 1;

      } while (piVar19 != *(int **)(iVar14 + 8));

    }

    if (*(int *)(iVar14 + 0x24) == 0) {

      FUN_007a4480(0,"Glom didn\'t exist");

    }

    else {

      FUN_007a4480(0,"Glom existed");

      iVar15 = *(int *)(iVar14 + 0x24);

      iVar18 = *(int *)(iVar15 + 0x14);

      while( true ) {

        *(int *)(iVar15 + 0x18) = iVar18;

        iVar15 = *(int *)(*(int *)(iVar14 + 0x24) + 0x18);

        if (iVar15 == 0) break;

        iVar15 = *(int *)(iVar15 + 0xc);

        if ((*(int *)(iVar15 + 4) != 0) &&

           (iVar15 = *(int *)(iVar15 + 4),

           iVar15 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar15 + 4) + 4) + 4 + iVar15) + 0x1d0))

                              (), iVar15 != 0)) {

          iVar18 = *(int *)(*(int *)(iVar15 + 4) + 4) + iVar15;

          uVar17 = *(uint32_t /* width from decompiler */ *)(iVar18 + 0x158);

          uVar6 = *(uint *)(iVar18 + 0x180);

          fVar4 = *(float *)(iVar18 + 0xbc);

          uVar7 = *(uint32_t /* width from decompiler */ *)(iVar15 + 0x50);

          uVar1 = *(uint8_t *)(iVar15 + 0x4f);

          uVar2 = *(uint8_t *)(iVar15 + 0x4d);

          uVar8 = *(uint32_t /* width from decompiler */ *)(iVar15 + 0xbc);

          uVar3 = *(uint8_t *)(iVar15 + 0x4e);

          uVar9 = *(uint32_t /* width from decompiler */ *)(iVar18 + 0x18);

          if (*(int *)(iVar18 + 0xac) == 0) {

            uStack_3c = 0xffffffff;

          }

          else {

            uStack_3c = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar18 + 0xac) + 0x34);

          }

          iVar18 = *(int *)(*(int *)(iVar15 + 4) + 4);

          uVar10 = *(uint32_t /* width from decompiler */ *)(iVar18 + 0x168 + iVar15);

          uVar11 = *(uint32_t /* width from decompiler */ *)(iVar18 + 0x164 + iVar15);

          iVar12 = *(int *)(*(int *)(iVar15 + 4) + 4);

          uVar16 = (**(code **)(*(int *)(iVar18 + iVar15 + 4) + 0x23c))();

          uVar17 = (**(code **)(*(int *)(iVar12 + 4 + iVar15) + 0x160))

                             (uStack_3c,uVar9,(byte)(uVar6 >> 3) & 1,uVar3,uVar8,uVar2,uVar1,uVar7,

                              (double)fVar4,uVar17,uVar16);

          FUN_007a4480(0,

                       "%I64d name:%s cbid(%d) Ghost:%u ghosted:%d visible:%d lastghost:%d static:%d loading:%d culllist:%d scale:%f dmg:%d hp:%d"

                       ,uVar11,uVar10,uVar17);

        }

        iVar15 = *(int *)(iVar14 + 0x24);

        if (*(int *)(iVar15 + 0x18) == 0) {

          return 1;

        }

        iVar18 = *(int *)(*(int *)(iVar15 + 0x18) + 4);

        if (iVar18 == 0) {

          return 1;

        }

      }

    }

  }

  return 1;

}
