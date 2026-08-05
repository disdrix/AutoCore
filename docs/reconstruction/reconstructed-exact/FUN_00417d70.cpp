// =============================================================================
// FUN_00417d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00417d70
// Address:   0x00417d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00417d70 @ 0x00417d70
// Stable ID: aa_00417d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: DeleteCriticalSection×2, FUN_00417c50, FUN_00417d70.
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

void __fastcall FUN_00417d70(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  

  *param_1 = &PTR_FUN_00a76580;

  pvVar1 = (void *)FUN_00417c50(param_1);

  if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[3] = 0;

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 10));

  return;

}
