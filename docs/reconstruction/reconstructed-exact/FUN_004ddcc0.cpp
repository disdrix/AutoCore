// =============================================================================
// FUN_004ddcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ddcc0
// Address:   0x004ddcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ddcc0 @ 0x004ddcc0
// Stable ID: aa_004ddcc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~143 non-empty decompiler lines.
//  - Control keywords: if×12, return×5, do×3, while×3.
//  - Notable callees: FUN_00553ff0×2, FUN_004a94e0, FUN_004cd9a0, FUN_004dbc20, FUN_004dbda0, FUN_004ddcc0, FUN_00513880, FUN_005b06d0.
//  - Return sites: 5.

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

/* WARNING: Removing unreachable block (ram,0x004ddfdd) */



int * __fastcall FUN_004ddcc0(int param_1)



{

  int *piVar1;

  int iVar2;

  void *pvVar3;

  int unaff_EBX;

  int unaff_EBP;

  int unaff_ESI;

  int *piStack_6f4;

  uint32_t /* width from decompiler */ uStack_6f0;

  uint8_t *puStack_6ec;

  uint32_t /* width from decompiler */ uStack_6e8;

  uint32_t /* width from decompiler */ *puStack_6e4;

  int iStack_6bc;

  uint8_t auStack_6a8 [244];

  uint8_t auStack_5b4 [4];

  uint8_t auStack_5b0 [4];

  int aiStack_5ac [2];

  uint32_t /* width from decompiler */ uStack_5a4;

  uint8_t auStack_5a0 [1420];

  uint32_t /* width from decompiler */ uStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a2438;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b6a20();

  piVar1 = (int *)FUN_007b72b0();

  if (piVar1 != (int *)0x0) {

    *(uint8_t *)(param_1 + 0x81) = 1;

    iVar2 = FUN_004a94e0();

    *(int *)(param_1 + 0x8c) = iVar2;

    if (iVar2 != -1) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe4f8) + 4);

      (**(code **)(*piVar1 + 0x14))();

      (**(code **)(*piVar1 + 0x14))();

      puStack_6e4 = local_c;

      uStack_6e8 = 0x4ddd75;

      (**(code **)(*piVar1 + 0x14))();

      uStack_6e8 = 4;

      puStack_6ec = puStack_10;

      uStack_6f0 = 0x4ddd87;

      (**(code **)(*piVar1 + 0x14))();

      uStack_6f0 = uStack_14;

      piStack_6f4 = piVar1;

      FUN_00513880();

      uStack_6f0 = 8;

      piStack_6f4 = (int *)(param_1 + 0xe7e0);

      (**(code **)(*piVar1 + 0x14))();

      (**(code **)(*piVar1 + 0x14))(param_1 + 0xe7e8,8);

      if (0x20 < *(int *)(param_1 + 0x8c)) {

        (**(code **)(*piVar1 + 0x14))(param_1 + 0xe7d8,8);

      }

      if (0x21 < *(int *)(param_1 + 0x8c)) {

        (**(code **)(*piVar1 + 0x14))(param_1 + 0xe7f0,8);

      }

      FUN_004dbc20(piVar1);

      FUN_004dbda0(piVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x8c));

      FUN_005b06d0(piVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x8c));

      (**(code **)(**(int **)(param_1 + 0xe520) + 4))();

      if ((0x24 < *(int *)(param_1 + 0x8c)) && (*(int *)(param_1 + 0x8c) < 0x2f)) {

        (**(code **)(*piVar1 + 0x14))();

        iVar2 = 0;

        if (0 < unaff_EBP) {

          do {

            uStack_5a4 = 0;

            auStack_5a0[0] = 0;

            auStack_6a8[0] = 0;

            (**(code **)(*piVar1 + 0x14))();

            puStack_6e4 = &uStack_5a4;

            uStack_6e8 = 0x4dde98;

            (**(code **)(*piVar1 + 0x14))();

            uStack_6e8 = 4;

            puStack_6ec = auStack_5a0;

            uStack_6f0 = 0x4ddeaa;

            (**(code **)(*piVar1 + 0x14))();

            uStack_6f0 = 4;

            piStack_6f4 = aiStack_5ac;

            (**(code **)(*piVar1 + 0x14))();

            (**(code **)(*piVar1 + 0x14))(aiStack_5ac,1);

            (**(code **)(*piVar1 + 0x14))(auStack_5b0,4);

            (**(code **)(*piVar1 + 0x14))(auStack_5b4,4);

            (**(code **)(*piVar1 + 0x14))(&piStack_6f4,4);

            if (iStack_6bc != 0) {

              (**(code **)(*piVar1 + 0x14))();

              auStack_6a8[iStack_6bc] = 0;

            }

            iVar2 = iVar2 + 1;

          } while (iVar2 < unaff_EBP);

        }

        (**(code **)(*piVar1 + 0x14))();

        iVar2 = 0;

        if (0 < iStack_6bc) {

          do {

            (**(code **)(*piVar1 + 0x14))();

            iVar2 = iVar2 + 1;

          } while (iVar2 < iStack_6bc);

        }

      }

      if ((0x25 < *(int *)(param_1 + 0x8c)) && (*(int *)(param_1 + 0x8c) < 0x2f)) {

        (**(code **)(*piVar1 + 0x14))();

        if (iStack_6bc != 0) {

          pvVar3 = operator_new__(iStack_6bc + 1);

          (**(code **)(*piVar1 + 0x14))();

          *(uint8_t *)((int)pvVar3 + unaff_EBP) = 0;

          FUN_00553ff0();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar3);

        }

        iVar2 = 4;

        do {

          (**(code **)(*piVar1 + 0x14))();

          iVar2 = iVar2 + -1;

        } while (iVar2 != 0);

      }

      if (*(int *)(param_1 + 0x8c) < 0x2f) {

        if (*(int *)(param_1 + 0x8c) < 0x26) {

          ExceptionList = local_c;

          return piVar1;

        }

        FUN_004cd9a0();

        ExceptionList = local_c;

        return piVar1;

      }

      (**(code **)(*piVar1 + 0x14))();

      pvVar3 = operator_new__(unaff_EBX + 1);

      (**(code **)(*piVar1 + 0x14))();

      *(uint8_t *)((int)pvVar3 + unaff_ESI) = 0;

      puStack_6e4 = (uint32_t /* width from decompiler */ *)0x4de05e;

      FUN_00553ff0();

                    /* WARNING: Subroutine does not return */

      puStack_6e4 = (uint32_t /* width from decompiler */ *)&UNK_004de064;

      operator_delete(pvVar3);

    }

    FUN_007a4480();

  }

  ExceptionList = local_c;

  return (int *)0x0;

}
