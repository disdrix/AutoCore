// =============================================================================
// FUN_00799290
// -----------------------------------------------------------------------------
// Stable ID: aa_00799290
// Address:   0x00799290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00799290 @ 0x00799290
// Stable ID: aa_00799290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00798bb0, FUN_00799290, _wtof.
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

char FUN_00799290(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,float *param_3,uint8_t *param_4)



{

  char cVar1;

  double dVar2;

  wchar_t local_80 [64];

  

  *param_4 = 0;

  cVar1 = FUN_00798bb0(param_1,param_2,local_80);

  if (cVar1 != '\0') {

    if (local_80[0] == L'R') {

      local_80[0] = L' ';

      *param_4 = 1;

    }

    else {

      *param_4 = 0;

    }

    dVar2 = _wtof(local_80);

    *param_3 = (float)dVar2;

  }

  return cVar1;

}
