// =============================================================================
// FUN_005d4b60
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4b60
// Address:   0x005d4b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d4b60 @ 0x005d4b60
// Stable ID: aa_005d4b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_0053cfd0, FUN_005813b0, FUN_00581480, FUN_005834f0, FUN_005d4b60.
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

uint32_t /* width from decompiler */ __thiscall FUN_005d4b60(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int *)(param_1 + -0xd8) == 0) {

    uVar2 = FUN_005834f0(param_2);

    return uVar2;

  }

  cVar1 = FUN_005813b0(param_2);

  if (cVar1 != '\0') {

    cVar1 = FUN_00581480(param_2);

    if (cVar1 != '\0') {

      cVar1 = FUN_0053cfd0(param_2);

      if (cVar1 != '\0') {

        return 1;

      }

    }

  }

  return 0;

}
