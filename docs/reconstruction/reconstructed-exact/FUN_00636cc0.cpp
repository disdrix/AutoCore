// =============================================================================
// FUN_00636cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00636cc0
// Address:   0x00636cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00636cc0 @ 0x00636cc0
// Stable ID: aa_00636cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004fc650, FUN_005081d0, FUN_00636cc0.
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

void __thiscall FUN_00636cc0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  char cVar1;

  

  if (*(int *)(param_1 + 0x24) == 0) {

    *param_2 = DAT_00af4f84;

    return;

  }

  cVar1 = FUN_004fc650(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),*(uint32_t /* width from decompiler */ *)(param_1 + 0x30),

                       *(uint32_t /* width from decompiler */ *)(param_1 + 0x34),1);

  if (cVar1 == '\0') {

    FUN_005081d0();

  }

  *param_2 = DAT_00d02c60;

  return;

}
