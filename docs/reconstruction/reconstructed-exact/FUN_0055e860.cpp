// =============================================================================
// FUN_0055e860
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e860
// Address:   0x0055e860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055e860 @ 0x0055e860
// Stable ID: aa_0055e860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0055e860, FUN_005b3370, FUN_0062a590.
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

void __thiscall FUN_0055e860(int param_1,uint8_t *param_2,int param_3)



{

  int *piVar1;

  uint8_t *unaff_retaddr;

  

  if (*(char *)(param_1 + 300) == '\x01') {

    if (*(uint *)(param_1 + 0x100) == (*(uint *)(param_1 + 0x104) & 0x7fffffff)) {

      FUN_005b3370((int *)(param_1 + 0xfc),4);

    }

    *(int *)(*(int *)(param_1 + 0xfc) + *(int *)(param_1 + 0x100) * 4) = param_3;

    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + 1;

    *(short *)(param_3 + 6) = *(short *)(param_3 + 6) + 1;

    *param_2 = 0;

    return;

  }

  piVar1 = *(int **)(*(int *)(param_3 + 0xc) + 0x44);

  if (piVar1[9] == -1) {

    piVar1 = *(int **)(*(int *)(param_3 + 0x10) + 0x44);

  }

  FUN_0062a590(param_1,param_3);

  (**(code **)(*piVar1 + 4))(param_3);

  *unaff_retaddr = 1;

  return;

}
