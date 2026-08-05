// =============================================================================
// FUN_0075a300
// -----------------------------------------------------------------------------
// Stable ID: aa_0075a300
// Address:   0x0075a300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075a300 @ 0x0075a300
// Stable ID: aa_0075a300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×8, for×2, return×1.
//  - Notable callees: SQRT×2, FUN_0075a300.
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



void FUN_0075a300(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint8_t uVar4;

  int in_EAX;

  int *piVar5;

  int *piVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  

  piVar6 = *(int **)(in_EAX + 0x10);

  for (piVar5 = *(int **)(in_EAX + 0xc); piVar5 != piVar6; piVar5 = piVar5 + 4) {

    piVar1 = (int *)*piVar5;

    if (((piVar1[0x16] != 0) && (piVar1[0x17] != 0)) &&

       (*(int *)(piVar1[0x17] + 0x1c) != piVar1[0x18])) {

      (**(code **)(*piVar1 + 0x80))();

    }

    iVar2 = piVar1[0x19];

    piVar1 = (int *)*piVar5;

    iVar3 = *(int *)(param_1 + 8);

    fVar9 = *(float *)(iVar2 + 0x98) - *(float *)(iVar3 + 0x98);

    fVar8 = *(float *)(iVar2 + 0x94) - *(float *)(iVar3 + 0x94);

    fVar7 = *(float *)(iVar2 + 0x90) - *(float *)(iVar3 + 0x90);

    if ((*(byte *)(piVar1 + 0x2f) & 1) != 0) {

      (**(code **)(*piVar1 + 0x5c))();

    }

    fVar7 = (SQRT(fVar9 * fVar9 + fVar8 * fVar8 + fVar7 * fVar7) - (float)piVar1[0xd]) -

            _DAT_00d1a544;

    fVar8 = 0.0;

    if (g_flZero <= fVar7) {

      fVar8 = fVar7;

    }

    if ((fVar8 < (float)piVar5[2]) || ((float)piVar5[3] <= fVar8)) {

      uVar4 = 0;

    }

    else {

      uVar4 = 1;

    }

    *(uint8_t *)(piVar5 + 1) = uVar4;

  }

  piVar5 = *(int **)(in_EAX + 0x20);

  for (piVar6 = *(int **)(in_EAX + 0x1c); piVar6 != piVar5; piVar6 = piVar6 + 4) {

    piVar1 = (int *)*piVar6;

    if (((piVar1[0x16] != 0) && (piVar1[0x17] != 0)) &&

       (*(int *)(piVar1[0x17] + 0x1c) != piVar1[0x18])) {

      (**(code **)(*piVar1 + 0x80))();

    }

    iVar2 = piVar1[0x19];

    piVar1 = (int *)*piVar6;

    iVar3 = *(int *)(param_1 + 8);

    fVar9 = *(float *)(iVar2 + 0x98) - *(float *)(iVar3 + 0x98);

    fVar8 = *(float *)(iVar2 + 0x94) - *(float *)(iVar3 + 0x94);

    fVar7 = *(float *)(iVar2 + 0x90) - *(float *)(iVar3 + 0x90);

    if ((*(byte *)(piVar1 + 0x2f) & 1) != 0) {

      (**(code **)(*piVar1 + 0x5c))();

    }

    fVar7 = (SQRT(fVar9 * fVar9 + fVar8 * fVar8 + fVar7 * fVar7) - (float)piVar1[0xd]) -

            _DAT_00d1a544;

    fVar8 = 0.0;

    if (g_flZero <= fVar7) {

      fVar8 = fVar7;

    }

    if ((fVar8 < (float)piVar6[2]) || ((float)piVar6[3] <= fVar8)) {

      uVar4 = 0;

    }

    else {

      uVar4 = 1;

    }

    *(uint8_t *)(piVar6 + 1) = uVar4;

  }

  return;

}
