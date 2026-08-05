// =============================================================================
// FUN_0061c830
// -----------------------------------------------------------------------------
// Stable ID: aa_0061c830
// Address:   0x0061c830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061c830 @ 0x0061c830
// Stable ID: aa_0061c830
// Embedded strings (evidence for future rename):
//   - "conversion_percent"
//   - "%g%%"
//   - "op_scalar_1"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: FUN_00412c60×2, sprintf×2, strncmp×2, FUN_005781a0, FUN_0061c830, tolower.
//  - Strings: "conversion_percent"; "%g%%"; "op_scalar_1".
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

uint32_t /* width from decompiler */ FUN_0061c830(uint32_t /* width from decompiler */ param_1,char *param_2,char *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  float10 fVar3;

  

  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {

    iVar1 = tolower((int)*param_2);

    if (iVar1 == 99) {

      iVar1 = strncmp(param_2,"conversion_percent",0x12);

      if (iVar1 == 0) {

        fVar3 = (float10)FUN_00412c60();

        sprintf(param_3,"%g%%",(double)fVar3);

        return 1;

      }

    }

    else if (iVar1 == 0x6f) {

      iVar1 = strncmp(param_2,"op_scalar_1",0xb);

      if (iVar1 == 0) {

        fVar3 = (float10)FUN_00412c60();

        sprintf(param_3,"%g%%",(double)fVar3);

        return 1;

      }

    }

    uVar2 = FUN_005781a0(param_1,param_2,param_3);

    return uVar2;

  }

  return 0;

}
