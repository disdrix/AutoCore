// =============================================================================
// FUN_00799160
// -----------------------------------------------------------------------------
// Stable ID: aa_00799160
// Address:   0x00799160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00799160 @ 0x00799160
// Stable ID: aa_00799160
// Embedded strings (evidence for future rename):
//   - "%f,%f,%f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00798bb0, FUN_00799160, swscanf.
//  - Strings: "%f,%f,%f".
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

char FUN_00799160(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ local_8c;

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  wchar_t local_80 [64];

  

  cVar1 = FUN_00798bb0(param_1,param_2,local_80);

  if (cVar1 != '\0') {

    local_84 = 0;

    local_8c = 0;

    local_88 = 0;

    swscanf(local_80,L"%f,%f,%f",&local_84,&local_8c,&local_88);

    *param_3 = local_84;

    param_3[1] = local_8c;

    param_3[2] = local_88;

    param_3[3] = 0;

  }

  return cVar1;

}
