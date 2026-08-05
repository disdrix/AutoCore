// =============================================================================
// FUN_00713290
// -----------------------------------------------------------------------------
// Stable ID: aa_00713290
// Address:   0x00713290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713290 @ 0x00713290
// Stable ID: aa_00713290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_00713290.
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

uint32_t /* width from decompiler */ FUN_00713290(int *param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  

  uVar1 = 0;

  iVar2 = 0;

  if (0 < param_2) {

    while (*param_1 != param_3) {

      iVar2 = iVar2 + 1;

      param_1 = param_1 + 1;

      if (param_2 <= iVar2) {

        return uVar1;

      }

    }

    uVar1 = 1;

  }

  return uVar1;

}
