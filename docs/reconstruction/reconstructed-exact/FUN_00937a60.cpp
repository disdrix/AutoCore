// =============================================================================
// FUN_00937a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00937a60
// Address:   0x00937a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00937a60 @ 0x00937a60
// Stable ID: aa_00937a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, do×1, goto×1, while×1.
//  - Notable callees: FUN_0040aeb0×2, FUN_0040add0, FUN_00755ab0, FUN_00759730, FUN_009329c0, FUN_00937a60, Object_ResolveFromTFID.
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

void FUN_00937a60(int param_1,char param_2)



{

  float fVar1;

  float fVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char cVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  float *pfVar9;

  int *piVar10;

  uint32_t /* width from decompiler */ *puStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  float *pfStack_48;

  int iStack_28;

  int iStack_24;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b2cb7;

  local_c = ExceptionList;

  fVar1 = *(float *)(DAT_00d09874 + 0x68);

  piVar3 = *(int **)(*(int *)(param_1 + 0xe04) + 0xe890);

  ExceptionList = &local_c;

  if (*(char *)(param_1 + 0x1f) != '\0') {

    pfStack_48 = (float *)0x937aa8;

    ExceptionList = &local_c;

    FUN_009329c0();

  }

  piVar10 = (int *)**(int **)(param_1 + 0xab8);

  if (piVar10 != *(int **)(param_1 + 0xab8)) {

    do {

      if (param_2 == '\0') {

        *(float *)(piVar10[2] + 0x1c) = *(float *)(piVar10[2] + 0x1c) - fVar1;

        puVar4 = (uint32_t /* width from decompiler */ *)piVar10[2];

        if (0.0 < (float)puVar4[7]) {

          *(char *)((int)puVar4 + 0x27) =

               (char)(int)(((float)puVar4[7] / (float)puVar4[8]) * DAT_00aaa6f8);

          goto LAB_00937b60;

        }

        if ((void *)*puVar4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          pfStack_48 = (float *)&UNK_00937af6;

          operator_delete((void *)*puVar4);

        }

        *(uint32_t /* width from decompiler */ *)piVar10[2] = 0;

        if ((void *)piVar10[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          pfStack_48 = (float *)&UNK_00937b0f;

          operator_delete((void *)piVar10[2]);

        }

        piVar10[2] = 0;

        piVar6 = (int *)*piVar10;

        if (piVar10 != *(int **)(param_1 + 0xab8)) {

          *(int **)piVar10[1] = piVar6;

          *(int *)(*piVar10 + 4) = piVar10[1];

                    /* WARNING: Subroutine does not return */

          pfStack_48 = (float *)&UNK_00937b36;

          operator_delete(piVar10);

        }

      }

      else {

LAB_00937b60:

        pfStack_48 = (float *)0x937b7a;

        piVar6 = Object_ResolveFromTFID((TFID_16 *)(piVar10[2] + 0x38));

        if ((((piVar6 != (int *)0x0) && (piVar6[0x2b] == 0)) &&

            (iVar7 = (**(code **)(*piVar6 + 0x1cc))(), iVar7 != 0)) &&

           (*(int **)(iVar7 + 8) != (int *)0x0)) {

          iVar8 = (**(code **)(**(int **)(iVar7 + 8) + 0xc))();

          fStack_18 = *(float *)(iVar8 + 0x90);

          fStack_14 = *(float *)(iVar8 + 0x94);

          fStack_10 = *(float *)(iVar8 + 0x98);

          pfVar9 = (float *)(**(code **)(**(int **)(iVar7 + 8) + 0x54))();

          fStack_18 = *pfVar9 + fStack_18;

          iVar8 = (**(code **)(**(int **)(iVar7 + 8) + 0x54))();

          fStack_10 = *(float *)(iVar8 + 8) + fStack_10;

          iVar7 = (**(code **)(**(int **)(iVar7 + 8) + 0x54))();

          fVar2 = *(float *)(iVar7 + 0x24);

          iVar7 = *(int *)(param_1 + 0xde8);

          fStack_18 = *(float *)(iVar7 + 0x210) * fVar2 + fStack_18;

          fStack_10 = *(float *)(iVar7 + 0x218) * fVar2 + fStack_10;

          fStack_14 = fStack_14 + *(float *)(iVar7 + 0x214) * fVar2;

          pfStack_48 = &fStack_18;

          uStack_4c = 0x937c72;

          cVar5 = (**(code **)(*piVar3 + 4))();

          if (cVar5 != '\0') {

            pfStack_48 = (float *)0x937c91;

            FUN_0040aeb0();

            uStack_4 = 0;

            if (param_1 != 0) {

              iStack_24 = iStack_24 + -0x32;

              pfStack_48 = (float *)0x937cb5;

              piVar6 = (int *)FUN_00755ab0();

              pfStack_48 = (float *)0x3f800000;

              uStack_4c = 1;

              uStack_50 = 0;

              iStack_28 = iStack_28 - *piVar6 / 2;

              puStack_60 = (uint32_t /* width from decompiler */ *)piVar10[2];

              uStack_5c = *puStack_60;

              uStack_54 = 0;

              uStack_58 = 0xffffffff;

              FUN_0040aeb0(&puStack_60);

              uStack_4 = uStack_4 & 0xffffff00;

              FUN_00759730(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c),&iStack_28,

                           piVar10[2] + 0x24);

            }

            uStack_4 = 0xffffffff;

            FUN_0040add0();

          }

        }

        piVar6 = (int *)*piVar10;

      }

      piVar10 = piVar6;

    } while (piVar6 != *(int **)(param_1 + 0xab8));

  }

  ExceptionList = local_c;

  return;

}
