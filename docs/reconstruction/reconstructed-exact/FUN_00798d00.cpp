// =============================================================================
// FUN_00798d00
// -----------------------------------------------------------------------------
// Stable ID: aa_00798d00
// Address:   0x00798d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00798d00 @ 0x00798d00
// Stable ID: aa_00798d00
// Embedded strings (evidence for future rename):
//   - "%d,%d,%d;%d,%d,%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00798bb0, FUN_00798d00, swscanf.
//  - Strings: "%d,%d,%d;%d,%d,%d".
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

char FUN_00798d00(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint8_t *param_3)



{

  char cVar1;

  int iVar2;

  uint8_t local_98 [4];

  uint8_t local_94 [4];

  uint8_t local_90 [4];

  uint8_t local_8c [4];

  uint8_t local_88 [4];

  uint8_t local_84 [4];

  wchar_t local_80 [64];

  

  cVar1 = FUN_00798bb0(param_1,param_2,local_80);

  if (cVar1 != '\0') {

    iVar2 = swscanf(local_80,L"%d,%d,%d;%d,%d,%d",local_94,local_98,local_90,local_88,local_84,

                    local_8c);

    if (iVar2 < 3) {

      return '\0';

    }

    param_3[2] = local_94[0];

    param_3[1] = local_98[0];

    *param_3 = local_90[0];

  }

  return cVar1;

}
