// =============================================================================
// FUN_005accf0
// -----------------------------------------------------------------------------
// Stable ID: aa_005accf0
// Address:   0x005accf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005accf0 @ 0x005accf0
// Stable ID: aa_005accf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×7, while×1, return×1.
//  - Notable callees: FUN_004bb1c0×2, FUN_005accf0, FUN_005ae050, SQRT.
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

float10 __thiscall

FUN_005accf0(int param_1,int param_2,int param_3,float param_4,int param_5,int param_6)



{

  uint32_t /* width from decompiler */ *puVar1;

  float fVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  float *pfVar6;

  int iVar7;

  int *piVar8;

  int *piVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float local_20;

  float local_1c;

  float local_18;

  

  fVar2 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 0x250) + 4) + 4) + 0xac

                                      + *(int *)(param_2 + 0x250)) + 0x3c) + 0x634);

  if (param_5 < 0) {

    pfVar6 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) +

                                  0x1a0))();

    local_20 = *pfVar6;

    local_1c = pfVar6[1];

    local_18 = pfVar6[2];

  }

  else {

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4c) + param_5 * 8);

    iVar7 = FUN_004bb1c0(0,*puVar1,puVar1[1]);

    if (iVar7 != 0) {

      iVar4 = *(int *)(*(int *)(iVar7 + 4) + 4);

      local_20 = *(float *)(iVar4 + 0x84 + iVar7);

      local_1c = *(float *)(iVar4 + 0x88 + iVar7);

      local_18 = *(float *)(iVar4 + 0x8c + iVar7);

    }

  }

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4c) + param_6 * 8);

  iVar7 = FUN_004bb1c0(0,*puVar1,puVar1[1]);

  if (iVar7 != 0) {

    iVar4 = *(int *)(*(int *)(iVar7 + 4) + 4);

    piVar9 = (int *)(*(int **)(param_1 + 0x8c))[1];

    fVar10 = local_20 - *(float *)(iVar4 + 0x84 + iVar7);

    fVar11 = local_1c - *(float *)(iVar4 + 0x88 + iVar7);

    fVar12 = local_18 - *(float *)(iVar4 + 0x8c + iVar7);

    cVar3 = *(char *)((int)piVar9 + 0x19);

    piVar5 = *(int **)(param_1 + 0x8c);

    while (cVar3 == '\0') {

      if (piVar9[3] < param_3) {

        piVar8 = (int *)piVar9[2];

        piVar9 = piVar5;

      }

      else {

        piVar8 = (int *)*piVar9;

      }

      piVar5 = piVar9;

      piVar9 = piVar8;

      cVar3 = *(char *)((int)piVar8 + 0x19);

    }

    piVar9 = *(int **)(param_1 + 0x8c);

    if (piVar5 != (int *)*piVar9) {

      FUN_005ae050();

    }

    fVar10 = SQRT(fVar10 * fVar10 + fVar11 * fVar11 + fVar12 * fVar12);

    if (piVar5 == piVar9) {

      fVar10 = fVar10 / fVar2;

    }

    else {

      fVar10 = (fVar10 / fVar2) * (float)piVar5[5];

    }

    param_4 = fVar10 + param_4;

  }

  if (param_3 < 1) {

    param_4 = param_4 + DAT_00aaa688;

  }

  return (float10)param_4;

}
