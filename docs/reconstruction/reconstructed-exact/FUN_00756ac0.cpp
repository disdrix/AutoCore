// =============================================================================
// FUN_00756ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00756ac0
// Address:   0x00756ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00756ac0 @ 0x00756ac0
// Stable ID: aa_00756ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00756ac0.
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

void FUN_00756ac0(void)



{

  int *piVar1;

  int in_EAX;

  float local_20;

  float local_1c;

  uint32_t /* width from decompiler */ local_18;

  float local_14;

  

  local_20 = g_flLevelUpUiBase_Inferred / (float)*(int *)(in_EAX + 0x80);

  local_1c = DAT_00a12f70 / (float)*(int *)(in_EAX + 0x84);

  local_18 = DAT_00d0dfe4;

  local_14 = g_flOne;

  if (*(int *)(DAT_00d1f05c + 4) != 0) {

    piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

    (**(code **)(*piVar1 + 0x50))(piVar1,DAT_00d0dfd4,&local_20,0xffffffff);

  }

  return;

}
