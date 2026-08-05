// =============================================================================
// FUN_005fea70
// -----------------------------------------------------------------------------
// Stable ID: aa_005fea70
// Address:   0x005fea70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fea70 @ 0x005fea70
// Stable ID: aa_005fea70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004ce940, FUN_00508b10, FUN_005fea70.
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

uint32_t /* width from decompiler */ __thiscall FUN_005fea70(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  FUN_004ce940();

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_00508b10(param_2);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*puVar1)(param_1 + -0xe0,param_3,0);

    return 1;

  }

  return 0;

}
