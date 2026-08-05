// =============================================================================
// FUN_00713880
// -----------------------------------------------------------------------------
// Stable ID: aa_00713880
// Address:   0x00713880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713880 @ 0x00713880
// Stable ID: aa_00713880
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00713880, FUN_00713910.
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

void FUN_00713880(int *param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = param_1[2];

  iVar3 = *param_1;

  iVar2 = FUN_00713910(-((param_3 + 1 >> 1) + param_2),param_1[1],iVar3);

  iVar3 = iVar3 - iVar2;

  if (param_3 <= iVar3) {

    (*(code *)PTR_memcpy_00af8a54)(param_4,iVar1 + iVar2 * 4,param_3 * 4);

    return;

  }

  (*(code *)PTR_memcpy_00af8a54)(param_4,iVar1 + iVar2 * 4,iVar3 * 4);

  (*(code *)PTR_memcpy_00af8a54)(iVar3 * 4 + param_4,iVar1,(iVar3 * 0x3fffffff + param_3) * 4);

  return;

}
