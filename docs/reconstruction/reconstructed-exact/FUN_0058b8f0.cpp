// =============================================================================
// FUN_0058b8f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058b8f0
// Address:   0x0058b8f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058b8f0 @ 0x0058b8f0
// Stable ID: aa_0058b8f0
// Embedded strings (evidence for future rename):
//   - "attr_combat"
//   - "attr_perception"
//   - "attr_tech"
//   - "attr_theory"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×6, return×6.
//  - Notable callees: strncmp×4, sprintf×3, FUN_0058b8f0, tolower.
//  - Strings: "attr_combat"; "attr_perception"; "%+d"; "attr_tech".
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ FUN_0058b8f0(int param_1,char *param_2,char *param_3,float param_4)



{

  short sVar1;

  int iVar2;

  

  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

    return 0;

  }

  iVar2 = tolower((int)*param_2);

  if (iVar2 != 0x61) {

    return 0;

  }

  iVar2 = strncmp(param_2,"attr_combat",0xb);

  if (iVar2 == 0) {

    sVar1 = *(short *)(param_1 + 0xd0);

  }

  else {

    iVar2 = strncmp(param_2,"attr_perception",0xf);

    if (iVar2 == 0) {

      sprintf(param_3,"%+d",(int)((float)(int)*(short *)(param_1 + 0xd4) * param_4));

      return 1;

    }

    iVar2 = strncmp(param_2,"attr_tech",9);

    if (iVar2 == 0) {

      sprintf(param_3,"%+d",(int)((float)(int)*(short *)(param_1 + 0xd6) * param_4));

      return 1;

    }

    iVar2 = strncmp(param_2,"attr_theory",0xb);

    if (iVar2 != 0) {

      return 0;

    }

    sVar1 = *(short *)(param_1 + 0xd2);

  }

  sprintf(param_3,"%+d",(int)((float)(int)sVar1 * param_4));

  return 1;

}
