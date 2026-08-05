// =============================================================================
// FUN_00711da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00711da0
// Address:   0x00711da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711da0 @ 0x00711da0
// Stable ID: aa_00711da0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_00711e60×3, printf×2, FUN_00711da0, localtime, time.
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

int FUN_00711da0(int param_1)



{

  tm *ptVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  uint64_t local_28;

  uint32_t /* width from decompiler */ local_18;

  int local_14;

  int local_10;

  

  time(&local_28);

  ptVar1 = localtime(&local_28);

  piVar5 = (int *)((int)&local_28 + 4);

  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {

    *piVar5 = ptVar1->tm_sec;

    ptVar1 = (tm *)&ptVar1->tm_min;

    piVar5 = piVar5 + 1;

  }

  if (param_1 != 0) {

    printf(s_Today_s_date___02d__02d__d_00af8a80,local_14 + 1,local_18,local_10 + 0x76c);

    printf(s_Expiration_date___02d__02d__d_00af8a60,3,1,0x7d4);

  }

  iVar4 = FUN_00711e60(local_14 + 1,local_18,local_10 + 0x76c);

  iVar2 = FUN_00711e60(3,1,0x7d4);

  iVar3 = FUN_00711e60(2,1,0x7d4);

  if (iVar2 <= iVar4) {

    return 1;

  }

  return (iVar3 <= iVar4) - 1;

}
