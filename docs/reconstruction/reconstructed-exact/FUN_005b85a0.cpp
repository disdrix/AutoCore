// =============================================================================
// FUN_005b85a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b85a0
// Address:   0x005b85a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b85a0 @ 0x005b85a0
// Stable ID: aa_005b85a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005b85a0.
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

void __fastcall FUN_005b85a0(int param_1)



{

  void *pvVar1;

  

  pvVar1 = (void *)(param_1 + 0x90);

  if (*(void **)(param_1 + 0x90) != pvVar1) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x90));

  }

  *(void **)(param_1 + 0x94) = pvVar1;

  *(void **)(param_1 + 0xc4) = pvVar1;

  *(void **)pvVar1 = pvVar1;

  return;

}
