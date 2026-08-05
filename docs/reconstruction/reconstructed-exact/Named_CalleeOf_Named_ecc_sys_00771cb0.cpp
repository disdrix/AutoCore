// =============================================================================
// Named_CalleeOf_Named_ecc_sys_00771cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00771cb0
// Callee of Named_ecc_sys (+1 other named callers)
// Address:   0x00771cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_ecc_sys (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1, for×1.
//  - Notable callees: FUN_00770440, FUN_007707d0, FUN_00771cb0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_ecc_sys_00771cb0(int param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  

  uVar2 = 0;

  iVar4 = 0;

  if (param_1 != 0) {

    while( true ) {

      iVar3 = FUN_00770440();

      if (iVar3 != 0) break;

      piVar1 = (int *)((int)register0x00000010 + 8);

      iVar4 = iVar4 + 1;

      register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4);

      if (*piVar1 == 0) {

        return 0;

      }

    }

    for (; iVar4 != 0; iVar4 = iVar4 + -1) {

      FUN_007707d0();

    }

    uVar2 = 0xfffffffe;

  }

  return uVar2;

}
