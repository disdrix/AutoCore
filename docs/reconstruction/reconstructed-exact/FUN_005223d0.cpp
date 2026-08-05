// =============================================================================
// FUN_005223d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005223d0
// Address:   0x005223d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005223d0 @ 0x005223d0
// Stable ID: aa_005223d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_004c3a00, FUN_005223d0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_005223d0(int param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  iVar2 = *(int *)(*(int *)(param_1 + -0xd9c) + 4);

  if (*(char *)(*(int *)(iVar2 + -0xcf8 + param_1) + 0xf5) != '\0') {

    if (*(int *)(param_1 + -0xd98) == 0) {

      return &DAT_00b045a0;

    }

    return (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0xd98) + 0x3c) + 0x40);

  }

  if (((*(char *)(param_1 + -0x6e7) != '\0') &&

      (piVar1 = *(int **)(iVar2 + param_1 + -0xcfc), piVar1 != (int *)0x0)) &&

     (iVar2 = (**(code **)(*piVar1 + 0x1c8))(), iVar2 != 0)) {

    iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xcfc + param_1) +

                        0x1c8))();

    if (*(int *)(iVar2 + 8) == 0) {

      return &DAT_00b045a0;

    }

    return (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar2 + 8) + 0x3c) + 0x40);

  }

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_004c3a00();

  return puVar3;

}
