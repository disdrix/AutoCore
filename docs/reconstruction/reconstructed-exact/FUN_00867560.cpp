// =============================================================================
// FUN_00867560
// -----------------------------------------------------------------------------
// Stable ID: aa_00867560
// Address:   0x00867560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00867560 @ 0x00867560
// Stable ID: aa_00867560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007b08d0, FUN_00867560.
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

void __thiscall FUN_00867560(int param_1,int *param_2)



{

  int unaff_ESI;

  int unaff_EDI;

  int *piStack_1c;

  int local_10 [2];

  uint8_t local_8 [8];

  

  piStack_1c = param_2;

  FUN_007b08d0();

  if (*(int *)(param_1 + 0x530) != 0) {

    piStack_1c = (int *)0x0;

    (**(code **)(**(int **)(param_1 + 0x530) + 0x120))(local_10,1);

    unaff_ESI = *param_2 - (int)piStack_1c;

    local_10[0] = param_2[1] - unaff_EDI;

    (**(code **)(**(int **)(param_1 + 0x530) + 300))(&stack0xffffffec);

  }

  if (*(int *)(param_1 + 0x534) != 0) {

    piStack_1c = (int *)0x0;

    (**(code **)(**(int **)(param_1 + 0x534) + 0x120))(local_8,1);

    piStack_1c = (int *)(*param_2 - unaff_ESI);

    (**(code **)(**(int **)(param_1 + 0x534) + 300))(&piStack_1c);

  }

  return;

}
