// =============================================================================
// FUN_0046f460
// -----------------------------------------------------------------------------
// Stable ID: aa_0046f460
// Address:   0x0046f460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046f460 @ 0x0046f460
// Stable ID: aa_0046f460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0041b440, FUN_0041b610, FUN_0046f460, FUN_0046f670.
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

uint32_t /* width from decompiler */ FUN_0046f460(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar2;

  int in_stack_fffffffc;

  

  uVar2 = 0;

  FUN_0041b610();

  if (in_stack_fffffffc != *(int *)(unaff_ESI + 4)) {

    return 0xffffffff;

  }

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_0041b440(uVar2,0);

  *puVar1 = FUN_0046e7f0;

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_0046f670(uVar2,0);

  *puVar1 = param_1;

  puVar1[1] = param_2;

  return 0;

}
