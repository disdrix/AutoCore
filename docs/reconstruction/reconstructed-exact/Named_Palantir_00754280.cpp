// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0071aef0, FUN_00754280, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\framework\\Palantir.cpp"; "Preload thread already runnning.".
//  - Return sites: 2.

// =============================================================================
// Named_Palantir_00754280
// -----------------------------------------------------------------------------
// Stable ID: aa_00754280
// Address:   0x00754280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Palantir"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_Palantir_00754280(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0xd4) != 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\framework\\Palantir.cpp",0x1fd,2,

                   "Preload thread already runnning.");

    return 0;

  }

  puVar1 = operator_new(0x10);

  puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[3] = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    *puVar1 = &PTR_FUN_00a9e9bc;

    puVar1[3] = *(uint32_t /* width from decompiler */ *)(DAT_00d1f050 + 0x6c);

    puVar2 = puVar1;

  }

  *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0xd4) = puVar2;

  FUN_0071aef0();

  return 1;

}
