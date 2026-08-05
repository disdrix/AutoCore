// =============================================================================
// Named_CalleeOf_Auth_AuthServer_00415e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00415e90
// Callee of Auth_AuthServer
// Address:   0x00415e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Auth_AuthServer: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00415e90.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Auth_AuthServer
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

void Named_CalleeOf_Auth_AuthServer_00415e90(void)

{
  uint32_t /* width from decompiler */ *puVar1;
  void *pvVar2;
  int unaff_ESI;
  
  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 4);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(unaff_ESI + 4) + 4) = *(int *)(unaff_ESI + 4);
  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;
  if (pvVar2 != *(void **)(unaff_ESI + 4)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar2);
  }
  return;
}
