// =============================================================================
// FUN_00798d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00798d90
// Address:   0x00798d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00798d90 @ 0x00798d90
// Stable ID: aa_00798d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_007989f0, FUN_00798bb0, FUN_00798d90, _wtol.
//  - Return sites: 3.

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

char FUN_00798d90(uint32_t /* width from decompiler */ param_1,long *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint8_t *param_6)



{

  char cVar1;

  char cVar2;

  long lVar3;

  short *local_84;

  short local_80;

  wchar_t local_7e [63];

  

  *param_2 = -1;

  if (param_6 != (uint8_t *)0x0) {

    *param_6 = 0;

  }

  cVar1 = FUN_00798bb0(param_1,param_3,&local_80);

  if (cVar1 != '\0') {

    if ((local_80 != 0x70) && (local_80 != 0x50)) {

      local_84 = &local_80;

      cVar2 = FUN_007989f0(&local_84);

      if (cVar2 == '\0') {

        return '\0';

      }

      return cVar1;

    }

    lVar3 = _wtol(local_7e);

    *param_2 = lVar3;

  }

  return cVar1;

}
