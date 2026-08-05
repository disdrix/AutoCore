// =============================================================================
// FUN_007137d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007137d0
// Address:   0x007137d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007137d0 @ 0x007137d0
// Stable ID: aa_007137d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00713910×2, FUN_007137d0.
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

void FUN_007137d0(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar4 = *param_1;

  iVar1 = param_1[1];

  iVar2 = param_1[2];

  iVar3 = FUN_00713910(param_2,iVar1,iVar4);

  iVar5 = iVar4 - iVar3;

  if (iVar5 < param_3) {

    (*(code *)PTR_memcpy_00af8a54)(iVar2 + iVar3 * 4,param_4,iVar5 * 4);

    (*(code *)PTR_memcpy_00af8a54)(iVar2,iVar5 * 4 + param_4,(iVar5 * 0x3fffffff + param_3) * 4);

  }

  else {

    (*(code *)PTR_memcpy_00af8a54)(iVar2 + iVar3 * 4,param_4,param_3 << 2);

  }

  iVar4 = FUN_00713910(param_3,iVar1,iVar4);

  param_1[1] = iVar4;

  return;

}
