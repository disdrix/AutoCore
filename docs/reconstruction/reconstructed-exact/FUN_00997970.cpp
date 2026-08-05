// =============================================================================
// FUN_00997970
// -----------------------------------------------------------------------------
// Stable ID: aa_00997970
// Address:   0x00997970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00997970 @ 0x00997970
// Stable ID: aa_00997970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00447ea0, FUN_0044cc30, FUN_00746910, FUN_00747220, FUN_00997970.
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

void FUN_00997970(uint param_1)



{

  int *piVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  

  uVar3 = param_1;

  piVar2 = *(int **)(param_1 + 0x110);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = 0;

  }

  if (*(int *)(param_1 + 0x1c) != 0) {

    iVar4 = *(int *)(param_1 + 0x14);

    FUN_00447ea0();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x34);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x38);

    FUN_00747220(1,0xffffffff);

    piVar2 = (int *)(param_1 + 0xcc);

    piVar1 = (int *)(param_1 + 200);

    param_1 = param_1 & 0xffffff00;

    iVar4 = *piVar2 + -8;

    FUN_0044cc30(*piVar1,iVar4,iVar4 - *piVar1 >> 3,param_1);

    *(uint32_t /* width from decompiler */ *)(uVar3 + 0xd4) = 0;

    *(uint32_t /* width from decompiler */ *)(uVar3 + 0xd8) = 0;

    FUN_00746910();

  }

  *(uint *)(uVar3 + 0xbc) = *(uint *)(uVar3 + 0xbc) & 0xfffffff7;

  return;

}
