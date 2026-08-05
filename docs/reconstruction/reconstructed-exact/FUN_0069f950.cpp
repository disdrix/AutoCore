// =============================================================================
// FUN_0069f950
// -----------------------------------------------------------------------------
// Stable ID: aa_0069f950
// Address:   0x0069f950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069f950 @ 0x0069f950
// Stable ID: aa_0069f950
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, return×1.
//  - Notable callees: FUN_0056f570×2, FUN_0069f950.
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

float * __thiscall FUN_0069f950(float *param_1,float *param_2,float *param_3)



{

  int iVar1;

  float *pfVar2;

  float *pfVar3;

  float local_3c [6];

  float local_24;

  float local_20;

  float local_1c;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aafb1;

  local_c = ExceptionList;

  pfVar2 = local_3c;

  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {

    *pfVar2 = *param_1;

    param_1 = param_1 + 1;

    pfVar2 = pfVar2 + 1;

  }

  if (*param_3 < local_3c[0]) {

    local_3c[0] = *param_3;

  }

  if (param_3[1] < local_3c[1]) {

    local_3c[1] = param_3[1];

  }

  if (param_3[2] < local_3c[2]) {

    local_3c[2] = param_3[2];

  }

  if (local_24 < *param_3) {

    local_24 = *param_3;

  }

  if (local_20 < param_3[1]) {

    local_20 = param_3[1];

  }

  if (local_1c < param_3[2]) {

    local_1c = param_3[2];

  }

  pfVar2 = local_3c;

  pfVar3 = param_2;

  ExceptionList = &local_c;

  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {

    *pfVar3 = *pfVar2;

    pfVar2 = pfVar2 + 1;

    pfVar3 = pfVar3 + 1;

  }

  local_4 = 1;

  FUN_0056f570();

  local_4 = local_4 & 0xffffff00;

  FUN_0056f570();

  ExceptionList = local_c;

  return param_2;

}
