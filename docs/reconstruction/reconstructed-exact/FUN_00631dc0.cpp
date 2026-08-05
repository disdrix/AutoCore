// =============================================================================
// FUN_00631dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00631dc0
// Address:   0x00631dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00631dc0 @ 0x00631dc0
// Stable ID: aa_00631dc0
// Embedded strings (evidence for future rename):
//   - "(null)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00631dc0, FUN_00638060.
//  - Strings: "(null)".
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

int __thiscall FUN_00631dc0(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (param_2 != 0) {

    iVar1 = **(int **)(param_1 + 8);

    uVar2 = FUN_00638060(param_2);

    (**(code **)(iVar1 + 8))(param_2,uVar2);

    return param_1;

  }

  (**(code **)(**(int **)(param_1 + 8) + 8))("(null)",6);

  return param_1;

}
