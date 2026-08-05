// =============================================================================
// FUN_008dc420
// -----------------------------------------------------------------------------
// Stable ID: aa_008dc420
// Address:   0x008dc420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008dc420 @ 0x008dc420
// Stable ID: aa_008dc420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×19, return×1.
//  - Notable callees: FUN_006a3db0×2, CONCAT11, CONCAT13, CONCAT21, FUN_00791f30, FUN_008db100, FUN_008dc420, fcos.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_008dc420(int param_1,float param_2)



{

  float fVar1;

  byte bVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  float *pfVar6;

  float unaff_ESI;

  float10 fVar7;

  uint8_t *puVar8;

  uint8_t *puVar9;

  uint32_t /* width from decompiler */ uStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  int iStack_14;

  uint8_t auStack_10 [4];

  uint8_t auStack_c [12];

  

  if (*(char *)(param_1 + 0x518) != '\0') {

    if (*(int **)(param_1 + 0x5a0) != (int *)0x0) {

      iVar4 = (**(code **)(**(int **)(param_1 + 0x5a0) + 0xe8))();

      if (iVar4 == 0) {

        fStack_1c = *(float *)(param_1 + 0x50c) + param_2;

        piVar5 = *(int **)(param_1 + 0x5a0);

        *(float *)(param_1 + 0x50c) = fStack_1c;

        if ((char)piVar5[0x123] == '\0') {

          fcos((float10)fStack_1c * (float10)DAT_00aaa688);

          bVar2 = FUN_006a3db0();

          uStack_24 = (float)CONCAT13(bVar2,CONCAT21(CONCAT11(bVar2,bVar2),bVar2));

          (**(code **)(*piVar5 + 0x15c))(0,&uStack_24);

          if (*(int **)(param_1 + 0x5a4) != (int *)0x0) {

            cVar3 = (**(code **)(**(int **)(param_1 + 0x5a4) + 0xd0))();

            if (cVar3 != '\0') {

              uStack_24 = (float)(uint)bVar2;

              FUN_006a3db0();

              (**(code **)(**(int **)(param_1 + 0x5a4) + 0x15c))(1,&stack0xffffffd4);

            }

          }

        }

        else {

          uStack_24 = -NAN;

          (**(code **)(*piVar5 + 0x15c))(0,&uStack_24);

          if (*(int **)(param_1 + 0x5a4) != (int *)0x0) {

            cVar3 = (**(code **)(**(int **)(param_1 + 0x5a4) + 0xd0))();

            if (cVar3 != '\0') {

              (**(code **)(**(int **)(param_1 + 0x5a4) + 0x15c))(1,&stack0xffffffd4);

            }

          }

        }

        (**(code **)(**(int **)(param_1 + 0x5a0) + 0x34c))();

        if (*(int **)(param_1 + 0x5a4) != (int *)0x0) {

          cVar3 = (**(code **)(**(int **)(param_1 + 0x5a4) + 0xd0))();

          if (cVar3 != '\0') {

            (**(code **)(**(int **)(param_1 + 0x5a4) + 0x34c))();

          }

        }

        if (_DAT_00aaaa2c < *(float *)(param_1 + 0x50c) * DAT_00aaa688) {

          *(float *)(param_1 + 0x50c) = *(float *)(param_1 + 0x50c) - _DAT_00aaaa28;

          if (*(int **)(param_1 + 0x5a8) != (int *)0x0) {

            cVar3 = (**(code **)(**(int **)(param_1 + 0x5a8) + 0xd0))();

            if (cVar3 == '\0') {

              FUN_008db100();

            }

          }

        }

      }

    }

    if (*(char *)(param_1 + 0x518) != '\0') {

      if (*(int **)(param_1 + 0x5a8) != (int *)0x0) {

        iVar4 = (**(code **)(**(int **)(param_1 + 0x5a8) + 0xe8))();

        if (iVar4 == -1) {

          fStack_1c = *(float *)(param_1 + 0x510) + param_2;

          *(float *)(param_1 + 0x510) = fStack_1c;

          fStack_1c = fStack_1c * DAT_00aaaa24;

          uStack_24 = fStack_1c * DAT_00a0f298;

          iVar4 = (**(code **)(**(int **)(param_1 + 0x5a8) + 0x124))();

          puVar9 = auStack_c;

          fStack_18 = (float)DAT_00d1e81c * (*(float *)(iVar4 + 4) - unaff_ESI) * DAT_00aaa678;

          (**(code **)(**(int **)(param_1 + 0x5a8) + 0x124))();

          fVar1 = fStack_1c;

          puVar8 = auStack_10;

          iVar4 = (**(code **)(**(int **)(param_1 + 0x5a8) + 0x134))();

          fStack_20 = (float)DAT_00d1e81c * (*(float *)(iVar4 + 4) + fVar1) * DAT_00aaa678;

          (**(code **)(**(int **)(param_1 + 0x5a8) + 0x134))(&fStack_1c);

          iVar4 = *(int *)(param_1 + 0x5a8);

          *(uint8_t **)(iVar4 + 0x264) = puVar8;

          *(uint8_t **)(iVar4 + 0x268) = puVar9;

          (**(code **)(**(int **)(param_1 + 0x5a8) + 0x140))(&fStack_18,1);

          piVar5 = (int *)(**(code **)(**(int **)(param_1 + 0x5a8) + 0x140))(&stack0xffffffd8,1);

          iVar4 = *(int *)(param_1 + 0x5a8);

          *(float *)(iVar4 + 0x26c) = fStack_1c - (float)*piVar5;

          *(int *)(iVar4 + 0x270) = iStack_14;

        }

      }

      if ((*(char *)(param_1 + 0x518) != '\0') && (*(int **)(param_1 + 0x5ac) != (int *)0x0)) {

        iVar4 = (**(code **)(**(int **)(param_1 + 0x5ac) + 0xe8))();

        if (iVar4 == -1) {

          fVar7 = (float10)(**(code **)(**(int **)(param_1 + 0x5ac) + 0xf4))();

          if ((float10)g_flZero != fVar7) {

            *(float *)(param_1 + 0x514) = *(float *)(param_1 + 0x514) + param_2;

            fVar7 = (float10)(**(code **)(**(int **)(param_1 + 0x5ac) + 0xf4))();

            iVar4 = *(int *)(param_1 + 0x5ac);

            uStack_24 = *(float *)(iVar4 + 0x168);

            iStack_14 = *(int *)(iVar4 + 0x160) - (int)uStack_24;

            fVar1 = (float)((float10)*(float *)(param_1 + 0x514) / fVar7);

            *(float *)(iVar4 + 0x268) =

                 (float)(*(int *)(iVar4 + 0x164) - *(int *)(iVar4 + 0x16c)) * fVar1 +

                 (float)*(int *)(iVar4 + 0x16c);

            fStack_1c = g_flOne - fVar1;

            *(float *)(iVar4 + 0x264) = (float)iStack_14 * fVar1 + (float)(int)uStack_24;

            iVar4 = (**(code **)(**(int **)(param_1 + 0x5ac) + 0x134))();

            fStack_18 = (float)DAT_00d1e81c * *(float *)(iVar4 + 4) * fStack_20 * DAT_00aaa678;

            pfVar6 = (float *)(**(code **)(**(int **)(param_1 + 0x5ac) + 0x134))(&iStack_14);

            iVar4 = *(int *)(param_1 + 0x5ac);

            *(float *)(iVar4 + 0x26c) = (float)DAT_00d1e818 * fStack_1c * *pfVar6 * DAT_00aaa67c;

            *(int *)(iVar4 + 0x270) = iStack_14;

          }

        }

      }

    }

  }

  FUN_00791f30();

  return;

}
