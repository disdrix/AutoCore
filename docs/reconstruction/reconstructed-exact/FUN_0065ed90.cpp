// =============================================================================
// FUN_0065ed90
// -----------------------------------------------------------------------------
// Stable ID: aa_0065ed90
// Address:   0x0065ed90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065ed90 @ 0x0065ed90
// Stable ID: aa_0065ed90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~373 non-empty decompiler lines.
//  - Control keywords: if×42, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300×20, FUN_005d68f0, FUN_0065ed90.
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

void __fastcall FUN_0065ed90(int param_1)



{

  float fVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  int *piVar9;

  int iVar10;

  float *pfVar11;

  uint32_t /* width from decompiler */ *puVar12;

  int iVar13;

  

  piVar5 = operator_new(0x18);

  piVar9 = (int *)0x0;

  if (piVar5 != (int *)0x0) {

    *piVar5 = 0;

    piVar5[1] = 0;

    piVar5[2] = -0x80000000;

    piVar5[3] = 0;

    piVar5[4] = 0;

    piVar5[5] = -0x80000000;

    piVar9 = piVar5;

  }

  *(int **)(param_1 + 0x50) = piVar9;

  iVar10 = piVar9[1];

  iVar13 = iVar10 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar13) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar13) {

      iVar6 = iVar13;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar13;

  fVar1 = *(float *)(param_1 + 0x68);

  fVar2 = *(float *)(param_1 + 100);

  pfVar11 = (float *)(iVar10 * 0x10 + *piVar9);

  *pfVar11 = 0.0 - *(float *)(param_1 + 0x60);

  pfVar11[1] = fVar2;

  pfVar11[2] = fVar1;

  pfVar11[3] = 0.0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar10 = piVar9[1];

  iVar13 = iVar10 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar13) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar13) {

      iVar6 = iVar13;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar13;

  uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

  puVar12 = (uint32_t /* width from decompiler */ *)(iVar10 * 0x10 + *piVar9);

  *puVar12 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  puVar12[1] = uVar4;

  puVar12[2] = uVar3;

  puVar12[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar10 = piVar9[1];

  iVar13 = iVar10 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar13) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar13) {

      iVar6 = iVar13;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar13;

  uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

  puVar12 = (uint32_t /* width from decompiler */ *)(iVar10 * 0x10 + *piVar9);

  fVar1 = *(float *)(param_1 + 100);

  *puVar12 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  puVar12[1] = 0.0 - fVar1;

  puVar12[2] = uVar3;

  puVar12[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar10 = piVar9[1];

  iVar13 = iVar10 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar13) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar13) {

      iVar6 = iVar13;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar13;

  fVar1 = *(float *)(param_1 + 0x68);

  pfVar11 = (float *)(iVar10 * 0x10 + *piVar9);

  fVar2 = *(float *)(param_1 + 100);

  *pfVar11 = 0.0 - *(float *)(param_1 + 0x60);

  pfVar11[1] = 0.0 - fVar2;

  pfVar11[2] = fVar1;

  pfVar11[3] = 0.0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar10 = piVar9[1];

  iVar13 = iVar10 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar13) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar13) {

      iVar6 = iVar13;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar13;

  fVar1 = *(float *)(param_1 + 100);

  pfVar11 = (float *)(iVar10 * 0x10 + *piVar9);

  fVar2 = *(float *)(param_1 + 0x68);

  *pfVar11 = 0.0 - *(float *)(param_1 + 0x60);

  pfVar11[1] = fVar1;

  pfVar11[2] = 0.0 - fVar2;

  pfVar11[3] = 0.0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar10 = piVar9[1];

  iVar13 = iVar10 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar13) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar13) {

      iVar6 = iVar13;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar13;

  uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

  puVar12 = (uint32_t /* width from decompiler */ *)(iVar10 * 0x10 + *piVar9);

  fVar1 = *(float *)(param_1 + 0x68);

  *puVar12 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  puVar12[1] = uVar3;

  puVar12[2] = 0.0 - fVar1;

  puVar12[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar10 = piVar9[1];

  iVar13 = iVar10 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar13) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar13) {

      iVar6 = iVar13;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(iVar10 * 0x10 + *piVar9);

  fVar1 = *(float *)(param_1 + 0x68);

  fVar2 = *(float *)(param_1 + 100);

  *puVar12 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  puVar12[1] = 0.0 - fVar2;

  puVar12[2] = 0.0 - fVar1;

  puVar12[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar10 = piVar9[1];

  iVar13 = iVar10 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar13) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar13) {

      iVar6 = iVar13;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar13;

  pfVar11 = (float *)(iVar10 * 0x10 + *piVar9);

  fVar1 = *(float *)(param_1 + 0x68);

  fVar2 = *(float *)(param_1 + 100);

  *pfVar11 = 0.0 - *(float *)(param_1 + 0x60);

  pfVar11[1] = 0.0 - fVar2;

  pfVar11[2] = 0.0 - fVar1;

  pfVar11[3] = 0.0;

  iVar13 = 0;

  if (0 < *(int *)(*(int *)(param_1 + 0x50) + 4)) {

    iVar10 = 0;

    do {

      FUN_005d68f0(param_1 + 0x10,**(int **)(param_1 + 0x50) + iVar10);

      iVar13 = iVar13 + 1;

      iVar10 = iVar10 + 0x10;

    } while (iVar13 < *(int *)(*(int *)(param_1 + 0x50) + 4));

  }

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 3;

  puVar12[1] = 2;

  puVar12[2] = 1;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 3;

  puVar12[1] = 1;

  puVar12[2] = 0;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 6;

  puVar12[1] = 7;

  puVar12[2] = 4;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 6;

  puVar12[1] = 4;

  puVar12[2] = 5;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 4;

  puVar12[1] = 7;

  puVar12[2] = 3;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 4;

  puVar12[1] = 3;

  puVar12[2] = 0;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 2;

  puVar12[1] = 6;

  puVar12[2] = 5;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 2;

  puVar12[1] = 5;

  puVar12[2] = 1;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 7;

  puVar12[1] = 6;

  puVar12[2] = 2;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 7;

  puVar12[1] = 2;

  puVar12[2] = 3;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 1;

  puVar12[1] = 5;

  puVar12[2] = 4;

  iVar10 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar10 + 0x10);

  iVar13 = iVar6 + 1;

  uVar7 = *(uint *)(iVar10 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar13) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar13) {

      iVar8 = iVar13;

    }

    FUN_005b3300((int *)(iVar10 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar10 + 0x10) = iVar13;

  puVar12 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar10 + 0xc) + iVar6 * 0xc);

  *puVar12 = 1;

  puVar12[1] = 4;

  puVar12[2] = 0;

  return;

}
