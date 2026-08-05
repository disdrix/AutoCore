// =============================================================================
// FUN_00626fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00626fd0
// Address:   0x00626fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00626fd0 @ 0x00626fd0
// Stable ID: aa_00626fd0
// Embedded strings (evidence for future rename):
//   - "level"
//   - ";

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, goto×1.
//  - Notable callees: strncmp×2, FUN_005781a0, FUN_00626fd0, FUN_007a69d0, FUN_007a6de0, sprintf, tolower.
//  - Strings: "level"; "op_scalar_2".
//  - Return sites: 4.

  }

  else {

    if ((iVar1 != 0x6f) || (iVar1 = strncmp(param_2,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

uint32_t /* width from decompiler */ FUN_00626fd0(int param_1,char *param_2,char *param_3)



{

  int iVar1;

  char *_Format;

  uint32_t /* width from decompiler */ uVar2;

  

  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

    return 0;

  }

  iVar1 = tolower((int)*param_2);

  if (iVar1 == 0x6c) {

    iVar1 = strncmp(param_2,"level",5);

    if (iVar1 != 0) goto LAB_00627085;

    iVar1 = (int)*(short *)(param_1 + 0xdc);

    _Format = "%d";

  }

  else {

    if ((iVar1 != 0x6f) || (iVar1 = strncmp(param_2,"op_scalar_2",0xb), iVar1 != 0)) {

LAB_00627085:

      uVar2 = FUN_005781a0(param_1,param_2,param_3);

      return uVar2;

    }

    if ((short)(int)*(float *)(param_1 + 0x164) != 0) {

      return 1;

    }

    param_1 = param_1 + 0x184;

    uVar2 = 0xffffffff;

    FUN_007a69d0(param_1,0xffffffff);

    iVar1 = FUN_007a6de0(param_1,uVar2);

    _Format = "%s";

  }

  sprintf(param_3,_Format,iVar1);

  return 1;

}
