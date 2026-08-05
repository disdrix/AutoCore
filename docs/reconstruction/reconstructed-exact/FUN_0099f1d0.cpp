// =============================================================================
// FUN_0099f1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099f1d0
// Address:   0x0099f1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099f1d0 @ 0x0099f1d0
// Stable ID: aa_0099f1d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00424d10, FUN_0098bc60, FUN_0099f1d0.
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

uint8_t FUN_0099f1d0(int *param_1)



{

  int *piVar1;

  uint8_t uVar2;

  int in_EAX;

  

  if (*(char *)(in_EAX + 0x24) == '\0') {

    if (param_1 != (int *)0x0) {

      piVar1 = param_1 + 2;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*param_1 + 8))();

      }

    }

    return 0;

  }

  uVar2 = FUN_0098bc60(param_1);

  FUN_00424d10();

  if (param_1 != (int *)0x0) {

    piVar1 = param_1 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*param_1 + 8))();

    }

  }

  return uVar2;

}
