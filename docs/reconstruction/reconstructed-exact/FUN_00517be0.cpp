// =============================================================================
// FUN_00517be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00517be0
// Address:   0x00517be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00517be0 @ 0x00517be0
// Stable ID: aa_00517be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT44, FUN_004e2320, FUN_00517be0.
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

uint64_t FUN_00517be0(int param_1,uint param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int local_4;

  

  iVar1 = param_1;

  iVar2 = FUN_004e2320(&param_2);

  local_4 = *(int *)(iVar1 + 4);

  if (((iVar2 == local_4) || (param_3 < *(int *)(iVar2 + 0x14))) ||

     ((param_3 <= *(int *)(iVar2 + 0x14) && (param_2 < *(uint *)(iVar2 + 0x10))))) {

    piVar3 = &local_4;

  }

  else {

    piVar3 = &param_1;

  }

  if (*piVar3 != local_4) {

    return *(uint64_t *)(*piVar3 + 0x18);

  }

  return CONCAT44(param_3,param_2);

}
