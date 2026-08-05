// =============================================================================
// FUN_0094eb20
// -----------------------------------------------------------------------------
// Stable ID: aa_0094eb20
// Address:   0x0094eb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094eb20 @ 0x0094eb20
// Stable ID: aa_0094eb20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGReaction_UnlockContinentObject, FUN_0094eb20, atoi, strtok.
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

uint32_t /* width from decompiler */ __thiscall FUN_0094eb20(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  char *_Str;

  uint continentId;

  

  if (*(int *)(param_1 + 0xe98) != 0) {

    _Str = strtok((char *)0x0,param_3);

    if (_Str != (char *)0x0) {

      continentId = atoi(_Str);

      CVOGReaction_UnlockContinentObject(*(void **)(param_1 + 0xe98),continentId);

    }

  }

  return 1;

}
