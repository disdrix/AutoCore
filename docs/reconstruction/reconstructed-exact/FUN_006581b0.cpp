// =============================================================================
// FUN_006581b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006581b0
// Address:   0x006581b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006581b0 @ 0x006581b0
// Stable ID: aa_006581b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~361 non-empty decompiler lines.
//  - Control keywords: if×41, return×1.
//  - Notable callees: FUN_005b3300×20, FUN_006581b0.
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

void __fastcall FUN_006581b0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  int *piVar9;

  uint32_t /* width from decompiler */ *puVar10;

  

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

  iVar3 = piVar9[1];

  iVar1 = iVar3 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar1) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar1) {

      iVar6 = iVar1;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar1;

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

  puVar10 = (uint32_t /* width from decompiler */ *)(iVar3 * 0x10 + *piVar9);

  puVar10[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

  *puVar10 = uVar4;

  puVar10[1] = uVar2;

  puVar10[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar3 = piVar9[1];

  iVar1 = iVar3 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar1) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar1) {

      iVar6 = iVar1;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar1;

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  puVar10 = (uint32_t /* width from decompiler */ *)(iVar3 * 0x10 + *piVar9);

  puVar10[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  *puVar10 = uVar4;

  puVar10[1] = uVar2;

  puVar10[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar3 = piVar9[1];

  iVar1 = iVar3 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar1) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar1) {

      iVar6 = iVar1;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar1;

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  puVar10 = (uint32_t /* width from decompiler */ *)(iVar3 * 0x10 + *piVar9);

  puVar10[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  *puVar10 = uVar4;

  puVar10[1] = uVar2;

  puVar10[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar3 = piVar9[1];

  iVar1 = iVar3 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar1) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar1) {

      iVar6 = iVar1;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar1;

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

  puVar10 = (uint32_t /* width from decompiler */ *)(iVar3 * 0x10 + *piVar9);

  puVar10[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

  *puVar10 = uVar4;

  puVar10[1] = uVar2;

  puVar10[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar3 = piVar9[1];

  iVar1 = iVar3 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar1) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar1) {

      iVar6 = iVar1;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar1;

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  puVar10 = (uint32_t /* width from decompiler */ *)(iVar3 * 0x10 + *piVar9);

  puVar10[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

  *puVar10 = uVar4;

  puVar10[1] = uVar2;

  puVar10[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar3 = piVar9[1];

  iVar1 = iVar3 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar1) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar1) {

      iVar6 = iVar1;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar1;

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  puVar10 = (uint32_t /* width from decompiler */ *)(iVar3 * 0x10 + *piVar9);

  puVar10[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  *puVar10 = uVar4;

  puVar10[1] = uVar2;

  puVar10[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar3 = piVar9[1];

  iVar1 = iVar3 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar1) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar1) {

      iVar6 = iVar1;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar1;

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  puVar10 = (uint32_t /* width from decompiler */ *)(iVar3 * 0x10 + *piVar9);

  puVar10[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  *puVar10 = uVar4;

  puVar10[1] = uVar2;

  puVar10[3] = 0;

  piVar9 = *(int **)(param_1 + 0x50);

  iVar3 = piVar9[1];

  iVar1 = iVar3 + 1;

  if ((int)(piVar9[2] & 0x7fffffffU) < iVar1) {

    iVar6 = (piVar9[2] & 0x7fffffffU) * 2;

    if (iVar6 <= iVar1) {

      iVar6 = iVar1;

    }

    FUN_005b3300(piVar9,iVar6,0x10);

  }

  piVar9[1] = iVar1;

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  puVar10 = (uint32_t /* width from decompiler */ *)(iVar3 * 0x10 + *piVar9);

  puVar10[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

  *puVar10 = uVar4;

  puVar10[1] = uVar2;

  puVar10[3] = 0;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 0;

  puVar10[1] = 3;

  puVar10[2] = 1;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 1;

  puVar10[1] = 3;

  puVar10[2] = 2;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 2;

  puVar10[1] = 6;

  puVar10[2] = 5;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 5;

  puVar10[1] = 1;

  puVar10[2] = 2;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 5;

  puVar10[1] = 6;

  puVar10[2] = 4;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 4;

  puVar10[1] = 6;

  puVar10[2] = 7;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 7;

  puVar10[1] = 3;

  puVar10[2] = 0;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 0;

  puVar10[1] = 4;

  puVar10[2] = 7;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 0;

  puVar10[1] = 1;

  puVar10[2] = 4;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 4;

  puVar10[1] = 1;

  puVar10[2] = 5;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 2;

  puVar10[1] = 3;

  puVar10[2] = 6;

  iVar3 = *(int *)(param_1 + 0x50);

  iVar6 = *(int *)(iVar3 + 0x10);

  iVar1 = iVar6 + 1;

  uVar7 = *(uint *)(iVar3 + 0x14) & 0x7fffffff;

  if ((int)uVar7 < iVar1) {

    iVar8 = uVar7 * 2;

    if (iVar8 <= iVar1) {

      iVar8 = iVar1;

    }

    FUN_005b3300((int *)(iVar3 + 0xc),iVar8,0xc);

  }

  *(int *)(iVar3 + 0x10) = iVar1;

  puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xc) + iVar6 * 0xc);

  *puVar10 = 6;

  puVar10[1] = 3;

  puVar10[2] = 7;

  return;

}
