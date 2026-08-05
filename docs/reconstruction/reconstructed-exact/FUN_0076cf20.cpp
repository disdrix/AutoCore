// =============================================================================
// FUN_0076cf20
// -----------------------------------------------------------------------------
// Stable ID: aa_0076cf20
// Address:   0x0076cf20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076cf20 @ 0x0076cf20
// Stable ID: aa_0076cf20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0076cce0, FUN_0076cf20.
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

void FUN_0076cf20(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *unaff_EDI;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &DAT_009ab5b5;

  local_c = ExceptionList;

  local_4 = 0;

  pvVar1 = (void *)*unaff_EDI;

  if (pvVar1 != (void *)0x0) {

    ExceptionList = &local_c;

    FUN_0076cce0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *unaff_EDI = 0;

  unaff_EDI[1] = 0;

  DAT_00d1f040 = 0;

  return;

}
