// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0076d140×2, FUN_0044f5a0, FUN_0076d2a0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\arda2\\core\\corErrorHandler.cpp"; "Attempt to remove non-installed handler".
//  - Return sites: 2.

// =============================================================================
// Named_corErrorHandler_0076d2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d2a0
// Address:   0x0076d2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "corErrorHandler"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_corErrorHandler_0076d2a0(void)



{

  int iVar1;

  int *unaff_EDI;

  uint8_t *puVar2;

  

  if ((char)unaff_EDI[2] != '\0') {

    puVar2 = &stack0xfffffffc;

    (**(code **)(*unaff_EDI + 0xc))();

    iVar1 = FUN_0076d140();

    if (*(int *)(iVar1 + 8) != 0) {

      FUN_0076d140(&stack0xfffffffc);

      FUN_0044f5a0(puVar2);

    }

    *(uint8_t *)(unaff_EDI + 2) = 0;

    return;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\core\\corErrorHandler.cpp",0x56,3,

                 "Attempt to remove non-installed handler");

  return;

}
