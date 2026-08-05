// =============================================================================
// FUN_004647b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004647b0
// Address:   0x004647b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004647b0 @ 0x004647b0
// Stable ID: aa_004647b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_004647b0.
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

void FUN_004647b0(void)



{

  void *pvVar1;

  int unaff_EBX;

  

  pvVar1 = *(void **)(unaff_EBX + 0xc);

  if (pvVar1 == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc) = 0;

    return;

  }

  if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)((int)pvVar1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0xc) = 0;

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
