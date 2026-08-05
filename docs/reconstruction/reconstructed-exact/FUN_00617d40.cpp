// =============================================================================
// FUN_00617d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00617d40
// Address:   0x00617d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00617d40 @ 0x00617d40
// Stable ID: aa_00617d40
// Embedded strings (evidence for future rename):
//   - "max_hp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_005781a0, FUN_0058ba20, FUN_00617d40, sprintf, strncmp, tolower.
//  - Strings: "max_hp".
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ FUN_00617d40(int param_1,char *param_2,char *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

    return 0;

  }

  iVar1 = tolower((int)*param_2);

  if (iVar1 == 0x6d) {

    iVar1 = strncmp(param_2,"max_hp",6);

    if (iVar1 == 0) {

      sprintf(param_3,"%d",(int)*(float *)(param_1 + 0x4c));

      return 1;

    }

  }

  iVar1 = FUN_0058ba20(param_1,param_2,param_3,0x3f800000);

  if (iVar1 != 0) {

    return 1;

  }

  uVar2 = FUN_005781a0(param_1,param_2,param_3);

  return uVar2;

}
