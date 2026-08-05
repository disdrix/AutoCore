// =============================================================================
// FUN_005ab110
// -----------------------------------------------------------------------------
// Stable ID: aa_005ab110
// Address:   0x005ab110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ab110 @ 0x005ab110
// Stable ID: aa_005ab110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005ab110.
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

void __fastcall FUN_005ab110(int param_1)



{

  *(uint8_t *)(param_1 + 0x4f68) = 0;

  *(uint8_t *)(param_1 + 0x5030) = 0;

  *(uint8_t *)(param_1 + 0x4f5c) = 0;

  *(uint8_t *)(param_1 + 0x4f5d) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4f60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4f64) = 0;

  if (*(void **)(param_1 + 0x50fc) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x50fc));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50fc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5104) = 0;

  return;

}
