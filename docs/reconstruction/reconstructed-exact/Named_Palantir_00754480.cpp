// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00754480, FUN_0075eff0, Sleep, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\framework\\Palantir.cpp"; "Palantir::ResetDevice failed. Will try again in 1000 msec. ".
//  - Return sites: 2.

// =============================================================================
// Named_Palantir_00754480
// -----------------------------------------------------------------------------
// Stable ID: aa_00754480
// Address:   0x00754480  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __fastcall Named_Palantir_00754480(int param_1)



{

  int iVar1;

  

  iVar1 = FUN_0075eff0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x28),*(uint32_t /* width from decompiler */ *)(param_1 + 0xb0),

                       *(uint8_t *)(param_1 + 5));

  if (iVar1 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\framework\\Palantir.cpp",0x184,0,

                   "Palantir::ResetDevice failed. Will try again in 1000 msec. ");

    *(uint8_t *)(param_1 + 6) = 1;

    Sleep(1000);

    return 0xffffffff;

  }

  *(uint8_t *)(param_1 + 6) = 0;

  (**(code **)(**(int **)(param_1 + 0x2c) + 8))(param_1 + 8);

  return 0;

}
