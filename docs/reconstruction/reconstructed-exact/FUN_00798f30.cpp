// =============================================================================
// FUN_00798f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00798f30
// Address:   0x00798f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00798f30 @ 0x00798f30
// Stable ID: aa_00798f30
// Embedded strings (evidence for future rename):
//   - "%f;%f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: swscanf×2, FUN_00798bb0, FUN_00798f30, _wtol.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



char FUN_00798f30(uint32_t /* width from decompiler */ param_1,long *param_2,uint32_t /* width from decompiler */ param_3,float *param_4,float *param_5,

                 uint8_t *param_6)



{

  char cVar1;

  int iVar2;

  long lVar3;

  wchar_t local_80;

  wchar_t local_7e;

  short local_7c;

  wchar_t local_7a [61];

  

  *param_2 = -1;

  if (param_6 != (uint8_t *)0x0) {

    *param_6 = 0;

  }

  cVar1 = FUN_00798bb0(param_1,param_3,&local_80);

  if (cVar1 != '\0') {

    if ((local_80 != L'p') && (local_80 != L'P')) {

      if (param_6 != (uint8_t *)0x0) {

        *param_6 = 0;

      }

      iVar2 = swscanf(&local_80,L"%f;%f",param_4,param_5);

      if ((iVar2 == 2) && (*param_5 = *param_5 - *param_4, param_6 != (uint8_t *)0x0)) {

        *param_6 = 1;

      }

      return cVar1;

    }

    lVar3 = _wtol(&local_7e);

    *param_2 = lVar3;

    if (local_7c == 0x3b) {

      if (param_6 != (uint8_t *)0x0) {

        *param_6 = 0;

      }

      iVar2 = swscanf(local_7a,L"%f;%f",param_4,0);

      if ((iVar2 == 2) && (_DAT_00000000 = _DAT_00000000 - *param_4, param_6 != (uint8_t *)0x0))

      {

        *param_6 = 1;

      }

      *param_6 = 1;

      *param_5 = *param_4;

    }

  }

  return cVar1;

}
