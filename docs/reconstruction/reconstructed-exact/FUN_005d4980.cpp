// =============================================================================
// FUN_005d4980
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4980
// Address:   0x005d4980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d4980 @ 0x005d4980
// Stable ID: aa_005d4980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0053d170, FUN_005819e0, FUN_00581ab0, FUN_005d4980.
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

uint32_t /* width from decompiler */ FUN_005d4980(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  

  cVar1 = FUN_005819e0(param_1,param_2);

  if (cVar1 != '\0') {

    cVar1 = FUN_00581ab0(param_1,param_2);

    if (cVar1 != '\0') {

      cVar1 = FUN_0053d170(param_1,param_2,param_3,param_4);

      if (cVar1 != '\0') {

        return 1;

      }

    }

  }

  return 0;

}
