// =============================================================================
// FUN_008d42b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008d42b0
// Address:   0x008d42b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d42b0 @ 0x008d42b0
// Stable ID: aa_008d42b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, do×2, while×2.
//  - Notable callees: FUN_0040eba0, FUN_00519a30, FUN_00519d20, FUN_006a3db0, FUN_008d42b0, FUN_0096efd0, FUN_0096f0e0.
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

int * FUN_008d42b0(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  int local_1c;

  int *local_18;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b102e;

  local_c = ExceptionList;

  iVar6 = 0;

  ExceptionList = &local_c;

  if ((DAT_00b042b8 == 0) && (ExceptionList = &local_c, FUN_00519a30(), DAT_00b042b8 == 0)) {

    ExceptionList = local_c;

    return (int *)0x0;

  }

  iVar1 = *param_1;

  local_1c = FUN_006a3db0();

  if (local_1c < 2) {

    local_1c = 1;

  }

  local_18 = operator_new(4);

  if (local_18 == (int *)0x0) {

    local_18 = (int *)0x0;

  }

  else {

    *local_18 = 0;

  }

  local_4 = 0xffffffff;

  if (local_18 == (int *)0x0) {

    ExceptionList = local_c;

    return (int *)0x0;

  }

  iVar2 = FUN_0096f0e0(0x15,param_1,1,1,1,0);

  if (-1 < iVar2) {

    iVar2 = FUN_0040eba0(0,0);

    if ((iVar2 != 0) && (0 < param_1[1])) {

      iVar3 = *param_1;

      do {

        iVar7 = 0;

        if (0 < iVar3) {

          do {

            iVar3 = iVar7 / local_1c + (iVar6 / local_1c) * (iVar1 / local_1c);

            if (0x3f < iVar3) {

              iVar3 = 0;

            }

            uVar4 = FUN_00519d20((&DAT_00a1e2e8)[iVar3]);

            iVar3 = (*param_1 * iVar6 + iVar7) * 4;

            *(char *)(iVar3 + iVar2) = (char)uVar4;

            *(char *)(iVar2 + 1 + iVar3) = (char)((uint)uVar4 >> 8);

            *(char *)(iVar2 + 2 + iVar3) = (char)((uint)uVar4 >> 0x10);

            *(uint8_t *)(iVar2 + 3 + iVar3) = 0xff;

            iVar3 = *param_1;

            iVar7 = iVar7 + 1;

          } while (iVar7 < iVar3);

        }

        iVar6 = iVar6 + 1;

      } while (iVar6 < param_1[1]);

    }

    iVar6 = *local_18;

    if (iVar6 != 0) {

      uVar5 = *(uint *)(iVar6 + 0x2c) & 0xf;

      if (uVar5 == 1) {

        (**(code **)(**(int **)(iVar6 + 0x10) + 0x50))(*(int **)(iVar6 + 0x10),0);

      }

      else if (uVar5 == 2) {

        (**(code **)(**(int **)(iVar6 + 0x10) + 0x50))

                  (*(int **)(iVar6 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x3c),0);

      }

      else if (uVar5 == 4) {

        (**(code **)(**(int **)(iVar6 + 0x10) + 0x50))(*(int **)(iVar6 + 0x10),0);

      }

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x38) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x3c) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x40) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x44) = 0;

    }

    ExceptionList = local_c;

    return local_18;

  }

  FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

  operator_delete(local_18);

}
