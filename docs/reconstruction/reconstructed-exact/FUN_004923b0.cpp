// =============================================================================
// FUN_004923b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004923b0
// Address:   0x004923b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004923b0 @ 0x004923b0
// Stable ID: aa_004923b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_00491ed0, FUN_004923b0, FUN_004c0970.
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

void __fastcall FUN_004923b0(int param_1)



{

  int *piVar1;

  

  piVar1 = (int *)**(int **)(param_1 + 0xe8);

  if (piVar1 != *(int **)(param_1 + 0xe8)) {

    do {

      (*(code *)**(uint32_t /* width from decompiler */ **)piVar1[2])(*(uint32_t /* width from decompiler */ *)(param_1 + 0xdc));

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(param_1 + 0xe8));

  }

  piVar1 = (int *)**(int **)(param_1 + 0xf4);

  if (piVar1 != *(int **)(param_1 + 0xf4)) {

    do {

      (*(code *)**(uint32_t /* width from decompiler */ **)piVar1[2])(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe0));

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(param_1 + 0xf4));

  }

  if (*(int *)(param_1 + 0xcc) != 0) {

    FUN_004c0970(*(uint32_t /* width from decompiler */ *)(param_1 + 0xdc));

  }

  FUN_00491ed0();

  return;

}
