// =============================================================================
// FUN_004776d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004776d0
// Address:   0x004776d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004776d0 @ 0x004776d0
// Stable ID: aa_004776d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00476cc0, FUN_004776d0, malloc.
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

void * __fastcall FUN_004776d0(size_t param_1)



{

  void *pvVar1;

  int unaff_ESI;

  

  if ((unaff_ESI == 0) || (param_1 == 0)) {

    pvVar1 = (void *)0x0;

  }

  else {

    if (*(code **)(unaff_ESI + 0x248) == (code *)0x0) {

      pvVar1 = malloc(param_1);

    }

    else {

      pvVar1 = (void *)(**(code **)(unaff_ESI + 0x248))();

    }

    if ((pvVar1 == (void *)0x0) && ((*(byte *)(unaff_ESI + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0();

    }

  }

  return pvVar1;

}
