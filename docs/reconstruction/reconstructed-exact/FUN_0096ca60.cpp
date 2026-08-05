// =============================================================================
// FUN_0096ca60
// -----------------------------------------------------------------------------
// Stable ID: aa_0096ca60
// Address:   0x0096ca60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096ca60 @ 0x0096ca60
// Stable ID: aa_0096ca60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31, FUN_0096c8e0, FUN_0096ca60.
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

void FUN_0096ca60(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009afc0d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_LAB_00aa0a20;

  param_1[1] = &PTR_LAB_00aa0a10;

  local_4 = 2;

  FUN_0096c8e0();

  local_4 = CONCAT31(local_4._1_3_,1);

  iVar2 = param_1[0x14];

  if (iVar2 != 0) {

    piVar1 = (int *)(iVar2 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(iVar2 + 4) + 8))();

    }

  }

  param_1[1] = &PTR_LAB_009d45f0;

  *param_1 = &PTR_LAB_00a9a9bc;

  ExceptionList = local_c;

  return;

}
