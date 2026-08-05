// =============================================================================
// FUN_00638ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00638ac0
// Address:   0x00638ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00638ac0 @ 0x00638ac0
// Stable ID: aa_00638ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×8, return×5, goto×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_004c8610, FUN_005172d0, FUN_00638ac0.
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

uint32_t /* width from decompiler */ __fastcall FUN_00638ac0(int *param_1)



{

  int *piVar1;

  ushort uVar2;

  int iVar3;

  int iVar4;

  

  piVar1 = param_1 + 0xb;

  *piVar1 = *piVar1 - param_1[2];

  if (-1 < *piVar1) {

    return 0;

  }

  param_1[0xb] = 0x5dc;

  iVar3 = (**(code **)(*(int *)param_1[6] + 0x214))();

  if (iVar3 == 0) {

    return 0;

  }

  FUN_004c8610(0);

  if (*(char *)(*(int *)(param_1[6] + 0xa4) + 0x7e) == '\0') {

    return 0;

  }

  if (*(int *)(param_1[6] + 0xa0) != 0) {

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    uVar2 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    if ((uint)uVar2 % 100 < 0x24) goto LAB_00638b89;

  }

  iVar4 = (**(code **)(*param_1 + 0x24))();

  if ((iVar4 != 0) && (*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4 != *(int *)(param_1[6] + 0xa0))

     ) {

    (**(code **)(*param_1 + 0x20))();

    FUN_005172d0(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);

    return 1;

  }

LAB_00638b89:

  if (*(int *)(param_1[6] + 0xa0) == 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 600))

              (DAT_009e3c10,DAT_009e3c14,DAT_009e3c18,DAT_009e3c1c);

  }

  return 0;

}
