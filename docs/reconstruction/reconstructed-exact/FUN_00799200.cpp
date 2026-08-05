// =============================================================================
// FUN_00799200
// -----------------------------------------------------------------------------
// Stable ID: aa_00799200
// Address:   0x00799200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00799200 @ 0x00799200
// Stable ID: aa_00799200
// Embedded strings (evidence for future rename):
//   - "%f;%f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00798bb0, FUN_00799200, swscanf.
//  - Strings: "%f;%f".
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

char FUN_00799200(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,float *param_3,float *param_4,

                 uint8_t *param_5)



{

  char cVar1;

  int iVar2;

  wchar_t local_80 [64];

  

  cVar1 = FUN_00798bb0(param_1,param_2,local_80);

  *param_5 = 0;

  if (cVar1 != '\0') {

    *param_5 = 0;

    iVar2 = swscanf(local_80,L"%f;%f",param_3,param_4);

    if (iVar2 == 2) {

      *param_4 = *param_4 - *param_3;

      *param_5 = 1;

    }

    return cVar1;

  }

  return '\0';

}
