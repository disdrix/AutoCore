// =============================================================================
// FUN_004d31a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d31a0
// Address:   0x004d31a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d31a0 @ 0x004d31a0
// Stable ID: aa_004d31a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_004cf120, FUN_004d2820, FUN_004d31a0, FUN_00521510.
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

void __thiscall FUN_004d31a0(int param_1,int *param_2,int *param_3)



{

  float fVar1;

  ushort uVar2;

  int iVar3;

  uint64_t uVar4;

  

  iVar3 = (**(code **)(*param_2 + 0x210))(0);

  if ((iVar3 != 0) && (param_3 != (int *)0x0)) {

    iVar3 = (**(code **)(*param_3 + 0x210))(0);

    if (iVar3 != 0) {

      fVar1 = *(float *)(param_1 + 0x30);

      iVar3 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar3 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

      }

      uVar2 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

      *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

      if ((float)uVar2 * DAT_00aaa638 < fVar1) {

        (**(code **)(*param_3 + 0x144))();

        iVar3 = FUN_004cf120(0x21a3,0xffffffff);

        uVar4 = FUN_00521510(&stack0xffffffd8);

        *(uint64_t *)(iVar3 + 0x170) = uVar4;

        FUN_004d2820(iVar3,&stack0xffffffd8,0x3f800000,1);

      }

    }

  }

  return;

}
