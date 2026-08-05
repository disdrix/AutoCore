// =============================================================================
// FUN_0061fd60
// -----------------------------------------------------------------------------
// Stable ID: aa_0061fd60
// Address:   0x0061fd60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061fd60 @ 0x0061fd60
// Stable ID: aa_0061fd60
// Embedded strings (evidence for future rename):
//   - "op_scalar_2"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0061aaa0, FUN_0061fd60, sprintf, strncmp, tolower.
//  - Strings: "op_scalar_2".
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

uint32_t /* width from decompiler */ FUN_0061fd60(int param_1,char *param_2,char *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {

    iVar1 = tolower((int)*param_2);

    if (iVar1 == 0x6f) {

      iVar1 = strncmp(param_2,"op_scalar_2",0xb);

      if (iVar1 == 0) {

        sprintf(param_3,"%d",(int)*(float *)(param_1 + 0x164));

        return 1;

      }

    }

    uVar2 = FUN_0061aaa0(param_1,param_2,param_3);

    return uVar2;

  }

  return 0;

}
