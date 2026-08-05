// =============================================================================
// FUN_00711680
// -----------------------------------------------------------------------------
// Stable ID: aa_00711680
// Address:   0x00711680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711680 @ 0x00711680
// Stable ID: aa_00711680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00713e40×2, FUN_00711680, FUN_00713790, FUN_00713b90, FUN_007166f0.
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

uint FUN_00711680(int *param_1)



{

  int iVar1;

  

  iVar1 = *param_1;

  if (iVar1 != 0) {

    FUN_00713790(iVar1);

    FUN_007166f0(iVar1 + 4);

    FUN_00713e40(iVar1 + 0x10);

    FUN_00713b90(iVar1 + 0x14);

    FUN_00713e40(iVar1 + 0x18);

    if (*(int *)(iVar1 + 0x48) != 0) {

      (*(code *)PTR_free_00af8a4c)(*(int *)(iVar1 + 0x48));

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x48) = 0;

    }

    param_1 = (int *)(*(code *)PTR_free_00af8a4c)(iVar1);

  }

  return (uint)param_1 & 0xffff0000;

}
