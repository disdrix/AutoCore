// =============================================================================
// FUN_0078fd10
// -----------------------------------------------------------------------------
// Stable ID: aa_0078fd10
// Address:   0x0078fd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078fd10 @ 0x0078fd10
// Stable ID: aa_0078fd10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0078fd10.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_0078fd10(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int *)(param_1 + 0x4b8) != 0) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x4b8) + 0xa0))();

    if (cVar1 != '\0') {

      return 1;

    }

    cVar1 = (**(code **)(**(int **)(param_1 + 0x4b8) + 0xa4))();

    if (cVar1 != '\0') {

                    /* WARNING: Could not recover jumptable at 0x0078fd4d. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      uVar2 = (**(code **)(**(int **)(param_1 + 0x4b8) + 0x3e4))();

      return uVar2;

    }

  }

  return 0;

}
