// =============================================================================
// FUN_0058fd30
// -----------------------------------------------------------------------------
// Stable ID: aa_0058fd30
// Address:   0x0058fd30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058fd30 @ 0x0058fd30
// Stable ID: aa_0058fd30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, do×3, while×3, goto×2.
//  - Notable callees: CONCAT22, FUN_004cf860, FUN_004eb4a0, FUN_0058fd30.
//  - Return sites: 4.

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

int * FUN_0058fd30(byte *param_1,float param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                  uint32_t /* width from decompiler */ param_5)



{

  float *pfVar1;

  byte bVar2;

  byte *pbVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  int *unaff_EBX;

  byte *pbVar8;

  uint uVar9;

  bool bVar10;

  int *local_4;

  

  uVar9 = 0;

  do {

    if (DAT_00b04e34 == 0) {

      return (int *)0x0;

    }

    if ((uint)(DAT_00b04e38 - DAT_00b04e34 >> 2) <= uVar9) {

      return (int *)0x0;

    }

    pbVar3 = *(byte **)(DAT_00b04e34 + uVar9 * 4);

    pfVar1 = (float *)(pbVar3 + 0x170);

    pbVar8 = param_1;

    do {

      bVar2 = *pbVar3;

      bVar10 = bVar2 < *pbVar8;

      if (bVar2 != *pbVar8) {

LAB_0058fd94:

        iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);

        goto LAB_0058fd99;

      }

      if (bVar2 == 0) break;

      bVar2 = pbVar3[1];

      bVar10 = bVar2 < pbVar8[1];

      if (bVar2 != pbVar8[1]) goto LAB_0058fd94;

      pbVar3 = pbVar3 + 2;

      pbVar8 = pbVar8 + 2;

    } while (bVar2 != 0);

    iVar4 = 0;

LAB_0058fd99:

    if (iVar4 == 0) {

      iVar4 = uVar9 * 4;

      if (*(int *)(*(int *)(iVar4 + DAT_00b04e34) + 0x100) != 0) {

        if (param_2 != *pfVar1) {

          FUN_004eb4a0(*(int *)(iVar4 + DAT_00b04e34) + 0x100,param_2,param_3,param_4,param_5);

          *(float *)(*(int *)(iVar4 + DAT_00b04e34) + 0x170) = param_2;

        }

        local_4 = (int *)0x0;

        FUN_004cf860(&local_4,*(uint32_t /* width from decompiler */ *)(*(int *)(iVar4 + DAT_00b04e34) + 0x100));

        if (local_4 != (int *)0x0) {

          uVar9 = 0;

          iVar5 = (**(code **)(*local_4 + 0x4c))();

          if (iVar5 != 0) {

            do {

              iVar6 = (**(code **)(*local_4 + 0x50))();

              iVar5 = *(int *)(*(int *)(iVar4 + DAT_00b04e34) + 0x100);

              (**(code **)(**(int **)(iVar6 + uVar9 * 4) + 8))

                        (CONCAT22((short)((uint)iVar5 >> 0x10),*(uint16_t *)(iVar5 + 0x3c)));

              uVar9 = uVar9 + 1;

              uVar7 = (**(code **)(*unaff_EBX + 0x4c))();

            } while (uVar9 < uVar7);

          }

          return local_4;

        }

      }

      return (int *)0x0;

    }

    uVar9 = uVar9 + 1;

  } while( true );

}
