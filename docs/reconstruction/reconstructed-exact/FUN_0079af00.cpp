// =============================================================================
// FUN_0079af00
// -----------------------------------------------------------------------------
// Stable ID: aa_0079af00
// Address:   0x0079af00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079af00 @ 0x0079af00
// Stable ID: aa_0079af00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0079af00, FUN_007a81a0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0079af00(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if (cVar1 != '\0') {

    (**(code **)(*param_1 + 0x3d0))(1);

    (**(code **)(*param_1 + 0x34c))();

    FUN_007a81a0(unaff_retaddr,param_2);

    return 1;

  }

  return 0;

}
