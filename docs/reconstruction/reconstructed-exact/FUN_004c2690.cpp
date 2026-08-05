// =============================================================================
// FUN_004c2690
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2690
// Address:   0x004c2690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c2690 @ 0x004c2690
// Stable ID: aa_004c2690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_004c2500, FUN_004c2690.
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

void __fastcall FUN_004c2690(int param_1)



{

  FUN_004c2500();

  if (*(void **)(param_1 + 500) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 500));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 500) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1f8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1fc) = 0;

  if (*(void **)(param_1 + 0x1e4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x1e4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ec) = 0;

  return;

}
