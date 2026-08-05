// =============================================================================
// FUN_005a72d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a72d0
// Address:   0x005a72d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a72d0 @ 0x005a72d0
// Stable ID: aa_005a72d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, while×1.
//  - Notable callees: FUN_0048fb10, FUN_005a72d0.
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

uint32_t /* width from decompiler */ __thiscall FUN_005a72d0(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  char cVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  if ((((*(int *)(param_1 + 0xe8) != 0) && (cVar5 = (char)param_2, -1 < cVar5)) &&

      (cVar5 < *(char *)(param_1 + 0xb0))) &&

     (piVar1 = (int *)(*(int *)(param_1 + 0xe8) + cVar5 * 0x14c), piVar1 != (int *)0x0)) {

    iVar2 = (**(code **)(*piVar1 + 0xc))();

    iVar3 = (**(code **)(*piVar1 + 0x48))();

    fStack_4 = *(float *)(iVar3 + 0x1c) + *(float *)(iVar2 + 0x98);

    fStack_8 = *(float *)(iVar3 + 0x18) + *(float *)(iVar2 + 0x94);

    fStack_c = *(float *)(iVar2 + 0x90) + *(float *)(iVar3 + 0x14);

    iVar3 = (**(code **)(*piVar1 + 0x48))();

    fStack_14 = *(float *)(iVar3 + 0x24) + *(float *)(iVar2 + 0x94);

    fStack_18 = *(float *)(iVar3 + 0x20) + *(float *)(iVar2 + 0x90);

    fStack_10 = *(float *)(iVar3 + 0x28) + *(float *)(iVar2 + 0x98);

    while (param_2 = param_2 + 1, param_2 < param_3) {

      if (((*(int *)(param_1 + 0xe8) != 0) && (cVar5 = (char)param_2, -1 < cVar5)) &&

         ((cVar5 < *(char *)(param_1 + 0xb0) &&

          (piVar1 = (int *)(*(int *)(param_1 + 0xe8) + cVar5 * 0x14c), piVar1 != (int *)0x0)))) {

        iVar2 = (**(code **)(*piVar1 + 0xc))();

        iVar3 = (**(code **)(*piVar1 + 0x48))();

        fVar6 = *(float *)(iVar2 + 0x90) + *(float *)(iVar3 + 0x14);

        fVar7 = *(float *)(iVar3 + 0x18) + *(float *)(iVar2 + 0x94);

        fVar8 = *(float *)(iVar3 + 0x1c) + *(float *)(iVar2 + 0x98);

        if (fVar6 < fStack_c) {

          fStack_c = fVar6;

        }

        if (fVar7 < fStack_8) {

          fStack_8 = fVar7;

        }

        if (fVar8 < fStack_4) {

          fStack_4 = fVar8;

        }

        iVar3 = (**(code **)(*piVar1 + 0x48))();

        fVar6 = *(float *)(iVar2 + 0x90) + *(float *)(iVar3 + 0x20);

        fVar7 = *(float *)(iVar3 + 0x24) + *(float *)(iVar2 + 0x94);

        fVar8 = *(float *)(iVar3 + 0x28) + *(float *)(iVar2 + 0x98);

        if (fStack_18 < fVar6) {

          fStack_18 = fVar6;

        }

        if (fStack_14 < fVar7) {

          fStack_14 = fVar7;

        }

        if (fStack_10 < fVar8) {

          fStack_10 = fVar8;

        }

      }

    }

    uVar4 = FUN_0048fb10(&fStack_c,&fStack_18);

    return uVar4;

  }

  return 0xffffffff;

}
