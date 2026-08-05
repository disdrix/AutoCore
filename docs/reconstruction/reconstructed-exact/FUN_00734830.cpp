// =============================================================================
// FUN_00734830
// -----------------------------------------------------------------------------
// Stable ID: aa_00734830
// Address:   0x00734830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00734830 @ 0x00734830
// Stable ID: aa_00734830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_00456780, FUN_00734830, FUN_0095d690.
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

void FUN_00734830(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x2c);

  while( true ) {

    if (puVar2 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x30)) {

      FUN_00456780(0);

      return;

    }

    pvVar1 = (void *)*puVar2;

    if (pvVar1 != (void *)0x0) break;

    puVar2 = puVar2 + 1;

  }

  FUN_0095d690();

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
