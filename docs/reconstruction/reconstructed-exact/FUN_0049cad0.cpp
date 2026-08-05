// =============================================================================
// FUN_0049cad0
// -----------------------------------------------------------------------------
// Stable ID: aa_0049cad0
// Address:   0x0049cad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049cad0 @ 0x0049cad0
// Stable ID: aa_0049cad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, if×1, while×1.
//  - Notable callees: FUN_0049cad0, FUN_004b99c0.
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

void FUN_0049cad0(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = &DAT_00b035e4;

  do {

    pvVar1 = (void *)*puVar2;

    if (pvVar1 != (void *)0x0) {

      FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  } while ((int)puVar2 < 0xb035fc);

  return;

}
