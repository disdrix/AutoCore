// =============================================================================
// FUN_006031f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006031f0
// Address:   0x006031f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006031f0 @ 0x006031f0
// Stable ID: aa_006031f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~131 non-empty decompiler lines.
//  - Control keywords: if×17, return×4, do×3, goto×3, while×3.
//  - Notable callees: FUN_0040f840×4, FUN_006031f0×3, memmove×2, FUN_004f1e20, FUN_00603160, FUN_00603580, FUN_00603660, FUN_00603f00.
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

void __thiscall

FUN_006031f0(int *param_1,uint32_t /* width from decompiler */ param_2,uint *param_3,uint *param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,int param_7)



{

  uint *_Dst;

  uint *puVar1;

  uint8_t uVar2;

  uint uVar3;

  void *pvVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  uint *puVar8;

  void *local_3c;

  void *local_20;

  void *local_c;

  uint8_t *puStack_8;

  uint8_t local_4;

  undefined3 uStack_3;

  

  puVar1 = param_4;

  _Dst = param_3;

  puStack_8 = &LAB_009a7f8e;

  local_c = ExceptionList;

  local_4 = 0;

  uStack_3 = 0;

  if (param_3 == (uint *)0x0) {

    return;

  }

  uVar3 = (int)param_4 - (int)param_3 >> 2;

  ExceptionList = &local_c;

  if (uVar3 != 0) {

    ExceptionList = &local_c;

    FUN_00603660();

    iVar5 = param_7;

    puVar8 = _Dst;

    uVar2 = local_4;

    if (_Dst != puVar1) {

      do {

        local_4 = uVar2;

        iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                 (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & *puVar8) * 4) + 4)

        ;

        if (iVar6 == 0) {

LAB_00603294:

          iVar6 = 0;

        }

        else {

          do {

            if (*puVar8 == *(uint *)(iVar6 + 0x10)) {

              if (iVar6 == 0) goto LAB_00603294;

              iVar6 = *(int *)(iVar6 + 8);

              goto LAB_0060329b;

            }

            iVar6 = *(int *)(iVar6 + 0xc);

          } while (iVar6 != 0);

          iVar6 = 0;

        }

LAB_0060329b:

        if (iVar6 != 0) {

          if (*(int *)(iVar6 + 0x3c) == 0) {

            FUN_004f1e20();

          }

          if ((*(int *)(iVar6 + 0x3c) != 0) &&

             (iVar6 = *(int *)(*(int *)(iVar6 + 0x3c) + 0x4dc), iVar5 < iVar6)) {

            iVar5 = iVar6;

            param_7 = iVar6;

          }

        }

        FUN_0040f840();

        local_4 = 1;

        FUN_0040f840();

        local_4 = 2;

        FUN_00603f00();

        if (local_20 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_20);

        }

        local_20 = (void *)0x0;

        local_4 = 0;

        uVar2 = local_4;

        local_4 = 0;

        if (local_3c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_3c);

        }

        puVar8 = puVar8 + 1;

        local_3c = (void *)0x0;

      } while (puVar8 != param_4);

    }

    puVar1 = param_4;

    if (*_Dst == param_1[3]) {

      FUN_006043c0();

      param_1[1] = param_1[1] + 1;

    }

    else {

      piVar7 = (int *)param_1[5];

      if (piVar7 != (int *)param_1[6]) {

        do {

          if (*(uint *)(*piVar7 + 0xc) == *_Dst) {

            if (1 < uVar3) {

              memmove(_Dst,_Dst + 1,((int)param_4 - (int)(_Dst + 1) >> 2) * 4);

              param_4 = puVar1 + -1;

            }

            FUN_0040f840(&param_2);

            FUN_006031f0();

            goto LAB_006034a9;

          }

          piVar7 = piVar7 + 1;

        } while (piVar7 != (int *)param_1[6]);

      }

      pvVar4 = operator_new(0x3c);

      local_4 = 3;

      if (pvVar4 != (void *)0x0) {

        FUN_00603160();

      }

      puVar1 = param_4;

      local_4 = 0;

      if (1 < uVar3) {

        memmove(_Dst,_Dst + 1,((int)param_4 - (int)(_Dst + 1) >> 2) * 4);

        param_4 = puVar1 + -1;

      }

      FUN_0040f840(&param_2);

      FUN_006031f0();

      FUN_00603580();

      *param_1 = *param_1 + 1;

    }

  }

LAB_006034a9:

                    /* WARNING: Subroutine does not return */

  operator_delete(_Dst);

}
