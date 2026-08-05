// =============================================================================
// FUN_0061bcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0061bcc0
// Address:   0x0061bcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061bcc0 @ 0x0061bcc0
// Stable ID: aa_0061bcc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: Map_LowerBoundFindByIntKey×2, FUN_0061bcc0.
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

void FUN_0061bcc0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *extraout_EAX;

  int *piVar1;

  int local_4;

  

  piVar1 = (int *)0x0;

  Map_LowerBoundFindByIntKey(&DAT_00b04740,&local_4,&stack0xfffffff8,(int *)0x0);

  if (local_4 == DAT_00b04744) {

    piVar1 = (int *)0x0;

  }

  else {

    local_4 = 0;

    Map_LowerBoundFindByIntKey(&DAT_00b04740,&stack0xfffffff8,&local_4,piVar1);

    piVar1 = *(int **)(*extraout_EAX + 0x10);

  }

  (**(code **)(*piVar1 + 0x38))(param_1,param_2,param_3);

  return;

}
