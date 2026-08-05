// =============================================================================
// FUN_00799460
// -----------------------------------------------------------------------------
// Stable ID: aa_00799460
// Address:   0x00799460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00799460 @ 0x00799460
// Stable ID: aa_00799460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00798bb0, FUN_00799460, wcstol.
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

char FUN_00799460(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,long *param_3,int param_4)



{

  char cVar1;

  long lVar2;

  wchar_t *local_84;

  wchar_t local_80 [64];

  

  cVar1 = FUN_00798bb0(param_1,param_2,local_80);

  if (cVar1 != '\0') {

    lVar2 = wcstol(local_80,&local_84,param_4);

    *param_3 = lVar2;

  }

  return cVar1;

}
