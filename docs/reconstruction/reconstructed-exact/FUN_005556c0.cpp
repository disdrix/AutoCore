// =============================================================================
// FUN_005556c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005556c0
// Address:   0x005556c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005556c0 @ 0x005556c0
// Stable ID: aa_005556c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_005556c0, FUN_00558eb0.
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

uint __fastcall FUN_005556c0(int param_1)



{

  ushort uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  float fVar5;

  int local_4;

  

  local_4 = param_1;

  FUN_00558eb0(&local_4,&stack0x00000004);

  iVar2 = local_4;

  if (local_4 != *(int *)(param_1 + 0x174)) {

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    fVar5 = (float)uVar1 * DAT_00aaa638;

    iVar3 = 0;

    for (uVar4 = 0;

        (*(int *)(iVar2 + 0x444) != 0 &&

        (uVar4 < (uint)((*(int *)(iVar2 + 0x448) - *(int *)(iVar2 + 0x444)) / 0x134)));

        uVar4 = uVar4 + 1) {

      fVar5 = fVar5 - *(float *)(*(int *)(iVar2 + 0x444) + 300 + iVar3);

      if ((0.0 < *(float *)(*(int *)(iVar2 + 0x444) + 300 + iVar3)) && (fVar5 < 0.0)) {

        return uVar4;

      }

      iVar3 = iVar3 + 0x134;

    }

  }

  return 0;

}
