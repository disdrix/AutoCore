// =============================================================================
// FUN_00756b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00756b40
// Address:   0x00756b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00756b40 @ 0x00756b40
// Stable ID: aa_00756b40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00756b40.
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

uint32_t /* width from decompiler */ __fastcall FUN_00756b40(int param_1)



{

  int *piVar1;

  int *in_EAX;

  float local_20;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_20 = (float)*in_EAX - DAT_00a0f298;

  local_1c = (float)in_EAX[1] - DAT_00a0f298;

  local_18 = (float)(*(int *)(param_1 + 0x70) + *(int *)(param_1 + 0x6c));

  local_14 = 0;

  if (*(int *)(DAT_00d1f05c + 4) != 0) {

    piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

    (**(code **)(*piVar1 + 0x50))(piVar1,DAT_00d0dfe0,&local_20,0xffffffff);

  }

  return 0;

}
