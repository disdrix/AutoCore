// =============================================================================
// FUN_004982f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004982f0
// Address:   0x004982f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004982f0 @ 0x004982f0
// Stable ID: aa_004982f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00497c80, FUN_004982f0, FUN_00787410, FUN_007874b0.
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

uint32_t /* width from decompiler */ __fastcall FUN_004982f0(uint8_t *param_1)



{

  int iVar1;

  int iVar2;

  float fVar3;

  

  FUN_00497c80();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 10;

  iVar1 = *(int *)(*(int *)(param_1 + 0xc4) + 0xe4f8);

  fVar3 = *(float *)(iVar1 + 0x18) * DAT_00a14000;

  iVar2 = (int)((float)*(int *)(iVar1 + 0x10) * fVar3);

  *(int *)(param_1 + 4) = iVar2;

  iVar1 = (int)((float)*(int *)(*(int *)(*(int *)(param_1 + 0xc4) + 0xe4f8) + 0x14) * fVar3);

  *(int *)(param_1 + 8) = iVar1;

  if ((iVar2 < 1) || (iVar1 < 1)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *param_1 = 1;

  }

  else {

    *param_1 = 0;

  }

  FUN_007874b0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

  FUN_00787410(0);

  return 1;

}
