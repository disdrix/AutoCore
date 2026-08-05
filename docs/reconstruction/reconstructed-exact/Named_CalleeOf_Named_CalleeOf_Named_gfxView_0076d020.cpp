// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxView_0076d020
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d020
// Callee of Named_CalleeOf_Named_gfxView
// Address:   0x0076d020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxView: callee helper. Evidence string: "NDError". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "NDError"
//   - ",param_4);

  }

  fputs(local_400,(FILE *)(_iob_exref + 0x40));

  fputs("
//   - ",(FILE *)(_iob_exref + 0x40));

  fflush((FILE *)(_iob_exref + 0x40));

  pcVar1 = strstr("
//   - ");

  if (pcVar1 == (char *)0x0) {

    FUN_0076c130("
//   - "
//   - "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0076c130×2, _snprintf×2, fputs×2, s×2, strstr×2, FUN_0076d020, fflush.
//  - Strings: "NDError"; "%s - %s(%d) : %s"; "%s(%d) : %s: %s\n".
//  - Return sites: 1.

  }

  fputs(local_400,(FILE *)(_iob_exref + 0x40));

  fputs("
//   - ",(FILE *)(_iob_exref + 0x40));

  fflush((FILE *)(_iob_exref + 0x40));

  pcVar1 = strstr("
//   - ");

  if (pcVar1 == (char *)0x0) {

    FUN_0076c130("
// Readability: control flow preserved from Ghidra decompile; types tentative.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxView
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_gfxView_0076d020(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *unaff_ESI;

  char local_400 [1024];

  

  pcVar1 = strstr(unaff_ESI,"NDError");

  if (pcVar1 == (char *)0x0) {

    _snprintf(local_400,0x400,"%s - %s(%d) : %s",param_3);

  }

  else {

    _snprintf(local_400,0x400,"%s",param_4);

  }

  fputs(local_400,(FILE *)(_iob_exref + 0x40));

  fputs("\n",(FILE *)(_iob_exref + 0x40));

  fflush((FILE *)(_iob_exref + 0x40));

  pcVar1 = strstr(unaff_ESI,"NDError");

  if (pcVar1 == (char *)0x0) {

    FUN_0076c130("%s(%d) : %s: %s\n");

  }

  else {

    FUN_0076c130(&DAT_00a57d38,param_4);

  }

  uVar2 = 3;

  if (param_2 < 4) {

    uVar2 = 1;

  }

  return uVar2;

}
