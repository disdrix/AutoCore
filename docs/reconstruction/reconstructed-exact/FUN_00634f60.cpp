// =============================================================================
// FUN_00634f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00634f60
// Address:   0x00634f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00634f60 @ 0x00634f60
// Stable ID: aa_00634f60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, do×2, while×2, for×1.
//  - Notable callees: FUN_006c2fb0×2, FUN_0055e860, FUN_00634f60, SQRT.
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

void __thiscall FUN_00634f60(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  float *pfVar8;

  int iVar9;

  int iVar10;

  float fVar11;

  float fStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  float fStack_8;

  uint8_t uStack_4;

  

  if (*(char *)(param_1 + 0x2c) == '\0') {

    iVar5 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))();

    iVar6 = (**(code **)(**(int **)(param_1 + 0x20) + 0x18))();

    fVar11 = 0.0;

    iVar10 = 0;

    fStack_10 = 0.0;

    if (3 < iVar6) {

      iVar9 = (iVar6 - 4U >> 2) + 1;

      pfVar8 = (float *)(iVar5 + 0x10);

      iVar10 = iVar9 * 4;

      do {

        pfVar1 = pfVar8 + -4;

        pfVar2 = pfVar8 + -2;

        fVar4 = *pfVar8;

        pfVar3 = pfVar8 + 2;

        pfVar8 = pfVar8 + 8;

        iVar9 = iVar9 + -1;

        fVar11 = *pfVar1 * *pfVar1 + fVar11 + *pfVar2 * *pfVar2 + fVar4 * fVar4 + *pfVar3 * *pfVar3;

        fStack_10 = fVar11;

      } while (iVar9 != 0);

    }

    for (; iVar10 < iVar6; iVar10 = iVar10 + 1) {

      fVar11 = *(float *)(iVar5 + iVar10 * 8);

      fStack_10 = fVar11 * fVar11 + fStack_10;

    }

    if (*(float *)(param_1 + 0x28) <= fStack_10 && fStack_10 != *(float *)(param_1 + 0x28)) {

      *(uint8_t *)(param_1 + 0x2c) = 1;

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x30) != (uint32_t /* width from decompiler */ *)0x0) {

        uStack_4 = *(uint8_t *)(param_1 + 0x2d);

        fStack_8 = SQRT(fStack_10);

        uStack_c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x30))(&uStack_c);

      }

    }

  }

  if (*(char *)(param_1 + 0x2c) != '\0') {

    if (*(char *)(param_1 + 0x2d) != '\0') {

      uVar7 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))();

      (**(code **)(**(int **)(param_1 + 0x20) + 0x18))();

      FUN_006c2fb0(param_2,param_3,uVar7,8);

      FUN_0055e860(&param_3,param_1);

      return;

    }

    if (*(char *)(param_1 + 0x2c) != '\0') {

      uVar7 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))();

      (**(code **)(**(int **)(param_1 + 0x20) + 0x18))();

      FUN_006c2fb0(param_2,param_3,uVar7,8);

      return;

    }

  }

  iVar10 = (**(code **)(**(int **)(param_1 + 0x20) + 0x14))();

  iVar5 = (**(code **)(**(int **)(param_1 + 0x20) + 0x18))();

  if (0 < iVar5) {

    iVar6 = 0;

    do {

      *(uint32_t /* width from decompiler */ *)(iVar10 + iVar6 * 8) = 0;

      iVar6 = iVar6 + 1;

    } while (iVar6 < iVar5);

  }

  (**(code **)(**(int **)(param_1 + 0x20) + 0x24))(param_2,param_3);

  return;

}
