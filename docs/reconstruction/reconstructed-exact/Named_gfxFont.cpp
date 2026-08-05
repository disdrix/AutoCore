// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0073bc50, FUN_0076cec0, FUN_0099ed40, vog_LogMessage.
//  - Strings: "Failed to create font: %s"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFont.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_gfxFont
// -----------------------------------------------------------------------------
// Stable ID: aa_0099ed40
// Address:   0x0099ed40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxFont"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_gfxFont(void)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ in_EAX;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ unaff_EDI;

  

  piVar3 = (int *)FUN_0073bc50(DAT_00d1f628,unaff_EDI,in_EAX);

  if (piVar3 == (int *)0x0) {

    uVar4 = FUN_0076cec0(&stack0x00000004,"Failed to create font: %s");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFont.cpp",0x14,3,uVar4);

    return 0xffffffff;

  }

  piVar3[1] = piVar3[1] + 1;

  if (piVar3[1] == 1) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = (int *)*unaff_EBX;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *unaff_EBX = (int)piVar3;

  return 0;

}
