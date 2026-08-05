// =============================================================================
// FUN_006e8e50
// -----------------------------------------------------------------------------
// Stable ID: aa_006e8e50
// Address:   0x006e8e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e8e50 @ 0x006e8e50
// Stable ID: aa_006e8e50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_006e8e50.
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

void __fastcall FUN_006e8e50(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  

  iVar1 = 0;

  if (0 < (int)param_1[4]) {

    do {

      (**(code **)(**(int **)(param_1[3] + 4 + iVar1 * 8) + 0x14))();

      iVar1 = iVar1 + 1;

    } while (iVar1 < (int)param_1[4]);

  }

  (**(code **)*param_1)(1);

  return;

}
