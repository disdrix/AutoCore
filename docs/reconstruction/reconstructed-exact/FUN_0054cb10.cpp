// =============================================================================
// FUN_0054cb10
// -----------------------------------------------------------------------------
// Stable ID: aa_0054cb10
// Address:   0x0054cb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0054cb10 @ 0x0054cb10
// Stable ID: aa_0054cb10
// Embedded strings (evidence for future rename):
//   - "conversion_percent"
//   - "%g%%"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0040dab0, FUN_0054cb10, FUN_005781a0, sprintf, strncmp.
//  - Strings: "conversion_percent"; "%g%%".
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

uint32_t /* width from decompiler */ FUN_0054cb10(uint32_t /* width from decompiler */ param_1,char *param_2,char *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {

    if (*param_2 == 'c') {

      iVar1 = strncmp(param_2,"conversion_percent",0x12);

      if (iVar1 == 0) {

        iVar1 = FUN_0040dab0();

        sprintf(param_3,"%g%%",(double)((float)iVar1 * g_flMultiKillCountBlend));

        return 1;

      }

    }

    uVar2 = FUN_005781a0(param_1,param_2,param_3);

    return uVar2;

  }

  return 0;

}
