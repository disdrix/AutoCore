// =============================================================================
// FUN_0056db30
// -----------------------------------------------------------------------------
// Stable ID: aa_0056db30
// Address:   0x0056db30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056db30 @ 0x0056db30
// Stable ID: aa_0056db30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_004e9aa0, FUN_004ea350, FUN_0056db30.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool __thiscall FUN_0056db30(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  float fVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  char cVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  uint uVar10;

  bool bVar11;

  float10 fVar12;

  float local_34;

  uint8_t auStack_1c [4];

  void *pvStack_18;

  int iStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a4ddf;

  pvStack_c = ExceptionList;

  local_34 = _DAT_009d2fc8;

  bVar11 = false;

  ExceptionList = &pvStack_c;

  uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1a0))();

  pvStack_18 = (void *)0x0;

  iStack_14 = 0;

  uStack_10 = 0;

  uStack_4 = 0;

  FUN_004ea350(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1),uVar6,param_1[0x3a],

               auStack_1c,0,1);

  uVar10 = 0;

  do {

    if ((pvStack_18 == (void *)0x0) || ((uint)(iStack_14 - (int)pvStack_18 >> 2) <= uVar10)) {

      if (pvStack_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvStack_18);

      }

      ExceptionList = pvStack_c;

      return *param_4 != 0;

    }

    iVar9 = *(int *)((int)pvStack_18 + uVar10 * 4);

    iVar7 = (**(code **)(**(int **)(*(int *)(param_1[1] + 4) + 0xb0 + (int)param_1) + 0x1c8))();

    if (iVar9 != iVar7) {

      cVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x198))();

      if ((cVar5 == '\0') &&

         (iVar7 = *(int *)(*(int *)(iVar9 + 4) + 4),

         (*(uint *)(iVar7 + 0x180 + iVar9) >> 10 & 1) == 0)) {

        cVar5 = (**(code **)(**(int **)(*(int *)(param_1[1] + 4) + 0xb0 + (int)param_1) + 0x298))

                          (iVar7 + iVar9 + 4);

        if (cVar5 != '\0') {

          if (bVar11) {

            iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x214))()

            ;

            if (iVar7 == 0) goto LAB_0056dd6a;

          }

          piVar2 = *(int **)(*(int *)(param_1[1] + 4) + 0xb0 + (int)param_1);

          iVar7 = param_1[0x37];

          iVar3 = param_1[0x3a];

          iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x19c))

                            ();

          uVar4 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x34);

          iVar8 = (**(code **)(*piVar2 + 0x210))(0);

          fVar12 = (float10)FUN_004e9aa0(uVar6,uVar4,iVar3,iVar9,param_3,iVar7,iVar8 != 0);

          fVar1 = (float)fVar12;

          if ((fVar1 != g_flZero) && (fVar1 < local_34)) {

            cVar5 = (**(code **)(*param_1 + 0x58))

                              (*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[1] + 4) + 0xb0 + (int)param_1),

                               *(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9,fVar1,0);

            if (cVar5 != '\0') {

              *param_4 = *(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9;

              iVar9 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x214))

                                ();

              bVar11 = iVar9 != 0;

              local_34 = fVar1;

            }

          }

        }

      }

    }

LAB_0056dd6a:

    uVar10 = uVar10 + 1;

  } while( true );

}
