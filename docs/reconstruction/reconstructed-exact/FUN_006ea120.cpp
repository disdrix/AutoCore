// =============================================================================
// FUN_006ea120
// -----------------------------------------------------------------------------
// Stable ID: aa_006ea120
// Address:   0x006ea120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ea120 @ 0x006ea120
// Stable ID: aa_006ea120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_006ea120.
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

void __fastcall FUN_006ea120(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = param_1[3];

  iVar1 = iVar2 + param_1[4] * 0xc;

  for (; iVar2 != iVar1; iVar2 = iVar2 + 0xc) {

    if (*(int **)(iVar2 + 8) != (int *)0x0) {

      (**(code **)(**(int **)(iVar2 + 8) + 0x14))();

    }

  }

  (**(code **)*param_1)(1);

  return;

}
