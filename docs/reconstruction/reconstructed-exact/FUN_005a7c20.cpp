// =============================================================================
// FUN_005a7c20
// -----------------------------------------------------------------------------
// Stable ID: aa_005a7c20
// Address:   0x005a7c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a7c20 @ 0x005a7c20
// Stable ID: aa_005a7c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~184 non-empty decompiler lines.
//  - Control keywords: if×15, do×5, while×5, return×1.
//  - Notable callees: FUN_00989e00×4, FUN_007a4480×3, FUN_00403450×2, _eh_vector_constructor_iterator_×2, FUN_00586060, FUN_005a7c20, FUN_0076cec0, free.
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

uint32_t /* width from decompiler */ __thiscall FUN_005a7c20(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  char *pcVar6;

  int iVar7;

  uint8_t *puVar8;

  int iVar9;

  int iVar10;

  uint32_t /* width from decompiler */ uVar11;

  int *piVar12;

  char *_Memory;

  uint32_t /* width from decompiler */ *puVar13;

  bool bVar14;

  uint32_t /* width from decompiler */ uStack_15d;

  uint8_t auStack_158 [68];

  char *pcStack_114;

  char acStack_110 [128];

  char *pcStack_90;

  char acStack_8c [128];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a642c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00586060(param_2);

  iVar4 = *(int *)(*(int *)(param_1 + 4) + 4);

  if (((*(int *)(param_1 + 0xb0 + iVar4) == 0) &&

      (iVar4 = (**(code **)(*(int *)(param_1 + 4 + iVar4) + 0x1cc))(), iVar4 != 0)) &&

     (iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1cc))(),

     *(int *)(iVar4 + 8) != 0)) {

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1cc))();

    (**(code **)(**(int **)(iVar4 + 8) + 0x48))();

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1cc))();

    (**(code **)(**(int **)(iVar4 + 8) + 0x18))();

  }

  iVar4 = *(int *)(*(int *)(param_1 + 4) + 4);

  if (*(int *)(*(int *)(param_1 + 0xac + iVar4) + 0x3c) == 0) {

    uVar11 = 0;

  }

  else {

    iVar4 = *(int *)(*(int *)(param_1 + 0xac + iVar4) + 0x3c);

    cVar3 = *(char *)(iVar4 + 0x4cd) + *(char *)(iVar4 + 0x4cc);

    iVar4 = (int)cVar3;

    *(char *)(param_1 + 0xb0) = cVar3;

    piVar5 = operator_new__(iVar4 * 0x14c + 4);

    uStack_4 = 0;

    if (piVar5 == (int *)0x0) {

      piVar12 = (int *)0x0;

    }

    else {

      piVar12 = piVar5 + 1;

      *piVar5 = iVar4;

      _eh_vector_constructor_iterator_(piVar12,0x14c,iVar4,FUN_00764030,FUN_00763f60);

    }

    cVar3 = '\0';

    uStack_4 = 0xffffffff;

    *(int **)(param_1 + 0xe8) = piVar12;

    if ('\0' < *(char *)(param_1 + 0xb0)) {

      do {

        if ((int)cVar3 <

            (int)(uint)*(byte *)(*(int *)(*(int *)(param_1 + 0xac +

                                                  *(int *)(*(int *)(param_1 + 4) + 4)) + 0x3c) +

                                0x4cc)) {

          pcStack_114 = acStack_110;

          (*(code *)PTR_FUN_00af8c9c)();

          FUN_00403450();

          _Memory = pcStack_114;

          iVar4 = 1 - (int)pcStack_114;

          pcVar6 = pcStack_114;

          do {

            cVar1 = *pcVar6;

            pcVar6[(int)&uStack_15d + iVar4] = cVar1;

            pcVar6 = pcVar6 + 1;

          } while (cVar1 != '\0');

          bVar14 = _Memory == acStack_110;

        }

        else {

          pcStack_90 = acStack_8c;

          (*(code *)PTR_FUN_00af8c9c)();

          FUN_00403450();

          _Memory = pcStack_90;

          iVar4 = 1 - (int)pcStack_90;

          pcVar6 = pcStack_90;

          do {

            cVar1 = *pcVar6;

            pcVar6[(int)&uStack_15d + iVar4] = cVar1;

            pcVar6 = pcVar6 + 1;

          } while (cVar1 != '\0');

          bVar14 = _Memory == acStack_8c;

        }

        if (!bVar14) {

          free(_Memory);

        }

        if ((uStack_15d._1_1_ != '\0') && (uStack_15d._1_1_ != ' ')) {

          puVar2 = &uStack_15d;

          do {

            puVar13 = puVar2;

            puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar13 + 1);

          } while (*(char *)((int)puVar13 + 1) != '\0');

          *(uint32_t /* width from decompiler */ *)((int)puVar13 + 1) = DAT_00a28904;

          *(uint8_t *)((int)puVar13 + 5) = DAT_00a28908;

          FUN_00989e00();

          iVar4 = cVar3 * 0x14c;

          iVar7 = (**(code **)(*(int *)(iVar4 + *(int *)(param_1 + 0xe8)) + 0x5c))();

          if (iVar7 < 0) {

            FUN_0076cec0();

            vog_LogMessage();

          }

          else {

            *(uint8_t *)(*(int *)(param_1 + 0xe8) + iVar4 + 0x13a) = 1;

            (**(code **)(*(int *)(iVar4 + *(int *)(param_1 + 0xe8)) + 0x18))();

            (**(code **)(*(int *)(*(int *)(param_1 + 0xe8) + iVar4) + 0x14))();

            puVar8 = operator_new(0xc);

            *puVar8 = 1;

            *(int *)(puVar8 + 4) = *(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1;

            *(uint8_t **)(*(int *)(param_1 + 0xe8) + iVar4 + 0x78) = puVar8;

            piVar5 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

            if ((piVar5 != (int *)0x0) && (iVar7 = (**(code **)(*piVar5 + 0x1d4))(), iVar7 != 0)) {

              (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x1d4)

              )();

              (**(code **)(*(int *)(*(int *)(param_1 + 0xe8) + iVar4) + 0x1c))();

            }

          }

        }

        cVar3 = cVar3 + '\x01';

      } while (cVar3 < *(char *)(param_1 + 0xb0));

    }

    iVar7 = (int)*(char *)(param_1 + 0xb0) / 2;

    *(int *)(param_1 + 0xf0) = iVar7;

    iVar4 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

    if ((*(char *)(iVar4 + 0x4ce) == '\x01') || (*(char *)(iVar4 + 0x4ce) == '\x03')) {

      piVar5 = operator_new__(iVar7 * 0x3e4 + 4);

      uStack_4 = 1;

      if (piVar5 == (int *)0x0) {

        piVar12 = (int *)0x0;

      }

      else {

        piVar12 = piVar5 + 1;

        *piVar5 = iVar7 * 3;

        _eh_vector_constructor_iterator_(piVar12,0x14c,iVar7 * 3,FUN_00764030,FUN_00763f60);

      }

      iVar4 = 0;

      uStack_4 = 0xffffffff;

      *(int **)(param_1 + 0xec) = piVar12;

      if (0 < *(int *)(param_1 + 0xf0)) {

        do {

          FUN_00989e00();

          iVar7 = iVar4 * 0x3e4;

          iVar9 = (**(code **)(*(int *)(iVar7 + *(int *)(param_1 + 0xec)) + 0x5c))();

          if (iVar9 < 0) {

            FUN_007a4480();

          }

          FUN_00989e00();

          iVar9 = (**(code **)(*(int *)(iVar7 + 0x14c + *(int *)(param_1 + 0xec)) + 0x5c))();

          if (iVar9 < 0) {

            FUN_007a4480();

          }

          FUN_00989e00();

          iVar9 = (iVar4 * 3 + 2) * 0x14c;

          iVar10 = (**(code **)(*(int *)(*(int *)(param_1 + 0xec) + iVar9) + 0x5c))();

          if (iVar10 < 0) {

            FUN_007a4480();

          }

          *(uint8_t *)(iVar7 + 0x13a + *(int *)(param_1 + 0xec)) = 1;

          *(uint8_t *)(iVar7 + 0x286 + *(int *)(param_1 + 0xec)) = 1;

          *(uint8_t *)(iVar7 + 0x3d2 + *(int *)(param_1 + 0xec)) = 1;

          (**(code **)(*(int *)(*(int *)(param_1 + 0xec) + iVar7) + 0x18))();

          (**(code **)(*(int *)(iVar7 + 0x14c + *(int *)(param_1 + 0xec)) + 0x18))();

          (**(code **)(*(int *)(*(int *)(param_1 + 0xec) + iVar9) + 0x18))();

          iVar4 = iVar4 + 1;

        } while (iVar4 < *(int *)(param_1 + 0xf0));

      }

    }

    uVar11 = 1;

  }

  ExceptionList = pvStack_c;

  return uVar11;

}
