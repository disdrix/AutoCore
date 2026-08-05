// =============================================================================
// FUN_006499c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006499c0
// Address:   0x006499c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006499c0 @ 0x006499c0
// Stable ID: aa_006499c0
// Embedded strings (evidence for future rename):
//   - "%s_FIXED_RIGID_BODY"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00646390×2, FUN_00638180, FUN_006381e0, FUN_006499c0, FUN_00690170.
//  - Strings: "%s_FIXED_RIGID_BODY".
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

void __thiscall FUN_006499c0(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  undefined *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  

  FUN_00646390(param_2,param_3);

  puVar2 = (undefined *)(**(code **)(*param_2 + 0xc))();

  if (puVar2 == &DAT_00d02688) {

    uVar3 = FUN_00690170();

    DAT_00d02c6c = DAT_00d02c6c + 1;

    FUN_006381e0(&stack0x00000000,"%s_FIXED_RIGID_BODY",param_3);

    FUN_00646390(uVar3,&DAT_00d02c70);

    piVar1 = (int *)(unaff_ESI + -4);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

      return;

    }

  }

  else if (puVar2 == &DAT_00d0352c) {

    *(uint8_t *)(param_1 + 0x14) = 1;

  }

  return;

}
