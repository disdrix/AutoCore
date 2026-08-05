// =============================================================================
// FUN_00977d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00977d40
// Address:   0x00977d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00977d40 @ 0x00977d40
// Stable ID: aa_00977d40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: FUN_00977d40.
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

void __thiscall FUN_00977d40(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  

  piVar1 = (int *)**(int **)(param_1 + 0x38);

  if (piVar1 == *(int **)(param_1 + 0x38)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = param_2;

    return;

  }

  do {

    (**(code **)(*(int *)piVar1[2] + 0x2c))(param_2);

    piVar1 = (int *)*piVar1;

  } while (piVar1 != (int *)*(int *)(param_1 + 0x38));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = param_2;

  return;

}
