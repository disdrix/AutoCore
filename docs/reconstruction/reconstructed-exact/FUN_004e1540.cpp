// =============================================================================
// FUN_004e1540
// -----------------------------------------------------------------------------
// Stable ID: aa_004e1540
// Address:   0x004e1540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004e1540 @ 0x004e1540
// Stable ID: aa_004e1540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004e1540.
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

void __fastcall FUN_004e1540(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  

  pvVar1 = (void *)param_1[1];

  *param_1 = &PTR_FUN_009cc1d4;

  if (pvVar1 != (void *)0x0) {

    operator_delete__(*(void **)((int)pvVar1 + 0x24));

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  return;

}
