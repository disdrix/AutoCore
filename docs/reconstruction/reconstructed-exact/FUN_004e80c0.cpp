// =============================================================================
// FUN_004e80c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e80c0
// Address:   0x004e80c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004e80c0 @ 0x004e80c0
// Stable ID: aa_004e80c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×11, return×3, do×3, while×3, goto×2.
//  - Notable callees: FUN_004e7130×3, CONCAT31, FUN_00404840, FUN_0040fb90, FUN_004e80c0, _eh_vector_constructor_iterator_, _eh_vector_destructor_iterator_.
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

void __thiscall FUN_004e80c0(uint8_t *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  uint uVar4;

  int *piVar5;

  uint uVar6;

  uint8_t *puVar7;

  int local_158;

  uint8_t local_154 [4];

  int *local_150;

  int local_14c [2];

  uint8_t local_144 [4];

  int local_140 [2];

  uint8_t local_138 [300];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a25a1;

  local_c = ExceptionList;

  if (*(uint *)(param_1 + 8) < 2) {

    return;

  }

  ExceptionList = &local_c;

  piVar3 = (int *)FUN_0040fb90();

  uVar4 = 0;

  local_14c[0] = 0;

  local_4 = 0;

  local_150 = piVar3;

  _eh_vector_constructor_iterator_(local_144,0xc,0x1a,FUN_004023f0,FUN_00403430);

  iVar1 = *(int *)(param_1 + 8);

  local_4 = CONCAT31(local_4._1_3_,1);

  do {

    if (iVar1 == 0) {

      if (1 < uVar4) {

        local_158 = uVar4 - 1;

        puVar7 = local_138;

        do {

          FUN_004e7130(puVar7 + -0xc,param_2);

          puVar7 = puVar7 + 0xc;

          local_158 = local_158 + -1;

        } while (local_158 != 0);

      }

      iVar1 = local_14c[uVar4 * 3];

      local_14c[uVar4 * 3] = *(int *)(param_1 + 4);

      *(int *)(param_1 + 4) = iVar1;

      uVar2 = *(uint32_t /* width from decompiler */ *)(local_144 + uVar4 * 0xc + -4);

      *(uint32_t /* width from decompiler */ *)(local_144 + uVar4 * 0xc + -4) = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar2;

      local_4 = local_4 & 0xffffff00;

      _eh_vector_destructor_iterator_(local_144,0xc,0x1a,FUN_00403430);

      piVar5 = (int *)*piVar3;

      *piVar3 = (int)piVar3;

      piVar3[1] = (int)piVar3;

      if (piVar5 != piVar3) {

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar5);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar3);

    }

    piVar5 = (int *)**(int **)(param_1 + 4);

    iVar1 = *piVar3;

    if (piVar5 != *(int **)(param_1 + 4)) {

      local_14c[1] = *piVar5;

      if (local_154 == param_1) {

        if (((int *)iVar1 == piVar5) || (iVar1 == *piVar5)) goto LAB_004e8196;

      }

      else {

        FUN_00404840(1);

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;

        piVar3 = local_150;

      }

      *(int *)piVar5[1] = local_14c[1];

      **(int **)(local_14c[1] + 4) = iVar1;

      **(int **)(iVar1 + 4) = (int)piVar5;

      uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = *(uint32_t /* width from decompiler */ *)(local_14c[1] + 4);

      *(int *)(local_14c[1] + 4) = piVar5[1];

      piVar5[1] = uVar2;

    }

LAB_004e8196:

    uVar6 = 0;

    if (uVar4 == 0) {

LAB_004e8202:

      local_150 = (int *)local_140[uVar6 * 3];

      local_140[uVar6 * 3] = (int)piVar3;

      iVar1 = local_140[uVar6 * 3 + 1];

      local_140[uVar6 * 3 + 1] = local_14c[0];

      local_14c[0] = iVar1;

      if (uVar6 == uVar4) {

        uVar4 = uVar4 + 1;

      }

    }

    else {

      piVar5 = local_140 + 1;

      do {

        if (*piVar5 == 0) break;

        FUN_004e7130(local_154,param_2);

        piVar3 = (int *)piVar5[-1];

        piVar5[-1] = (int)local_150;

        iVar1 = *piVar5;

        *piVar5 = local_14c[0];

        uVar6 = uVar6 + 1;

        piVar5 = piVar5 + 3;

        local_14c[0] = iVar1;

        local_150 = piVar3;

      } while (uVar6 < uVar4);

      if (uVar6 != 0x19) goto LAB_004e8202;

      FUN_004e7130(local_154,param_2);

    }

    iVar1 = *(int *)(param_1 + 8);

    piVar3 = local_150;

  } while( true );

}
